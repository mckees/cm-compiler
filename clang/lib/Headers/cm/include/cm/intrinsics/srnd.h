/*========================== begin_copyright_notice ============================

Copyright (C) 2020-2024 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#if (__INCLUDE_LEVEL__ == 1)
static_assert(0, "CM:w:intrinsics/srnd.h should not be included explicitly - "
                 "only <cm/cm.h> is required");
#endif

#ifndef _CLANG_INTRINSICS_SRND_H_
#define _CLANG_INTRINSICS_SRND_H_

#include <cm/cm_common.h>
#include <cm/cm_has_instr.h>
#include <cm/cm_internal.h>

namespace details {

template <typename OutputTy, typename InputTy, typename BiasTy, unsigned Width>
vector<OutputTy, Width> __cm_intrinsic_impl_srnd(vector<InputTy, Width> Src,
                                                 vector<BiasTy, Width> Bias);

template <typename OutputTy>
using EnableIfHalfType = std::enable_if_t<is_half_type<OutputTy>::value, half>;
} // namespace details

#if CM_HAS_SRND_FP32_TO_FP16
#define CM_HAS_STOCHASTIC_ROUNDING 1
#define CM_HAS_SRND_FP32_TO_FP16_CONTROL CM_HAS_CONTROL(true)
#else // CM_HAS_SRND_FP32_TO_FP16
#define CM_HAS_SRND_FP32_TO_FP16_CONTROL CM_HAS_CONTROL(false)
#endif // CM_HAS_SRND_FP32_TO_FP16

template <typename ResTy, typename SrcTy, typename BiasTy, unsigned Width>
CM_NODEBUG CM_INLINE vector<details::EnableIfHalfType<ResTy>, Width>
cm_srnd(vector<SrcTy, Width> Src, vector<BiasTy, Width> Bias) {
  CM_HAS_SRND_FP32_TO_FP16_CONTROL;
  CM_STATIC_ERROR(details::is_float_type<SrcTy>::value,
                  "Unsupported stochastic rounding operation");
  CM_STATIC_ERROR(
      (std::is_same<SrcTy, BiasTy>::value ||
       (std::is_integral<BiasTy>::value && sizeof(BiasTy) == sizeof(ResTy))),
      "Unsupported stochastic rounding bias type");

  return details::__cm_intrinsic_impl_srnd<ResTy>(Src, Bias);
}

template <typename ResTy, typename SrcTy, typename BiasTy, unsigned Height,
          unsigned Width>
CM_NODEBUG CM_INLINE matrix<details::EnableIfHalfType<ResTy>, Height, Width>
cm_srnd(matrix<SrcTy, Height, Width> Src, matrix<BiasTy, Height, Width> Bias) {
  return cm_srnd<ResTy>(Src.template format<SrcTy>(),
                        Bias.template format<BiasTy>());
}

template <typename ResTy, typename SrcTy, typename BiasTy>
CM_NODEBUG CM_INLINE details::EnableIfHalfType<ResTy> cm_srnd(SrcTy Src,
                                                              BiasTy Bias) {
  vector<SrcTy, 1> _Src = Src;
  vector<BiasTy, 1> _Bias = Bias;
  vector<ResTy, 1> _Res = cm_srnd<ResTy>(_Src, _Bias);
  return _Res[0];
}
#endif // _CLANG_INTRINSICS_SRND_H_
