/*========================== begin_copyright_notice ============================

Copyright (C) 2019-2024 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#if (__INCLUDE_LEVEL__ == 1)
static_assert(0, "CM:w:cm_lsc.h should not be included explicitly - only "
                 "<cm/cm.h> is required");
#endif

#ifndef _CLANG_CM_LSC_H_
#define _CLANG_CM_LSC_H_

#include "cm_common.h"
#include "cm_has_instr.h"
#include "cm_internal.h"

namespace details {

template <CacheHint Hint> class CacheHintWrap {
private:
  template <CacheHint...> class is_one_of_t;

  template <CacheHint Last>
  struct is_one_of_t<Last>
      : public std::conditional<Last == Hint, std::true_type,
                                std::false_type>::type {};

  template <CacheHint Head, CacheHint... Tail>
  struct is_one_of_t<Head, Tail...>
      : public std::conditional<Head == Hint, std::true_type,
                                is_one_of_t<Tail...>>::type {};

public:
  constexpr operator CacheHint() const { return Hint; }

  template <CacheHint... Hints> static constexpr bool is_one_of() {
    return is_one_of_t<Hints...>::value;
  }
};

template <CacheHint Val>
constexpr bool are_all_equal_to(CacheHint First, CacheHint Second) {
  return First == Val && Second == Val;
}

template <CacheHint L1, CacheHint L2>
constexpr bool lsc_check_cache_hint_prefetch() {
  constexpr CacheHintWrap<L1> L1H;
  constexpr CacheHintWrap<L2> L2H;
  bool Res = are_all_equal_to<CacheHint::Default>(L1H, L2H) ||
             (L1H.is_one_of<CacheHint::Uncached, CacheHint::Cached,
                            CacheHint::Streaming>() &&
              L2H.is_one_of<CacheHint::Uncached, CacheHint::Cached>() &&
              !are_all_equal_to<CacheHint::Uncached>(L1H, L2H));
#ifdef CM_HAS_LSC_L1L3CC_HINT
  Res = Res || (L1H.is_one_of<CacheHint::Uncached, CacheHint::Cached>() &&
                L2H == CacheHint::ConstCached);
#endif // CM_HAS_LSC_L1L3CC_HINT
  return Res;
}

template <CacheHint L1, CacheHint L2>
constexpr bool lsc_check_cache_hint_load() {
  constexpr CacheHintWrap<L1> L1H;
  constexpr CacheHintWrap<L2> L2H;
  bool Res = are_all_equal_to<CacheHint::Default>(L1H, L2H) ||
             (L1H.is_one_of<CacheHint::Uncached, CacheHint::Cached,
                            CacheHint::Streaming>() &&
              L2H.is_one_of<CacheHint::Uncached, CacheHint::Cached>());
#ifdef CM_HAS_LSC_L1L3CC_HINT
  Res = Res || (L1H.is_one_of<CacheHint::Uncached, CacheHint::Cached>() &&
                L2H == CacheHint::ConstCached);
#endif // CM_HAS_LSC_L1L3CC_HINT
#ifdef CM_HAS_LSC_LOAD_L1RI_L3RI_HINT
  Res = Res || are_all_equal_to<CacheHint::ReadInvalidate>(L1H, L2H);
#endif // CM_HAS_LSC_LOAD_L1RI_L3RI_HINT
#ifdef CM_HAS_LSC_LOAD_L1RI_L3CA_HINT
  Res = Res || (L1H == CacheHint::ReadInvalidate && L2H == CacheHint::Cached);
#endif // CM_HAS_LSC_LOAD_L1RI_L3CA_HINT
  return Res;
}

template <CacheHint L1, CacheHint L2>
constexpr bool lsc_check_cache_hint_store() {
  constexpr CacheHintWrap<L1> L1H;
  constexpr CacheHintWrap<L2> L2H;
  return are_all_equal_to<CacheHint::Default>(L1H, L2H) ||
         are_all_equal_to<CacheHint::WriteBack>(L1H, L2H) ||
         (L1H.is_one_of<CacheHint::Uncached, CacheHint::WriteThrough,
                        CacheHint::Streaming>() &&
          L2H.is_one_of<CacheHint::Uncached, CacheHint::WriteBack>());
}

template <CacheHint L1, CacheHint L2>
constexpr bool lsc_check_cache_hint_atomic() {
  constexpr CacheHintWrap<L1> L1H;
  constexpr CacheHintWrap<L2> L2H;
  return are_all_equal_to<CacheHint::Default>(L1H, L2H) ||
         (L1H == CacheHint::Uncached &&
          L2H.is_one_of<CacheHint::Uncached, CacheHint::WriteBack>());
}
} // namespace details

/// \brief Data prefetch.
///
/// @param VS Vector size
///
/// @param DS Data size
///
/// @param L1H L1 cache hint
///
/// @param L2H L2 chache hint
///
/// @param N The number of channels (platform dependent)
///
/// @param Idx Surface index, which must correspond to a buffer.
///
/// @param Offset zero based offset of the input buffer in bytes.
///
/// @param Pred Predicate
///
template <VectorSize VS = VectorSize::N1, DataSize DS = DataSize::U32,
          CacheHint L1H = CacheHint::Cached, CacheHint L2H = CacheHint::Cached,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE void cm_prefetch(SurfaceIndex Idx,
                                      vector<unsigned, N> Offset,
                                      vector<ushort, N> Pred = 1) {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_prefetch<L1H, L2H>()),
                  "unsupported cache hint");
  constexpr int ImmOffset = 0;
  __cm_intrinsic_impl_prefetch_bti<DS, VS, ImmOffset, L1H, L2H, N>(Idx, Offset,
                                                                   Pred);
}

/// flat-address prefetch
template <VectorSize VS = VectorSize::N1, DataSize DS = DataSize::U32,
          CacheHint L1H = CacheHint::Cached, CacheHint L2H = CacheHint::Cached,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE void cm_ptr_prefetch(const void *const Ptr,
                                          vector<unsigned, N> Offset,
                                          vector<ushort, N> Pred = 1) {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_prefetch<L1H, L2H>()),
                  "unsupported cache hint");
  constexpr int ImmOffset = 0;
  uint64_t Addr = (uint64_t)Ptr;
  __cm_intrinsic_impl_prefetch_flat<DS, VS, ImmOffset, L1H, L2H, N>(
      Addr, Offset, Pred);
}

/// Surface-based Block prefetch.
template <VectorSize VS, DataSize DS = DataSize::U32,
          CacheHint L1H = CacheHint::Cached,
          CacheHint L2H = CacheHint::Cached>
CM_NODEBUG CM_INLINE void cm_prefetch(SurfaceIndex Idx, unsigned Offset) {
  using namespace details;
  CM_HAS_LSC_CONTROL;

  CM_STATIC_WARNING(details::always_false<decltype(VS)>(),
                    "Please use new interface with explicit NElts");
  CM_STATIC_ERROR(
      DS == DataSize::U32 || DS == DataSize::U64,
      "Transposed prefetch can work only with U32 and U64 data sizes");
  CM_STATIC_ERROR((lsc_check_cache_hint_prefetch<L1H, L2H>()),
                  "unsupported cache hint");
  constexpr int _ImmOffset = 0;
  details::__cm_intrinsic_impl_block_prefetch_bti<DS, VS, _ImmOffset, L1H, L2H>(
      Idx, Offset);
}

// Surface-based block prefetch, new interface
template <int NElts, DataSize DS = DataSize::U32,
          CacheHint L1H = CacheHint::Cached,
          CacheHint L2H = CacheHint::Cached>
CM_NODEBUG CM_INLINE void cm_prefetch(SurfaceIndex Idx, unsigned Offset) {
  using namespace details;
  CM_HAS_LSC_CONTROL;

  CM_STATIC_ERROR(
      DS == DataSize::U32 || DS == DataSize::U64,
      "Transposed prefetch can work only with U32 and U64 data sizes");
  CM_STATIC_ERROR((lsc_check_cache_hint_prefetch<L1H, L2H>()),
                  "unsupported cache hint");
  constexpr int _ImmOffset = 0;
  constexpr VectorSize VS = details::lsc_vector_size<NElts>();
  details::__cm_intrinsic_impl_block_prefetch_bti<DS, VS, _ImmOffset, L1H, L2H>(
      Idx, Offset);
}

/// Flat-address Block prefetch.
template <VectorSize VS, DataSize DS = DataSize::U32,
          CacheHint L1H = CacheHint::Cached,
          CacheHint L2H = CacheHint::Cached>
CM_NODEBUG CM_INLINE void cm_ptr_prefetch(const unsigned *const Ptr,
                                          unsigned Offset) {
  using namespace details;
  CM_HAS_LSC_CONTROL;

  CM_STATIC_WARNING(details::always_false<decltype(VS)>(),
                    "Please use new interface with explicit NElts");
  CM_STATIC_ERROR(
      DS == DataSize::U32 || DS == DataSize::U64,
      "Transposed prefetch can work only with U32 and U64 data sizes");
  CM_STATIC_ERROR((lsc_check_cache_hint_prefetch<L1H, L2H>()),
                  "unsupported cache hint");
  constexpr int _ImmOffset = 0;
  uint64_t _Addr = (uint64_t)Ptr;
  details::__cm_intrinsic_impl_block_prefetch_flat<DS, VS, _ImmOffset, L1H,
                                                   L2H>(_Addr, Offset);
}

/// Flat-address Block prefetch, new interface
template <int NElts, DataSize DS = DataSize::U32,
          CacheHint L1H = CacheHint::Cached,
          CacheHint L2H = CacheHint::Cached>
CM_NODEBUG CM_INLINE void cm_ptr_prefetch(const unsigned *const Ptr,
                                          unsigned Offset) {
  using namespace details;
  CM_HAS_LSC_CONTROL;

  CM_STATIC_ERROR(
      DS == DataSize::U32 || DS == DataSize::U64,
      "Transposed prefetch can work only with U32 and U64 data sizes");
  CM_STATIC_ERROR((lsc_check_cache_hint_prefetch<L1H, L2H>()),
                  "unsupported cache hint");
  constexpr int ImmOffset = 0;
  constexpr VectorSize VS = details::lsc_vector_size<NElts>();
  uint64_t Addr = (uint64_t)Ptr;
  details::__cm_intrinsic_impl_block_prefetch_flat<DS, VS, ImmOffset, L1H, L2H>(
      Addr, Offset);
}

/// \brief Data Read.
///
/// @param T The return element data type.
///
/// @param N The number of channels (platform dependent)
///
/// @param VS Vector size
///
/// @param DS Data size
///
/// @param L1H L1 cache hint
///
/// @param L2H L2 chache hint
///
/// @param Pred Predicate
///
/// @param Idx Surface index, which must correspond to a buffer.
///
/// @param Offset zero based offset of the input buffer in bytes.
///
/// BTI non-transposed load
template <typename T, VectorSize VS = VectorSize::N1,
          DataSize DS = DataSize::Default, CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE auto cm_load(SurfaceIndex Idx, vector<unsigned, N> Offset,
                                  vector<ushort, N> Pred = 1) {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_load<L1H, L2H>()),
                  "unsupported cache hint");
  CM_HAS_LSC_NON_TRANSPOSE_MESSAGES_WITH_NON_DEFAULT_SIMT_CONTROL(N, VS);
  using _MessTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _RetTy = decltype(lsc_data_type<T, N, VS>());
  constexpr DataSize _DS = lsc_expand_ds(lsc_data_size<T, DS>());
  constexpr int _ImmOffset = 0;
  constexpr bool _Transposed = false;
  auto _TmpRes =
      __cm_intrinsic_impl_load_bti<_MessTy, _DS, VS, _ImmOffset, L1H, L2H,
                                   _Transposed, N>(Idx, Offset, Pred);
  return lsc_format_ret<T, _MessTy, _RetTy>(_TmpRes);
}

/// Flat-address non-transposed load
template <typename T, VectorSize VS = VectorSize::N1,
          DataSize DS = DataSize::Default, CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE auto cm_ptr_load(const T *const Ptr,
                                      vector<unsigned, N> Offset,
                                      vector<ushort, N> Pred = 1) {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_load<L1H, L2H>()),
                  "unsupported cache hint");
  CM_HAS_LSC_NON_TRANSPOSE_MESSAGES_WITH_NON_DEFAULT_SIMT_CONTROL(N, VS);
  using _MessTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _RetTy = decltype(lsc_data_type<T, N, VS>());
  constexpr DataSize _DS = lsc_expand_ds(lsc_data_size<T, DS>());
  constexpr int _ImmOffset = 0;
  constexpr bool _Transposed = false;
  uint64_t _Addr = (uint64_t)Ptr;
  auto _TmpRes =
      __cm_intrinsic_impl_load_flat<_MessTy, _DS, VS, _ImmOffset, L1H, L2H,
                                    _Transposed, N>(_Addr, Offset, Pred);
  return lsc_format_ret<T, _MessTy, _RetTy>(_TmpRes);
}

// Block-load with a SurfaceIndex
template <typename T, VectorSize VS, DataSize DS = DataSize::Default,
          CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default>
CM_NODEBUG CM_INLINE auto cm_load(SurfaceIndex Idx, unsigned Offset) {
  using namespace details;
  CM_HAS_LSC_CONTROL;

  CM_STATIC_WARNING(details::always_false<decltype(VS)>(),
                    "Please use new interface with explicit NElts");
  CM_STATIC_ERROR((lsc_check_cache_hint_load<L1H, L2H>()),
                  "unsupported cache hint");
  using _RetTy = decltype(details::lsc_data_type<T, 1, VS>());
  static_assert(VS != VectorSize::N0, "invalid vector size");
  constexpr DataSize _DS = details::lsc_data_size<T, DS>();
  CM_STATIC_ERROR(_DS == DataSize::U32 || _DS == DataSize::U64,
                  "Transposed load can work only with U32 and U64 data sizes");
  constexpr int _ImmOffset = 0;
  constexpr bool _Transposed = true;
  return details::__cm_intrinsic_impl_block_load_bti<
      _RetTy, _DS, VS, _ImmOffset, L1H, L2H, _Transposed>(Idx, Offset);
}

// Block-load with a SurfaceIndex, new interface
template <typename T, int NElts, DataSize DS = DataSize::Default,
          CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default>
CM_NODEBUG CM_INLINE auto cm_load(SurfaceIndex Idx, unsigned Offset) {
  using namespace details;
  CM_HAS_LSC_CONTROL;

  CM_STATIC_ERROR((lsc_check_cache_hint_load<L1H, L2H>()),
                  "unsupported cache hint");
  constexpr VectorSize VS = details::lsc_vector_size<NElts>();
  using _RetTy = decltype(details::lsc_data_type<T, 1, VS>());
  static_assert(VS != VectorSize::N0, "invalid vector size");
  constexpr DataSize _DS = details::lsc_data_size<T, DS>();
  CM_STATIC_ERROR(_DS == DataSize::U32 || _DS == DataSize::U64,
                  "Transposed load can work only with U32 and U64 data sizes");
  constexpr int _ImmOffset = 0;
  constexpr bool _Transposed = true;
  return details::__cm_intrinsic_impl_block_load_bti<
      _RetTy, _DS, VS, _ImmOffset, L1H, L2H, _Transposed>(Idx, Offset);
}

// Block-load with a base-pointer to the buffer
template <typename T, VectorSize VS, DataSize DS = DataSize::Default,
          CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default>
CM_NODEBUG CM_INLINE auto cm_ptr_load(const T *const Ptr, unsigned Offset) {
  using namespace details;
  CM_HAS_LSC_CONTROL;

  CM_STATIC_ERROR((lsc_check_cache_hint_load<L1H, L2H>()),
                  "unsupported cache hint");
  CM_STATIC_WARNING(details::always_false<decltype(VS)>(),
                    "Please use new interface with explicit NElts");
  using _RetTy = decltype(details::lsc_data_type<T, 1, VS>());
  static_assert(VS != VectorSize::N0, "invalid vector size");
  constexpr DataSize _DS = details::lsc_data_size<T, DS>();
  CM_STATIC_ERROR(_DS == DataSize::U32 || _DS == DataSize::U64,
                  "Transposed load can work only with U32 and U64 data sizes");
  constexpr int _ImmOffset = 0;
  constexpr bool _Transposed = true;
  uint64_t _Addr = (uint64_t)Ptr;
  return details::__cm_intrinsic_impl_block_load_flat<
      _RetTy, _DS, VS, _ImmOffset, L1H, L2H, _Transposed>(_Addr, Offset);
}
// Block-load with a base-pointer to the buffer, new interface
template <typename T, int NElts, DataSize DS = DataSize::Default,
          CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default>
CM_NODEBUG CM_INLINE auto cm_ptr_load(const T *const Ptr, unsigned Offset) {
  using namespace details;
  CM_HAS_LSC_CONTROL;

  CM_STATIC_ERROR((lsc_check_cache_hint_load<L1H, L2H>()),
                  "unsupported cache hint");
  constexpr VectorSize VS = details::lsc_vector_size<NElts>();
  using _RetTy = decltype(details::lsc_data_type<T, 1, VS>());
  static_assert(VS != VectorSize::N0, "invalid vector size");
  constexpr DataSize _DS = details::lsc_data_size<T, DS>();
  CM_STATIC_ERROR(_DS == DataSize::U32 || _DS == DataSize::U64,
                  "Transposed load can work only with U32 and U64 data sizes");
  constexpr int _ImmOffset = 0;
  constexpr bool _Transposed = true;
  uint64_t _Addr = (uint64_t)Ptr;
  return details::__cm_intrinsic_impl_block_load_flat<
      _RetTy, _DS, VS, _ImmOffset, L1H, L2H, _Transposed>(_Addr, Offset);
}

/// BTI non-transposed quad load
///   * vector size is always 4 for quad so it is not specified
///   * store is always transposed, so no block version
template <typename T, ChannelMaskType Mask, DataSize DS = DataSize::Default,
          CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE auto cm_load4(SurfaceIndex Idx, vector<unsigned, N> Offset,
                                   vector<ushort, N> Pred = 1) {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_load<L1H, L2H>()),
                  "unsupported cache hint");
  constexpr VectorSize _VS =
      details::lsc_get_vector_size_from_channel_mask<Mask>();
  CM_HAS_LSC_NON_TRANSPOSE_MESSAGES_WITH_NON_DEFAULT_SIMT_CONTROL(N, _VS);
  using _MessTy = decltype(lsc_data_type_ext<T, N, _VS>());
  using _RetTy = decltype(lsc_data_type<T, N, _VS>());
  constexpr DataSize _DS = lsc_expand_ds(lsc_data_size<T, DS>());
  constexpr int _ImmOffset = 0;
  constexpr bool _Transposed = false;
  auto _TmpRes =
      __cm_intrinsic_impl_load4_bti<_MessTy, _DS, _VS, _ImmOffset, L1H, L2H,
                                    _Transposed, N>(Idx, Offset, Pred, Mask);
  return lsc_format_ret<T, _MessTy, _RetTy>(_TmpRes);
}

/// Flat-address non-transposed quad load
template <typename T, ChannelMaskType Mask, DataSize DS = DataSize::Default,
          CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE auto cm_ptr_load4(const T *const Ptr,
                                       vector<unsigned, N> Offset,
                                       vector<ushort, N> Pred = 1) {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_load<L1H, L2H>()),
                  "unsupported cache hint");
  constexpr VectorSize _VS =
      details::lsc_get_vector_size_from_channel_mask<Mask>();
  CM_HAS_LSC_NON_TRANSPOSE_MESSAGES_WITH_NON_DEFAULT_SIMT_CONTROL(N, _VS);
  using _MessTy = decltype(lsc_data_type_ext<T, N, _VS>());
  using _RetTy = decltype(lsc_data_type_ext<T, N, _VS>());
  constexpr DataSize _DS = lsc_expand_ds(lsc_data_size<T, DS>());
  constexpr int _ImmOffset = 0;
  constexpr bool _Transposed = false;
  uint64_t _Addr = (uint64_t)Ptr;
  auto _TmpRes =
      __cm_intrinsic_impl_load4_flat<_MessTy, _DS, _VS, _ImmOffset, L1H, L2H,
                                     _Transposed, N>(_Addr, Offset, Pred, Mask);
  return lsc_format_ret<T, _MessTy, _RetTy>(_TmpRes);
}

/// \brief Data Write.
///
/// @param T The element data type.
///
/// @param N The number of channels (platform dependent)
///
/// @param NElts The number of element to store (for block store only)
///
/// @param VS Vector size
///
/// @param DS Data size
///
/// @param L1H L1 cache hint
///
/// @param L2H L2 chache hint
///
/// @param Pred Predicate
///
/// @param Idx Surface index, which must correspond to a buffer.
///
/// @param Offset zero based offset of the output buffer in bytes.
///
/// @param Data data to write.
///
template <typename T, VectorSize VS = VectorSize::N1,
          DataSize DS = DataSize::Default, CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE void
cm_store(SurfaceIndex Idx, vector<unsigned, N> Offset,
         vector<T, N * details::lsc_vector_size<VS>()> Data,
         vector<ushort, N> Pred = 1) {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_store<L1H, L2H>()),
                  "unsupported cache hint");
  CM_HAS_LSC_NON_TRANSPOSE_MESSAGES_WITH_NON_DEFAULT_SIMT_CONTROL(N, VS);
  constexpr DataSize _DS = lsc_expand_ds(details::lsc_data_size<T, DS>());
  constexpr int _ImmOffset = 0;
  constexpr bool _Transposed = false;
  using _StTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _CastTy = typename lsc_bitcast_type<T>::type;
  _StTy _TmpData = Data.format<_CastTy>();
  details::__cm_intrinsic_impl_store_bti<typename lsc_expand_type<T>::type, _DS,
                                         VS, _ImmOffset, L1H, L2H, _Transposed,
                                         N>(Idx, Offset, _TmpData, Pred);
}
/// Flat-address store using a base-address to a buffer
template <typename T, VectorSize VS = VectorSize::N1,
          DataSize DS = DataSize::Default, CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE void
cm_ptr_store(T *Ptr, vector<unsigned, N> Offset,
             vector<T, N * details::lsc_vector_size<VS>()> Data,
             vector<ushort, N> Pred = 1) {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_store<L1H, L2H>()),
                  "unsupported cache hint");
  CM_HAS_LSC_NON_TRANSPOSE_MESSAGES_WITH_NON_DEFAULT_SIMT_CONTROL(N, VS);
  constexpr DataSize _DS = lsc_expand_ds(details::lsc_data_size<T, DS>());
  constexpr int _ImmOffset = 0;
  constexpr bool _Transposed = false;
  uint64_t _Addr = (uint64_t)Ptr;
  using _StTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _CastTy = typename lsc_bitcast_type<T>::type;
  _StTy _TmpData = Data.format<_CastTy>();
  details::__cm_intrinsic_impl_store_flat<typename lsc_expand_type<T>::type,
                                          _DS, VS, _ImmOffset, L1H, L2H,
                                          _Transposed, N>(_Addr, Offset,
                                                          _TmpData, Pred);
}

/// Quad version of BTI store:
///   * vector size is always 4 for quad so it is not specified
///   * store is always transposed, so no block version
template <typename T, ChannelMaskType Mask, DataSize DS = DataSize::Default,
          CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE void cm_store4(
    SurfaceIndex Idx, vector<unsigned, N> Offset,
    vector<T, N * details::lsc_get_num_elements_from_channel_mask<Mask>()> Data,
    vector<ushort, N> Pred = 1) {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_store<L1H, L2H>()),
                  "unsupported cache hint");
  constexpr VectorSize _VS =
      details::lsc_get_vector_size_from_channel_mask<Mask>();
  CM_HAS_LSC_NON_TRANSPOSE_MESSAGES_WITH_NON_DEFAULT_SIMT_CONTROL(N, _VS);
  constexpr DataSize _DS = lsc_expand_ds(details::lsc_data_size<T, DS>());
  constexpr int _ImmOffset = 0;
  constexpr bool _Transposed = false;
  using _StTy = decltype(lsc_data_type_ext<T, N, _VS>());
  using _CastTy = typename lsc_bitcast_type<T>::type;
  _StTy _TmpData = Data.format<_CastTy>();
  details::__cm_intrinsic_impl_store4_bti<typename lsc_expand_type<T>::type,
                                          _DS, _VS, _ImmOffset, L1H, L2H,
                                          _Transposed, N>(Idx, Offset, _TmpData,
                                                          Pred, Mask);
}

/// Quad version of flat store
template <typename T, ChannelMaskType Mask, DataSize DS = DataSize::Default,
          CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE void cm_ptr_store4(
    T *Ptr, vector<unsigned, N> Offset,
    vector<T, N * details::lsc_get_num_elements_from_channel_mask<Mask>()> Data,
    vector<ushort, N> Pred = 1) {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_store<L1H, L2H>()),
                  "unsupported cache hint");
  constexpr VectorSize _VS =
      details::lsc_get_vector_size_from_channel_mask<Mask>();
  CM_HAS_LSC_NON_TRANSPOSE_MESSAGES_WITH_NON_DEFAULT_SIMT_CONTROL(N, _VS);
  constexpr DataSize _DS = lsc_expand_ds(details::lsc_data_size<T, DS>());
  constexpr int _ImmOffset = 0;
  constexpr bool _Transposed = false;
  uint64_t _Addr = (uint64_t)Ptr;
  using _StTy = decltype(lsc_data_type_ext<T, N, _VS>());
  using _CastTy = typename lsc_bitcast_type<T>::type;
  _StTy _TmpData = Data.format<_CastTy>();
  details::__cm_intrinsic_impl_store4_flat<typename lsc_expand_type<T>::type,
                                           _DS, _VS, _ImmOffset, L1H, L2H,
                                           _Transposed, N>(
      _Addr, Offset, _TmpData, Pred, Mask);
}

/// Block store with a SurfaceIndex.
template <typename T, int NElts, DataSize DS = DataSize::Default,
          CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default>
CM_NODEBUG CM_INLINE void cm_store(SurfaceIndex Idx, unsigned Offset,
                                   vector<T, NElts> Data) {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_store<L1H, L2H>()),
                  "unsupported cache hint");
  constexpr DataSize _DS = lsc_data_size<T, DS>();
  CM_STATIC_ERROR(_DS == DataSize::U32 || _DS == DataSize::U64,
                  "Transposed store can work only with U32 and U64 data sizes");
  constexpr VectorSize _VS = lsc_vector_size<NElts>();
  static_assert(_VS != VectorSize::N0, "invalid vector size");
  constexpr int _ImmOffset = 0;
  constexpr bool _Transposed = true;
  __cm_intrinsic_impl_block_store_bti<T, _DS, _VS, _ImmOffset, L1H, L2H,
                                      _Transposed>(Idx, Offset, Data);
}

/// Block store with a base pointer.
template <typename T, int NElts, DataSize DS = DataSize::Default,
          CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default>
CM_NODEBUG CM_INLINE void cm_ptr_store(T *ptr, unsigned Offset,
                                       vector<T, NElts> Data) {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_store<L1H, L2H>()),
                  "unsupported cache hint");
  constexpr DataSize _DS = lsc_data_size<T, DS>();
  CM_STATIC_ERROR(_DS == DataSize::U32 || _DS == DataSize::U64,
                  "Transposed store can work only with U32 and U64 data sizes");
  constexpr VectorSize _VS = lsc_vector_size<NElts>();
  static_assert(_VS != VectorSize::N0, "invalid vector size");
  constexpr int _ImmOffset = 0;
  constexpr bool _Transposed = true;
  uint64_t _Addr = (uint64_t)ptr;
  __cm_intrinsic_impl_block_store_flat<T, _DS, _VS, _ImmOffset, L1H, L2H,
                                       _Transposed>(_Addr, Offset, Data);
}

/// \brief SLM Data Read.
///
/// @param T The return element data type.
///
/// @param N The number of channels (platform dependent)
///
/// @param VS Vector size
///
/// @param DS Data size
///
/// @param Pred Predicate
///
/// @param Offset zero based offset of the input SLM buffer in bytes.
///

// Non-transposed SLM load
template <typename T, VectorSize VS = VectorSize::N1,
          DataSize DS = DataSize::Default, int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE auto cm_load_slm(vector<unsigned, N> Offset,
                                      vector<ushort, N> Pred = 1) {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  CM_HAS_LSC_NON_TRANSPOSE_MESSAGES_WITH_NON_DEFAULT_SIMT_CONTROL(N, VS);
  using _MessTy = decltype(details::lsc_data_type_ext<T, N, VS>());
  using _RetTy = decltype(lsc_data_type<T, N, VS>());
  constexpr DataSize _DS = lsc_expand_ds(details::lsc_data_size<T, DS>());
  constexpr int _ImmOffset = 0;
  constexpr bool _Transposed = false;
  auto _TmpRes =
      details::__cm_intrinsic_impl_load_slm<_MessTy, _DS, VS, _ImmOffset,
                                            _Transposed>(Offset, Pred);
  return lsc_format_ret<T, _MessTy, _RetTy>(_TmpRes);
}

// Non-transposed SLM quad load
template <typename T, ChannelMaskType Mask, DataSize DS = DataSize::Default,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE auto cm_load4_slm(vector<unsigned, N> Offset,
                                       vector<ushort, N> Pred = 1) {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  constexpr VectorSize _VS =
      details::lsc_get_vector_size_from_channel_mask<Mask>();
  CM_HAS_LSC_NON_TRANSPOSE_MESSAGES_WITH_NON_DEFAULT_SIMT_CONTROL(N, _VS);
  using _MessTy = decltype(details::lsc_data_type_ext<T, N, _VS>());
  using _RetTy = decltype(lsc_data_type<T, N, _VS>());
  constexpr DataSize DS_ = lsc_expand_ds(details::lsc_data_size<T, DS>());
  constexpr int ImmOffset = 0;
  constexpr bool Transposed = false;
  auto _TmpRes =
      details::__cm_intrinsic_impl_load4_slm<_MessTy, DS_, _VS, ImmOffset,
                                             Transposed>(Offset, Pred, Mask);
  auto _Formatted = _TmpRes.format<T>();
  constexpr int stride = _Formatted.n_elems() / _TmpRes.n_elems();
  _RetTy _Res = _Formatted.select<_TmpRes.n_elems(), stride>(0);
  return _Res;
}

/// \brief SLM Data Write.
///
/// @param T The element data type.
///
/// @param N The number of channels (platform dependent)
///
/// @param NElts The number of element to store (for block store only)
///
/// @param VS Vector size
///
/// @param DS Data size
///
/// @param Pred Predicate
///
/// @param Offset zero based offset of the output SLM buffer in bytes.
///
/// @param Data data to write.
///
template <typename T, VectorSize VS = VectorSize::N1,
          DataSize DS = DataSize::Default, int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE void
cm_store_slm(vector<unsigned, N> Offset,
             vector<T, N * details::lsc_vector_size<VS>()> Data,
             vector<ushort, N> Pred = 1) {
  CM_HAS_LSC_CONTROL;

  CM_STATIC_WARNING(details::always_false<decltype(VS)>(),
                    "Please use new interface with explicit NElts");
  using namespace details;
  CM_HAS_LSC_NON_TRANSPOSE_MESSAGES_WITH_NON_DEFAULT_SIMT_CONTROL(N, VS);
  constexpr DataSize _DS = lsc_expand_ds(details::lsc_data_size<T, DS>());
  constexpr int _ImmOffset = 0;
  constexpr bool _Transposed = false;
  using _StTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _CastTy = typename lsc_bitcast_type<T>::type;
  _StTy _TmpData = Data.format<_CastTy>();
  details::__cm_intrinsic_impl_store_slm<typename lsc_expand_type<T>::type, _DS,
                                         VS, _ImmOffset, _Transposed, N>(
      Offset, _TmpData, Pred);
}

// explicit NElts version
template <typename T, int NElts, DataSize DS = DataSize::Default,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE void
cm_store_slm(vector<unsigned, N> Offset,
             vector<T, N * details::lsc_vector_size<NElts>()> Data,
             vector<ushort, N> Pred = 1) {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  CM_HAS_LSC_NON_TRANSPOSE_MESSAGES_WITH_NON_DEFAULT_SIMT_CONTROL(
      N, details::lsc_vector_size<NElts>());
  constexpr DataSize DS_ = lsc_expand_ds(details::lsc_data_size<T, DS>());
  constexpr int ImmOffset = 0;
  constexpr bool Transposed = false;
  constexpr VectorSize VS = details::lsc_vector_size<NElts>();
  using _StTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _CastTy = typename lsc_bitcast_type<T>::type;
  _StTy _TmpData = Data.format<_CastTy>();
  details::__cm_intrinsic_impl_store_slm<typename lsc_expand_type<T>::type, DS_,
                                         VS, ImmOffset, Transposed, N>(
      Offset, _TmpData, Pred);
}

// Quad version
template <typename T, ChannelMaskType Mask, DataSize DS = DataSize::Default,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE void cm_store4_slm(
    vector<unsigned, N> Offset,
    vector<T, N * details::lsc_get_num_elements_from_channel_mask<Mask>()> Data,
    vector<ushort, N> Pred = 1) {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  constexpr DataSize _DS = lsc_expand_ds(details::lsc_data_size<T, DS>());
  constexpr VectorSize _VS =
      details::lsc_get_vector_size_from_channel_mask<Mask>();
  CM_HAS_LSC_NON_TRANSPOSE_MESSAGES_WITH_NON_DEFAULT_SIMT_CONTROL(N, _VS);
  constexpr int _ImmOffset = 0;
  constexpr bool _Transposed = false;
  using _StTy = decltype(lsc_data_type_ext<T, N, _VS>());
  using _CastTy = typename lsc_bitcast_type<T>::type;
  _StTy _TmpData = Data.format<_CastTy>();
  details::__cm_intrinsic_impl_store4_slm<typename lsc_expand_type<T>::type,
                                          _DS, _VS, _ImmOffset, _Transposed, N>(
      Offset, _TmpData, Pred, Mask);
}

/// \brief 2D Block Read (flat)
///
/// @param T The element data type.
///
/// @param N The data size
///
/// @param Width The block width in number of elements
///
/// @param Height The block height
///
/// @param NBlks, The number of blocks
///
/// @param Transposed Is Transposed or not
///
/// @param Transformed apply VNNI transform or not
///
/// @param L1H L1 cache hint
///
/// @param L2H L2 chache hint
///
/// @param Ptr Surface base address
///
/// @param SurfaceWidth the surface width minus 1 in bytes
///
/// @param SurfaceHeight the surface height minus 1 in rows
///
/// @param SurfacePitch the surface pitch minus 1 in bytes
///
/// @param X zero based X-coordinate of the left upper rectangle corner in
/// number of elements.
///
/// @param Y zero based Y-coordinate of the left upper rectangle corner in rows.
///
/// @param Data Data to store.
///
/// @return vector of type T and size N. Size is specified with padding.
/// see details::getBlock2dDataSize for details
template <typename T, int Width, int Height = 1, int NBlks = 1,
          bool Transposed = false, bool Transformed = false,
          CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::getBlock2dDataSize<T, NBlks, Height, Width,
                                              Transposed, Transformed>()>
CM_NODEBUG CM_INLINE vector<T, N>
cm_ptr_load(T *Ptr, unsigned SurfaceWidth, unsigned SurfaceHeight,
            unsigned SurfacePitch, int X, int Y) {
  using namespace details;
  CM_HAS_LSC_UNTYPED_2D_CONTROL;

  CM_STATIC_ERROR(!Transposed || !Transformed,
                  "Transposed and transformed is not supported");
  CM_STATIC_ERROR(!Transposed || (Transposed && NBlks == 1),
                  "Transposed expected to be 1 block only");
  CM_STATIC_ERROR((lsc_check_cache_hint_load<L1H, L2H>()),
                  "unsupported cache hint");
  uintptr_t Base = reinterpret_cast<uintptr_t>(Ptr);

  // Calculate number of elements with padding
  constexpr int vnni_elements = sizeof(uint32_t) / sizeof(T);
  constexpr int grf_width = Transposed    ? Height
                            : Transformed ? Width * vnni_elements
                                          : Width;
  constexpr int grf_row_pitch = details::getNextPowerOf2(grf_width);
  constexpr int grf_height =
      Transposed ? Width
                 : (Transformed ? (Height + vnni_elements - 1) / vnni_elements
                                : Height);
  constexpr int grf_block_elements = grf_row_pitch * grf_height;
  constexpr int grf_block_pitch =
      details::roundUpNextMultiple(grf_block_elements, 64 / sizeof(T));
  constexpr int grf_elements = grf_block_pitch * NBlks;

  constexpr int dst_block_elements = grf_width * grf_height;
  constexpr int dst_elements = dst_block_elements * NBlks;

  CM_STATIC_ERROR(N == grf_elements || N == dst_elements,
                  "Incorrect element count");

  vector<T, grf_elements> raw = details::__cm_intrinsic_impl_block_load2d_flat<
      T, NBlks, Width, Height, Transposed, Transformed, L1H, L2H, grf_elements>(
      Base, SurfaceWidth, SurfaceHeight, SurfacePitch, X, Y);

  // If no padding is observed, then return as read
  if constexpr (grf_elements == N)
    return raw;

  // HW restrictions force data which is read to contain padding filled with
  // garbage for 2d lsc loads. This code eliminates such padding. For details
  // see documentation for LSC_UNTYPED (LOAD_BLOCK2D).
  vector<T, dst_elements> dst;

#pragma unroll
  for (int i = 0; i < NBlks; i++) {
    auto dst_block =
        dst.template select<dst_block_elements, 1>(i * dst_block_elements);

    auto raw_block =
        raw.template select<grf_block_elements, 1>(i * grf_block_pitch);
    auto raw_block_2d =
        raw_block.template format<T, grf_height, grf_row_pitch>();

    dst_block = raw_block_2d.template select<grf_height, 1, grf_width, 1>(0, 0);
  }

  return dst;
}

// convenient overload to not break legacy
template <typename T, int Width, int Height = 1, int NBlks = 1,
          bool Transposed = false, bool Transformed = false,
          CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::getBlock2dDataSize<T, NBlks, Height, Width,
                                              Transposed, Transformed>()>
CM_NODEBUG CM_INLINE vector<T, N> cm_load(T *Ptr, unsigned SurfaceWidth,
                                          unsigned SurfaceHeight,
                                          unsigned SurfacePitch, int X, int Y) {
  return cm_ptr_load<T, Width, Height, NBlks, Transposed, Transformed, L1H, L2H,
                     N>(Ptr, SurfaceWidth, SurfaceHeight, SurfacePitch, X, Y);
}

/// \brief 2D Block Prefetch (flat)
template <typename T, int Width, int Height = 1, int NBlks = 1,
          CacheHint L1H = CacheHint::Cached,
          CacheHint L2H = CacheHint::Cached>
CM_NODEBUG CM_INLINE void cm_ptr_prefetch(T *Ptr, unsigned SurfaceWidth,
                                          unsigned SurfaceHeight,
                                          unsigned SurfacePitch, int X, int Y) {
  CM_HAS_LSC_UNTYPED_2D_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_prefetch<L1H, L2H>()),
                  "unsupported cache hint");
  uintptr_t Base = reinterpret_cast<uintptr_t>(Ptr);
  __cm_intrinsic_impl_block_prefetch2d_flat<T, NBlks, Width, Height, L1H, L2H>(
      Base, SurfaceWidth, SurfaceHeight, SurfacePitch, X, Y);
}

/// convenient overload to not break legacy
template <typename T, int Width, int Height = 1, int NBlks = 1,
          CacheHint L1H = CacheHint::Cached,
          CacheHint L2H = CacheHint::Cached>
CM_NODEBUG CM_INLINE void cm_prefetch(T *Ptr, unsigned SurfaceWidth,
                                      unsigned SurfaceHeight,
                                      unsigned SurfacePitch, int X, int Y) {
  return cm_ptr_prefetch<T, Width, Height, NBlks, L1H, L2H>(
      Ptr, SurfaceWidth, SurfaceHeight, SurfacePitch, X, Y);
}

/// \brief 2D Block Store (flat)
template <typename T, int Width, int Height = 1,
          CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::getBlock2dDataSize<T, 1 /*NBlks*/, Height, Width,
                                              false /*Transposed*/,
                                              false /*Transformed*/>()>
