// Distributed under GPLv3 only as specified in repository's root LICENSE file

#include "ModeSwitcher.h"
#include "Configuration.h"
#include "FfsFunction.h"
#include "Function.h"
#include "Gadget.h"
#include "Library.h"
#include "MassStorageFunction.h"
#include "ModeSwitcher.h"
#include "Udc.h"
#include "descriptors.h"
#include "utils.h"
#include <boost/filesystem.hpp>
#include <boost/filesystem/operations.hpp>
#include <fcntl.h>
#include <iostream>
#include <linux/usb/functionfs.h>
#include <unistd.h>
#include <csignal>

static volatile sig_atomic_t stopFlag = 0;
static int fdGlobal = -1;

static void signalHandler(int) {
  stopFlag = 1;
 if (fdGlobal != -1) {
    std::cout << "\nSIGINT caught: closing fd..." << std::endl;
    close(fdGlobal);
    fdGlobal = -1;
  }

}


ssize_t ModeSwitcher::handleSwitchMessage(int fd, const void *buf,
                                          size_t nbytes) {
  const usb_functionfs_event *event = (const usb_functionfs_event *)buf;
  for (size_t n = nbytes / sizeof *event; n; --n, ++event) {
    if (event->type == FUNCTIONFS_SETUP) {
      const struct usb_ctrlrequest &setup = event->u.setup;

      std::cout << "USB SETUP: "
          << "bmRequestType=0x" << std::hex << (int)setup.bRequestType << " "
          << "bRequest=0x"     << (int)setup.bRequest     << " "
          << "wValue=0x"       << setup.wValue            << " "
          << "wIndex=0x"       << setup.wIndex            << " "
          << "wLength=0x"      << setup.wLength
          << std::dec << std::endl;


    if (setup.bRequest == 51) {
        auto ret = write(fd, "\002\000", 2);
        std::cout << "Got 51, write=" << ret << std::endl;
      } else if (setup.bRequest == 52) {
        std::cout << "Got some info: " << setup.wIndex << "=";
        if (setup.wLength < nbytes) {
          std::cout << std::endl;
        }
      } else if (setup.bRequest == 53) {
        std::cout << "Got 53, exit" << std::endl;
        return 0;
      }
    } else {
      std::cout << std::string((char *)buf, nbytes) << std::endl;
    }
  }
  return nbytes;
}

void ModeSwitcher::handleSwitchToAccessoryMode(const Library &lib) {
  //Gadget initialGadget(lib, 0x12d1, 0x107e, rr("initial_state"));
  Gadget initialGadget(lib, 0x18D1, 0x2D00, rr("initial_state2"));
  initialGadget.setStrings("TAG", "AAServer", sr("TAGAAS"));

  auto lun0path = (boost::filesystem::temp_directory_path() / rr("lun0"));
  std::ofstream ofs(lun0path.c_str(), std::ios::binary | std::ios::out);
  ofs.seekp((4 << 20) - 1);
  ofs.write("", 1);
  ofs.flush();
  MassStorageFunction ms_function(initialGadget, rr("massstorage_initial"),
                                  lun0path.c_str());

  auto tmpMountpoint = boost::filesystem::temp_directory_path() /
                       rr("AAServer_mp_loopback_initial");
  create_directory(tmpMountpoint);
  FfsFunction ffs_function(initialGadget, rr("ffs_initial"),
                           tmpMountpoint.c_str());

  Configuration configuration(initialGadget, "c0");
  configuration.addFunction(ms_function, "massstorage_initial");
  configuration.addFunction(ffs_function, "loopback_initial");

  auto fd = open((tmpMountpoint / "ep0").c_str(), O_RDWR);
  write_descriptors_default(fd);
  fdGlobal = fd;  // register for signal handler

  auto udc = Udc::getUdcById(lib, 0);
  initialGadget.enable(udc);

  std::cout << "    ModeSwitcher: gadget enabled" << std::endl;

  auto eSize = sizeof(struct usb_functionfs_event);
  auto bufSize = 4 * eSize;
  uint8_t buffer[bufSize];

  signal(SIGINT, signalHandler);

  /*
    The while loop below handles switching to accessory mode 
    but the Desktop Head Unit output says it's already in accessory mode
    At the moment the code behaves identically whether this while loop is 
    included or not so I'm removing it for now  
  */

  /*
  while (!stopFlag) {
    std::cout << "pre read" << std::endl;
    auto length = checkError(read(fd, buffer, bufSize), {EINTR, EAGAIN});
    std::cout << "post read: " << length << std::endl;
    if (length == 0)
      continue;
    if (length == -1)
      break;
    std::cout << "pre hSM" << std::endl;
    checkError(handleSwitchMessage(fd, buffer, length), {EINTR, EAGAIN});
    std::cout << "post hSM: " << length << std::endl;
    if (length == -1)
      break;
  }
  */

  std::cout << "pre close fd" << std::endl;
  close(fd);
  std::cout << "post close fd" << std::endl;
}
