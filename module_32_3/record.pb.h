// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: record.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_record_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_record_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017003 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_record_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_record_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_record_2eproto;
class Record;
struct RecordDefaultTypeInternal;
extern RecordDefaultTypeInternal _Record_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::Record* Arena::CreateMaybeMessage<::Record>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class Record final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Record) */ {
 public:
  inline Record() : Record(nullptr) {}
  ~Record() override;
  explicit constexpr Record(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Record(const Record& from);
  Record(Record&& from) noexcept
    : Record() {
    *this = ::std::move(from);
  }

  inline Record& operator=(const Record& from) {
    CopyFrom(from);
    return *this;
  }
  inline Record& operator=(Record&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Record& default_instance() {
    return *internal_default_instance();
  }
  static inline const Record* internal_default_instance() {
    return reinterpret_cast<const Record*>(
               &_Record_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Record& a, Record& b) {
    a.Swap(&b);
  }
  inline void Swap(Record* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Record* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Record* New() const final {
    return new Record();
  }

  Record* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Record>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Record& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Record& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to, const ::PROTOBUF_NAMESPACE_ID::Message&from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Record* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Record";
  }
  protected:
  explicit Record(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kLegalAddressFieldNumber = 1,
    kTitleFieldNumber = 2,
    kTypeActivityFieldNumber = 3,
    kImplementationForeignEconomicFieldNumber = 4,
    kYearFoundationFieldNumber = 1997,
  };
  // required string legal_address = 1;
  bool has_legal_address() const;
  private:
  bool _internal_has_legal_address() const;
  public:
  void clear_legal_address();
  const std::string& legal_address() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_legal_address(ArgT0&& arg0, ArgT... args);
  std::string* mutable_legal_address();
  PROTOBUF_MUST_USE_RESULT std::string* release_legal_address();
  void set_allocated_legal_address(std::string* legal_address);
  private:
  const std::string& _internal_legal_address() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_legal_address(const std::string& value);
  std::string* _internal_mutable_legal_address();
  public:

  // required string title = 2;
  bool has_title() const;
  private:
  bool _internal_has_title() const;
  public:
  void clear_title();
  const std::string& title() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_title(ArgT0&& arg0, ArgT... args);
  std::string* mutable_title();
  PROTOBUF_MUST_USE_RESULT std::string* release_title();
  void set_allocated_title(std::string* title);
  private:
  const std::string& _internal_title() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_title(const std::string& value);
  std::string* _internal_mutable_title();
  public:

  // optional string type_activity = 3;
  bool has_type_activity() const;
  private:
  bool _internal_has_type_activity() const;
  public:
  void clear_type_activity();
  const std::string& type_activity() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_type_activity(ArgT0&& arg0, ArgT... args);
  std::string* mutable_type_activity();
  PROTOBUF_MUST_USE_RESULT std::string* release_type_activity();
  void set_allocated_type_activity(std::string* type_activity);
  private:
  const std::string& _internal_type_activity() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_type_activity(const std::string& value);
  std::string* _internal_mutable_type_activity();
  public:

  // optional bool implementation_foreign_economic = 4;
  bool has_implementation_foreign_economic() const;
  private:
  bool _internal_has_implementation_foreign_economic() const;
  public:
  void clear_implementation_foreign_economic();
  bool implementation_foreign_economic() const;
  void set_implementation_foreign_economic(bool value);
  private:
  bool _internal_implementation_foreign_economic() const;
  void _internal_set_implementation_foreign_economic(bool value);
  public:

  // required int32 year_foundation = 1997;
  bool has_year_foundation() const;
  private:
  bool _internal_has_year_foundation() const;
  public:
  void clear_year_foundation();
  ::PROTOBUF_NAMESPACE_ID::int32 year_foundation() const;
  void set_year_foundation(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_year_foundation() const;
  void _internal_set_year_foundation(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:Record)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr legal_address_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr title_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr type_activity_;
  bool implementation_foreign_economic_;
  ::PROTOBUF_NAMESPACE_ID::int32 year_foundation_;
  friend struct ::TableStruct_record_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Record

// required int32 year_foundation = 1997;
inline bool Record::_internal_has_year_foundation() const {
  bool value = (_has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool Record::has_year_foundation() const {
  return _internal_has_year_foundation();
}
inline void Record::clear_year_foundation() {
  year_foundation_ = 0;
  _has_bits_[0] &= ~0x00000010u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Record::_internal_year_foundation() const {
  return year_foundation_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Record::year_foundation() const {
  // @@protoc_insertion_point(field_get:Record.year_foundation)
  return _internal_year_foundation();
}
inline void Record::_internal_set_year_foundation(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000010u;
  year_foundation_ = value;
}
inline void Record::set_year_foundation(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_year_foundation(value);
  // @@protoc_insertion_point(field_set:Record.year_foundation)
}

// required string legal_address = 1;
inline bool Record::_internal_has_legal_address() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool Record::has_legal_address() const {
  return _internal_has_legal_address();
}
inline void Record::clear_legal_address() {
  legal_address_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& Record::legal_address() const {
  // @@protoc_insertion_point(field_get:Record.legal_address)
  return _internal_legal_address();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Record::set_legal_address(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000001u;
 legal_address_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Record.legal_address)
}
inline std::string* Record::mutable_legal_address() {
  std::string* _s = _internal_mutable_legal_address();
  // @@protoc_insertion_point(field_mutable:Record.legal_address)
  return _s;
}
inline const std::string& Record::_internal_legal_address() const {
  return legal_address_.Get();
}
inline void Record::_internal_set_legal_address(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  legal_address_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Record::_internal_mutable_legal_address() {
  _has_bits_[0] |= 0x00000001u;
  return legal_address_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Record::release_legal_address() {
  // @@protoc_insertion_point(field_release:Record.legal_address)
  if (!_internal_has_legal_address()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return legal_address_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Record::set_allocated_legal_address(std::string* legal_address) {
  if (legal_address != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  legal_address_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), legal_address,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:Record.legal_address)
}

// required string title = 2;
inline bool Record::_internal_has_title() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool Record::has_title() const {
  return _internal_has_title();
}
inline void Record::clear_title() {
  title_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000002u;
}
inline const std::string& Record::title() const {
  // @@protoc_insertion_point(field_get:Record.title)
  return _internal_title();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Record::set_title(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000002u;
 title_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Record.title)
}
inline std::string* Record::mutable_title() {
  std::string* _s = _internal_mutable_title();
  // @@protoc_insertion_point(field_mutable:Record.title)
  return _s;
}
inline const std::string& Record::_internal_title() const {
  return title_.Get();
}
inline void Record::_internal_set_title(const std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  title_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Record::_internal_mutable_title() {
  _has_bits_[0] |= 0x00000002u;
  return title_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Record::release_title() {
  // @@protoc_insertion_point(field_release:Record.title)
  if (!_internal_has_title()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  return title_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Record::set_allocated_title(std::string* title) {
  if (title != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  title_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), title,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:Record.title)
}

// optional string type_activity = 3;
inline bool Record::_internal_has_type_activity() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool Record::has_type_activity() const {
  return _internal_has_type_activity();
}
inline void Record::clear_type_activity() {
  type_activity_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000004u;
}
inline const std::string& Record::type_activity() const {
  // @@protoc_insertion_point(field_get:Record.type_activity)
  return _internal_type_activity();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Record::set_type_activity(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000004u;
 type_activity_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Record.type_activity)
}
inline std::string* Record::mutable_type_activity() {
  std::string* _s = _internal_mutable_type_activity();
  // @@protoc_insertion_point(field_mutable:Record.type_activity)
  return _s;
}
inline const std::string& Record::_internal_type_activity() const {
  return type_activity_.Get();
}
inline void Record::_internal_set_type_activity(const std::string& value) {
  _has_bits_[0] |= 0x00000004u;
  type_activity_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Record::_internal_mutable_type_activity() {
  _has_bits_[0] |= 0x00000004u;
  return type_activity_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Record::release_type_activity() {
  // @@protoc_insertion_point(field_release:Record.type_activity)
  if (!_internal_has_type_activity()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000004u;
  return type_activity_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Record::set_allocated_type_activity(std::string* type_activity) {
  if (type_activity != nullptr) {
    _has_bits_[0] |= 0x00000004u;
  } else {
    _has_bits_[0] &= ~0x00000004u;
  }
  type_activity_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), type_activity,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:Record.type_activity)
}

// optional bool implementation_foreign_economic = 4;
inline bool Record::_internal_has_implementation_foreign_economic() const {
  bool value = (_has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool Record::has_implementation_foreign_economic() const {
  return _internal_has_implementation_foreign_economic();
}
inline void Record::clear_implementation_foreign_economic() {
  implementation_foreign_economic_ = false;
  _has_bits_[0] &= ~0x00000008u;
}
inline bool Record::_internal_implementation_foreign_economic() const {
  return implementation_foreign_economic_;
}
inline bool Record::implementation_foreign_economic() const {
  // @@protoc_insertion_point(field_get:Record.implementation_foreign_economic)
  return _internal_implementation_foreign_economic();
}
inline void Record::_internal_set_implementation_foreign_economic(bool value) {
  _has_bits_[0] |= 0x00000008u;
  implementation_foreign_economic_ = value;
}
inline void Record::set_implementation_foreign_economic(bool value) {
  _internal_set_implementation_foreign_economic(value);
  // @@protoc_insertion_point(field_set:Record.implementation_foreign_economic)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_record_2eproto