CM_NODEBUG CM_INLINE void
cm_ptr_store(T *Ptr, unsigned SurfaceWidth, unsigned SurfaceHeight,
             unsigned SurfacePitch, int X, int Y, vector<T, N> Data) {
  CM_HAS_LSC_UNTYPED_2D_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_store<L1H, L2H>()),
                  "unsupported cache hint");
  constexpr int NBlks = 1;
  uintptr_t Base = reinterpret_cast<uintptr_t>(Ptr);

  constexpr int Pitch = details::getNextPowerOf2(Width);
  matrix<T, Height, Pitch> raw;

  if constexpr (raw.n_elems() == Data.n_elems())
    raw = Data;
  else {
    auto data_2d = Data.template format<T, Height, Width>();
    raw.template select<Height, 1, Width, 1>(0, 0) = data_2d;
  }

  __cm_intrinsic_impl_block_store2d_flat<T, NBlks, Width, Height, L1H, L2H,
                                         raw.n_elems()>(
      Base, SurfaceWidth, SurfaceHeight, SurfacePitch, X, Y,
      raw.template format<T>());
}

/// convenient overload to not break legacy
template <typename T, int Width, int Height = 1,
          CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::getBlock2dDataSize<T, 1 /*NBlks*/, Height, Width,
                                              false /*Transposed*/,
                                              false /*Transformed*/>()>
