// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: PingResponse.proto

#include "PingResponse.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace tag {
namespace aas {
class PingResponseDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<PingResponse> _instance;
} _PingResponse_default_instance_;
}  // namespace aas
}  // namespace tag
static void InitDefaultsscc_info_PingResponse_PingResponse_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::tag::aas::_PingResponse_default_instance_;
    new (ptr) ::tag::aas::PingResponse();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::tag::aas::PingResponse::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_PingResponse_PingResponse_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_PingResponse_PingResponse_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_PingResponse_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_PingResponse_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_PingResponse_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_PingResponse_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::tag::aas::PingResponse, _has_bits_),
  PROTOBUF_FIELD_OFFSET(::tag::aas::PingResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::tag::aas::PingResponse, timestamp_),
  0,
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 6, sizeof(::tag::aas::PingResponse)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::tag::aas::_PingResponse_default_instance_),
};

const char descriptor_table_protodef_PingResponse_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022PingResponse.proto\022\007tag.aas\"!\n\014PingRes"
  "ponse\022\021\n\ttimestamp\030\001 \002(\003"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_PingResponse_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_PingResponse_2eproto_sccs[1] = {
  &scc_info_PingResponse_PingResponse_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_PingResponse_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_PingResponse_2eproto = {
  false, false, descriptor_table_protodef_PingResponse_2eproto, "PingResponse.proto", 64,
  &descriptor_table_PingResponse_2eproto_once, descriptor_table_PingResponse_2eproto_sccs, descriptor_table_PingResponse_2eproto_deps, 1, 0,
  schemas, file_default_instances, TableStruct_PingResponse_2eproto::offsets,
  file_level_metadata_PingResponse_2eproto, 1, file_level_enum_descriptors_PingResponse_2eproto, file_level_service_descriptors_PingResponse_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_PingResponse_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_PingResponse_2eproto)), true);
namespace tag {
namespace aas {

// ===================================================================

void PingResponse::InitAsDefaultInstance() {
}
class PingResponse::_Internal {
 public:
  using HasBits = decltype(std::declval<PingResponse>()._has_bits_);
  static void set_has_timestamp(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x00000001) ^ 0x00000001) != 0;
  }
};

PingResponse::PingResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:tag.aas.PingResponse)
}
PingResponse::PingResponse(const PingResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _has_bits_(from._has_bits_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  timestamp_ = from.timestamp_;
  // @@protoc_insertion_point(copy_constructor:tag.aas.PingResponse)
}

void PingResponse::SharedCtor() {
  timestamp_ = PROTOBUF_LONGLONG(0);
}

PingResponse::~PingResponse() {
  // @@protoc_insertion_point(destructor:tag.aas.PingResponse)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void PingResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
}

void PingResponse::ArenaDtor(void* object) {
  PingResponse* _this = reinterpret_cast< PingResponse* >(object);
  (void)_this;
}
void PingResponse::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void PingResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const PingResponse& PingResponse::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_PingResponse_PingResponse_2eproto.base);
  return *internal_default_instance();
}


void PingResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:tag.aas.PingResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  timestamp_ = PROTOBUF_LONGLONG(0);
  _has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* PingResponse::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // required int64 timestamp = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 8)) {
          _Internal::set_has_timestamp(&has_bits);
          timestamp_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  _has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* PingResponse::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:tag.aas.PingResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _has_bits_[0];
  // required int64 timestamp = 1;
  if (cached_has_bits & 0x00000001u) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt64ToArray(1, this->_internal_timestamp(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:tag.aas.PingResponse)
  return target;
}

size_t PingResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tag.aas.PingResponse)
  size_t total_size = 0;

  // required int64 timestamp = 1;
  if (_internal_has_timestamp()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int64Size(
        this->_internal_timestamp());
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void PingResponse::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:tag.aas.PingResponse)
  GOOGLE_DCHECK_NE(&from, this);
  const PingResponse* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<PingResponse>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:tag.aas.PingResponse)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:tag.aas.PingResponse)
    MergeFrom(*source);
  }
}

void PingResponse::MergeFrom(const PingResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:tag.aas.PingResponse)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_timestamp()) {
    _internal_set_timestamp(from._internal_timestamp());
  }
}

void PingResponse::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:tag.aas.PingResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void PingResponse::CopyFrom(const PingResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tag.aas.PingResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PingResponse::IsInitialized() const {
  if (_Internal::MissingRequiredFields(_has_bits_)) return false;
  return true;
}

void PingResponse::InternalSwap(PingResponse* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(_has_bits_[0], other->_has_bits_[0]);
  swap(timestamp_, other->timestamp_);
}

::PROTOBUF_NAMESPACE_ID::Metadata PingResponse::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace aas
}  // namespace tag
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::tag::aas::PingResponse* Arena::CreateMaybeMessage< ::tag::aas::PingResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::tag::aas::PingResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
