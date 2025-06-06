// B"H

// Distributed under GPLv3 only as specified in repository's root LICENSE file

#include "AaCommunicator.h"
#include "ChannelType.h"
#include "Library.h"
#include "ManualResetEvent.h"
#include "ModeSwitcher.h"
#include "Packet.h"
#include "PacketType.h"
#include "SocketCommunicator.h"
#include "Udc.h"
#include "utils.h"
#include <boost/program_options.hpp>
#include <csignal>
#include <gst/gst.h>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <cstdlib>

using namespace std;
using namespace boost::program_options;

string configFsBasePath = "/sys/kernel/config";
ManualResetEvent mre;

void signal_handler(int signal) {
  cout << "Quitting..." << endl;
  mre.set();
  std::signal(SIGINT, SIG_DFL);
}

int main(int argc, char *argv[]) {
  if (std::system("sudo modprobe libcomposite") != 0)
    std::cout << "Failed to load libcomposite\n";

  if (std::system("sudo modprobe usb_f_fs") != 0)
    std::cout << "Failed to load usb_f_fs\n";

  if (std::system("sudo modprobe usb_f_mass_storage") != 0)
    std::cout << "Failed to load usb_f_mass_storage\n";

  options_description desc("Allowed options");
  desc.add_options()("help", "produce help message")(
      "dumpfile", value<string>(), "specify pcap dumpfile for communication");

  variables_map vm;
  store(parse_command_line(argc, argv, desc), vm);
  notify(vm);

  if (vm.count("help")) {
    cout << desc << "\n";
    return 1;
  }
  string dumpfile;
  if (vm.count("dumpfile")) {
    dumpfile = vm["dumpfile"].as<string>();
  }
  signal(SIGINT, signal_handler);
  gst_init(&argc, &argv);
  Library lib(configFsBasePath);

  cout << "(1) Library loaded for configFs" << endl;

  ModeSwitcher::handleSwitchToAccessoryMode(lib);

  cout << "(2) Accessory mode active" << endl;

  AaCommunicator aac(lib, dumpfile);

  cout << "(3) AaCommunicator active" << endl;

  aac.setup(Udc::getUdcById(lib, 0));

  cout << "(4) AaCommunicator get Udc" << endl;

  mutex error_mutex;
  aac.error.connect([&](const std::exception &ex) {
    unique_lock ul(error_mutex);
    cout << "Error: " << ex.what() << endl;
    if (const aa_runtime_error *are =
            dynamic_cast<const aa_runtime_error *>(&ex)) {
      cout << "StackTrace:" << endl;
      are->printTrace(cout);
    }
    mre.set();
  });

  cout << "(5) AaCommunicator connect()" << endl;

  map<SocketClient *, int> clients;
  int hi = 0;
  aac.gotMessage.connect([&clients, &hi](int clientId, int channelNumber,
                                         bool specific, vector<uint8_t> data) {
    cout << hi++ << " data from headunit: " << channelNumber << " "
         << data.size() << endl;
    vector<uint8_t> msg;
    msg.push_back(channelNumber);
    msg.push_back(specific ? 0xff : 0x00);
    copy(data.begin(), data.end(), back_inserter(msg));
    for (auto cl : clients) {
      if (cl.second == clientId || clientId == -1)
        try {
          cl.first->sendMessage(msg);
        } catch (client_disconnected_error &cde) {
        }
    }
  });

  cout << "(6) data from head unit" << endl;

  
  SocketCommunicator sc("./socket");
  int pi = 0;
  int clientCount = 0;

  sc.newClient.connect([&](SocketClient *scl) {
    clients.insert({scl, clientCount++});
    cout << "connect: " << clients[scl] << endl;
    scl->gotPacket.connect([&aac, scl, &pi, &clients](const Packet &p) {
      if (p.packetType == PacketType::GetChannelNumberByChannelType) {
        auto channelId =
            aac.getChannelNumberByChannelType((ChannelType)p.channelNumber);
        cout << "get channel: " << (int)p.channelNumber << "->"
             << (int)channelId << endl;
        scl->sendMessage({channelId});
      } else if (p.packetType == PacketType::RawData) {
        try {
          aac.sendToChannel(clients[scl], p.channelNumber, p.specific, p.data);
        } catch (exception &ex) {
          cout << "disconnect client: " << clients[scl] << " " << ex.what()
               << endl;
          aac.disconnected(clients[scl]);
          clients.erase(scl);
          throw;
        }
      } else if (p.packetType == PacketType::GetServiceDescriptor) {
        cout << "get service descriptor" << endl;
        scl->sendMessage(aac.getServiceDescriptor());
      } else {
        throw runtime_error("Unknown packetType");
      }
    });
    scl->disconnected.connect([&aac, &clients, scl]() {
      cout << "disconnected: " << clients[scl] << endl;
      aac.disconnected(clients[scl]);
      clients.erase(scl);
    });
  });
  
  //while (!mre.wait_for(std::chrono::milliseconds(100))) {
  //  // Loop lets SIGINT be delivered and handled
  //}
  cout << "(7) " << endl;
  mre.wait();
  return 0;
}