CM_NODEBUG CM_INLINE void
cm_store(T *Ptr, unsigned SurfaceWidth, unsigned SurfaceHeight,
         unsigned SurfacePitch, int X, int Y, vector<T, N> Data) {
  cm_ptr_store<T, Width, Height, L1H, L2H, N>(Ptr, SurfaceWidth, SurfaceHeight,
                                              SurfacePitch, X, Y, Data);
}

// typed bti load4/store4/prefetch4 are Xe2+
template <ChannelMaskType ChMask, CacheHint L1Hint = CacheHint::Default,
          CacheHint L2Hint = CacheHint::Default, typename T = unsigned,
          int SimdWidth = 16>
CM_NODEBUG CM_INLINE std::enable_if_t<details::is_fp_or_dword_type<T>::value>
cm_load4_typed(
    matrix_ref<T, details::lsc_get_num_elements_from_channel_mask<ChMask>(),
               SimdWidth>
        Output,
    vector<uint16_t, SimdWidth> Pred, SurfaceIndex Image,
    vector<unsigned, SimdWidth> U, vector<unsigned, SimdWidth> V = 0,
    vector<unsigned, SimdWidth> R = 0, vector<unsigned, SimdWidth> LOD = 0) {
  using namespace details;
  CM_HAS_LSC_TYPED_CONTROL;
  CM_STATIC_ERROR((lsc_check_cache_hint_load<L1Hint, L2Hint>()),
                  "unsupported cache hint");
  Output = __cm_intrinsic_impl_load4_typed_bti<ChMask, L1Hint, L2Hint>(
      Pred, Image, U, V, R, LOD, Output);
}

