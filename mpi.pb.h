// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mpi.proto

#ifndef PROTOBUF_mpi_2eproto__INCLUDED
#define PROTOBUF_mpi_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3005001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace protobuf_mpi_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[2];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
void InitDefaultsRequestContextImpl();
void InitDefaultsRequestContext();
void InitDefaultsReplyContextImpl();
void InitDefaultsReplyContext();
inline void InitDefaults() {
  InitDefaultsRequestContext();
  InitDefaultsReplyContext();
}
}  // namespace protobuf_mpi_2eproto
namespace mpis {
class ReplyContext;
class ReplyContextDefaultTypeInternal;
extern ReplyContextDefaultTypeInternal _ReplyContext_default_instance_;
class RequestContext;
class RequestContextDefaultTypeInternal;
extern RequestContextDefaultTypeInternal _RequestContext_default_instance_;
}  // namespace mpis
namespace mpis {

// ===================================================================

class RequestContext : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:mpis.RequestContext) */ {
 public:
  RequestContext();
  virtual ~RequestContext();

  RequestContext(const RequestContext& from);

  inline RequestContext& operator=(const RequestContext& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  RequestContext(RequestContext&& from) noexcept
    : RequestContext() {
    *this = ::std::move(from);
  }

  inline RequestContext& operator=(RequestContext&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const RequestContext& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RequestContext* internal_default_instance() {
    return reinterpret_cast<const RequestContext*>(
               &_RequestContext_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(RequestContext* other);
  friend void swap(RequestContext& a, RequestContext& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline RequestContext* New() const PROTOBUF_FINAL { return New(NULL); }

  RequestContext* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const RequestContext& from);
  void MergeFrom(const RequestContext& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(RequestContext* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // int32 src = 1;
  void clear_src();
  static const int kSrcFieldNumber = 1;
  ::google::protobuf::int32 src() const;
  void set_src(::google::protobuf::int32 value);

  // int32 device = 2;
  void clear_device();
  static const int kDeviceFieldNumber = 2;
  ::google::protobuf::int32 device() const;
  void set_device(::google::protobuf::int32 value);

  // int32 buffer_size = 3;
  void clear_buffer_size();
  static const int kBufferSizeFieldNumber = 3;
  ::google::protobuf::int32 buffer_size() const;
  void set_buffer_size(::google::protobuf::int32 value);

  // int32 tag = 4;
  void clear_tag();
  static const int kTagFieldNumber = 4;
  ::google::protobuf::int32 tag() const;
  void set_tag(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:mpis.RequestContext)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 src_;
  ::google::protobuf::int32 device_;
  ::google::protobuf::int32 buffer_size_;
  ::google::protobuf::int32 tag_;
  mutable int _cached_size_;
  friend struct ::protobuf_mpi_2eproto::TableStruct;
  friend void ::protobuf_mpi_2eproto::InitDefaultsRequestContextImpl();
};
// -------------------------------------------------------------------

class ReplyContext : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:mpis.ReplyContext) */ {
 public:
  ReplyContext();
  virtual ~ReplyContext();

  ReplyContext(const ReplyContext& from);

  inline ReplyContext& operator=(const ReplyContext& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ReplyContext(ReplyContext&& from) noexcept
    : ReplyContext() {
    *this = ::std::move(from);
  }

  inline ReplyContext& operator=(ReplyContext&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ReplyContext& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ReplyContext* internal_default_instance() {
    return reinterpret_cast<const ReplyContext*>(
               &_ReplyContext_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(ReplyContext* other);
  friend void swap(ReplyContext& a, ReplyContext& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ReplyContext* New() const PROTOBUF_FINAL { return New(NULL); }

  ReplyContext* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const ReplyContext& from);
  void MergeFrom(const ReplyContext& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(ReplyContext* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // int32 status = 1;
  void clear_status();
  static const int kStatusFieldNumber = 1;
  ::google::protobuf::int32 status() const;
  void set_status(::google::protobuf::int32 value);

  // int32 dst = 2;
  void clear_dst();
  static const int kDstFieldNumber = 2;
  ::google::protobuf::int32 dst() const;
  void set_dst(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:mpis.ReplyContext)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 status_;
  ::google::protobuf::int32 dst_;
  mutable int _cached_size_;
  friend struct ::protobuf_mpi_2eproto::TableStruct;
  friend void ::protobuf_mpi_2eproto::InitDefaultsReplyContextImpl();
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RequestContext

// int32 src = 1;
inline void RequestContext::clear_src() {
  src_ = 0;
}
inline ::google::protobuf::int32 RequestContext::src() const {
  // @@protoc_insertion_point(field_get:mpis.RequestContext.src)
  return src_;
}
inline void RequestContext::set_src(::google::protobuf::int32 value) {
  
  src_ = value;
  // @@protoc_insertion_point(field_set:mpis.RequestContext.src)
}

// int32 device = 2;
inline void RequestContext::clear_device() {
  device_ = 0;
}
inline ::google::protobuf::int32 RequestContext::device() const {
  // @@protoc_insertion_point(field_get:mpis.RequestContext.device)
  return device_;
}
inline void RequestContext::set_device(::google::protobuf::int32 value) {
  
  device_ = value;
  // @@protoc_insertion_point(field_set:mpis.RequestContext.device)
}

// int32 buffer_size = 3;
inline void RequestContext::clear_buffer_size() {
  buffer_size_ = 0;
}
inline ::google::protobuf::int32 RequestContext::buffer_size() const {
  // @@protoc_insertion_point(field_get:mpis.RequestContext.buffer_size)
  return buffer_size_;
}
inline void RequestContext::set_buffer_size(::google::protobuf::int32 value) {
  
  buffer_size_ = value;
  // @@protoc_insertion_point(field_set:mpis.RequestContext.buffer_size)
}

// int32 tag = 4;
inline void RequestContext::clear_tag() {
  tag_ = 0;
}
inline ::google::protobuf::int32 RequestContext::tag() const {
  // @@protoc_insertion_point(field_get:mpis.RequestContext.tag)
  return tag_;
}
inline void RequestContext::set_tag(::google::protobuf::int32 value) {
  
  tag_ = value;
  // @@protoc_insertion_point(field_set:mpis.RequestContext.tag)
}

// -------------------------------------------------------------------

// ReplyContext

// int32 status = 1;
inline void ReplyContext::clear_status() {
  status_ = 0;
}
inline ::google::protobuf::int32 ReplyContext::status() const {
  // @@protoc_insertion_point(field_get:mpis.ReplyContext.status)
  return status_;
}
inline void ReplyContext::set_status(::google::protobuf::int32 value) {
  
  status_ = value;
  // @@protoc_insertion_point(field_set:mpis.ReplyContext.status)
}

// int32 dst = 2;
inline void ReplyContext::clear_dst() {
  dst_ = 0;
}
inline ::google::protobuf::int32 ReplyContext::dst() const {
  // @@protoc_insertion_point(field_get:mpis.ReplyContext.dst)
  return dst_;
}
inline void ReplyContext::set_dst(::google::protobuf::int32 value) {
  
  dst_ = value;
  // @@protoc_insertion_point(field_set:mpis.ReplyContext.dst)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace mpis

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_mpi_2eproto__INCLUDED