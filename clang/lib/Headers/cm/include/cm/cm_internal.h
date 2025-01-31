/*========================== begin_copyright_notice ============================

Copyright (C) 2014-2024 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#if (__INCLUDE_LEVEL__ == 1)
static_assert(0, "CM:w:cm_internal.h should not be included explicitly - only "
                 "<cm/cm.h> is required");
#endif

#ifndef _CLANG_CM_INTERNAL_H_
#define _CLANG_CM_INTERNAL_H_

#include "cm_common.h"
#include "cm_util.h"

namespace details {

template <typename T0, typename T1, int SZ>
vector<T0, SZ> __cm_intrinsic_impl_sat(vector<T1, SZ> src);

template <typename T0, typename T1> T0 __cm_intrinsic_impl_sat(T1 src);

template <typename T, int SZ>
vector<T, SZ> __cm_intrinsic_impl_abs(vector<T, SZ> src0);

template <typename T0, typename T1, int SZ>
vector<T0, SZ> __cm_intrinsic_impl_add(vector<T1, SZ> src0, vector<T1, SZ> src1,
                                       int flag);

template <typename T0, typename T1, int SZ>
vector<T0, SZ> __cm_intrinsic_impl_mul(vector<T1, SZ> src0, vector<T1, SZ> src1,
                                       int flag);

template <typename T0, typename T1, int SZ>
vector<T0, SZ> __cm_intrinsic_impl_avg(vector<T1, SZ> src0, vector<T1, SZ> src1,
                                       int flag);

template <typename T0, typename T1, int SZ>
vector<T0, SZ> __cm_intrinsic_impl_shl(vector<T1, SZ> src0, vector<T1, SZ> src1,
                                       int flag);

template <typename T0, typename T1, int SZ>
vector<T0, SZ> __cm_intrinsic_impl_rol(vector<T1, SZ> src0, vector<T1, SZ> src1);
template <typename T0, typename T1, int SZ>
vector<T0, SZ> __cm_intrinsic_impl_ror(vector<T1, SZ> src0, vector<T1, SZ> src1);

template <typename T, int SZ>
vector<T, SZ> __cm_intrinsic_impl_imad(vector_ref<T, SZ> lo, vector<T, SZ> src0,
                                       vector<T, SZ> src1, vector<T, SZ> src2);
template <typename T> T __cm_intrinsic_impl_imad(T &lo, T src0, T src1, T src2);

template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_dp2(vector<float, SZ> src0,
                                          vector<float, SZ> src1);

template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_dp3(vector<float, SZ> src0,
                                          vector<float, SZ> src1);

template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_dp4(vector<float, SZ> src0,
                                          vector<float, SZ> src1);

template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_dph(vector<float, SZ> src0,
                                          vector<float, SZ> src1);

template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_frc(vector<float, SZ> src0);

template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_line(vector<float, 4> src0,
                                           vector<float, SZ> src1);

template <typename T, int SZ>
vector<T, SZ> __cm_intrinsic_impl_max(vector<T, SZ> src0, vector<T, SZ> src1);

template <typename T, int SZ>
vector<T, SZ> __cm_intrinsic_impl_lzd(vector<T, SZ> src0);

template <typename T, int SZ>
vector<T, SZ> __cm_intrinsic_impl_min(vector<T, SZ> src0, vector<T, SZ> src1);

//sad2 has 8-bit inputs and 16-bit result, no need for saturation
template <typename T0, typename T1, int SZ>
vector<T0, SZ> __cm_intrinsic_impl_sad2(vector<T1, SZ> src0,
                                        vector<T1, SZ> src1);

template <typename T0, typename T1, int SZ>
vector<T0, SZ> __cm_intrinsic_impl_sada2(vector<T1, SZ> src0,
                                         vector<T1, SZ> src1,
                                         vector<T0, SZ> src2, int flag);

template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_lrp(vector<float, SZ> src0,
                                          vector<float, SZ> src1,
                                          vector<float, SZ> src2);

template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_pln(vector<float, 4> src0,
                                          vector<float, SZ * 2> src1);

template <typename T0, typename T1, int SZ>
vector<T0, SZ> __cm_intrinsic_impl_bfrev(vector<T1, SZ> src0);

template <typename T, int SZ>
vector<unsigned int, SZ> __cm_intrinsic_impl_cbit(vector<T, SZ> src0);

template <typename T0, int SZ>
vector<T0, SZ>
__cm_intrinsic_impl_bfins(vector<T0, SZ> src0, vector<T0, SZ> src1,
                          vector<T0, SZ> src2, vector<T0, SZ> src3);

template <typename T0, int SZ>
vector<T0, SZ> __cm_intrinsic_impl_bfext(vector<T0, SZ> src0,
                                         vector<T0, SZ> src1,
                                         vector<T0, SZ> src2);

template <int SZ>
vector<uint, SZ> __cm_intrinsic_impl_fbl(vector<uint, SZ> src0);

template <typename T0, int SZ>
vector<int, SZ> __cm_intrinsic_impl_sfbh(vector<T0, SZ> src0);

template <typename T0, int SZ>
vector<uint, SZ> __cm_intrinsic_impl_ufbh(vector<T0, SZ> src0);

template <typename T0, typename T1, int SZ>
T0 __cm_intrinsic_impl_sum(vector<T1, SZ> src);
template <typename T0, typename T1, int SZ>
T0 __cm_intrinsic_impl_sum_sat(vector<T1, SZ> src);
template <typename T0, typename T1, int SZ>
T0 __cm_intrinsic_impl_prod(vector<T1, SZ> src);
template <typename T0, typename T1, int SZ>
T0 __cm_intrinsic_impl_prod_sat(vector<T1, SZ> src);
template <typename T, int SZ>
T __cm_intrinsic_impl_reduced_min(vector<T, SZ> src);
template <typename T, int SZ>
T __cm_intrinsic_impl_reduced_max(vector<T, SZ> src);

template <int SZ>
vector<half, SZ> __cm_intrinsic_impl_inv(vector<half, SZ> src0);
template <int SZ>
vector<half, SZ> __cm_intrinsic_impl_log(vector<half, SZ> src0);
template <int SZ>
vector<half, SZ> __cm_intrinsic_impl_exp(vector<half, SZ> src0);
template <int SZ>
vector<half, SZ> __cm_intrinsic_impl_sqrt(vector<half, SZ> src0);
template <int SZ>
vector<half, SZ> __cm_intrinsic_impl_rsqrt(vector<half, SZ> src0);
template <int SZ>
vector<half, SZ> __cm_intrinsic_impl_sin(vector<half, SZ> src0);
template <int SZ>
vector<half, SZ> __cm_intrinsic_impl_cos(vector<half, SZ> src0);
template <int SZ>
vector<half, SZ> __cm_intrinsic_impl_pow(vector<half, SZ> src0,
                                         vector<half, SZ> src1);

template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_inv(vector<float, SZ> src0);
template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_log(vector<float, SZ> src0);
template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_exp(vector<float, SZ> src0);
template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_sqrt(vector<float, SZ> src0);
template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_sqrt_ieee(vector<float, SZ> src0);
template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_rsqrt(vector<float, SZ> src0);
template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_sin(vector<float, SZ> src0);
template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_cos(vector<float, SZ> src0);
template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_pow(vector<float, SZ> src0,
                                          vector<float, SZ> src1);
template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_div_ieee(vector<float, SZ> src0,
                                               vector<float, SZ> src1);

template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_rndd(vector<float, SZ> src0);
template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_rndu(vector<float, SZ> src0);
template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_rnde(vector<float, SZ> src0);
template <int SZ>
vector<float, SZ> __cm_intrinsic_impl_rndz(vector<float, SZ> src0);

template <int SZ>
vector<double, SZ> __cm_intrinsic_impl_sqrt_ieee(vector<double, SZ> src0);
template <int SZ>
vector<double, SZ> __cm_intrinsic_impl_div_ieee(vector<double, SZ> src0,
                                                vector<double, SZ> src1);

template <typename T, int SZ>
vector<T, SZ> __cm_intrinsic_impl_oword_read(SurfaceIndex index, int offset);

template <typename T, int SZ>
vector<T, SZ> __cm_intrinsic_impl_oword_read_dwaligned(SurfaceIndex index,
                                                       int offset);

template <typename T, int SZ>
void __cm_intrinsic_impl_oword_write(SurfaceIndex index, int offset,
                                     vector<T, SZ> src);

template <typename T, int N, int M, int _M, CmBufferAttrib attr>
matrix<T, N, _M> __cm_intrinsic_impl_media_read(SurfaceIndex index, int X,
                                                int Y);

template <typename T, int N, int M, int _M, CmBufferAttrib attr>
void __cm_intrinsic_impl_media_write(SurfaceIndex index, int X, int Y,
                                     matrix<T, N, _M> src);

template <typename T, int N, int M, CmBufferAttrib attr,
          CmSurfacePlaneIndex plane>
matrix<T, N, M> __cm_intrinsic_impl_read_plane(SurfaceIndex index, int X,
                                               int Y);

template <typename T, int N, int M, int _M, CmBufferAttrib attr,
          CmSurfacePlaneIndex plane>
void __cm_intrinsic_impl_write_plane(SurfaceIndex index, int X, int Y,
                                     matrix<T, N, _M> src);

template <typename T, int N, ChannelMaskType Mask>
matrix<T, N, 16>
__cm_intrinsic_impl_sample16(SamplerIndex sampIndex, SurfaceIndex surfIndex,
                             vector<float, 16> u, vector<float, 16> v,
                             vector<float, 16> r);

template <int N, ChannelMaskType Mask, OutputFormatControl Ofc>
matrix<ushort, N, 32>
__cm_intrinsic_impl_sample32(SamplerIndex sampIndex, SurfaceIndex surfIndex,
                             float u, float v, float deltaU, float deltaV);

template <typename T, int N, ChannelMaskType Mask>
matrix<T, N, 16>
__cm_intrinsic_impl_load16(SurfaceIndex surfIndex, vector<uint, 16> u,
                           vector<uint, 16> v, vector<uint, 16> r);

template <CmAtomicOpType Op, int N, typename T>
vector<T, N> __cm_intrinsic_impl_atomic_write(vector<ushort, N> mask,
                                              SurfaceIndex index,
                                              vector<uint, N> elementOffset,
                                              vector<T, N> src0,
                                              vector<T, N> src1,
                                              vector<T, N> oldVal);

template <CmAtomicOpType Op, typename T, int N, typename... Args>
vector<T, N>
__cm_intrinsic_impl_atomic_write_typed(vector<ushort, N> mask,
                                       SurfaceIndex surfIndex,
                                       vector<T, N> src0, vector<T, N> src1,
                                       vector<uint, N> u, Args... args);

template <typename T0, typename T1, int N>
vector<T1, N> __cm_intrinsic_impl_scatter_read(SurfaceIndex index,
                                               uint globalOffset,
                                               vector<uint, N> elementOffset,
                                               vector<T1, N> oldVal, T0 dummy);

template <typename T0, typename T1, int N>
void __cm_intrinsic_impl_scatter_write(SurfaceIndex index, uint globalOffset,
                                       vector<uint, N> elementOffset,
                                       vector<T1, N> data, T0 dummy);

template <CmAtomicOpType Op, typename T, int N>
vector<T, N> __cm_intrinsic_impl_svm_atomic(vector<uint64_t, N> vAddr,
                                            vector<T, N> oldVal);

template <CmAtomicOpType Op, typename T, int N>
vector<T, N> __cm_intrinsic_impl_svm_atomic(vector<uint64_t, N> vAddr,
                                            vector<T, N> src0,
                                            vector<T, N> oldVal);

template <CmAtomicOpType Op, typename T, int N>
vector<T, N>
__cm_intrinsic_impl_svm_atomic(vector<uint64_t, N> vAddr, vector<T, N> src0,
                               vector<T, N> src1, vector<T, N> oldVal);

template <typename T, int N>
bool __cm_intrinsic_impl_simdfork_any(vector<T, N> t, const char *filename,
                                      unsigned line);
template <typename T, int R, int C>
bool __cm_intrinsic_impl_simdfork_any(matrix<T, R, C> t, const char *filename,
                                      unsigned line);

template <typename T = void>
bool __cm_intrinsic_impl_simdfork_any(int t, const char *filename, unsigned line);

template <typename T, int N>
bool __cm_intrinsic_impl_simdcf_any(vector<T, N> t, const char *filename,
                                    unsigned line);
template <typename T, int R, int C>
bool __cm_intrinsic_impl_simdcf_any(matrix<T, R, C> t, const char *filename,
                                    unsigned line);

template <typename T = void>
bool __cm_intrinsic_impl_simdcf_any(int t, const char *filename, unsigned line);

template <typename T0, int N>
vector<T0, N> __cm_intrinsic_impl_simdcf_predgen(vector<T0, N> arg0);

template <typename T0, int N>
vector<T0, N> __cm_intrinsic_impl_simdcf_predmin(vector<T0, N> arg0);

template <typename T0, int N>
vector<T0, N> __cm_intrinsic_impl_simdcf_predmax(vector<T0, N> arg0);

template <int N> uint __cm_intrinsic_impl_pack_mask(vector<ushort, N> src0);

template <int N1, int N2>
uint __cm_intrinsic_impl_pack_mask(matrix<ushort, N1, N2> src0);

template <typename T, int N>
vector<ushort, N> __cm_intrinsic_impl_unpack_mask(uint src0);

// Dummy mov inserts a mov to a null location from the src0
// Initial intended use is to allow for dependencies for results from wait_event
// intrinsic call
template <typename T> void __cm_intrinsic_impl_dummy_mov(T src0);

// Predefined surface support.
SurfaceIndex __cm_intrinsic_impl_predefined_surface(unsigned id);

template <typename T1, typename T2, typename T3, typename T4, int N>
vector<T1, N> __cm_intrinsic_impl_dp4a(vector<T2, N> src0, vector<T3, N> src1, vector<T4, N> src2,
                                       int flag);

template <typename T>
T __cm_intrinsic_impl_bfn(T s0, T s1, T s2, unsigned char bfval);

// ----------------------------------------------------------------------------
//
// Conversions to special types
//
// ----------------------------------------------------------------------------

template <typename T, typename T0, int N>
vector<T, N> __cm_intrinsic_impl_tf32_cvt(vector<T0, N> src0);

// ----------------------------------------------------------------------------
//
// LSC intrinsics
//
// ----------------------------------------------------------------------------

template <DataSize DS, VectorSize VS, int ImmOffset, CacheHint L1H,
          CacheHint L2H, int N>
void __cm_intrinsic_impl_prefetch_bti(SurfaceIndex Idx, vector<uint, N> Offset,
                                      vector<ushort, N> Pred);

template <DataSize DS, VectorSize VS, int ImmOffset, CacheHint L1H, CacheHint L2H, int N>
void __cm_intrinsic_impl_prefetch_flat(uint64_t Addr, vector<uint, N> Offset,
                                       vector<ushort, N> Pred);

template <DataSize DS, VectorSize VS, int ImmOffset, CacheHint L1H,
          CacheHint L2H>
void __cm_intrinsic_impl_block_prefetch_bti(SurfaceIndex Idx, unsigned Offset);

template <DataSize DS, VectorSize VS, int ImmOffset, CacheHint L1H,
          CacheHint L2H>
void __cm_intrinsic_impl_block_prefetch_flat(uint64_t Addr, unsigned Offset);

template <typename RetTy, DataSize DS, VectorSize VS, int ImmOffset,
          CacheHint L1H, CacheHint L2H, bool Transposed, int N>
RetTy __cm_intrinsic_impl_load_bti(SurfaceIndex Idx, vector<uint, N> Offset,
                                   vector<ushort, N> Pred);

template <typename RetTy, DataSize DS, VectorSize VS, int ImmOffset,
          CacheHint L1H, CacheHint L2H, bool Transposed, int N>
RetTy __cm_intrinsic_impl_load_flat(uint64_t Addr, vector<uint, N> Offset,
                                   vector<ushort, N> Pred);

template <typename RetTy, DataSize DS, VectorSize VS, int ImmOffset,
          CacheHint L1H, CacheHint L2H, bool Transposed, int N>
RetTy __cm_intrinsic_impl_load4_bti(SurfaceIndex Idx, vector<uint, N> Offset,
                                    vector<ushort, N> Pred,
                                    ChannelMaskType mask);

template <typename RetTy, DataSize DS, VectorSize VS, int ImmOffset,
          CacheHint L1H, CacheHint L2H, bool Transposed, int N>
RetTy __cm_intrinsic_impl_load4_flat(uint64_t Addr, vector<uint, N> Offset,
                                     vector<ushort, N> Pred,
                                     ChannelMaskType mask);
template <typename RetTy, DataSize DS, VectorSize VS, int ImmOffset,
          CacheHint L1H, CacheHint L2H, bool Transposed>
RetTy __cm_intrinsic_impl_block_load_bti(SurfaceIndex Idx, unsigned Offset);

template <typename RetTy, DataSize DS, VectorSize VS, int ImmOffset,
          CacheHint L1H, CacheHint L2H, bool Transposed>
RetTy __cm_intrinsic_impl_block_load_flat(uint64_t Addr, unsigned Offset);

template <typename T, DataSize DS, VectorSize VS, int ImmOffset,
          CacheHint L1H, CacheHint L2H, bool Transposed, int N>
void __cm_intrinsic_impl_store_bti(
    SurfaceIndex Idx, vector<uint, N> Offset,
    vector<T, N * details::lsc_vector_size<VS>()> Data, vector<ushort, N> Pred);

template <typename T, DataSize DS, VectorSize VS, int ImmOffset,
          CacheHint L1H, CacheHint L2H, bool Transposed, int N>
void __cm_intrinsic_impl_store_flat(
    uint64_t Addr, vector<uint, N> Offset,
    vector<T, N * details::lsc_vector_size<VS>()> Data, vector<ushort, N> Pred);

template <typename T, DataSize DS, VectorSize VS, int ImmOffset, CacheHint L1H,
          CacheHint L2H, bool Transposed, int N>
void __cm_intrinsic_impl_store4_bti(
    SurfaceIndex Idx, vector<uint, N> Offset,
    vector<T, N * details::lsc_vector_size<VS>()> Data, vector<ushort, N> Pred,
    ChannelMaskType mask);

template <typename T, DataSize DS, VectorSize VS, int ImmOffset, CacheHint L1H,
          CacheHint L2H, bool Transposed, int N>
void __cm_intrinsic_impl_store4_flat(
    uint64_t Addr, vector<uint, N> Offset,
    vector<T, N * details::lsc_vector_size<VS>()> Data, vector<ushort, N> Pred,
    ChannelMaskType mask);

template <typename T, DataSize DS, VectorSize VS, int ImmOffset, CacheHint L1H,
          CacheHint L2H, bool Transposed>
void __cm_intrinsic_impl_block_store_bti(
    SurfaceIndex Idx, unsigned Offset,
    vector<T, details::lsc_vector_size<VS>()> Data);

template <typename T, DataSize DS, VectorSize VS, int ImmOffset, CacheHint L1H,
          CacheHint L2H, bool Transposed>
void __cm_intrinsic_impl_block_store_flat(
    uint64_t Addr, unsigned Offset,
    vector<T, details::lsc_vector_size<VS>()> Data);

template <typename RetTy, DataSize DS, VectorSize VS, int ImmOffset,
          bool Transposed, int N>
RetTy __cm_intrinsic_impl_load_slm(vector<unsigned, N> Offset,
                                   vector<ushort, N> Pred);

template <typename RetTy, DataSize DS, VectorSize VS, int ImmOffset,
          bool Transposed, int N>
RetTy __cm_intrinsic_impl_load4_slm(vector<unsigned, N> Offset,
                                    vector<ushort, N> Pred,
                                    ChannelMaskType mask);

template <typename T, DataSize DS, VectorSize VS, int ImmOffset,
          bool Transposed, int N>
void __cm_intrinsic_impl_store_slm(
    vector<unsigned, N> Offset,
    vector<T, N * details::lsc_vector_size<VS>()> Data,
    vector<ushort, N> Pred);

template <typename T, DataSize DS, VectorSize VS, int ImmOffset,
          bool Transposed, int N>
void __cm_intrinsic_impl_store4_slm(
    vector<unsigned, N> Offset,
    vector<T, N * details::lsc_vector_size<VS>()> Data, vector<ushort, N> Pred,
    ChannelMaskType mask);

template <typename T, int NBlocks, int Width, int Height, bool Transposed,
          bool Transformed, CacheHint L1H, CacheHint L2H, int N>
vector<T, N> __cm_intrinsic_impl_block_load2d_flat(uintptr_t BaseAddr,
    unsigned SurfaceWidth, unsigned SurfaceHeight, unsigned SurfacePitch,
    int X, int Y);

template <typename T, int NBlocks, int Width, int Height, CacheHint L1H,
          CacheHint L2H, int N>
void __cm_intrinsic_impl_block_store2d_flat(uintptr_t BaseAddr,
    unsigned SurfaceWidth, unsigned SurfaceHeight, unsigned SurfacePitch,
    int X, int Y, vector<T, N> Data);

template <typename T, int NBlocks, int Width, int Height, CacheHint L1H,
          CacheHint L2H>
void __cm_intrinsic_impl_block_prefetch2d_flat(uintptr_t BaseAddr,
    unsigned SurfaceWidth, unsigned SurfaceHeight, unsigned SurfacePitch,
    int X, int Y);

template <ChannelMaskType Mask, CacheHint L1H, CacheHint L2H, int N, typename T,
          int M>
matrix<T, M, N> __cm_intrinsic_impl_load4_typed_bti(
    vector<ushort, N> Pred, SurfaceIndex Image, vector<unsigned, N> U,
    vector<unsigned, N> V, vector<unsigned, N> R, vector<unsigned, N> LOD,
    matrix<T, M, N>);
template <ChannelMaskType Mask, CacheHint L1H, CacheHint L2H, int N, typename T,
          int M>
void __cm_intrinsic_impl_store4_typed_bti(
    vector<ushort, N> Pred, SurfaceIndex Image, vector<unsigned, N> U,
    vector<unsigned, N> V, vector<unsigned, N> R, vector<unsigned, N> LOD,
    matrix<T, M, N> StoreData);
template <ChannelMaskType Mask, CacheHint L1H, CacheHint L2H, int N>
void __cm_intrinsic_impl_prefetch4_typed_bti(
    vector<ushort, N> Pred, SurfaceIndex Image, vector<unsigned, N> U,
    vector<unsigned, N> V, vector<unsigned, N> R, vector<unsigned, N> LOD);

template <typename T, int Height, int Width, CacheHint L1H, CacheHint L2H>
matrix<T, Height, Width> __cm_intrinsic_impl_load2d_bti(SurfaceIndex, int, int);

template <typename T, int Height, int Width, CacheHint L1H, CacheHint L2H>
void __cm_intrinsic_impl_prefetch2d_bti(SurfaceIndex, int, int);

template <typename T, int Height, int Width, CacheHint L1H, CacheHint L2H>
void __cm_intrinsic_impl_store2d_bti(SurfaceIndex, int, int,
                                     matrix<T, Height, Width>);

template <AtomicOp Op, DataSize DS, VectorSize VS, bool Transposed,
          CacheHint L1H, CacheHint L2H, typename RetTy, int N, typename... Args>
RetTy __cm_intrinsic_impl_lsc_atomic_bti(vector<ushort, N> Pred,
                                         SurfaceIndex Idx,
                                         vector<unsigned, N> Offset,
                                         Args... args);

template <AtomicOp Op, DataSize DS, VectorSize VS, bool Transposed,
          CacheHint L1H, CacheHint L2H, typename RetTy, int N, typename... Args>
RetTy __cm_intrinsic_impl_lsc_atomic_flat(vector<ushort, N> Pred,
                                          uint64_t Addr,
                                          vector<unsigned, N> Offset,
                                          Args... args);

template <AtomicOp Op, DataSize DS, VectorSize VS, bool Transposed,
          CacheHint L1H, CacheHint L2H, typename RetTy, int N, typename... Args>
RetTy __cm_intrinsic_impl_lsc_atomic_slm(vector<ushort, N> Pred,
                                         vector<unsigned, N> Offset,
                                         Args... args);

template <LSC_SFID Sfid, LSC_FENCE_OP FenceOp, LSC_SCOPE Scope, int N>
void __cm_intrinsic_impl_lsc_fence(vector<ushort, N> Pred);

template <typename T, int n> struct simd_type {
  static constexpr int length = n;
  using type = T __attribute__((ext_vector_type(n)));
  using element_type = T;
};

template <int n> struct mask_type {
  static constexpr int length = n;
  using type = uint16_t __attribute__((ext_vector_type(n)));
};

template <int width, int stride, typename T, int n>
typename simd_type<T, width>::type
__cm_intrinsic_impl_rdregion(typename simd_type<T, n>::type in, int offset);

template <int width, int stride, typename T, int n, int m>
typename simd_type<T, n>::type
__cm_intrinsic_impl_wrregion(typename simd_type<T, n>::type oldVal,
                             typename simd_type<T, m>::type newVal, int offset,
                             typename mask_type<n>::type mask = 1);

template <typename T, int n, int A = 0>
typename simd_type<T, n>::type
__cm_builtin_impl_svm_gather(typename simd_type<uint64_t, n>::type addrs,
                             typename simd_type<ushort, n>::type mask,
                             typename simd_type<T, n>::type oldVal);

template <typename T, int n, int A = 0>
void __cm_builtin_impl_svm_scatter(typename simd_type<T, n>::type src,
                                   typename simd_type<uint64_t, n>::type addrs,
                                   typename simd_type<ushort, n>::type mask);

void __cm_intrinsic_impl_nbarrier_arrive(uchar BarrierId, uchar Role,
                                         uchar NumProducers,
                                         uchar NumConsumers);

} // namespace details


#endif