template <ChannelMaskType ChMask, CacheHint L1Hint = CacheHint::Default,
          CacheHint L2Hint = CacheHint::Default, typename T = unsigned,
          int SimdWidth = 16>
CM_NODEBUG CM_INLINE std::enable_if_t<details::is_fp_or_dword_type<T>::value>
cm_load4_typed(
    matrix_ref<T, details::lsc_get_num_elements_from_channel_mask<ChMask>(),
               SimdWidth>
        Output,
    SurfaceIndex Image, vector<unsigned, SimdWidth> U,
    vector<unsigned, SimdWidth> V = 0, vector<unsigned, SimdWidth> R = 0,
    vector<unsigned, SimdWidth> LOD = 0) {
  vector<uint16_t, SimdWidth> Pred = 1;
  cm_load4_typed<ChMask, L1Hint, L2Hint>(Output, Pred, Image, U, V, R, LOD);
}

template <ChannelMaskType ChMask, CacheHint L1Hint = CacheHint::Default,
          CacheHint L2Hint = CacheHint::Default, typename T = unsigned,
          int SimdWidth = 16>
CM_NODEBUG CM_INLINE std::enable_if_t<details::is_fp_or_dword_type<T>::value>
cm_store4_typed(
    matrix<T, details::lsc_get_num_elements_from_channel_mask<ChMask>(),
           SimdWidth>
        Data,
    vector<uint16_t, SimdWidth> Pred, SurfaceIndex Image,
    vector<unsigned, SimdWidth> U, vector<unsigned, SimdWidth> V = 0,
    vector<unsigned, SimdWidth> R = 0, vector<unsigned, SimdWidth> LOD = 0) {
  using namespace details;
  CM_HAS_LSC_TYPED_CONTROL;
  CM_STATIC_ERROR((lsc_check_cache_hint_store<L1Hint, L2Hint>()),
                  "unsupported cache hint");
  CM_STATIC_ERROR(ChMask == CM_R_ENABLE || ChMask == CM_GR_ENABLE ||
                      ChMask == CM_BGR_ENABLE || ChMask == CM_ABGR_ENABLE,
                  "Only contiguous channel masks are supported");
  __cm_intrinsic_impl_store4_typed_bti<ChMask, L1Hint, L2Hint>(Pred, Image, U,
                                                               V, R, LOD, Data);
}

