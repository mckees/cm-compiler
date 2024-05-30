/*========================== begin_copyright_notice ============================

Copyright (C) 2024 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#if (__INCLUDE_LEVEL__ == 1)
static_assert(0, "CM:w:dpas/helpers.h should not be included explicitly - only "
                 "<cm/cm.h> is required");
#endif

#ifndef _CLANG_CM_DPAS_HELPERS_H_
#define _CLANG_CM_DPAS_HELPERS_H_

#include <cm/cm_common.h>

#define CM_HAS_DPAS_INT_MIX 1
#define CM_HAS_DPAS_INT2 1

#define CM_HAS_DPAS_INT4 1
#define CM_HAS_DPAS_INT8 1

#if (CM_GENX >= 1280) //>= PVC
// FIXME: get these macros from the platforms table
#define CM_HAS_DPAS_ACC_HALF 1
#define CM_HAS_DPAS_ACC_BF16 1
#endif

namespace details {
inline constexpr int get_dpas_execution_size(CmPrecisionType Precision) {
  (void)Precision;
  // The dpas execution size is the number of 32-bit elements per register.
  return CM_GRF_WIDTH / 32;
}

template <typename T>
constexpr bool is_dpas_source_type(CmPrecisionType Precision) {
  (void)Precision;
  return details::is_dword_type<T>::value;
}

constexpr bool is_valid_dpas_int_precision(CmPrecisionType Ty) {
#if defined(CM_HAS_DPAS_INT2)
  if (Ty == CmPrecisionType::CM_Precision_U2 ||
      Ty == CmPrecisionType::CM_Precision_S2)
    return true;
#endif // defined(CM_HAS_DPAS_INT2)
#if defined(CM_HAS_DPAS_INT4)
  if (Ty == CmPrecisionType::CM_Precision_U4 ||
      Ty == CmPrecisionType::CM_Precision_S4)
    return true;
#endif // defined(CM_HAS_DPAS_INT4)
#if defined(CM_HAS_DPAS_INT8)
  if (Ty == CmPrecisionType::CM_Precision_U8 ||
      Ty == CmPrecisionType::CM_Precision_S8)
    return true;
#endif // defined(CM_HAS_DPAS_INT8)
  return false;
}

template <typename ResTy, typename AccTy>
constexpr bool is_valid_dpas_int(CmPrecisionType Src1Ty,
                                 CmPrecisionType Src2Ty) {
  bool IsValid = is_valid_dpas_int_precision(Src1Ty) &&
                 is_valid_dpas_int_precision(Src2Ty) &&
                 is_one_of_v<ResTy, int, unsigned> &&
                 is_one_of_v<AccTy, int, unsigned>;

#if !defined(CM_HAS_DPAS_INT_MIX)
  IsValid &= get_precision_bits(Src1Ty) == get_precision_bits(Src2Ty);
#endif // !defined(CM_HAS_DPAS_INT_MIX)

  return IsValid;
}

template <typename ResTy, typename AccTy>
constexpr bool is_valid_dpas_fp16(CmPrecisionType Src1Ty,
                                  CmPrecisionType Src2Ty) {

  auto IsValid = is_one_of_v<ResTy, float, half> &&
                 is_one_of_v<AccTy, float, half> &&
                 Src1Ty == CmPrecisionType::CM_Precision_FP16 &&
                 Src2Ty == CmPrecisionType::CM_Precision_FP16;

#if !defined(CM_HAS_DPAS_ACC_HALF)
  IsValid &= is_one_of_v<ResTy, float> && is_one_of_v<AccTy, float>;
#endif // !defined(CM_HAS_DPAS_ACC_HALF)

  return IsValid;
}

template <typename ResTy, typename AccTy>
constexpr bool is_valid_dpas_bf16(CmPrecisionType Src1Ty,
                                  CmPrecisionType Src2Ty) {
#if defined(CM_HAS_BF16)
  auto IsValid = is_one_of_v<ResTy, float, __bf16, short> &&
                 is_one_of_v<AccTy, float, __bf16, short> &&
                 Src1Ty == CmPrecisionType::CM_Precision_BF16 &&
                 Src2Ty == CmPrecisionType::CM_Precision_BF16;

#if !defined(CM_HAS_DPAS_ACC_BF16)
  IsValid &= is_one_of_v<ResTy, float> && is_one_of_v<AccTy, float>;
#endif // !defined(CM_HAS_DPAS_ACC_BF16)

  return IsValid;
#else // defined(CM_HAS_BF16)
  return false;
#endif // defined(CM_HAS_BF16)
}

template <typename ResTy, typename AccTy>
constexpr bool is_valid_dpas_tf32(CmPrecisionType Src1Ty,
                                  CmPrecisionType Src2Ty) {
#if defined(CM_HAS_TF32)
  return is_one_of_v<ResTy, float> && is_one_of_v<AccTy, float> &&
         Src1Ty == CmPrecisionType::CM_Precision_TF32 &&
         Src2Ty == CmPrecisionType::CM_Precision_TF32;
#else
  return false;
#endif // defined(CM_HAS_DPAS_TF32)
}

template <typename ResTy, typename AccTy>
constexpr bool is_valid_dpas(CmPrecisionType Src1Ty, CmPrecisionType Src2Ty) {
  bool IsValid = is_valid_dpas_int<ResTy, AccTy>(Src1Ty, Src2Ty);
  IsValid |= is_valid_dpas_fp16<ResTy, AccTy>(Src1Ty, Src2Ty);
  IsValid |= is_valid_dpas_bf16<ResTy, AccTy>(Src1Ty, Src2Ty);
  IsValid |= is_valid_dpas_tf32<ResTy, AccTy>(Src1Ty, Src2Ty);

  return IsValid;
}

constexpr bool is_valid_repeat_count(int RepeatCount, CmPrecisionType Precision) {
  (void)Precision;
  return RepeatCount >= 1 && RepeatCount <= 8;
}

constexpr unsigned get_dpas_acc_size(unsigned RepeatCount,
                                     CmPrecisionType Precision) {
  unsigned ExecSize = get_dpas_execution_size(Precision);
  return ExecSize * RepeatCount;
}

constexpr unsigned get_dpas_src1_size(CmPrecisionType Src1Ty,
                                      CmPrecisionType Src2Ty,
                                      unsigned SystolicDepth) {
  unsigned ExecSize = get_dpas_execution_size(Src1Ty);

  unsigned OpsPerChannel = get_ops_per_channel(Src1Ty, Src2Ty);
  unsigned KDimension = SystolicDepth * OpsPerChannel;

  unsigned Src1Bits = get_precision_bits(Src1Ty);
  unsigned ElementsPerDWord = 32 / Src1Bits;

  return KDimension * ExecSize / ElementsPerDWord;
}

constexpr unsigned get_dpas_src2_size(CmPrecisionType Src1Ty,
                                      CmPrecisionType Src2Ty,
                                      unsigned RepeatCount,
                                      unsigned SystolicDepth) {
  unsigned OpsPerChannel = get_ops_per_channel(Src1Ty, Src2Ty);
  unsigned KDimension = SystolicDepth * OpsPerChannel;

  unsigned Src2Bits = get_precision_bits(Src2Ty);
  unsigned ElementsPerDWord = 32 / Src2Bits;

  return RepeatCount * KDimension / ElementsPerDWord;
}

} // namespace details

#endif // _CLANG_CM_DPAS_HELPERS_H_