template <ChannelMaskType ChMask, CacheHint L1Hint = CacheHint::Default,
          CacheHint L2Hint = CacheHint::Default, typename T = unsigned,
          int SimdWidth = 16>
CM_NODEBUG CM_INLINE std::enable_if_t<details::is_fp_or_dword_type<T>::value>
cm_store4_typed(
    matrix<T, details::lsc_get_num_elements_from_channel_mask<ChMask>(),
           SimdWidth>
        Data,
    SurfaceIndex Image, vector<unsigned, SimdWidth> U,
    vector<unsigned, SimdWidth> V = 0, vector<unsigned, SimdWidth> R = 0,
    vector<unsigned, SimdWidth> LOD = 0) {
  vector<uint16_t, SimdWidth> Pred = 1;
  cm_store4_typed<ChMask, L1Hint, L2Hint>(Data, Pred, Image, U, V, R, LOD);
}

template <ChannelMaskType ChMask, CacheHint L1Hint, CacheHint L2Hint,
          int SimdWidth = 16>
CM_NODEBUG CM_INLINE void cm_prefetch4_typed(
    vector<uint16_t, SimdWidth> Pred, SurfaceIndex Image,
    vector<unsigned, SimdWidth> U, vector<unsigned, SimdWidth> V = 0,
    vector<unsigned, SimdWidth> R = 0, vector<unsigned, SimdWidth> LOD = 0) {
  using namespace details;
  CM_HAS_LSC_TYPED_CONTROL;
  CM_STATIC_ERROR((lsc_check_cache_hint_prefetch<L1Hint, L2Hint>()),
                  "unsupported cache hint");
  __cm_intrinsic_impl_prefetch4_typed_bti<ChMask, L1Hint, L2Hint>(Pred, Image,
                                                                  U, V, R, LOD);
}

template <ChannelMaskType ChMask, CacheHint L1Hint, CacheHint L2Hint,
          int SimdWidth = 16>
CM_NODEBUG CM_INLINE void
cm_prefetch4_typed(SurfaceIndex Image, vector<unsigned, SimdWidth> U,
                   vector<unsigned, SimdWidth> V = 0,
                   vector<unsigned, SimdWidth> R = 0,
                   vector<unsigned, SimdWidth> LOD = 0) {
  vector<uint16_t, SimdWidth> Pred = 1;
  cm_prefetch4_typed<ChMask, L1Hint, L2Hint>(Pred, Image, U, V, R, LOD);
}

// 2d typed bti loads/stores are Xe2+

/// \brief 2D load (BTI)
///        basic cm_load interface for stateful access
///        T, N, M may be inferred from matrix type just like in read()
template <typename T, int Height, int Width, CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default>
CM_NODEBUG CM_INLINE void cm_load(SurfaceIndex Idx, int X, int Y,
                                  matrix_ref<T, Height, Width> Output) {
  CM_HAS_LSC_TYPED_2D_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_load<L1H, L2H>()),
                  "unsupported cache hint");
  Output =
      __cm_intrinsic_impl_load2d_bti<T, Height, Width, L1H, L2H>(Idx, X, Y);
}

/// \brief 2D prefetch (BTI)
///        basic cm_prefetch interface for stateful access
///        T, N, M may be inferred from matrix type just like in read()
template <typename T, int Height, int Width, CacheHint L1H = CacheHint::Cached,
          CacheHint L2H = CacheHint::Cached>
CM_NODEBUG CM_INLINE void cm_prefetch(SurfaceIndex Idx, int X, int Y) {
  CM_HAS_LSC_TYPED_2D_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_prefetch<L1H, L2H>()),
                  "unsupported cache hint");
  __cm_intrinsic_impl_prefetch2d_bti<T, Height, Width, L1H, L2H>(Idx, X, Y);
}

/// \brief 2D store (BTI)
///        basic cm_store interface for stateful access
///        T, N, M may be inferred from matrix type just like in write()
template <typename T, int Height, int Width, CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default>
CM_NODEBUG CM_INLINE void cm_store(SurfaceIndex Idx, int X, int Y,
                                   matrix<T, Height, Width> Input) {
  CM_HAS_LSC_TYPED_2D_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_store<L1H, L2H>()),
                  "unsupported cache hint");
  __cm_intrinsic_impl_store2d_bti<T, Height, Width, L1H, L2H>(Idx, X, Y, Input);
}

/// \brief LSC Atomic.
///
/// @param T The element data type.
///
/// @param VS Vector size
///
/// @param DS Data size
///
/// @param L1H L1 cache hint
///
/// @param L2H L2 chache hint
///
/// @param Pred Predicate
///
/// @param Idx Surface index, which must correspond to a buffer.
///
/// @param Offset zero based byte offset of the input buffer or SLM byte offset
///
template <AtomicOp Op, typename T, VectorSize VS = VectorSize::N1,
          DataSize DS = DataSize::Default, CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE auto cm_atomic(SurfaceIndex Idx,
                                    vector<unsigned, N> Offset,
                                    vector<ushort, N> Pred = 1) ->
    typename std::enable_if<
        details::lsc_atomic_nsrcs<Op>() == 0,
        vector<T, N * details::lsc_vector_size<VS>()> >::type {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_atomic<L1H, L2H>()),
                  "unsupported cache hint");
  constexpr DataSize _DS = lsc_expand_ds(lsc_data_size<T, DS>());
  constexpr bool _Transposed = false;
  using _IntRetTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _RetTy = decltype(lsc_data_type<T, N, VS>());
  auto _TmpRes =
      __cm_intrinsic_impl_lsc_atomic_bti<Op, _DS, VS, _Transposed, L1H, L2H,
                                         _IntRetTy, N>(Pred, Idx, Offset);
  return lsc_format_ret<T, _IntRetTy, _RetTy>(_TmpRes);
}

template <AtomicOp Op, typename T, VectorSize VS = VectorSize::N1,
          DataSize DS = DataSize::Default, CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE auto
cm_atomic(SurfaceIndex Idx, vector<unsigned, N> Offset,
          vector<T, N * details::lsc_vector_size<VS>()> Src0,
          vector<ushort, N> Pred = 1) ->
    typename std::enable_if<details::lsc_atomic_nsrcs<Op>() == 1,
                            decltype(Src0)>::type {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_atomic<L1H, L2H>()),
                  "unsupported cache hint");
  CM_STATIC_ERROR(lsc_check_atomic_src<T>(),
                  "unsupported type for lsc atomic source or dest arguments");
  constexpr DataSize _DS = lsc_expand_ds(lsc_data_size<T, DS>());
  constexpr bool _Transposed = false;
  using _IntRetTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _SrcTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _CastTy = typename lsc_bitcast_type<T>::type;
  using _RetTy = decltype(lsc_data_type<T, N, VS>());
  _SrcTy _TmpSrc0 = Src0.format<_CastTy>();
  auto _TmpRes = __cm_intrinsic_impl_lsc_atomic_bti<Op, _DS, VS, _Transposed,
                                                    L1H, L2H, _IntRetTy, N>(
      Pred, Idx, Offset, _TmpSrc0);
  return lsc_format_ret<T, _IntRetTy, _RetTy>(_TmpRes);
}

template <AtomicOp Op, typename T, VectorSize VS = VectorSize::N1,
          DataSize DS = DataSize::Default, CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE auto
cm_atomic(SurfaceIndex Idx, vector<unsigned, N> Offset,
          vector<T, N * details::lsc_vector_size<VS>()> Src0,
          vector<T, N * details::lsc_vector_size<VS>()> Src1,
          vector<ushort, N> Pred = 1) ->
    typename std::enable_if<details::lsc_atomic_nsrcs<Op>() == 2,
                            decltype(Src0)>::type {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_atomic<L1H, L2H>()),
                  "unsupported cache hint");
  CM_STATIC_ERROR(lsc_check_atomic_src<T>(),
                  "unsupported type for lsc atomic source or dest arguments");
  constexpr DataSize _DS = lsc_expand_ds(lsc_data_size<T, DS>());
  using _IntRetTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _SrcTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _RetTy = decltype(lsc_data_type<T, N, VS>());
  using _CastTy = typename lsc_bitcast_type<T>::type;
  _SrcTy _TmpSrc0 = Src0.format<_CastTy>();
  _SrcTy _TmpSrc1 = Src1.format<_CastTy>();
  constexpr bool _Transposed = false;
  auto _TmpRes = __cm_intrinsic_impl_lsc_atomic_bti<Op, _DS, VS, _Transposed,
                                                    L1H, L2H, _IntRetTy, N>(
      Pred, Idx, Offset, _TmpSrc0, _TmpSrc1);
  return lsc_format_ret<T, _IntRetTy, _RetTy>(_TmpRes);
}

// flat-address atomic
template <AtomicOp Op, typename T, VectorSize VS = VectorSize::N1,
          DataSize DS = DataSize::Default, CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE auto cm_ptr_atomic(T *Ptr, vector<unsigned, N> Offset,
                                        vector<ushort, N> Pred = 1) ->
    typename std::enable_if<
        details::lsc_atomic_nsrcs<Op>() == 0,
        vector<T, N * details::lsc_vector_size<VS>()> >::type {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_atomic<L1H, L2H>()),
                  "unsupported cache hint");
  constexpr DataSize _DS = lsc_expand_ds(lsc_data_size<T, DS>());
  constexpr bool _Transposed = false;
  uint64_t _Addr = (uint64_t)Ptr;
  using _IntRetTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _RetTy = decltype(lsc_data_type<T, N, VS>());
  auto _TmpRes =
      __cm_intrinsic_impl_lsc_atomic_flat<Op, _DS, VS, _Transposed, L1H, L2H,
                                          _IntRetTy, N>(Pred, _Addr, Offset);
  return lsc_format_ret<T, _IntRetTy, _RetTy>(_TmpRes);
}

template <AtomicOp Op, typename T, VectorSize VS = VectorSize::N1,
          DataSize DS = DataSize::Default, CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE auto
cm_ptr_atomic(T *Ptr, vector<unsigned, N> Offset,
              vector<T, N * details::lsc_vector_size<VS>()> Src0,
              vector<ushort, N> Pred = 1) ->
    typename std::enable_if<details::lsc_atomic_nsrcs<Op>() == 1,
                            decltype(Src0)>::type {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_atomic<L1H, L2H>()),
                  "unsupported cache hint");
  CM_STATIC_ERROR(lsc_check_atomic_src<T>(),
                  "unsupported type for lsc atomic source or dest arguments");
  constexpr DataSize _DS = lsc_expand_ds(lsc_data_size<T, DS>());
  constexpr bool _Transposed = false;
  uint64_t _Addr = (uint64_t)Ptr;
  using _IntRetTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _SrcTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _RetTy = decltype(lsc_data_type<T, N, VS>());
  using _CastTy = typename lsc_bitcast_type<T>::type;
  _SrcTy _TmpSrc0 = Src0.format<_CastTy>();
  auto _TmpRes = __cm_intrinsic_impl_lsc_atomic_flat<Op, _DS, VS, _Transposed,
                                                     L1H, L2H, _IntRetTy, N>(
      Pred, _Addr, Offset, _TmpSrc0);
  return lsc_format_ret<T, _IntRetTy, _RetTy>(_TmpRes);
}

template <AtomicOp Op, typename T, VectorSize VS = VectorSize::N1,
          DataSize DS = DataSize::Default, CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE auto
cm_ptr_atomic(T *Ptr, vector<unsigned, N> Offset,
              vector<T, N * details::lsc_vector_size<VS>()> Src0,
              vector<T, N * details::lsc_vector_size<VS>()> Src1,
              vector<ushort, N> Pred = 1) ->
    typename std::enable_if<details::lsc_atomic_nsrcs<Op>() == 2,
                            decltype(Src0)>::type {
  CM_HAS_LSC_CONTROL;

  using namespace details;
  CM_STATIC_ERROR((lsc_check_cache_hint_atomic<L1H, L2H>()),
                  "unsupported cache hint");
  CM_STATIC_ERROR(lsc_check_atomic_src<T>(),
                  "unsupported type for lsc atomic source or dest arguments");
  constexpr DataSize _DS = lsc_expand_ds(lsc_data_size<T, DS>());
  using _IntRetTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _SrcTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _RetTy = decltype(lsc_data_type<T, N, VS>());
  using _CastTy = typename lsc_bitcast_type<T>::type;
  _SrcTy _TmpSrc0 = Src0.format<_CastTy>();
  _SrcTy _TmpSrc1 = Src1.format<_CastTy>();
  constexpr bool _Transposed = false;
  uint64_t _Addr = (uint64_t)Ptr;
  auto _TmpRes = __cm_intrinsic_impl_lsc_atomic_flat<Op, _DS, VS, _Transposed,
                                                     L1H, L2H, _IntRetTy, N>(
      Pred, _Addr, Offset, _TmpSrc0, _TmpSrc1);
  return lsc_format_ret<T, _IntRetTy, _RetTy>(_TmpRes);
}

template <AtomicOp Op, typename T, VectorSize VS = VectorSize::N1,
          DataSize DS = DataSize::Default, CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE auto cm_atomic_slm(vector<unsigned, N> Offset,
                                        vector<ushort, N> Pred = 1) ->
    typename std::enable_if<
        details::lsc_atomic_nsrcs<Op>() == 0,
        vector<T, N * details::lsc_vector_size<VS>()> >::type {
  CM_HAS_LSC_CONTROL;

  if constexpr (sizeof(T) == sizeof(long long) || sizeof(T) == sizeof(double))
    CM_HAS_SLM_CAS_INT64_CONTROL;

  using namespace details;
  CM_STATIC_ERROR(L1H == CacheHint::Default && L2H == CacheHint::Default,
                  "SLM messages don't support cache hints");
  constexpr DataSize _DS = lsc_expand_ds(lsc_data_size<T, DS>());
  constexpr bool _Transposed = false;
  using _IntRetTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _RetTy = decltype(lsc_data_type<T, N, VS>());
  auto _TmpRes =
      __cm_intrinsic_impl_lsc_atomic_slm<Op, _DS, VS, _Transposed, L1H, L2H,
                                         _IntRetTy, N>(Pred, Offset);
  return lsc_format_ret<T, _IntRetTy, _RetTy>(_TmpRes);
}

template <AtomicOp Op, typename T, VectorSize VS = VectorSize::N1,
          DataSize DS = DataSize::Default, CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE auto
cm_atomic_slm(vector<unsigned, N> Offset,
              vector<T, N * details::lsc_vector_size<VS>()> Src0,
              vector<ushort, N> Pred = 1) ->
    typename std::enable_if<details::lsc_atomic_nsrcs<Op>() == 1,
                            decltype(Src0)>::type {
  CM_HAS_LSC_CONTROL;

  if constexpr (sizeof(T) == sizeof(long long) || sizeof(T) == sizeof(double))
    CM_HAS_SLM_CAS_INT64_CONTROL;

  using namespace details;
  CM_STATIC_ERROR(L1H == CacheHint::Default && L2H == CacheHint::Default,
                  "SLM messages don't support cache hints");
  CM_STATIC_ERROR(lsc_check_atomic_src<T>(),
                  "unsupported type for lsc atomic source or dest arguments");
  constexpr DataSize _DS = lsc_expand_ds(lsc_data_size<T, DS>());
  constexpr bool _Transposed = false;
  using _IntRetTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _SrcTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _RetTy = decltype(lsc_data_type<T, N, VS>());
  using _CastTy = typename lsc_bitcast_type<T>::type;
  _SrcTy _TmpSrc0 = Src0.format<_CastTy>();
  auto _TmpRes =
      __cm_intrinsic_impl_lsc_atomic_slm<Op, _DS, VS, _Transposed, L1H, L2H,
                                         _IntRetTy, N>(Pred, Offset, _TmpSrc0);
  return lsc_format_ret<T, _IntRetTy, _RetTy>(_TmpRes);
}

template <AtomicOp Op, typename T, VectorSize VS = VectorSize::N1,
          DataSize DS = DataSize::Default, CacheHint L1H = CacheHint::Default,
          CacheHint L2H = CacheHint::Default,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE auto
cm_atomic_slm(vector<unsigned, N> Offset,
              vector<T, N * details::lsc_vector_size<VS>()> Src0,
              vector<T, N * details::lsc_vector_size<VS>()> Src1,
              vector<ushort, N> Pred = 1) ->
    typename std::enable_if<details::lsc_atomic_nsrcs<Op>() == 2,
                            decltype(Src0)>::type {
  CM_HAS_LSC_CONTROL;

  if constexpr (sizeof(T) == sizeof(long long) || sizeof(T) == sizeof(double))
    CM_HAS_SLM_CAS_INT64_CONTROL;

  using namespace details;
  CM_STATIC_ERROR(L1H == CacheHint::Default && L2H == CacheHint::Default,
                  "SLM messages don't support cache hints");
  CM_STATIC_ERROR(lsc_check_atomic_src<T>(),
                  "unsupported type for lsc atomic source or dest arguments");
  constexpr DataSize _DS = lsc_expand_ds(lsc_data_size<T, DS>());
  using _IntRetTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _SrcTy = decltype(lsc_data_type_ext<T, N, VS>());
  using _RetTy = decltype(lsc_data_type<T, N, VS>());
  using _CastTy = typename lsc_bitcast_type<T>::type;
  _SrcTy _TmpSrc0 = Src0.format<_CastTy>();
  _SrcTy _TmpSrc1 = Src1.format<_CastTy>();
  constexpr bool _Transposed = false;
  auto _TmpRes = __cm_intrinsic_impl_lsc_atomic_slm<Op, _DS, VS, _Transposed,
                                                    L1H, L2H, _IntRetTy, N>(
      Pred, Offset, _TmpSrc0, _TmpSrc1);
  return lsc_format_ret<T, _IntRetTy, _RetTy>(_TmpRes);
}

///
/// LSC Fence built-in
///
/// \brief LSC Fence.
///
/// @param N The number of channels (platform dependent)
///
/// @param Sfid shaded funnction
///
/// @param FenceOp
///
/// @param Scope
///
template <LSC_SFID Sfid = LSC_SFID::LSC_UGM,
          LSC_FENCE_OP FenceOp = LSC_FENCE_OP::LSC_FENCE_OP_NONE,
          LSC_SCOPE Scope = LSC_SCOPE::LSC_SCOPE_GROUP,
          int N = details::lsc_default_simt()>
CM_NODEBUG CM_INLINE void cm_fence(vector<ushort, N> Pred = 1) {
  CM_HAS_LSC_CONTROL; // control platform version

  using namespace details;
#ifndef CM_HAS_LSC_SYS_FENCE
  CM_STATIC_ERROR(Scope != LSC_SCOPE::LSC_SCOPE_SYSTEM &&
                      Scope != LSC_SCOPE::LSC_SCOPE_SYSACQ,
                  "unsupported system fence type");
#endif
  __cm_intrinsic_impl_lsc_fence<Sfid, FenceOp, Scope, N>(Pred);
}

#endif // _CLANG_CM_LSC_H_
