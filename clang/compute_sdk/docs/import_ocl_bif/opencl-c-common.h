//===--- opencl-c-common.h - OpenCL C language builtin function header ----===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef _OPENCL_COMMON_H_
#define _OPENCL_COMMON_H_

#define cl_khr_fp16
#define cl_khr_fp64
#define CL_VERSION_1_2 120
#define CL_VERSION_2_0 200
#define __OPENCL_C_VERSION__ CL_VERSION_1_2

#define __ovld __attribute__((overloadable))
#define __conv __attribute__((convergent))

// Optimizations
#define __purefn __attribute__((pure))
#define __cnfn __attribute__((const))

#ifdef cl_khr_fp64
#if __OPENCL_C_VERSION__ < CL_VERSION_1_2
#pragma OPENCL EXTENSION cl_khr_fp64 : enable
#endif
#endif

#if __OPENCL_C_VERSION__ < CL_VERSION_2_0
#ifdef cl_khr_3d_image_writes
#pragma OPENCL EXTENSION cl_khr_3d_image_writes : enable
#endif //cl_khr_3d_image_writes
#endif //__OPENCL_C_VERSION__ < CL_VERSION_2_0

// built-in scalar data types:

/**
 * An unsigned 8-bit integer.
 */
typedef unsigned char uchar;

/**
 * An unsigned 16-bit integer.
 */
typedef unsigned short ushort;

/**
 * An unsigned 32-bit integer.
 */
typedef unsigned int uint;

/**
 * An unsigned 64-bit integer.
 */
typedef unsigned long ulong;

// Flag type and values for barrier, mem_fence, read_mem_fence, write_mem_fence
typedef uint cl_mem_fence_flags;


// built-in vector data types:
typedef char char2 __attribute__((ext_vector_type(2)));
typedef char char3 __attribute__((ext_vector_type(3)));
typedef char char4 __attribute__((ext_vector_type(4)));
typedef char char8 __attribute__((ext_vector_type(8)));
typedef char char16 __attribute__((ext_vector_type(16)));
typedef uchar uchar2 __attribute__((ext_vector_type(2)));
typedef uchar uchar3 __attribute__((ext_vector_type(3)));
typedef uchar uchar4 __attribute__((ext_vector_type(4)));
typedef uchar uchar8 __attribute__((ext_vector_type(8)));
typedef uchar uchar16 __attribute__((ext_vector_type(16)));
typedef short short2 __attribute__((ext_vector_type(2)));
typedef short short3 __attribute__((ext_vector_type(3)));
typedef short short4 __attribute__((ext_vector_type(4)));
typedef short short8 __attribute__((ext_vector_type(8)));
typedef short short16 __attribute__((ext_vector_type(16)));
typedef ushort ushort2 __attribute__((ext_vector_type(2)));
typedef ushort ushort3 __attribute__((ext_vector_type(3)));
typedef ushort ushort4 __attribute__((ext_vector_type(4)));
typedef ushort ushort8 __attribute__((ext_vector_type(8)));
typedef ushort ushort16 __attribute__((ext_vector_type(16)));
typedef int int2 __attribute__((ext_vector_type(2)));
typedef int int3 __attribute__((ext_vector_type(3)));
typedef int int4 __attribute__((ext_vector_type(4)));
typedef int int8 __attribute__((ext_vector_type(8)));
typedef int int16 __attribute__((ext_vector_type(16)));
typedef uint uint2 __attribute__((ext_vector_type(2)));
typedef uint uint3 __attribute__((ext_vector_type(3)));
typedef uint uint4 __attribute__((ext_vector_type(4)));
typedef uint uint8 __attribute__((ext_vector_type(8)));
typedef uint uint16 __attribute__((ext_vector_type(16)));
typedef long long2 __attribute__((ext_vector_type(2)));
typedef long long3 __attribute__((ext_vector_type(3)));
typedef long long4 __attribute__((ext_vector_type(4)));
typedef long long8 __attribute__((ext_vector_type(8)));
typedef long long16 __attribute__((ext_vector_type(16)));
typedef ulong ulong2 __attribute__((ext_vector_type(2)));
typedef ulong ulong3 __attribute__((ext_vector_type(3)));
typedef ulong ulong4 __attribute__((ext_vector_type(4)));
typedef ulong ulong8 __attribute__((ext_vector_type(8)));
typedef ulong ulong16 __attribute__((ext_vector_type(16)));
typedef float float2 __attribute__((ext_vector_type(2)));
typedef float float3 __attribute__((ext_vector_type(3)));
typedef float float4 __attribute__((ext_vector_type(4)));
typedef float float8 __attribute__((ext_vector_type(8)));
typedef float float16 __attribute__((ext_vector_type(16)));
#ifdef cl_khr_fp16
#pragma OPENCL EXTENSION cl_khr_fp16 : enable
typedef half half2 __attribute__((ext_vector_type(2)));
typedef half half3 __attribute__((ext_vector_type(3)));
typedef half half4 __attribute__((ext_vector_type(4)));
typedef half half8 __attribute__((ext_vector_type(8)));
typedef half half16 __attribute__((ext_vector_type(16)));
#endif
#ifdef cl_khr_fp64
typedef double double2 __attribute__((ext_vector_type(2)));
typedef double double3 __attribute__((ext_vector_type(3)));
typedef double double4 __attribute__((ext_vector_type(4)));
typedef double double8 __attribute__((ext_vector_type(8)));
typedef double double16 __attribute__((ext_vector_type(16)));
#endif

/**
 * Value of maximum non-infinite single-precision floating-point
 * number.
 */
#define MAXFLOAT 0x1.fffffep127f

/**
 * A positive float constant expression. HUGE_VALF evaluates
 * to +infinity. Used as an error value returned by the built-in
 * math functions.
 */
#define HUGE_VALF (__builtin_huge_valf())

/**
 * A positive double constant expression. HUGE_VAL evaluates
 * to +infinity. Used as an error value returned by the built-in
 * math functions.
 */
#define HUGE_VAL (__builtin_huge_val())

/**
 * A constant expression of type float representing positive or
 * unsigned infinity.
 */
#define INFINITY (__builtin_inff())

/**
 * A constant expression of type float representing a quiet NaN.
 */
#define NAN as_float(INT_MAX)

#define FP_ILOGB0    INT_MIN
#define FP_ILOGBNAN    INT_MAX

#define FLT_DIG 6
#define FLT_MANT_DIG 24
#define FLT_MAX_10_EXP +38
#define FLT_MAX_EXP +128
#define FLT_MIN_10_EXP -37
#define FLT_MIN_EXP -125
#define FLT_RADIX 2
#define FLT_MAX 0x1.fffffep127f
#define FLT_MIN 0x1.0p-126f
#define FLT_EPSILON 0x1.0p-23f

#define M_E_F         2.71828182845904523536028747135266250f
#define M_LOG2E_F     1.44269504088896340735992468100189214f
#define M_LOG10E_F    0.434294481903251827651128918916605082f
#define M_LN2_F       0.693147180559945309417232121458176568f
#define M_LN10_F      2.30258509299404568401799145468436421f
#define M_PI_F        3.14159265358979323846264338327950288f
#define M_PI_2_F      1.57079632679489661923132169163975144f
#define M_PI_4_F      0.785398163397448309615660845819875721f
#define M_1_PI_F      0.318309886183790671537767526745028724f
#define M_2_PI_F      0.636619772367581343075535053490057448f
#define M_2_SQRTPI_F  1.12837916709551257389615890312154517f
#define M_SQRT2_F     1.41421356237309504880168872420969808f
#define M_SQRT1_2_F   0.707106781186547524400844362104849039f

#define DBL_DIG 15
#define DBL_MANT_DIG 53
#define DBL_MAX_10_EXP +308
#define DBL_MAX_EXP +1024
#define DBL_MIN_10_EXP -307
#define DBL_MIN_EXP -1021
#define DBL_RADIX 2
#define DBL_MAX 0x1.fffffffffffffp1023
#define DBL_MIN 0x1.0p-1022
#define DBL_EPSILON 0x1.0p-52

#define M_E           0x1.5bf0a8b145769p+1
#define M_LOG2E       0x1.71547652b82fep+0
#define M_LOG10E      0x1.bcb7b1526e50ep-2
#define M_LN2         0x1.62e42fefa39efp-1
#define M_LN10        0x1.26bb1bbb55516p+1
#define M_PI          0x1.921fb54442d18p+1
#define M_PI_2        0x1.921fb54442d18p+0
#define M_PI_4        0x1.921fb54442d18p-1
#define M_1_PI        0x1.45f306dc9c883p-2
#define M_2_PI        0x1.45f306dc9c883p-1
#define M_2_SQRTPI    0x1.20dd750429b6dp+0
#define M_SQRT2       0x1.6a09e667f3bcdp+0
#define M_SQRT1_2     0x1.6a09e667f3bcdp-1

#ifdef cl_khr_fp16

#define HALF_DIG 3
#define HALF_MANT_DIG 11
#define HALF_MAX_10_EXP +4
#define HALF_MAX_EXP +16
#define HALF_MIN_10_EXP -4
#define HALF_MIN_EXP -13
#define HALF_RADIX 2
#define HALF_MAX ((0x1.ffcp15h))
#define HALF_MIN ((0x1.0p-14h))
#define HALF_EPSILON ((0x1.0p-10h))

#define M_E_H         2.71828182845904523536028747135266250h
#define M_LOG2E_H     1.44269504088896340735992468100189214h
#define M_LOG10E_H    0.434294481903251827651128918916605082h
#define M_LN2_H       0.693147180559945309417232121458176568h
#define M_LN10_H      2.30258509299404568401799145468436421h
#define M_PI_H        3.14159265358979323846264338327950288h
#define M_PI_2_H      1.57079632679489661923132169163975144h
#define M_PI_4_H      0.785398163397448309615660845819875721h
#define M_1_PI_H      0.318309886183790671537767526745028724h
#define M_2_PI_H      0.636619772367581343075535053490057448h
#define M_2_SQRTPI_H  1.12837916709551257389615890312154517h
#define M_SQRT2_H     1.41421356237309504880168872420969808h
#define M_SQRT1_2_H   0.707106781186547524400844362104849039h

#endif //cl_khr_fp16

#define CHAR_BIT    8
#define SCHAR_MAX  127
#define SCHAR_MIN  (-128)
#define UCHAR_MAX  255
#define CHAR_MAX  SCHAR_MAX
#define CHAR_MIN  SCHAR_MIN
#define USHRT_MAX  65535
#define SHRT_MAX  32767
#define SHRT_MIN  (-32768)
#define UINT_MAX  0xffffffff
#define INT_MAX    2147483647
#define INT_MIN    (-2147483647-1)
#define ULONG_MAX  0xffffffffffffffffUL
#define LONG_MAX  0x7fffffffffffffffL
#define LONG_MIN  (-0x7fffffffffffffffL-1)

// OpenCL v1.1/1.2/2.0 s6.2.3 - Explicit conversions

char __ovld __cnfn convert_char_rte(char);
char __ovld __cnfn convert_char_sat_rte(char);
char __ovld __cnfn convert_char_rtz(char);
char __ovld __cnfn convert_char_sat_rtz(char);
char __ovld __cnfn convert_char_rtp(char);
char __ovld __cnfn convert_char_sat_rtp(char);
char __ovld __cnfn convert_char_rtn(char);
char __ovld __cnfn convert_char_sat_rtn(char);
char __ovld __cnfn convert_char(char);
char __ovld __cnfn convert_char_sat(char);
char __ovld __cnfn convert_char_rte(uchar);
char __ovld __cnfn convert_char_sat_rte(uchar);
char __ovld __cnfn convert_char_rtz(uchar);
char __ovld __cnfn convert_char_sat_rtz(uchar);
char __ovld __cnfn convert_char_rtp(uchar);
char __ovld __cnfn convert_char_sat_rtp(uchar);
char __ovld __cnfn convert_char_rtn(uchar);
char __ovld __cnfn convert_char_sat_rtn(uchar);
char __ovld __cnfn convert_char(uchar);
char __ovld __cnfn convert_char_sat(uchar);
char __ovld __cnfn convert_char_rte(short);
char __ovld __cnfn convert_char_sat_rte(short);
char __ovld __cnfn convert_char_rtz(short);
char __ovld __cnfn convert_char_sat_rtz(short);
char __ovld __cnfn convert_char_rtp(short);
char __ovld __cnfn convert_char_sat_rtp(short);
char __ovld __cnfn convert_char_rtn(short);
char __ovld __cnfn convert_char_sat_rtn(short);
char __ovld __cnfn convert_char(short);
char __ovld __cnfn convert_char_sat(short);
char __ovld __cnfn convert_char_rte(ushort);
char __ovld __cnfn convert_char_sat_rte(ushort);
char __ovld __cnfn convert_char_rtz(ushort);
char __ovld __cnfn convert_char_sat_rtz(ushort);
char __ovld __cnfn convert_char_rtp(ushort);
char __ovld __cnfn convert_char_sat_rtp(ushort);
char __ovld __cnfn convert_char_rtn(ushort);
char __ovld __cnfn convert_char_sat_rtn(ushort);
char __ovld __cnfn convert_char(ushort);
char __ovld __cnfn convert_char_sat(ushort);
char __ovld __cnfn convert_char_rte(int);
char __ovld __cnfn convert_char_sat_rte(int);
char __ovld __cnfn convert_char_rtz(int);
char __ovld __cnfn convert_char_sat_rtz(int);
char __ovld __cnfn convert_char_rtp(int);
char __ovld __cnfn convert_char_sat_rtp(int);
char __ovld __cnfn convert_char_rtn(int);
char __ovld __cnfn convert_char_sat_rtn(int);
char __ovld __cnfn convert_char(int);
char __ovld __cnfn convert_char_sat(int);
char __ovld __cnfn convert_char_rte(uint);
char __ovld __cnfn convert_char_sat_rte(uint);
char __ovld __cnfn convert_char_rtz(uint);
char __ovld __cnfn convert_char_sat_rtz(uint);
char __ovld __cnfn convert_char_rtp(uint);
char __ovld __cnfn convert_char_sat_rtp(uint);
char __ovld __cnfn convert_char_rtn(uint);
char __ovld __cnfn convert_char_sat_rtn(uint);
char __ovld __cnfn convert_char(uint);
char __ovld __cnfn convert_char_sat(uint);
char __ovld __cnfn convert_char_rte(long);
char __ovld __cnfn convert_char_sat_rte(long);
char __ovld __cnfn convert_char_rtz(long);
char __ovld __cnfn convert_char_sat_rtz(long);
char __ovld __cnfn convert_char_rtp(long);
char __ovld __cnfn convert_char_sat_rtp(long);
char __ovld __cnfn convert_char_rtn(long);
char __ovld __cnfn convert_char_sat_rtn(long);
char __ovld __cnfn convert_char(long);
char __ovld __cnfn convert_char_sat(long);
char __ovld __cnfn convert_char_rte(ulong);
char __ovld __cnfn convert_char_sat_rte(ulong);
char __ovld __cnfn convert_char_rtz(ulong);
char __ovld __cnfn convert_char_sat_rtz(ulong);
char __ovld __cnfn convert_char_rtp(ulong);
char __ovld __cnfn convert_char_sat_rtp(ulong);
char __ovld __cnfn convert_char_rtn(ulong);
char __ovld __cnfn convert_char_sat_rtn(ulong);
char __ovld __cnfn convert_char(ulong);
char __ovld __cnfn convert_char_sat(ulong);
char __ovld __cnfn convert_char_rte(float);
char __ovld __cnfn convert_char_sat_rte(float);
char __ovld __cnfn convert_char_rtz(float);
char __ovld __cnfn convert_char_sat_rtz(float);
char __ovld __cnfn convert_char_rtp(float);
char __ovld __cnfn convert_char_sat_rtp(float);
char __ovld __cnfn convert_char_rtn(float);
char __ovld __cnfn convert_char_sat_rtn(float);
char __ovld __cnfn convert_char(float);
char __ovld __cnfn convert_char_sat(float);
uchar __ovld __cnfn convert_uchar_rte(char);
uchar __ovld __cnfn convert_uchar_sat_rte(char);
uchar __ovld __cnfn convert_uchar_rtz(char);
uchar __ovld __cnfn convert_uchar_sat_rtz(char);
uchar __ovld __cnfn convert_uchar_rtp(char);
uchar __ovld __cnfn convert_uchar_sat_rtp(char);
uchar __ovld __cnfn convert_uchar_rtn(char);
uchar __ovld __cnfn convert_uchar_sat_rtn(char);
uchar __ovld __cnfn convert_uchar(char);
uchar __ovld __cnfn convert_uchar_sat(char);
uchar __ovld __cnfn convert_uchar_rte(uchar);
uchar __ovld __cnfn convert_uchar_sat_rte(uchar);
uchar __ovld __cnfn convert_uchar_rtz(uchar);
uchar __ovld __cnfn convert_uchar_sat_rtz(uchar);
uchar __ovld __cnfn convert_uchar_rtp(uchar);
uchar __ovld __cnfn convert_uchar_sat_rtp(uchar);
uchar __ovld __cnfn convert_uchar_rtn(uchar);
uchar __ovld __cnfn convert_uchar_sat_rtn(uchar);
uchar __ovld __cnfn convert_uchar(uchar);
uchar __ovld __cnfn convert_uchar_sat(uchar);
uchar __ovld __cnfn convert_uchar_rte(short);
uchar __ovld __cnfn convert_uchar_sat_rte(short);
uchar __ovld __cnfn convert_uchar_rtz(short);
uchar __ovld __cnfn convert_uchar_sat_rtz(short);
uchar __ovld __cnfn convert_uchar_rtp(short);
uchar __ovld __cnfn convert_uchar_sat_rtp(short);
uchar __ovld __cnfn convert_uchar_rtn(short);
uchar __ovld __cnfn convert_uchar_sat_rtn(short);
uchar __ovld __cnfn convert_uchar(short);
uchar __ovld __cnfn convert_uchar_sat(short);
uchar __ovld __cnfn convert_uchar_rte(ushort);
uchar __ovld __cnfn convert_uchar_sat_rte(ushort);
uchar __ovld __cnfn convert_uchar_rtz(ushort);
uchar __ovld __cnfn convert_uchar_sat_rtz(ushort);
uchar __ovld __cnfn convert_uchar_rtp(ushort);
uchar __ovld __cnfn convert_uchar_sat_rtp(ushort);
uchar __ovld __cnfn convert_uchar_rtn(ushort);
uchar __ovld __cnfn convert_uchar_sat_rtn(ushort);
uchar __ovld __cnfn convert_uchar(ushort);
uchar __ovld __cnfn convert_uchar_sat(ushort);
uchar __ovld __cnfn convert_uchar_rte(int);
uchar __ovld __cnfn convert_uchar_sat_rte(int);
uchar __ovld __cnfn convert_uchar_rtz(int);
uchar __ovld __cnfn convert_uchar_sat_rtz(int);
uchar __ovld __cnfn convert_uchar_rtp(int);
uchar __ovld __cnfn convert_uchar_sat_rtp(int);
uchar __ovld __cnfn convert_uchar_rtn(int);
uchar __ovld __cnfn convert_uchar_sat_rtn(int);
uchar __ovld __cnfn convert_uchar(int);
uchar __ovld __cnfn convert_uchar_sat(int);
uchar __ovld __cnfn convert_uchar_rte(uint);
uchar __ovld __cnfn convert_uchar_sat_rte(uint);
uchar __ovld __cnfn convert_uchar_rtz(uint);
uchar __ovld __cnfn convert_uchar_sat_rtz(uint);
uchar __ovld __cnfn convert_uchar_rtp(uint);
uchar __ovld __cnfn convert_uchar_sat_rtp(uint);
uchar __ovld __cnfn convert_uchar_rtn(uint);
uchar __ovld __cnfn convert_uchar_sat_rtn(uint);
uchar __ovld __cnfn convert_uchar(uint);
uchar __ovld __cnfn convert_uchar_sat(uint);
uchar __ovld __cnfn convert_uchar_rte(long);
uchar __ovld __cnfn convert_uchar_sat_rte(long);
uchar __ovld __cnfn convert_uchar_rtz(long);
uchar __ovld __cnfn convert_uchar_sat_rtz(long);
uchar __ovld __cnfn convert_uchar_rtp(long);
uchar __ovld __cnfn convert_uchar_sat_rtp(long);
uchar __ovld __cnfn convert_uchar_rtn(long);
uchar __ovld __cnfn convert_uchar_sat_rtn(long);
uchar __ovld __cnfn convert_uchar(long);
uchar __ovld __cnfn convert_uchar_sat(long);
uchar __ovld __cnfn convert_uchar_rte(ulong);
uchar __ovld __cnfn convert_uchar_sat_rte(ulong);
uchar __ovld __cnfn convert_uchar_rtz(ulong);
uchar __ovld __cnfn convert_uchar_sat_rtz(ulong);
uchar __ovld __cnfn convert_uchar_rtp(ulong);
uchar __ovld __cnfn convert_uchar_sat_rtp(ulong);
uchar __ovld __cnfn convert_uchar_rtn(ulong);
uchar __ovld __cnfn convert_uchar_sat_rtn(ulong);
uchar __ovld __cnfn convert_uchar(ulong);
uchar __ovld __cnfn convert_uchar_sat(ulong);
uchar __ovld __cnfn convert_uchar_rte(float);
uchar __ovld __cnfn convert_uchar_sat_rte(float);
uchar __ovld __cnfn convert_uchar_rtz(float);
uchar __ovld __cnfn convert_uchar_sat_rtz(float);
uchar __ovld __cnfn convert_uchar_rtp(float);
uchar __ovld __cnfn convert_uchar_sat_rtp(float);
uchar __ovld __cnfn convert_uchar_rtn(float);
uchar __ovld __cnfn convert_uchar_sat_rtn(float);
uchar __ovld __cnfn convert_uchar(float);
uchar __ovld __cnfn convert_uchar_sat(float);

short __ovld __cnfn convert_short_rte(char);
short __ovld __cnfn convert_short_sat_rte(char);
short __ovld __cnfn convert_short_rtz(char);
short __ovld __cnfn convert_short_sat_rtz(char);
short __ovld __cnfn convert_short_rtp(char);
short __ovld __cnfn convert_short_sat_rtp(char);
short __ovld __cnfn convert_short_rtn(char);
short __ovld __cnfn convert_short_sat_rtn(char);
short __ovld __cnfn convert_short(char);
short __ovld __cnfn convert_short_sat(char);
short __ovld __cnfn convert_short_rte(uchar);
short __ovld __cnfn convert_short_sat_rte(uchar);
short __ovld __cnfn convert_short_rtz(uchar);
short __ovld __cnfn convert_short_sat_rtz(uchar);
short __ovld __cnfn convert_short_rtp(uchar);
short __ovld __cnfn convert_short_sat_rtp(uchar);
short __ovld __cnfn convert_short_rtn(uchar);
short __ovld __cnfn convert_short_sat_rtn(uchar);
short __ovld __cnfn convert_short(uchar);
short __ovld __cnfn convert_short_sat(uchar);
short __ovld __cnfn convert_short_rte(short);
short __ovld __cnfn convert_short_sat_rte(short);
short __ovld __cnfn convert_short_rtz(short);
short __ovld __cnfn convert_short_sat_rtz(short);
short __ovld __cnfn convert_short_rtp(short);
short __ovld __cnfn convert_short_sat_rtp(short);
short __ovld __cnfn convert_short_rtn(short);
short __ovld __cnfn convert_short_sat_rtn(short);
short __ovld __cnfn convert_short(short);
short __ovld __cnfn convert_short_sat(short);
short __ovld __cnfn convert_short_rte(ushort);
short __ovld __cnfn convert_short_sat_rte(ushort);
short __ovld __cnfn convert_short_rtz(ushort);
short __ovld __cnfn convert_short_sat_rtz(ushort);
short __ovld __cnfn convert_short_rtp(ushort);
short __ovld __cnfn convert_short_sat_rtp(ushort);
short __ovld __cnfn convert_short_rtn(ushort);
short __ovld __cnfn convert_short_sat_rtn(ushort);
short __ovld __cnfn convert_short(ushort);
short __ovld __cnfn convert_short_sat(ushort);
short __ovld __cnfn convert_short_rte(int);
short __ovld __cnfn convert_short_sat_rte(int);
short __ovld __cnfn convert_short_rtz(int);
short __ovld __cnfn convert_short_sat_rtz(int);
short __ovld __cnfn convert_short_rtp(int);
short __ovld __cnfn convert_short_sat_rtp(int);
short __ovld __cnfn convert_short_rtn(int);
short __ovld __cnfn convert_short_sat_rtn(int);
short __ovld __cnfn convert_short(int);
short __ovld __cnfn convert_short_sat(int);
short __ovld __cnfn convert_short_rte(uint);
short __ovld __cnfn convert_short_sat_rte(uint);
short __ovld __cnfn convert_short_rtz(uint);
short __ovld __cnfn convert_short_sat_rtz(uint);
short __ovld __cnfn convert_short_rtp(uint);
short __ovld __cnfn convert_short_sat_rtp(uint);
short __ovld __cnfn convert_short_rtn(uint);
short __ovld __cnfn convert_short_sat_rtn(uint);
short __ovld __cnfn convert_short(uint);
short __ovld __cnfn convert_short_sat(uint);
short __ovld __cnfn convert_short_rte(long);
short __ovld __cnfn convert_short_sat_rte(long);
short __ovld __cnfn convert_short_rtz(long);
short __ovld __cnfn convert_short_sat_rtz(long);
short __ovld __cnfn convert_short_rtp(long);
short __ovld __cnfn convert_short_sat_rtp(long);
short __ovld __cnfn convert_short_rtn(long);
short __ovld __cnfn convert_short_sat_rtn(long);
short __ovld __cnfn convert_short(long);
short __ovld __cnfn convert_short_sat(long);
short __ovld __cnfn convert_short_rte(ulong);
short __ovld __cnfn convert_short_sat_rte(ulong);
short __ovld __cnfn convert_short_rtz(ulong);
short __ovld __cnfn convert_short_sat_rtz(ulong);
short __ovld __cnfn convert_short_rtp(ulong);
short __ovld __cnfn convert_short_sat_rtp(ulong);
short __ovld __cnfn convert_short_rtn(ulong);
short __ovld __cnfn convert_short_sat_rtn(ulong);
short __ovld __cnfn convert_short(ulong);
short __ovld __cnfn convert_short_sat(ulong);
short __ovld __cnfn convert_short_rte(float);
short __ovld __cnfn convert_short_sat_rte(float);
short __ovld __cnfn convert_short_rtz(float);
short __ovld __cnfn convert_short_sat_rtz(float);
short __ovld __cnfn convert_short_rtp(float);
short __ovld __cnfn convert_short_sat_rtp(float);
short __ovld __cnfn convert_short_rtn(float);
short __ovld __cnfn convert_short_sat_rtn(float);
short __ovld __cnfn convert_short(float);
short __ovld __cnfn convert_short_sat(float);
ushort __ovld __cnfn convert_ushort_rte(char);
ushort __ovld __cnfn convert_ushort_sat_rte(char);
ushort __ovld __cnfn convert_ushort_rtz(char);
ushort __ovld __cnfn convert_ushort_sat_rtz(char);
ushort __ovld __cnfn convert_ushort_rtp(char);
ushort __ovld __cnfn convert_ushort_sat_rtp(char);
ushort __ovld __cnfn convert_ushort_rtn(char);
ushort __ovld __cnfn convert_ushort_sat_rtn(char);
ushort __ovld __cnfn convert_ushort(char);
ushort __ovld __cnfn convert_ushort_sat(char);
ushort __ovld __cnfn convert_ushort_rte(uchar);
ushort __ovld __cnfn convert_ushort_sat_rte(uchar);
ushort __ovld __cnfn convert_ushort_rtz(uchar);
ushort __ovld __cnfn convert_ushort_sat_rtz(uchar);
ushort __ovld __cnfn convert_ushort_rtp(uchar);
ushort __ovld __cnfn convert_ushort_sat_rtp(uchar);
ushort __ovld __cnfn convert_ushort_rtn(uchar);
ushort __ovld __cnfn convert_ushort_sat_rtn(uchar);
ushort __ovld __cnfn convert_ushort(uchar);
ushort __ovld __cnfn convert_ushort_sat(uchar);
ushort __ovld __cnfn convert_ushort_rte(short);
ushort __ovld __cnfn convert_ushort_sat_rte(short);
ushort __ovld __cnfn convert_ushort_rtz(short);
ushort __ovld __cnfn convert_ushort_sat_rtz(short);
ushort __ovld __cnfn convert_ushort_rtp(short);
ushort __ovld __cnfn convert_ushort_sat_rtp(short);
ushort __ovld __cnfn convert_ushort_rtn(short);
ushort __ovld __cnfn convert_ushort_sat_rtn(short);
ushort __ovld __cnfn convert_ushort(short);
ushort __ovld __cnfn convert_ushort_sat(short);
ushort __ovld __cnfn convert_ushort_rte(ushort);
ushort __ovld __cnfn convert_ushort_sat_rte(ushort);
ushort __ovld __cnfn convert_ushort_rtz(ushort);
ushort __ovld __cnfn convert_ushort_sat_rtz(ushort);
ushort __ovld __cnfn convert_ushort_rtp(ushort);
ushort __ovld __cnfn convert_ushort_sat_rtp(ushort);
ushort __ovld __cnfn convert_ushort_rtn(ushort);
ushort __ovld __cnfn convert_ushort_sat_rtn(ushort);
ushort __ovld __cnfn convert_ushort(ushort);
ushort __ovld __cnfn convert_ushort_sat(ushort);
ushort __ovld __cnfn convert_ushort_rte(int);
ushort __ovld __cnfn convert_ushort_sat_rte(int);
ushort __ovld __cnfn convert_ushort_rtz(int);
ushort __ovld __cnfn convert_ushort_sat_rtz(int);
ushort __ovld __cnfn convert_ushort_rtp(int);
ushort __ovld __cnfn convert_ushort_sat_rtp(int);
ushort __ovld __cnfn convert_ushort_rtn(int);
ushort __ovld __cnfn convert_ushort_sat_rtn(int);
ushort __ovld __cnfn convert_ushort(int);
ushort __ovld __cnfn convert_ushort_sat(int);
ushort __ovld __cnfn convert_ushort_rte(uint);
ushort __ovld __cnfn convert_ushort_sat_rte(uint);
ushort __ovld __cnfn convert_ushort_rtz(uint);
ushort __ovld __cnfn convert_ushort_sat_rtz(uint);
ushort __ovld __cnfn convert_ushort_rtp(uint);
ushort __ovld __cnfn convert_ushort_sat_rtp(uint);
ushort __ovld __cnfn convert_ushort_rtn(uint);
ushort __ovld __cnfn convert_ushort_sat_rtn(uint);
ushort __ovld __cnfn convert_ushort(uint);
ushort __ovld __cnfn convert_ushort_sat(uint);
ushort __ovld __cnfn convert_ushort_rte(long);
ushort __ovld __cnfn convert_ushort_sat_rte(long);
ushort __ovld __cnfn convert_ushort_rtz(long);
ushort __ovld __cnfn convert_ushort_sat_rtz(long);
ushort __ovld __cnfn convert_ushort_rtp(long);
ushort __ovld __cnfn convert_ushort_sat_rtp(long);
ushort __ovld __cnfn convert_ushort_rtn(long);
ushort __ovld __cnfn convert_ushort_sat_rtn(long);
ushort __ovld __cnfn convert_ushort(long);
ushort __ovld __cnfn convert_ushort_sat(long);
ushort __ovld __cnfn convert_ushort_rte(ulong);
ushort __ovld __cnfn convert_ushort_sat_rte(ulong);
ushort __ovld __cnfn convert_ushort_rtz(ulong);
ushort __ovld __cnfn convert_ushort_sat_rtz(ulong);
ushort __ovld __cnfn convert_ushort_rtp(ulong);
ushort __ovld __cnfn convert_ushort_sat_rtp(ulong);
ushort __ovld __cnfn convert_ushort_rtn(ulong);
ushort __ovld __cnfn convert_ushort_sat_rtn(ulong);
ushort __ovld __cnfn convert_ushort(ulong);
ushort __ovld __cnfn convert_ushort_sat(ulong);
ushort __ovld __cnfn convert_ushort_rte(float);
ushort __ovld __cnfn convert_ushort_sat_rte(float);
ushort __ovld __cnfn convert_ushort_rtz(float);
ushort __ovld __cnfn convert_ushort_sat_rtz(float);
ushort __ovld __cnfn convert_ushort_rtp(float);
ushort __ovld __cnfn convert_ushort_sat_rtp(float);
ushort __ovld __cnfn convert_ushort_rtn(float);
ushort __ovld __cnfn convert_ushort_sat_rtn(float);
ushort __ovld __cnfn convert_ushort(float);
ushort __ovld __cnfn convert_ushort_sat(float);
int __ovld __cnfn convert_int_rte(char);
int __ovld __cnfn convert_int_sat_rte(char);
int __ovld __cnfn convert_int_rtz(char);
int __ovld __cnfn convert_int_sat_rtz(char);
int __ovld __cnfn convert_int_rtp(char);
int __ovld __cnfn convert_int_sat_rtp(char);
int __ovld __cnfn convert_int_rtn(char);
int __ovld __cnfn convert_int_sat_rtn(char);
int __ovld __cnfn convert_int(char);
int __ovld __cnfn convert_int_sat(char);
int __ovld __cnfn convert_int_rte(uchar);
int __ovld __cnfn convert_int_sat_rte(uchar);
int __ovld __cnfn convert_int_rtz(uchar);
int __ovld __cnfn convert_int_sat_rtz(uchar);
int __ovld __cnfn convert_int_rtp(uchar);
int __ovld __cnfn convert_int_sat_rtp(uchar);
int __ovld __cnfn convert_int_rtn(uchar);
int __ovld __cnfn convert_int_sat_rtn(uchar);
int __ovld __cnfn convert_int(uchar);
int __ovld __cnfn convert_int_sat(uchar);
int __ovld __cnfn convert_int_rte(short);
int __ovld __cnfn convert_int_sat_rte(short);
int __ovld __cnfn convert_int_rtz(short);
int __ovld __cnfn convert_int_sat_rtz(short);
int __ovld __cnfn convert_int_rtp(short);
int __ovld __cnfn convert_int_sat_rtp(short);
int __ovld __cnfn convert_int_rtn(short);
int __ovld __cnfn convert_int_sat_rtn(short);
int __ovld __cnfn convert_int(short);
int __ovld __cnfn convert_int_sat(short);
int __ovld __cnfn convert_int_rte(ushort);
int __ovld __cnfn convert_int_sat_rte(ushort);
int __ovld __cnfn convert_int_rtz(ushort);
int __ovld __cnfn convert_int_sat_rtz(ushort);
int __ovld __cnfn convert_int_rtp(ushort);
int __ovld __cnfn convert_int_sat_rtp(ushort);
int __ovld __cnfn convert_int_rtn(ushort);
int __ovld __cnfn convert_int_sat_rtn(ushort);
int __ovld __cnfn convert_int(ushort);
int __ovld __cnfn convert_int_sat(ushort);
int __ovld __cnfn convert_int_rte(int);
int __ovld __cnfn convert_int_sat_rte(int);
int __ovld __cnfn convert_int_rtz(int);
int __ovld __cnfn convert_int_sat_rtz(int);
int __ovld __cnfn convert_int_rtp(int);
int __ovld __cnfn convert_int_sat_rtp(int);
int __ovld __cnfn convert_int_rtn(int);
int __ovld __cnfn convert_int_sat_rtn(int);
int __ovld __cnfn convert_int(int);
int __ovld __cnfn convert_int_sat(int);
int __ovld __cnfn convert_int_rte(uint);
int __ovld __cnfn convert_int_sat_rte(uint);
int __ovld __cnfn convert_int_rtz(uint);
int __ovld __cnfn convert_int_sat_rtz(uint);
int __ovld __cnfn convert_int_rtp(uint);
int __ovld __cnfn convert_int_sat_rtp(uint);
int __ovld __cnfn convert_int_rtn(uint);
int __ovld __cnfn convert_int_sat_rtn(uint);
int __ovld __cnfn convert_int(uint);
int __ovld __cnfn convert_int_sat(uint);
int __ovld __cnfn convert_int_rte(long);
int __ovld __cnfn convert_int_sat_rte(long);
int __ovld __cnfn convert_int_rtz(long);
int __ovld __cnfn convert_int_sat_rtz(long);
int __ovld __cnfn convert_int_rtp(long);
int __ovld __cnfn convert_int_sat_rtp(long);
int __ovld __cnfn convert_int_rtn(long);
int __ovld __cnfn convert_int_sat_rtn(long);
int __ovld __cnfn convert_int(long);
int __ovld __cnfn convert_int_sat(long);
int __ovld __cnfn convert_int_rte(ulong);
int __ovld __cnfn convert_int_sat_rte(ulong);
int __ovld __cnfn convert_int_rtz(ulong);
int __ovld __cnfn convert_int_sat_rtz(ulong);
int __ovld __cnfn convert_int_rtp(ulong);
int __ovld __cnfn convert_int_sat_rtp(ulong);
int __ovld __cnfn convert_int_rtn(ulong);
int __ovld __cnfn convert_int_sat_rtn(ulong);
int __ovld __cnfn convert_int(ulong);
int __ovld __cnfn convert_int_sat(ulong);
int __ovld __cnfn convert_int_rte(float);
int __ovld __cnfn convert_int_sat_rte(float);
int __ovld __cnfn convert_int_rtz(float);
int __ovld __cnfn convert_int_sat_rtz(float);
int __ovld __cnfn convert_int_rtp(float);
int __ovld __cnfn convert_int_sat_rtp(float);
int __ovld __cnfn convert_int_rtn(float);
int __ovld __cnfn convert_int_sat_rtn(float);
int __ovld __cnfn convert_int(float);
int __ovld __cnfn convert_int_sat(float);
uint __ovld __cnfn convert_uint_rte(char);
uint __ovld __cnfn convert_uint_sat_rte(char);
uint __ovld __cnfn convert_uint_rtz(char);
uint __ovld __cnfn convert_uint_sat_rtz(char);
uint __ovld __cnfn convert_uint_rtp(char);
uint __ovld __cnfn convert_uint_sat_rtp(char);
uint __ovld __cnfn convert_uint_rtn(char);
uint __ovld __cnfn convert_uint_sat_rtn(char);
uint __ovld __cnfn convert_uint(char);
uint __ovld __cnfn convert_uint_sat(char);
uint __ovld __cnfn convert_uint_rte(uchar);
uint __ovld __cnfn convert_uint_sat_rte(uchar);
uint __ovld __cnfn convert_uint_rtz(uchar);
uint __ovld __cnfn convert_uint_sat_rtz(uchar);
uint __ovld __cnfn convert_uint_rtp(uchar);
uint __ovld __cnfn convert_uint_sat_rtp(uchar);
uint __ovld __cnfn convert_uint_rtn(uchar);
uint __ovld __cnfn convert_uint_sat_rtn(uchar);
uint __ovld __cnfn convert_uint(uchar);
uint __ovld __cnfn convert_uint_sat(uchar);
uint __ovld __cnfn convert_uint_rte(short);
uint __ovld __cnfn convert_uint_sat_rte(short);
uint __ovld __cnfn convert_uint_rtz(short);
uint __ovld __cnfn convert_uint_sat_rtz(short);
uint __ovld __cnfn convert_uint_rtp(short);
uint __ovld __cnfn convert_uint_sat_rtp(short);
uint __ovld __cnfn convert_uint_rtn(short);
uint __ovld __cnfn convert_uint_sat_rtn(short);
uint __ovld __cnfn convert_uint(short);
uint __ovld __cnfn convert_uint_sat(short);
uint __ovld __cnfn convert_uint_rte(ushort);
uint __ovld __cnfn convert_uint_sat_rte(ushort);
uint __ovld __cnfn convert_uint_rtz(ushort);
uint __ovld __cnfn convert_uint_sat_rtz(ushort);
uint __ovld __cnfn convert_uint_rtp(ushort);
uint __ovld __cnfn convert_uint_sat_rtp(ushort);
uint __ovld __cnfn convert_uint_rtn(ushort);
uint __ovld __cnfn convert_uint_sat_rtn(ushort);
uint __ovld __cnfn convert_uint(ushort);
uint __ovld __cnfn convert_uint_sat(ushort);
uint __ovld __cnfn convert_uint_rte(int);
uint __ovld __cnfn convert_uint_sat_rte(int);
uint __ovld __cnfn convert_uint_rtz(int);
uint __ovld __cnfn convert_uint_sat_rtz(int);
uint __ovld __cnfn convert_uint_rtp(int);
uint __ovld __cnfn convert_uint_sat_rtp(int);
uint __ovld __cnfn convert_uint_rtn(int);
uint __ovld __cnfn convert_uint_sat_rtn(int);
uint __ovld __cnfn convert_uint(int);
uint __ovld __cnfn convert_uint_sat(int);
uint __ovld __cnfn convert_uint_rte(uint);
uint __ovld __cnfn convert_uint_sat_rte(uint);
uint __ovld __cnfn convert_uint_rtz(uint);
uint __ovld __cnfn convert_uint_sat_rtz(uint);
uint __ovld __cnfn convert_uint_rtp(uint);
uint __ovld __cnfn convert_uint_sat_rtp(uint);
uint __ovld __cnfn convert_uint_rtn(uint);
uint __ovld __cnfn convert_uint_sat_rtn(uint);
uint __ovld __cnfn convert_uint(uint);
uint __ovld __cnfn convert_uint_sat(uint);
uint __ovld __cnfn convert_uint_rte(long);
uint __ovld __cnfn convert_uint_sat_rte(long);
uint __ovld __cnfn convert_uint_rtz(long);
uint __ovld __cnfn convert_uint_sat_rtz(long);
uint __ovld __cnfn convert_uint_rtp(long);
uint __ovld __cnfn convert_uint_sat_rtp(long);
uint __ovld __cnfn convert_uint_rtn(long);
uint __ovld __cnfn convert_uint_sat_rtn(long);
uint __ovld __cnfn convert_uint(long);
uint __ovld __cnfn convert_uint_sat(long);
uint __ovld __cnfn convert_uint_rte(ulong);
uint __ovld __cnfn convert_uint_sat_rte(ulong);
uint __ovld __cnfn convert_uint_rtz(ulong);
uint __ovld __cnfn convert_uint_sat_rtz(ulong);
uint __ovld __cnfn convert_uint_rtp(ulong);
uint __ovld __cnfn convert_uint_sat_rtp(ulong);
uint __ovld __cnfn convert_uint_rtn(ulong);
uint __ovld __cnfn convert_uint_sat_rtn(ulong);
uint __ovld __cnfn convert_uint(ulong);
uint __ovld __cnfn convert_uint_sat(ulong);
uint __ovld __cnfn convert_uint_rte(float);
uint __ovld __cnfn convert_uint_sat_rte(float);
uint __ovld __cnfn convert_uint_rtz(float);
uint __ovld __cnfn convert_uint_sat_rtz(float);
uint __ovld __cnfn convert_uint_rtp(float);
uint __ovld __cnfn convert_uint_sat_rtp(float);
uint __ovld __cnfn convert_uint_rtn(float);
uint __ovld __cnfn convert_uint_sat_rtn(float);
uint __ovld __cnfn convert_uint(float);
uint __ovld __cnfn convert_uint_sat(float);
long __ovld __cnfn convert_long_rte(char);
long __ovld __cnfn convert_long_sat_rte(char);
long __ovld __cnfn convert_long_rtz(char);
long __ovld __cnfn convert_long_sat_rtz(char);
long __ovld __cnfn convert_long_rtp(char);
long __ovld __cnfn convert_long_sat_rtp(char);
long __ovld __cnfn convert_long_rtn(char);
long __ovld __cnfn convert_long_sat_rtn(char);
long __ovld __cnfn convert_long(char);
long __ovld __cnfn convert_long_sat(char);
long __ovld __cnfn convert_long_rte(uchar);
long __ovld __cnfn convert_long_sat_rte(uchar);
long __ovld __cnfn convert_long_rtz(uchar);
long __ovld __cnfn convert_long_sat_rtz(uchar);
long __ovld __cnfn convert_long_rtp(uchar);
long __ovld __cnfn convert_long_sat_rtp(uchar);
long __ovld __cnfn convert_long_rtn(uchar);
long __ovld __cnfn convert_long_sat_rtn(uchar);
long __ovld __cnfn convert_long(uchar);
long __ovld __cnfn convert_long_sat(uchar);
long __ovld __cnfn convert_long_rte(short);
long __ovld __cnfn convert_long_sat_rte(short);
long __ovld __cnfn convert_long_rtz(short);
long __ovld __cnfn convert_long_sat_rtz(short);
long __ovld __cnfn convert_long_rtp(short);
long __ovld __cnfn convert_long_sat_rtp(short);
long __ovld __cnfn convert_long_rtn(short);
long __ovld __cnfn convert_long_sat_rtn(short);
long __ovld __cnfn convert_long(short);
long __ovld __cnfn convert_long_sat(short);
long __ovld __cnfn convert_long_rte(ushort);
long __ovld __cnfn convert_long_sat_rte(ushort);
long __ovld __cnfn convert_long_rtz(ushort);
long __ovld __cnfn convert_long_sat_rtz(ushort);
long __ovld __cnfn convert_long_rtp(ushort);
long __ovld __cnfn convert_long_sat_rtp(ushort);
long __ovld __cnfn convert_long_rtn(ushort);
long __ovld __cnfn convert_long_sat_rtn(ushort);
long __ovld __cnfn convert_long(ushort);
long __ovld __cnfn convert_long_sat(ushort);
long __ovld __cnfn convert_long_rte(int);
long __ovld __cnfn convert_long_sat_rte(int);
long __ovld __cnfn convert_long_rtz(int);
long __ovld __cnfn convert_long_sat_rtz(int);
long __ovld __cnfn convert_long_rtp(int);
long __ovld __cnfn convert_long_sat_rtp(int);
long __ovld __cnfn convert_long_rtn(int);
long __ovld __cnfn convert_long_sat_rtn(int);
long __ovld __cnfn convert_long(int);
long __ovld __cnfn convert_long_sat(int);
long __ovld __cnfn convert_long_rte(uint);
long __ovld __cnfn convert_long_sat_rte(uint);
long __ovld __cnfn convert_long_rtz(uint);
long __ovld __cnfn convert_long_sat_rtz(uint);
long __ovld __cnfn convert_long_rtp(uint);
long __ovld __cnfn convert_long_sat_rtp(uint);
long __ovld __cnfn convert_long_rtn(uint);
long __ovld __cnfn convert_long_sat_rtn(uint);
long __ovld __cnfn convert_long(uint);
long __ovld __cnfn convert_long_sat(uint);
long __ovld __cnfn convert_long_rte(long);
long __ovld __cnfn convert_long_sat_rte(long);
long __ovld __cnfn convert_long_rtz(long);
long __ovld __cnfn convert_long_sat_rtz(long);
long __ovld __cnfn convert_long_rtp(long);
long __ovld __cnfn convert_long_sat_rtp(long);
long __ovld __cnfn convert_long_rtn(long);
long __ovld __cnfn convert_long_sat_rtn(long);
long __ovld __cnfn convert_long(long);
long __ovld __cnfn convert_long_sat(long);
long __ovld __cnfn convert_long_rte(ulong);
long __ovld __cnfn convert_long_sat_rte(ulong);
long __ovld __cnfn convert_long_rtz(ulong);
long __ovld __cnfn convert_long_sat_rtz(ulong);
long __ovld __cnfn convert_long_rtp(ulong);
long __ovld __cnfn convert_long_sat_rtp(ulong);
long __ovld __cnfn convert_long_rtn(ulong);
long __ovld __cnfn convert_long_sat_rtn(ulong);
long __ovld __cnfn convert_long(ulong);
long __ovld __cnfn convert_long_sat(ulong);
long __ovld __cnfn convert_long_rte(float);
long __ovld __cnfn convert_long_sat_rte(float);
long __ovld __cnfn convert_long_rtz(float);
long __ovld __cnfn convert_long_sat_rtz(float);
long __ovld __cnfn convert_long_rtp(float);
long __ovld __cnfn convert_long_sat_rtp(float);
long __ovld __cnfn convert_long_rtn(float);
long __ovld __cnfn convert_long_sat_rtn(float);
long __ovld __cnfn convert_long(float);
long __ovld __cnfn convert_long_sat(float);
ulong __ovld __cnfn convert_ulong_rte(char);
ulong __ovld __cnfn convert_ulong_sat_rte(char);
ulong __ovld __cnfn convert_ulong_rtz(char);
ulong __ovld __cnfn convert_ulong_sat_rtz(char);
ulong __ovld __cnfn convert_ulong_rtp(char);
ulong __ovld __cnfn convert_ulong_sat_rtp(char);
ulong __ovld __cnfn convert_ulong_rtn(char);
ulong __ovld __cnfn convert_ulong_sat_rtn(char);
ulong __ovld __cnfn convert_ulong(char);
ulong __ovld __cnfn convert_ulong_sat(char);
ulong __ovld __cnfn convert_ulong_rte(uchar);
ulong __ovld __cnfn convert_ulong_sat_rte(uchar);
ulong __ovld __cnfn convert_ulong_rtz(uchar);
ulong __ovld __cnfn convert_ulong_sat_rtz(uchar);
ulong __ovld __cnfn convert_ulong_rtp(uchar);
ulong __ovld __cnfn convert_ulong_sat_rtp(uchar);
ulong __ovld __cnfn convert_ulong_rtn(uchar);
ulong __ovld __cnfn convert_ulong_sat_rtn(uchar);
ulong __ovld __cnfn convert_ulong(uchar);
ulong __ovld __cnfn convert_ulong_sat(uchar);
ulong __ovld __cnfn convert_ulong_rte(short);
ulong __ovld __cnfn convert_ulong_sat_rte(short);
ulong __ovld __cnfn convert_ulong_rtz(short);
ulong __ovld __cnfn convert_ulong_sat_rtz(short);
ulong __ovld __cnfn convert_ulong_rtp(short);
ulong __ovld __cnfn convert_ulong_sat_rtp(short);
ulong __ovld __cnfn convert_ulong_rtn(short);
ulong __ovld __cnfn convert_ulong_sat_rtn(short);
ulong __ovld __cnfn convert_ulong(short);
ulong __ovld __cnfn convert_ulong_sat(short);
ulong __ovld __cnfn convert_ulong_rte(ushort);
ulong __ovld __cnfn convert_ulong_sat_rte(ushort);
ulong __ovld __cnfn convert_ulong_rtz(ushort);
ulong __ovld __cnfn convert_ulong_sat_rtz(ushort);
ulong __ovld __cnfn convert_ulong_rtp(ushort);
ulong __ovld __cnfn convert_ulong_sat_rtp(ushort);
ulong __ovld __cnfn convert_ulong_rtn(ushort);
ulong __ovld __cnfn convert_ulong_sat_rtn(ushort);
ulong __ovld __cnfn convert_ulong(ushort);
ulong __ovld __cnfn convert_ulong_sat(ushort);
ulong __ovld __cnfn convert_ulong_rte(int);
ulong __ovld __cnfn convert_ulong_sat_rte(int);
ulong __ovld __cnfn convert_ulong_rtz(int);
ulong __ovld __cnfn convert_ulong_sat_rtz(int);
ulong __ovld __cnfn convert_ulong_rtp(int);
ulong __ovld __cnfn convert_ulong_sat_rtp(int);
ulong __ovld __cnfn convert_ulong_rtn(int);
ulong __ovld __cnfn convert_ulong_sat_rtn(int);
ulong __ovld __cnfn convert_ulong(int);
ulong __ovld __cnfn convert_ulong_sat(int);
ulong __ovld __cnfn convert_ulong_rte(uint);
ulong __ovld __cnfn convert_ulong_sat_rte(uint);
ulong __ovld __cnfn convert_ulong_rtz(uint);
ulong __ovld __cnfn convert_ulong_sat_rtz(uint);
ulong __ovld __cnfn convert_ulong_rtp(uint);
ulong __ovld __cnfn convert_ulong_sat_rtp(uint);
ulong __ovld __cnfn convert_ulong_rtn(uint);
ulong __ovld __cnfn convert_ulong_sat_rtn(uint);
ulong __ovld __cnfn convert_ulong(uint);
ulong __ovld __cnfn convert_ulong_sat(uint);
ulong __ovld __cnfn convert_ulong_rte(long);
ulong __ovld __cnfn convert_ulong_sat_rte(long);
ulong __ovld __cnfn convert_ulong_rtz(long);
ulong __ovld __cnfn convert_ulong_sat_rtz(long);
ulong __ovld __cnfn convert_ulong_rtp(long);
ulong __ovld __cnfn convert_ulong_sat_rtp(long);
ulong __ovld __cnfn convert_ulong_rtn(long);
ulong __ovld __cnfn convert_ulong_sat_rtn(long);
ulong __ovld __cnfn convert_ulong(long);
ulong __ovld __cnfn convert_ulong_sat(long);
ulong __ovld __cnfn convert_ulong_rte(ulong);
ulong __ovld __cnfn convert_ulong_sat_rte(ulong);
ulong __ovld __cnfn convert_ulong_rtz(ulong);
ulong __ovld __cnfn convert_ulong_sat_rtz(ulong);
ulong __ovld __cnfn convert_ulong_rtp(ulong);
ulong __ovld __cnfn convert_ulong_sat_rtp(ulong);
ulong __ovld __cnfn convert_ulong_rtn(ulong);
ulong __ovld __cnfn convert_ulong_sat_rtn(ulong);
ulong __ovld __cnfn convert_ulong(ulong);
ulong __ovld __cnfn convert_ulong_sat(ulong);
ulong __ovld __cnfn convert_ulong_rte(float);
ulong __ovld __cnfn convert_ulong_sat_rte(float);
ulong __ovld __cnfn convert_ulong_rtz(float);
ulong __ovld __cnfn convert_ulong_sat_rtz(float);
ulong __ovld __cnfn convert_ulong_rtp(float);
ulong __ovld __cnfn convert_ulong_sat_rtp(float);
ulong __ovld __cnfn convert_ulong_rtn(float);
ulong __ovld __cnfn convert_ulong_sat_rtn(float);
ulong __ovld __cnfn convert_ulong(float);
ulong __ovld __cnfn convert_ulong_sat(float);
float __ovld __cnfn convert_float_rte(char);
float __ovld __cnfn convert_float_rtz(char);
float __ovld __cnfn convert_float_rtp(char);
float __ovld __cnfn convert_float_rtn(char);
float __ovld __cnfn convert_float(char);
float __ovld __cnfn convert_float_rte(uchar);
float __ovld __cnfn convert_float_rtz(uchar);
float __ovld __cnfn convert_float_rtp(uchar);
float __ovld __cnfn convert_float_rtn(uchar);
float __ovld __cnfn convert_float(uchar);
float __ovld __cnfn convert_float_rte(short);
float __ovld __cnfn convert_float_rtz(short);
float __ovld __cnfn convert_float_rtp(short);
float __ovld __cnfn convert_float_rtn(short);
float __ovld __cnfn convert_float(short);
float __ovld __cnfn convert_float_rte(ushort);
float __ovld __cnfn convert_float_rtz(ushort);
float __ovld __cnfn convert_float_rtp(ushort);
float __ovld __cnfn convert_float_rtn(ushort);
float __ovld __cnfn convert_float(ushort);
float __ovld __cnfn convert_float_rte(int);
float __ovld __cnfn convert_float_rtz(int);
float __ovld __cnfn convert_float_rtp(int);
float __ovld __cnfn convert_float_rtn(int);
float __ovld __cnfn convert_float(int);
float __ovld __cnfn convert_float_rte(uint);
float __ovld __cnfn convert_float_rtz(uint);
float __ovld __cnfn convert_float_rtp(uint);
float __ovld __cnfn convert_float_rtn(uint);
float __ovld __cnfn convert_float(uint);
float __ovld __cnfn convert_float_rte(long);
float __ovld __cnfn convert_float_rtz(long);
float __ovld __cnfn convert_float_rtp(long);
float __ovld __cnfn convert_float_rtn(long);
float __ovld __cnfn convert_float(long);
float __ovld __cnfn convert_float_rte(ulong);
float __ovld __cnfn convert_float_rtz(ulong);
float __ovld __cnfn convert_float_rtp(ulong);
float __ovld __cnfn convert_float_rtn(ulong);
float __ovld __cnfn convert_float(ulong);
float __ovld __cnfn convert_float_rte(float);
float __ovld __cnfn convert_float_rtz(float);
float __ovld __cnfn convert_float_rtp(float);
float __ovld __cnfn convert_float_rtn(float);
float __ovld __cnfn convert_float(float);
char2 __ovld __cnfn convert_char2_rte(char2);
char2 __ovld __cnfn convert_char2_sat_rte(char2);
char2 __ovld __cnfn convert_char2_rtz(char2);
char2 __ovld __cnfn convert_char2_sat_rtz(char2);
char2 __ovld __cnfn convert_char2_rtp(char2);
char2 __ovld __cnfn convert_char2_sat_rtp(char2);
char2 __ovld __cnfn convert_char2_rtn(char2);
char2 __ovld __cnfn convert_char2_sat_rtn(char2);
char2 __ovld __cnfn convert_char2(char2);
char2 __ovld __cnfn convert_char2_sat(char2);
char2 __ovld __cnfn convert_char2_rte(uchar2);
char2 __ovld __cnfn convert_char2_sat_rte(uchar2);
char2 __ovld __cnfn convert_char2_rtz(uchar2);
char2 __ovld __cnfn convert_char2_sat_rtz(uchar2);
char2 __ovld __cnfn convert_char2_rtp(uchar2);
char2 __ovld __cnfn convert_char2_sat_rtp(uchar2);
char2 __ovld __cnfn convert_char2_rtn(uchar2);
char2 __ovld __cnfn convert_char2_sat_rtn(uchar2);
char2 __ovld __cnfn convert_char2(uchar2);
char2 __ovld __cnfn convert_char2_sat(uchar2);
char2 __ovld __cnfn convert_char2_rte(short2);
char2 __ovld __cnfn convert_char2_sat_rte(short2);
char2 __ovld __cnfn convert_char2_rtz(short2);
char2 __ovld __cnfn convert_char2_sat_rtz(short2);
char2 __ovld __cnfn convert_char2_rtp(short2);
char2 __ovld __cnfn convert_char2_sat_rtp(short2);
char2 __ovld __cnfn convert_char2_rtn(short2);
char2 __ovld __cnfn convert_char2_sat_rtn(short2);
char2 __ovld __cnfn convert_char2(short2);
char2 __ovld __cnfn convert_char2_sat(short2);
char2 __ovld __cnfn convert_char2_rte(ushort2);
char2 __ovld __cnfn convert_char2_sat_rte(ushort2);
char2 __ovld __cnfn convert_char2_rtz(ushort2);
char2 __ovld __cnfn convert_char2_sat_rtz(ushort2);
char2 __ovld __cnfn convert_char2_rtp(ushort2);
char2 __ovld __cnfn convert_char2_sat_rtp(ushort2);
char2 __ovld __cnfn convert_char2_rtn(ushort2);
char2 __ovld __cnfn convert_char2_sat_rtn(ushort2);
char2 __ovld __cnfn convert_char2(ushort2);
char2 __ovld __cnfn convert_char2_sat(ushort2);
char2 __ovld __cnfn convert_char2_rte(int2);
char2 __ovld __cnfn convert_char2_sat_rte(int2);
char2 __ovld __cnfn convert_char2_rtz(int2);
char2 __ovld __cnfn convert_char2_sat_rtz(int2);
char2 __ovld __cnfn convert_char2_rtp(int2);
char2 __ovld __cnfn convert_char2_sat_rtp(int2);
char2 __ovld __cnfn convert_char2_rtn(int2);
char2 __ovld __cnfn convert_char2_sat_rtn(int2);
char2 __ovld __cnfn convert_char2(int2);
char2 __ovld __cnfn convert_char2_sat(int2);
char2 __ovld __cnfn convert_char2_rte(uint2);
char2 __ovld __cnfn convert_char2_sat_rte(uint2);
char2 __ovld __cnfn convert_char2_rtz(uint2);
char2 __ovld __cnfn convert_char2_sat_rtz(uint2);
char2 __ovld __cnfn convert_char2_rtp(uint2);
char2 __ovld __cnfn convert_char2_sat_rtp(uint2);
char2 __ovld __cnfn convert_char2_rtn(uint2);
char2 __ovld __cnfn convert_char2_sat_rtn(uint2);
char2 __ovld __cnfn convert_char2(uint2);
char2 __ovld __cnfn convert_char2_sat(uint2);
char2 __ovld __cnfn convert_char2_rte(long2);
char2 __ovld __cnfn convert_char2_sat_rte(long2);
char2 __ovld __cnfn convert_char2_rtz(long2);
char2 __ovld __cnfn convert_char2_sat_rtz(long2);
char2 __ovld __cnfn convert_char2_rtp(long2);
char2 __ovld __cnfn convert_char2_sat_rtp(long2);
char2 __ovld __cnfn convert_char2_rtn(long2);
char2 __ovld __cnfn convert_char2_sat_rtn(long2);
char2 __ovld __cnfn convert_char2(long2);
char2 __ovld __cnfn convert_char2_sat(long2);
char2 __ovld __cnfn convert_char2_rte(ulong2);
char2 __ovld __cnfn convert_char2_sat_rte(ulong2);
char2 __ovld __cnfn convert_char2_rtz(ulong2);
char2 __ovld __cnfn convert_char2_sat_rtz(ulong2);
char2 __ovld __cnfn convert_char2_rtp(ulong2);
char2 __ovld __cnfn convert_char2_sat_rtp(ulong2);
char2 __ovld __cnfn convert_char2_rtn(ulong2);
char2 __ovld __cnfn convert_char2_sat_rtn(ulong2);
char2 __ovld __cnfn convert_char2(ulong2);
char2 __ovld __cnfn convert_char2_sat(ulong2);
char2 __ovld __cnfn convert_char2_rte(float2);
char2 __ovld __cnfn convert_char2_sat_rte(float2);
char2 __ovld __cnfn convert_char2_rtz(float2);
char2 __ovld __cnfn convert_char2_sat_rtz(float2);
char2 __ovld __cnfn convert_char2_rtp(float2);
char2 __ovld __cnfn convert_char2_sat_rtp(float2);
char2 __ovld __cnfn convert_char2_rtn(float2);
char2 __ovld __cnfn convert_char2_sat_rtn(float2);
char2 __ovld __cnfn convert_char2(float2);
char2 __ovld __cnfn convert_char2_sat(float2);
uchar2 __ovld __cnfn convert_uchar2_rte(char2);
uchar2 __ovld __cnfn convert_uchar2_sat_rte(char2);
uchar2 __ovld __cnfn convert_uchar2_rtz(char2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtz(char2);
uchar2 __ovld __cnfn convert_uchar2_rtp(char2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtp(char2);
uchar2 __ovld __cnfn convert_uchar2_rtn(char2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtn(char2);
uchar2 __ovld __cnfn convert_uchar2(char2);
uchar2 __ovld __cnfn convert_uchar2_sat(char2);
uchar2 __ovld __cnfn convert_uchar2_rte(uchar2);
uchar2 __ovld __cnfn convert_uchar2_sat_rte(uchar2);
uchar2 __ovld __cnfn convert_uchar2_rtz(uchar2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtz(uchar2);
uchar2 __ovld __cnfn convert_uchar2_rtp(uchar2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtp(uchar2);
uchar2 __ovld __cnfn convert_uchar2_rtn(uchar2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtn(uchar2);
uchar2 __ovld __cnfn convert_uchar2(uchar2);
uchar2 __ovld __cnfn convert_uchar2_sat(uchar2);
uchar2 __ovld __cnfn convert_uchar2_rte(short2);
uchar2 __ovld __cnfn convert_uchar2_sat_rte(short2);
uchar2 __ovld __cnfn convert_uchar2_rtz(short2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtz(short2);
uchar2 __ovld __cnfn convert_uchar2_rtp(short2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtp(short2);
uchar2 __ovld __cnfn convert_uchar2_rtn(short2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtn(short2);
uchar2 __ovld __cnfn convert_uchar2(short2);
uchar2 __ovld __cnfn convert_uchar2_sat(short2);
uchar2 __ovld __cnfn convert_uchar2_rte(ushort2);
uchar2 __ovld __cnfn convert_uchar2_sat_rte(ushort2);
uchar2 __ovld __cnfn convert_uchar2_rtz(ushort2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtz(ushort2);
uchar2 __ovld __cnfn convert_uchar2_rtp(ushort2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtp(ushort2);
uchar2 __ovld __cnfn convert_uchar2_rtn(ushort2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtn(ushort2);
uchar2 __ovld __cnfn convert_uchar2(ushort2);
uchar2 __ovld __cnfn convert_uchar2_sat(ushort2);
uchar2 __ovld __cnfn convert_uchar2_rte(int2);
uchar2 __ovld __cnfn convert_uchar2_sat_rte(int2);
uchar2 __ovld __cnfn convert_uchar2_rtz(int2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtz(int2);
uchar2 __ovld __cnfn convert_uchar2_rtp(int2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtp(int2);
uchar2 __ovld __cnfn convert_uchar2_rtn(int2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtn(int2);
uchar2 __ovld __cnfn convert_uchar2(int2);
uchar2 __ovld __cnfn convert_uchar2_sat(int2);
uchar2 __ovld __cnfn convert_uchar2_rte(uint2);
uchar2 __ovld __cnfn convert_uchar2_sat_rte(uint2);
uchar2 __ovld __cnfn convert_uchar2_rtz(uint2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtz(uint2);
uchar2 __ovld __cnfn convert_uchar2_rtp(uint2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtp(uint2);
uchar2 __ovld __cnfn convert_uchar2_rtn(uint2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtn(uint2);
uchar2 __ovld __cnfn convert_uchar2(uint2);
uchar2 __ovld __cnfn convert_uchar2_sat(uint2);
uchar2 __ovld __cnfn convert_uchar2_rte(long2);
uchar2 __ovld __cnfn convert_uchar2_sat_rte(long2);
uchar2 __ovld __cnfn convert_uchar2_rtz(long2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtz(long2);
uchar2 __ovld __cnfn convert_uchar2_rtp(long2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtp(long2);
uchar2 __ovld __cnfn convert_uchar2_rtn(long2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtn(long2);
uchar2 __ovld __cnfn convert_uchar2(long2);
uchar2 __ovld __cnfn convert_uchar2_sat(long2);
uchar2 __ovld __cnfn convert_uchar2_rte(ulong2);
uchar2 __ovld __cnfn convert_uchar2_sat_rte(ulong2);
uchar2 __ovld __cnfn convert_uchar2_rtz(ulong2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtz(ulong2);
uchar2 __ovld __cnfn convert_uchar2_rtp(ulong2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtp(ulong2);
uchar2 __ovld __cnfn convert_uchar2_rtn(ulong2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtn(ulong2);
uchar2 __ovld __cnfn convert_uchar2(ulong2);
uchar2 __ovld __cnfn convert_uchar2_sat(ulong2);
uchar2 __ovld __cnfn convert_uchar2_rte(float2);
uchar2 __ovld __cnfn convert_uchar2_sat_rte(float2);
uchar2 __ovld __cnfn convert_uchar2_rtz(float2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtz(float2);
uchar2 __ovld __cnfn convert_uchar2_rtp(float2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtp(float2);
uchar2 __ovld __cnfn convert_uchar2_rtn(float2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtn(float2);
uchar2 __ovld __cnfn convert_uchar2(float2);
uchar2 __ovld __cnfn convert_uchar2_sat(float2);
short2 __ovld __cnfn convert_short2_rte(char2);
short2 __ovld __cnfn convert_short2_sat_rte(char2);
short2 __ovld __cnfn convert_short2_rtz(char2);
short2 __ovld __cnfn convert_short2_sat_rtz(char2);
short2 __ovld __cnfn convert_short2_rtp(char2);
short2 __ovld __cnfn convert_short2_sat_rtp(char2);
short2 __ovld __cnfn convert_short2_rtn(char2);
short2 __ovld __cnfn convert_short2_sat_rtn(char2);
short2 __ovld __cnfn convert_short2(char2);
short2 __ovld __cnfn convert_short2_sat(char2);
short2 __ovld __cnfn convert_short2_rte(uchar2);
short2 __ovld __cnfn convert_short2_sat_rte(uchar2);
short2 __ovld __cnfn convert_short2_rtz(uchar2);
short2 __ovld __cnfn convert_short2_sat_rtz(uchar2);
short2 __ovld __cnfn convert_short2_rtp(uchar2);
short2 __ovld __cnfn convert_short2_sat_rtp(uchar2);
short2 __ovld __cnfn convert_short2_rtn(uchar2);
short2 __ovld __cnfn convert_short2_sat_rtn(uchar2);
short2 __ovld __cnfn convert_short2(uchar2);
short2 __ovld __cnfn convert_short2_sat(uchar2);
short2 __ovld __cnfn convert_short2_rte(short2);
short2 __ovld __cnfn convert_short2_sat_rte(short2);
short2 __ovld __cnfn convert_short2_rtz(short2);
short2 __ovld __cnfn convert_short2_sat_rtz(short2);
short2 __ovld __cnfn convert_short2_rtp(short2);
short2 __ovld __cnfn convert_short2_sat_rtp(short2);
short2 __ovld __cnfn convert_short2_rtn(short2);
short2 __ovld __cnfn convert_short2_sat_rtn(short2);
short2 __ovld __cnfn convert_short2(short2);
short2 __ovld __cnfn convert_short2_sat(short2);
short2 __ovld __cnfn convert_short2_rte(ushort2);
short2 __ovld __cnfn convert_short2_sat_rte(ushort2);
short2 __ovld __cnfn convert_short2_rtz(ushort2);
short2 __ovld __cnfn convert_short2_sat_rtz(ushort2);
short2 __ovld __cnfn convert_short2_rtp(ushort2);
short2 __ovld __cnfn convert_short2_sat_rtp(ushort2);
short2 __ovld __cnfn convert_short2_rtn(ushort2);
short2 __ovld __cnfn convert_short2_sat_rtn(ushort2);
short2 __ovld __cnfn convert_short2(ushort2);
short2 __ovld __cnfn convert_short2_sat(ushort2);
short2 __ovld __cnfn convert_short2_rte(int2);
short2 __ovld __cnfn convert_short2_sat_rte(int2);
short2 __ovld __cnfn convert_short2_rtz(int2);
short2 __ovld __cnfn convert_short2_sat_rtz(int2);
short2 __ovld __cnfn convert_short2_rtp(int2);
short2 __ovld __cnfn convert_short2_sat_rtp(int2);
short2 __ovld __cnfn convert_short2_rtn(int2);
short2 __ovld __cnfn convert_short2_sat_rtn(int2);
short2 __ovld __cnfn convert_short2(int2);
short2 __ovld __cnfn convert_short2_sat(int2);
short2 __ovld __cnfn convert_short2_rte(uint2);
short2 __ovld __cnfn convert_short2_sat_rte(uint2);
short2 __ovld __cnfn convert_short2_rtz(uint2);
short2 __ovld __cnfn convert_short2_sat_rtz(uint2);
short2 __ovld __cnfn convert_short2_rtp(uint2);
short2 __ovld __cnfn convert_short2_sat_rtp(uint2);
short2 __ovld __cnfn convert_short2_rtn(uint2);
short2 __ovld __cnfn convert_short2_sat_rtn(uint2);
short2 __ovld __cnfn convert_short2(uint2);
short2 __ovld __cnfn convert_short2_sat(uint2);
short2 __ovld __cnfn convert_short2_rte(long2);
short2 __ovld __cnfn convert_short2_sat_rte(long2);
short2 __ovld __cnfn convert_short2_rtz(long2);
short2 __ovld __cnfn convert_short2_sat_rtz(long2);
short2 __ovld __cnfn convert_short2_rtp(long2);
short2 __ovld __cnfn convert_short2_sat_rtp(long2);
short2 __ovld __cnfn convert_short2_rtn(long2);
short2 __ovld __cnfn convert_short2_sat_rtn(long2);
short2 __ovld __cnfn convert_short2(long2);
short2 __ovld __cnfn convert_short2_sat(long2);
short2 __ovld __cnfn convert_short2_rte(ulong2);
short2 __ovld __cnfn convert_short2_sat_rte(ulong2);
short2 __ovld __cnfn convert_short2_rtz(ulong2);
short2 __ovld __cnfn convert_short2_sat_rtz(ulong2);
short2 __ovld __cnfn convert_short2_rtp(ulong2);
short2 __ovld __cnfn convert_short2_sat_rtp(ulong2);
short2 __ovld __cnfn convert_short2_rtn(ulong2);
short2 __ovld __cnfn convert_short2_sat_rtn(ulong2);
short2 __ovld __cnfn convert_short2(ulong2);
short2 __ovld __cnfn convert_short2_sat(ulong2);
short2 __ovld __cnfn convert_short2_rte(float2);
short2 __ovld __cnfn convert_short2_sat_rte(float2);
short2 __ovld __cnfn convert_short2_rtz(float2);
short2 __ovld __cnfn convert_short2_sat_rtz(float2);
short2 __ovld __cnfn convert_short2_rtp(float2);
short2 __ovld __cnfn convert_short2_sat_rtp(float2);
short2 __ovld __cnfn convert_short2_rtn(float2);
short2 __ovld __cnfn convert_short2_sat_rtn(float2);
short2 __ovld __cnfn convert_short2(float2);
short2 __ovld __cnfn convert_short2_sat(float2);
ushort2 __ovld __cnfn convert_ushort2_rte(char2);
ushort2 __ovld __cnfn convert_ushort2_sat_rte(char2);
ushort2 __ovld __cnfn convert_ushort2_rtz(char2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtz(char2);
ushort2 __ovld __cnfn convert_ushort2_rtp(char2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtp(char2);
ushort2 __ovld __cnfn convert_ushort2_rtn(char2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtn(char2);
ushort2 __ovld __cnfn convert_ushort2(char2);
ushort2 __ovld __cnfn convert_ushort2_sat(char2);
ushort2 __ovld __cnfn convert_ushort2_rte(uchar2);
ushort2 __ovld __cnfn convert_ushort2_sat_rte(uchar2);
ushort2 __ovld __cnfn convert_ushort2_rtz(uchar2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtz(uchar2);
ushort2 __ovld __cnfn convert_ushort2_rtp(uchar2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtp(uchar2);
ushort2 __ovld __cnfn convert_ushort2_rtn(uchar2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtn(uchar2);
ushort2 __ovld __cnfn convert_ushort2(uchar2);
ushort2 __ovld __cnfn convert_ushort2_sat(uchar2);
ushort2 __ovld __cnfn convert_ushort2_rte(short2);
ushort2 __ovld __cnfn convert_ushort2_sat_rte(short2);
ushort2 __ovld __cnfn convert_ushort2_rtz(short2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtz(short2);
ushort2 __ovld __cnfn convert_ushort2_rtp(short2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtp(short2);
ushort2 __ovld __cnfn convert_ushort2_rtn(short2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtn(short2);
ushort2 __ovld __cnfn convert_ushort2(short2);
ushort2 __ovld __cnfn convert_ushort2_sat(short2);
ushort2 __ovld __cnfn convert_ushort2_rte(ushort2);
ushort2 __ovld __cnfn convert_ushort2_sat_rte(ushort2);
ushort2 __ovld __cnfn convert_ushort2_rtz(ushort2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtz(ushort2);
ushort2 __ovld __cnfn convert_ushort2_rtp(ushort2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtp(ushort2);
ushort2 __ovld __cnfn convert_ushort2_rtn(ushort2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtn(ushort2);
ushort2 __ovld __cnfn convert_ushort2(ushort2);
ushort2 __ovld __cnfn convert_ushort2_sat(ushort2);
ushort2 __ovld __cnfn convert_ushort2_rte(int2);
ushort2 __ovld __cnfn convert_ushort2_sat_rte(int2);
ushort2 __ovld __cnfn convert_ushort2_rtz(int2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtz(int2);
ushort2 __ovld __cnfn convert_ushort2_rtp(int2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtp(int2);
ushort2 __ovld __cnfn convert_ushort2_rtn(int2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtn(int2);
ushort2 __ovld __cnfn convert_ushort2(int2);
ushort2 __ovld __cnfn convert_ushort2_sat(int2);
ushort2 __ovld __cnfn convert_ushort2_rte(uint2);
ushort2 __ovld __cnfn convert_ushort2_sat_rte(uint2);
ushort2 __ovld __cnfn convert_ushort2_rtz(uint2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtz(uint2);
ushort2 __ovld __cnfn convert_ushort2_rtp(uint2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtp(uint2);
ushort2 __ovld __cnfn convert_ushort2_rtn(uint2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtn(uint2);
ushort2 __ovld __cnfn convert_ushort2(uint2);
ushort2 __ovld __cnfn convert_ushort2_sat(uint2);
ushort2 __ovld __cnfn convert_ushort2_rte(long2);
ushort2 __ovld __cnfn convert_ushort2_sat_rte(long2);
ushort2 __ovld __cnfn convert_ushort2_rtz(long2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtz(long2);
ushort2 __ovld __cnfn convert_ushort2_rtp(long2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtp(long2);
ushort2 __ovld __cnfn convert_ushort2_rtn(long2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtn(long2);
ushort2 __ovld __cnfn convert_ushort2(long2);
ushort2 __ovld __cnfn convert_ushort2_sat(long2);
ushort2 __ovld __cnfn convert_ushort2_rte(ulong2);
ushort2 __ovld __cnfn convert_ushort2_sat_rte(ulong2);
ushort2 __ovld __cnfn convert_ushort2_rtz(ulong2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtz(ulong2);
ushort2 __ovld __cnfn convert_ushort2_rtp(ulong2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtp(ulong2);
ushort2 __ovld __cnfn convert_ushort2_rtn(ulong2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtn(ulong2);
ushort2 __ovld __cnfn convert_ushort2(ulong2);
ushort2 __ovld __cnfn convert_ushort2_sat(ulong2);
ushort2 __ovld __cnfn convert_ushort2_rte(float2);
ushort2 __ovld __cnfn convert_ushort2_sat_rte(float2);
ushort2 __ovld __cnfn convert_ushort2_rtz(float2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtz(float2);
ushort2 __ovld __cnfn convert_ushort2_rtp(float2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtp(float2);
ushort2 __ovld __cnfn convert_ushort2_rtn(float2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtn(float2);
ushort2 __ovld __cnfn convert_ushort2(float2);
ushort2 __ovld __cnfn convert_ushort2_sat(float2);
int2 __ovld __cnfn convert_int2_rte(char2);
int2 __ovld __cnfn convert_int2_sat_rte(char2);
int2 __ovld __cnfn convert_int2_rtz(char2);
int2 __ovld __cnfn convert_int2_sat_rtz(char2);
int2 __ovld __cnfn convert_int2_rtp(char2);
int2 __ovld __cnfn convert_int2_sat_rtp(char2);
int2 __ovld __cnfn convert_int2_rtn(char2);
int2 __ovld __cnfn convert_int2_sat_rtn(char2);
int2 __ovld __cnfn convert_int2(char2);
int2 __ovld __cnfn convert_int2_sat(char2);
int2 __ovld __cnfn convert_int2_rte(uchar2);
int2 __ovld __cnfn convert_int2_sat_rte(uchar2);
int2 __ovld __cnfn convert_int2_rtz(uchar2);
int2 __ovld __cnfn convert_int2_sat_rtz(uchar2);
int2 __ovld __cnfn convert_int2_rtp(uchar2);
int2 __ovld __cnfn convert_int2_sat_rtp(uchar2);
int2 __ovld __cnfn convert_int2_rtn(uchar2);
int2 __ovld __cnfn convert_int2_sat_rtn(uchar2);
int2 __ovld __cnfn convert_int2(uchar2);
int2 __ovld __cnfn convert_int2_sat(uchar2);
int2 __ovld __cnfn convert_int2_rte(short2);
int2 __ovld __cnfn convert_int2_sat_rte(short2);
int2 __ovld __cnfn convert_int2_rtz(short2);
int2 __ovld __cnfn convert_int2_sat_rtz(short2);
int2 __ovld __cnfn convert_int2_rtp(short2);
int2 __ovld __cnfn convert_int2_sat_rtp(short2);
int2 __ovld __cnfn convert_int2_rtn(short2);
int2 __ovld __cnfn convert_int2_sat_rtn(short2);
int2 __ovld __cnfn convert_int2(short2);
int2 __ovld __cnfn convert_int2_sat(short2);
int2 __ovld __cnfn convert_int2_rte(ushort2);
int2 __ovld __cnfn convert_int2_sat_rte(ushort2);
int2 __ovld __cnfn convert_int2_rtz(ushort2);
int2 __ovld __cnfn convert_int2_sat_rtz(ushort2);
int2 __ovld __cnfn convert_int2_rtp(ushort2);
int2 __ovld __cnfn convert_int2_sat_rtp(ushort2);
int2 __ovld __cnfn convert_int2_rtn(ushort2);
int2 __ovld __cnfn convert_int2_sat_rtn(ushort2);
int2 __ovld __cnfn convert_int2(ushort2);
int2 __ovld __cnfn convert_int2_sat(ushort2);
int2 __ovld __cnfn convert_int2_rte(int2);
int2 __ovld __cnfn convert_int2_sat_rte(int2);
int2 __ovld __cnfn convert_int2_rtz(int2);
int2 __ovld __cnfn convert_int2_sat_rtz(int2);
int2 __ovld __cnfn convert_int2_rtp(int2);
int2 __ovld __cnfn convert_int2_sat_rtp(int2);
int2 __ovld __cnfn convert_int2_rtn(int2);
int2 __ovld __cnfn convert_int2_sat_rtn(int2);
int2 __ovld __cnfn convert_int2(int2);
int2 __ovld __cnfn convert_int2_sat(int2);
int2 __ovld __cnfn convert_int2_rte(uint2);
int2 __ovld __cnfn convert_int2_sat_rte(uint2);
int2 __ovld __cnfn convert_int2_rtz(uint2);
int2 __ovld __cnfn convert_int2_sat_rtz(uint2);
int2 __ovld __cnfn convert_int2_rtp(uint2);
int2 __ovld __cnfn convert_int2_sat_rtp(uint2);
int2 __ovld __cnfn convert_int2_rtn(uint2);
int2 __ovld __cnfn convert_int2_sat_rtn(uint2);
int2 __ovld __cnfn convert_int2(uint2);
int2 __ovld __cnfn convert_int2_sat(uint2);
int2 __ovld __cnfn convert_int2_rte(long2);
int2 __ovld __cnfn convert_int2_sat_rte(long2);
int2 __ovld __cnfn convert_int2_rtz(long2);
int2 __ovld __cnfn convert_int2_sat_rtz(long2);
int2 __ovld __cnfn convert_int2_rtp(long2);
int2 __ovld __cnfn convert_int2_sat_rtp(long2);
int2 __ovld __cnfn convert_int2_rtn(long2);
int2 __ovld __cnfn convert_int2_sat_rtn(long2);
int2 __ovld __cnfn convert_int2(long2);
int2 __ovld __cnfn convert_int2_sat(long2);
int2 __ovld __cnfn convert_int2_rte(ulong2);
int2 __ovld __cnfn convert_int2_sat_rte(ulong2);
int2 __ovld __cnfn convert_int2_rtz(ulong2);
int2 __ovld __cnfn convert_int2_sat_rtz(ulong2);
int2 __ovld __cnfn convert_int2_rtp(ulong2);
int2 __ovld __cnfn convert_int2_sat_rtp(ulong2);
int2 __ovld __cnfn convert_int2_rtn(ulong2);
int2 __ovld __cnfn convert_int2_sat_rtn(ulong2);
int2 __ovld __cnfn convert_int2(ulong2);
int2 __ovld __cnfn convert_int2_sat(ulong2);
int2 __ovld __cnfn convert_int2_rte(float2);
int2 __ovld __cnfn convert_int2_sat_rte(float2);
int2 __ovld __cnfn convert_int2_rtz(float2);
int2 __ovld __cnfn convert_int2_sat_rtz(float2);
int2 __ovld __cnfn convert_int2_rtp(float2);
int2 __ovld __cnfn convert_int2_sat_rtp(float2);
int2 __ovld __cnfn convert_int2_rtn(float2);
int2 __ovld __cnfn convert_int2_sat_rtn(float2);
int2 __ovld __cnfn convert_int2(float2);
int2 __ovld __cnfn convert_int2_sat(float2);
uint2 __ovld __cnfn convert_uint2_rte(char2);
uint2 __ovld __cnfn convert_uint2_sat_rte(char2);
uint2 __ovld __cnfn convert_uint2_rtz(char2);
uint2 __ovld __cnfn convert_uint2_sat_rtz(char2);
uint2 __ovld __cnfn convert_uint2_rtp(char2);
uint2 __ovld __cnfn convert_uint2_sat_rtp(char2);
uint2 __ovld __cnfn convert_uint2_rtn(char2);
uint2 __ovld __cnfn convert_uint2_sat_rtn(char2);
uint2 __ovld __cnfn convert_uint2(char2);
uint2 __ovld __cnfn convert_uint2_sat(char2);
uint2 __ovld __cnfn convert_uint2_rte(uchar2);
uint2 __ovld __cnfn convert_uint2_sat_rte(uchar2);
uint2 __ovld __cnfn convert_uint2_rtz(uchar2);
uint2 __ovld __cnfn convert_uint2_sat_rtz(uchar2);
uint2 __ovld __cnfn convert_uint2_rtp(uchar2);
uint2 __ovld __cnfn convert_uint2_sat_rtp(uchar2);
uint2 __ovld __cnfn convert_uint2_rtn(uchar2);
uint2 __ovld __cnfn convert_uint2_sat_rtn(uchar2);
uint2 __ovld __cnfn convert_uint2(uchar2);
uint2 __ovld __cnfn convert_uint2_sat(uchar2);
uint2 __ovld __cnfn convert_uint2_rte(short2);
uint2 __ovld __cnfn convert_uint2_sat_rte(short2);
uint2 __ovld __cnfn convert_uint2_rtz(short2);
uint2 __ovld __cnfn convert_uint2_sat_rtz(short2);
uint2 __ovld __cnfn convert_uint2_rtp(short2);
uint2 __ovld __cnfn convert_uint2_sat_rtp(short2);
uint2 __ovld __cnfn convert_uint2_rtn(short2);
uint2 __ovld __cnfn convert_uint2_sat_rtn(short2);
uint2 __ovld __cnfn convert_uint2(short2);
uint2 __ovld __cnfn convert_uint2_sat(short2);
uint2 __ovld __cnfn convert_uint2_rte(ushort2);
uint2 __ovld __cnfn convert_uint2_sat_rte(ushort2);
uint2 __ovld __cnfn convert_uint2_rtz(ushort2);
uint2 __ovld __cnfn convert_uint2_sat_rtz(ushort2);
uint2 __ovld __cnfn convert_uint2_rtp(ushort2);
uint2 __ovld __cnfn convert_uint2_sat_rtp(ushort2);
uint2 __ovld __cnfn convert_uint2_rtn(ushort2);
uint2 __ovld __cnfn convert_uint2_sat_rtn(ushort2);
uint2 __ovld __cnfn convert_uint2(ushort2);
uint2 __ovld __cnfn convert_uint2_sat(ushort2);
uint2 __ovld __cnfn convert_uint2_rte(int2);
uint2 __ovld __cnfn convert_uint2_sat_rte(int2);
uint2 __ovld __cnfn convert_uint2_rtz(int2);
uint2 __ovld __cnfn convert_uint2_sat_rtz(int2);
uint2 __ovld __cnfn convert_uint2_rtp(int2);
uint2 __ovld __cnfn convert_uint2_sat_rtp(int2);
uint2 __ovld __cnfn convert_uint2_rtn(int2);
uint2 __ovld __cnfn convert_uint2_sat_rtn(int2);
uint2 __ovld __cnfn convert_uint2(int2);
uint2 __ovld __cnfn convert_uint2_sat(int2);
uint2 __ovld __cnfn convert_uint2_rte(uint2);
uint2 __ovld __cnfn convert_uint2_sat_rte(uint2);
uint2 __ovld __cnfn convert_uint2_rtz(uint2);
uint2 __ovld __cnfn convert_uint2_sat_rtz(uint2);
uint2 __ovld __cnfn convert_uint2_rtp(uint2);
uint2 __ovld __cnfn convert_uint2_sat_rtp(uint2);
uint2 __ovld __cnfn convert_uint2_rtn(uint2);
uint2 __ovld __cnfn convert_uint2_sat_rtn(uint2);
uint2 __ovld __cnfn convert_uint2(uint2);
uint2 __ovld __cnfn convert_uint2_sat(uint2);
uint2 __ovld __cnfn convert_uint2_rte(long2);
uint2 __ovld __cnfn convert_uint2_sat_rte(long2);
uint2 __ovld __cnfn convert_uint2_rtz(long2);
uint2 __ovld __cnfn convert_uint2_sat_rtz(long2);
uint2 __ovld __cnfn convert_uint2_rtp(long2);
uint2 __ovld __cnfn convert_uint2_sat_rtp(long2);
uint2 __ovld __cnfn convert_uint2_rtn(long2);
uint2 __ovld __cnfn convert_uint2_sat_rtn(long2);
uint2 __ovld __cnfn convert_uint2(long2);
uint2 __ovld __cnfn convert_uint2_sat(long2);
uint2 __ovld __cnfn convert_uint2_rte(ulong2);
uint2 __ovld __cnfn convert_uint2_sat_rte(ulong2);
uint2 __ovld __cnfn convert_uint2_rtz(ulong2);
uint2 __ovld __cnfn convert_uint2_sat_rtz(ulong2);
uint2 __ovld __cnfn convert_uint2_rtp(ulong2);
uint2 __ovld __cnfn convert_uint2_sat_rtp(ulong2);
uint2 __ovld __cnfn convert_uint2_rtn(ulong2);
uint2 __ovld __cnfn convert_uint2_sat_rtn(ulong2);
uint2 __ovld __cnfn convert_uint2(ulong2);
uint2 __ovld __cnfn convert_uint2_sat(ulong2);
uint2 __ovld __cnfn convert_uint2_rte(float2);
uint2 __ovld __cnfn convert_uint2_sat_rte(float2);
uint2 __ovld __cnfn convert_uint2_rtz(float2);
uint2 __ovld __cnfn convert_uint2_sat_rtz(float2);
uint2 __ovld __cnfn convert_uint2_rtp(float2);
uint2 __ovld __cnfn convert_uint2_sat_rtp(float2);
uint2 __ovld __cnfn convert_uint2_rtn(float2);
uint2 __ovld __cnfn convert_uint2_sat_rtn(float2);
uint2 __ovld __cnfn convert_uint2(float2);
uint2 __ovld __cnfn convert_uint2_sat(float2);
long2 __ovld __cnfn convert_long2_rte(char2);
long2 __ovld __cnfn convert_long2_sat_rte(char2);
long2 __ovld __cnfn convert_long2_rtz(char2);
long2 __ovld __cnfn convert_long2_sat_rtz(char2);
long2 __ovld __cnfn convert_long2_rtp(char2);
long2 __ovld __cnfn convert_long2_sat_rtp(char2);
long2 __ovld __cnfn convert_long2_rtn(char2);
long2 __ovld __cnfn convert_long2_sat_rtn(char2);
long2 __ovld __cnfn convert_long2(char2);
long2 __ovld __cnfn convert_long2_sat(char2);
long2 __ovld __cnfn convert_long2_rte(uchar2);
long2 __ovld __cnfn convert_long2_sat_rte(uchar2);
long2 __ovld __cnfn convert_long2_rtz(uchar2);
long2 __ovld __cnfn convert_long2_sat_rtz(uchar2);
long2 __ovld __cnfn convert_long2_rtp(uchar2);
long2 __ovld __cnfn convert_long2_sat_rtp(uchar2);
long2 __ovld __cnfn convert_long2_rtn(uchar2);
long2 __ovld __cnfn convert_long2_sat_rtn(uchar2);
long2 __ovld __cnfn convert_long2(uchar2);
long2 __ovld __cnfn convert_long2_sat(uchar2);
long2 __ovld __cnfn convert_long2_rte(short2);
long2 __ovld __cnfn convert_long2_sat_rte(short2);
long2 __ovld __cnfn convert_long2_rtz(short2);
long2 __ovld __cnfn convert_long2_sat_rtz(short2);
long2 __ovld __cnfn convert_long2_rtp(short2);
long2 __ovld __cnfn convert_long2_sat_rtp(short2);
long2 __ovld __cnfn convert_long2_rtn(short2);
long2 __ovld __cnfn convert_long2_sat_rtn(short2);
long2 __ovld __cnfn convert_long2(short2);
long2 __ovld __cnfn convert_long2_sat(short2);
long2 __ovld __cnfn convert_long2_rte(ushort2);
long2 __ovld __cnfn convert_long2_sat_rte(ushort2);
long2 __ovld __cnfn convert_long2_rtz(ushort2);
long2 __ovld __cnfn convert_long2_sat_rtz(ushort2);
long2 __ovld __cnfn convert_long2_rtp(ushort2);
long2 __ovld __cnfn convert_long2_sat_rtp(ushort2);
long2 __ovld __cnfn convert_long2_rtn(ushort2);
long2 __ovld __cnfn convert_long2_sat_rtn(ushort2);
long2 __ovld __cnfn convert_long2(ushort2);
long2 __ovld __cnfn convert_long2_sat(ushort2);
long2 __ovld __cnfn convert_long2_rte(int2);
long2 __ovld __cnfn convert_long2_sat_rte(int2);
long2 __ovld __cnfn convert_long2_rtz(int2);
long2 __ovld __cnfn convert_long2_sat_rtz(int2);
long2 __ovld __cnfn convert_long2_rtp(int2);
long2 __ovld __cnfn convert_long2_sat_rtp(int2);
long2 __ovld __cnfn convert_long2_rtn(int2);
long2 __ovld __cnfn convert_long2_sat_rtn(int2);
long2 __ovld __cnfn convert_long2(int2);
long2 __ovld __cnfn convert_long2_sat(int2);
long2 __ovld __cnfn convert_long2_rte(uint2);
long2 __ovld __cnfn convert_long2_sat_rte(uint2);
long2 __ovld __cnfn convert_long2_rtz(uint2);
long2 __ovld __cnfn convert_long2_sat_rtz(uint2);
long2 __ovld __cnfn convert_long2_rtp(uint2);
long2 __ovld __cnfn convert_long2_sat_rtp(uint2);
long2 __ovld __cnfn convert_long2_rtn(uint2);
long2 __ovld __cnfn convert_long2_sat_rtn(uint2);
long2 __ovld __cnfn convert_long2(uint2);
long2 __ovld __cnfn convert_long2_sat(uint2);
long2 __ovld __cnfn convert_long2_rte(long2);
long2 __ovld __cnfn convert_long2_sat_rte(long2);
long2 __ovld __cnfn convert_long2_rtz(long2);
long2 __ovld __cnfn convert_long2_sat_rtz(long2);
long2 __ovld __cnfn convert_long2_rtp(long2);
long2 __ovld __cnfn convert_long2_sat_rtp(long2);
long2 __ovld __cnfn convert_long2_rtn(long2);
long2 __ovld __cnfn convert_long2_sat_rtn(long2);
long2 __ovld __cnfn convert_long2(long2);
long2 __ovld __cnfn convert_long2_sat(long2);
long2 __ovld __cnfn convert_long2_rte(ulong2);
long2 __ovld __cnfn convert_long2_sat_rte(ulong2);
long2 __ovld __cnfn convert_long2_rtz(ulong2);
long2 __ovld __cnfn convert_long2_sat_rtz(ulong2);
long2 __ovld __cnfn convert_long2_rtp(ulong2);
long2 __ovld __cnfn convert_long2_sat_rtp(ulong2);
long2 __ovld __cnfn convert_long2_rtn(ulong2);
long2 __ovld __cnfn convert_long2_sat_rtn(ulong2);
long2 __ovld __cnfn convert_long2(ulong2);
long2 __ovld __cnfn convert_long2_sat(ulong2);
long2 __ovld __cnfn convert_long2_rte(float2);
long2 __ovld __cnfn convert_long2_sat_rte(float2);
long2 __ovld __cnfn convert_long2_rtz(float2);
long2 __ovld __cnfn convert_long2_sat_rtz(float2);
long2 __ovld __cnfn convert_long2_rtp(float2);
long2 __ovld __cnfn convert_long2_sat_rtp(float2);
long2 __ovld __cnfn convert_long2_rtn(float2);
long2 __ovld __cnfn convert_long2_sat_rtn(float2);
long2 __ovld __cnfn convert_long2(float2);
long2 __ovld __cnfn convert_long2_sat(float2);
ulong2 __ovld __cnfn convert_ulong2_rte(char2);
ulong2 __ovld __cnfn convert_ulong2_sat_rte(char2);
ulong2 __ovld __cnfn convert_ulong2_rtz(char2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtz(char2);
ulong2 __ovld __cnfn convert_ulong2_rtp(char2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtp(char2);
ulong2 __ovld __cnfn convert_ulong2_rtn(char2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtn(char2);
ulong2 __ovld __cnfn convert_ulong2(char2);
ulong2 __ovld __cnfn convert_ulong2_sat(char2);
ulong2 __ovld __cnfn convert_ulong2_rte(uchar2);
ulong2 __ovld __cnfn convert_ulong2_sat_rte(uchar2);
ulong2 __ovld __cnfn convert_ulong2_rtz(uchar2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtz(uchar2);
ulong2 __ovld __cnfn convert_ulong2_rtp(uchar2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtp(uchar2);
ulong2 __ovld __cnfn convert_ulong2_rtn(uchar2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtn(uchar2);
ulong2 __ovld __cnfn convert_ulong2(uchar2);
ulong2 __ovld __cnfn convert_ulong2_sat(uchar2);
ulong2 __ovld __cnfn convert_ulong2_rte(short2);
ulong2 __ovld __cnfn convert_ulong2_sat_rte(short2);
ulong2 __ovld __cnfn convert_ulong2_rtz(short2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtz(short2);
ulong2 __ovld __cnfn convert_ulong2_rtp(short2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtp(short2);
ulong2 __ovld __cnfn convert_ulong2_rtn(short2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtn(short2);
ulong2 __ovld __cnfn convert_ulong2(short2);
ulong2 __ovld __cnfn convert_ulong2_sat(short2);
ulong2 __ovld __cnfn convert_ulong2_rte(ushort2);
ulong2 __ovld __cnfn convert_ulong2_sat_rte(ushort2);
ulong2 __ovld __cnfn convert_ulong2_rtz(ushort2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtz(ushort2);
ulong2 __ovld __cnfn convert_ulong2_rtp(ushort2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtp(ushort2);
ulong2 __ovld __cnfn convert_ulong2_rtn(ushort2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtn(ushort2);
ulong2 __ovld __cnfn convert_ulong2(ushort2);
ulong2 __ovld __cnfn convert_ulong2_sat(ushort2);
ulong2 __ovld __cnfn convert_ulong2_rte(int2);
ulong2 __ovld __cnfn convert_ulong2_sat_rte(int2);
ulong2 __ovld __cnfn convert_ulong2_rtz(int2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtz(int2);
ulong2 __ovld __cnfn convert_ulong2_rtp(int2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtp(int2);
ulong2 __ovld __cnfn convert_ulong2_rtn(int2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtn(int2);
ulong2 __ovld __cnfn convert_ulong2(int2);
ulong2 __ovld __cnfn convert_ulong2_sat(int2);
ulong2 __ovld __cnfn convert_ulong2_rte(uint2);
ulong2 __ovld __cnfn convert_ulong2_sat_rte(uint2);
ulong2 __ovld __cnfn convert_ulong2_rtz(uint2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtz(uint2);
ulong2 __ovld __cnfn convert_ulong2_rtp(uint2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtp(uint2);
ulong2 __ovld __cnfn convert_ulong2_rtn(uint2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtn(uint2);
ulong2 __ovld __cnfn convert_ulong2(uint2);
ulong2 __ovld __cnfn convert_ulong2_sat(uint2);
ulong2 __ovld __cnfn convert_ulong2_rte(long2);
ulong2 __ovld __cnfn convert_ulong2_sat_rte(long2);
ulong2 __ovld __cnfn convert_ulong2_rtz(long2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtz(long2);
ulong2 __ovld __cnfn convert_ulong2_rtp(long2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtp(long2);
ulong2 __ovld __cnfn convert_ulong2_rtn(long2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtn(long2);
ulong2 __ovld __cnfn convert_ulong2(long2);
ulong2 __ovld __cnfn convert_ulong2_sat(long2);
ulong2 __ovld __cnfn convert_ulong2_rte(ulong2);
ulong2 __ovld __cnfn convert_ulong2_sat_rte(ulong2);
ulong2 __ovld __cnfn convert_ulong2_rtz(ulong2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtz(ulong2);
ulong2 __ovld __cnfn convert_ulong2_rtp(ulong2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtp(ulong2);
ulong2 __ovld __cnfn convert_ulong2_rtn(ulong2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtn(ulong2);
ulong2 __ovld __cnfn convert_ulong2(ulong2);
ulong2 __ovld __cnfn convert_ulong2_sat(ulong2);
ulong2 __ovld __cnfn convert_ulong2_rte(float2);
ulong2 __ovld __cnfn convert_ulong2_sat_rte(float2);
ulong2 __ovld __cnfn convert_ulong2_rtz(float2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtz(float2);
ulong2 __ovld __cnfn convert_ulong2_rtp(float2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtp(float2);
ulong2 __ovld __cnfn convert_ulong2_rtn(float2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtn(float2);
ulong2 __ovld __cnfn convert_ulong2(float2);
ulong2 __ovld __cnfn convert_ulong2_sat(float2);
float2 __ovld __cnfn convert_float2_rte(char2);
float2 __ovld __cnfn convert_float2_rtz(char2);
float2 __ovld __cnfn convert_float2_rtp(char2);
float2 __ovld __cnfn convert_float2_rtn(char2);
float2 __ovld __cnfn convert_float2(char2);
float2 __ovld __cnfn convert_float2_rte(uchar2);
float2 __ovld __cnfn convert_float2_rtz(uchar2);
float2 __ovld __cnfn convert_float2_rtp(uchar2);
float2 __ovld __cnfn convert_float2_rtn(uchar2);
float2 __ovld __cnfn convert_float2(uchar2);
float2 __ovld __cnfn convert_float2_rte(short2);
float2 __ovld __cnfn convert_float2_rtz(short2);
float2 __ovld __cnfn convert_float2_rtp(short2);
float2 __ovld __cnfn convert_float2_rtn(short2);
float2 __ovld __cnfn convert_float2(short2);
float2 __ovld __cnfn convert_float2_rte(ushort2);
float2 __ovld __cnfn convert_float2_rtz(ushort2);
float2 __ovld __cnfn convert_float2_rtp(ushort2);
float2 __ovld __cnfn convert_float2_rtn(ushort2);
float2 __ovld __cnfn convert_float2(ushort2);
float2 __ovld __cnfn convert_float2_rte(int2);
float2 __ovld __cnfn convert_float2_rtz(int2);
float2 __ovld __cnfn convert_float2_rtp(int2);
float2 __ovld __cnfn convert_float2_rtn(int2);
float2 __ovld __cnfn convert_float2(int2);
float2 __ovld __cnfn convert_float2_rte(uint2);
float2 __ovld __cnfn convert_float2_rtz(uint2);
float2 __ovld __cnfn convert_float2_rtp(uint2);
float2 __ovld __cnfn convert_float2_rtn(uint2);
float2 __ovld __cnfn convert_float2(uint2);
float2 __ovld __cnfn convert_float2_rte(long2);
float2 __ovld __cnfn convert_float2_rtz(long2);
float2 __ovld __cnfn convert_float2_rtp(long2);
float2 __ovld __cnfn convert_float2_rtn(long2);
float2 __ovld __cnfn convert_float2(long2);
float2 __ovld __cnfn convert_float2_rte(ulong2);
float2 __ovld __cnfn convert_float2_rtz(ulong2);
float2 __ovld __cnfn convert_float2_rtp(ulong2);
float2 __ovld __cnfn convert_float2_rtn(ulong2);
float2 __ovld __cnfn convert_float2(ulong2);
float2 __ovld __cnfn convert_float2_rte(float2);
float2 __ovld __cnfn convert_float2_rtz(float2);
float2 __ovld __cnfn convert_float2_rtp(float2);
float2 __ovld __cnfn convert_float2_rtn(float2);
float2 __ovld __cnfn convert_float2(float2);
char3 __ovld __cnfn convert_char3_rte(char3);
char3 __ovld __cnfn convert_char3_sat_rte(char3);
char3 __ovld __cnfn convert_char3_rtz(char3);
char3 __ovld __cnfn convert_char3_sat_rtz(char3);
char3 __ovld __cnfn convert_char3_rtp(char3);
char3 __ovld __cnfn convert_char3_sat_rtp(char3);
char3 __ovld __cnfn convert_char3_rtn(char3);
char3 __ovld __cnfn convert_char3_sat_rtn(char3);
char3 __ovld __cnfn convert_char3(char3);
char3 __ovld __cnfn convert_char3_sat(char3);
char3 __ovld __cnfn convert_char3_rte(uchar3);
char3 __ovld __cnfn convert_char3_sat_rte(uchar3);
char3 __ovld __cnfn convert_char3_rtz(uchar3);
char3 __ovld __cnfn convert_char3_sat_rtz(uchar3);
char3 __ovld __cnfn convert_char3_rtp(uchar3);
char3 __ovld __cnfn convert_char3_sat_rtp(uchar3);
char3 __ovld __cnfn convert_char3_rtn(uchar3);
char3 __ovld __cnfn convert_char3_sat_rtn(uchar3);
char3 __ovld __cnfn convert_char3(uchar3);
char3 __ovld __cnfn convert_char3_sat(uchar3);
char3 __ovld __cnfn convert_char3_rte(short3);
char3 __ovld __cnfn convert_char3_sat_rte(short3);
char3 __ovld __cnfn convert_char3_rtz(short3);
char3 __ovld __cnfn convert_char3_sat_rtz(short3);
char3 __ovld __cnfn convert_char3_rtp(short3);
char3 __ovld __cnfn convert_char3_sat_rtp(short3);
char3 __ovld __cnfn convert_char3_rtn(short3);
char3 __ovld __cnfn convert_char3_sat_rtn(short3);
char3 __ovld __cnfn convert_char3(short3);
char3 __ovld __cnfn convert_char3_sat(short3);
char3 __ovld __cnfn convert_char3_rte(ushort3);
char3 __ovld __cnfn convert_char3_sat_rte(ushort3);
char3 __ovld __cnfn convert_char3_rtz(ushort3);
char3 __ovld __cnfn convert_char3_sat_rtz(ushort3);
char3 __ovld __cnfn convert_char3_rtp(ushort3);
char3 __ovld __cnfn convert_char3_sat_rtp(ushort3);
char3 __ovld __cnfn convert_char3_rtn(ushort3);
char3 __ovld __cnfn convert_char3_sat_rtn(ushort3);
char3 __ovld __cnfn convert_char3(ushort3);
char3 __ovld __cnfn convert_char3_sat(ushort3);
char3 __ovld __cnfn convert_char3_rte(int3);
char3 __ovld __cnfn convert_char3_sat_rte(int3);
char3 __ovld __cnfn convert_char3_rtz(int3);
char3 __ovld __cnfn convert_char3_sat_rtz(int3);
char3 __ovld __cnfn convert_char3_rtp(int3);
char3 __ovld __cnfn convert_char3_sat_rtp(int3);
char3 __ovld __cnfn convert_char3_rtn(int3);
char3 __ovld __cnfn convert_char3_sat_rtn(int3);
char3 __ovld __cnfn convert_char3(int3);
char3 __ovld __cnfn convert_char3_sat(int3);
char3 __ovld __cnfn convert_char3_rte(uint3);
char3 __ovld __cnfn convert_char3_sat_rte(uint3);
char3 __ovld __cnfn convert_char3_rtz(uint3);
char3 __ovld __cnfn convert_char3_sat_rtz(uint3);
char3 __ovld __cnfn convert_char3_rtp(uint3);
char3 __ovld __cnfn convert_char3_sat_rtp(uint3);
char3 __ovld __cnfn convert_char3_rtn(uint3);
char3 __ovld __cnfn convert_char3_sat_rtn(uint3);
char3 __ovld __cnfn convert_char3(uint3);
char3 __ovld __cnfn convert_char3_sat(uint3);
char3 __ovld __cnfn convert_char3_rte(long3);
char3 __ovld __cnfn convert_char3_sat_rte(long3);
char3 __ovld __cnfn convert_char3_rtz(long3);
char3 __ovld __cnfn convert_char3_sat_rtz(long3);
char3 __ovld __cnfn convert_char3_rtp(long3);
char3 __ovld __cnfn convert_char3_sat_rtp(long3);
char3 __ovld __cnfn convert_char3_rtn(long3);
char3 __ovld __cnfn convert_char3_sat_rtn(long3);
char3 __ovld __cnfn convert_char3(long3);
char3 __ovld __cnfn convert_char3_sat(long3);
char3 __ovld __cnfn convert_char3_rte(ulong3);
char3 __ovld __cnfn convert_char3_sat_rte(ulong3);
char3 __ovld __cnfn convert_char3_rtz(ulong3);
char3 __ovld __cnfn convert_char3_sat_rtz(ulong3);
char3 __ovld __cnfn convert_char3_rtp(ulong3);
char3 __ovld __cnfn convert_char3_sat_rtp(ulong3);
char3 __ovld __cnfn convert_char3_rtn(ulong3);
char3 __ovld __cnfn convert_char3_sat_rtn(ulong3);
char3 __ovld __cnfn convert_char3(ulong3);
char3 __ovld __cnfn convert_char3_sat(ulong3);
char3 __ovld __cnfn convert_char3_rte(float3);
char3 __ovld __cnfn convert_char3_sat_rte(float3);
char3 __ovld __cnfn convert_char3_rtz(float3);
char3 __ovld __cnfn convert_char3_sat_rtz(float3);
char3 __ovld __cnfn convert_char3_rtp(float3);
char3 __ovld __cnfn convert_char3_sat_rtp(float3);
char3 __ovld __cnfn convert_char3_rtn(float3);
char3 __ovld __cnfn convert_char3_sat_rtn(float3);
char3 __ovld __cnfn convert_char3(float3);
char3 __ovld __cnfn convert_char3_sat(float3);
uchar3 __ovld __cnfn convert_uchar3_rte(char3);
uchar3 __ovld __cnfn convert_uchar3_sat_rte(char3);
uchar3 __ovld __cnfn convert_uchar3_rtz(char3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtz(char3);
uchar3 __ovld __cnfn convert_uchar3_rtp(char3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtp(char3);
uchar3 __ovld __cnfn convert_uchar3_rtn(char3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtn(char3);
uchar3 __ovld __cnfn convert_uchar3(char3);
uchar3 __ovld __cnfn convert_uchar3_sat(char3);
uchar3 __ovld __cnfn convert_uchar3_rte(uchar3);
uchar3 __ovld __cnfn convert_uchar3_sat_rte(uchar3);
uchar3 __ovld __cnfn convert_uchar3_rtz(uchar3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtz(uchar3);
uchar3 __ovld __cnfn convert_uchar3_rtp(uchar3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtp(uchar3);
uchar3 __ovld __cnfn convert_uchar3_rtn(uchar3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtn(uchar3);
uchar3 __ovld __cnfn convert_uchar3(uchar3);
uchar3 __ovld __cnfn convert_uchar3_sat(uchar3);
uchar3 __ovld __cnfn convert_uchar3_rte(short3);
uchar3 __ovld __cnfn convert_uchar3_sat_rte(short3);
uchar3 __ovld __cnfn convert_uchar3_rtz(short3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtz(short3);
uchar3 __ovld __cnfn convert_uchar3_rtp(short3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtp(short3);
uchar3 __ovld __cnfn convert_uchar3_rtn(short3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtn(short3);
uchar3 __ovld __cnfn convert_uchar3(short3);
uchar3 __ovld __cnfn convert_uchar3_sat(short3);
uchar3 __ovld __cnfn convert_uchar3_rte(ushort3);
uchar3 __ovld __cnfn convert_uchar3_sat_rte(ushort3);
uchar3 __ovld __cnfn convert_uchar3_rtz(ushort3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtz(ushort3);
uchar3 __ovld __cnfn convert_uchar3_rtp(ushort3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtp(ushort3);
uchar3 __ovld __cnfn convert_uchar3_rtn(ushort3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtn(ushort3);
uchar3 __ovld __cnfn convert_uchar3(ushort3);
uchar3 __ovld __cnfn convert_uchar3_sat(ushort3);
uchar3 __ovld __cnfn convert_uchar3_rte(int3);
uchar3 __ovld __cnfn convert_uchar3_sat_rte(int3);
uchar3 __ovld __cnfn convert_uchar3_rtz(int3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtz(int3);
uchar3 __ovld __cnfn convert_uchar3_rtp(int3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtp(int3);
uchar3 __ovld __cnfn convert_uchar3_rtn(int3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtn(int3);
uchar3 __ovld __cnfn convert_uchar3(int3);
uchar3 __ovld __cnfn convert_uchar3_sat(int3);
uchar3 __ovld __cnfn convert_uchar3_rte(uint3);
uchar3 __ovld __cnfn convert_uchar3_sat_rte(uint3);
uchar3 __ovld __cnfn convert_uchar3_rtz(uint3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtz(uint3);
uchar3 __ovld __cnfn convert_uchar3_rtp(uint3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtp(uint3);
uchar3 __ovld __cnfn convert_uchar3_rtn(uint3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtn(uint3);
uchar3 __ovld __cnfn convert_uchar3(uint3);
uchar3 __ovld __cnfn convert_uchar3_sat(uint3);
uchar3 __ovld __cnfn convert_uchar3_rte(long3);
uchar3 __ovld __cnfn convert_uchar3_sat_rte(long3);
uchar3 __ovld __cnfn convert_uchar3_rtz(long3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtz(long3);
uchar3 __ovld __cnfn convert_uchar3_rtp(long3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtp(long3);
uchar3 __ovld __cnfn convert_uchar3_rtn(long3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtn(long3);
uchar3 __ovld __cnfn convert_uchar3(long3);
uchar3 __ovld __cnfn convert_uchar3_sat(long3);
uchar3 __ovld __cnfn convert_uchar3_rte(ulong3);
uchar3 __ovld __cnfn convert_uchar3_sat_rte(ulong3);
uchar3 __ovld __cnfn convert_uchar3_rtz(ulong3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtz(ulong3);
uchar3 __ovld __cnfn convert_uchar3_rtp(ulong3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtp(ulong3);
uchar3 __ovld __cnfn convert_uchar3_rtn(ulong3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtn(ulong3);
uchar3 __ovld __cnfn convert_uchar3(ulong3);
uchar3 __ovld __cnfn convert_uchar3_sat(ulong3);
uchar3 __ovld __cnfn convert_uchar3_rte(float3);
uchar3 __ovld __cnfn convert_uchar3_sat_rte(float3);
uchar3 __ovld __cnfn convert_uchar3_rtz(float3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtz(float3);
uchar3 __ovld __cnfn convert_uchar3_rtp(float3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtp(float3);
uchar3 __ovld __cnfn convert_uchar3_rtn(float3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtn(float3);
uchar3 __ovld __cnfn convert_uchar3(float3);
uchar3 __ovld __cnfn convert_uchar3_sat(float3);
short3 __ovld __cnfn convert_short3_rte(char3);
short3 __ovld __cnfn convert_short3_sat_rte(char3);
short3 __ovld __cnfn convert_short3_rtz(char3);
short3 __ovld __cnfn convert_short3_sat_rtz(char3);
short3 __ovld __cnfn convert_short3_rtp(char3);
short3 __ovld __cnfn convert_short3_sat_rtp(char3);
short3 __ovld __cnfn convert_short3_rtn(char3);
short3 __ovld __cnfn convert_short3_sat_rtn(char3);
short3 __ovld __cnfn convert_short3(char3);
short3 __ovld __cnfn convert_short3_sat(char3);
short3 __ovld __cnfn convert_short3_rte(uchar3);
short3 __ovld __cnfn convert_short3_sat_rte(uchar3);
short3 __ovld __cnfn convert_short3_rtz(uchar3);
short3 __ovld __cnfn convert_short3_sat_rtz(uchar3);
short3 __ovld __cnfn convert_short3_rtp(uchar3);
short3 __ovld __cnfn convert_short3_sat_rtp(uchar3);
short3 __ovld __cnfn convert_short3_rtn(uchar3);
short3 __ovld __cnfn convert_short3_sat_rtn(uchar3);
short3 __ovld __cnfn convert_short3(uchar3);
short3 __ovld __cnfn convert_short3_sat(uchar3);
short3 __ovld __cnfn convert_short3_rte(short3);
short3 __ovld __cnfn convert_short3_sat_rte(short3);
short3 __ovld __cnfn convert_short3_rtz(short3);
short3 __ovld __cnfn convert_short3_sat_rtz(short3);
short3 __ovld __cnfn convert_short3_rtp(short3);
short3 __ovld __cnfn convert_short3_sat_rtp(short3);
short3 __ovld __cnfn convert_short3_rtn(short3);
short3 __ovld __cnfn convert_short3_sat_rtn(short3);
short3 __ovld __cnfn convert_short3(short3);
short3 __ovld __cnfn convert_short3_sat(short3);
short3 __ovld __cnfn convert_short3_rte(ushort3);
short3 __ovld __cnfn convert_short3_sat_rte(ushort3);
short3 __ovld __cnfn convert_short3_rtz(ushort3);
short3 __ovld __cnfn convert_short3_sat_rtz(ushort3);
short3 __ovld __cnfn convert_short3_rtp(ushort3);
short3 __ovld __cnfn convert_short3_sat_rtp(ushort3);
short3 __ovld __cnfn convert_short3_rtn(ushort3);
short3 __ovld __cnfn convert_short3_sat_rtn(ushort3);
short3 __ovld __cnfn convert_short3(ushort3);
short3 __ovld __cnfn convert_short3_sat(ushort3);
short3 __ovld __cnfn convert_short3_rte(int3);
short3 __ovld __cnfn convert_short3_sat_rte(int3);
short3 __ovld __cnfn convert_short3_rtz(int3);
short3 __ovld __cnfn convert_short3_sat_rtz(int3);
short3 __ovld __cnfn convert_short3_rtp(int3);
short3 __ovld __cnfn convert_short3_sat_rtp(int3);
short3 __ovld __cnfn convert_short3_rtn(int3);
short3 __ovld __cnfn convert_short3_sat_rtn(int3);
short3 __ovld __cnfn convert_short3(int3);
short3 __ovld __cnfn convert_short3_sat(int3);
short3 __ovld __cnfn convert_short3_rte(uint3);
short3 __ovld __cnfn convert_short3_sat_rte(uint3);
short3 __ovld __cnfn convert_short3_rtz(uint3);
short3 __ovld __cnfn convert_short3_sat_rtz(uint3);
short3 __ovld __cnfn convert_short3_rtp(uint3);
short3 __ovld __cnfn convert_short3_sat_rtp(uint3);
short3 __ovld __cnfn convert_short3_rtn(uint3);
short3 __ovld __cnfn convert_short3_sat_rtn(uint3);
short3 __ovld __cnfn convert_short3(uint3);
short3 __ovld __cnfn convert_short3_sat(uint3);
short3 __ovld __cnfn convert_short3_rte(long3);
short3 __ovld __cnfn convert_short3_sat_rte(long3);
short3 __ovld __cnfn convert_short3_rtz(long3);
short3 __ovld __cnfn convert_short3_sat_rtz(long3);
short3 __ovld __cnfn convert_short3_rtp(long3);
short3 __ovld __cnfn convert_short3_sat_rtp(long3);
short3 __ovld __cnfn convert_short3_rtn(long3);
short3 __ovld __cnfn convert_short3_sat_rtn(long3);
short3 __ovld __cnfn convert_short3(long3);
short3 __ovld __cnfn convert_short3_sat(long3);
short3 __ovld __cnfn convert_short3_rte(ulong3);
short3 __ovld __cnfn convert_short3_sat_rte(ulong3);
short3 __ovld __cnfn convert_short3_rtz(ulong3);
short3 __ovld __cnfn convert_short3_sat_rtz(ulong3);
short3 __ovld __cnfn convert_short3_rtp(ulong3);
short3 __ovld __cnfn convert_short3_sat_rtp(ulong3);
short3 __ovld __cnfn convert_short3_rtn(ulong3);
short3 __ovld __cnfn convert_short3_sat_rtn(ulong3);
short3 __ovld __cnfn convert_short3(ulong3);
short3 __ovld __cnfn convert_short3_sat(ulong3);
short3 __ovld __cnfn convert_short3_rte(float3);
short3 __ovld __cnfn convert_short3_sat_rte(float3);
short3 __ovld __cnfn convert_short3_rtz(float3);
short3 __ovld __cnfn convert_short3_sat_rtz(float3);
short3 __ovld __cnfn convert_short3_rtp(float3);
short3 __ovld __cnfn convert_short3_sat_rtp(float3);
short3 __ovld __cnfn convert_short3_rtn(float3);
short3 __ovld __cnfn convert_short3_sat_rtn(float3);
short3 __ovld __cnfn convert_short3(float3);
short3 __ovld __cnfn convert_short3_sat(float3);
ushort3 __ovld __cnfn convert_ushort3_rte(char3);
ushort3 __ovld __cnfn convert_ushort3_sat_rte(char3);
ushort3 __ovld __cnfn convert_ushort3_rtz(char3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtz(char3);
ushort3 __ovld __cnfn convert_ushort3_rtp(char3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtp(char3);
ushort3 __ovld __cnfn convert_ushort3_rtn(char3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtn(char3);
ushort3 __ovld __cnfn convert_ushort3(char3);
ushort3 __ovld __cnfn convert_ushort3_sat(char3);
ushort3 __ovld __cnfn convert_ushort3_rte(uchar3);
ushort3 __ovld __cnfn convert_ushort3_sat_rte(uchar3);
ushort3 __ovld __cnfn convert_ushort3_rtz(uchar3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtz(uchar3);
ushort3 __ovld __cnfn convert_ushort3_rtp(uchar3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtp(uchar3);
ushort3 __ovld __cnfn convert_ushort3_rtn(uchar3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtn(uchar3);
ushort3 __ovld __cnfn convert_ushort3(uchar3);
ushort3 __ovld __cnfn convert_ushort3_sat(uchar3);
ushort3 __ovld __cnfn convert_ushort3_rte(short3);
ushort3 __ovld __cnfn convert_ushort3_sat_rte(short3);
ushort3 __ovld __cnfn convert_ushort3_rtz(short3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtz(short3);
ushort3 __ovld __cnfn convert_ushort3_rtp(short3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtp(short3);
ushort3 __ovld __cnfn convert_ushort3_rtn(short3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtn(short3);
ushort3 __ovld __cnfn convert_ushort3(short3);
ushort3 __ovld __cnfn convert_ushort3_sat(short3);
ushort3 __ovld __cnfn convert_ushort3_rte(ushort3);
ushort3 __ovld __cnfn convert_ushort3_sat_rte(ushort3);
ushort3 __ovld __cnfn convert_ushort3_rtz(ushort3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtz(ushort3);
ushort3 __ovld __cnfn convert_ushort3_rtp(ushort3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtp(ushort3);
ushort3 __ovld __cnfn convert_ushort3_rtn(ushort3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtn(ushort3);
ushort3 __ovld __cnfn convert_ushort3(ushort3);
ushort3 __ovld __cnfn convert_ushort3_sat(ushort3);
ushort3 __ovld __cnfn convert_ushort3_rte(int3);
ushort3 __ovld __cnfn convert_ushort3_sat_rte(int3);
ushort3 __ovld __cnfn convert_ushort3_rtz(int3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtz(int3);
ushort3 __ovld __cnfn convert_ushort3_rtp(int3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtp(int3);
ushort3 __ovld __cnfn convert_ushort3_rtn(int3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtn(int3);
ushort3 __ovld __cnfn convert_ushort3(int3);
ushort3 __ovld __cnfn convert_ushort3_sat(int3);
ushort3 __ovld __cnfn convert_ushort3_rte(uint3);
ushort3 __ovld __cnfn convert_ushort3_sat_rte(uint3);
ushort3 __ovld __cnfn convert_ushort3_rtz(uint3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtz(uint3);
ushort3 __ovld __cnfn convert_ushort3_rtp(uint3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtp(uint3);
ushort3 __ovld __cnfn convert_ushort3_rtn(uint3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtn(uint3);
ushort3 __ovld __cnfn convert_ushort3(uint3);
ushort3 __ovld __cnfn convert_ushort3_sat(uint3);
ushort3 __ovld __cnfn convert_ushort3_rte(long3);
ushort3 __ovld __cnfn convert_ushort3_sat_rte(long3);
ushort3 __ovld __cnfn convert_ushort3_rtz(long3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtz(long3);
ushort3 __ovld __cnfn convert_ushort3_rtp(long3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtp(long3);
ushort3 __ovld __cnfn convert_ushort3_rtn(long3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtn(long3);
ushort3 __ovld __cnfn convert_ushort3(long3);
ushort3 __ovld __cnfn convert_ushort3_sat(long3);
ushort3 __ovld __cnfn convert_ushort3_rte(ulong3);
ushort3 __ovld __cnfn convert_ushort3_sat_rte(ulong3);
ushort3 __ovld __cnfn convert_ushort3_rtz(ulong3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtz(ulong3);
ushort3 __ovld __cnfn convert_ushort3_rtp(ulong3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtp(ulong3);
ushort3 __ovld __cnfn convert_ushort3_rtn(ulong3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtn(ulong3);
ushort3 __ovld __cnfn convert_ushort3(ulong3);
ushort3 __ovld __cnfn convert_ushort3_sat(ulong3);
ushort3 __ovld __cnfn convert_ushort3_rte(float3);
ushort3 __ovld __cnfn convert_ushort3_sat_rte(float3);
ushort3 __ovld __cnfn convert_ushort3_rtz(float3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtz(float3);
ushort3 __ovld __cnfn convert_ushort3_rtp(float3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtp(float3);
ushort3 __ovld __cnfn convert_ushort3_rtn(float3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtn(float3);
ushort3 __ovld __cnfn convert_ushort3(float3);
ushort3 __ovld __cnfn convert_ushort3_sat(float3);
int3 __ovld __cnfn convert_int3_rte(char3);
int3 __ovld __cnfn convert_int3_sat_rte(char3);
int3 __ovld __cnfn convert_int3_rtz(char3);
int3 __ovld __cnfn convert_int3_sat_rtz(char3);
int3 __ovld __cnfn convert_int3_rtp(char3);
int3 __ovld __cnfn convert_int3_sat_rtp(char3);
int3 __ovld __cnfn convert_int3_rtn(char3);
int3 __ovld __cnfn convert_int3_sat_rtn(char3);
int3 __ovld __cnfn convert_int3(char3);
int3 __ovld __cnfn convert_int3_sat(char3);
int3 __ovld __cnfn convert_int3_rte(uchar3);
int3 __ovld __cnfn convert_int3_sat_rte(uchar3);
int3 __ovld __cnfn convert_int3_rtz(uchar3);
int3 __ovld __cnfn convert_int3_sat_rtz(uchar3);
int3 __ovld __cnfn convert_int3_rtp(uchar3);
int3 __ovld __cnfn convert_int3_sat_rtp(uchar3);
int3 __ovld __cnfn convert_int3_rtn(uchar3);
int3 __ovld __cnfn convert_int3_sat_rtn(uchar3);
int3 __ovld __cnfn convert_int3(uchar3);
int3 __ovld __cnfn convert_int3_sat(uchar3);
int3 __ovld __cnfn convert_int3_rte(short3);
int3 __ovld __cnfn convert_int3_sat_rte(short3);
int3 __ovld __cnfn convert_int3_rtz(short3);
int3 __ovld __cnfn convert_int3_sat_rtz(short3);
int3 __ovld __cnfn convert_int3_rtp(short3);
int3 __ovld __cnfn convert_int3_sat_rtp(short3);
int3 __ovld __cnfn convert_int3_rtn(short3);
int3 __ovld __cnfn convert_int3_sat_rtn(short3);
int3 __ovld __cnfn convert_int3(short3);
int3 __ovld __cnfn convert_int3_sat(short3);
int3 __ovld __cnfn convert_int3_rte(ushort3);
int3 __ovld __cnfn convert_int3_sat_rte(ushort3);
int3 __ovld __cnfn convert_int3_rtz(ushort3);
int3 __ovld __cnfn convert_int3_sat_rtz(ushort3);
int3 __ovld __cnfn convert_int3_rtp(ushort3);
int3 __ovld __cnfn convert_int3_sat_rtp(ushort3);
int3 __ovld __cnfn convert_int3_rtn(ushort3);
int3 __ovld __cnfn convert_int3_sat_rtn(ushort3);
int3 __ovld __cnfn convert_int3(ushort3);
int3 __ovld __cnfn convert_int3_sat(ushort3);
int3 __ovld __cnfn convert_int3_rte(int3);
int3 __ovld __cnfn convert_int3_sat_rte(int3);
int3 __ovld __cnfn convert_int3_rtz(int3);
int3 __ovld __cnfn convert_int3_sat_rtz(int3);
int3 __ovld __cnfn convert_int3_rtp(int3);
int3 __ovld __cnfn convert_int3_sat_rtp(int3);
int3 __ovld __cnfn convert_int3_rtn(int3);
int3 __ovld __cnfn convert_int3_sat_rtn(int3);
int3 __ovld __cnfn convert_int3(int3);
int3 __ovld __cnfn convert_int3_sat(int3);
int3 __ovld __cnfn convert_int3_rte(uint3);
int3 __ovld __cnfn convert_int3_sat_rte(uint3);
int3 __ovld __cnfn convert_int3_rtz(uint3);
int3 __ovld __cnfn convert_int3_sat_rtz(uint3);
int3 __ovld __cnfn convert_int3_rtp(uint3);
int3 __ovld __cnfn convert_int3_sat_rtp(uint3);
int3 __ovld __cnfn convert_int3_rtn(uint3);
int3 __ovld __cnfn convert_int3_sat_rtn(uint3);
int3 __ovld __cnfn convert_int3(uint3);
int3 __ovld __cnfn convert_int3_sat(uint3);
int3 __ovld __cnfn convert_int3_rte(long3);
int3 __ovld __cnfn convert_int3_sat_rte(long3);
int3 __ovld __cnfn convert_int3_rtz(long3);
int3 __ovld __cnfn convert_int3_sat_rtz(long3);
int3 __ovld __cnfn convert_int3_rtp(long3);
int3 __ovld __cnfn convert_int3_sat_rtp(long3);
int3 __ovld __cnfn convert_int3_rtn(long3);
int3 __ovld __cnfn convert_int3_sat_rtn(long3);
int3 __ovld __cnfn convert_int3(long3);
int3 __ovld __cnfn convert_int3_sat(long3);
int3 __ovld __cnfn convert_int3_rte(ulong3);
int3 __ovld __cnfn convert_int3_sat_rte(ulong3);
int3 __ovld __cnfn convert_int3_rtz(ulong3);
int3 __ovld __cnfn convert_int3_sat_rtz(ulong3);
int3 __ovld __cnfn convert_int3_rtp(ulong3);
int3 __ovld __cnfn convert_int3_sat_rtp(ulong3);
int3 __ovld __cnfn convert_int3_rtn(ulong3);
int3 __ovld __cnfn convert_int3_sat_rtn(ulong3);
int3 __ovld __cnfn convert_int3(ulong3);
int3 __ovld __cnfn convert_int3_sat(ulong3);
int3 __ovld __cnfn convert_int3_rte(float3);
int3 __ovld __cnfn convert_int3_sat_rte(float3);
int3 __ovld __cnfn convert_int3_rtz(float3);
int3 __ovld __cnfn convert_int3_sat_rtz(float3);
int3 __ovld __cnfn convert_int3_rtp(float3);
int3 __ovld __cnfn convert_int3_sat_rtp(float3);
int3 __ovld __cnfn convert_int3_rtn(float3);
int3 __ovld __cnfn convert_int3_sat_rtn(float3);
int3 __ovld __cnfn convert_int3(float3);
int3 __ovld __cnfn convert_int3_sat(float3);
uint3 __ovld __cnfn convert_uint3_rte(char3);
uint3 __ovld __cnfn convert_uint3_sat_rte(char3);
uint3 __ovld __cnfn convert_uint3_rtz(char3);
uint3 __ovld __cnfn convert_uint3_sat_rtz(char3);
uint3 __ovld __cnfn convert_uint3_rtp(char3);
uint3 __ovld __cnfn convert_uint3_sat_rtp(char3);
uint3 __ovld __cnfn convert_uint3_rtn(char3);
uint3 __ovld __cnfn convert_uint3_sat_rtn(char3);
uint3 __ovld __cnfn convert_uint3(char3);
uint3 __ovld __cnfn convert_uint3_sat(char3);
uint3 __ovld __cnfn convert_uint3_rte(uchar3);
uint3 __ovld __cnfn convert_uint3_sat_rte(uchar3);
uint3 __ovld __cnfn convert_uint3_rtz(uchar3);
uint3 __ovld __cnfn convert_uint3_sat_rtz(uchar3);
uint3 __ovld __cnfn convert_uint3_rtp(uchar3);
uint3 __ovld __cnfn convert_uint3_sat_rtp(uchar3);
uint3 __ovld __cnfn convert_uint3_rtn(uchar3);
uint3 __ovld __cnfn convert_uint3_sat_rtn(uchar3);
uint3 __ovld __cnfn convert_uint3(uchar3);
uint3 __ovld __cnfn convert_uint3_sat(uchar3);
uint3 __ovld __cnfn convert_uint3_rte(short3);
uint3 __ovld __cnfn convert_uint3_sat_rte(short3);
uint3 __ovld __cnfn convert_uint3_rtz(short3);
uint3 __ovld __cnfn convert_uint3_sat_rtz(short3);
uint3 __ovld __cnfn convert_uint3_rtp(short3);
uint3 __ovld __cnfn convert_uint3_sat_rtp(short3);
uint3 __ovld __cnfn convert_uint3_rtn(short3);
uint3 __ovld __cnfn convert_uint3_sat_rtn(short3);
uint3 __ovld __cnfn convert_uint3(short3);
uint3 __ovld __cnfn convert_uint3_sat(short3);
uint3 __ovld __cnfn convert_uint3_rte(ushort3);
uint3 __ovld __cnfn convert_uint3_sat_rte(ushort3);
uint3 __ovld __cnfn convert_uint3_rtz(ushort3);
uint3 __ovld __cnfn convert_uint3_sat_rtz(ushort3);
uint3 __ovld __cnfn convert_uint3_rtp(ushort3);
uint3 __ovld __cnfn convert_uint3_sat_rtp(ushort3);
uint3 __ovld __cnfn convert_uint3_rtn(ushort3);
uint3 __ovld __cnfn convert_uint3_sat_rtn(ushort3);
uint3 __ovld __cnfn convert_uint3(ushort3);
uint3 __ovld __cnfn convert_uint3_sat(ushort3);
uint3 __ovld __cnfn convert_uint3_rte(int3);
uint3 __ovld __cnfn convert_uint3_sat_rte(int3);
uint3 __ovld __cnfn convert_uint3_rtz(int3);
uint3 __ovld __cnfn convert_uint3_sat_rtz(int3);
uint3 __ovld __cnfn convert_uint3_rtp(int3);
uint3 __ovld __cnfn convert_uint3_sat_rtp(int3);
uint3 __ovld __cnfn convert_uint3_rtn(int3);
uint3 __ovld __cnfn convert_uint3_sat_rtn(int3);
uint3 __ovld __cnfn convert_uint3(int3);
uint3 __ovld __cnfn convert_uint3_sat(int3);
uint3 __ovld __cnfn convert_uint3_rte(uint3);
uint3 __ovld __cnfn convert_uint3_sat_rte(uint3);
uint3 __ovld __cnfn convert_uint3_rtz(uint3);
uint3 __ovld __cnfn convert_uint3_sat_rtz(uint3);
uint3 __ovld __cnfn convert_uint3_rtp(uint3);
uint3 __ovld __cnfn convert_uint3_sat_rtp(uint3);
uint3 __ovld __cnfn convert_uint3_rtn(uint3);
uint3 __ovld __cnfn convert_uint3_sat_rtn(uint3);
uint3 __ovld __cnfn convert_uint3(uint3);
uint3 __ovld __cnfn convert_uint3_sat(uint3);
uint3 __ovld __cnfn convert_uint3_rte(long3);
uint3 __ovld __cnfn convert_uint3_sat_rte(long3);
uint3 __ovld __cnfn convert_uint3_rtz(long3);
uint3 __ovld __cnfn convert_uint3_sat_rtz(long3);
uint3 __ovld __cnfn convert_uint3_rtp(long3);
uint3 __ovld __cnfn convert_uint3_sat_rtp(long3);
uint3 __ovld __cnfn convert_uint3_rtn(long3);
uint3 __ovld __cnfn convert_uint3_sat_rtn(long3);
uint3 __ovld __cnfn convert_uint3(long3);
uint3 __ovld __cnfn convert_uint3_sat(long3);
uint3 __ovld __cnfn convert_uint3_rte(ulong3);
uint3 __ovld __cnfn convert_uint3_sat_rte(ulong3);
uint3 __ovld __cnfn convert_uint3_rtz(ulong3);
uint3 __ovld __cnfn convert_uint3_sat_rtz(ulong3);
uint3 __ovld __cnfn convert_uint3_rtp(ulong3);
uint3 __ovld __cnfn convert_uint3_sat_rtp(ulong3);
uint3 __ovld __cnfn convert_uint3_rtn(ulong3);
uint3 __ovld __cnfn convert_uint3_sat_rtn(ulong3);
uint3 __ovld __cnfn convert_uint3(ulong3);
uint3 __ovld __cnfn convert_uint3_sat(ulong3);
uint3 __ovld __cnfn convert_uint3_rte(float3);
uint3 __ovld __cnfn convert_uint3_sat_rte(float3);
uint3 __ovld __cnfn convert_uint3_rtz(float3);
uint3 __ovld __cnfn convert_uint3_sat_rtz(float3);
uint3 __ovld __cnfn convert_uint3_rtp(float3);
uint3 __ovld __cnfn convert_uint3_sat_rtp(float3);
uint3 __ovld __cnfn convert_uint3_rtn(float3);
uint3 __ovld __cnfn convert_uint3_sat_rtn(float3);
uint3 __ovld __cnfn convert_uint3(float3);
uint3 __ovld __cnfn convert_uint3_sat(float3);
long3 __ovld __cnfn convert_long3_rte(char3);
long3 __ovld __cnfn convert_long3_sat_rte(char3);
long3 __ovld __cnfn convert_long3_rtz(char3);
long3 __ovld __cnfn convert_long3_sat_rtz(char3);
long3 __ovld __cnfn convert_long3_rtp(char3);
long3 __ovld __cnfn convert_long3_sat_rtp(char3);
long3 __ovld __cnfn convert_long3_rtn(char3);
long3 __ovld __cnfn convert_long3_sat_rtn(char3);
long3 __ovld __cnfn convert_long3(char3);
long3 __ovld __cnfn convert_long3_sat(char3);
long3 __ovld __cnfn convert_long3_rte(uchar3);
long3 __ovld __cnfn convert_long3_sat_rte(uchar3);
long3 __ovld __cnfn convert_long3_rtz(uchar3);
long3 __ovld __cnfn convert_long3_sat_rtz(uchar3);
long3 __ovld __cnfn convert_long3_rtp(uchar3);
long3 __ovld __cnfn convert_long3_sat_rtp(uchar3);
long3 __ovld __cnfn convert_long3_rtn(uchar3);
long3 __ovld __cnfn convert_long3_sat_rtn(uchar3);
long3 __ovld __cnfn convert_long3(uchar3);
long3 __ovld __cnfn convert_long3_sat(uchar3);
long3 __ovld __cnfn convert_long3_rte(short3);
long3 __ovld __cnfn convert_long3_sat_rte(short3);
long3 __ovld __cnfn convert_long3_rtz(short3);
long3 __ovld __cnfn convert_long3_sat_rtz(short3);
long3 __ovld __cnfn convert_long3_rtp(short3);
long3 __ovld __cnfn convert_long3_sat_rtp(short3);
long3 __ovld __cnfn convert_long3_rtn(short3);
long3 __ovld __cnfn convert_long3_sat_rtn(short3);
long3 __ovld __cnfn convert_long3(short3);
long3 __ovld __cnfn convert_long3_sat(short3);
long3 __ovld __cnfn convert_long3_rte(ushort3);
long3 __ovld __cnfn convert_long3_sat_rte(ushort3);
long3 __ovld __cnfn convert_long3_rtz(ushort3);
long3 __ovld __cnfn convert_long3_sat_rtz(ushort3);
long3 __ovld __cnfn convert_long3_rtp(ushort3);
long3 __ovld __cnfn convert_long3_sat_rtp(ushort3);
long3 __ovld __cnfn convert_long3_rtn(ushort3);
long3 __ovld __cnfn convert_long3_sat_rtn(ushort3);
long3 __ovld __cnfn convert_long3(ushort3);
long3 __ovld __cnfn convert_long3_sat(ushort3);
long3 __ovld __cnfn convert_long3_rte(int3);
long3 __ovld __cnfn convert_long3_sat_rte(int3);
long3 __ovld __cnfn convert_long3_rtz(int3);
long3 __ovld __cnfn convert_long3_sat_rtz(int3);
long3 __ovld __cnfn convert_long3_rtp(int3);
long3 __ovld __cnfn convert_long3_sat_rtp(int3);
long3 __ovld __cnfn convert_long3_rtn(int3);
long3 __ovld __cnfn convert_long3_sat_rtn(int3);
long3 __ovld __cnfn convert_long3(int3);
long3 __ovld __cnfn convert_long3_sat(int3);
long3 __ovld __cnfn convert_long3_rte(uint3);
long3 __ovld __cnfn convert_long3_sat_rte(uint3);
long3 __ovld __cnfn convert_long3_rtz(uint3);
long3 __ovld __cnfn convert_long3_sat_rtz(uint3);
long3 __ovld __cnfn convert_long3_rtp(uint3);
long3 __ovld __cnfn convert_long3_sat_rtp(uint3);
long3 __ovld __cnfn convert_long3_rtn(uint3);
long3 __ovld __cnfn convert_long3_sat_rtn(uint3);
long3 __ovld __cnfn convert_long3(uint3);
long3 __ovld __cnfn convert_long3_sat(uint3);
long3 __ovld __cnfn convert_long3_rte(long3);
long3 __ovld __cnfn convert_long3_sat_rte(long3);
long3 __ovld __cnfn convert_long3_rtz(long3);
long3 __ovld __cnfn convert_long3_sat_rtz(long3);
long3 __ovld __cnfn convert_long3_rtp(long3);
long3 __ovld __cnfn convert_long3_sat_rtp(long3);
long3 __ovld __cnfn convert_long3_rtn(long3);
long3 __ovld __cnfn convert_long3_sat_rtn(long3);
long3 __ovld __cnfn convert_long3(long3);
long3 __ovld __cnfn convert_long3_sat(long3);
long3 __ovld __cnfn convert_long3_rte(ulong3);
long3 __ovld __cnfn convert_long3_sat_rte(ulong3);
long3 __ovld __cnfn convert_long3_rtz(ulong3);
long3 __ovld __cnfn convert_long3_sat_rtz(ulong3);
long3 __ovld __cnfn convert_long3_rtp(ulong3);
long3 __ovld __cnfn convert_long3_sat_rtp(ulong3);
long3 __ovld __cnfn convert_long3_rtn(ulong3);
long3 __ovld __cnfn convert_long3_sat_rtn(ulong3);
long3 __ovld __cnfn convert_long3(ulong3);
long3 __ovld __cnfn convert_long3_sat(ulong3);
long3 __ovld __cnfn convert_long3_rte(float3);
long3 __ovld __cnfn convert_long3_sat_rte(float3);
long3 __ovld __cnfn convert_long3_rtz(float3);
long3 __ovld __cnfn convert_long3_sat_rtz(float3);
long3 __ovld __cnfn convert_long3_rtp(float3);
long3 __ovld __cnfn convert_long3_sat_rtp(float3);
long3 __ovld __cnfn convert_long3_rtn(float3);
long3 __ovld __cnfn convert_long3_sat_rtn(float3);
long3 __ovld __cnfn convert_long3(float3);
long3 __ovld __cnfn convert_long3_sat(float3);
ulong3 __ovld __cnfn convert_ulong3_rte(char3);
ulong3 __ovld __cnfn convert_ulong3_sat_rte(char3);
ulong3 __ovld __cnfn convert_ulong3_rtz(char3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtz(char3);
ulong3 __ovld __cnfn convert_ulong3_rtp(char3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtp(char3);
ulong3 __ovld __cnfn convert_ulong3_rtn(char3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtn(char3);
ulong3 __ovld __cnfn convert_ulong3(char3);
ulong3 __ovld __cnfn convert_ulong3_sat(char3);
ulong3 __ovld __cnfn convert_ulong3_rte(uchar3);
ulong3 __ovld __cnfn convert_ulong3_sat_rte(uchar3);
ulong3 __ovld __cnfn convert_ulong3_rtz(uchar3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtz(uchar3);
ulong3 __ovld __cnfn convert_ulong3_rtp(uchar3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtp(uchar3);
ulong3 __ovld __cnfn convert_ulong3_rtn(uchar3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtn(uchar3);
ulong3 __ovld __cnfn convert_ulong3(uchar3);
ulong3 __ovld __cnfn convert_ulong3_sat(uchar3);
ulong3 __ovld __cnfn convert_ulong3_rte(short3);
ulong3 __ovld __cnfn convert_ulong3_sat_rte(short3);
ulong3 __ovld __cnfn convert_ulong3_rtz(short3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtz(short3);
ulong3 __ovld __cnfn convert_ulong3_rtp(short3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtp(short3);
ulong3 __ovld __cnfn convert_ulong3_rtn(short3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtn(short3);
ulong3 __ovld __cnfn convert_ulong3(short3);
ulong3 __ovld __cnfn convert_ulong3_sat(short3);
ulong3 __ovld __cnfn convert_ulong3_rte(ushort3);
ulong3 __ovld __cnfn convert_ulong3_sat_rte(ushort3);
ulong3 __ovld __cnfn convert_ulong3_rtz(ushort3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtz(ushort3);
ulong3 __ovld __cnfn convert_ulong3_rtp(ushort3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtp(ushort3);
ulong3 __ovld __cnfn convert_ulong3_rtn(ushort3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtn(ushort3);
ulong3 __ovld __cnfn convert_ulong3(ushort3);
ulong3 __ovld __cnfn convert_ulong3_sat(ushort3);
ulong3 __ovld __cnfn convert_ulong3_rte(int3);
ulong3 __ovld __cnfn convert_ulong3_sat_rte(int3);
ulong3 __ovld __cnfn convert_ulong3_rtz(int3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtz(int3);
ulong3 __ovld __cnfn convert_ulong3_rtp(int3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtp(int3);
ulong3 __ovld __cnfn convert_ulong3_rtn(int3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtn(int3);
ulong3 __ovld __cnfn convert_ulong3(int3);
ulong3 __ovld __cnfn convert_ulong3_sat(int3);
ulong3 __ovld __cnfn convert_ulong3_rte(uint3);
ulong3 __ovld __cnfn convert_ulong3_sat_rte(uint3);
ulong3 __ovld __cnfn convert_ulong3_rtz(uint3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtz(uint3);
ulong3 __ovld __cnfn convert_ulong3_rtp(uint3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtp(uint3);
ulong3 __ovld __cnfn convert_ulong3_rtn(uint3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtn(uint3);
ulong3 __ovld __cnfn convert_ulong3(uint3);
ulong3 __ovld __cnfn convert_ulong3_sat(uint3);
ulong3 __ovld __cnfn convert_ulong3_rte(long3);
ulong3 __ovld __cnfn convert_ulong3_sat_rte(long3);
ulong3 __ovld __cnfn convert_ulong3_rtz(long3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtz(long3);
ulong3 __ovld __cnfn convert_ulong3_rtp(long3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtp(long3);
ulong3 __ovld __cnfn convert_ulong3_rtn(long3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtn(long3);
ulong3 __ovld __cnfn convert_ulong3(long3);
ulong3 __ovld __cnfn convert_ulong3_sat(long3);
ulong3 __ovld __cnfn convert_ulong3_rte(ulong3);
ulong3 __ovld __cnfn convert_ulong3_sat_rte(ulong3);
ulong3 __ovld __cnfn convert_ulong3_rtz(ulong3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtz(ulong3);
ulong3 __ovld __cnfn convert_ulong3_rtp(ulong3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtp(ulong3);
ulong3 __ovld __cnfn convert_ulong3_rtn(ulong3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtn(ulong3);
ulong3 __ovld __cnfn convert_ulong3(ulong3);
ulong3 __ovld __cnfn convert_ulong3_sat(ulong3);
ulong3 __ovld __cnfn convert_ulong3_rte(float3);
ulong3 __ovld __cnfn convert_ulong3_sat_rte(float3);
ulong3 __ovld __cnfn convert_ulong3_rtz(float3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtz(float3);
ulong3 __ovld __cnfn convert_ulong3_rtp(float3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtp(float3);
ulong3 __ovld __cnfn convert_ulong3_rtn(float3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtn(float3);
ulong3 __ovld __cnfn convert_ulong3(float3);
ulong3 __ovld __cnfn convert_ulong3_sat(float3);
float3 __ovld __cnfn convert_float3_rte(char3);
float3 __ovld __cnfn convert_float3_rtz(char3);
float3 __ovld __cnfn convert_float3_rtp(char3);
float3 __ovld __cnfn convert_float3_rtn(char3);
float3 __ovld __cnfn convert_float3(char3);
float3 __ovld __cnfn convert_float3_rte(uchar3);
float3 __ovld __cnfn convert_float3_rtz(uchar3);
float3 __ovld __cnfn convert_float3_rtp(uchar3);
float3 __ovld __cnfn convert_float3_rtn(uchar3);
float3 __ovld __cnfn convert_float3(uchar3);
float3 __ovld __cnfn convert_float3_rte(short3);
float3 __ovld __cnfn convert_float3_rtz(short3);
float3 __ovld __cnfn convert_float3_rtp(short3);
float3 __ovld __cnfn convert_float3_rtn(short3);
float3 __ovld __cnfn convert_float3(short3);
float3 __ovld __cnfn convert_float3_rte(ushort3);
float3 __ovld __cnfn convert_float3_rtz(ushort3);
float3 __ovld __cnfn convert_float3_rtp(ushort3);
float3 __ovld __cnfn convert_float3_rtn(ushort3);
float3 __ovld __cnfn convert_float3(ushort3);
float3 __ovld __cnfn convert_float3_rte(int3);
float3 __ovld __cnfn convert_float3_rtz(int3);
float3 __ovld __cnfn convert_float3_rtp(int3);
float3 __ovld __cnfn convert_float3_rtn(int3);
float3 __ovld __cnfn convert_float3(int3);
float3 __ovld __cnfn convert_float3_rte(uint3);
float3 __ovld __cnfn convert_float3_rtz(uint3);
float3 __ovld __cnfn convert_float3_rtp(uint3);
float3 __ovld __cnfn convert_float3_rtn(uint3);
float3 __ovld __cnfn convert_float3(uint3);
float3 __ovld __cnfn convert_float3_rte(long3);
float3 __ovld __cnfn convert_float3_rtz(long3);
float3 __ovld __cnfn convert_float3_rtp(long3);
float3 __ovld __cnfn convert_float3_rtn(long3);
float3 __ovld __cnfn convert_float3(long3);
float3 __ovld __cnfn convert_float3_rte(ulong3);
float3 __ovld __cnfn convert_float3_rtz(ulong3);
float3 __ovld __cnfn convert_float3_rtp(ulong3);
float3 __ovld __cnfn convert_float3_rtn(ulong3);
float3 __ovld __cnfn convert_float3(ulong3);
float3 __ovld __cnfn convert_float3_rte(float3);
float3 __ovld __cnfn convert_float3_rtz(float3);
float3 __ovld __cnfn convert_float3_rtp(float3);
float3 __ovld __cnfn convert_float3_rtn(float3);
float3 __ovld __cnfn convert_float3(float3);
char4 __ovld __cnfn convert_char4_rte(char4);
char4 __ovld __cnfn convert_char4_sat_rte(char4);
char4 __ovld __cnfn convert_char4_rtz(char4);
char4 __ovld __cnfn convert_char4_sat_rtz(char4);
char4 __ovld __cnfn convert_char4_rtp(char4);
char4 __ovld __cnfn convert_char4_sat_rtp(char4);
char4 __ovld __cnfn convert_char4_rtn(char4);
char4 __ovld __cnfn convert_char4_sat_rtn(char4);
char4 __ovld __cnfn convert_char4(char4);
char4 __ovld __cnfn convert_char4_sat(char4);
char4 __ovld __cnfn convert_char4_rte(uchar4);
char4 __ovld __cnfn convert_char4_sat_rte(uchar4);
char4 __ovld __cnfn convert_char4_rtz(uchar4);
char4 __ovld __cnfn convert_char4_sat_rtz(uchar4);
char4 __ovld __cnfn convert_char4_rtp(uchar4);
char4 __ovld __cnfn convert_char4_sat_rtp(uchar4);
char4 __ovld __cnfn convert_char4_rtn(uchar4);
char4 __ovld __cnfn convert_char4_sat_rtn(uchar4);
char4 __ovld __cnfn convert_char4(uchar4);
char4 __ovld __cnfn convert_char4_sat(uchar4);
char4 __ovld __cnfn convert_char4_rte(short4);
char4 __ovld __cnfn convert_char4_sat_rte(short4);
char4 __ovld __cnfn convert_char4_rtz(short4);
char4 __ovld __cnfn convert_char4_sat_rtz(short4);
char4 __ovld __cnfn convert_char4_rtp(short4);
char4 __ovld __cnfn convert_char4_sat_rtp(short4);
char4 __ovld __cnfn convert_char4_rtn(short4);
char4 __ovld __cnfn convert_char4_sat_rtn(short4);
char4 __ovld __cnfn convert_char4(short4);
char4 __ovld __cnfn convert_char4_sat(short4);
char4 __ovld __cnfn convert_char4_rte(ushort4);
char4 __ovld __cnfn convert_char4_sat_rte(ushort4);
char4 __ovld __cnfn convert_char4_rtz(ushort4);
char4 __ovld __cnfn convert_char4_sat_rtz(ushort4);
char4 __ovld __cnfn convert_char4_rtp(ushort4);
char4 __ovld __cnfn convert_char4_sat_rtp(ushort4);
char4 __ovld __cnfn convert_char4_rtn(ushort4);
char4 __ovld __cnfn convert_char4_sat_rtn(ushort4);
char4 __ovld __cnfn convert_char4(ushort4);
char4 __ovld __cnfn convert_char4_sat(ushort4);
char4 __ovld __cnfn convert_char4_rte(int4);
char4 __ovld __cnfn convert_char4_sat_rte(int4);
char4 __ovld __cnfn convert_char4_rtz(int4);
char4 __ovld __cnfn convert_char4_sat_rtz(int4);
char4 __ovld __cnfn convert_char4_rtp(int4);
char4 __ovld __cnfn convert_char4_sat_rtp(int4);
char4 __ovld __cnfn convert_char4_rtn(int4);
char4 __ovld __cnfn convert_char4_sat_rtn(int4);
char4 __ovld __cnfn convert_char4(int4);
char4 __ovld __cnfn convert_char4_sat(int4);
char4 __ovld __cnfn convert_char4_rte(uint4);
char4 __ovld __cnfn convert_char4_sat_rte(uint4);
char4 __ovld __cnfn convert_char4_rtz(uint4);
char4 __ovld __cnfn convert_char4_sat_rtz(uint4);
char4 __ovld __cnfn convert_char4_rtp(uint4);
char4 __ovld __cnfn convert_char4_sat_rtp(uint4);
char4 __ovld __cnfn convert_char4_rtn(uint4);
char4 __ovld __cnfn convert_char4_sat_rtn(uint4);
char4 __ovld __cnfn convert_char4(uint4);
char4 __ovld __cnfn convert_char4_sat(uint4);
char4 __ovld __cnfn convert_char4_rte(long4);
char4 __ovld __cnfn convert_char4_sat_rte(long4);
char4 __ovld __cnfn convert_char4_rtz(long4);
char4 __ovld __cnfn convert_char4_sat_rtz(long4);
char4 __ovld __cnfn convert_char4_rtp(long4);
char4 __ovld __cnfn convert_char4_sat_rtp(long4);
char4 __ovld __cnfn convert_char4_rtn(long4);
char4 __ovld __cnfn convert_char4_sat_rtn(long4);
char4 __ovld __cnfn convert_char4(long4);
char4 __ovld __cnfn convert_char4_sat(long4);
char4 __ovld __cnfn convert_char4_rte(ulong4);
char4 __ovld __cnfn convert_char4_sat_rte(ulong4);
char4 __ovld __cnfn convert_char4_rtz(ulong4);
char4 __ovld __cnfn convert_char4_sat_rtz(ulong4);
char4 __ovld __cnfn convert_char4_rtp(ulong4);
char4 __ovld __cnfn convert_char4_sat_rtp(ulong4);
char4 __ovld __cnfn convert_char4_rtn(ulong4);
char4 __ovld __cnfn convert_char4_sat_rtn(ulong4);
char4 __ovld __cnfn convert_char4(ulong4);
char4 __ovld __cnfn convert_char4_sat(ulong4);
char4 __ovld __cnfn convert_char4_rte(float4);
char4 __ovld __cnfn convert_char4_sat_rte(float4);
char4 __ovld __cnfn convert_char4_rtz(float4);
char4 __ovld __cnfn convert_char4_sat_rtz(float4);
char4 __ovld __cnfn convert_char4_rtp(float4);
char4 __ovld __cnfn convert_char4_sat_rtp(float4);
char4 __ovld __cnfn convert_char4_rtn(float4);
char4 __ovld __cnfn convert_char4_sat_rtn(float4);
char4 __ovld __cnfn convert_char4(float4);
char4 __ovld __cnfn convert_char4_sat(float4);
uchar4 __ovld __cnfn convert_uchar4_rte(char4);
uchar4 __ovld __cnfn convert_uchar4_sat_rte(char4);
uchar4 __ovld __cnfn convert_uchar4_rtz(char4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtz(char4);
uchar4 __ovld __cnfn convert_uchar4_rtp(char4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtp(char4);
uchar4 __ovld __cnfn convert_uchar4_rtn(char4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtn(char4);
uchar4 __ovld __cnfn convert_uchar4(char4);
uchar4 __ovld __cnfn convert_uchar4_sat(char4);
uchar4 __ovld __cnfn convert_uchar4_rte(uchar4);
uchar4 __ovld __cnfn convert_uchar4_sat_rte(uchar4);
uchar4 __ovld __cnfn convert_uchar4_rtz(uchar4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtz(uchar4);
uchar4 __ovld __cnfn convert_uchar4_rtp(uchar4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtp(uchar4);
uchar4 __ovld __cnfn convert_uchar4_rtn(uchar4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtn(uchar4);
uchar4 __ovld __cnfn convert_uchar4(uchar4);
uchar4 __ovld __cnfn convert_uchar4_sat(uchar4);
uchar4 __ovld __cnfn convert_uchar4_rte(short4);
uchar4 __ovld __cnfn convert_uchar4_sat_rte(short4);
uchar4 __ovld __cnfn convert_uchar4_rtz(short4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtz(short4);
uchar4 __ovld __cnfn convert_uchar4_rtp(short4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtp(short4);
uchar4 __ovld __cnfn convert_uchar4_rtn(short4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtn(short4);
uchar4 __ovld __cnfn convert_uchar4(short4);
uchar4 __ovld __cnfn convert_uchar4_sat(short4);
uchar4 __ovld __cnfn convert_uchar4_rte(ushort4);
uchar4 __ovld __cnfn convert_uchar4_sat_rte(ushort4);
uchar4 __ovld __cnfn convert_uchar4_rtz(ushort4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtz(ushort4);
uchar4 __ovld __cnfn convert_uchar4_rtp(ushort4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtp(ushort4);
uchar4 __ovld __cnfn convert_uchar4_rtn(ushort4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtn(ushort4);
uchar4 __ovld __cnfn convert_uchar4(ushort4);
uchar4 __ovld __cnfn convert_uchar4_sat(ushort4);
uchar4 __ovld __cnfn convert_uchar4_rte(int4);
uchar4 __ovld __cnfn convert_uchar4_sat_rte(int4);
uchar4 __ovld __cnfn convert_uchar4_rtz(int4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtz(int4);
uchar4 __ovld __cnfn convert_uchar4_rtp(int4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtp(int4);
uchar4 __ovld __cnfn convert_uchar4_rtn(int4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtn(int4);
uchar4 __ovld __cnfn convert_uchar4(int4);
uchar4 __ovld __cnfn convert_uchar4_sat(int4);
uchar4 __ovld __cnfn convert_uchar4_rte(uint4);
uchar4 __ovld __cnfn convert_uchar4_sat_rte(uint4);
uchar4 __ovld __cnfn convert_uchar4_rtz(uint4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtz(uint4);
uchar4 __ovld __cnfn convert_uchar4_rtp(uint4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtp(uint4);
uchar4 __ovld __cnfn convert_uchar4_rtn(uint4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtn(uint4);
uchar4 __ovld __cnfn convert_uchar4(uint4);
uchar4 __ovld __cnfn convert_uchar4_sat(uint4);
uchar4 __ovld __cnfn convert_uchar4_rte(long4);
uchar4 __ovld __cnfn convert_uchar4_sat_rte(long4);
uchar4 __ovld __cnfn convert_uchar4_rtz(long4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtz(long4);
uchar4 __ovld __cnfn convert_uchar4_rtp(long4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtp(long4);
uchar4 __ovld __cnfn convert_uchar4_rtn(long4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtn(long4);
uchar4 __ovld __cnfn convert_uchar4(long4);
uchar4 __ovld __cnfn convert_uchar4_sat(long4);
uchar4 __ovld __cnfn convert_uchar4_rte(ulong4);
uchar4 __ovld __cnfn convert_uchar4_sat_rte(ulong4);
uchar4 __ovld __cnfn convert_uchar4_rtz(ulong4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtz(ulong4);
uchar4 __ovld __cnfn convert_uchar4_rtp(ulong4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtp(ulong4);
uchar4 __ovld __cnfn convert_uchar4_rtn(ulong4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtn(ulong4);
uchar4 __ovld __cnfn convert_uchar4(ulong4);
uchar4 __ovld __cnfn convert_uchar4_sat(ulong4);
uchar4 __ovld __cnfn convert_uchar4_rte(float4);
uchar4 __ovld __cnfn convert_uchar4_sat_rte(float4);
uchar4 __ovld __cnfn convert_uchar4_rtz(float4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtz(float4);
uchar4 __ovld __cnfn convert_uchar4_rtp(float4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtp(float4);
uchar4 __ovld __cnfn convert_uchar4_rtn(float4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtn(float4);
uchar4 __ovld __cnfn convert_uchar4(float4);
uchar4 __ovld __cnfn convert_uchar4_sat(float4);
short4 __ovld __cnfn convert_short4_rte(char4);
short4 __ovld __cnfn convert_short4_sat_rte(char4);
short4 __ovld __cnfn convert_short4_rtz(char4);
short4 __ovld __cnfn convert_short4_sat_rtz(char4);
short4 __ovld __cnfn convert_short4_rtp(char4);
short4 __ovld __cnfn convert_short4_sat_rtp(char4);
short4 __ovld __cnfn convert_short4_rtn(char4);
short4 __ovld __cnfn convert_short4_sat_rtn(char4);
short4 __ovld __cnfn convert_short4(char4);
short4 __ovld __cnfn convert_short4_sat(char4);
short4 __ovld __cnfn convert_short4_rte(uchar4);
short4 __ovld __cnfn convert_short4_sat_rte(uchar4);
short4 __ovld __cnfn convert_short4_rtz(uchar4);
short4 __ovld __cnfn convert_short4_sat_rtz(uchar4);
short4 __ovld __cnfn convert_short4_rtp(uchar4);
short4 __ovld __cnfn convert_short4_sat_rtp(uchar4);
short4 __ovld __cnfn convert_short4_rtn(uchar4);
short4 __ovld __cnfn convert_short4_sat_rtn(uchar4);
short4 __ovld __cnfn convert_short4(uchar4);
short4 __ovld __cnfn convert_short4_sat(uchar4);
short4 __ovld __cnfn convert_short4_rte(short4);
short4 __ovld __cnfn convert_short4_sat_rte(short4);
short4 __ovld __cnfn convert_short4_rtz(short4);
short4 __ovld __cnfn convert_short4_sat_rtz(short4);
short4 __ovld __cnfn convert_short4_rtp(short4);
short4 __ovld __cnfn convert_short4_sat_rtp(short4);
short4 __ovld __cnfn convert_short4_rtn(short4);
short4 __ovld __cnfn convert_short4_sat_rtn(short4);
short4 __ovld __cnfn convert_short4(short4);
short4 __ovld __cnfn convert_short4_sat(short4);
short4 __ovld __cnfn convert_short4_rte(ushort4);
short4 __ovld __cnfn convert_short4_sat_rte(ushort4);
short4 __ovld __cnfn convert_short4_rtz(ushort4);
short4 __ovld __cnfn convert_short4_sat_rtz(ushort4);
short4 __ovld __cnfn convert_short4_rtp(ushort4);
short4 __ovld __cnfn convert_short4_sat_rtp(ushort4);
short4 __ovld __cnfn convert_short4_rtn(ushort4);
short4 __ovld __cnfn convert_short4_sat_rtn(ushort4);
short4 __ovld __cnfn convert_short4(ushort4);
short4 __ovld __cnfn convert_short4_sat(ushort4);
short4 __ovld __cnfn convert_short4_rte(int4);
short4 __ovld __cnfn convert_short4_sat_rte(int4);
short4 __ovld __cnfn convert_short4_rtz(int4);
short4 __ovld __cnfn convert_short4_sat_rtz(int4);
short4 __ovld __cnfn convert_short4_rtp(int4);
short4 __ovld __cnfn convert_short4_sat_rtp(int4);
short4 __ovld __cnfn convert_short4_rtn(int4);
short4 __ovld __cnfn convert_short4_sat_rtn(int4);
short4 __ovld __cnfn convert_short4(int4);
short4 __ovld __cnfn convert_short4_sat(int4);
short4 __ovld __cnfn convert_short4_rte(uint4);
short4 __ovld __cnfn convert_short4_sat_rte(uint4);
short4 __ovld __cnfn convert_short4_rtz(uint4);
short4 __ovld __cnfn convert_short4_sat_rtz(uint4);
short4 __ovld __cnfn convert_short4_rtp(uint4);
short4 __ovld __cnfn convert_short4_sat_rtp(uint4);
short4 __ovld __cnfn convert_short4_rtn(uint4);
short4 __ovld __cnfn convert_short4_sat_rtn(uint4);
short4 __ovld __cnfn convert_short4(uint4);
short4 __ovld __cnfn convert_short4_sat(uint4);
short4 __ovld __cnfn convert_short4_rte(long4);
short4 __ovld __cnfn convert_short4_sat_rte(long4);
short4 __ovld __cnfn convert_short4_rtz(long4);
short4 __ovld __cnfn convert_short4_sat_rtz(long4);
short4 __ovld __cnfn convert_short4_rtp(long4);
short4 __ovld __cnfn convert_short4_sat_rtp(long4);
short4 __ovld __cnfn convert_short4_rtn(long4);
short4 __ovld __cnfn convert_short4_sat_rtn(long4);
short4 __ovld __cnfn convert_short4(long4);
short4 __ovld __cnfn convert_short4_sat(long4);
short4 __ovld __cnfn convert_short4_rte(ulong4);
short4 __ovld __cnfn convert_short4_sat_rte(ulong4);
short4 __ovld __cnfn convert_short4_rtz(ulong4);
short4 __ovld __cnfn convert_short4_sat_rtz(ulong4);
short4 __ovld __cnfn convert_short4_rtp(ulong4);
short4 __ovld __cnfn convert_short4_sat_rtp(ulong4);
short4 __ovld __cnfn convert_short4_rtn(ulong4);
short4 __ovld __cnfn convert_short4_sat_rtn(ulong4);
short4 __ovld __cnfn convert_short4(ulong4);
short4 __ovld __cnfn convert_short4_sat(ulong4);
short4 __ovld __cnfn convert_short4_rte(float4);
short4 __ovld __cnfn convert_short4_sat_rte(float4);
short4 __ovld __cnfn convert_short4_rtz(float4);
short4 __ovld __cnfn convert_short4_sat_rtz(float4);
short4 __ovld __cnfn convert_short4_rtp(float4);
short4 __ovld __cnfn convert_short4_sat_rtp(float4);
short4 __ovld __cnfn convert_short4_rtn(float4);
short4 __ovld __cnfn convert_short4_sat_rtn(float4);
short4 __ovld __cnfn convert_short4(float4);
short4 __ovld __cnfn convert_short4_sat(float4);
ushort4 __ovld __cnfn convert_ushort4_rte(char4);
ushort4 __ovld __cnfn convert_ushort4_sat_rte(char4);
ushort4 __ovld __cnfn convert_ushort4_rtz(char4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtz(char4);
ushort4 __ovld __cnfn convert_ushort4_rtp(char4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtp(char4);
ushort4 __ovld __cnfn convert_ushort4_rtn(char4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtn(char4);
ushort4 __ovld __cnfn convert_ushort4(char4);
ushort4 __ovld __cnfn convert_ushort4_sat(char4);
ushort4 __ovld __cnfn convert_ushort4_rte(uchar4);
ushort4 __ovld __cnfn convert_ushort4_sat_rte(uchar4);
ushort4 __ovld __cnfn convert_ushort4_rtz(uchar4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtz(uchar4);
ushort4 __ovld __cnfn convert_ushort4_rtp(uchar4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtp(uchar4);
ushort4 __ovld __cnfn convert_ushort4_rtn(uchar4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtn(uchar4);
ushort4 __ovld __cnfn convert_ushort4(uchar4);
ushort4 __ovld __cnfn convert_ushort4_sat(uchar4);
ushort4 __ovld __cnfn convert_ushort4_rte(short4);
ushort4 __ovld __cnfn convert_ushort4_sat_rte(short4);
ushort4 __ovld __cnfn convert_ushort4_rtz(short4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtz(short4);
ushort4 __ovld __cnfn convert_ushort4_rtp(short4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtp(short4);
ushort4 __ovld __cnfn convert_ushort4_rtn(short4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtn(short4);
ushort4 __ovld __cnfn convert_ushort4(short4);
ushort4 __ovld __cnfn convert_ushort4_sat(short4);
ushort4 __ovld __cnfn convert_ushort4_rte(ushort4);
ushort4 __ovld __cnfn convert_ushort4_sat_rte(ushort4);
ushort4 __ovld __cnfn convert_ushort4_rtz(ushort4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtz(ushort4);
ushort4 __ovld __cnfn convert_ushort4_rtp(ushort4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtp(ushort4);
ushort4 __ovld __cnfn convert_ushort4_rtn(ushort4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtn(ushort4);
ushort4 __ovld __cnfn convert_ushort4(ushort4);
ushort4 __ovld __cnfn convert_ushort4_sat(ushort4);
ushort4 __ovld __cnfn convert_ushort4_rte(int4);
ushort4 __ovld __cnfn convert_ushort4_sat_rte(int4);
ushort4 __ovld __cnfn convert_ushort4_rtz(int4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtz(int4);
ushort4 __ovld __cnfn convert_ushort4_rtp(int4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtp(int4);
ushort4 __ovld __cnfn convert_ushort4_rtn(int4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtn(int4);
ushort4 __ovld __cnfn convert_ushort4(int4);
ushort4 __ovld __cnfn convert_ushort4_sat(int4);
ushort4 __ovld __cnfn convert_ushort4_rte(uint4);
ushort4 __ovld __cnfn convert_ushort4_sat_rte(uint4);
ushort4 __ovld __cnfn convert_ushort4_rtz(uint4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtz(uint4);
ushort4 __ovld __cnfn convert_ushort4_rtp(uint4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtp(uint4);
ushort4 __ovld __cnfn convert_ushort4_rtn(uint4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtn(uint4);
ushort4 __ovld __cnfn convert_ushort4(uint4);
ushort4 __ovld __cnfn convert_ushort4_sat(uint4);
ushort4 __ovld __cnfn convert_ushort4_rte(long4);
ushort4 __ovld __cnfn convert_ushort4_sat_rte(long4);
ushort4 __ovld __cnfn convert_ushort4_rtz(long4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtz(long4);
ushort4 __ovld __cnfn convert_ushort4_rtp(long4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtp(long4);
ushort4 __ovld __cnfn convert_ushort4_rtn(long4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtn(long4);
ushort4 __ovld __cnfn convert_ushort4(long4);
ushort4 __ovld __cnfn convert_ushort4_sat(long4);
ushort4 __ovld __cnfn convert_ushort4_rte(ulong4);
ushort4 __ovld __cnfn convert_ushort4_sat_rte(ulong4);
ushort4 __ovld __cnfn convert_ushort4_rtz(ulong4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtz(ulong4);
ushort4 __ovld __cnfn convert_ushort4_rtp(ulong4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtp(ulong4);
ushort4 __ovld __cnfn convert_ushort4_rtn(ulong4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtn(ulong4);
ushort4 __ovld __cnfn convert_ushort4(ulong4);
ushort4 __ovld __cnfn convert_ushort4_sat(ulong4);
ushort4 __ovld __cnfn convert_ushort4_rte(float4);
ushort4 __ovld __cnfn convert_ushort4_sat_rte(float4);
ushort4 __ovld __cnfn convert_ushort4_rtz(float4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtz(float4);
ushort4 __ovld __cnfn convert_ushort4_rtp(float4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtp(float4);
ushort4 __ovld __cnfn convert_ushort4_rtn(float4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtn(float4);
ushort4 __ovld __cnfn convert_ushort4(float4);
ushort4 __ovld __cnfn convert_ushort4_sat(float4);
int4 __ovld __cnfn convert_int4_rte(char4);
int4 __ovld __cnfn convert_int4_sat_rte(char4);
int4 __ovld __cnfn convert_int4_rtz(char4);
int4 __ovld __cnfn convert_int4_sat_rtz(char4);
int4 __ovld __cnfn convert_int4_rtp(char4);
int4 __ovld __cnfn convert_int4_sat_rtp(char4);
int4 __ovld __cnfn convert_int4_rtn(char4);
int4 __ovld __cnfn convert_int4_sat_rtn(char4);
int4 __ovld __cnfn convert_int4(char4);
int4 __ovld __cnfn convert_int4_sat(char4);
int4 __ovld __cnfn convert_int4_rte(uchar4);
int4 __ovld __cnfn convert_int4_sat_rte(uchar4);
int4 __ovld __cnfn convert_int4_rtz(uchar4);
int4 __ovld __cnfn convert_int4_sat_rtz(uchar4);
int4 __ovld __cnfn convert_int4_rtp(uchar4);
int4 __ovld __cnfn convert_int4_sat_rtp(uchar4);
int4 __ovld __cnfn convert_int4_rtn(uchar4);
int4 __ovld __cnfn convert_int4_sat_rtn(uchar4);
int4 __ovld __cnfn convert_int4(uchar4);
int4 __ovld __cnfn convert_int4_sat(uchar4);
int4 __ovld __cnfn convert_int4_rte(short4);
int4 __ovld __cnfn convert_int4_sat_rte(short4);
int4 __ovld __cnfn convert_int4_rtz(short4);
int4 __ovld __cnfn convert_int4_sat_rtz(short4);
int4 __ovld __cnfn convert_int4_rtp(short4);
int4 __ovld __cnfn convert_int4_sat_rtp(short4);
int4 __ovld __cnfn convert_int4_rtn(short4);
int4 __ovld __cnfn convert_int4_sat_rtn(short4);
int4 __ovld __cnfn convert_int4(short4);
int4 __ovld __cnfn convert_int4_sat(short4);
int4 __ovld __cnfn convert_int4_rte(ushort4);
int4 __ovld __cnfn convert_int4_sat_rte(ushort4);
int4 __ovld __cnfn convert_int4_rtz(ushort4);
int4 __ovld __cnfn convert_int4_sat_rtz(ushort4);
int4 __ovld __cnfn convert_int4_rtp(ushort4);
int4 __ovld __cnfn convert_int4_sat_rtp(ushort4);
int4 __ovld __cnfn convert_int4_rtn(ushort4);
int4 __ovld __cnfn convert_int4_sat_rtn(ushort4);
int4 __ovld __cnfn convert_int4(ushort4);
int4 __ovld __cnfn convert_int4_sat(ushort4);
int4 __ovld __cnfn convert_int4_rte(int4);
int4 __ovld __cnfn convert_int4_sat_rte(int4);
int4 __ovld __cnfn convert_int4_rtz(int4);
int4 __ovld __cnfn convert_int4_sat_rtz(int4);
int4 __ovld __cnfn convert_int4_rtp(int4);
int4 __ovld __cnfn convert_int4_sat_rtp(int4);
int4 __ovld __cnfn convert_int4_rtn(int4);
int4 __ovld __cnfn convert_int4_sat_rtn(int4);
int4 __ovld __cnfn convert_int4(int4);
int4 __ovld __cnfn convert_int4_sat(int4);
int4 __ovld __cnfn convert_int4_rte(uint4);
int4 __ovld __cnfn convert_int4_sat_rte(uint4);
int4 __ovld __cnfn convert_int4_rtz(uint4);
int4 __ovld __cnfn convert_int4_sat_rtz(uint4);
int4 __ovld __cnfn convert_int4_rtp(uint4);
int4 __ovld __cnfn convert_int4_sat_rtp(uint4);
int4 __ovld __cnfn convert_int4_rtn(uint4);
int4 __ovld __cnfn convert_int4_sat_rtn(uint4);
int4 __ovld __cnfn convert_int4(uint4);
int4 __ovld __cnfn convert_int4_sat(uint4);
int4 __ovld __cnfn convert_int4_rte(long4);
int4 __ovld __cnfn convert_int4_sat_rte(long4);
int4 __ovld __cnfn convert_int4_rtz(long4);
int4 __ovld __cnfn convert_int4_sat_rtz(long4);
int4 __ovld __cnfn convert_int4_rtp(long4);
int4 __ovld __cnfn convert_int4_sat_rtp(long4);
int4 __ovld __cnfn convert_int4_rtn(long4);
int4 __ovld __cnfn convert_int4_sat_rtn(long4);
int4 __ovld __cnfn convert_int4(long4);
int4 __ovld __cnfn convert_int4_sat(long4);
int4 __ovld __cnfn convert_int4_rte(ulong4);
int4 __ovld __cnfn convert_int4_sat_rte(ulong4);
int4 __ovld __cnfn convert_int4_rtz(ulong4);
int4 __ovld __cnfn convert_int4_sat_rtz(ulong4);
int4 __ovld __cnfn convert_int4_rtp(ulong4);
int4 __ovld __cnfn convert_int4_sat_rtp(ulong4);
int4 __ovld __cnfn convert_int4_rtn(ulong4);
int4 __ovld __cnfn convert_int4_sat_rtn(ulong4);
int4 __ovld __cnfn convert_int4(ulong4);
int4 __ovld __cnfn convert_int4_sat(ulong4);
int4 __ovld __cnfn convert_int4_rte(float4);
int4 __ovld __cnfn convert_int4_sat_rte(float4);
int4 __ovld __cnfn convert_int4_rtz(float4);
int4 __ovld __cnfn convert_int4_sat_rtz(float4);
int4 __ovld __cnfn convert_int4_rtp(float4);
int4 __ovld __cnfn convert_int4_sat_rtp(float4);
int4 __ovld __cnfn convert_int4_rtn(float4);
int4 __ovld __cnfn convert_int4_sat_rtn(float4);
int4 __ovld __cnfn convert_int4(float4);
int4 __ovld __cnfn convert_int4_sat(float4);
uint4 __ovld __cnfn convert_uint4_rte(char4);
uint4 __ovld __cnfn convert_uint4_sat_rte(char4);
uint4 __ovld __cnfn convert_uint4_rtz(char4);
uint4 __ovld __cnfn convert_uint4_sat_rtz(char4);
uint4 __ovld __cnfn convert_uint4_rtp(char4);
uint4 __ovld __cnfn convert_uint4_sat_rtp(char4);
uint4 __ovld __cnfn convert_uint4_rtn(char4);
uint4 __ovld __cnfn convert_uint4_sat_rtn(char4);
uint4 __ovld __cnfn convert_uint4(char4);
uint4 __ovld __cnfn convert_uint4_sat(char4);
uint4 __ovld __cnfn convert_uint4_rte(uchar4);
uint4 __ovld __cnfn convert_uint4_sat_rte(uchar4);
uint4 __ovld __cnfn convert_uint4_rtz(uchar4);
uint4 __ovld __cnfn convert_uint4_sat_rtz(uchar4);
uint4 __ovld __cnfn convert_uint4_rtp(uchar4);
uint4 __ovld __cnfn convert_uint4_sat_rtp(uchar4);
uint4 __ovld __cnfn convert_uint4_rtn(uchar4);
uint4 __ovld __cnfn convert_uint4_sat_rtn(uchar4);
uint4 __ovld __cnfn convert_uint4(uchar4);
uint4 __ovld __cnfn convert_uint4_sat(uchar4);
uint4 __ovld __cnfn convert_uint4_rte(short4);
uint4 __ovld __cnfn convert_uint4_sat_rte(short4);
uint4 __ovld __cnfn convert_uint4_rtz(short4);
uint4 __ovld __cnfn convert_uint4_sat_rtz(short4);
uint4 __ovld __cnfn convert_uint4_rtp(short4);
uint4 __ovld __cnfn convert_uint4_sat_rtp(short4);
uint4 __ovld __cnfn convert_uint4_rtn(short4);
uint4 __ovld __cnfn convert_uint4_sat_rtn(short4);
uint4 __ovld __cnfn convert_uint4(short4);
uint4 __ovld __cnfn convert_uint4_sat(short4);
uint4 __ovld __cnfn convert_uint4_rte(ushort4);
uint4 __ovld __cnfn convert_uint4_sat_rte(ushort4);
uint4 __ovld __cnfn convert_uint4_rtz(ushort4);
uint4 __ovld __cnfn convert_uint4_sat_rtz(ushort4);
uint4 __ovld __cnfn convert_uint4_rtp(ushort4);
uint4 __ovld __cnfn convert_uint4_sat_rtp(ushort4);
uint4 __ovld __cnfn convert_uint4_rtn(ushort4);
uint4 __ovld __cnfn convert_uint4_sat_rtn(ushort4);
uint4 __ovld __cnfn convert_uint4(ushort4);
uint4 __ovld __cnfn convert_uint4_sat(ushort4);
uint4 __ovld __cnfn convert_uint4_rte(int4);
uint4 __ovld __cnfn convert_uint4_sat_rte(int4);
uint4 __ovld __cnfn convert_uint4_rtz(int4);
uint4 __ovld __cnfn convert_uint4_sat_rtz(int4);
uint4 __ovld __cnfn convert_uint4_rtp(int4);
uint4 __ovld __cnfn convert_uint4_sat_rtp(int4);
uint4 __ovld __cnfn convert_uint4_rtn(int4);
uint4 __ovld __cnfn convert_uint4_sat_rtn(int4);
uint4 __ovld __cnfn convert_uint4(int4);
uint4 __ovld __cnfn convert_uint4_sat(int4);
uint4 __ovld __cnfn convert_uint4_rte(uint4);
uint4 __ovld __cnfn convert_uint4_sat_rte(uint4);
uint4 __ovld __cnfn convert_uint4_rtz(uint4);
uint4 __ovld __cnfn convert_uint4_sat_rtz(uint4);
uint4 __ovld __cnfn convert_uint4_rtp(uint4);
uint4 __ovld __cnfn convert_uint4_sat_rtp(uint4);
uint4 __ovld __cnfn convert_uint4_rtn(uint4);
uint4 __ovld __cnfn convert_uint4_sat_rtn(uint4);
uint4 __ovld __cnfn convert_uint4(uint4);
uint4 __ovld __cnfn convert_uint4_sat(uint4);
uint4 __ovld __cnfn convert_uint4_rte(long4);
uint4 __ovld __cnfn convert_uint4_sat_rte(long4);
uint4 __ovld __cnfn convert_uint4_rtz(long4);
uint4 __ovld __cnfn convert_uint4_sat_rtz(long4);
uint4 __ovld __cnfn convert_uint4_rtp(long4);
uint4 __ovld __cnfn convert_uint4_sat_rtp(long4);
uint4 __ovld __cnfn convert_uint4_rtn(long4);
uint4 __ovld __cnfn convert_uint4_sat_rtn(long4);
uint4 __ovld __cnfn convert_uint4(long4);
uint4 __ovld __cnfn convert_uint4_sat(long4);
uint4 __ovld __cnfn convert_uint4_rte(ulong4);
uint4 __ovld __cnfn convert_uint4_sat_rte(ulong4);
uint4 __ovld __cnfn convert_uint4_rtz(ulong4);
uint4 __ovld __cnfn convert_uint4_sat_rtz(ulong4);
uint4 __ovld __cnfn convert_uint4_rtp(ulong4);
uint4 __ovld __cnfn convert_uint4_sat_rtp(ulong4);
uint4 __ovld __cnfn convert_uint4_rtn(ulong4);
uint4 __ovld __cnfn convert_uint4_sat_rtn(ulong4);
uint4 __ovld __cnfn convert_uint4(ulong4);
uint4 __ovld __cnfn convert_uint4_sat(ulong4);
uint4 __ovld __cnfn convert_uint4_rte(float4);
uint4 __ovld __cnfn convert_uint4_sat_rte(float4);
uint4 __ovld __cnfn convert_uint4_rtz(float4);
uint4 __ovld __cnfn convert_uint4_sat_rtz(float4);
uint4 __ovld __cnfn convert_uint4_rtp(float4);
uint4 __ovld __cnfn convert_uint4_sat_rtp(float4);
uint4 __ovld __cnfn convert_uint4_rtn(float4);
uint4 __ovld __cnfn convert_uint4_sat_rtn(float4);
uint4 __ovld __cnfn convert_uint4(float4);
uint4 __ovld __cnfn convert_uint4_sat(float4);
long4 __ovld __cnfn convert_long4_rte(char4);
long4 __ovld __cnfn convert_long4_sat_rte(char4);
long4 __ovld __cnfn convert_long4_rtz(char4);
long4 __ovld __cnfn convert_long4_sat_rtz(char4);
long4 __ovld __cnfn convert_long4_rtp(char4);
long4 __ovld __cnfn convert_long4_sat_rtp(char4);
long4 __ovld __cnfn convert_long4_rtn(char4);
long4 __ovld __cnfn convert_long4_sat_rtn(char4);
long4 __ovld __cnfn convert_long4(char4);
long4 __ovld __cnfn convert_long4_sat(char4);
long4 __ovld __cnfn convert_long4_rte(uchar4);
long4 __ovld __cnfn convert_long4_sat_rte(uchar4);
long4 __ovld __cnfn convert_long4_rtz(uchar4);
long4 __ovld __cnfn convert_long4_sat_rtz(uchar4);
long4 __ovld __cnfn convert_long4_rtp(uchar4);
long4 __ovld __cnfn convert_long4_sat_rtp(uchar4);
long4 __ovld __cnfn convert_long4_rtn(uchar4);
long4 __ovld __cnfn convert_long4_sat_rtn(uchar4);
long4 __ovld __cnfn convert_long4(uchar4);
long4 __ovld __cnfn convert_long4_sat(uchar4);
long4 __ovld __cnfn convert_long4_rte(short4);
long4 __ovld __cnfn convert_long4_sat_rte(short4);
long4 __ovld __cnfn convert_long4_rtz(short4);
long4 __ovld __cnfn convert_long4_sat_rtz(short4);
long4 __ovld __cnfn convert_long4_rtp(short4);
long4 __ovld __cnfn convert_long4_sat_rtp(short4);
long4 __ovld __cnfn convert_long4_rtn(short4);
long4 __ovld __cnfn convert_long4_sat_rtn(short4);
long4 __ovld __cnfn convert_long4(short4);
long4 __ovld __cnfn convert_long4_sat(short4);
long4 __ovld __cnfn convert_long4_rte(ushort4);
long4 __ovld __cnfn convert_long4_sat_rte(ushort4);
long4 __ovld __cnfn convert_long4_rtz(ushort4);
long4 __ovld __cnfn convert_long4_sat_rtz(ushort4);
long4 __ovld __cnfn convert_long4_rtp(ushort4);
long4 __ovld __cnfn convert_long4_sat_rtp(ushort4);
long4 __ovld __cnfn convert_long4_rtn(ushort4);
long4 __ovld __cnfn convert_long4_sat_rtn(ushort4);
long4 __ovld __cnfn convert_long4(ushort4);
long4 __ovld __cnfn convert_long4_sat(ushort4);
long4 __ovld __cnfn convert_long4_rte(int4);
long4 __ovld __cnfn convert_long4_sat_rte(int4);
long4 __ovld __cnfn convert_long4_rtz(int4);
long4 __ovld __cnfn convert_long4_sat_rtz(int4);
long4 __ovld __cnfn convert_long4_rtp(int4);
long4 __ovld __cnfn convert_long4_sat_rtp(int4);
long4 __ovld __cnfn convert_long4_rtn(int4);
long4 __ovld __cnfn convert_long4_sat_rtn(int4);
long4 __ovld __cnfn convert_long4(int4);
long4 __ovld __cnfn convert_long4_sat(int4);
long4 __ovld __cnfn convert_long4_rte(uint4);
long4 __ovld __cnfn convert_long4_sat_rte(uint4);
long4 __ovld __cnfn convert_long4_rtz(uint4);
long4 __ovld __cnfn convert_long4_sat_rtz(uint4);
long4 __ovld __cnfn convert_long4_rtp(uint4);
long4 __ovld __cnfn convert_long4_sat_rtp(uint4);
long4 __ovld __cnfn convert_long4_rtn(uint4);
long4 __ovld __cnfn convert_long4_sat_rtn(uint4);
long4 __ovld __cnfn convert_long4(uint4);
long4 __ovld __cnfn convert_long4_sat(uint4);
long4 __ovld __cnfn convert_long4_rte(long4);
long4 __ovld __cnfn convert_long4_sat_rte(long4);
long4 __ovld __cnfn convert_long4_rtz(long4);
long4 __ovld __cnfn convert_long4_sat_rtz(long4);
long4 __ovld __cnfn convert_long4_rtp(long4);
long4 __ovld __cnfn convert_long4_sat_rtp(long4);
long4 __ovld __cnfn convert_long4_rtn(long4);
long4 __ovld __cnfn convert_long4_sat_rtn(long4);
long4 __ovld __cnfn convert_long4(long4);
long4 __ovld __cnfn convert_long4_sat(long4);
long4 __ovld __cnfn convert_long4_rte(ulong4);
long4 __ovld __cnfn convert_long4_sat_rte(ulong4);
long4 __ovld __cnfn convert_long4_rtz(ulong4);
long4 __ovld __cnfn convert_long4_sat_rtz(ulong4);
long4 __ovld __cnfn convert_long4_rtp(ulong4);
long4 __ovld __cnfn convert_long4_sat_rtp(ulong4);
long4 __ovld __cnfn convert_long4_rtn(ulong4);
long4 __ovld __cnfn convert_long4_sat_rtn(ulong4);
long4 __ovld __cnfn convert_long4(ulong4);
long4 __ovld __cnfn convert_long4_sat(ulong4);
long4 __ovld __cnfn convert_long4_rte(float4);
long4 __ovld __cnfn convert_long4_sat_rte(float4);
long4 __ovld __cnfn convert_long4_rtz(float4);
long4 __ovld __cnfn convert_long4_sat_rtz(float4);
long4 __ovld __cnfn convert_long4_rtp(float4);
long4 __ovld __cnfn convert_long4_sat_rtp(float4);
long4 __ovld __cnfn convert_long4_rtn(float4);
long4 __ovld __cnfn convert_long4_sat_rtn(float4);
long4 __ovld __cnfn convert_long4(float4);
long4 __ovld __cnfn convert_long4_sat(float4);
ulong4 __ovld __cnfn convert_ulong4_rte(char4);
ulong4 __ovld __cnfn convert_ulong4_sat_rte(char4);
ulong4 __ovld __cnfn convert_ulong4_rtz(char4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtz(char4);
ulong4 __ovld __cnfn convert_ulong4_rtp(char4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtp(char4);
ulong4 __ovld __cnfn convert_ulong4_rtn(char4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtn(char4);
ulong4 __ovld __cnfn convert_ulong4(char4);
ulong4 __ovld __cnfn convert_ulong4_sat(char4);
ulong4 __ovld __cnfn convert_ulong4_rte(uchar4);
ulong4 __ovld __cnfn convert_ulong4_sat_rte(uchar4);
ulong4 __ovld __cnfn convert_ulong4_rtz(uchar4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtz(uchar4);
ulong4 __ovld __cnfn convert_ulong4_rtp(uchar4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtp(uchar4);
ulong4 __ovld __cnfn convert_ulong4_rtn(uchar4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtn(uchar4);
ulong4 __ovld __cnfn convert_ulong4(uchar4);
ulong4 __ovld __cnfn convert_ulong4_sat(uchar4);
ulong4 __ovld __cnfn convert_ulong4_rte(short4);
ulong4 __ovld __cnfn convert_ulong4_sat_rte(short4);
ulong4 __ovld __cnfn convert_ulong4_rtz(short4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtz(short4);
ulong4 __ovld __cnfn convert_ulong4_rtp(short4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtp(short4);
ulong4 __ovld __cnfn convert_ulong4_rtn(short4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtn(short4);
ulong4 __ovld __cnfn convert_ulong4(short4);
ulong4 __ovld __cnfn convert_ulong4_sat(short4);
ulong4 __ovld __cnfn convert_ulong4_rte(ushort4);
ulong4 __ovld __cnfn convert_ulong4_sat_rte(ushort4);
ulong4 __ovld __cnfn convert_ulong4_rtz(ushort4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtz(ushort4);
ulong4 __ovld __cnfn convert_ulong4_rtp(ushort4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtp(ushort4);
ulong4 __ovld __cnfn convert_ulong4_rtn(ushort4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtn(ushort4);
ulong4 __ovld __cnfn convert_ulong4(ushort4);
ulong4 __ovld __cnfn convert_ulong4_sat(ushort4);
ulong4 __ovld __cnfn convert_ulong4_rte(int4);
ulong4 __ovld __cnfn convert_ulong4_sat_rte(int4);
ulong4 __ovld __cnfn convert_ulong4_rtz(int4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtz(int4);
ulong4 __ovld __cnfn convert_ulong4_rtp(int4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtp(int4);
ulong4 __ovld __cnfn convert_ulong4_rtn(int4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtn(int4);
ulong4 __ovld __cnfn convert_ulong4(int4);
ulong4 __ovld __cnfn convert_ulong4_sat(int4);
ulong4 __ovld __cnfn convert_ulong4_rte(uint4);
ulong4 __ovld __cnfn convert_ulong4_sat_rte(uint4);
ulong4 __ovld __cnfn convert_ulong4_rtz(uint4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtz(uint4);
ulong4 __ovld __cnfn convert_ulong4_rtp(uint4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtp(uint4);
ulong4 __ovld __cnfn convert_ulong4_rtn(uint4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtn(uint4);
ulong4 __ovld __cnfn convert_ulong4(uint4);
ulong4 __ovld __cnfn convert_ulong4_sat(uint4);
ulong4 __ovld __cnfn convert_ulong4_rte(long4);
ulong4 __ovld __cnfn convert_ulong4_sat_rte(long4);
ulong4 __ovld __cnfn convert_ulong4_rtz(long4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtz(long4);
ulong4 __ovld __cnfn convert_ulong4_rtp(long4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtp(long4);
ulong4 __ovld __cnfn convert_ulong4_rtn(long4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtn(long4);
ulong4 __ovld __cnfn convert_ulong4(long4);
ulong4 __ovld __cnfn convert_ulong4_sat(long4);
ulong4 __ovld __cnfn convert_ulong4_rte(ulong4);
ulong4 __ovld __cnfn convert_ulong4_sat_rte(ulong4);
ulong4 __ovld __cnfn convert_ulong4_rtz(ulong4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtz(ulong4);
ulong4 __ovld __cnfn convert_ulong4_rtp(ulong4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtp(ulong4);
ulong4 __ovld __cnfn convert_ulong4_rtn(ulong4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtn(ulong4);
ulong4 __ovld __cnfn convert_ulong4(ulong4);
ulong4 __ovld __cnfn convert_ulong4_sat(ulong4);
ulong4 __ovld __cnfn convert_ulong4_rte(float4);
ulong4 __ovld __cnfn convert_ulong4_sat_rte(float4);
ulong4 __ovld __cnfn convert_ulong4_rtz(float4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtz(float4);
ulong4 __ovld __cnfn convert_ulong4_rtp(float4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtp(float4);
ulong4 __ovld __cnfn convert_ulong4_rtn(float4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtn(float4);
ulong4 __ovld __cnfn convert_ulong4(float4);
ulong4 __ovld __cnfn convert_ulong4_sat(float4);
float4 __ovld __cnfn convert_float4_rte(char4);
float4 __ovld __cnfn convert_float4_rtz(char4);
float4 __ovld __cnfn convert_float4_rtp(char4);
float4 __ovld __cnfn convert_float4_rtn(char4);
float4 __ovld __cnfn convert_float4(char4);
float4 __ovld __cnfn convert_float4_rte(uchar4);
float4 __ovld __cnfn convert_float4_rtz(uchar4);
float4 __ovld __cnfn convert_float4_rtp(uchar4);
float4 __ovld __cnfn convert_float4_rtn(uchar4);
float4 __ovld __cnfn convert_float4(uchar4);
float4 __ovld __cnfn convert_float4_rte(short4);
float4 __ovld __cnfn convert_float4_rtz(short4);
float4 __ovld __cnfn convert_float4_rtp(short4);
float4 __ovld __cnfn convert_float4_rtn(short4);
float4 __ovld __cnfn convert_float4(short4);
float4 __ovld __cnfn convert_float4_rte(ushort4);
float4 __ovld __cnfn convert_float4_rtz(ushort4);
float4 __ovld __cnfn convert_float4_rtp(ushort4);
float4 __ovld __cnfn convert_float4_rtn(ushort4);
float4 __ovld __cnfn convert_float4(ushort4);
float4 __ovld __cnfn convert_float4_rte(int4);
float4 __ovld __cnfn convert_float4_rtz(int4);
float4 __ovld __cnfn convert_float4_rtp(int4);
float4 __ovld __cnfn convert_float4_rtn(int4);
float4 __ovld __cnfn convert_float4(int4);
float4 __ovld __cnfn convert_float4_rte(uint4);
float4 __ovld __cnfn convert_float4_rtz(uint4);
float4 __ovld __cnfn convert_float4_rtp(uint4);
float4 __ovld __cnfn convert_float4_rtn(uint4);
float4 __ovld __cnfn convert_float4(uint4);
float4 __ovld __cnfn convert_float4_rte(long4);
float4 __ovld __cnfn convert_float4_rtz(long4);
float4 __ovld __cnfn convert_float4_rtp(long4);
float4 __ovld __cnfn convert_float4_rtn(long4);
float4 __ovld __cnfn convert_float4(long4);
float4 __ovld __cnfn convert_float4_rte(ulong4);
float4 __ovld __cnfn convert_float4_rtz(ulong4);
float4 __ovld __cnfn convert_float4_rtp(ulong4);
float4 __ovld __cnfn convert_float4_rtn(ulong4);
float4 __ovld __cnfn convert_float4(ulong4);
float4 __ovld __cnfn convert_float4_rte(float4);
float4 __ovld __cnfn convert_float4_rtz(float4);
float4 __ovld __cnfn convert_float4_rtp(float4);
float4 __ovld __cnfn convert_float4_rtn(float4);
float4 __ovld __cnfn convert_float4(float4);
char8 __ovld __cnfn convert_char8_rte(char8);
char8 __ovld __cnfn convert_char8_sat_rte(char8);
char8 __ovld __cnfn convert_char8_rtz(char8);
char8 __ovld __cnfn convert_char8_sat_rtz(char8);
char8 __ovld __cnfn convert_char8_rtp(char8);
char8 __ovld __cnfn convert_char8_sat_rtp(char8);
char8 __ovld __cnfn convert_char8_rtn(char8);
char8 __ovld __cnfn convert_char8_sat_rtn(char8);
char8 __ovld __cnfn convert_char8(char8);
char8 __ovld __cnfn convert_char8_sat(char8);
char8 __ovld __cnfn convert_char8_rte(uchar8);
char8 __ovld __cnfn convert_char8_sat_rte(uchar8);
char8 __ovld __cnfn convert_char8_rtz(uchar8);
char8 __ovld __cnfn convert_char8_sat_rtz(uchar8);
char8 __ovld __cnfn convert_char8_rtp(uchar8);
char8 __ovld __cnfn convert_char8_sat_rtp(uchar8);
char8 __ovld __cnfn convert_char8_rtn(uchar8);
char8 __ovld __cnfn convert_char8_sat_rtn(uchar8);
char8 __ovld __cnfn convert_char8(uchar8);
char8 __ovld __cnfn convert_char8_sat(uchar8);
char8 __ovld __cnfn convert_char8_rte(short8);
char8 __ovld __cnfn convert_char8_sat_rte(short8);
char8 __ovld __cnfn convert_char8_rtz(short8);
char8 __ovld __cnfn convert_char8_sat_rtz(short8);
char8 __ovld __cnfn convert_char8_rtp(short8);
char8 __ovld __cnfn convert_char8_sat_rtp(short8);
char8 __ovld __cnfn convert_char8_rtn(short8);
char8 __ovld __cnfn convert_char8_sat_rtn(short8);
char8 __ovld __cnfn convert_char8(short8);
char8 __ovld __cnfn convert_char8_sat(short8);
char8 __ovld __cnfn convert_char8_rte(ushort8);
char8 __ovld __cnfn convert_char8_sat_rte(ushort8);
char8 __ovld __cnfn convert_char8_rtz(ushort8);
char8 __ovld __cnfn convert_char8_sat_rtz(ushort8);
char8 __ovld __cnfn convert_char8_rtp(ushort8);
char8 __ovld __cnfn convert_char8_sat_rtp(ushort8);
char8 __ovld __cnfn convert_char8_rtn(ushort8);
char8 __ovld __cnfn convert_char8_sat_rtn(ushort8);
char8 __ovld __cnfn convert_char8(ushort8);
char8 __ovld __cnfn convert_char8_sat(ushort8);
char8 __ovld __cnfn convert_char8_rte(int8);
char8 __ovld __cnfn convert_char8_sat_rte(int8);
char8 __ovld __cnfn convert_char8_rtz(int8);
char8 __ovld __cnfn convert_char8_sat_rtz(int8);
char8 __ovld __cnfn convert_char8_rtp(int8);
char8 __ovld __cnfn convert_char8_sat_rtp(int8);
char8 __ovld __cnfn convert_char8_rtn(int8);
char8 __ovld __cnfn convert_char8_sat_rtn(int8);
char8 __ovld __cnfn convert_char8(int8);
char8 __ovld __cnfn convert_char8_sat(int8);
char8 __ovld __cnfn convert_char8_rte(uint8);
char8 __ovld __cnfn convert_char8_sat_rte(uint8);
char8 __ovld __cnfn convert_char8_rtz(uint8);
char8 __ovld __cnfn convert_char8_sat_rtz(uint8);
char8 __ovld __cnfn convert_char8_rtp(uint8);
char8 __ovld __cnfn convert_char8_sat_rtp(uint8);
char8 __ovld __cnfn convert_char8_rtn(uint8);
char8 __ovld __cnfn convert_char8_sat_rtn(uint8);
char8 __ovld __cnfn convert_char8(uint8);
char8 __ovld __cnfn convert_char8_sat(uint8);
char8 __ovld __cnfn convert_char8_rte(long8);
char8 __ovld __cnfn convert_char8_sat_rte(long8);
char8 __ovld __cnfn convert_char8_rtz(long8);
char8 __ovld __cnfn convert_char8_sat_rtz(long8);
char8 __ovld __cnfn convert_char8_rtp(long8);
char8 __ovld __cnfn convert_char8_sat_rtp(long8);
char8 __ovld __cnfn convert_char8_rtn(long8);
char8 __ovld __cnfn convert_char8_sat_rtn(long8);
char8 __ovld __cnfn convert_char8(long8);
char8 __ovld __cnfn convert_char8_sat(long8);
char8 __ovld __cnfn convert_char8_rte(ulong8);
char8 __ovld __cnfn convert_char8_sat_rte(ulong8);
char8 __ovld __cnfn convert_char8_rtz(ulong8);
char8 __ovld __cnfn convert_char8_sat_rtz(ulong8);
char8 __ovld __cnfn convert_char8_rtp(ulong8);
char8 __ovld __cnfn convert_char8_sat_rtp(ulong8);
char8 __ovld __cnfn convert_char8_rtn(ulong8);
char8 __ovld __cnfn convert_char8_sat_rtn(ulong8);
char8 __ovld __cnfn convert_char8(ulong8);
char8 __ovld __cnfn convert_char8_sat(ulong8);
char8 __ovld __cnfn convert_char8_rte(float8);
char8 __ovld __cnfn convert_char8_sat_rte(float8);
char8 __ovld __cnfn convert_char8_rtz(float8);
char8 __ovld __cnfn convert_char8_sat_rtz(float8);
char8 __ovld __cnfn convert_char8_rtp(float8);
char8 __ovld __cnfn convert_char8_sat_rtp(float8);
char8 __ovld __cnfn convert_char8_rtn(float8);
char8 __ovld __cnfn convert_char8_sat_rtn(float8);
char8 __ovld __cnfn convert_char8(float8);
char8 __ovld __cnfn convert_char8_sat(float8);
uchar8 __ovld __cnfn convert_uchar8_rte(char8);
uchar8 __ovld __cnfn convert_uchar8_sat_rte(char8);
uchar8 __ovld __cnfn convert_uchar8_rtz(char8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtz(char8);
uchar8 __ovld __cnfn convert_uchar8_rtp(char8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtp(char8);
uchar8 __ovld __cnfn convert_uchar8_rtn(char8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtn(char8);
uchar8 __ovld __cnfn convert_uchar8(char8);
uchar8 __ovld __cnfn convert_uchar8_sat(char8);
uchar8 __ovld __cnfn convert_uchar8_rte(uchar8);
uchar8 __ovld __cnfn convert_uchar8_sat_rte(uchar8);
uchar8 __ovld __cnfn convert_uchar8_rtz(uchar8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtz(uchar8);
uchar8 __ovld __cnfn convert_uchar8_rtp(uchar8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtp(uchar8);
uchar8 __ovld __cnfn convert_uchar8_rtn(uchar8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtn(uchar8);
uchar8 __ovld __cnfn convert_uchar8(uchar8);
uchar8 __ovld __cnfn convert_uchar8_sat(uchar8);
uchar8 __ovld __cnfn convert_uchar8_rte(short8);
uchar8 __ovld __cnfn convert_uchar8_sat_rte(short8);
uchar8 __ovld __cnfn convert_uchar8_rtz(short8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtz(short8);
uchar8 __ovld __cnfn convert_uchar8_rtp(short8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtp(short8);
uchar8 __ovld __cnfn convert_uchar8_rtn(short8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtn(short8);
uchar8 __ovld __cnfn convert_uchar8(short8);
uchar8 __ovld __cnfn convert_uchar8_sat(short8);
uchar8 __ovld __cnfn convert_uchar8_rte(ushort8);
uchar8 __ovld __cnfn convert_uchar8_sat_rte(ushort8);
uchar8 __ovld __cnfn convert_uchar8_rtz(ushort8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtz(ushort8);
uchar8 __ovld __cnfn convert_uchar8_rtp(ushort8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtp(ushort8);
uchar8 __ovld __cnfn convert_uchar8_rtn(ushort8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtn(ushort8);
uchar8 __ovld __cnfn convert_uchar8(ushort8);
uchar8 __ovld __cnfn convert_uchar8_sat(ushort8);
uchar8 __ovld __cnfn convert_uchar8_rte(int8);
uchar8 __ovld __cnfn convert_uchar8_sat_rte(int8);
uchar8 __ovld __cnfn convert_uchar8_rtz(int8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtz(int8);
uchar8 __ovld __cnfn convert_uchar8_rtp(int8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtp(int8);
uchar8 __ovld __cnfn convert_uchar8_rtn(int8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtn(int8);
uchar8 __ovld __cnfn convert_uchar8(int8);
uchar8 __ovld __cnfn convert_uchar8_sat(int8);
uchar8 __ovld __cnfn convert_uchar8_rte(uint8);
uchar8 __ovld __cnfn convert_uchar8_sat_rte(uint8);
uchar8 __ovld __cnfn convert_uchar8_rtz(uint8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtz(uint8);
uchar8 __ovld __cnfn convert_uchar8_rtp(uint8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtp(uint8);
uchar8 __ovld __cnfn convert_uchar8_rtn(uint8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtn(uint8);
uchar8 __ovld __cnfn convert_uchar8(uint8);
uchar8 __ovld __cnfn convert_uchar8_sat(uint8);
uchar8 __ovld __cnfn convert_uchar8_rte(long8);
uchar8 __ovld __cnfn convert_uchar8_sat_rte(long8);
uchar8 __ovld __cnfn convert_uchar8_rtz(long8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtz(long8);
uchar8 __ovld __cnfn convert_uchar8_rtp(long8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtp(long8);
uchar8 __ovld __cnfn convert_uchar8_rtn(long8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtn(long8);
uchar8 __ovld __cnfn convert_uchar8(long8);
uchar8 __ovld __cnfn convert_uchar8_sat(long8);
uchar8 __ovld __cnfn convert_uchar8_rte(ulong8);
uchar8 __ovld __cnfn convert_uchar8_sat_rte(ulong8);
uchar8 __ovld __cnfn convert_uchar8_rtz(ulong8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtz(ulong8);
uchar8 __ovld __cnfn convert_uchar8_rtp(ulong8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtp(ulong8);
uchar8 __ovld __cnfn convert_uchar8_rtn(ulong8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtn(ulong8);
uchar8 __ovld __cnfn convert_uchar8(ulong8);
uchar8 __ovld __cnfn convert_uchar8_sat(ulong8);
uchar8 __ovld __cnfn convert_uchar8_rte(float8);
uchar8 __ovld __cnfn convert_uchar8_sat_rte(float8);
uchar8 __ovld __cnfn convert_uchar8_rtz(float8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtz(float8);
uchar8 __ovld __cnfn convert_uchar8_rtp(float8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtp(float8);
uchar8 __ovld __cnfn convert_uchar8_rtn(float8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtn(float8);
uchar8 __ovld __cnfn convert_uchar8(float8);
uchar8 __ovld __cnfn convert_uchar8_sat(float8);
short8 __ovld __cnfn convert_short8_rte(char8);
short8 __ovld __cnfn convert_short8_sat_rte(char8);
short8 __ovld __cnfn convert_short8_rtz(char8);
short8 __ovld __cnfn convert_short8_sat_rtz(char8);
short8 __ovld __cnfn convert_short8_rtp(char8);
short8 __ovld __cnfn convert_short8_sat_rtp(char8);
short8 __ovld __cnfn convert_short8_rtn(char8);
short8 __ovld __cnfn convert_short8_sat_rtn(char8);
short8 __ovld __cnfn convert_short8(char8);
short8 __ovld __cnfn convert_short8_sat(char8);
short8 __ovld __cnfn convert_short8_rte(uchar8);
short8 __ovld __cnfn convert_short8_sat_rte(uchar8);
short8 __ovld __cnfn convert_short8_rtz(uchar8);
short8 __ovld __cnfn convert_short8_sat_rtz(uchar8);
short8 __ovld __cnfn convert_short8_rtp(uchar8);
short8 __ovld __cnfn convert_short8_sat_rtp(uchar8);
short8 __ovld __cnfn convert_short8_rtn(uchar8);
short8 __ovld __cnfn convert_short8_sat_rtn(uchar8);
short8 __ovld __cnfn convert_short8(uchar8);
short8 __ovld __cnfn convert_short8_sat(uchar8);
short8 __ovld __cnfn convert_short8_rte(short8);
short8 __ovld __cnfn convert_short8_sat_rte(short8);
short8 __ovld __cnfn convert_short8_rtz(short8);
short8 __ovld __cnfn convert_short8_sat_rtz(short8);
short8 __ovld __cnfn convert_short8_rtp(short8);
short8 __ovld __cnfn convert_short8_sat_rtp(short8);
short8 __ovld __cnfn convert_short8_rtn(short8);
short8 __ovld __cnfn convert_short8_sat_rtn(short8);
short8 __ovld __cnfn convert_short8(short8);
short8 __ovld __cnfn convert_short8_sat(short8);
short8 __ovld __cnfn convert_short8_rte(ushort8);
short8 __ovld __cnfn convert_short8_sat_rte(ushort8);
short8 __ovld __cnfn convert_short8_rtz(ushort8);
short8 __ovld __cnfn convert_short8_sat_rtz(ushort8);
short8 __ovld __cnfn convert_short8_rtp(ushort8);
short8 __ovld __cnfn convert_short8_sat_rtp(ushort8);
short8 __ovld __cnfn convert_short8_rtn(ushort8);
short8 __ovld __cnfn convert_short8_sat_rtn(ushort8);
short8 __ovld __cnfn convert_short8(ushort8);
short8 __ovld __cnfn convert_short8_sat(ushort8);
short8 __ovld __cnfn convert_short8_rte(int8);
short8 __ovld __cnfn convert_short8_sat_rte(int8);
short8 __ovld __cnfn convert_short8_rtz(int8);
short8 __ovld __cnfn convert_short8_sat_rtz(int8);
short8 __ovld __cnfn convert_short8_rtp(int8);
short8 __ovld __cnfn convert_short8_sat_rtp(int8);
short8 __ovld __cnfn convert_short8_rtn(int8);
short8 __ovld __cnfn convert_short8_sat_rtn(int8);
short8 __ovld __cnfn convert_short8(int8);
short8 __ovld __cnfn convert_short8_sat(int8);
short8 __ovld __cnfn convert_short8_rte(uint8);
short8 __ovld __cnfn convert_short8_sat_rte(uint8);
short8 __ovld __cnfn convert_short8_rtz(uint8);
short8 __ovld __cnfn convert_short8_sat_rtz(uint8);
short8 __ovld __cnfn convert_short8_rtp(uint8);
short8 __ovld __cnfn convert_short8_sat_rtp(uint8);
short8 __ovld __cnfn convert_short8_rtn(uint8);
short8 __ovld __cnfn convert_short8_sat_rtn(uint8);
short8 __ovld __cnfn convert_short8(uint8);
short8 __ovld __cnfn convert_short8_sat(uint8);
short8 __ovld __cnfn convert_short8_rte(long8);
short8 __ovld __cnfn convert_short8_sat_rte(long8);
short8 __ovld __cnfn convert_short8_rtz(long8);
short8 __ovld __cnfn convert_short8_sat_rtz(long8);
short8 __ovld __cnfn convert_short8_rtp(long8);
short8 __ovld __cnfn convert_short8_sat_rtp(long8);
short8 __ovld __cnfn convert_short8_rtn(long8);
short8 __ovld __cnfn convert_short8_sat_rtn(long8);
short8 __ovld __cnfn convert_short8(long8);
short8 __ovld __cnfn convert_short8_sat(long8);
short8 __ovld __cnfn convert_short8_rte(ulong8);
short8 __ovld __cnfn convert_short8_sat_rte(ulong8);
short8 __ovld __cnfn convert_short8_rtz(ulong8);
short8 __ovld __cnfn convert_short8_sat_rtz(ulong8);
short8 __ovld __cnfn convert_short8_rtp(ulong8);
short8 __ovld __cnfn convert_short8_sat_rtp(ulong8);
short8 __ovld __cnfn convert_short8_rtn(ulong8);
short8 __ovld __cnfn convert_short8_sat_rtn(ulong8);
short8 __ovld __cnfn convert_short8(ulong8);
short8 __ovld __cnfn convert_short8_sat(ulong8);
short8 __ovld __cnfn convert_short8_rte(float8);
short8 __ovld __cnfn convert_short8_sat_rte(float8);
short8 __ovld __cnfn convert_short8_rtz(float8);
short8 __ovld __cnfn convert_short8_sat_rtz(float8);
short8 __ovld __cnfn convert_short8_rtp(float8);
short8 __ovld __cnfn convert_short8_sat_rtp(float8);
short8 __ovld __cnfn convert_short8_rtn(float8);
short8 __ovld __cnfn convert_short8_sat_rtn(float8);
short8 __ovld __cnfn convert_short8(float8);
short8 __ovld __cnfn convert_short8_sat(float8);
ushort8 __ovld __cnfn convert_ushort8_rte(char8);
ushort8 __ovld __cnfn convert_ushort8_sat_rte(char8);
ushort8 __ovld __cnfn convert_ushort8_rtz(char8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtz(char8);
ushort8 __ovld __cnfn convert_ushort8_rtp(char8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtp(char8);
ushort8 __ovld __cnfn convert_ushort8_rtn(char8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtn(char8);
ushort8 __ovld __cnfn convert_ushort8(char8);
ushort8 __ovld __cnfn convert_ushort8_sat(char8);
ushort8 __ovld __cnfn convert_ushort8_rte(uchar8);
ushort8 __ovld __cnfn convert_ushort8_sat_rte(uchar8);
ushort8 __ovld __cnfn convert_ushort8_rtz(uchar8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtz(uchar8);
ushort8 __ovld __cnfn convert_ushort8_rtp(uchar8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtp(uchar8);
ushort8 __ovld __cnfn convert_ushort8_rtn(uchar8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtn(uchar8);
ushort8 __ovld __cnfn convert_ushort8(uchar8);
ushort8 __ovld __cnfn convert_ushort8_sat(uchar8);
ushort8 __ovld __cnfn convert_ushort8_rte(short8);
ushort8 __ovld __cnfn convert_ushort8_sat_rte(short8);
ushort8 __ovld __cnfn convert_ushort8_rtz(short8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtz(short8);
ushort8 __ovld __cnfn convert_ushort8_rtp(short8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtp(short8);
ushort8 __ovld __cnfn convert_ushort8_rtn(short8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtn(short8);
ushort8 __ovld __cnfn convert_ushort8(short8);
ushort8 __ovld __cnfn convert_ushort8_sat(short8);
ushort8 __ovld __cnfn convert_ushort8_rte(ushort8);
ushort8 __ovld __cnfn convert_ushort8_sat_rte(ushort8);
ushort8 __ovld __cnfn convert_ushort8_rtz(ushort8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtz(ushort8);
ushort8 __ovld __cnfn convert_ushort8_rtp(ushort8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtp(ushort8);
ushort8 __ovld __cnfn convert_ushort8_rtn(ushort8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtn(ushort8);
ushort8 __ovld __cnfn convert_ushort8(ushort8);
ushort8 __ovld __cnfn convert_ushort8_sat(ushort8);
ushort8 __ovld __cnfn convert_ushort8_rte(int8);
ushort8 __ovld __cnfn convert_ushort8_sat_rte(int8);
ushort8 __ovld __cnfn convert_ushort8_rtz(int8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtz(int8);
ushort8 __ovld __cnfn convert_ushort8_rtp(int8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtp(int8);
ushort8 __ovld __cnfn convert_ushort8_rtn(int8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtn(int8);
ushort8 __ovld __cnfn convert_ushort8(int8);
ushort8 __ovld __cnfn convert_ushort8_sat(int8);
ushort8 __ovld __cnfn convert_ushort8_rte(uint8);
ushort8 __ovld __cnfn convert_ushort8_sat_rte(uint8);
ushort8 __ovld __cnfn convert_ushort8_rtz(uint8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtz(uint8);
ushort8 __ovld __cnfn convert_ushort8_rtp(uint8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtp(uint8);
ushort8 __ovld __cnfn convert_ushort8_rtn(uint8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtn(uint8);
ushort8 __ovld __cnfn convert_ushort8(uint8);
ushort8 __ovld __cnfn convert_ushort8_sat(uint8);
ushort8 __ovld __cnfn convert_ushort8_rte(long8);
ushort8 __ovld __cnfn convert_ushort8_sat_rte(long8);
ushort8 __ovld __cnfn convert_ushort8_rtz(long8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtz(long8);
ushort8 __ovld __cnfn convert_ushort8_rtp(long8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtp(long8);
ushort8 __ovld __cnfn convert_ushort8_rtn(long8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtn(long8);
ushort8 __ovld __cnfn convert_ushort8(long8);
ushort8 __ovld __cnfn convert_ushort8_sat(long8);
ushort8 __ovld __cnfn convert_ushort8_rte(ulong8);
ushort8 __ovld __cnfn convert_ushort8_sat_rte(ulong8);
ushort8 __ovld __cnfn convert_ushort8_rtz(ulong8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtz(ulong8);
ushort8 __ovld __cnfn convert_ushort8_rtp(ulong8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtp(ulong8);
ushort8 __ovld __cnfn convert_ushort8_rtn(ulong8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtn(ulong8);
ushort8 __ovld __cnfn convert_ushort8(ulong8);
ushort8 __ovld __cnfn convert_ushort8_sat(ulong8);
ushort8 __ovld __cnfn convert_ushort8_rte(float8);
ushort8 __ovld __cnfn convert_ushort8_sat_rte(float8);
ushort8 __ovld __cnfn convert_ushort8_rtz(float8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtz(float8);
ushort8 __ovld __cnfn convert_ushort8_rtp(float8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtp(float8);
ushort8 __ovld __cnfn convert_ushort8_rtn(float8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtn(float8);
ushort8 __ovld __cnfn convert_ushort8(float8);
ushort8 __ovld __cnfn convert_ushort8_sat(float8);
int8 __ovld __cnfn convert_int8_rte(char8);
int8 __ovld __cnfn convert_int8_sat_rte(char8);
int8 __ovld __cnfn convert_int8_rtz(char8);
int8 __ovld __cnfn convert_int8_sat_rtz(char8);
int8 __ovld __cnfn convert_int8_rtp(char8);
int8 __ovld __cnfn convert_int8_sat_rtp(char8);
int8 __ovld __cnfn convert_int8_rtn(char8);
int8 __ovld __cnfn convert_int8_sat_rtn(char8);
int8 __ovld __cnfn convert_int8(char8);
int8 __ovld __cnfn convert_int8_sat(char8);
int8 __ovld __cnfn convert_int8_rte(uchar8);
int8 __ovld __cnfn convert_int8_sat_rte(uchar8);
int8 __ovld __cnfn convert_int8_rtz(uchar8);
int8 __ovld __cnfn convert_int8_sat_rtz(uchar8);
int8 __ovld __cnfn convert_int8_rtp(uchar8);
int8 __ovld __cnfn convert_int8_sat_rtp(uchar8);
int8 __ovld __cnfn convert_int8_rtn(uchar8);
int8 __ovld __cnfn convert_int8_sat_rtn(uchar8);
int8 __ovld __cnfn convert_int8(uchar8);
int8 __ovld __cnfn convert_int8_sat(uchar8);
int8 __ovld __cnfn convert_int8_rte(short8);
int8 __ovld __cnfn convert_int8_sat_rte(short8);
int8 __ovld __cnfn convert_int8_rtz(short8);
int8 __ovld __cnfn convert_int8_sat_rtz(short8);
int8 __ovld __cnfn convert_int8_rtp(short8);
int8 __ovld __cnfn convert_int8_sat_rtp(short8);
int8 __ovld __cnfn convert_int8_rtn(short8);
int8 __ovld __cnfn convert_int8_sat_rtn(short8);
int8 __ovld __cnfn convert_int8(short8);
int8 __ovld __cnfn convert_int8_sat(short8);
int8 __ovld __cnfn convert_int8_rte(ushort8);
int8 __ovld __cnfn convert_int8_sat_rte(ushort8);
int8 __ovld __cnfn convert_int8_rtz(ushort8);
int8 __ovld __cnfn convert_int8_sat_rtz(ushort8);
int8 __ovld __cnfn convert_int8_rtp(ushort8);
int8 __ovld __cnfn convert_int8_sat_rtp(ushort8);
int8 __ovld __cnfn convert_int8_rtn(ushort8);
int8 __ovld __cnfn convert_int8_sat_rtn(ushort8);
int8 __ovld __cnfn convert_int8(ushort8);
int8 __ovld __cnfn convert_int8_sat(ushort8);
int8 __ovld __cnfn convert_int8_rte(int8);
int8 __ovld __cnfn convert_int8_sat_rte(int8);
int8 __ovld __cnfn convert_int8_rtz(int8);
int8 __ovld __cnfn convert_int8_sat_rtz(int8);
int8 __ovld __cnfn convert_int8_rtp(int8);
int8 __ovld __cnfn convert_int8_sat_rtp(int8);
int8 __ovld __cnfn convert_int8_rtn(int8);
int8 __ovld __cnfn convert_int8_sat_rtn(int8);
int8 __ovld __cnfn convert_int8(int8);
int8 __ovld __cnfn convert_int8_sat(int8);
int8 __ovld __cnfn convert_int8_rte(uint8);
int8 __ovld __cnfn convert_int8_sat_rte(uint8);
int8 __ovld __cnfn convert_int8_rtz(uint8);
int8 __ovld __cnfn convert_int8_sat_rtz(uint8);
int8 __ovld __cnfn convert_int8_rtp(uint8);
int8 __ovld __cnfn convert_int8_sat_rtp(uint8);
int8 __ovld __cnfn convert_int8_rtn(uint8);
int8 __ovld __cnfn convert_int8_sat_rtn(uint8);
int8 __ovld __cnfn convert_int8(uint8);
int8 __ovld __cnfn convert_int8_sat(uint8);
int8 __ovld __cnfn convert_int8_rte(long8);
int8 __ovld __cnfn convert_int8_sat_rte(long8);
int8 __ovld __cnfn convert_int8_rtz(long8);
int8 __ovld __cnfn convert_int8_sat_rtz(long8);
int8 __ovld __cnfn convert_int8_rtp(long8);
int8 __ovld __cnfn convert_int8_sat_rtp(long8);
int8 __ovld __cnfn convert_int8_rtn(long8);
int8 __ovld __cnfn convert_int8_sat_rtn(long8);
int8 __ovld __cnfn convert_int8(long8);
int8 __ovld __cnfn convert_int8_sat(long8);
int8 __ovld __cnfn convert_int8_rte(ulong8);
int8 __ovld __cnfn convert_int8_sat_rte(ulong8);
int8 __ovld __cnfn convert_int8_rtz(ulong8);
int8 __ovld __cnfn convert_int8_sat_rtz(ulong8);
int8 __ovld __cnfn convert_int8_rtp(ulong8);
int8 __ovld __cnfn convert_int8_sat_rtp(ulong8);
int8 __ovld __cnfn convert_int8_rtn(ulong8);
int8 __ovld __cnfn convert_int8_sat_rtn(ulong8);
int8 __ovld __cnfn convert_int8(ulong8);
int8 __ovld __cnfn convert_int8_sat(ulong8);
int8 __ovld __cnfn convert_int8_rte(float8);
int8 __ovld __cnfn convert_int8_sat_rte(float8);
int8 __ovld __cnfn convert_int8_rtz(float8);
int8 __ovld __cnfn convert_int8_sat_rtz(float8);
int8 __ovld __cnfn convert_int8_rtp(float8);
int8 __ovld __cnfn convert_int8_sat_rtp(float8);
int8 __ovld __cnfn convert_int8_rtn(float8);
int8 __ovld __cnfn convert_int8_sat_rtn(float8);
int8 __ovld __cnfn convert_int8(float8);
int8 __ovld __cnfn convert_int8_sat(float8);
uint8 __ovld __cnfn convert_uint8_rte(char8);
uint8 __ovld __cnfn convert_uint8_sat_rte(char8);
uint8 __ovld __cnfn convert_uint8_rtz(char8);
uint8 __ovld __cnfn convert_uint8_sat_rtz(char8);
uint8 __ovld __cnfn convert_uint8_rtp(char8);
uint8 __ovld __cnfn convert_uint8_sat_rtp(char8);
uint8 __ovld __cnfn convert_uint8_rtn(char8);
uint8 __ovld __cnfn convert_uint8_sat_rtn(char8);
uint8 __ovld __cnfn convert_uint8(char8);
uint8 __ovld __cnfn convert_uint8_sat(char8);
uint8 __ovld __cnfn convert_uint8_rte(uchar8);
uint8 __ovld __cnfn convert_uint8_sat_rte(uchar8);
uint8 __ovld __cnfn convert_uint8_rtz(uchar8);
uint8 __ovld __cnfn convert_uint8_sat_rtz(uchar8);
uint8 __ovld __cnfn convert_uint8_rtp(uchar8);
uint8 __ovld __cnfn convert_uint8_sat_rtp(uchar8);
uint8 __ovld __cnfn convert_uint8_rtn(uchar8);
uint8 __ovld __cnfn convert_uint8_sat_rtn(uchar8);
uint8 __ovld __cnfn convert_uint8(uchar8);
uint8 __ovld __cnfn convert_uint8_sat(uchar8);
uint8 __ovld __cnfn convert_uint8_rte(short8);
uint8 __ovld __cnfn convert_uint8_sat_rte(short8);
uint8 __ovld __cnfn convert_uint8_rtz(short8);
uint8 __ovld __cnfn convert_uint8_sat_rtz(short8);
uint8 __ovld __cnfn convert_uint8_rtp(short8);
uint8 __ovld __cnfn convert_uint8_sat_rtp(short8);
uint8 __ovld __cnfn convert_uint8_rtn(short8);
uint8 __ovld __cnfn convert_uint8_sat_rtn(short8);
uint8 __ovld __cnfn convert_uint8(short8);
uint8 __ovld __cnfn convert_uint8_sat(short8);
uint8 __ovld __cnfn convert_uint8_rte(ushort8);
uint8 __ovld __cnfn convert_uint8_sat_rte(ushort8);
uint8 __ovld __cnfn convert_uint8_rtz(ushort8);
uint8 __ovld __cnfn convert_uint8_sat_rtz(ushort8);
uint8 __ovld __cnfn convert_uint8_rtp(ushort8);
uint8 __ovld __cnfn convert_uint8_sat_rtp(ushort8);
uint8 __ovld __cnfn convert_uint8_rtn(ushort8);
uint8 __ovld __cnfn convert_uint8_sat_rtn(ushort8);
uint8 __ovld __cnfn convert_uint8(ushort8);
uint8 __ovld __cnfn convert_uint8_sat(ushort8);
uint8 __ovld __cnfn convert_uint8_rte(int8);
uint8 __ovld __cnfn convert_uint8_sat_rte(int8);
uint8 __ovld __cnfn convert_uint8_rtz(int8);
uint8 __ovld __cnfn convert_uint8_sat_rtz(int8);
uint8 __ovld __cnfn convert_uint8_rtp(int8);
uint8 __ovld __cnfn convert_uint8_sat_rtp(int8);
uint8 __ovld __cnfn convert_uint8_rtn(int8);
uint8 __ovld __cnfn convert_uint8_sat_rtn(int8);
uint8 __ovld __cnfn convert_uint8(int8);
uint8 __ovld __cnfn convert_uint8_sat(int8);
uint8 __ovld __cnfn convert_uint8_rte(uint8);
uint8 __ovld __cnfn convert_uint8_sat_rte(uint8);
uint8 __ovld __cnfn convert_uint8_rtz(uint8);
uint8 __ovld __cnfn convert_uint8_sat_rtz(uint8);
uint8 __ovld __cnfn convert_uint8_rtp(uint8);
uint8 __ovld __cnfn convert_uint8_sat_rtp(uint8);
uint8 __ovld __cnfn convert_uint8_rtn(uint8);
uint8 __ovld __cnfn convert_uint8_sat_rtn(uint8);
uint8 __ovld __cnfn convert_uint8(uint8);
uint8 __ovld __cnfn convert_uint8_sat(uint8);
uint8 __ovld __cnfn convert_uint8_rte(long8);
uint8 __ovld __cnfn convert_uint8_sat_rte(long8);
uint8 __ovld __cnfn convert_uint8_rtz(long8);
uint8 __ovld __cnfn convert_uint8_sat_rtz(long8);
uint8 __ovld __cnfn convert_uint8_rtp(long8);
uint8 __ovld __cnfn convert_uint8_sat_rtp(long8);
uint8 __ovld __cnfn convert_uint8_rtn(long8);
uint8 __ovld __cnfn convert_uint8_sat_rtn(long8);
uint8 __ovld __cnfn convert_uint8(long8);
uint8 __ovld __cnfn convert_uint8_sat(long8);
uint8 __ovld __cnfn convert_uint8_rte(ulong8);
uint8 __ovld __cnfn convert_uint8_sat_rte(ulong8);
uint8 __ovld __cnfn convert_uint8_rtz(ulong8);
uint8 __ovld __cnfn convert_uint8_sat_rtz(ulong8);
uint8 __ovld __cnfn convert_uint8_rtp(ulong8);
uint8 __ovld __cnfn convert_uint8_sat_rtp(ulong8);
uint8 __ovld __cnfn convert_uint8_rtn(ulong8);
uint8 __ovld __cnfn convert_uint8_sat_rtn(ulong8);
uint8 __ovld __cnfn convert_uint8(ulong8);
uint8 __ovld __cnfn convert_uint8_sat(ulong8);
uint8 __ovld __cnfn convert_uint8_rte(float8);
uint8 __ovld __cnfn convert_uint8_sat_rte(float8);
uint8 __ovld __cnfn convert_uint8_rtz(float8);
uint8 __ovld __cnfn convert_uint8_sat_rtz(float8);
uint8 __ovld __cnfn convert_uint8_rtp(float8);
uint8 __ovld __cnfn convert_uint8_sat_rtp(float8);
uint8 __ovld __cnfn convert_uint8_rtn(float8);
uint8 __ovld __cnfn convert_uint8_sat_rtn(float8);
uint8 __ovld __cnfn convert_uint8(float8);
uint8 __ovld __cnfn convert_uint8_sat(float8);
long8 __ovld __cnfn convert_long8_rte(char8);
long8 __ovld __cnfn convert_long8_sat_rte(char8);
long8 __ovld __cnfn convert_long8_rtz(char8);
long8 __ovld __cnfn convert_long8_sat_rtz(char8);
long8 __ovld __cnfn convert_long8_rtp(char8);
long8 __ovld __cnfn convert_long8_sat_rtp(char8);
long8 __ovld __cnfn convert_long8_rtn(char8);
long8 __ovld __cnfn convert_long8_sat_rtn(char8);
long8 __ovld __cnfn convert_long8(char8);
long8 __ovld __cnfn convert_long8_sat(char8);
long8 __ovld __cnfn convert_long8_rte(uchar8);
long8 __ovld __cnfn convert_long8_sat_rte(uchar8);
long8 __ovld __cnfn convert_long8_rtz(uchar8);
long8 __ovld __cnfn convert_long8_sat_rtz(uchar8);
long8 __ovld __cnfn convert_long8_rtp(uchar8);
long8 __ovld __cnfn convert_long8_sat_rtp(uchar8);
long8 __ovld __cnfn convert_long8_rtn(uchar8);
long8 __ovld __cnfn convert_long8_sat_rtn(uchar8);
long8 __ovld __cnfn convert_long8(uchar8);
long8 __ovld __cnfn convert_long8_sat(uchar8);
long8 __ovld __cnfn convert_long8_rte(short8);
long8 __ovld __cnfn convert_long8_sat_rte(short8);
long8 __ovld __cnfn convert_long8_rtz(short8);
long8 __ovld __cnfn convert_long8_sat_rtz(short8);
long8 __ovld __cnfn convert_long8_rtp(short8);
long8 __ovld __cnfn convert_long8_sat_rtp(short8);
long8 __ovld __cnfn convert_long8_rtn(short8);
long8 __ovld __cnfn convert_long8_sat_rtn(short8);
long8 __ovld __cnfn convert_long8(short8);
long8 __ovld __cnfn convert_long8_sat(short8);
long8 __ovld __cnfn convert_long8_rte(ushort8);
long8 __ovld __cnfn convert_long8_sat_rte(ushort8);
long8 __ovld __cnfn convert_long8_rtz(ushort8);
long8 __ovld __cnfn convert_long8_sat_rtz(ushort8);
long8 __ovld __cnfn convert_long8_rtp(ushort8);
long8 __ovld __cnfn convert_long8_sat_rtp(ushort8);
long8 __ovld __cnfn convert_long8_rtn(ushort8);
long8 __ovld __cnfn convert_long8_sat_rtn(ushort8);
long8 __ovld __cnfn convert_long8(ushort8);
long8 __ovld __cnfn convert_long8_sat(ushort8);
long8 __ovld __cnfn convert_long8_rte(int8);
long8 __ovld __cnfn convert_long8_sat_rte(int8);
long8 __ovld __cnfn convert_long8_rtz(int8);
long8 __ovld __cnfn convert_long8_sat_rtz(int8);
long8 __ovld __cnfn convert_long8_rtp(int8);
long8 __ovld __cnfn convert_long8_sat_rtp(int8);
long8 __ovld __cnfn convert_long8_rtn(int8);
long8 __ovld __cnfn convert_long8_sat_rtn(int8);
long8 __ovld __cnfn convert_long8(int8);
long8 __ovld __cnfn convert_long8_sat(int8);
long8 __ovld __cnfn convert_long8_rte(uint8);
long8 __ovld __cnfn convert_long8_sat_rte(uint8);
long8 __ovld __cnfn convert_long8_rtz(uint8);
long8 __ovld __cnfn convert_long8_sat_rtz(uint8);
long8 __ovld __cnfn convert_long8_rtp(uint8);
long8 __ovld __cnfn convert_long8_sat_rtp(uint8);
long8 __ovld __cnfn convert_long8_rtn(uint8);
long8 __ovld __cnfn convert_long8_sat_rtn(uint8);
long8 __ovld __cnfn convert_long8(uint8);
long8 __ovld __cnfn convert_long8_sat(uint8);
long8 __ovld __cnfn convert_long8_rte(long8);
long8 __ovld __cnfn convert_long8_sat_rte(long8);
long8 __ovld __cnfn convert_long8_rtz(long8);
long8 __ovld __cnfn convert_long8_sat_rtz(long8);
long8 __ovld __cnfn convert_long8_rtp(long8);
long8 __ovld __cnfn convert_long8_sat_rtp(long8);
long8 __ovld __cnfn convert_long8_rtn(long8);
long8 __ovld __cnfn convert_long8_sat_rtn(long8);
long8 __ovld __cnfn convert_long8(long8);
long8 __ovld __cnfn convert_long8_sat(long8);
long8 __ovld __cnfn convert_long8_rte(ulong8);
long8 __ovld __cnfn convert_long8_sat_rte(ulong8);
long8 __ovld __cnfn convert_long8_rtz(ulong8);
long8 __ovld __cnfn convert_long8_sat_rtz(ulong8);
long8 __ovld __cnfn convert_long8_rtp(ulong8);
long8 __ovld __cnfn convert_long8_sat_rtp(ulong8);
long8 __ovld __cnfn convert_long8_rtn(ulong8);
long8 __ovld __cnfn convert_long8_sat_rtn(ulong8);
long8 __ovld __cnfn convert_long8(ulong8);
long8 __ovld __cnfn convert_long8_sat(ulong8);
long8 __ovld __cnfn convert_long8_rte(float8);
long8 __ovld __cnfn convert_long8_sat_rte(float8);
long8 __ovld __cnfn convert_long8_rtz(float8);
long8 __ovld __cnfn convert_long8_sat_rtz(float8);
long8 __ovld __cnfn convert_long8_rtp(float8);
long8 __ovld __cnfn convert_long8_sat_rtp(float8);
long8 __ovld __cnfn convert_long8_rtn(float8);
long8 __ovld __cnfn convert_long8_sat_rtn(float8);
long8 __ovld __cnfn convert_long8(float8);
long8 __ovld __cnfn convert_long8_sat(float8);
ulong8 __ovld __cnfn convert_ulong8_rte(char8);
ulong8 __ovld __cnfn convert_ulong8_sat_rte(char8);
ulong8 __ovld __cnfn convert_ulong8_rtz(char8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtz(char8);
ulong8 __ovld __cnfn convert_ulong8_rtp(char8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtp(char8);
ulong8 __ovld __cnfn convert_ulong8_rtn(char8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtn(char8);
ulong8 __ovld __cnfn convert_ulong8(char8);
ulong8 __ovld __cnfn convert_ulong8_sat(char8);
ulong8 __ovld __cnfn convert_ulong8_rte(uchar8);
ulong8 __ovld __cnfn convert_ulong8_sat_rte(uchar8);
ulong8 __ovld __cnfn convert_ulong8_rtz(uchar8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtz(uchar8);
ulong8 __ovld __cnfn convert_ulong8_rtp(uchar8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtp(uchar8);
ulong8 __ovld __cnfn convert_ulong8_rtn(uchar8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtn(uchar8);
ulong8 __ovld __cnfn convert_ulong8(uchar8);
ulong8 __ovld __cnfn convert_ulong8_sat(uchar8);
ulong8 __ovld __cnfn convert_ulong8_rte(short8);
ulong8 __ovld __cnfn convert_ulong8_sat_rte(short8);
ulong8 __ovld __cnfn convert_ulong8_rtz(short8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtz(short8);
ulong8 __ovld __cnfn convert_ulong8_rtp(short8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtp(short8);
ulong8 __ovld __cnfn convert_ulong8_rtn(short8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtn(short8);
ulong8 __ovld __cnfn convert_ulong8(short8);
ulong8 __ovld __cnfn convert_ulong8_sat(short8);
ulong8 __ovld __cnfn convert_ulong8_rte(ushort8);
ulong8 __ovld __cnfn convert_ulong8_sat_rte(ushort8);
ulong8 __ovld __cnfn convert_ulong8_rtz(ushort8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtz(ushort8);
ulong8 __ovld __cnfn convert_ulong8_rtp(ushort8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtp(ushort8);
ulong8 __ovld __cnfn convert_ulong8_rtn(ushort8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtn(ushort8);
ulong8 __ovld __cnfn convert_ulong8(ushort8);
ulong8 __ovld __cnfn convert_ulong8_sat(ushort8);
ulong8 __ovld __cnfn convert_ulong8_rte(int8);
ulong8 __ovld __cnfn convert_ulong8_sat_rte(int8);
ulong8 __ovld __cnfn convert_ulong8_rtz(int8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtz(int8);
ulong8 __ovld __cnfn convert_ulong8_rtp(int8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtp(int8);
ulong8 __ovld __cnfn convert_ulong8_rtn(int8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtn(int8);
ulong8 __ovld __cnfn convert_ulong8(int8);
ulong8 __ovld __cnfn convert_ulong8_sat(int8);
ulong8 __ovld __cnfn convert_ulong8_rte(uint8);
ulong8 __ovld __cnfn convert_ulong8_sat_rte(uint8);
ulong8 __ovld __cnfn convert_ulong8_rtz(uint8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtz(uint8);
ulong8 __ovld __cnfn convert_ulong8_rtp(uint8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtp(uint8);
ulong8 __ovld __cnfn convert_ulong8_rtn(uint8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtn(uint8);
ulong8 __ovld __cnfn convert_ulong8(uint8);
ulong8 __ovld __cnfn convert_ulong8_sat(uint8);
ulong8 __ovld __cnfn convert_ulong8_rte(long8);
ulong8 __ovld __cnfn convert_ulong8_sat_rte(long8);
ulong8 __ovld __cnfn convert_ulong8_rtz(long8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtz(long8);
ulong8 __ovld __cnfn convert_ulong8_rtp(long8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtp(long8);
ulong8 __ovld __cnfn convert_ulong8_rtn(long8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtn(long8);
ulong8 __ovld __cnfn convert_ulong8(long8);
ulong8 __ovld __cnfn convert_ulong8_sat(long8);
ulong8 __ovld __cnfn convert_ulong8_rte(ulong8);
ulong8 __ovld __cnfn convert_ulong8_sat_rte(ulong8);
ulong8 __ovld __cnfn convert_ulong8_rtz(ulong8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtz(ulong8);
ulong8 __ovld __cnfn convert_ulong8_rtp(ulong8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtp(ulong8);
ulong8 __ovld __cnfn convert_ulong8_rtn(ulong8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtn(ulong8);
ulong8 __ovld __cnfn convert_ulong8(ulong8);
ulong8 __ovld __cnfn convert_ulong8_sat(ulong8);
ulong8 __ovld __cnfn convert_ulong8_rte(float8);
ulong8 __ovld __cnfn convert_ulong8_sat_rte(float8);
ulong8 __ovld __cnfn convert_ulong8_rtz(float8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtz(float8);
ulong8 __ovld __cnfn convert_ulong8_rtp(float8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtp(float8);
ulong8 __ovld __cnfn convert_ulong8_rtn(float8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtn(float8);
ulong8 __ovld __cnfn convert_ulong8(float8);
ulong8 __ovld __cnfn convert_ulong8_sat(float8);
float8 __ovld __cnfn convert_float8_rte(char8);
float8 __ovld __cnfn convert_float8_rtz(char8);
float8 __ovld __cnfn convert_float8_rtp(char8);
float8 __ovld __cnfn convert_float8_rtn(char8);
float8 __ovld __cnfn convert_float8(char8);
float8 __ovld __cnfn convert_float8_rte(uchar8);
float8 __ovld __cnfn convert_float8_rtz(uchar8);
float8 __ovld __cnfn convert_float8_rtp(uchar8);
float8 __ovld __cnfn convert_float8_rtn(uchar8);
float8 __ovld __cnfn convert_float8(uchar8);
float8 __ovld __cnfn convert_float8_rte(short8);
float8 __ovld __cnfn convert_float8_rtz(short8);
float8 __ovld __cnfn convert_float8_rtp(short8);
float8 __ovld __cnfn convert_float8_rtn(short8);
float8 __ovld __cnfn convert_float8(short8);
float8 __ovld __cnfn convert_float8_rte(ushort8);
float8 __ovld __cnfn convert_float8_rtz(ushort8);
float8 __ovld __cnfn convert_float8_rtp(ushort8);
float8 __ovld __cnfn convert_float8_rtn(ushort8);
float8 __ovld __cnfn convert_float8(ushort8);
float8 __ovld __cnfn convert_float8_rte(int8);
float8 __ovld __cnfn convert_float8_rtz(int8);
float8 __ovld __cnfn convert_float8_rtp(int8);
float8 __ovld __cnfn convert_float8_rtn(int8);
float8 __ovld __cnfn convert_float8(int8);
float8 __ovld __cnfn convert_float8_rte(uint8);
float8 __ovld __cnfn convert_float8_rtz(uint8);
float8 __ovld __cnfn convert_float8_rtp(uint8);
float8 __ovld __cnfn convert_float8_rtn(uint8);
float8 __ovld __cnfn convert_float8(uint8);
float8 __ovld __cnfn convert_float8_rte(long8);
float8 __ovld __cnfn convert_float8_rtz(long8);
float8 __ovld __cnfn convert_float8_rtp(long8);
float8 __ovld __cnfn convert_float8_rtn(long8);
float8 __ovld __cnfn convert_float8(long8);
float8 __ovld __cnfn convert_float8_rte(ulong8);
float8 __ovld __cnfn convert_float8_rtz(ulong8);
float8 __ovld __cnfn convert_float8_rtp(ulong8);
float8 __ovld __cnfn convert_float8_rtn(ulong8);
float8 __ovld __cnfn convert_float8(ulong8);
float8 __ovld __cnfn convert_float8_rte(float8);
float8 __ovld __cnfn convert_float8_rtz(float8);
float8 __ovld __cnfn convert_float8_rtp(float8);
float8 __ovld __cnfn convert_float8_rtn(float8);
float8 __ovld __cnfn convert_float8(float8);
char16 __ovld __cnfn convert_char16_rte(char16);
char16 __ovld __cnfn convert_char16_sat_rte(char16);
char16 __ovld __cnfn convert_char16_rtz(char16);
char16 __ovld __cnfn convert_char16_sat_rtz(char16);
char16 __ovld __cnfn convert_char16_rtp(char16);
char16 __ovld __cnfn convert_char16_sat_rtp(char16);
char16 __ovld __cnfn convert_char16_rtn(char16);
char16 __ovld __cnfn convert_char16_sat_rtn(char16);
char16 __ovld __cnfn convert_char16(char16);
char16 __ovld __cnfn convert_char16_sat(char16);
char16 __ovld __cnfn convert_char16_rte(uchar16);
char16 __ovld __cnfn convert_char16_sat_rte(uchar16);
char16 __ovld __cnfn convert_char16_rtz(uchar16);
char16 __ovld __cnfn convert_char16_sat_rtz(uchar16);
char16 __ovld __cnfn convert_char16_rtp(uchar16);
char16 __ovld __cnfn convert_char16_sat_rtp(uchar16);
char16 __ovld __cnfn convert_char16_rtn(uchar16);
char16 __ovld __cnfn convert_char16_sat_rtn(uchar16);
char16 __ovld __cnfn convert_char16(uchar16);
char16 __ovld __cnfn convert_char16_sat(uchar16);
char16 __ovld __cnfn convert_char16_rte(short16);
char16 __ovld __cnfn convert_char16_sat_rte(short16);
char16 __ovld __cnfn convert_char16_rtz(short16);
char16 __ovld __cnfn convert_char16_sat_rtz(short16);
char16 __ovld __cnfn convert_char16_rtp(short16);
char16 __ovld __cnfn convert_char16_sat_rtp(short16);
char16 __ovld __cnfn convert_char16_rtn(short16);
char16 __ovld __cnfn convert_char16_sat_rtn(short16);
char16 __ovld __cnfn convert_char16(short16);
char16 __ovld __cnfn convert_char16_sat(short16);
char16 __ovld __cnfn convert_char16_rte(ushort16);
char16 __ovld __cnfn convert_char16_sat_rte(ushort16);
char16 __ovld __cnfn convert_char16_rtz(ushort16);
char16 __ovld __cnfn convert_char16_sat_rtz(ushort16);
char16 __ovld __cnfn convert_char16_rtp(ushort16);
char16 __ovld __cnfn convert_char16_sat_rtp(ushort16);
char16 __ovld __cnfn convert_char16_rtn(ushort16);
char16 __ovld __cnfn convert_char16_sat_rtn(ushort16);
char16 __ovld __cnfn convert_char16(ushort16);
char16 __ovld __cnfn convert_char16_sat(ushort16);
char16 __ovld __cnfn convert_char16_rte(int16);
char16 __ovld __cnfn convert_char16_sat_rte(int16);
char16 __ovld __cnfn convert_char16_rtz(int16);
char16 __ovld __cnfn convert_char16_sat_rtz(int16);
char16 __ovld __cnfn convert_char16_rtp(int16);
char16 __ovld __cnfn convert_char16_sat_rtp(int16);
char16 __ovld __cnfn convert_char16_rtn(int16);
char16 __ovld __cnfn convert_char16_sat_rtn(int16);
char16 __ovld __cnfn convert_char16(int16);
char16 __ovld __cnfn convert_char16_sat(int16);
char16 __ovld __cnfn convert_char16_rte(uint16);
char16 __ovld __cnfn convert_char16_sat_rte(uint16);
char16 __ovld __cnfn convert_char16_rtz(uint16);
char16 __ovld __cnfn convert_char16_sat_rtz(uint16);
char16 __ovld __cnfn convert_char16_rtp(uint16);
char16 __ovld __cnfn convert_char16_sat_rtp(uint16);
char16 __ovld __cnfn convert_char16_rtn(uint16);
char16 __ovld __cnfn convert_char16_sat_rtn(uint16);
char16 __ovld __cnfn convert_char16(uint16);
char16 __ovld __cnfn convert_char16_sat(uint16);
char16 __ovld __cnfn convert_char16_rte(long16);
char16 __ovld __cnfn convert_char16_sat_rte(long16);
char16 __ovld __cnfn convert_char16_rtz(long16);
char16 __ovld __cnfn convert_char16_sat_rtz(long16);
char16 __ovld __cnfn convert_char16_rtp(long16);
char16 __ovld __cnfn convert_char16_sat_rtp(long16);
char16 __ovld __cnfn convert_char16_rtn(long16);
char16 __ovld __cnfn convert_char16_sat_rtn(long16);
char16 __ovld __cnfn convert_char16(long16);
char16 __ovld __cnfn convert_char16_sat(long16);
char16 __ovld __cnfn convert_char16_rte(ulong16);
char16 __ovld __cnfn convert_char16_sat_rte(ulong16);
char16 __ovld __cnfn convert_char16_rtz(ulong16);
char16 __ovld __cnfn convert_char16_sat_rtz(ulong16);
char16 __ovld __cnfn convert_char16_rtp(ulong16);
char16 __ovld __cnfn convert_char16_sat_rtp(ulong16);
char16 __ovld __cnfn convert_char16_rtn(ulong16);
char16 __ovld __cnfn convert_char16_sat_rtn(ulong16);
char16 __ovld __cnfn convert_char16(ulong16);
char16 __ovld __cnfn convert_char16_sat(ulong16);
char16 __ovld __cnfn convert_char16_rte(float16);
char16 __ovld __cnfn convert_char16_sat_rte(float16);
char16 __ovld __cnfn convert_char16_rtz(float16);
char16 __ovld __cnfn convert_char16_sat_rtz(float16);
char16 __ovld __cnfn convert_char16_rtp(float16);
char16 __ovld __cnfn convert_char16_sat_rtp(float16);
char16 __ovld __cnfn convert_char16_rtn(float16);
char16 __ovld __cnfn convert_char16_sat_rtn(float16);
char16 __ovld __cnfn convert_char16(float16);
char16 __ovld __cnfn convert_char16_sat(float16);
uchar16 __ovld __cnfn convert_uchar16_rte(char16);
uchar16 __ovld __cnfn convert_uchar16_sat_rte(char16);
uchar16 __ovld __cnfn convert_uchar16_rtz(char16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtz(char16);
uchar16 __ovld __cnfn convert_uchar16_rtp(char16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtp(char16);
uchar16 __ovld __cnfn convert_uchar16_rtn(char16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtn(char16);
uchar16 __ovld __cnfn convert_uchar16(char16);
uchar16 __ovld __cnfn convert_uchar16_sat(char16);
uchar16 __ovld __cnfn convert_uchar16_rte(uchar16);
uchar16 __ovld __cnfn convert_uchar16_sat_rte(uchar16);
uchar16 __ovld __cnfn convert_uchar16_rtz(uchar16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtz(uchar16);
uchar16 __ovld __cnfn convert_uchar16_rtp(uchar16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtp(uchar16);
uchar16 __ovld __cnfn convert_uchar16_rtn(uchar16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtn(uchar16);
uchar16 __ovld __cnfn convert_uchar16(uchar16);
uchar16 __ovld __cnfn convert_uchar16_sat(uchar16);
uchar16 __ovld __cnfn convert_uchar16_rte(short16);
uchar16 __ovld __cnfn convert_uchar16_sat_rte(short16);
uchar16 __ovld __cnfn convert_uchar16_rtz(short16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtz(short16);
uchar16 __ovld __cnfn convert_uchar16_rtp(short16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtp(short16);
uchar16 __ovld __cnfn convert_uchar16_rtn(short16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtn(short16);
uchar16 __ovld __cnfn convert_uchar16(short16);
uchar16 __ovld __cnfn convert_uchar16_sat(short16);
uchar16 __ovld __cnfn convert_uchar16_rte(ushort16);
uchar16 __ovld __cnfn convert_uchar16_sat_rte(ushort16);
uchar16 __ovld __cnfn convert_uchar16_rtz(ushort16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtz(ushort16);
uchar16 __ovld __cnfn convert_uchar16_rtp(ushort16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtp(ushort16);
uchar16 __ovld __cnfn convert_uchar16_rtn(ushort16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtn(ushort16);
uchar16 __ovld __cnfn convert_uchar16(ushort16);
uchar16 __ovld __cnfn convert_uchar16_sat(ushort16);
uchar16 __ovld __cnfn convert_uchar16_rte(int16);
uchar16 __ovld __cnfn convert_uchar16_sat_rte(int16);
uchar16 __ovld __cnfn convert_uchar16_rtz(int16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtz(int16);
uchar16 __ovld __cnfn convert_uchar16_rtp(int16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtp(int16);
uchar16 __ovld __cnfn convert_uchar16_rtn(int16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtn(int16);
uchar16 __ovld __cnfn convert_uchar16(int16);
uchar16 __ovld __cnfn convert_uchar16_sat(int16);
uchar16 __ovld __cnfn convert_uchar16_rte(uint16);
uchar16 __ovld __cnfn convert_uchar16_sat_rte(uint16);
uchar16 __ovld __cnfn convert_uchar16_rtz(uint16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtz(uint16);
uchar16 __ovld __cnfn convert_uchar16_rtp(uint16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtp(uint16);
uchar16 __ovld __cnfn convert_uchar16_rtn(uint16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtn(uint16);
uchar16 __ovld __cnfn convert_uchar16(uint16);
uchar16 __ovld __cnfn convert_uchar16_sat(uint16);
uchar16 __ovld __cnfn convert_uchar16_rte(long16);
uchar16 __ovld __cnfn convert_uchar16_sat_rte(long16);
uchar16 __ovld __cnfn convert_uchar16_rtz(long16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtz(long16);
uchar16 __ovld __cnfn convert_uchar16_rtp(long16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtp(long16);
uchar16 __ovld __cnfn convert_uchar16_rtn(long16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtn(long16);
uchar16 __ovld __cnfn convert_uchar16(long16);
uchar16 __ovld __cnfn convert_uchar16_sat(long16);
uchar16 __ovld __cnfn convert_uchar16_rte(ulong16);
uchar16 __ovld __cnfn convert_uchar16_sat_rte(ulong16);
uchar16 __ovld __cnfn convert_uchar16_rtz(ulong16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtz(ulong16);
uchar16 __ovld __cnfn convert_uchar16_rtp(ulong16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtp(ulong16);
uchar16 __ovld __cnfn convert_uchar16_rtn(ulong16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtn(ulong16);
uchar16 __ovld __cnfn convert_uchar16(ulong16);
uchar16 __ovld __cnfn convert_uchar16_sat(ulong16);
uchar16 __ovld __cnfn convert_uchar16_rte(float16);
uchar16 __ovld __cnfn convert_uchar16_sat_rte(float16);
uchar16 __ovld __cnfn convert_uchar16_rtz(float16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtz(float16);
uchar16 __ovld __cnfn convert_uchar16_rtp(float16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtp(float16);
uchar16 __ovld __cnfn convert_uchar16_rtn(float16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtn(float16);
uchar16 __ovld __cnfn convert_uchar16(float16);
uchar16 __ovld __cnfn convert_uchar16_sat(float16);
short16 __ovld __cnfn convert_short16_rte(char16);
short16 __ovld __cnfn convert_short16_sat_rte(char16);
short16 __ovld __cnfn convert_short16_rtz(char16);
short16 __ovld __cnfn convert_short16_sat_rtz(char16);
short16 __ovld __cnfn convert_short16_rtp(char16);
short16 __ovld __cnfn convert_short16_sat_rtp(char16);
short16 __ovld __cnfn convert_short16_rtn(char16);
short16 __ovld __cnfn convert_short16_sat_rtn(char16);
short16 __ovld __cnfn convert_short16(char16);
short16 __ovld __cnfn convert_short16_sat(char16);
short16 __ovld __cnfn convert_short16_rte(uchar16);
short16 __ovld __cnfn convert_short16_sat_rte(uchar16);
short16 __ovld __cnfn convert_short16_rtz(uchar16);
short16 __ovld __cnfn convert_short16_sat_rtz(uchar16);
short16 __ovld __cnfn convert_short16_rtp(uchar16);
short16 __ovld __cnfn convert_short16_sat_rtp(uchar16);
short16 __ovld __cnfn convert_short16_rtn(uchar16);
short16 __ovld __cnfn convert_short16_sat_rtn(uchar16);
short16 __ovld __cnfn convert_short16(uchar16);
short16 __ovld __cnfn convert_short16_sat(uchar16);
short16 __ovld __cnfn convert_short16_rte(short16);
short16 __ovld __cnfn convert_short16_sat_rte(short16);
short16 __ovld __cnfn convert_short16_rtz(short16);
short16 __ovld __cnfn convert_short16_sat_rtz(short16);
short16 __ovld __cnfn convert_short16_rtp(short16);
short16 __ovld __cnfn convert_short16_sat_rtp(short16);
short16 __ovld __cnfn convert_short16_rtn(short16);
short16 __ovld __cnfn convert_short16_sat_rtn(short16);
short16 __ovld __cnfn convert_short16(short16);
short16 __ovld __cnfn convert_short16_sat(short16);
short16 __ovld __cnfn convert_short16_rte(ushort16);
short16 __ovld __cnfn convert_short16_sat_rte(ushort16);
short16 __ovld __cnfn convert_short16_rtz(ushort16);
short16 __ovld __cnfn convert_short16_sat_rtz(ushort16);
short16 __ovld __cnfn convert_short16_rtp(ushort16);
short16 __ovld __cnfn convert_short16_sat_rtp(ushort16);
short16 __ovld __cnfn convert_short16_rtn(ushort16);
short16 __ovld __cnfn convert_short16_sat_rtn(ushort16);
short16 __ovld __cnfn convert_short16(ushort16);
short16 __ovld __cnfn convert_short16_sat(ushort16);
short16 __ovld __cnfn convert_short16_rte(int16);
short16 __ovld __cnfn convert_short16_sat_rte(int16);
short16 __ovld __cnfn convert_short16_rtz(int16);
short16 __ovld __cnfn convert_short16_sat_rtz(int16);
short16 __ovld __cnfn convert_short16_rtp(int16);
short16 __ovld __cnfn convert_short16_sat_rtp(int16);
short16 __ovld __cnfn convert_short16_rtn(int16);
short16 __ovld __cnfn convert_short16_sat_rtn(int16);
short16 __ovld __cnfn convert_short16(int16);
short16 __ovld __cnfn convert_short16_sat(int16);
short16 __ovld __cnfn convert_short16_rte(uint16);
short16 __ovld __cnfn convert_short16_sat_rte(uint16);
short16 __ovld __cnfn convert_short16_rtz(uint16);
short16 __ovld __cnfn convert_short16_sat_rtz(uint16);
short16 __ovld __cnfn convert_short16_rtp(uint16);
short16 __ovld __cnfn convert_short16_sat_rtp(uint16);
short16 __ovld __cnfn convert_short16_rtn(uint16);
short16 __ovld __cnfn convert_short16_sat_rtn(uint16);
short16 __ovld __cnfn convert_short16(uint16);
short16 __ovld __cnfn convert_short16_sat(uint16);
short16 __ovld __cnfn convert_short16_rte(long16);
short16 __ovld __cnfn convert_short16_sat_rte(long16);
short16 __ovld __cnfn convert_short16_rtz(long16);
short16 __ovld __cnfn convert_short16_sat_rtz(long16);
short16 __ovld __cnfn convert_short16_rtp(long16);
short16 __ovld __cnfn convert_short16_sat_rtp(long16);
short16 __ovld __cnfn convert_short16_rtn(long16);
short16 __ovld __cnfn convert_short16_sat_rtn(long16);
short16 __ovld __cnfn convert_short16(long16);
short16 __ovld __cnfn convert_short16_sat(long16);
short16 __ovld __cnfn convert_short16_rte(ulong16);
short16 __ovld __cnfn convert_short16_sat_rte(ulong16);
short16 __ovld __cnfn convert_short16_rtz(ulong16);
short16 __ovld __cnfn convert_short16_sat_rtz(ulong16);
short16 __ovld __cnfn convert_short16_rtp(ulong16);
short16 __ovld __cnfn convert_short16_sat_rtp(ulong16);
short16 __ovld __cnfn convert_short16_rtn(ulong16);
short16 __ovld __cnfn convert_short16_sat_rtn(ulong16);
short16 __ovld __cnfn convert_short16(ulong16);
short16 __ovld __cnfn convert_short16_sat(ulong16);
short16 __ovld __cnfn convert_short16_rte(float16);
short16 __ovld __cnfn convert_short16_sat_rte(float16);
short16 __ovld __cnfn convert_short16_rtz(float16);
short16 __ovld __cnfn convert_short16_sat_rtz(float16);
short16 __ovld __cnfn convert_short16_rtp(float16);
short16 __ovld __cnfn convert_short16_sat_rtp(float16);
short16 __ovld __cnfn convert_short16_rtn(float16);
short16 __ovld __cnfn convert_short16_sat_rtn(float16);
short16 __ovld __cnfn convert_short16(float16);
short16 __ovld __cnfn convert_short16_sat(float16);
ushort16 __ovld __cnfn convert_ushort16_rte(char16);
ushort16 __ovld __cnfn convert_ushort16_sat_rte(char16);
ushort16 __ovld __cnfn convert_ushort16_rtz(char16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtz(char16);
ushort16 __ovld __cnfn convert_ushort16_rtp(char16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtp(char16);
ushort16 __ovld __cnfn convert_ushort16_rtn(char16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtn(char16);
ushort16 __ovld __cnfn convert_ushort16(char16);
ushort16 __ovld __cnfn convert_ushort16_sat(char16);
ushort16 __ovld __cnfn convert_ushort16_rte(uchar16);
ushort16 __ovld __cnfn convert_ushort16_sat_rte(uchar16);
ushort16 __ovld __cnfn convert_ushort16_rtz(uchar16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtz(uchar16);
ushort16 __ovld __cnfn convert_ushort16_rtp(uchar16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtp(uchar16);
ushort16 __ovld __cnfn convert_ushort16_rtn(uchar16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtn(uchar16);
ushort16 __ovld __cnfn convert_ushort16(uchar16);
ushort16 __ovld __cnfn convert_ushort16_sat(uchar16);
ushort16 __ovld __cnfn convert_ushort16_rte(short16);
ushort16 __ovld __cnfn convert_ushort16_sat_rte(short16);
ushort16 __ovld __cnfn convert_ushort16_rtz(short16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtz(short16);
ushort16 __ovld __cnfn convert_ushort16_rtp(short16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtp(short16);
ushort16 __ovld __cnfn convert_ushort16_rtn(short16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtn(short16);
ushort16 __ovld __cnfn convert_ushort16(short16);
ushort16 __ovld __cnfn convert_ushort16_sat(short16);
ushort16 __ovld __cnfn convert_ushort16_rte(ushort16);
ushort16 __ovld __cnfn convert_ushort16_sat_rte(ushort16);
ushort16 __ovld __cnfn convert_ushort16_rtz(ushort16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtz(ushort16);
ushort16 __ovld __cnfn convert_ushort16_rtp(ushort16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtp(ushort16);
ushort16 __ovld __cnfn convert_ushort16_rtn(ushort16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtn(ushort16);
ushort16 __ovld __cnfn convert_ushort16(ushort16);
ushort16 __ovld __cnfn convert_ushort16_sat(ushort16);
ushort16 __ovld __cnfn convert_ushort16_rte(int16);
ushort16 __ovld __cnfn convert_ushort16_sat_rte(int16);
ushort16 __ovld __cnfn convert_ushort16_rtz(int16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtz(int16);
ushort16 __ovld __cnfn convert_ushort16_rtp(int16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtp(int16);
ushort16 __ovld __cnfn convert_ushort16_rtn(int16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtn(int16);
ushort16 __ovld __cnfn convert_ushort16(int16);
ushort16 __ovld __cnfn convert_ushort16_sat(int16);
ushort16 __ovld __cnfn convert_ushort16_rte(uint16);
ushort16 __ovld __cnfn convert_ushort16_sat_rte(uint16);
ushort16 __ovld __cnfn convert_ushort16_rtz(uint16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtz(uint16);
ushort16 __ovld __cnfn convert_ushort16_rtp(uint16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtp(uint16);
ushort16 __ovld __cnfn convert_ushort16_rtn(uint16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtn(uint16);
ushort16 __ovld __cnfn convert_ushort16(uint16);
ushort16 __ovld __cnfn convert_ushort16_sat(uint16);
ushort16 __ovld __cnfn convert_ushort16_rte(long16);
ushort16 __ovld __cnfn convert_ushort16_sat_rte(long16);
ushort16 __ovld __cnfn convert_ushort16_rtz(long16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtz(long16);
ushort16 __ovld __cnfn convert_ushort16_rtp(long16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtp(long16);
ushort16 __ovld __cnfn convert_ushort16_rtn(long16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtn(long16);
ushort16 __ovld __cnfn convert_ushort16(long16);
ushort16 __ovld __cnfn convert_ushort16_sat(long16);
ushort16 __ovld __cnfn convert_ushort16_rte(ulong16);
ushort16 __ovld __cnfn convert_ushort16_sat_rte(ulong16);
ushort16 __ovld __cnfn convert_ushort16_rtz(ulong16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtz(ulong16);
ushort16 __ovld __cnfn convert_ushort16_rtp(ulong16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtp(ulong16);
ushort16 __ovld __cnfn convert_ushort16_rtn(ulong16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtn(ulong16);
ushort16 __ovld __cnfn convert_ushort16(ulong16);
ushort16 __ovld __cnfn convert_ushort16_sat(ulong16);
ushort16 __ovld __cnfn convert_ushort16_rte(float16);
ushort16 __ovld __cnfn convert_ushort16_sat_rte(float16);
ushort16 __ovld __cnfn convert_ushort16_rtz(float16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtz(float16);
ushort16 __ovld __cnfn convert_ushort16_rtp(float16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtp(float16);
ushort16 __ovld __cnfn convert_ushort16_rtn(float16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtn(float16);
ushort16 __ovld __cnfn convert_ushort16(float16);
ushort16 __ovld __cnfn convert_ushort16_sat(float16);
int16 __ovld __cnfn convert_int16_rte(char16);
int16 __ovld __cnfn convert_int16_sat_rte(char16);
int16 __ovld __cnfn convert_int16_rtz(char16);
int16 __ovld __cnfn convert_int16_sat_rtz(char16);
int16 __ovld __cnfn convert_int16_rtp(char16);
int16 __ovld __cnfn convert_int16_sat_rtp(char16);
int16 __ovld __cnfn convert_int16_rtn(char16);
int16 __ovld __cnfn convert_int16_sat_rtn(char16);
int16 __ovld __cnfn convert_int16(char16);
int16 __ovld __cnfn convert_int16_sat(char16);
int16 __ovld __cnfn convert_int16_rte(uchar16);
int16 __ovld __cnfn convert_int16_sat_rte(uchar16);
int16 __ovld __cnfn convert_int16_rtz(uchar16);
int16 __ovld __cnfn convert_int16_sat_rtz(uchar16);
int16 __ovld __cnfn convert_int16_rtp(uchar16);
int16 __ovld __cnfn convert_int16_sat_rtp(uchar16);
int16 __ovld __cnfn convert_int16_rtn(uchar16);
int16 __ovld __cnfn convert_int16_sat_rtn(uchar16);
int16 __ovld __cnfn convert_int16(uchar16);
int16 __ovld __cnfn convert_int16_sat(uchar16);
int16 __ovld __cnfn convert_int16_rte(short16);
int16 __ovld __cnfn convert_int16_sat_rte(short16);
int16 __ovld __cnfn convert_int16_rtz(short16);
int16 __ovld __cnfn convert_int16_sat_rtz(short16);
int16 __ovld __cnfn convert_int16_rtp(short16);
int16 __ovld __cnfn convert_int16_sat_rtp(short16);
int16 __ovld __cnfn convert_int16_rtn(short16);
int16 __ovld __cnfn convert_int16_sat_rtn(short16);
int16 __ovld __cnfn convert_int16(short16);
int16 __ovld __cnfn convert_int16_sat(short16);
int16 __ovld __cnfn convert_int16_rte(ushort16);
int16 __ovld __cnfn convert_int16_sat_rte(ushort16);
int16 __ovld __cnfn convert_int16_rtz(ushort16);
int16 __ovld __cnfn convert_int16_sat_rtz(ushort16);
int16 __ovld __cnfn convert_int16_rtp(ushort16);
int16 __ovld __cnfn convert_int16_sat_rtp(ushort16);
int16 __ovld __cnfn convert_int16_rtn(ushort16);
int16 __ovld __cnfn convert_int16_sat_rtn(ushort16);
int16 __ovld __cnfn convert_int16(ushort16);
int16 __ovld __cnfn convert_int16_sat(ushort16);
int16 __ovld __cnfn convert_int16_rte(int16);
int16 __ovld __cnfn convert_int16_sat_rte(int16);
int16 __ovld __cnfn convert_int16_rtz(int16);
int16 __ovld __cnfn convert_int16_sat_rtz(int16);
int16 __ovld __cnfn convert_int16_rtp(int16);
int16 __ovld __cnfn convert_int16_sat_rtp(int16);
int16 __ovld __cnfn convert_int16_rtn(int16);
int16 __ovld __cnfn convert_int16_sat_rtn(int16);
int16 __ovld __cnfn convert_int16(int16);
int16 __ovld __cnfn convert_int16_sat(int16);
int16 __ovld __cnfn convert_int16_rte(uint16);
int16 __ovld __cnfn convert_int16_sat_rte(uint16);
int16 __ovld __cnfn convert_int16_rtz(uint16);
int16 __ovld __cnfn convert_int16_sat_rtz(uint16);
int16 __ovld __cnfn convert_int16_rtp(uint16);
int16 __ovld __cnfn convert_int16_sat_rtp(uint16);
int16 __ovld __cnfn convert_int16_rtn(uint16);
int16 __ovld __cnfn convert_int16_sat_rtn(uint16);
int16 __ovld __cnfn convert_int16(uint16);
int16 __ovld __cnfn convert_int16_sat(uint16);
int16 __ovld __cnfn convert_int16_rte(long16);
int16 __ovld __cnfn convert_int16_sat_rte(long16);
int16 __ovld __cnfn convert_int16_rtz(long16);
int16 __ovld __cnfn convert_int16_sat_rtz(long16);
int16 __ovld __cnfn convert_int16_rtp(long16);
int16 __ovld __cnfn convert_int16_sat_rtp(long16);
int16 __ovld __cnfn convert_int16_rtn(long16);
int16 __ovld __cnfn convert_int16_sat_rtn(long16);
int16 __ovld __cnfn convert_int16(long16);
int16 __ovld __cnfn convert_int16_sat(long16);
int16 __ovld __cnfn convert_int16_rte(ulong16);
int16 __ovld __cnfn convert_int16_sat_rte(ulong16);
int16 __ovld __cnfn convert_int16_rtz(ulong16);
int16 __ovld __cnfn convert_int16_sat_rtz(ulong16);
int16 __ovld __cnfn convert_int16_rtp(ulong16);
int16 __ovld __cnfn convert_int16_sat_rtp(ulong16);
int16 __ovld __cnfn convert_int16_rtn(ulong16);
int16 __ovld __cnfn convert_int16_sat_rtn(ulong16);
int16 __ovld __cnfn convert_int16(ulong16);
int16 __ovld __cnfn convert_int16_sat(ulong16);
int16 __ovld __cnfn convert_int16_rte(float16);
int16 __ovld __cnfn convert_int16_sat_rte(float16);
int16 __ovld __cnfn convert_int16_rtz(float16);
int16 __ovld __cnfn convert_int16_sat_rtz(float16);
int16 __ovld __cnfn convert_int16_rtp(float16);
int16 __ovld __cnfn convert_int16_sat_rtp(float16);
int16 __ovld __cnfn convert_int16_rtn(float16);
int16 __ovld __cnfn convert_int16_sat_rtn(float16);
int16 __ovld __cnfn convert_int16(float16);
int16 __ovld __cnfn convert_int16_sat(float16);
uint16 __ovld __cnfn convert_uint16_rte(char16);
uint16 __ovld __cnfn convert_uint16_sat_rte(char16);
uint16 __ovld __cnfn convert_uint16_rtz(char16);
uint16 __ovld __cnfn convert_uint16_sat_rtz(char16);
uint16 __ovld __cnfn convert_uint16_rtp(char16);
uint16 __ovld __cnfn convert_uint16_sat_rtp(char16);
uint16 __ovld __cnfn convert_uint16_rtn(char16);
uint16 __ovld __cnfn convert_uint16_sat_rtn(char16);
uint16 __ovld __cnfn convert_uint16(char16);
uint16 __ovld __cnfn convert_uint16_sat(char16);
uint16 __ovld __cnfn convert_uint16_rte(uchar16);
uint16 __ovld __cnfn convert_uint16_sat_rte(uchar16);
uint16 __ovld __cnfn convert_uint16_rtz(uchar16);
uint16 __ovld __cnfn convert_uint16_sat_rtz(uchar16);
uint16 __ovld __cnfn convert_uint16_rtp(uchar16);
uint16 __ovld __cnfn convert_uint16_sat_rtp(uchar16);
uint16 __ovld __cnfn convert_uint16_rtn(uchar16);
uint16 __ovld __cnfn convert_uint16_sat_rtn(uchar16);
uint16 __ovld __cnfn convert_uint16(uchar16);
uint16 __ovld __cnfn convert_uint16_sat(uchar16);
uint16 __ovld __cnfn convert_uint16_rte(short16);
uint16 __ovld __cnfn convert_uint16_sat_rte(short16);
uint16 __ovld __cnfn convert_uint16_rtz(short16);
uint16 __ovld __cnfn convert_uint16_sat_rtz(short16);
uint16 __ovld __cnfn convert_uint16_rtp(short16);
uint16 __ovld __cnfn convert_uint16_sat_rtp(short16);
uint16 __ovld __cnfn convert_uint16_rtn(short16);
uint16 __ovld __cnfn convert_uint16_sat_rtn(short16);
uint16 __ovld __cnfn convert_uint16(short16);
uint16 __ovld __cnfn convert_uint16_sat(short16);
uint16 __ovld __cnfn convert_uint16_rte(ushort16);
uint16 __ovld __cnfn convert_uint16_sat_rte(ushort16);
uint16 __ovld __cnfn convert_uint16_rtz(ushort16);
uint16 __ovld __cnfn convert_uint16_sat_rtz(ushort16);
uint16 __ovld __cnfn convert_uint16_rtp(ushort16);
uint16 __ovld __cnfn convert_uint16_sat_rtp(ushort16);
uint16 __ovld __cnfn convert_uint16_rtn(ushort16);
uint16 __ovld __cnfn convert_uint16_sat_rtn(ushort16);
uint16 __ovld __cnfn convert_uint16(ushort16);
uint16 __ovld __cnfn convert_uint16_sat(ushort16);
uint16 __ovld __cnfn convert_uint16_rte(int16);
uint16 __ovld __cnfn convert_uint16_sat_rte(int16);
uint16 __ovld __cnfn convert_uint16_rtz(int16);
uint16 __ovld __cnfn convert_uint16_sat_rtz(int16);
uint16 __ovld __cnfn convert_uint16_rtp(int16);
uint16 __ovld __cnfn convert_uint16_sat_rtp(int16);
uint16 __ovld __cnfn convert_uint16_rtn(int16);
uint16 __ovld __cnfn convert_uint16_sat_rtn(int16);
uint16 __ovld __cnfn convert_uint16(int16);
uint16 __ovld __cnfn convert_uint16_sat(int16);
uint16 __ovld __cnfn convert_uint16_rte(uint16);
uint16 __ovld __cnfn convert_uint16_sat_rte(uint16);
uint16 __ovld __cnfn convert_uint16_rtz(uint16);
uint16 __ovld __cnfn convert_uint16_sat_rtz(uint16);
uint16 __ovld __cnfn convert_uint16_rtp(uint16);
uint16 __ovld __cnfn convert_uint16_sat_rtp(uint16);
uint16 __ovld __cnfn convert_uint16_rtn(uint16);
uint16 __ovld __cnfn convert_uint16_sat_rtn(uint16);
uint16 __ovld __cnfn convert_uint16(uint16);
uint16 __ovld __cnfn convert_uint16_sat(uint16);
uint16 __ovld __cnfn convert_uint16_rte(long16);
uint16 __ovld __cnfn convert_uint16_sat_rte(long16);
uint16 __ovld __cnfn convert_uint16_rtz(long16);
uint16 __ovld __cnfn convert_uint16_sat_rtz(long16);
uint16 __ovld __cnfn convert_uint16_rtp(long16);
uint16 __ovld __cnfn convert_uint16_sat_rtp(long16);
uint16 __ovld __cnfn convert_uint16_rtn(long16);
uint16 __ovld __cnfn convert_uint16_sat_rtn(long16);
uint16 __ovld __cnfn convert_uint16(long16);
uint16 __ovld __cnfn convert_uint16_sat(long16);
uint16 __ovld __cnfn convert_uint16_rte(ulong16);
uint16 __ovld __cnfn convert_uint16_sat_rte(ulong16);
uint16 __ovld __cnfn convert_uint16_rtz(ulong16);
uint16 __ovld __cnfn convert_uint16_sat_rtz(ulong16);
uint16 __ovld __cnfn convert_uint16_rtp(ulong16);
uint16 __ovld __cnfn convert_uint16_sat_rtp(ulong16);
uint16 __ovld __cnfn convert_uint16_rtn(ulong16);
uint16 __ovld __cnfn convert_uint16_sat_rtn(ulong16);
uint16 __ovld __cnfn convert_uint16(ulong16);
uint16 __ovld __cnfn convert_uint16_sat(ulong16);
uint16 __ovld __cnfn convert_uint16_rte(float16);
uint16 __ovld __cnfn convert_uint16_sat_rte(float16);
uint16 __ovld __cnfn convert_uint16_rtz(float16);
uint16 __ovld __cnfn convert_uint16_sat_rtz(float16);
uint16 __ovld __cnfn convert_uint16_rtp(float16);
uint16 __ovld __cnfn convert_uint16_sat_rtp(float16);
uint16 __ovld __cnfn convert_uint16_rtn(float16);
uint16 __ovld __cnfn convert_uint16_sat_rtn(float16);
uint16 __ovld __cnfn convert_uint16(float16);
uint16 __ovld __cnfn convert_uint16_sat(float16);
long16 __ovld __cnfn convert_long16_rte(char16);
long16 __ovld __cnfn convert_long16_sat_rte(char16);
long16 __ovld __cnfn convert_long16_rtz(char16);
long16 __ovld __cnfn convert_long16_sat_rtz(char16);
long16 __ovld __cnfn convert_long16_rtp(char16);
long16 __ovld __cnfn convert_long16_sat_rtp(char16);
long16 __ovld __cnfn convert_long16_rtn(char16);
long16 __ovld __cnfn convert_long16_sat_rtn(char16);
long16 __ovld __cnfn convert_long16(char16);
long16 __ovld __cnfn convert_long16_sat(char16);
long16 __ovld __cnfn convert_long16_rte(uchar16);
long16 __ovld __cnfn convert_long16_sat_rte(uchar16);
long16 __ovld __cnfn convert_long16_rtz(uchar16);
long16 __ovld __cnfn convert_long16_sat_rtz(uchar16);
long16 __ovld __cnfn convert_long16_rtp(uchar16);
long16 __ovld __cnfn convert_long16_sat_rtp(uchar16);
long16 __ovld __cnfn convert_long16_rtn(uchar16);
long16 __ovld __cnfn convert_long16_sat_rtn(uchar16);
long16 __ovld __cnfn convert_long16(uchar16);
long16 __ovld __cnfn convert_long16_sat(uchar16);
long16 __ovld __cnfn convert_long16_rte(short16);
long16 __ovld __cnfn convert_long16_sat_rte(short16);
long16 __ovld __cnfn convert_long16_rtz(short16);
long16 __ovld __cnfn convert_long16_sat_rtz(short16);
long16 __ovld __cnfn convert_long16_rtp(short16);
long16 __ovld __cnfn convert_long16_sat_rtp(short16);
long16 __ovld __cnfn convert_long16_rtn(short16);
long16 __ovld __cnfn convert_long16_sat_rtn(short16);
long16 __ovld __cnfn convert_long16(short16);
long16 __ovld __cnfn convert_long16_sat(short16);
long16 __ovld __cnfn convert_long16_rte(ushort16);
long16 __ovld __cnfn convert_long16_sat_rte(ushort16);
long16 __ovld __cnfn convert_long16_rtz(ushort16);
long16 __ovld __cnfn convert_long16_sat_rtz(ushort16);
long16 __ovld __cnfn convert_long16_rtp(ushort16);
long16 __ovld __cnfn convert_long16_sat_rtp(ushort16);
long16 __ovld __cnfn convert_long16_rtn(ushort16);
long16 __ovld __cnfn convert_long16_sat_rtn(ushort16);
long16 __ovld __cnfn convert_long16(ushort16);
long16 __ovld __cnfn convert_long16_sat(ushort16);
long16 __ovld __cnfn convert_long16_rte(int16);
long16 __ovld __cnfn convert_long16_sat_rte(int16);
long16 __ovld __cnfn convert_long16_rtz(int16);
long16 __ovld __cnfn convert_long16_sat_rtz(int16);
long16 __ovld __cnfn convert_long16_rtp(int16);
long16 __ovld __cnfn convert_long16_sat_rtp(int16);
long16 __ovld __cnfn convert_long16_rtn(int16);
long16 __ovld __cnfn convert_long16_sat_rtn(int16);
long16 __ovld __cnfn convert_long16(int16);
long16 __ovld __cnfn convert_long16_sat(int16);
long16 __ovld __cnfn convert_long16_rte(uint16);
long16 __ovld __cnfn convert_long16_sat_rte(uint16);
long16 __ovld __cnfn convert_long16_rtz(uint16);
long16 __ovld __cnfn convert_long16_sat_rtz(uint16);
long16 __ovld __cnfn convert_long16_rtp(uint16);
long16 __ovld __cnfn convert_long16_sat_rtp(uint16);
long16 __ovld __cnfn convert_long16_rtn(uint16);
long16 __ovld __cnfn convert_long16_sat_rtn(uint16);
long16 __ovld __cnfn convert_long16(uint16);
long16 __ovld __cnfn convert_long16_sat(uint16);
long16 __ovld __cnfn convert_long16_rte(long16);
long16 __ovld __cnfn convert_long16_sat_rte(long16);
long16 __ovld __cnfn convert_long16_rtz(long16);
long16 __ovld __cnfn convert_long16_sat_rtz(long16);
long16 __ovld __cnfn convert_long16_rtp(long16);
long16 __ovld __cnfn convert_long16_sat_rtp(long16);
long16 __ovld __cnfn convert_long16_rtn(long16);
long16 __ovld __cnfn convert_long16_sat_rtn(long16);
long16 __ovld __cnfn convert_long16(long16);
long16 __ovld __cnfn convert_long16_sat(long16);
long16 __ovld __cnfn convert_long16_rte(ulong16);
long16 __ovld __cnfn convert_long16_sat_rte(ulong16);
long16 __ovld __cnfn convert_long16_rtz(ulong16);
long16 __ovld __cnfn convert_long16_sat_rtz(ulong16);
long16 __ovld __cnfn convert_long16_rtp(ulong16);
long16 __ovld __cnfn convert_long16_sat_rtp(ulong16);
long16 __ovld __cnfn convert_long16_rtn(ulong16);
long16 __ovld __cnfn convert_long16_sat_rtn(ulong16);
long16 __ovld __cnfn convert_long16(ulong16);
long16 __ovld __cnfn convert_long16_sat(ulong16);
long16 __ovld __cnfn convert_long16_rte(float16);
long16 __ovld __cnfn convert_long16_sat_rte(float16);
long16 __ovld __cnfn convert_long16_rtz(float16);
long16 __ovld __cnfn convert_long16_sat_rtz(float16);
long16 __ovld __cnfn convert_long16_rtp(float16);
long16 __ovld __cnfn convert_long16_sat_rtp(float16);
long16 __ovld __cnfn convert_long16_rtn(float16);
long16 __ovld __cnfn convert_long16_sat_rtn(float16);
long16 __ovld __cnfn convert_long16(float16);
long16 __ovld __cnfn convert_long16_sat(float16);
ulong16 __ovld __cnfn convert_ulong16_rte(char16);
ulong16 __ovld __cnfn convert_ulong16_sat_rte(char16);
ulong16 __ovld __cnfn convert_ulong16_rtz(char16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtz(char16);
ulong16 __ovld __cnfn convert_ulong16_rtp(char16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtp(char16);
ulong16 __ovld __cnfn convert_ulong16_rtn(char16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtn(char16);
ulong16 __ovld __cnfn convert_ulong16(char16);
ulong16 __ovld __cnfn convert_ulong16_sat(char16);
ulong16 __ovld __cnfn convert_ulong16_rte(uchar16);
ulong16 __ovld __cnfn convert_ulong16_sat_rte(uchar16);
ulong16 __ovld __cnfn convert_ulong16_rtz(uchar16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtz(uchar16);
ulong16 __ovld __cnfn convert_ulong16_rtp(uchar16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtp(uchar16);
ulong16 __ovld __cnfn convert_ulong16_rtn(uchar16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtn(uchar16);
ulong16 __ovld __cnfn convert_ulong16(uchar16);
ulong16 __ovld __cnfn convert_ulong16_sat(uchar16);
ulong16 __ovld __cnfn convert_ulong16_rte(short16);
ulong16 __ovld __cnfn convert_ulong16_sat_rte(short16);
ulong16 __ovld __cnfn convert_ulong16_rtz(short16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtz(short16);
ulong16 __ovld __cnfn convert_ulong16_rtp(short16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtp(short16);
ulong16 __ovld __cnfn convert_ulong16_rtn(short16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtn(short16);
ulong16 __ovld __cnfn convert_ulong16(short16);
ulong16 __ovld __cnfn convert_ulong16_sat(short16);
ulong16 __ovld __cnfn convert_ulong16_rte(ushort16);
ulong16 __ovld __cnfn convert_ulong16_sat_rte(ushort16);
ulong16 __ovld __cnfn convert_ulong16_rtz(ushort16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtz(ushort16);
ulong16 __ovld __cnfn convert_ulong16_rtp(ushort16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtp(ushort16);
ulong16 __ovld __cnfn convert_ulong16_rtn(ushort16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtn(ushort16);
ulong16 __ovld __cnfn convert_ulong16(ushort16);
ulong16 __ovld __cnfn convert_ulong16_sat(ushort16);
ulong16 __ovld __cnfn convert_ulong16_rte(int16);
ulong16 __ovld __cnfn convert_ulong16_sat_rte(int16);
ulong16 __ovld __cnfn convert_ulong16_rtz(int16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtz(int16);
ulong16 __ovld __cnfn convert_ulong16_rtp(int16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtp(int16);
ulong16 __ovld __cnfn convert_ulong16_rtn(int16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtn(int16);
ulong16 __ovld __cnfn convert_ulong16(int16);
ulong16 __ovld __cnfn convert_ulong16_sat(int16);
ulong16 __ovld __cnfn convert_ulong16_rte(uint16);
ulong16 __ovld __cnfn convert_ulong16_sat_rte(uint16);
ulong16 __ovld __cnfn convert_ulong16_rtz(uint16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtz(uint16);
ulong16 __ovld __cnfn convert_ulong16_rtp(uint16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtp(uint16);
ulong16 __ovld __cnfn convert_ulong16_rtn(uint16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtn(uint16);
ulong16 __ovld __cnfn convert_ulong16(uint16);
ulong16 __ovld __cnfn convert_ulong16_sat(uint16);
ulong16 __ovld __cnfn convert_ulong16_rte(long16);
ulong16 __ovld __cnfn convert_ulong16_sat_rte(long16);
ulong16 __ovld __cnfn convert_ulong16_rtz(long16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtz(long16);
ulong16 __ovld __cnfn convert_ulong16_rtp(long16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtp(long16);
ulong16 __ovld __cnfn convert_ulong16_rtn(long16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtn(long16);
ulong16 __ovld __cnfn convert_ulong16(long16);
ulong16 __ovld __cnfn convert_ulong16_sat(long16);
ulong16 __ovld __cnfn convert_ulong16_rte(ulong16);
ulong16 __ovld __cnfn convert_ulong16_sat_rte(ulong16);
ulong16 __ovld __cnfn convert_ulong16_rtz(ulong16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtz(ulong16);
ulong16 __ovld __cnfn convert_ulong16_rtp(ulong16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtp(ulong16);
ulong16 __ovld __cnfn convert_ulong16_rtn(ulong16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtn(ulong16);
ulong16 __ovld __cnfn convert_ulong16(ulong16);
ulong16 __ovld __cnfn convert_ulong16_sat(ulong16);
ulong16 __ovld __cnfn convert_ulong16_rte(float16);
ulong16 __ovld __cnfn convert_ulong16_sat_rte(float16);
ulong16 __ovld __cnfn convert_ulong16_rtz(float16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtz(float16);
ulong16 __ovld __cnfn convert_ulong16_rtp(float16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtp(float16);
ulong16 __ovld __cnfn convert_ulong16_rtn(float16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtn(float16);
ulong16 __ovld __cnfn convert_ulong16(float16);
ulong16 __ovld __cnfn convert_ulong16_sat(float16);
float16 __ovld __cnfn convert_float16_rte(char16);
float16 __ovld __cnfn convert_float16_rtz(char16);
float16 __ovld __cnfn convert_float16_rtp(char16);
float16 __ovld __cnfn convert_float16_rtn(char16);
float16 __ovld __cnfn convert_float16(char16);
float16 __ovld __cnfn convert_float16_rte(uchar16);
float16 __ovld __cnfn convert_float16_rtz(uchar16);
float16 __ovld __cnfn convert_float16_rtp(uchar16);
float16 __ovld __cnfn convert_float16_rtn(uchar16);
float16 __ovld __cnfn convert_float16(uchar16);
float16 __ovld __cnfn convert_float16_rte(short16);
float16 __ovld __cnfn convert_float16_rtz(short16);
float16 __ovld __cnfn convert_float16_rtp(short16);
float16 __ovld __cnfn convert_float16_rtn(short16);
float16 __ovld __cnfn convert_float16(short16);
float16 __ovld __cnfn convert_float16_rte(ushort16);
float16 __ovld __cnfn convert_float16_rtz(ushort16);
float16 __ovld __cnfn convert_float16_rtp(ushort16);
float16 __ovld __cnfn convert_float16_rtn(ushort16);
float16 __ovld __cnfn convert_float16(ushort16);
float16 __ovld __cnfn convert_float16_rte(int16);
float16 __ovld __cnfn convert_float16_rtz(int16);
float16 __ovld __cnfn convert_float16_rtp(int16);
float16 __ovld __cnfn convert_float16_rtn(int16);
float16 __ovld __cnfn convert_float16(int16);
float16 __ovld __cnfn convert_float16_rte(uint16);
float16 __ovld __cnfn convert_float16_rtz(uint16);
float16 __ovld __cnfn convert_float16_rtp(uint16);
float16 __ovld __cnfn convert_float16_rtn(uint16);
float16 __ovld __cnfn convert_float16(uint16);
float16 __ovld __cnfn convert_float16_rte(long16);
float16 __ovld __cnfn convert_float16_rtz(long16);
float16 __ovld __cnfn convert_float16_rtp(long16);
float16 __ovld __cnfn convert_float16_rtn(long16);
float16 __ovld __cnfn convert_float16(long16);
float16 __ovld __cnfn convert_float16_rte(ulong16);
float16 __ovld __cnfn convert_float16_rtz(ulong16);
float16 __ovld __cnfn convert_float16_rtp(ulong16);
float16 __ovld __cnfn convert_float16_rtn(ulong16);
float16 __ovld __cnfn convert_float16(ulong16);
float16 __ovld __cnfn convert_float16_rte(float16);
float16 __ovld __cnfn convert_float16_rtz(float16);
float16 __ovld __cnfn convert_float16_rtp(float16);
float16 __ovld __cnfn convert_float16_rtn(float16);
float16 __ovld __cnfn convert_float16(float16);

// Conversions with double data type parameters or return value.

#ifdef cl_khr_fp64
char __ovld __cnfn convert_char(double);
char __ovld __cnfn convert_char_rte(double);
char __ovld __cnfn convert_char_rtn(double);
char __ovld __cnfn convert_char_rtp(double);
char __ovld __cnfn convert_char_rtz(double);
char __ovld __cnfn convert_char_sat(double);
char __ovld __cnfn convert_char_sat_rte(double);
char __ovld __cnfn convert_char_sat_rtn(double);
char __ovld __cnfn convert_char_sat_rtp(double);
char __ovld __cnfn convert_char_sat_rtz(double);
char2 __ovld __cnfn convert_char2(double2);
char2 __ovld __cnfn convert_char2_rte(double2);
char2 __ovld __cnfn convert_char2_rtn(double2);
char2 __ovld __cnfn convert_char2_rtp(double2);
char2 __ovld __cnfn convert_char2_rtz(double2);
char2 __ovld __cnfn convert_char2_sat(double2);
char2 __ovld __cnfn convert_char2_sat_rte(double2);
char2 __ovld __cnfn convert_char2_sat_rtn(double2);
char2 __ovld __cnfn convert_char2_sat_rtp(double2);
char2 __ovld __cnfn convert_char2_sat_rtz(double2);
char3 __ovld __cnfn convert_char3(double3);
char3 __ovld __cnfn convert_char3_rte(double3);
char3 __ovld __cnfn convert_char3_rtn(double3);
char3 __ovld __cnfn convert_char3_rtp(double3);
char3 __ovld __cnfn convert_char3_rtz(double3);
char3 __ovld __cnfn convert_char3_sat(double3);
char3 __ovld __cnfn convert_char3_sat_rte(double3);
char3 __ovld __cnfn convert_char3_sat_rtn(double3);
char3 __ovld __cnfn convert_char3_sat_rtp(double3);
char3 __ovld __cnfn convert_char3_sat_rtz(double3);
char4 __ovld __cnfn convert_char4(double4);
char4 __ovld __cnfn convert_char4_rte(double4);
char4 __ovld __cnfn convert_char4_rtn(double4);
char4 __ovld __cnfn convert_char4_rtp(double4);
char4 __ovld __cnfn convert_char4_rtz(double4);
char4 __ovld __cnfn convert_char4_sat(double4);
char4 __ovld __cnfn convert_char4_sat_rte(double4);
char4 __ovld __cnfn convert_char4_sat_rtn(double4);
char4 __ovld __cnfn convert_char4_sat_rtp(double4);
char4 __ovld __cnfn convert_char4_sat_rtz(double4);
char8 __ovld __cnfn convert_char8(double8);
char8 __ovld __cnfn convert_char8_rte(double8);
char8 __ovld __cnfn convert_char8_rtn(double8);
char8 __ovld __cnfn convert_char8_rtp(double8);
char8 __ovld __cnfn convert_char8_rtz(double8);
char8 __ovld __cnfn convert_char8_sat(double8);
char8 __ovld __cnfn convert_char8_sat_rte(double8);
char8 __ovld __cnfn convert_char8_sat_rtn(double8);
char8 __ovld __cnfn convert_char8_sat_rtp(double8);
char8 __ovld __cnfn convert_char8_sat_rtz(double8);
char16 __ovld __cnfn convert_char16(double16);
char16 __ovld __cnfn convert_char16_rte(double16);
char16 __ovld __cnfn convert_char16_rtn(double16);
char16 __ovld __cnfn convert_char16_rtp(double16);
char16 __ovld __cnfn convert_char16_rtz(double16);
char16 __ovld __cnfn convert_char16_sat(double16);
char16 __ovld __cnfn convert_char16_sat_rte(double16);
char16 __ovld __cnfn convert_char16_sat_rtn(double16);
char16 __ovld __cnfn convert_char16_sat_rtp(double16);
char16 __ovld __cnfn convert_char16_sat_rtz(double16);

uchar __ovld __cnfn convert_uchar(double);
uchar __ovld __cnfn convert_uchar_rte(double);
uchar __ovld __cnfn convert_uchar_rtn(double);
uchar __ovld __cnfn convert_uchar_rtp(double);
uchar __ovld __cnfn convert_uchar_rtz(double);
uchar __ovld __cnfn convert_uchar_sat(double);
uchar __ovld __cnfn convert_uchar_sat_rte(double);
uchar __ovld __cnfn convert_uchar_sat_rtn(double);
uchar __ovld __cnfn convert_uchar_sat_rtp(double);
uchar __ovld __cnfn convert_uchar_sat_rtz(double);
uchar2 __ovld __cnfn convert_uchar2(double2);
uchar2 __ovld __cnfn convert_uchar2_rte(double2);
uchar2 __ovld __cnfn convert_uchar2_rtn(double2);
uchar2 __ovld __cnfn convert_uchar2_rtp(double2);
uchar2 __ovld __cnfn convert_uchar2_rtz(double2);
uchar2 __ovld __cnfn convert_uchar2_sat(double2);
uchar2 __ovld __cnfn convert_uchar2_sat_rte(double2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtn(double2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtp(double2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtz(double2);
uchar3 __ovld __cnfn convert_uchar3(double3);
uchar3 __ovld __cnfn convert_uchar3_rte(double3);
uchar3 __ovld __cnfn convert_uchar3_rtn(double3);
uchar3 __ovld __cnfn convert_uchar3_rtp(double3);
uchar3 __ovld __cnfn convert_uchar3_rtz(double3);
uchar3 __ovld __cnfn convert_uchar3_sat(double3);
uchar3 __ovld __cnfn convert_uchar3_sat_rte(double3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtn(double3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtp(double3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtz(double3);
uchar4 __ovld __cnfn convert_uchar4(double4);
uchar4 __ovld __cnfn convert_uchar4_rte(double4);
uchar4 __ovld __cnfn convert_uchar4_rtn(double4);
uchar4 __ovld __cnfn convert_uchar4_rtp(double4);
uchar4 __ovld __cnfn convert_uchar4_rtz(double4);
uchar4 __ovld __cnfn convert_uchar4_sat(double4);
uchar4 __ovld __cnfn convert_uchar4_sat_rte(double4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtn(double4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtp(double4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtz(double4);
uchar8 __ovld __cnfn convert_uchar8(double8);
uchar8 __ovld __cnfn convert_uchar8_rte(double8);
uchar8 __ovld __cnfn convert_uchar8_rtn(double8);
uchar8 __ovld __cnfn convert_uchar8_rtp(double8);
uchar8 __ovld __cnfn convert_uchar8_rtz(double8);
uchar8 __ovld __cnfn convert_uchar8_sat(double8);
uchar8 __ovld __cnfn convert_uchar8_sat_rte(double8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtn(double8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtp(double8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtz(double8);
uchar16 __ovld __cnfn convert_uchar16(double16);
uchar16 __ovld __cnfn convert_uchar16_rte(double16);
uchar16 __ovld __cnfn convert_uchar16_rtn(double16);
uchar16 __ovld __cnfn convert_uchar16_rtp(double16);
uchar16 __ovld __cnfn convert_uchar16_rtz(double16);
uchar16 __ovld __cnfn convert_uchar16_sat(double16);
uchar16 __ovld __cnfn convert_uchar16_sat_rte(double16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtn(double16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtp(double16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtz(double16);

short __ovld __cnfn convert_short(double);
short __ovld __cnfn convert_short_rte(double);
short __ovld __cnfn convert_short_rtn(double);
short __ovld __cnfn convert_short_rtp(double);
short __ovld __cnfn convert_short_rtz(double);
short __ovld __cnfn convert_short_sat(double);
short __ovld __cnfn convert_short_sat_rte(double);
short __ovld __cnfn convert_short_sat_rtn(double);
short __ovld __cnfn convert_short_sat_rtp(double);
short __ovld __cnfn convert_short_sat_rtz(double);
short2 __ovld __cnfn convert_short2(double2);
short2 __ovld __cnfn convert_short2_rte(double2);
short2 __ovld __cnfn convert_short2_rtn(double2);
short2 __ovld __cnfn convert_short2_rtp(double2);
short2 __ovld __cnfn convert_short2_rtz(double2);
short2 __ovld __cnfn convert_short2_sat(double2);
short2 __ovld __cnfn convert_short2_sat_rte(double2);
short2 __ovld __cnfn convert_short2_sat_rtn(double2);
short2 __ovld __cnfn convert_short2_sat_rtp(double2);
short2 __ovld __cnfn convert_short2_sat_rtz(double2);
short3 __ovld __cnfn convert_short3(double3);
short3 __ovld __cnfn convert_short3_rte(double3);
short3 __ovld __cnfn convert_short3_rtn(double3);
short3 __ovld __cnfn convert_short3_rtp(double3);
short3 __ovld __cnfn convert_short3_rtz(double3);
short3 __ovld __cnfn convert_short3_sat(double3);
short3 __ovld __cnfn convert_short3_sat_rte(double3);
short3 __ovld __cnfn convert_short3_sat_rtn(double3);
short3 __ovld __cnfn convert_short3_sat_rtp(double3);
short3 __ovld __cnfn convert_short3_sat_rtz(double3);
short4 __ovld __cnfn convert_short4(double4);
short4 __ovld __cnfn convert_short4_rte(double4);
short4 __ovld __cnfn convert_short4_rtn(double4);
short4 __ovld __cnfn convert_short4_rtp(double4);
short4 __ovld __cnfn convert_short4_rtz(double4);
short4 __ovld __cnfn convert_short4_sat(double4);
short4 __ovld __cnfn convert_short4_sat_rte(double4);
short4 __ovld __cnfn convert_short4_sat_rtn(double4);
short4 __ovld __cnfn convert_short4_sat_rtp(double4);
short4 __ovld __cnfn convert_short4_sat_rtz(double4);
short8 __ovld __cnfn convert_short8(double8);
short8 __ovld __cnfn convert_short8_rte(double8);
short8 __ovld __cnfn convert_short8_rtn(double8);
short8 __ovld __cnfn convert_short8_rtp(double8);
short8 __ovld __cnfn convert_short8_rtz(double8);
short8 __ovld __cnfn convert_short8_sat(double8);
short8 __ovld __cnfn convert_short8_sat_rte(double8);
short8 __ovld __cnfn convert_short8_sat_rtn(double8);
short8 __ovld __cnfn convert_short8_sat_rtp(double8);
short8 __ovld __cnfn convert_short8_sat_rtz(double8);
short16 __ovld __cnfn convert_short16(double16);
short16 __ovld __cnfn convert_short16_rte(double16);
short16 __ovld __cnfn convert_short16_rtn(double16);
short16 __ovld __cnfn convert_short16_rtp(double16);
short16 __ovld __cnfn convert_short16_rtz(double16);
short16 __ovld __cnfn convert_short16_sat(double16);
short16 __ovld __cnfn convert_short16_sat_rte(double16);
short16 __ovld __cnfn convert_short16_sat_rtn(double16);
short16 __ovld __cnfn convert_short16_sat_rtp(double16);
short16 __ovld __cnfn convert_short16_sat_rtz(double16);

ushort __ovld __cnfn convert_ushort(double);
ushort __ovld __cnfn convert_ushort_rte(double);
ushort __ovld __cnfn convert_ushort_rtn(double);
ushort __ovld __cnfn convert_ushort_rtp(double);
ushort __ovld __cnfn convert_ushort_rtz(double);
ushort __ovld __cnfn convert_ushort_sat(double);
ushort __ovld __cnfn convert_ushort_sat_rte(double);
ushort __ovld __cnfn convert_ushort_sat_rtn(double);
ushort __ovld __cnfn convert_ushort_sat_rtp(double);
ushort __ovld __cnfn convert_ushort_sat_rtz(double);
ushort2 __ovld __cnfn convert_ushort2(double2);
ushort2 __ovld __cnfn convert_ushort2_rte(double2);
ushort2 __ovld __cnfn convert_ushort2_rtn(double2);
ushort2 __ovld __cnfn convert_ushort2_rtp(double2);
ushort2 __ovld __cnfn convert_ushort2_rtz(double2);
ushort2 __ovld __cnfn convert_ushort2_sat(double2);
ushort2 __ovld __cnfn convert_ushort2_sat_rte(double2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtn(double2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtp(double2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtz(double2);
ushort3 __ovld __cnfn convert_ushort3(double3);
ushort3 __ovld __cnfn convert_ushort3_rte(double3);
ushort3 __ovld __cnfn convert_ushort3_rtn(double3);
ushort3 __ovld __cnfn convert_ushort3_rtp(double3);
ushort3 __ovld __cnfn convert_ushort3_rtz(double3);
ushort3 __ovld __cnfn convert_ushort3_sat(double3);
ushort3 __ovld __cnfn convert_ushort3_sat_rte(double3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtn(double3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtp(double3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtz(double3);
ushort4 __ovld __cnfn convert_ushort4(double4);
ushort4 __ovld __cnfn convert_ushort4_rte(double4);
ushort4 __ovld __cnfn convert_ushort4_rtn(double4);
ushort4 __ovld __cnfn convert_ushort4_rtp(double4);
ushort4 __ovld __cnfn convert_ushort4_rtz(double4);
ushort4 __ovld __cnfn convert_ushort4_sat(double4);
ushort4 __ovld __cnfn convert_ushort4_sat_rte(double4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtn(double4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtp(double4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtz(double4);
ushort8 __ovld __cnfn convert_ushort8(double8);
ushort8 __ovld __cnfn convert_ushort8_rte(double8);
ushort8 __ovld __cnfn convert_ushort8_rtn(double8);
ushort8 __ovld __cnfn convert_ushort8_rtp(double8);
ushort8 __ovld __cnfn convert_ushort8_rtz(double8);
ushort8 __ovld __cnfn convert_ushort8_sat(double8);
ushort8 __ovld __cnfn convert_ushort8_sat_rte(double8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtn(double8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtp(double8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtz(double8);
ushort16 __ovld __cnfn convert_ushort16(double16);
ushort16 __ovld __cnfn convert_ushort16_rte(double16);
ushort16 __ovld __cnfn convert_ushort16_rtn(double16);
ushort16 __ovld __cnfn convert_ushort16_rtp(double16);
ushort16 __ovld __cnfn convert_ushort16_rtz(double16);
ushort16 __ovld __cnfn convert_ushort16_sat(double16);
ushort16 __ovld __cnfn convert_ushort16_sat_rte(double16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtn(double16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtp(double16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtz(double16);

int __ovld __cnfn convert_int(double);
int __ovld __cnfn convert_int_rte(double);
int __ovld __cnfn convert_int_rtn(double);
int __ovld __cnfn convert_int_rtp(double);
int __ovld __cnfn convert_int_rtz(double);
int __ovld __cnfn convert_int_sat(double);
int __ovld __cnfn convert_int_sat_rte(double);
int __ovld __cnfn convert_int_sat_rtn(double);
int __ovld __cnfn convert_int_sat_rtp(double);
int __ovld __cnfn convert_int_sat_rtz(double);
int2 __ovld __cnfn convert_int2(double2);
int2 __ovld __cnfn convert_int2_rte(double2);
int2 __ovld __cnfn convert_int2_rtn(double2);
int2 __ovld __cnfn convert_int2_rtp(double2);
int2 __ovld __cnfn convert_int2_rtz(double2);
int2 __ovld __cnfn convert_int2_sat(double2);
int2 __ovld __cnfn convert_int2_sat_rte(double2);
int2 __ovld __cnfn convert_int2_sat_rtn(double2);
int2 __ovld __cnfn convert_int2_sat_rtp(double2);
int2 __ovld __cnfn convert_int2_sat_rtz(double2);
int3 __ovld __cnfn convert_int3(double3);
int3 __ovld __cnfn convert_int3_rte(double3);
int3 __ovld __cnfn convert_int3_rtn(double3);
int3 __ovld __cnfn convert_int3_rtp(double3);
int3 __ovld __cnfn convert_int3_rtz(double3);
int3 __ovld __cnfn convert_int3_sat(double3);
int3 __ovld __cnfn convert_int3_sat_rte(double3);
int3 __ovld __cnfn convert_int3_sat_rtn(double3);
int3 __ovld __cnfn convert_int3_sat_rtp(double3);
int3 __ovld __cnfn convert_int3_sat_rtz(double3);
int4 __ovld __cnfn convert_int4(double4);
int4 __ovld __cnfn convert_int4_rte(double4);
int4 __ovld __cnfn convert_int4_rtn(double4);
int4 __ovld __cnfn convert_int4_rtp(double4);
int4 __ovld __cnfn convert_int4_rtz(double4);
int4 __ovld __cnfn convert_int4_sat(double4);
int4 __ovld __cnfn convert_int4_sat_rte(double4);
int4 __ovld __cnfn convert_int4_sat_rtn(double4);
int4 __ovld __cnfn convert_int4_sat_rtp(double4);
int4 __ovld __cnfn convert_int4_sat_rtz(double4);
int8 __ovld __cnfn convert_int8(double8);
int8 __ovld __cnfn convert_int8_rte(double8);
int8 __ovld __cnfn convert_int8_rtn(double8);
int8 __ovld __cnfn convert_int8_rtp(double8);
int8 __ovld __cnfn convert_int8_rtz(double8);
int8 __ovld __cnfn convert_int8_sat(double8);
int8 __ovld __cnfn convert_int8_sat_rte(double8);
int8 __ovld __cnfn convert_int8_sat_rtn(double8);
int8 __ovld __cnfn convert_int8_sat_rtp(double8);
int8 __ovld __cnfn convert_int8_sat_rtz(double8);
int16 __ovld __cnfn convert_int16(double16);
int16 __ovld __cnfn convert_int16_rte(double16);
int16 __ovld __cnfn convert_int16_rtn(double16);
int16 __ovld __cnfn convert_int16_rtp(double16);
int16 __ovld __cnfn convert_int16_rtz(double16);
int16 __ovld __cnfn convert_int16_sat(double16);
int16 __ovld __cnfn convert_int16_sat_rte(double16);
int16 __ovld __cnfn convert_int16_sat_rtn(double16);
int16 __ovld __cnfn convert_int16_sat_rtp(double16);
int16 __ovld __cnfn convert_int16_sat_rtz(double16);

uint __ovld __cnfn convert_uint(double);
uint __ovld __cnfn convert_uint_rte(double);
uint __ovld __cnfn convert_uint_rtn(double);
uint __ovld __cnfn convert_uint_rtp(double);
uint __ovld __cnfn convert_uint_rtz(double);
uint __ovld __cnfn convert_uint_sat(double);
uint __ovld __cnfn convert_uint_sat_rte(double);
uint __ovld __cnfn convert_uint_sat_rtn(double);
uint __ovld __cnfn convert_uint_sat_rtp(double);
uint __ovld __cnfn convert_uint_sat_rtz(double);
uint2 __ovld __cnfn convert_uint2(double2);
uint2 __ovld __cnfn convert_uint2_rte(double2);
uint2 __ovld __cnfn convert_uint2_rtn(double2);
uint2 __ovld __cnfn convert_uint2_rtp(double2);
uint2 __ovld __cnfn convert_uint2_rtz(double2);
uint2 __ovld __cnfn convert_uint2_sat(double2);
uint2 __ovld __cnfn convert_uint2_sat_rte(double2);
uint2 __ovld __cnfn convert_uint2_sat_rtn(double2);
uint2 __ovld __cnfn convert_uint2_sat_rtp(double2);
uint2 __ovld __cnfn convert_uint2_sat_rtz(double2);
uint3 __ovld __cnfn convert_uint3(double3);
uint3 __ovld __cnfn convert_uint3_rte(double3);
uint3 __ovld __cnfn convert_uint3_rtn(double3);
uint3 __ovld __cnfn convert_uint3_rtp(double3);
uint3 __ovld __cnfn convert_uint3_rtz(double3);
uint3 __ovld __cnfn convert_uint3_sat(double3);
uint3 __ovld __cnfn convert_uint3_sat_rte(double3);
uint3 __ovld __cnfn convert_uint3_sat_rtn(double3);
uint3 __ovld __cnfn convert_uint3_sat_rtp(double3);
uint3 __ovld __cnfn convert_uint3_sat_rtz(double3);
uint4 __ovld __cnfn convert_uint4(double4);
uint4 __ovld __cnfn convert_uint4_rte(double4);
uint4 __ovld __cnfn convert_uint4_rtn(double4);
uint4 __ovld __cnfn convert_uint4_rtp(double4);
uint4 __ovld __cnfn convert_uint4_rtz(double4);
uint4 __ovld __cnfn convert_uint4_sat(double4);
uint4 __ovld __cnfn convert_uint4_sat_rte(double4);
uint4 __ovld __cnfn convert_uint4_sat_rtn(double4);
uint4 __ovld __cnfn convert_uint4_sat_rtp(double4);
uint4 __ovld __cnfn convert_uint4_sat_rtz(double4);
uint8 __ovld __cnfn convert_uint8(double8);
uint8 __ovld __cnfn convert_uint8_rte(double8);
uint8 __ovld __cnfn convert_uint8_rtn(double8);
uint8 __ovld __cnfn convert_uint8_rtp(double8);
uint8 __ovld __cnfn convert_uint8_rtz(double8);
uint8 __ovld __cnfn convert_uint8_sat(double8);
uint8 __ovld __cnfn convert_uint8_sat_rte(double8);
uint8 __ovld __cnfn convert_uint8_sat_rtn(double8);
uint8 __ovld __cnfn convert_uint8_sat_rtp(double8);
uint8 __ovld __cnfn convert_uint8_sat_rtz(double8);
uint16 __ovld __cnfn convert_uint16(double16);
uint16 __ovld __cnfn convert_uint16_rte(double16);
uint16 __ovld __cnfn convert_uint16_rtn(double16);
uint16 __ovld __cnfn convert_uint16_rtp(double16);
uint16 __ovld __cnfn convert_uint16_rtz(double16);
uint16 __ovld __cnfn convert_uint16_sat(double16);
uint16 __ovld __cnfn convert_uint16_sat_rte(double16);
uint16 __ovld __cnfn convert_uint16_sat_rtn(double16);
uint16 __ovld __cnfn convert_uint16_sat_rtp(double16);
uint16 __ovld __cnfn convert_uint16_sat_rtz(double16);

long __ovld __cnfn convert_long(double);
long __ovld __cnfn convert_long_rte(double);
long __ovld __cnfn convert_long_rtn(double);
long __ovld __cnfn convert_long_rtp(double);
long __ovld __cnfn convert_long_rtz(double);
long __ovld __cnfn convert_long_sat(double);
long __ovld __cnfn convert_long_sat_rte(double);
long __ovld __cnfn convert_long_sat_rtn(double);
long __ovld __cnfn convert_long_sat_rtp(double);
long __ovld __cnfn convert_long_sat_rtz(double);
long2 __ovld __cnfn convert_long2(double2);
long2 __ovld __cnfn convert_long2_rte(double2);
long2 __ovld __cnfn convert_long2_rtn(double2);
long2 __ovld __cnfn convert_long2_rtp(double2);
long2 __ovld __cnfn convert_long2_rtz(double2);
long2 __ovld __cnfn convert_long2_sat(double2);
long2 __ovld __cnfn convert_long2_sat_rte(double2);
long2 __ovld __cnfn convert_long2_sat_rtn(double2);
long2 __ovld __cnfn convert_long2_sat_rtp(double2);
long2 __ovld __cnfn convert_long2_sat_rtz(double2);
long3 __ovld __cnfn convert_long3(double3);
long3 __ovld __cnfn convert_long3_rte(double3);
long3 __ovld __cnfn convert_long3_rtn(double3);
long3 __ovld __cnfn convert_long3_rtp(double3);
long3 __ovld __cnfn convert_long3_rtz(double3);
long3 __ovld __cnfn convert_long3_sat(double3);
long3 __ovld __cnfn convert_long3_sat_rte(double3);
long3 __ovld __cnfn convert_long3_sat_rtn(double3);
long3 __ovld __cnfn convert_long3_sat_rtp(double3);
long3 __ovld __cnfn convert_long3_sat_rtz(double3);
long4 __ovld __cnfn convert_long4(double4);
long4 __ovld __cnfn convert_long4_rte(double4);
long4 __ovld __cnfn convert_long4_rtn(double4);
long4 __ovld __cnfn convert_long4_rtp(double4);
long4 __ovld __cnfn convert_long4_rtz(double4);
long4 __ovld __cnfn convert_long4_sat(double4);
long4 __ovld __cnfn convert_long4_sat_rte(double4);
long4 __ovld __cnfn convert_long4_sat_rtn(double4);
long4 __ovld __cnfn convert_long4_sat_rtp(double4);
long4 __ovld __cnfn convert_long4_sat_rtz(double4);
long8 __ovld __cnfn convert_long8(double8);
long8 __ovld __cnfn convert_long8_rte(double8);
long8 __ovld __cnfn convert_long8_rtn(double8);
long8 __ovld __cnfn convert_long8_rtp(double8);
long8 __ovld __cnfn convert_long8_rtz(double8);
long8 __ovld __cnfn convert_long8_sat(double8);
long8 __ovld __cnfn convert_long8_sat_rte(double8);
long8 __ovld __cnfn convert_long8_sat_rtn(double8);
long8 __ovld __cnfn convert_long8_sat_rtp(double8);
long8 __ovld __cnfn convert_long8_sat_rtz(double8);
long16 __ovld __cnfn convert_long16(double16);
long16 __ovld __cnfn convert_long16_rte(double16);
long16 __ovld __cnfn convert_long16_rtn(double16);
long16 __ovld __cnfn convert_long16_rtp(double16);
long16 __ovld __cnfn convert_long16_rtz(double16);
long16 __ovld __cnfn convert_long16_sat(double16);
long16 __ovld __cnfn convert_long16_sat_rte(double16);
long16 __ovld __cnfn convert_long16_sat_rtn(double16);
long16 __ovld __cnfn convert_long16_sat_rtp(double16);
long16 __ovld __cnfn convert_long16_sat_rtz(double16);

ulong __ovld __cnfn convert_ulong(double);
ulong __ovld __cnfn convert_ulong_rte(double);
ulong __ovld __cnfn convert_ulong_rtn(double);
ulong __ovld __cnfn convert_ulong_rtp(double);
ulong __ovld __cnfn convert_ulong_rtz(double);
ulong __ovld __cnfn convert_ulong_sat(double);
ulong __ovld __cnfn convert_ulong_sat_rte(double);
ulong __ovld __cnfn convert_ulong_sat_rtn(double);
ulong __ovld __cnfn convert_ulong_sat_rtp(double);
ulong __ovld __cnfn convert_ulong_sat_rtz(double);
ulong2 __ovld __cnfn convert_ulong2(double2);
ulong2 __ovld __cnfn convert_ulong2_rte(double2);
ulong2 __ovld __cnfn convert_ulong2_rtn(double2);
ulong2 __ovld __cnfn convert_ulong2_rtp(double2);
ulong2 __ovld __cnfn convert_ulong2_rtz(double2);
ulong2 __ovld __cnfn convert_ulong2_sat(double2);
ulong2 __ovld __cnfn convert_ulong2_sat_rte(double2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtn(double2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtp(double2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtz(double2);
ulong3 __ovld __cnfn convert_ulong3(double3);
ulong3 __ovld __cnfn convert_ulong3_rte(double3);
ulong3 __ovld __cnfn convert_ulong3_rtn(double3);
ulong3 __ovld __cnfn convert_ulong3_rtp(double3);
ulong3 __ovld __cnfn convert_ulong3_rtz(double3);
ulong3 __ovld __cnfn convert_ulong3_sat(double3);
ulong3 __ovld __cnfn convert_ulong3_sat_rte(double3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtn(double3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtp(double3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtz(double3);
ulong4 __ovld __cnfn convert_ulong4(double4);
ulong4 __ovld __cnfn convert_ulong4_rte(double4);
ulong4 __ovld __cnfn convert_ulong4_rtn(double4);
ulong4 __ovld __cnfn convert_ulong4_rtp(double4);
ulong4 __ovld __cnfn convert_ulong4_rtz(double4);
ulong4 __ovld __cnfn convert_ulong4_sat(double4);
ulong4 __ovld __cnfn convert_ulong4_sat_rte(double4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtn(double4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtp(double4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtz(double4);
ulong8 __ovld __cnfn convert_ulong8(double8);
ulong8 __ovld __cnfn convert_ulong8_rte(double8);
ulong8 __ovld __cnfn convert_ulong8_rtn(double8);
ulong8 __ovld __cnfn convert_ulong8_rtp(double8);
ulong8 __ovld __cnfn convert_ulong8_rtz(double8);
ulong8 __ovld __cnfn convert_ulong8_sat(double8);
ulong8 __ovld __cnfn convert_ulong8_sat_rte(double8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtn(double8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtp(double8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtz(double8);
ulong16 __ovld __cnfn convert_ulong16(double16);
ulong16 __ovld __cnfn convert_ulong16_rte(double16);
ulong16 __ovld __cnfn convert_ulong16_rtn(double16);
ulong16 __ovld __cnfn convert_ulong16_rtp(double16);
ulong16 __ovld __cnfn convert_ulong16_rtz(double16);
ulong16 __ovld __cnfn convert_ulong16_sat(double16);
ulong16 __ovld __cnfn convert_ulong16_sat_rte(double16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtn(double16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtp(double16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtz(double16);

float __ovld __cnfn convert_float(double);
float __ovld __cnfn convert_float_rte(double);
float __ovld __cnfn convert_float_rtn(double);
float __ovld __cnfn convert_float_rtp(double);
float __ovld __cnfn convert_float_rtz(double);
float2 __ovld __cnfn convert_float2(double2);
float2 __ovld __cnfn convert_float2_rte(double2);
float2 __ovld __cnfn convert_float2_rtn(double2);
float2 __ovld __cnfn convert_float2_rtp(double2);
float2 __ovld __cnfn convert_float2_rtz(double2);
float3 __ovld __cnfn convert_float3(double3);
float3 __ovld __cnfn convert_float3_rte(double3);
float3 __ovld __cnfn convert_float3_rtn(double3);
float3 __ovld __cnfn convert_float3_rtp(double3);
float3 __ovld __cnfn convert_float3_rtz(double3);
float4 __ovld __cnfn convert_float4(double4);
float4 __ovld __cnfn convert_float4_rte(double4);
float4 __ovld __cnfn convert_float4_rtn(double4);
float4 __ovld __cnfn convert_float4_rtp(double4);
float4 __ovld __cnfn convert_float4_rtz(double4);
float8 __ovld __cnfn convert_float8(double8);
float8 __ovld __cnfn convert_float8_rte(double8);
float8 __ovld __cnfn convert_float8_rtn(double8);
float8 __ovld __cnfn convert_float8_rtp(double8);
float8 __ovld __cnfn convert_float8_rtz(double8);
float16 __ovld __cnfn convert_float16(double16);
float16 __ovld __cnfn convert_float16_rte(double16);
float16 __ovld __cnfn convert_float16_rtn(double16);
float16 __ovld __cnfn convert_float16_rtp(double16);
float16 __ovld __cnfn convert_float16_rtz(double16);

double __ovld __cnfn convert_double(char);
double __ovld __cnfn convert_double(double);
double __ovld __cnfn convert_double(float);
double __ovld __cnfn convert_double(int);
double __ovld __cnfn convert_double(long);
double __ovld __cnfn convert_double(short);
double __ovld __cnfn convert_double(uchar);
double __ovld __cnfn convert_double(uint);
double __ovld __cnfn convert_double(ulong);
double __ovld __cnfn convert_double(ushort);
double __ovld __cnfn convert_double_rte(char);
double __ovld __cnfn convert_double_rte(double);
double __ovld __cnfn convert_double_rte(float);
double __ovld __cnfn convert_double_rte(int);
double __ovld __cnfn convert_double_rte(long);
double __ovld __cnfn convert_double_rte(short);
double __ovld __cnfn convert_double_rte(uchar);
double __ovld __cnfn convert_double_rte(uint);
double __ovld __cnfn convert_double_rte(ulong);
double __ovld __cnfn convert_double_rte(ushort);
double __ovld __cnfn convert_double_rtn(char);
double __ovld __cnfn convert_double_rtn(double);
double __ovld __cnfn convert_double_rtn(float);
double __ovld __cnfn convert_double_rtn(int);
double __ovld __cnfn convert_double_rtn(long);
double __ovld __cnfn convert_double_rtn(short);
double __ovld __cnfn convert_double_rtn(uchar);
double __ovld __cnfn convert_double_rtn(uint);
double __ovld __cnfn convert_double_rtn(ulong);
double __ovld __cnfn convert_double_rtn(ushort);
double __ovld __cnfn convert_double_rtp(char);
double __ovld __cnfn convert_double_rtp(double);
double __ovld __cnfn convert_double_rtp(float);
double __ovld __cnfn convert_double_rtp(int);
double __ovld __cnfn convert_double_rtp(long);
double __ovld __cnfn convert_double_rtp(short);
double __ovld __cnfn convert_double_rtp(uchar);
double __ovld __cnfn convert_double_rtp(uint);
double __ovld __cnfn convert_double_rtp(ulong);
double __ovld __cnfn convert_double_rtp(ushort);
double __ovld __cnfn convert_double_rtz(char);
double __ovld __cnfn convert_double_rtz(double);
double __ovld __cnfn convert_double_rtz(float);
double __ovld __cnfn convert_double_rtz(int);
double __ovld __cnfn convert_double_rtz(long);
double __ovld __cnfn convert_double_rtz(short);
double __ovld __cnfn convert_double_rtz(uchar);
double __ovld __cnfn convert_double_rtz(uint);
double __ovld __cnfn convert_double_rtz(ulong);
double __ovld __cnfn convert_double_rtz(ushort);
double2 __ovld __cnfn convert_double2(char2);
double2 __ovld __cnfn convert_double2(double2);
double2 __ovld __cnfn convert_double2(float2);
double2 __ovld __cnfn convert_double2(int2);
double2 __ovld __cnfn convert_double2(long2);
double2 __ovld __cnfn convert_double2(short2);
double2 __ovld __cnfn convert_double2(uchar2);
double2 __ovld __cnfn convert_double2(uint2);
double2 __ovld __cnfn convert_double2(ulong2);
double2 __ovld __cnfn convert_double2(ushort2);
double2 __ovld __cnfn convert_double2_rte(char2);
double2 __ovld __cnfn convert_double2_rte(double2);
double2 __ovld __cnfn convert_double2_rte(float2);
double2 __ovld __cnfn convert_double2_rte(int2);
double2 __ovld __cnfn convert_double2_rte(long2);
double2 __ovld __cnfn convert_double2_rte(short2);
double2 __ovld __cnfn convert_double2_rte(uchar2);
double2 __ovld __cnfn convert_double2_rte(uint2);
double2 __ovld __cnfn convert_double2_rte(ulong2);
double2 __ovld __cnfn convert_double2_rte(ushort2);
double2 __ovld __cnfn convert_double2_rtn(char2);
double2 __ovld __cnfn convert_double2_rtn(double2);
double2 __ovld __cnfn convert_double2_rtn(float2);
double2 __ovld __cnfn convert_double2_rtn(int2);
double2 __ovld __cnfn convert_double2_rtn(long2);
double2 __ovld __cnfn convert_double2_rtn(short2);
double2 __ovld __cnfn convert_double2_rtn(uchar2);
double2 __ovld __cnfn convert_double2_rtn(uint2);
double2 __ovld __cnfn convert_double2_rtn(ulong2);
double2 __ovld __cnfn convert_double2_rtn(ushort2);
double2 __ovld __cnfn convert_double2_rtp(char2);
double2 __ovld __cnfn convert_double2_rtp(double2);
double2 __ovld __cnfn convert_double2_rtp(float2);
double2 __ovld __cnfn convert_double2_rtp(int2);
double2 __ovld __cnfn convert_double2_rtp(long2);
double2 __ovld __cnfn convert_double2_rtp(short2);
double2 __ovld __cnfn convert_double2_rtp(uchar2);
double2 __ovld __cnfn convert_double2_rtp(uint2);
double2 __ovld __cnfn convert_double2_rtp(ulong2);
double2 __ovld __cnfn convert_double2_rtp(ushort2);
double2 __ovld __cnfn convert_double2_rtz(char2);
double2 __ovld __cnfn convert_double2_rtz(double2);
double2 __ovld __cnfn convert_double2_rtz(float2);
double2 __ovld __cnfn convert_double2_rtz(int2);
double2 __ovld __cnfn convert_double2_rtz(long2);
double2 __ovld __cnfn convert_double2_rtz(short2);
double2 __ovld __cnfn convert_double2_rtz(uchar2);
double2 __ovld __cnfn convert_double2_rtz(uint2);
double2 __ovld __cnfn convert_double2_rtz(ulong2);
double2 __ovld __cnfn convert_double2_rtz(ushort2);
double3 __ovld __cnfn convert_double3(char3);
double3 __ovld __cnfn convert_double3(double3);
double3 __ovld __cnfn convert_double3(float3);
double3 __ovld __cnfn convert_double3(int3);
double3 __ovld __cnfn convert_double3(long3);
double3 __ovld __cnfn convert_double3(short3);
double3 __ovld __cnfn convert_double3(uchar3);
double3 __ovld __cnfn convert_double3(uint3);
double3 __ovld __cnfn convert_double3(ulong3);
double3 __ovld __cnfn convert_double3(ushort3);
double3 __ovld __cnfn convert_double3_rte(char3);
double3 __ovld __cnfn convert_double3_rte(double3);
double3 __ovld __cnfn convert_double3_rte(float3);
double3 __ovld __cnfn convert_double3_rte(int3);
double3 __ovld __cnfn convert_double3_rte(long3);
double3 __ovld __cnfn convert_double3_rte(short3);
double3 __ovld __cnfn convert_double3_rte(uchar3);
double3 __ovld __cnfn convert_double3_rte(uint3);
double3 __ovld __cnfn convert_double3_rte(ulong3);
double3 __ovld __cnfn convert_double3_rte(ushort3);
double3 __ovld __cnfn convert_double3_rtn(char3);
double3 __ovld __cnfn convert_double3_rtn(double3);
double3 __ovld __cnfn convert_double3_rtn(float3);
double3 __ovld __cnfn convert_double3_rtn(int3);
double3 __ovld __cnfn convert_double3_rtn(long3);
double3 __ovld __cnfn convert_double3_rtn(short3);
double3 __ovld __cnfn convert_double3_rtn(uchar3);
double3 __ovld __cnfn convert_double3_rtn(uint3);
double3 __ovld __cnfn convert_double3_rtn(ulong3);
double3 __ovld __cnfn convert_double3_rtn(ushort3);
double3 __ovld __cnfn convert_double3_rtp(char3);
double3 __ovld __cnfn convert_double3_rtp(double3);
double3 __ovld __cnfn convert_double3_rtp(float3);
double3 __ovld __cnfn convert_double3_rtp(int3);
double3 __ovld __cnfn convert_double3_rtp(long3);
double3 __ovld __cnfn convert_double3_rtp(short3);
double3 __ovld __cnfn convert_double3_rtp(uchar3);
double3 __ovld __cnfn convert_double3_rtp(uint3);
double3 __ovld __cnfn convert_double3_rtp(ulong3);
double3 __ovld __cnfn convert_double3_rtp(ushort3);
double3 __ovld __cnfn convert_double3_rtz(char3);
double3 __ovld __cnfn convert_double3_rtz(double3);
double3 __ovld __cnfn convert_double3_rtz(float3);
double3 __ovld __cnfn convert_double3_rtz(int3);
double3 __ovld __cnfn convert_double3_rtz(long3);
double3 __ovld __cnfn convert_double3_rtz(short3);
double3 __ovld __cnfn convert_double3_rtz(uchar3);
double3 __ovld __cnfn convert_double3_rtz(uint3);
double3 __ovld __cnfn convert_double3_rtz(ulong3);
double3 __ovld __cnfn convert_double3_rtz(ushort3);
double4 __ovld __cnfn convert_double4(char4);
double4 __ovld __cnfn convert_double4(double4);
double4 __ovld __cnfn convert_double4(float4);
double4 __ovld __cnfn convert_double4(int4);
double4 __ovld __cnfn convert_double4(long4);
double4 __ovld __cnfn convert_double4(short4);
double4 __ovld __cnfn convert_double4(uchar4);
double4 __ovld __cnfn convert_double4(uint4);
double4 __ovld __cnfn convert_double4(ulong4);
double4 __ovld __cnfn convert_double4(ushort4);
double4 __ovld __cnfn convert_double4_rte(char4);
double4 __ovld __cnfn convert_double4_rte(double4);
double4 __ovld __cnfn convert_double4_rte(float4);
double4 __ovld __cnfn convert_double4_rte(int4);
double4 __ovld __cnfn convert_double4_rte(long4);
double4 __ovld __cnfn convert_double4_rte(short4);
double4 __ovld __cnfn convert_double4_rte(uchar4);
double4 __ovld __cnfn convert_double4_rte(uint4);
double4 __ovld __cnfn convert_double4_rte(ulong4);
double4 __ovld __cnfn convert_double4_rte(ushort4);
double4 __ovld __cnfn convert_double4_rtn(char4);
double4 __ovld __cnfn convert_double4_rtn(double4);
double4 __ovld __cnfn convert_double4_rtn(float4);
double4 __ovld __cnfn convert_double4_rtn(int4);
double4 __ovld __cnfn convert_double4_rtn(long4);
double4 __ovld __cnfn convert_double4_rtn(short4);
double4 __ovld __cnfn convert_double4_rtn(uchar4);
double4 __ovld __cnfn convert_double4_rtn(uint4);
double4 __ovld __cnfn convert_double4_rtn(ulong4);
double4 __ovld __cnfn convert_double4_rtn(ushort4);
double4 __ovld __cnfn convert_double4_rtp(char4);
double4 __ovld __cnfn convert_double4_rtp(double4);
double4 __ovld __cnfn convert_double4_rtp(float4);
double4 __ovld __cnfn convert_double4_rtp(int4);
double4 __ovld __cnfn convert_double4_rtp(long4);
double4 __ovld __cnfn convert_double4_rtp(short4);
double4 __ovld __cnfn convert_double4_rtp(uchar4);
double4 __ovld __cnfn convert_double4_rtp(uint4);
double4 __ovld __cnfn convert_double4_rtp(ulong4);
double4 __ovld __cnfn convert_double4_rtp(ushort4);
double4 __ovld __cnfn convert_double4_rtz(char4);
double4 __ovld __cnfn convert_double4_rtz(double4);
double4 __ovld __cnfn convert_double4_rtz(float4);
double4 __ovld __cnfn convert_double4_rtz(int4);
double4 __ovld __cnfn convert_double4_rtz(long4);
double4 __ovld __cnfn convert_double4_rtz(short4);
double4 __ovld __cnfn convert_double4_rtz(uchar4);
double4 __ovld __cnfn convert_double4_rtz(uint4);
double4 __ovld __cnfn convert_double4_rtz(ulong4);
double4 __ovld __cnfn convert_double4_rtz(ushort4);
double8 __ovld __cnfn convert_double8(char8);
double8 __ovld __cnfn convert_double8(double8);
double8 __ovld __cnfn convert_double8(float8);
double8 __ovld __cnfn convert_double8(int8);
double8 __ovld __cnfn convert_double8(long8);
double8 __ovld __cnfn convert_double8(short8);
double8 __ovld __cnfn convert_double8(uchar8);
double8 __ovld __cnfn convert_double8(uint8);
double8 __ovld __cnfn convert_double8(ulong8);
double8 __ovld __cnfn convert_double8(ushort8);
double8 __ovld __cnfn convert_double8_rte(char8);
double8 __ovld __cnfn convert_double8_rte(double8);
double8 __ovld __cnfn convert_double8_rte(float8);
double8 __ovld __cnfn convert_double8_rte(int8);
double8 __ovld __cnfn convert_double8_rte(long8);
double8 __ovld __cnfn convert_double8_rte(short8);
double8 __ovld __cnfn convert_double8_rte(uchar8);
double8 __ovld __cnfn convert_double8_rte(uint8);
double8 __ovld __cnfn convert_double8_rte(ulong8);
double8 __ovld __cnfn convert_double8_rte(ushort8);
double8 __ovld __cnfn convert_double8_rtn(char8);
double8 __ovld __cnfn convert_double8_rtn(double8);
double8 __ovld __cnfn convert_double8_rtn(float8);
double8 __ovld __cnfn convert_double8_rtn(int8);
double8 __ovld __cnfn convert_double8_rtn(long8);
double8 __ovld __cnfn convert_double8_rtn(short8);
double8 __ovld __cnfn convert_double8_rtn(uchar8);
double8 __ovld __cnfn convert_double8_rtn(uint8);
double8 __ovld __cnfn convert_double8_rtn(ulong8);
double8 __ovld __cnfn convert_double8_rtn(ushort8);
double8 __ovld __cnfn convert_double8_rtp(char8);
double8 __ovld __cnfn convert_double8_rtp(double8);
double8 __ovld __cnfn convert_double8_rtp(float8);
double8 __ovld __cnfn convert_double8_rtp(int8);
double8 __ovld __cnfn convert_double8_rtp(long8);
double8 __ovld __cnfn convert_double8_rtp(short8);
double8 __ovld __cnfn convert_double8_rtp(uchar8);
double8 __ovld __cnfn convert_double8_rtp(uint8);
double8 __ovld __cnfn convert_double8_rtp(ulong8);
double8 __ovld __cnfn convert_double8_rtp(ushort8);
double8 __ovld __cnfn convert_double8_rtz(char8);
double8 __ovld __cnfn convert_double8_rtz(double8);
double8 __ovld __cnfn convert_double8_rtz(float8);
double8 __ovld __cnfn convert_double8_rtz(int8);
double8 __ovld __cnfn convert_double8_rtz(long8);
double8 __ovld __cnfn convert_double8_rtz(short8);
double8 __ovld __cnfn convert_double8_rtz(uchar8);
double8 __ovld __cnfn convert_double8_rtz(uint8);
double8 __ovld __cnfn convert_double8_rtz(ulong8);
double8 __ovld __cnfn convert_double8_rtz(ushort8);
double16 __ovld __cnfn convert_double16(char16);
double16 __ovld __cnfn convert_double16(double16);
double16 __ovld __cnfn convert_double16(float16);
double16 __ovld __cnfn convert_double16(int16);
double16 __ovld __cnfn convert_double16(long16);
double16 __ovld __cnfn convert_double16(short16);
double16 __ovld __cnfn convert_double16(uchar16);
double16 __ovld __cnfn convert_double16(uint16);
double16 __ovld __cnfn convert_double16(ulong16);
double16 __ovld __cnfn convert_double16(ushort16);
double16 __ovld __cnfn convert_double16_rte(char16);
double16 __ovld __cnfn convert_double16_rte(double16);
double16 __ovld __cnfn convert_double16_rte(float16);
double16 __ovld __cnfn convert_double16_rte(int16);
double16 __ovld __cnfn convert_double16_rte(long16);
double16 __ovld __cnfn convert_double16_rte(short16);
double16 __ovld __cnfn convert_double16_rte(uchar16);
double16 __ovld __cnfn convert_double16_rte(uint16);
double16 __ovld __cnfn convert_double16_rte(ulong16);
double16 __ovld __cnfn convert_double16_rte(ushort16);
double16 __ovld __cnfn convert_double16_rtn(char16);
double16 __ovld __cnfn convert_double16_rtn(double16);
double16 __ovld __cnfn convert_double16_rtn(float16);
double16 __ovld __cnfn convert_double16_rtn(int16);
double16 __ovld __cnfn convert_double16_rtn(long16);
double16 __ovld __cnfn convert_double16_rtn(short16);
double16 __ovld __cnfn convert_double16_rtn(uchar16);
double16 __ovld __cnfn convert_double16_rtn(uint16);
double16 __ovld __cnfn convert_double16_rtn(ulong16);
double16 __ovld __cnfn convert_double16_rtn(ushort16);
double16 __ovld __cnfn convert_double16_rtp(char16);
double16 __ovld __cnfn convert_double16_rtp(double16);
double16 __ovld __cnfn convert_double16_rtp(float16);
double16 __ovld __cnfn convert_double16_rtp(int16);
double16 __ovld __cnfn convert_double16_rtp(long16);
double16 __ovld __cnfn convert_double16_rtp(short16);
double16 __ovld __cnfn convert_double16_rtp(uchar16);
double16 __ovld __cnfn convert_double16_rtp(uint16);
double16 __ovld __cnfn convert_double16_rtp(ulong16);
double16 __ovld __cnfn convert_double16_rtp(ushort16);
double16 __ovld __cnfn convert_double16_rtz(char16);
double16 __ovld __cnfn convert_double16_rtz(double16);
double16 __ovld __cnfn convert_double16_rtz(float16);
double16 __ovld __cnfn convert_double16_rtz(int16);
double16 __ovld __cnfn convert_double16_rtz(long16);
double16 __ovld __cnfn convert_double16_rtz(short16);
double16 __ovld __cnfn convert_double16_rtz(uchar16);
double16 __ovld __cnfn convert_double16_rtz(uint16);
double16 __ovld __cnfn convert_double16_rtz(ulong16);
double16 __ovld __cnfn convert_double16_rtz(ushort16);
#endif //cl_khr_fp64

#ifdef cl_khr_fp16
// Convert half types to non-double types.
uchar __ovld __cnfn convert_uchar(half);
uchar __ovld __cnfn convert_uchar_rte(half);
uchar __ovld __cnfn convert_uchar_rtp(half);
uchar __ovld __cnfn convert_uchar_rtn(half);
uchar __ovld __cnfn convert_uchar_rtz(half);
uchar __ovld __cnfn convert_uchar_sat(half);
uchar __ovld __cnfn convert_uchar_sat_rte(half);
uchar __ovld __cnfn convert_uchar_sat_rtp(half);
uchar __ovld __cnfn convert_uchar_sat_rtn(half);
uchar __ovld __cnfn convert_uchar_sat_rtz(half);
uchar2 __ovld __cnfn convert_uchar2(half2);
uchar2 __ovld __cnfn convert_uchar2_rte(half2);
uchar2 __ovld __cnfn convert_uchar2_rtp(half2);
uchar2 __ovld __cnfn convert_uchar2_rtn(half2);
uchar2 __ovld __cnfn convert_uchar2_rtz(half2);
uchar2 __ovld __cnfn convert_uchar2_sat(half2);
uchar2 __ovld __cnfn convert_uchar2_sat_rte(half2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtp(half2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtn(half2);
uchar2 __ovld __cnfn convert_uchar2_sat_rtz(half2);
uchar3 __ovld __cnfn convert_uchar3(half3);
uchar3 __ovld __cnfn convert_uchar3_rte(half3);
uchar3 __ovld __cnfn convert_uchar3_rtp(half3);
uchar3 __ovld __cnfn convert_uchar3_rtn(half3);
uchar3 __ovld __cnfn convert_uchar3_rtz(half3);
uchar3 __ovld __cnfn convert_uchar3_sat(half3);
uchar3 __ovld __cnfn convert_uchar3_sat_rte(half3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtp(half3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtn(half3);
uchar3 __ovld __cnfn convert_uchar3_sat_rtz(half3);
uchar4 __ovld __cnfn convert_uchar4(half4);
uchar4 __ovld __cnfn convert_uchar4_rte(half4);
uchar4 __ovld __cnfn convert_uchar4_rtp(half4);
uchar4 __ovld __cnfn convert_uchar4_rtn(half4);
uchar4 __ovld __cnfn convert_uchar4_rtz(half4);
uchar4 __ovld __cnfn convert_uchar4_sat(half4);
uchar4 __ovld __cnfn convert_uchar4_sat_rte(half4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtp(half4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtn(half4);
uchar4 __ovld __cnfn convert_uchar4_sat_rtz(half4);
uchar8 __ovld __cnfn convert_uchar8(half8);
uchar8 __ovld __cnfn convert_uchar8_rte(half8);
uchar8 __ovld __cnfn convert_uchar8_rtp(half8);
uchar8 __ovld __cnfn convert_uchar8_rtn(half8);
uchar8 __ovld __cnfn convert_uchar8_rtz(half8);
uchar8 __ovld __cnfn convert_uchar8_sat(half8);
uchar8 __ovld __cnfn convert_uchar8_sat_rte(half8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtp(half8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtn(half8);
uchar8 __ovld __cnfn convert_uchar8_sat_rtz(half8);
uchar16 __ovld __cnfn convert_uchar16(half16);
uchar16 __ovld __cnfn convert_uchar16_rte(half16);
uchar16 __ovld __cnfn convert_uchar16_rtp(half16);
uchar16 __ovld __cnfn convert_uchar16_rtn(half16);
uchar16 __ovld __cnfn convert_uchar16_rtz(half16);
uchar16 __ovld __cnfn convert_uchar16_sat(half16);
uchar16 __ovld __cnfn convert_uchar16_sat_rte(half16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtp(half16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtn(half16);
uchar16 __ovld __cnfn convert_uchar16_sat_rtz(half16);
ushort __ovld __cnfn convert_ushort(half);
ushort __ovld __cnfn convert_ushort_rte(half);
ushort __ovld __cnfn convert_ushort_rtp(half);
ushort __ovld __cnfn convert_ushort_rtn(half);
ushort __ovld __cnfn convert_ushort_rtz(half);
ushort __ovld __cnfn convert_ushort_sat(half);
ushort __ovld __cnfn convert_ushort_sat_rte(half);
ushort __ovld __cnfn convert_ushort_sat_rtp(half);
ushort __ovld __cnfn convert_ushort_sat_rtn(half);
ushort __ovld __cnfn convert_ushort_sat_rtz(half);
ushort2 __ovld __cnfn convert_ushort2(half2);
ushort2 __ovld __cnfn convert_ushort2_rte(half2);
ushort2 __ovld __cnfn convert_ushort2_rtp(half2);
ushort2 __ovld __cnfn convert_ushort2_rtn(half2);
ushort2 __ovld __cnfn convert_ushort2_rtz(half2);
ushort2 __ovld __cnfn convert_ushort2_sat(half2);
ushort2 __ovld __cnfn convert_ushort2_sat_rte(half2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtp(half2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtn(half2);
ushort2 __ovld __cnfn convert_ushort2_sat_rtz(half2);
ushort3 __ovld __cnfn convert_ushort3(half3);
ushort3 __ovld __cnfn convert_ushort3_rte(half3);
ushort3 __ovld __cnfn convert_ushort3_rtp(half3);
ushort3 __ovld __cnfn convert_ushort3_rtn(half3);
ushort3 __ovld __cnfn convert_ushort3_rtz(half3);
ushort3 __ovld __cnfn convert_ushort3_sat(half3);
ushort3 __ovld __cnfn convert_ushort3_sat_rte(half3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtp(half3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtn(half3);
ushort3 __ovld __cnfn convert_ushort3_sat_rtz(half3);
ushort4 __ovld __cnfn convert_ushort4(half4);
ushort4 __ovld __cnfn convert_ushort4_rte(half4);
ushort4 __ovld __cnfn convert_ushort4_rtp(half4);
ushort4 __ovld __cnfn convert_ushort4_rtn(half4);
ushort4 __ovld __cnfn convert_ushort4_rtz(half4);
ushort4 __ovld __cnfn convert_ushort4_sat(half4);
ushort4 __ovld __cnfn convert_ushort4_sat_rte(half4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtp(half4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtn(half4);
ushort4 __ovld __cnfn convert_ushort4_sat_rtz(half4);
ushort8 __ovld __cnfn convert_ushort8(half8);
ushort8 __ovld __cnfn convert_ushort8_rte(half8);
ushort8 __ovld __cnfn convert_ushort8_rtp(half8);
ushort8 __ovld __cnfn convert_ushort8_rtn(half8);
ushort8 __ovld __cnfn convert_ushort8_rtz(half8);
ushort8 __ovld __cnfn convert_ushort8_sat(half8);
ushort8 __ovld __cnfn convert_ushort8_sat_rte(half8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtp(half8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtn(half8);
ushort8 __ovld __cnfn convert_ushort8_sat_rtz(half8);
ushort16 __ovld __cnfn convert_ushort16(half16);
ushort16 __ovld __cnfn convert_ushort16_rte(half16);
ushort16 __ovld __cnfn convert_ushort16_rtp(half16);
ushort16 __ovld __cnfn convert_ushort16_rtn(half16);
ushort16 __ovld __cnfn convert_ushort16_rtz(half16);
ushort16 __ovld __cnfn convert_ushort16_sat(half16);
ushort16 __ovld __cnfn convert_ushort16_sat_rte(half16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtp(half16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtn(half16);
ushort16 __ovld __cnfn convert_ushort16_sat_rtz(half16);
uint __ovld __cnfn convert_uint(half);
uint __ovld __cnfn convert_uint_rte(half);
uint __ovld __cnfn convert_uint_rtp(half);
uint __ovld __cnfn convert_uint_rtn(half);
uint __ovld __cnfn convert_uint_rtz(half);
uint __ovld __cnfn convert_uint_sat(half);
uint __ovld __cnfn convert_uint_sat_rte(half);
uint __ovld __cnfn convert_uint_sat_rtp(half);
uint __ovld __cnfn convert_uint_sat_rtn(half);
uint __ovld __cnfn convert_uint_sat_rtz(half);
uint2 __ovld __cnfn convert_uint2(half2);
uint2 __ovld __cnfn convert_uint2_rte(half2);
uint2 __ovld __cnfn convert_uint2_rtp(half2);
uint2 __ovld __cnfn convert_uint2_rtn(half2);
uint2 __ovld __cnfn convert_uint2_rtz(half2);
uint2 __ovld __cnfn convert_uint2_sat(half2);
uint2 __ovld __cnfn convert_uint2_sat_rte(half2);
uint2 __ovld __cnfn convert_uint2_sat_rtp(half2);
uint2 __ovld __cnfn convert_uint2_sat_rtn(half2);
uint2 __ovld __cnfn convert_uint2_sat_rtz(half2);
uint3 __ovld __cnfn convert_uint3(half3);
uint3 __ovld __cnfn convert_uint3_rte(half3);
uint3 __ovld __cnfn convert_uint3_rtp(half3);
uint3 __ovld __cnfn convert_uint3_rtn(half3);
uint3 __ovld __cnfn convert_uint3_rtz(half3);
uint3 __ovld __cnfn convert_uint3_sat(half3);
uint3 __ovld __cnfn convert_uint3_sat_rte(half3);
uint3 __ovld __cnfn convert_uint3_sat_rtp(half3);
uint3 __ovld __cnfn convert_uint3_sat_rtn(half3);
uint3 __ovld __cnfn convert_uint3_sat_rtz(half3);
uint4 __ovld __cnfn convert_uint4(half4);
uint4 __ovld __cnfn convert_uint4_rte(half4);
uint4 __ovld __cnfn convert_uint4_rtp(half4);
uint4 __ovld __cnfn convert_uint4_rtn(half4);
uint4 __ovld __cnfn convert_uint4_rtz(half4);
uint4 __ovld __cnfn convert_uint4_sat(half4);
uint4 __ovld __cnfn convert_uint4_sat_rte(half4);
uint4 __ovld __cnfn convert_uint4_sat_rtp(half4);
uint4 __ovld __cnfn convert_uint4_sat_rtn(half4);
uint4 __ovld __cnfn convert_uint4_sat_rtz(half4);
uint8 __ovld __cnfn convert_uint8(half8);
uint8 __ovld __cnfn convert_uint8_rte(half8);
uint8 __ovld __cnfn convert_uint8_rtp(half8);
uint8 __ovld __cnfn convert_uint8_rtn(half8);
uint8 __ovld __cnfn convert_uint8_rtz(half8);
uint8 __ovld __cnfn convert_uint8_sat(half8);
uint8 __ovld __cnfn convert_uint8_sat_rte(half8);
uint8 __ovld __cnfn convert_uint8_sat_rtp(half8);
uint8 __ovld __cnfn convert_uint8_sat_rtn(half8);
uint8 __ovld __cnfn convert_uint8_sat_rtz(half8);
uint16 __ovld __cnfn convert_uint16(half16);
uint16 __ovld __cnfn convert_uint16_rte(half16);
uint16 __ovld __cnfn convert_uint16_rtp(half16);
uint16 __ovld __cnfn convert_uint16_rtn(half16);
uint16 __ovld __cnfn convert_uint16_rtz(half16);
uint16 __ovld __cnfn convert_uint16_sat(half16);
uint16 __ovld __cnfn convert_uint16_sat_rte(half16);
uint16 __ovld __cnfn convert_uint16_sat_rtp(half16);
uint16 __ovld __cnfn convert_uint16_sat_rtn(half16);
uint16 __ovld __cnfn convert_uint16_sat_rtz(half16);
ulong __ovld __cnfn convert_ulong(half);
ulong __ovld __cnfn convert_ulong_rte(half);
ulong __ovld __cnfn convert_ulong_rtp(half);
ulong __ovld __cnfn convert_ulong_rtn(half);
ulong __ovld __cnfn convert_ulong_rtz(half);
ulong __ovld __cnfn convert_ulong_sat(half);
ulong __ovld __cnfn convert_ulong_sat_rte(half);
ulong __ovld __cnfn convert_ulong_sat_rtp(half);
ulong __ovld __cnfn convert_ulong_sat_rtn(half);
ulong __ovld __cnfn convert_ulong_sat_rtz(half);
ulong2 __ovld __cnfn convert_ulong2(half2);
ulong2 __ovld __cnfn convert_ulong2_rte(half2);
ulong2 __ovld __cnfn convert_ulong2_rtp(half2);
ulong2 __ovld __cnfn convert_ulong2_rtn(half2);
ulong2 __ovld __cnfn convert_ulong2_rtz(half2);
ulong2 __ovld __cnfn convert_ulong2_sat(half2);
ulong2 __ovld __cnfn convert_ulong2_sat_rte(half2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtp(half2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtn(half2);
ulong2 __ovld __cnfn convert_ulong2_sat_rtz(half2);
ulong3 __ovld __cnfn convert_ulong3(half3);
ulong3 __ovld __cnfn convert_ulong3_rte(half3);
ulong3 __ovld __cnfn convert_ulong3_rtp(half3);
ulong3 __ovld __cnfn convert_ulong3_rtn(half3);
ulong3 __ovld __cnfn convert_ulong3_rtz(half3);
ulong3 __ovld __cnfn convert_ulong3_sat(half3);
ulong3 __ovld __cnfn convert_ulong3_sat_rte(half3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtp(half3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtn(half3);
ulong3 __ovld __cnfn convert_ulong3_sat_rtz(half3);
ulong4 __ovld __cnfn convert_ulong4(half4);
ulong4 __ovld __cnfn convert_ulong4_rte(half4);
ulong4 __ovld __cnfn convert_ulong4_rtp(half4);
ulong4 __ovld __cnfn convert_ulong4_rtn(half4);
ulong4 __ovld __cnfn convert_ulong4_rtz(half4);
ulong4 __ovld __cnfn convert_ulong4_sat(half4);
ulong4 __ovld __cnfn convert_ulong4_sat_rte(half4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtp(half4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtn(half4);
ulong4 __ovld __cnfn convert_ulong4_sat_rtz(half4);
ulong8 __ovld __cnfn convert_ulong8(half8);
ulong8 __ovld __cnfn convert_ulong8_rte(half8);
ulong8 __ovld __cnfn convert_ulong8_rtp(half8);
ulong8 __ovld __cnfn convert_ulong8_rtn(half8);
ulong8 __ovld __cnfn convert_ulong8_rtz(half8);
ulong8 __ovld __cnfn convert_ulong8_sat(half8);
ulong8 __ovld __cnfn convert_ulong8_sat_rte(half8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtp(half8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtn(half8);
ulong8 __ovld __cnfn convert_ulong8_sat_rtz(half8);
ulong16 __ovld __cnfn convert_ulong16(half16);
ulong16 __ovld __cnfn convert_ulong16_rte(half16);
ulong16 __ovld __cnfn convert_ulong16_rtp(half16);
ulong16 __ovld __cnfn convert_ulong16_rtn(half16);
ulong16 __ovld __cnfn convert_ulong16_rtz(half16);
ulong16 __ovld __cnfn convert_ulong16_sat(half16);
ulong16 __ovld __cnfn convert_ulong16_sat_rte(half16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtp(half16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtn(half16);
ulong16 __ovld __cnfn convert_ulong16_sat_rtz(half16);
char __ovld __cnfn convert_char(half);
char __ovld __cnfn convert_char_rte(half);
char __ovld __cnfn convert_char_rtp(half);
char __ovld __cnfn convert_char_rtn(half);
char __ovld __cnfn convert_char_rtz(half);
char __ovld __cnfn convert_char_sat(half);
char __ovld __cnfn convert_char_sat_rte(half);
char __ovld __cnfn convert_char_sat_rtp(half);
char __ovld __cnfn convert_char_sat_rtn(half);
char __ovld __cnfn convert_char_sat_rtz(half);
char2 __ovld __cnfn convert_char2(half2);
char2 __ovld __cnfn convert_char2_rte(half2);
char2 __ovld __cnfn convert_char2_rtp(half2);
char2 __ovld __cnfn convert_char2_rtn(half2);
char2 __ovld __cnfn convert_char2_rtz(half2);
char2 __ovld __cnfn convert_char2_sat(half2);
char2 __ovld __cnfn convert_char2_sat_rte(half2);
char2 __ovld __cnfn convert_char2_sat_rtp(half2);
char2 __ovld __cnfn convert_char2_sat_rtn(half2);
char2 __ovld __cnfn convert_char2_sat_rtz(half2);
char3 __ovld __cnfn convert_char3(half3);
char3 __ovld __cnfn convert_char3_rte(half3);
char3 __ovld __cnfn convert_char3_rtp(half3);
char3 __ovld __cnfn convert_char3_rtn(half3);
char3 __ovld __cnfn convert_char3_rtz(half3);
char3 __ovld __cnfn convert_char3_sat(half3);
char3 __ovld __cnfn convert_char3_sat_rte(half3);
char3 __ovld __cnfn convert_char3_sat_rtp(half3);
char3 __ovld __cnfn convert_char3_sat_rtn(half3);
char3 __ovld __cnfn convert_char3_sat_rtz(half3);
char4 __ovld __cnfn convert_char4(half4);
char4 __ovld __cnfn convert_char4_rte(half4);
char4 __ovld __cnfn convert_char4_rtp(half4);
char4 __ovld __cnfn convert_char4_rtn(half4);
char4 __ovld __cnfn convert_char4_rtz(half4);
char4 __ovld __cnfn convert_char4_sat(half4);
char4 __ovld __cnfn convert_char4_sat_rte(half4);
char4 __ovld __cnfn convert_char4_sat_rtp(half4);
char4 __ovld __cnfn convert_char4_sat_rtn(half4);
char4 __ovld __cnfn convert_char4_sat_rtz(half4);
char8 __ovld __cnfn convert_char8(half8);
char8 __ovld __cnfn convert_char8_rte(half8);
char8 __ovld __cnfn convert_char8_rtp(half8);
char8 __ovld __cnfn convert_char8_rtn(half8);
char8 __ovld __cnfn convert_char8_rtz(half8);
char8 __ovld __cnfn convert_char8_sat(half8);
char8 __ovld __cnfn convert_char8_sat_rte(half8);
char8 __ovld __cnfn convert_char8_sat_rtp(half8);
char8 __ovld __cnfn convert_char8_sat_rtn(half8);
char8 __ovld __cnfn convert_char8_sat_rtz(half8);
char16 __ovld __cnfn convert_char16(half16);
char16 __ovld __cnfn convert_char16_rte(half16);
char16 __ovld __cnfn convert_char16_rtp(half16);
char16 __ovld __cnfn convert_char16_rtn(half16);
char16 __ovld __cnfn convert_char16_rtz(half16);
char16 __ovld __cnfn convert_char16_sat(half16);
char16 __ovld __cnfn convert_char16_sat_rte(half16);
char16 __ovld __cnfn convert_char16_sat_rtp(half16);
char16 __ovld __cnfn convert_char16_sat_rtn(half16);
char16 __ovld __cnfn convert_char16_sat_rtz(half16);
short __ovld __cnfn convert_short(half);
short __ovld __cnfn convert_short_rte(half);
short __ovld __cnfn convert_short_rtp(half);
short __ovld __cnfn convert_short_rtn(half);
short __ovld __cnfn convert_short_rtz(half);
short __ovld __cnfn convert_short_sat(half);
short __ovld __cnfn convert_short_sat_rte(half);
short __ovld __cnfn convert_short_sat_rtp(half);
short __ovld __cnfn convert_short_sat_rtn(half);
short __ovld __cnfn convert_short_sat_rtz(half);
short2 __ovld __cnfn convert_short2(half2);
short2 __ovld __cnfn convert_short2_rte(half2);
short2 __ovld __cnfn convert_short2_rtp(half2);
short2 __ovld __cnfn convert_short2_rtn(half2);
short2 __ovld __cnfn convert_short2_rtz(half2);
short2 __ovld __cnfn convert_short2_sat(half2);
short2 __ovld __cnfn convert_short2_sat_rte(half2);
short2 __ovld __cnfn convert_short2_sat_rtp(half2);
short2 __ovld __cnfn convert_short2_sat_rtn(half2);
short2 __ovld __cnfn convert_short2_sat_rtz(half2);
short3 __ovld __cnfn convert_short3(half3);
short3 __ovld __cnfn convert_short3_rte(half3);
short3 __ovld __cnfn convert_short3_rtp(half3);
short3 __ovld __cnfn convert_short3_rtn(half3);
short3 __ovld __cnfn convert_short3_rtz(half3);
short3 __ovld __cnfn convert_short3_sat(half3);
short3 __ovld __cnfn convert_short3_sat_rte(half3);
short3 __ovld __cnfn convert_short3_sat_rtp(half3);
short3 __ovld __cnfn convert_short3_sat_rtn(half3);
short3 __ovld __cnfn convert_short3_sat_rtz(half3);
short4 __ovld __cnfn convert_short4(half4);
short4 __ovld __cnfn convert_short4_rte(half4);
short4 __ovld __cnfn convert_short4_rtp(half4);
short4 __ovld __cnfn convert_short4_rtn(half4);
short4 __ovld __cnfn convert_short4_rtz(half4);
short4 __ovld __cnfn convert_short4_sat(half4);
short4 __ovld __cnfn convert_short4_sat_rte(half4);
short4 __ovld __cnfn convert_short4_sat_rtp(half4);
short4 __ovld __cnfn convert_short4_sat_rtn(half4);
short4 __ovld __cnfn convert_short4_sat_rtz(half4);
short8 __ovld __cnfn convert_short8(half8);
short8 __ovld __cnfn convert_short8_rte(half8);
short8 __ovld __cnfn convert_short8_rtp(half8);
short8 __ovld __cnfn convert_short8_rtn(half8);
short8 __ovld __cnfn convert_short8_rtz(half8);
short8 __ovld __cnfn convert_short8_sat(half8);
short8 __ovld __cnfn convert_short8_sat_rte(half8);
short8 __ovld __cnfn convert_short8_sat_rtp(half8);
short8 __ovld __cnfn convert_short8_sat_rtn(half8);
short8 __ovld __cnfn convert_short8_sat_rtz(half8);
short16 __ovld __cnfn convert_short16(half16);
short16 __ovld __cnfn convert_short16_rte(half16);
short16 __ovld __cnfn convert_short16_rtp(half16);
short16 __ovld __cnfn convert_short16_rtn(half16);
short16 __ovld __cnfn convert_short16_rtz(half16);
short16 __ovld __cnfn convert_short16_sat(half16);
short16 __ovld __cnfn convert_short16_sat_rte(half16);
short16 __ovld __cnfn convert_short16_sat_rtp(half16);
short16 __ovld __cnfn convert_short16_sat_rtn(half16);
short16 __ovld __cnfn convert_short16_sat_rtz(half16);
int __ovld __cnfn convert_int(half);
int __ovld __cnfn convert_int_rte(half);
int __ovld __cnfn convert_int_rtp(half);
int __ovld __cnfn convert_int_rtn(half);
int __ovld __cnfn convert_int_rtz(half);
int __ovld __cnfn convert_int_sat(half);
int __ovld __cnfn convert_int_sat_rte(half);
int __ovld __cnfn convert_int_sat_rtp(half);
int __ovld __cnfn convert_int_sat_rtn(half);
int __ovld __cnfn convert_int_sat_rtz(half);
int2 __ovld __cnfn convert_int2(half2);
int2 __ovld __cnfn convert_int2_rte(half2);
int2 __ovld __cnfn convert_int2_rtp(half2);
int2 __ovld __cnfn convert_int2_rtn(half2);
int2 __ovld __cnfn convert_int2_rtz(half2);
int2 __ovld __cnfn convert_int2_sat(half2);
int2 __ovld __cnfn convert_int2_sat_rte(half2);
int2 __ovld __cnfn convert_int2_sat_rtp(half2);
int2 __ovld __cnfn convert_int2_sat_rtn(half2);
int2 __ovld __cnfn convert_int2_sat_rtz(half2);
int3 __ovld __cnfn convert_int3(half3);
int3 __ovld __cnfn convert_int3_rte(half3);
int3 __ovld __cnfn convert_int3_rtp(half3);
int3 __ovld __cnfn convert_int3_rtn(half3);
int3 __ovld __cnfn convert_int3_rtz(half3);
int3 __ovld __cnfn convert_int3_sat(half3);
int3 __ovld __cnfn convert_int3_sat_rte(half3);
int3 __ovld __cnfn convert_int3_sat_rtp(half3);
int3 __ovld __cnfn convert_int3_sat_rtn(half3);
int3 __ovld __cnfn convert_int3_sat_rtz(half3);
int4 __ovld __cnfn convert_int4(half4);
int4 __ovld __cnfn convert_int4_rte(half4);
int4 __ovld __cnfn convert_int4_rtp(half4);
int4 __ovld __cnfn convert_int4_rtn(half4);
int4 __ovld __cnfn convert_int4_rtz(half4);
int4 __ovld __cnfn convert_int4_sat(half4);
int4 __ovld __cnfn convert_int4_sat_rte(half4);
int4 __ovld __cnfn convert_int4_sat_rtp(half4);
int4 __ovld __cnfn convert_int4_sat_rtn(half4);
int4 __ovld __cnfn convert_int4_sat_rtz(half4);
int8 __ovld __cnfn convert_int8(half8);
int8 __ovld __cnfn convert_int8_rte(half8);
int8 __ovld __cnfn convert_int8_rtp(half8);
int8 __ovld __cnfn convert_int8_rtn(half8);
int8 __ovld __cnfn convert_int8_rtz(half8);
int8 __ovld __cnfn convert_int8_sat(half8);
int8 __ovld __cnfn convert_int8_sat_rte(half8);
int8 __ovld __cnfn convert_int8_sat_rtp(half8);
int8 __ovld __cnfn convert_int8_sat_rtn(half8);
int8 __ovld __cnfn convert_int8_sat_rtz(half8);
int16 __ovld __cnfn convert_int16(half16);
int16 __ovld __cnfn convert_int16_rte(half16);
int16 __ovld __cnfn convert_int16_rtp(half16);
int16 __ovld __cnfn convert_int16_rtn(half16);
int16 __ovld __cnfn convert_int16_rtz(half16);
int16 __ovld __cnfn convert_int16_sat(half16);
int16 __ovld __cnfn convert_int16_sat_rte(half16);
int16 __ovld __cnfn convert_int16_sat_rtp(half16);
int16 __ovld __cnfn convert_int16_sat_rtn(half16);
int16 __ovld __cnfn convert_int16_sat_rtz(half16);
long __ovld __cnfn convert_long(half);
long __ovld __cnfn convert_long_rte(half);
long __ovld __cnfn convert_long_rtp(half);
long __ovld __cnfn convert_long_rtn(half);
long __ovld __cnfn convert_long_rtz(half);
long __ovld __cnfn convert_long_sat(half);
long __ovld __cnfn convert_long_sat_rte(half);
long __ovld __cnfn convert_long_sat_rtp(half);
long __ovld __cnfn convert_long_sat_rtn(half);
long __ovld __cnfn convert_long_sat_rtz(half);
long2 __ovld __cnfn convert_long2(half2);
long2 __ovld __cnfn convert_long2_rte(half2);
long2 __ovld __cnfn convert_long2_rtp(half2);
long2 __ovld __cnfn convert_long2_rtn(half2);
long2 __ovld __cnfn convert_long2_rtz(half2);
long2 __ovld __cnfn convert_long2_sat(half2);
long2 __ovld __cnfn convert_long2_sat_rte(half2);
long2 __ovld __cnfn convert_long2_sat_rtp(half2);
long2 __ovld __cnfn convert_long2_sat_rtn(half2);
long2 __ovld __cnfn convert_long2_sat_rtz(half2);
long3 __ovld __cnfn convert_long3(half3);
long3 __ovld __cnfn convert_long3_rte(half3);
long3 __ovld __cnfn convert_long3_rtp(half3);
long3 __ovld __cnfn convert_long3_rtn(half3);
long3 __ovld __cnfn convert_long3_rtz(half3);
long3 __ovld __cnfn convert_long3_sat(half3);
long3 __ovld __cnfn convert_long3_sat_rte(half3);
long3 __ovld __cnfn convert_long3_sat_rtp(half3);
long3 __ovld __cnfn convert_long3_sat_rtn(half3);
long3 __ovld __cnfn convert_long3_sat_rtz(half3);
long4 __ovld __cnfn convert_long4(half4);
long4 __ovld __cnfn convert_long4_rte(half4);
long4 __ovld __cnfn convert_long4_rtp(half4);
long4 __ovld __cnfn convert_long4_rtn(half4);
long4 __ovld __cnfn convert_long4_rtz(half4);
long4 __ovld __cnfn convert_long4_sat(half4);
long4 __ovld __cnfn convert_long4_sat_rte(half4);
long4 __ovld __cnfn convert_long4_sat_rtp(half4);
long4 __ovld __cnfn convert_long4_sat_rtn(half4);
long4 __ovld __cnfn convert_long4_sat_rtz(half4);
long8 __ovld __cnfn convert_long8(half8);
long8 __ovld __cnfn convert_long8_rte(half8);
long8 __ovld __cnfn convert_long8_rtp(half8);
long8 __ovld __cnfn convert_long8_rtn(half8);
long8 __ovld __cnfn convert_long8_rtz(half8);
long8 __ovld __cnfn convert_long8_sat(half8);
long8 __ovld __cnfn convert_long8_sat_rte(half8);
long8 __ovld __cnfn convert_long8_sat_rtp(half8);
long8 __ovld __cnfn convert_long8_sat_rtn(half8);
long8 __ovld __cnfn convert_long8_sat_rtz(half8);
long16 __ovld __cnfn convert_long16(half16);
long16 __ovld __cnfn convert_long16_rte(half16);
long16 __ovld __cnfn convert_long16_rtp(half16);
long16 __ovld __cnfn convert_long16_rtn(half16);
long16 __ovld __cnfn convert_long16_rtz(half16);
long16 __ovld __cnfn convert_long16_sat(half16);
long16 __ovld __cnfn convert_long16_sat_rte(half16);
long16 __ovld __cnfn convert_long16_sat_rtp(half16);
long16 __ovld __cnfn convert_long16_sat_rtn(half16);
long16 __ovld __cnfn convert_long16_sat_rtz(half16);
float __ovld __cnfn convert_float(half);
float __ovld __cnfn convert_float_rte(half);
float __ovld __cnfn convert_float_rtp(half);
float __ovld __cnfn convert_float_rtn(half);
float __ovld __cnfn convert_float_rtz(half);
float2 __ovld __cnfn convert_float2(half2);
float2 __ovld __cnfn convert_float2_rte(half2);
float2 __ovld __cnfn convert_float2_rtp(half2);
float2 __ovld __cnfn convert_float2_rtn(half2);
float2 __ovld __cnfn convert_float2_rtz(half2);
float3 __ovld __cnfn convert_float3(half3);
float3 __ovld __cnfn convert_float3_rte(half3);
float3 __ovld __cnfn convert_float3_rtp(half3);
float3 __ovld __cnfn convert_float3_rtn(half3);
float3 __ovld __cnfn convert_float3_rtz(half3);
float4 __ovld __cnfn convert_float4(half4);
float4 __ovld __cnfn convert_float4_rte(half4);
float4 __ovld __cnfn convert_float4_rtp(half4);
float4 __ovld __cnfn convert_float4_rtn(half4);
float4 __ovld __cnfn convert_float4_rtz(half4);
float8 __ovld __cnfn convert_float8(half8);
float8 __ovld __cnfn convert_float8_rte(half8);
float8 __ovld __cnfn convert_float8_rtp(half8);
float8 __ovld __cnfn convert_float8_rtn(half8);
float8 __ovld __cnfn convert_float8_rtz(half8);
float16 __ovld __cnfn convert_float16(half16);
float16 __ovld __cnfn convert_float16_rte(half16);
float16 __ovld __cnfn convert_float16_rtp(half16);
float16 __ovld __cnfn convert_float16_rtn(half16);
float16 __ovld __cnfn convert_float16_rtz(half16);

// Convert non-double types to half types.
half __ovld __cnfn convert_half(uchar);
half __ovld __cnfn convert_half(ushort);
half __ovld __cnfn convert_half(uint);
half __ovld __cnfn convert_half(ulong);
half __ovld __cnfn convert_half(char);
half __ovld __cnfn convert_half(short);
half __ovld __cnfn convert_half(int);
half __ovld __cnfn convert_half(long);
half __ovld __cnfn convert_half(float);
half __ovld __cnfn convert_half(half);
half __ovld __cnfn convert_half_rte(uchar);
half __ovld __cnfn convert_half_rte(ushort);
half __ovld __cnfn convert_half_rte(uint);
half __ovld __cnfn convert_half_rte(ulong);
half __ovld __cnfn convert_half_rte(char);
half __ovld __cnfn convert_half_rte(short);
half __ovld __cnfn convert_half_rte(int);
half __ovld __cnfn convert_half_rte(long);
half __ovld __cnfn convert_half_rte(float);
half __ovld __cnfn convert_half_rte(half);
half __ovld __cnfn convert_half_rtp(uchar);
half __ovld __cnfn convert_half_rtp(ushort);
half __ovld __cnfn convert_half_rtp(uint);
half __ovld __cnfn convert_half_rtp(ulong);
half __ovld __cnfn convert_half_rtp(char);
half __ovld __cnfn convert_half_rtp(short);
half __ovld __cnfn convert_half_rtp(int);
half __ovld __cnfn convert_half_rtp(long);
half __ovld __cnfn convert_half_rtp(float);
half __ovld __cnfn convert_half_rtp(half);
half __ovld __cnfn convert_half_rtn(uchar);
half __ovld __cnfn convert_half_rtn(ushort);
half __ovld __cnfn convert_half_rtn(uint);
half __ovld __cnfn convert_half_rtn(ulong);
half __ovld __cnfn convert_half_rtn(char);
half __ovld __cnfn convert_half_rtn(short);
half __ovld __cnfn convert_half_rtn(int);
half __ovld __cnfn convert_half_rtn(long);
half __ovld __cnfn convert_half_rtn(float);
half __ovld __cnfn convert_half_rtn(half);
half __ovld __cnfn convert_half_rtz(uchar);
half __ovld __cnfn convert_half_rtz(ushort);
half __ovld __cnfn convert_half_rtz(uint);
half __ovld __cnfn convert_half_rtz(ulong);
half __ovld __cnfn convert_half_rtz(char);
half __ovld __cnfn convert_half_rtz(short);
half __ovld __cnfn convert_half_rtz(int);
half __ovld __cnfn convert_half_rtz(long);
half __ovld __cnfn convert_half_rtz(float);
half __ovld __cnfn convert_half_rtz(half);
half2 __ovld __cnfn convert_half2(char2);
half2 __ovld __cnfn convert_half2(uchar2);
half2 __ovld __cnfn convert_half2(short2);
half2 __ovld __cnfn convert_half2(ushort2);
half2 __ovld __cnfn convert_half2(int2);
half2 __ovld __cnfn convert_half2(uint2);
half2 __ovld __cnfn convert_half2(long2);
half2 __ovld __cnfn convert_half2(ulong2);
half2 __ovld __cnfn convert_half2(float2);
half2 __ovld __cnfn convert_half2(half2);
half2 __ovld __cnfn convert_half2_rte(char2);
half2 __ovld __cnfn convert_half2_rte(uchar2);
half2 __ovld __cnfn convert_half2_rte(short2);
half2 __ovld __cnfn convert_half2_rte(ushort2);
half2 __ovld __cnfn convert_half2_rte(int2);
half2 __ovld __cnfn convert_half2_rte(uint2);
half2 __ovld __cnfn convert_half2_rte(long2);
half2 __ovld __cnfn convert_half2_rte(ulong2);
half2 __ovld __cnfn convert_half2_rte(float2);
half2 __ovld __cnfn convert_half2_rte(half2);
half2 __ovld __cnfn convert_half2_rtp(char2);
half2 __ovld __cnfn convert_half2_rtp(uchar2);
half2 __ovld __cnfn convert_half2_rtp(short2);
half2 __ovld __cnfn convert_half2_rtp(ushort2);
half2 __ovld __cnfn convert_half2_rtp(int2);
half2 __ovld __cnfn convert_half2_rtp(uint2);
half2 __ovld __cnfn convert_half2_rtp(long2);
half2 __ovld __cnfn convert_half2_rtp(ulong2);
half2 __ovld __cnfn convert_half2_rtp(float2);
half2 __ovld __cnfn convert_half2_rtp(half2);
half2 __ovld __cnfn convert_half2_rtn(char2);
half2 __ovld __cnfn convert_half2_rtn(uchar2);
half2 __ovld __cnfn convert_half2_rtn(short2);
half2 __ovld __cnfn convert_half2_rtn(ushort2);
half2 __ovld __cnfn convert_half2_rtn(int2);
half2 __ovld __cnfn convert_half2_rtn(uint2);
half2 __ovld __cnfn convert_half2_rtn(long2);
half2 __ovld __cnfn convert_half2_rtn(ulong2);
half2 __ovld __cnfn convert_half2_rtn(float2);
half2 __ovld __cnfn convert_half2_rtn(half2);
half2 __ovld __cnfn convert_half2_rtz(char2);
half2 __ovld __cnfn convert_half2_rtz(uchar2);
half2 __ovld __cnfn convert_half2_rtz(short2);
half2 __ovld __cnfn convert_half2_rtz(ushort2);
half2 __ovld __cnfn convert_half2_rtz(int2);
half2 __ovld __cnfn convert_half2_rtz(uint2);
half2 __ovld __cnfn convert_half2_rtz(long2);
half2 __ovld __cnfn convert_half2_rtz(ulong2);
half2 __ovld __cnfn convert_half2_rtz(float2);
half2 __ovld __cnfn convert_half2_rtz(half2);
half3 __ovld __cnfn convert_half3(char3);
half3 __ovld __cnfn convert_half3(uchar3);
half3 __ovld __cnfn convert_half3(short3);
half3 __ovld __cnfn convert_half3(ushort3);
half3 __ovld __cnfn convert_half3(int3);
half3 __ovld __cnfn convert_half3(uint3);
half3 __ovld __cnfn convert_half3(long3);
half3 __ovld __cnfn convert_half3(ulong3);
half3 __ovld __cnfn convert_half3(float3);
half3 __ovld __cnfn convert_half3(half3);
half3 __ovld __cnfn convert_half3_rte(char3);
half3 __ovld __cnfn convert_half3_rte(uchar3);
half3 __ovld __cnfn convert_half3_rte(short3);
half3 __ovld __cnfn convert_half3_rte(ushort3);
half3 __ovld __cnfn convert_half3_rte(int3);
half3 __ovld __cnfn convert_half3_rte(uint3);
half3 __ovld __cnfn convert_half3_rte(long3);
half3 __ovld __cnfn convert_half3_rte(ulong3);
half3 __ovld __cnfn convert_half3_rte(float3);
half3 __ovld __cnfn convert_half3_rte(half3);
half3 __ovld __cnfn convert_half3_rtp(char3);
half3 __ovld __cnfn convert_half3_rtp(uchar3);
half3 __ovld __cnfn convert_half3_rtp(short3);
half3 __ovld __cnfn convert_half3_rtp(ushort3);
half3 __ovld __cnfn convert_half3_rtp(int3);
half3 __ovld __cnfn convert_half3_rtp(uint3);
half3 __ovld __cnfn convert_half3_rtp(long3);
half3 __ovld __cnfn convert_half3_rtp(ulong3);
half3 __ovld __cnfn convert_half3_rtp(float3);
half3 __ovld __cnfn convert_half3_rtp(half3);
half3 __ovld __cnfn convert_half3_rtn(char3);
half3 __ovld __cnfn convert_half3_rtn(uchar3);
half3 __ovld __cnfn convert_half3_rtn(short3);
half3 __ovld __cnfn convert_half3_rtn(ushort3);
half3 __ovld __cnfn convert_half3_rtn(int3);
half3 __ovld __cnfn convert_half3_rtn(uint3);
half3 __ovld __cnfn convert_half3_rtn(long3);
half3 __ovld __cnfn convert_half3_rtn(ulong3);
half3 __ovld __cnfn convert_half3_rtn(float3);
half3 __ovld __cnfn convert_half3_rtn(half3);
half3 __ovld __cnfn convert_half3_rtz(char3);
half3 __ovld __cnfn convert_half3_rtz(uchar3);
half3 __ovld __cnfn convert_half3_rtz(short3);
half3 __ovld __cnfn convert_half3_rtz(ushort3);
half3 __ovld __cnfn convert_half3_rtz(int3);
half3 __ovld __cnfn convert_half3_rtz(uint3);
half3 __ovld __cnfn convert_half3_rtz(long3);
half3 __ovld __cnfn convert_half3_rtz(ulong3);
half3 __ovld __cnfn convert_half3_rtz(float3);
half3 __ovld __cnfn convert_half3_rtz(half3);
half4 __ovld __cnfn convert_half4(char4);
half4 __ovld __cnfn convert_half4(uchar4);
half4 __ovld __cnfn convert_half4(short4);
half4 __ovld __cnfn convert_half4(ushort4);
half4 __ovld __cnfn convert_half4(int4);
half4 __ovld __cnfn convert_half4(uint4);
half4 __ovld __cnfn convert_half4(long4);
half4 __ovld __cnfn convert_half4(ulong4);
half4 __ovld __cnfn convert_half4(float4);
half4 __ovld __cnfn convert_half4(half4);
half4 __ovld __cnfn convert_half4_rte(char4);
half4 __ovld __cnfn convert_half4_rte(uchar4);
half4 __ovld __cnfn convert_half4_rte(short4);
half4 __ovld __cnfn convert_half4_rte(ushort4);
half4 __ovld __cnfn convert_half4_rte(int4);
half4 __ovld __cnfn convert_half4_rte(uint4);
half4 __ovld __cnfn convert_half4_rte(long4);
half4 __ovld __cnfn convert_half4_rte(ulong4);
half4 __ovld __cnfn convert_half4_rte(float4);
half4 __ovld __cnfn convert_half4_rte(half4);
half4 __ovld __cnfn convert_half4_rtp(char4);
half4 __ovld __cnfn convert_half4_rtp(uchar4);
half4 __ovld __cnfn convert_half4_rtp(short4);
half4 __ovld __cnfn convert_half4_rtp(ushort4);
half4 __ovld __cnfn convert_half4_rtp(int4);
half4 __ovld __cnfn convert_half4_rtp(uint4);
half4 __ovld __cnfn convert_half4_rtp(long4);
half4 __ovld __cnfn convert_half4_rtp(ulong4);
half4 __ovld __cnfn convert_half4_rtp(float4);
half4 __ovld __cnfn convert_half4_rtp(half4);
half4 __ovld __cnfn convert_half4_rtn(char4);
half4 __ovld __cnfn convert_half4_rtn(uchar4);
half4 __ovld __cnfn convert_half4_rtn(short4);
half4 __ovld __cnfn convert_half4_rtn(ushort4);
half4 __ovld __cnfn convert_half4_rtn(int4);
half4 __ovld __cnfn convert_half4_rtn(uint4);
half4 __ovld __cnfn convert_half4_rtn(long4);
half4 __ovld __cnfn convert_half4_rtn(ulong4);
half4 __ovld __cnfn convert_half4_rtn(float4);
half4 __ovld __cnfn convert_half4_rtn(half4);
half4 __ovld __cnfn convert_half4_rtz(char4);
half4 __ovld __cnfn convert_half4_rtz(uchar4);
half4 __ovld __cnfn convert_half4_rtz(short4);
half4 __ovld __cnfn convert_half4_rtz(ushort4);
half4 __ovld __cnfn convert_half4_rtz(int4);
half4 __ovld __cnfn convert_half4_rtz(uint4);
half4 __ovld __cnfn convert_half4_rtz(long4);
half4 __ovld __cnfn convert_half4_rtz(ulong4);
half4 __ovld __cnfn convert_half4_rtz(float4);
half4 __ovld __cnfn convert_half4_rtz(half4);
half8 __ovld __cnfn convert_half8(char8);
half8 __ovld __cnfn convert_half8(uchar8);
half8 __ovld __cnfn convert_half8(short8);
half8 __ovld __cnfn convert_half8(ushort8);
half8 __ovld __cnfn convert_half8(int8);
half8 __ovld __cnfn convert_half8(uint8);
half8 __ovld __cnfn convert_half8(long8);
half8 __ovld __cnfn convert_half8(ulong8);
half8 __ovld __cnfn convert_half8(float8);
half8 __ovld __cnfn convert_half8(half8);
half8 __ovld __cnfn convert_half8_rte(char8);
half8 __ovld __cnfn convert_half8_rte(uchar8);
half8 __ovld __cnfn convert_half8_rte(short8);
half8 __ovld __cnfn convert_half8_rte(ushort8);
half8 __ovld __cnfn convert_half8_rte(int8);
half8 __ovld __cnfn convert_half8_rte(uint8);
half8 __ovld __cnfn convert_half8_rte(long8);
half8 __ovld __cnfn convert_half8_rte(ulong8);
half8 __ovld __cnfn convert_half8_rte(float8);
half8 __ovld __cnfn convert_half8_rte(half8);
half8 __ovld __cnfn convert_half8_rtp(char8);
half8 __ovld __cnfn convert_half8_rtp(uchar8);
half8 __ovld __cnfn convert_half8_rtp(short8);
half8 __ovld __cnfn convert_half8_rtp(ushort8);
half8 __ovld __cnfn convert_half8_rtp(int8);
half8 __ovld __cnfn convert_half8_rtp(uint8);
half8 __ovld __cnfn convert_half8_rtp(long8);
half8 __ovld __cnfn convert_half8_rtp(ulong8);
half8 __ovld __cnfn convert_half8_rtp(float8);
half8 __ovld __cnfn convert_half8_rtp(half8);
half8 __ovld __cnfn convert_half8_rtn(char8);
half8 __ovld __cnfn convert_half8_rtn(uchar8);
half8 __ovld __cnfn convert_half8_rtn(short8);
half8 __ovld __cnfn convert_half8_rtn(ushort8);
half8 __ovld __cnfn convert_half8_rtn(int8);
half8 __ovld __cnfn convert_half8_rtn(uint8);
half8 __ovld __cnfn convert_half8_rtn(long8);
half8 __ovld __cnfn convert_half8_rtn(ulong8);
half8 __ovld __cnfn convert_half8_rtn(float8);
half8 __ovld __cnfn convert_half8_rtn(half8);
half8 __ovld __cnfn convert_half8_rtz(char8);
half8 __ovld __cnfn convert_half8_rtz(uchar8);
half8 __ovld __cnfn convert_half8_rtz(short8);
half8 __ovld __cnfn convert_half8_rtz(ushort8);
half8 __ovld __cnfn convert_half8_rtz(int8);
half8 __ovld __cnfn convert_half8_rtz(uint8);
half8 __ovld __cnfn convert_half8_rtz(long8);
half8 __ovld __cnfn convert_half8_rtz(ulong8);
half8 __ovld __cnfn convert_half8_rtz(float8);
half8 __ovld __cnfn convert_half8_rtz(half8);
half16 __ovld __cnfn convert_half16(char16);
half16 __ovld __cnfn convert_half16(uchar16);
half16 __ovld __cnfn convert_half16(short16);
half16 __ovld __cnfn convert_half16(ushort16);
half16 __ovld __cnfn convert_half16(int16);
half16 __ovld __cnfn convert_half16(uint16);
half16 __ovld __cnfn convert_half16(long16);
half16 __ovld __cnfn convert_half16(ulong16);
half16 __ovld __cnfn convert_half16(float16);
half16 __ovld __cnfn convert_half16(half16);
half16 __ovld __cnfn convert_half16_rte(char16);
half16 __ovld __cnfn convert_half16_rte(uchar16);
half16 __ovld __cnfn convert_half16_rte(short16);
half16 __ovld __cnfn convert_half16_rte(ushort16);
half16 __ovld __cnfn convert_half16_rte(int16);
half16 __ovld __cnfn convert_half16_rte(uint16);
half16 __ovld __cnfn convert_half16_rte(long16);
half16 __ovld __cnfn convert_half16_rte(ulong16);
half16 __ovld __cnfn convert_half16_rte(float16);
half16 __ovld __cnfn convert_half16_rte(half16);
half16 __ovld __cnfn convert_half16_rtp(char16);
half16 __ovld __cnfn convert_half16_rtp(uchar16);
half16 __ovld __cnfn convert_half16_rtp(short16);
half16 __ovld __cnfn convert_half16_rtp(ushort16);
half16 __ovld __cnfn convert_half16_rtp(int16);
half16 __ovld __cnfn convert_half16_rtp(uint16);
half16 __ovld __cnfn convert_half16_rtp(long16);
half16 __ovld __cnfn convert_half16_rtp(ulong16);
half16 __ovld __cnfn convert_half16_rtp(float16);
half16 __ovld __cnfn convert_half16_rtp(half16);
half16 __ovld __cnfn convert_half16_rtn(char16);
half16 __ovld __cnfn convert_half16_rtn(uchar16);
half16 __ovld __cnfn convert_half16_rtn(short16);
half16 __ovld __cnfn convert_half16_rtn(ushort16);
half16 __ovld __cnfn convert_half16_rtn(int16);
half16 __ovld __cnfn convert_half16_rtn(uint16);
half16 __ovld __cnfn convert_half16_rtn(long16);
half16 __ovld __cnfn convert_half16_rtn(ulong16);
half16 __ovld __cnfn convert_half16_rtn(float16);
half16 __ovld __cnfn convert_half16_rtn(half16);
half16 __ovld __cnfn convert_half16_rtz(char16);
half16 __ovld __cnfn convert_half16_rtz(uchar16);
half16 __ovld __cnfn convert_half16_rtz(short16);
half16 __ovld __cnfn convert_half16_rtz(ushort16);
half16 __ovld __cnfn convert_half16_rtz(int16);
half16 __ovld __cnfn convert_half16_rtz(uint16);
half16 __ovld __cnfn convert_half16_rtz(long16);
half16 __ovld __cnfn convert_half16_rtz(ulong16);
half16 __ovld __cnfn convert_half16_rtz(float16);
half16 __ovld __cnfn convert_half16_rtz(half16);

// Convert half types to double types.
#ifdef cl_khr_fp64
double __ovld __cnfn convert_double(half);
double __ovld __cnfn convert_double_rte(half);
double __ovld __cnfn convert_double_rtp(half);
double __ovld __cnfn convert_double_rtn(half);
double __ovld __cnfn convert_double_rtz(half);
double2 __ovld __cnfn convert_double2(half2);
double2 __ovld __cnfn convert_double2_rte(half2);
double2 __ovld __cnfn convert_double2_rtp(half2);
double2 __ovld __cnfn convert_double2_rtn(half2);
double2 __ovld __cnfn convert_double2_rtz(half2);
double3 __ovld __cnfn convert_double3(half3);
double3 __ovld __cnfn convert_double3_rte(half3);
double3 __ovld __cnfn convert_double3_rtp(half3);
double3 __ovld __cnfn convert_double3_rtn(half3);
double3 __ovld __cnfn convert_double3_rtz(half3);
double4 __ovld __cnfn convert_double4(half4);
double4 __ovld __cnfn convert_double4_rte(half4);
double4 __ovld __cnfn convert_double4_rtp(half4);
double4 __ovld __cnfn convert_double4_rtn(half4);
double4 __ovld __cnfn convert_double4_rtz(half4);
double8 __ovld __cnfn convert_double8(half8);
double8 __ovld __cnfn convert_double8_rte(half8);
double8 __ovld __cnfn convert_double8_rtp(half8);
double8 __ovld __cnfn convert_double8_rtn(half8);
double8 __ovld __cnfn convert_double8_rtz(half8);
double16 __ovld __cnfn convert_double16(half16);
double16 __ovld __cnfn convert_double16_rte(half16);
double16 __ovld __cnfn convert_double16_rtp(half16);
double16 __ovld __cnfn convert_double16_rtn(half16);
double16 __ovld __cnfn convert_double16_rtz(half16);

// Convert double types to half types.
half __ovld __cnfn convert_half(double);
half __ovld __cnfn convert_half_rte(double);
half __ovld __cnfn convert_half_rtp(double);
half __ovld __cnfn convert_half_rtn(double);
half __ovld __cnfn convert_half_rtz(double);
half2 __ovld __cnfn convert_half2(double2);
half2 __ovld __cnfn convert_half2_rte(double2);
half2 __ovld __cnfn convert_half2_rtp(double2);
half2 __ovld __cnfn convert_half2_rtn(double2);
half2 __ovld __cnfn convert_half2_rtz(double2);
half3 __ovld __cnfn convert_half3(double3);
half3 __ovld __cnfn convert_half3_rte(double3);
half3 __ovld __cnfn convert_half3_rtp(double3);
half3 __ovld __cnfn convert_half3_rtn(double3);
half3 __ovld __cnfn convert_half3_rtz(double3);
half4 __ovld __cnfn convert_half4(double4);
half4 __ovld __cnfn convert_half4_rte(double4);
half4 __ovld __cnfn convert_half4_rtp(double4);
half4 __ovld __cnfn convert_half4_rtn(double4);
half4 __ovld __cnfn convert_half4_rtz(double4);
half8 __ovld __cnfn convert_half8(double8);
half8 __ovld __cnfn convert_half8_rte(double8);
half8 __ovld __cnfn convert_half8_rtp(double8);
half8 __ovld __cnfn convert_half8_rtn(double8);
half8 __ovld __cnfn convert_half8_rtz(double8);
half16 __ovld __cnfn convert_half16(double16);
half16 __ovld __cnfn convert_half16_rte(double16);
half16 __ovld __cnfn convert_half16_rtp(double16);
half16 __ovld __cnfn convert_half16_rtn(double16);
half16 __ovld __cnfn convert_half16_rtz(double16);
#endif //cl_khr_fp64

#endif // cl_khr_fp16

/**
 * OpenCL as_type operators
 * Reinterprets a data type as another data type of the same size
 */
#define as_char(x) __builtin_astype((x), char)
#define as_char2(x) __builtin_astype((x), char2)
#define as_char3(x) __builtin_astype((x), char3)
#define as_char4(x) __builtin_astype((x), char4)
#define as_char8(x) __builtin_astype((x), char8)
#define as_char16(x) __builtin_astype((x), char16)

#define as_uchar(x) __builtin_astype((x), uchar)
#define as_uchar2(x) __builtin_astype((x), uchar2)
#define as_uchar3(x) __builtin_astype((x), uchar3)
#define as_uchar4(x) __builtin_astype((x), uchar4)
#define as_uchar8(x) __builtin_astype((x), uchar8)
#define as_uchar16(x) __builtin_astype((x), uchar16)

#define as_short(x) __builtin_astype((x), short)
#define as_short2(x) __builtin_astype((x), short2)
#define as_short3(x) __builtin_astype((x), short3)
#define as_short4(x) __builtin_astype((x), short4)
#define as_short8(x) __builtin_astype((x), short8)
#define as_short16(x) __builtin_astype((x), short16)

#define as_ushort(x) __builtin_astype((x), ushort)
#define as_ushort2(x) __builtin_astype((x), ushort2)
#define as_ushort3(x) __builtin_astype((x), ushort3)
#define as_ushort4(x) __builtin_astype((x), ushort4)
#define as_ushort8(x) __builtin_astype((x), ushort8)
#define as_ushort16(x) __builtin_astype((x), ushort16)

#define as_int(x) __builtin_astype((x), int)
#define as_int2(x) __builtin_astype((x), int2)
#define as_int3(x) __builtin_astype((x), int3)
#define as_int4(x) __builtin_astype((x), int4)
#define as_int8(x) __builtin_astype((x), int8)
#define as_int16(x) __builtin_astype((x), int16)

#define as_uint(x) __builtin_astype((x), uint)
#define as_uint2(x) __builtin_astype((x), uint2)
#define as_uint3(x) __builtin_astype((x), uint3)
#define as_uint4(x) __builtin_astype((x), uint4)
#define as_uint8(x) __builtin_astype((x), uint8)
#define as_uint16(x) __builtin_astype((x), uint16)

#define as_long(x) __builtin_astype((x), long)
#define as_long2(x) __builtin_astype((x), long2)
#define as_long3(x) __builtin_astype((x), long3)
#define as_long4(x) __builtin_astype((x), long4)
#define as_long8(x) __builtin_astype((x), long8)
#define as_long16(x) __builtin_astype((x), long16)

#define as_ulong(x) __builtin_astype((x), ulong)
#define as_ulong2(x) __builtin_astype((x), ulong2)
#define as_ulong3(x) __builtin_astype((x), ulong3)
#define as_ulong4(x) __builtin_astype((x), ulong4)
#define as_ulong8(x) __builtin_astype((x), ulong8)
#define as_ulong16(x) __builtin_astype((x), ulong16)

#define as_float(x) __builtin_astype((x), float)
#define as_float2(x) __builtin_astype((x), float2)
#define as_float3(x) __builtin_astype((x), float3)
#define as_float4(x) __builtin_astype((x), float4)
#define as_float8(x) __builtin_astype((x), float8)
#define as_float16(x) __builtin_astype((x), float16)

#define as_double(x) __builtin_astype((x), double)
#define as_double2(x) __builtin_astype((x), double2)
#define as_double3(x) __builtin_astype((x), double3)
#define as_double4(x) __builtin_astype((x), double4)
#define as_double8(x) __builtin_astype((x), double8)
#define as_double16(x) __builtin_astype((x), double16)

#ifdef cl_khr_fp16
#define as_half(x) __builtin_astype((x), half)
#define as_half2(x) __builtin_astype((x), half2)
#define as_half3(x) __builtin_astype((x), half3)
#define as_half4(x) __builtin_astype((x), half4)
#define as_half8(x) __builtin_astype((x), half8)
#define as_half16(x) __builtin_astype((x), half16)
#endif //cl_khr_fp16

// OpenCL v1.1 s6.9, v1.2/2.0 s6.10 - Function qualifiers

#define __kernel_exec(X, typen) __kernel \
	__attribute__((work_group_size_hint(X, 1, 1))) \
	__attribute__((vec_type_hint(typen)))

#define kernel_exec(X, typen) __kernel \
	__attribute__((work_group_size_hint(X, 1, 1))) \
	__attribute__((vec_type_hint(typen)))

// OpenCL v1.1 s6.11.1, v1.2 s6.12.1, v2.0 s6.13.1 - Work-item Functions

/**
 * Returns the number of dimensions in use. This is the
 * value given to the work_dim argument specified in
 * clEnqueueNDRangeKernel.
 * For clEnqueueTask, this returns 1.
 */
uint __ovld __cnfn get_work_dim(void);

// OpenCL v1.1 s6.11.2, v1.2 s6.12.2, v2.0 s6.13.2 - Math functions

/**
 * Arc cosine function.
 */
float __ovld __cnfn acos(float);
float2 __ovld __cnfn acos(float2);
float3 __ovld __cnfn acos(float3);
float4 __ovld __cnfn acos(float4);
float8 __ovld __cnfn acos(float8);
float16 __ovld __cnfn acos(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn acos(double);
double2 __ovld __cnfn acos(double2);
double3 __ovld __cnfn acos(double3);
double4 __ovld __cnfn acos(double4);
double8 __ovld __cnfn acos(double8);
double16 __ovld __cnfn acos(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn acos(half);
half2 __ovld __cnfn acos(half2);
half3 __ovld __cnfn acos(half3);
half4 __ovld __cnfn acos(half4);
half8 __ovld __cnfn acos(half8);
half16 __ovld __cnfn acos(half16);
#endif //cl_khr_fp16

/**
 * Inverse hyperbolic cosine.
 */
float __ovld __cnfn acosh(float);
float2 __ovld __cnfn acosh(float2);
float3 __ovld __cnfn acosh(float3);
float4 __ovld __cnfn acosh(float4);
float8 __ovld __cnfn acosh(float8);
float16 __ovld __cnfn acosh(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn acosh(double);
double2 __ovld __cnfn acosh(double2);
double3 __ovld __cnfn acosh(double3);
double4 __ovld __cnfn acosh(double4);
double8 __ovld __cnfn acosh(double8);
double16 __ovld __cnfn acosh(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn acosh(half);
half2 __ovld __cnfn acosh(half2);
half3 __ovld __cnfn acosh(half3);
half4 __ovld __cnfn acosh(half4);
half8 __ovld __cnfn acosh(half8);
half16 __ovld __cnfn acosh(half16);
#endif //cl_khr_fp16

/**
 * Compute acos (x) / PI.
 */
float __ovld __cnfn acospi(float x);
float2 __ovld __cnfn acospi(float2 x);
float3 __ovld __cnfn acospi(float3 x);
float4 __ovld __cnfn acospi(float4 x);
float8 __ovld __cnfn acospi(float8 x);
float16 __ovld __cnfn acospi(float16 x);
#ifdef cl_khr_fp64
double __ovld __cnfn acospi(double x);
double2 __ovld __cnfn acospi(double2 x);
double3 __ovld __cnfn acospi(double3 x);
double4 __ovld __cnfn acospi(double4 x);
double8 __ovld __cnfn acospi(double8 x);
double16 __ovld __cnfn acospi(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn acospi(half x);
half2 __ovld __cnfn acospi(half2 x);
half3 __ovld __cnfn acospi(half3 x);
half4 __ovld __cnfn acospi(half4 x);
half8 __ovld __cnfn acospi(half8 x);
half16 __ovld __cnfn acospi(half16 x);
#endif //cl_khr_fp16

/**
 * Arc sine function.
 */
float __ovld __cnfn asin(float);
float2 __ovld __cnfn asin(float2);
float3 __ovld __cnfn asin(float3);
float4 __ovld __cnfn asin(float4);
float8 __ovld __cnfn asin(float8);
float16 __ovld __cnfn asin(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn asin(double);
double2 __ovld __cnfn asin(double2);
double3 __ovld __cnfn asin(double3);
double4 __ovld __cnfn asin(double4);
double8 __ovld __cnfn asin(double8);
double16 __ovld __cnfn asin(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn asin(half);
half2 __ovld __cnfn asin(half2);
half3 __ovld __cnfn asin(half3);
half4 __ovld __cnfn asin(half4);
half8 __ovld __cnfn asin(half8);
half16 __ovld __cnfn asin(half16);
#endif //cl_khr_fp16

/**
 * Inverse hyperbolic sine.
 */
float __ovld __cnfn asinh(float);
float2 __ovld __cnfn asinh(float2);
float3 __ovld __cnfn asinh(float3);
float4 __ovld __cnfn asinh(float4);
float8 __ovld __cnfn asinh(float8);
float16 __ovld __cnfn asinh(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn asinh(double);
double2 __ovld __cnfn asinh(double2);
double3 __ovld __cnfn asinh(double3);
double4 __ovld __cnfn asinh(double4);
double8 __ovld __cnfn asinh(double8);
double16 __ovld __cnfn asinh(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn asinh(half);
half2 __ovld __cnfn asinh(half2);
half3 __ovld __cnfn asinh(half3);
half4 __ovld __cnfn asinh(half4);
half8 __ovld __cnfn asinh(half8);
half16 __ovld __cnfn asinh(half16);
#endif //cl_khr_fp16

/**
 * Compute asin (x) / PI.
 */
float __ovld __cnfn asinpi(float x);
float2 __ovld __cnfn asinpi(float2 x);
float3 __ovld __cnfn asinpi(float3 x);
float4 __ovld __cnfn asinpi(float4 x);
float8 __ovld __cnfn asinpi(float8 x);
float16 __ovld __cnfn asinpi(float16 x);
#ifdef cl_khr_fp64
double __ovld __cnfn asinpi(double x);
double2 __ovld __cnfn asinpi(double2 x);
double3 __ovld __cnfn asinpi(double3 x);
double4 __ovld __cnfn asinpi(double4 x);
double8 __ovld __cnfn asinpi(double8 x);
double16 __ovld __cnfn asinpi(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn asinpi(half x);
half2 __ovld __cnfn asinpi(half2 x);
half3 __ovld __cnfn asinpi(half3 x);
half4 __ovld __cnfn asinpi(half4 x);
half8 __ovld __cnfn asinpi(half8 x);
half16 __ovld __cnfn asinpi(half16 x);
#endif //cl_khr_fp16

/**
 * Arc tangent function.
 */
float __ovld __cnfn atan(float y_over_x);
float2 __ovld __cnfn atan(float2 y_over_x);
float3 __ovld __cnfn atan(float3 y_over_x);
float4 __ovld __cnfn atan(float4 y_over_x);
float8 __ovld __cnfn atan(float8 y_over_x);
float16 __ovld __cnfn atan(float16 y_over_x);
#ifdef cl_khr_fp64
double __ovld __cnfn atan(double y_over_x);
double2 __ovld __cnfn atan(double2 y_over_x);
double3 __ovld __cnfn atan(double3 y_over_x);
double4 __ovld __cnfn atan(double4 y_over_x);
double8 __ovld __cnfn atan(double8 y_over_x);
double16 __ovld __cnfn atan(double16 y_over_x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn atan(half y_over_x);
half2 __ovld __cnfn atan(half2 y_over_x);
half3 __ovld __cnfn atan(half3 y_over_x);
half4 __ovld __cnfn atan(half4 y_over_x);
half8 __ovld __cnfn atan(half8 y_over_x);
half16 __ovld __cnfn atan(half16 y_over_x);
#endif //cl_khr_fp16

/**
 * Arc tangent of y / x.
 */
float __ovld __cnfn atan2(float y, float x);
float2 __ovld __cnfn atan2(float2 y, float2 x);
float3 __ovld __cnfn atan2(float3 y, float3 x);
float4 __ovld __cnfn atan2(float4 y, float4 x);
float8 __ovld __cnfn atan2(float8 y, float8 x);
float16 __ovld __cnfn atan2(float16 y, float16 x);
#ifdef cl_khr_fp64
double __ovld __cnfn atan2(double y, double x);
double2 __ovld __cnfn atan2(double2 y, double2 x);
double3 __ovld __cnfn atan2(double3 y, double3 x);
double4 __ovld __cnfn atan2(double4 y, double4 x);
double8 __ovld __cnfn atan2(double8 y, double8 x);
double16 __ovld __cnfn atan2(double16 y, double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn atan2(half y, half x);
half2 __ovld __cnfn atan2(half2 y, half2 x);
half3 __ovld __cnfn atan2(half3 y, half3 x);
half4 __ovld __cnfn atan2(half4 y, half4 x);
half8 __ovld __cnfn atan2(half8 y, half8 x);
half16 __ovld __cnfn atan2(half16 y, half16 x);
#endif //cl_khr_fp16

/**
 * Hyperbolic arc tangent.
 */
float __ovld __cnfn atanh(float);
float2 __ovld __cnfn atanh(float2);
float3 __ovld __cnfn atanh(float3);
float4 __ovld __cnfn atanh(float4);
float8 __ovld __cnfn atanh(float8);
float16 __ovld __cnfn atanh(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn atanh(double);
double2 __ovld __cnfn atanh(double2);
double3 __ovld __cnfn atanh(double3);
double4 __ovld __cnfn atanh(double4);
double8 __ovld __cnfn atanh(double8);
double16 __ovld __cnfn atanh(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn atanh(half);
half2 __ovld __cnfn atanh(half2);
half3 __ovld __cnfn atanh(half3);
half4 __ovld __cnfn atanh(half4);
half8 __ovld __cnfn atanh(half8);
half16 __ovld __cnfn atanh(half16);
#endif //cl_khr_fp16

/**
 * Compute atan (x) / PI.
 */
float __ovld __cnfn atanpi(float x);
float2 __ovld __cnfn atanpi(float2 x);
float3 __ovld __cnfn atanpi(float3 x);
float4 __ovld __cnfn atanpi(float4 x);
float8 __ovld __cnfn atanpi(float8 x);
float16 __ovld __cnfn atanpi(float16 x);
#ifdef cl_khr_fp64
double __ovld __cnfn atanpi(double x);
double2 __ovld __cnfn atanpi(double2 x);
double3 __ovld __cnfn atanpi(double3 x);
double4 __ovld __cnfn atanpi(double4 x);
double8 __ovld __cnfn atanpi(double8 x);
double16 __ovld __cnfn atanpi(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn atanpi(half x);
half2 __ovld __cnfn atanpi(half2 x);
half3 __ovld __cnfn atanpi(half3 x);
half4 __ovld __cnfn atanpi(half4 x);
half8 __ovld __cnfn atanpi(half8 x);
half16 __ovld __cnfn atanpi(half16 x);
#endif //cl_khr_fp16

/**
 * Compute atan2 (y, x) / PI.
 */
float __ovld __cnfn atan2pi(float y, float x);
float2 __ovld __cnfn atan2pi(float2 y, float2 x);
float3 __ovld __cnfn atan2pi(float3 y, float3 x);
float4 __ovld __cnfn atan2pi(float4 y, float4 x);
float8 __ovld __cnfn atan2pi(float8 y, float8 x);
float16 __ovld __cnfn atan2pi(float16 y, float16 x);
#ifdef cl_khr_fp64
double __ovld __cnfn atan2pi(double y, double x);
double2 __ovld __cnfn atan2pi(double2 y, double2 x);
double3 __ovld __cnfn atan2pi(double3 y, double3 x);
double4 __ovld __cnfn atan2pi(double4 y, double4 x);
double8 __ovld __cnfn atan2pi(double8 y, double8 x);
double16 __ovld __cnfn atan2pi(double16 y, double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn atan2pi(half y, half x);
half2 __ovld __cnfn atan2pi(half2 y, half2 x);
half3 __ovld __cnfn atan2pi(half3 y, half3 x);
half4 __ovld __cnfn atan2pi(half4 y, half4 x);
half8 __ovld __cnfn atan2pi(half8 y, half8 x);
half16 __ovld __cnfn atan2pi(half16 y, half16 x);
#endif //cl_khr_fp16

/**
 * Compute cube-root.
 */
float __ovld __cnfn cbrt(float);
float2 __ovld __cnfn cbrt(float2);
float3 __ovld __cnfn cbrt(float3);
float4 __ovld __cnfn cbrt(float4);
float8 __ovld __cnfn cbrt(float8);
float16 __ovld __cnfn cbrt(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn cbrt(double);
double2 __ovld __cnfn cbrt(double2);
double3 __ovld __cnfn cbrt(double3);
double4 __ovld __cnfn cbrt(double4);
double8 __ovld __cnfn cbrt(double8);
double16 __ovld __cnfn cbrt(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn cbrt(half);
half2 __ovld __cnfn cbrt(half2);
half3 __ovld __cnfn cbrt(half3);
half4 __ovld __cnfn cbrt(half4);
half8 __ovld __cnfn cbrt(half8);
half16 __ovld __cnfn cbrt(half16);
#endif //cl_khr_fp16

/**
 * Round to integral value using the round to positive
 * infinity rounding mode.
 */
float __ovld __cnfn ceil(float);
float2 __ovld __cnfn ceil(float2);
float3 __ovld __cnfn ceil(float3);
float4 __ovld __cnfn ceil(float4);
float8 __ovld __cnfn ceil(float8);
float16 __ovld __cnfn ceil(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn ceil(double);
double2 __ovld __cnfn ceil(double2);
double3 __ovld __cnfn ceil(double3);
double4 __ovld __cnfn ceil(double4);
double8 __ovld __cnfn ceil(double8);
double16 __ovld __cnfn ceil(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn ceil(half);
half2 __ovld __cnfn ceil(half2);
half3 __ovld __cnfn ceil(half3);
half4 __ovld __cnfn ceil(half4);
half8 __ovld __cnfn ceil(half8);
half16 __ovld __cnfn ceil(half16);
#endif //cl_khr_fp16

/**
 * Returns x with its sign changed to match the sign of y.
 */
float __ovld __cnfn copysign(float x, float y);
float2 __ovld __cnfn copysign(float2 x, float2 y);
float3 __ovld __cnfn copysign(float3 x, float3 y);
float4 __ovld __cnfn copysign(float4 x, float4 y);
float8 __ovld __cnfn copysign(float8 x, float8 y);
float16 __ovld __cnfn copysign(float16 x, float16 y);
#ifdef cl_khr_fp64
double __ovld __cnfn copysign(double x, double y);
double2 __ovld __cnfn copysign(double2 x, double2 y);
double3 __ovld __cnfn copysign(double3 x, double3 y);
double4 __ovld __cnfn copysign(double4 x, double4 y);
double8 __ovld __cnfn copysign(double8 x, double8 y);
double16 __ovld __cnfn copysign(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn copysign(half x, half y);
half2 __ovld __cnfn copysign(half2 x, half2 y);
half3 __ovld __cnfn copysign(half3 x, half3 y);
half4 __ovld __cnfn copysign(half4 x, half4 y);
half8 __ovld __cnfn copysign(half8 x, half8 y);
half16 __ovld __cnfn copysign(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Compute cosine.
 */
float __ovld __cnfn cos(float);
float2 __ovld __cnfn cos(float2);
float3 __ovld __cnfn cos(float3);
float4 __ovld __cnfn cos(float4);
float8 __ovld __cnfn cos(float8);
float16 __ovld __cnfn cos(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn cos(double);
double2 __ovld __cnfn cos(double2);
double3 __ovld __cnfn cos(double3);
double4 __ovld __cnfn cos(double4);
double8 __ovld __cnfn cos(double8);
double16 __ovld __cnfn cos(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn cos(half);
half2 __ovld __cnfn cos(half2);
half3 __ovld __cnfn cos(half3);
half4 __ovld __cnfn cos(half4);
half8 __ovld __cnfn cos(half8);
half16 __ovld __cnfn cos(half16);
#endif //cl_khr_fp16

/**
 * Compute hyperbolic cosine.
 */
float __ovld __cnfn cosh(float);
float2 __ovld __cnfn cosh(float2);
float3 __ovld __cnfn cosh(float3);
float4 __ovld __cnfn cosh(float4);
float8 __ovld __cnfn cosh(float8);
float16 __ovld __cnfn cosh(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn cosh(double);
double2 __ovld __cnfn cosh(double2);
double3 __ovld __cnfn cosh(double3);
double4 __ovld __cnfn cosh(double4);
double8 __ovld __cnfn cosh(double8);
double16 __ovld __cnfn cosh(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn cosh(half);
half2 __ovld __cnfn cosh(half2);
half3 __ovld __cnfn cosh(half3);
half4 __ovld __cnfn cosh(half4);
half8 __ovld __cnfn cosh(half8);
half16 __ovld __cnfn cosh(half16);
#endif //cl_khr_fp16

/**
 * Compute cos (PI * x).
 */
float __ovld __cnfn cospi(float x);
float2 __ovld __cnfn cospi(float2 x);
float3 __ovld __cnfn cospi(float3 x);
float4 __ovld __cnfn cospi(float4 x);
float8 __ovld __cnfn cospi(float8 x);
float16 __ovld __cnfn cospi(float16 x);
#ifdef cl_khr_fp64
double __ovld __cnfn cospi(double x);
double2 __ovld __cnfn cospi(double2 x);
double3 __ovld __cnfn cospi(double3 x);
double4 __ovld __cnfn cospi(double4 x);
double8 __ovld __cnfn cospi(double8 x);
double16 __ovld __cnfn cospi(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn cospi(half x);
half2 __ovld __cnfn cospi(half2 x);
half3 __ovld __cnfn cospi(half3 x);
half4 __ovld __cnfn cospi(half4 x);
half8 __ovld __cnfn cospi(half8 x);
half16 __ovld __cnfn cospi(half16 x);
#endif //cl_khr_fp16

/**
 * Complementary error function.
 */
float __ovld __cnfn erfc(float);
float2 __ovld __cnfn erfc(float2);
float3 __ovld __cnfn erfc(float3);
float4 __ovld __cnfn erfc(float4);
float8 __ovld __cnfn erfc(float8);
float16 __ovld __cnfn erfc(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn erfc(double);
double2 __ovld __cnfn erfc(double2);
double3 __ovld __cnfn erfc(double3);
double4 __ovld __cnfn erfc(double4);
double8 __ovld __cnfn erfc(double8);
double16 __ovld __cnfn erfc(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn erfc(half);
half2 __ovld __cnfn erfc(half2);
half3 __ovld __cnfn erfc(half3);
half4 __ovld __cnfn erfc(half4);
half8 __ovld __cnfn erfc(half8);
half16 __ovld __cnfn erfc(half16);
#endif //cl_khr_fp16

/**
 * Error function encountered in integrating the
 * normal distribution.
 */
float __ovld __cnfn erf(float);
float2 __ovld __cnfn erf(float2);
float3 __ovld __cnfn erf(float3);
float4 __ovld __cnfn erf(float4);
float8 __ovld __cnfn erf(float8);
float16 __ovld __cnfn erf(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn erf(double);
double2 __ovld __cnfn erf(double2);
double3 __ovld __cnfn erf(double3);
double4 __ovld __cnfn erf(double4);
double8 __ovld __cnfn erf(double8);
double16 __ovld __cnfn erf(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn erf(half);
half2 __ovld __cnfn erf(half2);
half3 __ovld __cnfn erf(half3);
half4 __ovld __cnfn erf(half4);
half8 __ovld __cnfn erf(half8);
half16 __ovld __cnfn erf(half16);
#endif //cl_khr_fp16

/**
 * Compute the base e exponential function of x.
 */
float __ovld __cnfn exp(float x);
float2 __ovld __cnfn exp(float2 x);
float3 __ovld __cnfn exp(float3 x);
float4 __ovld __cnfn exp(float4 x);
float8 __ovld __cnfn exp(float8 x);
float16 __ovld __cnfn exp(float16 x);
#ifdef cl_khr_fp64
double __ovld __cnfn exp(double x);
double2 __ovld __cnfn exp(double2 x);
double3 __ovld __cnfn exp(double3 x);
double4 __ovld __cnfn exp(double4 x);
double8 __ovld __cnfn exp(double8 x);
double16 __ovld __cnfn exp(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn exp(half x);
half2 __ovld __cnfn exp(half2 x);
half3 __ovld __cnfn exp(half3 x);
half4 __ovld __cnfn exp(half4 x);
half8 __ovld __cnfn exp(half8 x);
half16 __ovld __cnfn exp(half16 x);
#endif //cl_khr_fp16

/**
 * Exponential base 2 function.
 */
float __ovld __cnfn exp2(float);
float2 __ovld __cnfn exp2(float2);
float3 __ovld __cnfn exp2(float3);
float4 __ovld __cnfn exp2(float4);
float8 __ovld __cnfn exp2(float8);
float16 __ovld __cnfn exp2(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn exp2(double);
double2 __ovld __cnfn exp2(double2);
double3 __ovld __cnfn exp2(double3);
double4 __ovld __cnfn exp2(double4);
double8 __ovld __cnfn exp2(double8);
double16 __ovld __cnfn exp2(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn exp2(half);
half2 __ovld __cnfn exp2(half2);
half3 __ovld __cnfn exp2(half3);
half4 __ovld __cnfn exp2(half4);
half8 __ovld __cnfn exp2(half8);
half16 __ovld __cnfn exp2(half16);
#endif //cl_khr_fp16

/**
 * Exponential base 10 function.
 */
float __ovld __cnfn exp10(float);
float2 __ovld __cnfn exp10(float2);
float3 __ovld __cnfn exp10(float3);
float4 __ovld __cnfn exp10(float4);
float8 __ovld __cnfn exp10(float8);
float16 __ovld __cnfn exp10(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn exp10(double);
double2 __ovld __cnfn exp10(double2);
double3 __ovld __cnfn exp10(double3);
double4 __ovld __cnfn exp10(double4);
double8 __ovld __cnfn exp10(double8);
double16 __ovld __cnfn exp10(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn exp10(half);
half2 __ovld __cnfn exp10(half2);
half3 __ovld __cnfn exp10(half3);
half4 __ovld __cnfn exp10(half4);
half8 __ovld __cnfn exp10(half8);
half16 __ovld __cnfn exp10(half16);
#endif //cl_khr_fp16

/**
 * Compute e^x- 1.0.
 */
float __ovld __cnfn expm1(float x);
float2 __ovld __cnfn expm1(float2 x);
float3 __ovld __cnfn expm1(float3 x);
float4 __ovld __cnfn expm1(float4 x);
float8 __ovld __cnfn expm1(float8 x);
float16 __ovld __cnfn expm1(float16 x);
#ifdef cl_khr_fp64
double __ovld __cnfn expm1(double x);
double2 __ovld __cnfn expm1(double2 x);
double3 __ovld __cnfn expm1(double3 x);
double4 __ovld __cnfn expm1(double4 x);
double8 __ovld __cnfn expm1(double8 x);
double16 __ovld __cnfn expm1(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn expm1(half x);
half2 __ovld __cnfn expm1(half2 x);
half3 __ovld __cnfn expm1(half3 x);
half4 __ovld __cnfn expm1(half4 x);
half8 __ovld __cnfn expm1(half8 x);
half16 __ovld __cnfn expm1(half16 x);
#endif //cl_khr_fp16

/**
 * Compute absolute value of a floating-point number.
 */
float __ovld __cnfn fabs(float);
float2 __ovld __cnfn fabs(float2);
float3 __ovld __cnfn fabs(float3);
float4 __ovld __cnfn fabs(float4);
float8 __ovld __cnfn fabs(float8);
float16 __ovld __cnfn fabs(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn fabs(double);
double2 __ovld __cnfn fabs(double2);
double3 __ovld __cnfn fabs(double3);
double4 __ovld __cnfn fabs(double4);
double8 __ovld __cnfn fabs(double8);
double16 __ovld __cnfn fabs(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn fabs(half);
half2 __ovld __cnfn fabs(half2);
half3 __ovld __cnfn fabs(half3);
half4 __ovld __cnfn fabs(half4);
half8 __ovld __cnfn fabs(half8);
half16 __ovld __cnfn fabs(half16);
#endif //cl_khr_fp16

/**
 * x - y if x > y, +0 if x is less than or equal to y.
 */
float __ovld __cnfn fdim(float x, float y);
float2 __ovld __cnfn fdim(float2 x, float2 y);
float3 __ovld __cnfn fdim(float3 x, float3 y);
float4 __ovld __cnfn fdim(float4 x, float4 y);
float8 __ovld __cnfn fdim(float8 x, float8 y);
float16 __ovld __cnfn fdim(float16 x, float16 y);
#ifdef cl_khr_fp64
double __ovld __cnfn fdim(double x, double y);
double2 __ovld __cnfn fdim(double2 x, double2 y);
double3 __ovld __cnfn fdim(double3 x, double3 y);
double4 __ovld __cnfn fdim(double4 x, double4 y);
double8 __ovld __cnfn fdim(double8 x, double8 y);
double16 __ovld __cnfn fdim(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn fdim(half x, half y);
half2 __ovld __cnfn fdim(half2 x, half2 y);
half3 __ovld __cnfn fdim(half3 x, half3 y);
half4 __ovld __cnfn fdim(half4 x, half4 y);
half8 __ovld __cnfn fdim(half8 x, half8 y);
half16 __ovld __cnfn fdim(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Round to integral value using the round to -ve
 * infinity rounding mode.
 */
float __ovld __cnfn floor(float);
float2 __ovld __cnfn floor(float2);
float3 __ovld __cnfn floor(float3);
float4 __ovld __cnfn floor(float4);
float8 __ovld __cnfn floor(float8);
float16 __ovld __cnfn floor(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn floor(double);
double2 __ovld __cnfn floor(double2);
double3 __ovld __cnfn floor(double3);
double4 __ovld __cnfn floor(double4);
double8 __ovld __cnfn floor(double8);
double16 __ovld __cnfn floor(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn floor(half);
half2 __ovld __cnfn floor(half2);
half3 __ovld __cnfn floor(half3);
half4 __ovld __cnfn floor(half4);
half8 __ovld __cnfn floor(half8);
half16 __ovld __cnfn floor(half16);
#endif //cl_khr_fp16

/**
 * Returns the correctly rounded floating-point
 * representation of the sum of c with the infinitely
 * precise product of a and b. Rounding of
 * intermediate products shall not occur. Edge case
 * behavior is per the IEEE 754-2008 standard.
 */
float __ovld __cnfn fma(float a, float b, float c);
float2 __ovld __cnfn fma(float2 a, float2 b, float2 c);
float3 __ovld __cnfn fma(float3 a, float3 b, float3 c);
float4 __ovld __cnfn fma(float4 a, float4 b, float4 c);
float8 __ovld __cnfn fma(float8 a, float8 b, float8 c);
float16 __ovld __cnfn fma(float16 a, float16 b, float16 c);
#ifdef cl_khr_fp64
double __ovld __cnfn fma(double a, double b, double c);
double2 __ovld __cnfn fma(double2 a, double2 b, double2 c);
double3 __ovld __cnfn fma(double3 a, double3 b, double3 c);
double4 __ovld __cnfn fma(double4 a, double4 b, double4 c);
double8 __ovld __cnfn fma(double8 a, double8 b, double8 c);
double16 __ovld __cnfn fma(double16 a, double16 b, double16 c);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn fma(half a, half b, half c);
half2 __ovld __cnfn fma(half2 a, half2 b, half2 c);
half3 __ovld __cnfn fma(half3 a, half3 b, half3 c);
half4 __ovld __cnfn fma(half4 a, half4 b, half4 c);
half8 __ovld __cnfn fma(half8 a, half8 b, half8 c);
half16 __ovld __cnfn fma(half16 a, half16 b, half16 c);
#endif //cl_khr_fp16

/**
 * Returns y if x < y, otherwise it returns x. If one
 * argument is a NaN, fmax() returns the other
 * argument. If both arguments are NaNs, fmax()
 * returns a NaN.
 */
float __ovld __cnfn fmax(float x, float y);
float2 __ovld __cnfn fmax(float2 x, float2 y);
float3 __ovld __cnfn fmax(float3 x, float3 y);
float4 __ovld __cnfn fmax(float4 x, float4 y);
float8 __ovld __cnfn fmax(float8 x, float8 y);
float16 __ovld __cnfn fmax(float16 x, float16 y);
float2 __ovld __cnfn fmax(float2 x, float y);
float3 __ovld __cnfn fmax(float3 x, float y);
float4 __ovld __cnfn fmax(float4 x, float y);
float8 __ovld __cnfn fmax(float8 x, float y);
float16 __ovld __cnfn fmax(float16 x, float y);
#ifdef cl_khr_fp64
double __ovld __cnfn fmax(double x, double y);
double2 __ovld __cnfn fmax(double2 x, double2 y);
double3 __ovld __cnfn fmax(double3 x, double3 y);
double4 __ovld __cnfn fmax(double4 x, double4 y);
double8 __ovld __cnfn fmax(double8 x, double8 y);
double16 __ovld __cnfn fmax(double16 x, double16 y);
double2 __ovld __cnfn fmax(double2 x, double y);
double3 __ovld __cnfn fmax(double3 x, double y);
double4 __ovld __cnfn fmax(double4 x, double y);
double8 __ovld __cnfn fmax(double8 x, double y);
double16 __ovld __cnfn fmax(double16 x, double y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn fmax(half x, half y);
half2 __ovld __cnfn fmax(half2 x, half2 y);
half3 __ovld __cnfn fmax(half3 x, half3 y);
half4 __ovld __cnfn fmax(half4 x, half4 y);
half8 __ovld __cnfn fmax(half8 x, half8 y);
half16 __ovld __cnfn fmax(half16 x, half16 y);
half2 __ovld __cnfn fmax(half2 x, half y);
half3 __ovld __cnfn fmax(half3 x, half y);
half4 __ovld __cnfn fmax(half4 x, half y);
half8 __ovld __cnfn fmax(half8 x, half y);
half16 __ovld __cnfn fmax(half16 x, half y);
#endif //cl_khr_fp16

/**
 * Returns y if y < x, otherwise it returns x. If one
 * argument is a NaN, fmin() returns the other
 * argument. If both arguments are NaNs, fmin()
 * returns a NaN.
 */
float __ovld __cnfn fmin(float x, float y);
float2 __ovld __cnfn fmin(float2 x, float2 y);
float3 __ovld __cnfn fmin(float3 x, float3 y);
float4 __ovld __cnfn fmin(float4 x, float4 y);
float8 __ovld __cnfn fmin(float8 x, float8 y);
float16 __ovld __cnfn fmin(float16 x, float16 y);
float2 __ovld __cnfn fmin(float2 x, float y);
float3 __ovld __cnfn fmin(float3 x, float y);
float4 __ovld __cnfn fmin(float4 x, float y);
float8 __ovld __cnfn fmin(float8 x, float y);
float16 __ovld __cnfn fmin(float16 x, float y);
#ifdef cl_khr_fp64
double __ovld __cnfn fmin(double x, double y);
double2 __ovld __cnfn fmin(double2 x, double2 y);
double3 __ovld __cnfn fmin(double3 x, double3 y);
double4 __ovld __cnfn fmin(double4 x, double4 y);
double8 __ovld __cnfn fmin(double8 x, double8 y);
double16 __ovld __cnfn fmin(double16 x, double16 y);
double2 __ovld __cnfn fmin(double2 x, double y);
double3 __ovld __cnfn fmin(double3 x, double y);
double4 __ovld __cnfn fmin(double4 x, double y);
double8 __ovld __cnfn fmin(double8 x, double y);
double16 __ovld __cnfn fmin(double16 x, double y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn fmin(half x, half y);
half2 __ovld __cnfn fmin(half2 x, half2 y);
half3 __ovld __cnfn fmin(half3 x, half3 y);
half4 __ovld __cnfn fmin(half4 x, half4 y);
half8 __ovld __cnfn fmin(half8 x, half8 y);
half16 __ovld __cnfn fmin(half16 x, half16 y);
half2 __ovld __cnfn fmin(half2 x, half y);
half3 __ovld __cnfn fmin(half3 x, half y);
half4 __ovld __cnfn fmin(half4 x, half y);
half8 __ovld __cnfn fmin(half8 x, half y);
half16 __ovld __cnfn fmin(half16 x, half y);
#endif //cl_khr_fp16

/**
 * Modulus. Returns x - y * trunc (x/y).
 */
float __ovld __cnfn fmod(float x, float y);
float2 __ovld __cnfn fmod(float2 x, float2 y);
float3 __ovld __cnfn fmod(float3 x, float3 y);
float4 __ovld __cnfn fmod(float4 x, float4 y);
float8 __ovld __cnfn fmod(float8 x, float8 y);
float16 __ovld __cnfn fmod(float16 x, float16 y);
#ifdef cl_khr_fp64
double __ovld __cnfn fmod(double x, double y);
double2 __ovld __cnfn fmod(double2 x, double2 y);
double3 __ovld __cnfn fmod(double3 x, double3 y);
double4 __ovld __cnfn fmod(double4 x, double4 y);
double8 __ovld __cnfn fmod(double8 x, double8 y);
double16 __ovld __cnfn fmod(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn fmod(half x, half y);
half2 __ovld __cnfn fmod(half2 x, half2 y);
half3 __ovld __cnfn fmod(half3 x, half3 y);
half4 __ovld __cnfn fmod(half4 x, half4 y);
half8 __ovld __cnfn fmod(half8 x, half8 y);
half16 __ovld __cnfn fmod(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Compute the value of the square root of x^2 + y^2
 * without undue overflow or underflow.
 */
float __ovld __cnfn hypot(float x, float y);
float2 __ovld __cnfn hypot(float2 x, float2 y);
float3 __ovld __cnfn hypot(float3 x, float3 y);
float4 __ovld __cnfn hypot(float4 x, float4 y);
float8 __ovld __cnfn hypot(float8 x, float8 y);
float16 __ovld __cnfn hypot(float16 x, float16 y);
#ifdef cl_khr_fp64
double __ovld __cnfn hypot(double x, double y);
double2 __ovld __cnfn hypot(double2 x, double2 y);
double3 __ovld __cnfn hypot(double3 x, double3 y);
double4 __ovld __cnfn hypot(double4 x, double4 y);
double8 __ovld __cnfn hypot(double8 x, double8 y);
double16 __ovld __cnfn hypot(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn hypot(half x, half y);
half2 __ovld __cnfn hypot(half2 x, half2 y);
half3 __ovld __cnfn hypot(half3 x, half3 y);
half4 __ovld __cnfn hypot(half4 x, half4 y);
half8 __ovld __cnfn hypot(half8 x, half8 y);
half16 __ovld __cnfn hypot(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Return the exponent as an integer value.
 */
int __ovld __cnfn ilogb(float x);
int2 __ovld __cnfn ilogb(float2 x);
int3 __ovld __cnfn ilogb(float3 x);
int4 __ovld __cnfn ilogb(float4 x);
int8 __ovld __cnfn ilogb(float8 x);
int16 __ovld __cnfn ilogb(float16 x);
#ifdef cl_khr_fp64
int __ovld __cnfn ilogb(double x);
int2 __ovld __cnfn ilogb(double2 x);
int3 __ovld __cnfn ilogb(double3 x);
int4 __ovld __cnfn ilogb(double4 x);
int8 __ovld __cnfn ilogb(double8 x);
int16 __ovld __cnfn ilogb(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __ovld __cnfn ilogb(half x);
int2 __ovld __cnfn ilogb(half2 x);
int3 __ovld __cnfn ilogb(half3 x);
int4 __ovld __cnfn ilogb(half4 x);
int8 __ovld __cnfn ilogb(half8 x);
int16 __ovld __cnfn ilogb(half16 x);
#endif //cl_khr_fp16

/**
 * Multiply x by 2 to the power n.
 */
float __ovld __cnfn ldexp(float x, int n);
float2 __ovld __cnfn ldexp(float2 x, int2 n);
float3 __ovld __cnfn ldexp(float3 x, int3 n);
float4 __ovld __cnfn ldexp(float4 x, int4 n);
float8 __ovld __cnfn ldexp(float8 x, int8 n);
float16 __ovld __cnfn ldexp(float16 x, int16 n);
float2 __ovld __cnfn ldexp(float2 x, int n);
float3 __ovld __cnfn ldexp(float3 x, int n);
float4 __ovld __cnfn ldexp(float4 x, int n);
float8 __ovld __cnfn ldexp(float8 x, int n);
float16 __ovld __cnfn ldexp(float16 x, int n);
#ifdef cl_khr_fp64
double __ovld __cnfn ldexp(double x, int n);
double2 __ovld __cnfn ldexp(double2 x, int2 n);
double3 __ovld __cnfn ldexp(double3 x, int3 n);
double4 __ovld __cnfn ldexp(double4 x, int4 n);
double8 __ovld __cnfn ldexp(double8 x, int8 n);
double16 __ovld __cnfn ldexp(double16 x, int16 n);
double2 __ovld __cnfn ldexp(double2 x, int n);
double3 __ovld __cnfn ldexp(double3 x, int n);
double4 __ovld __cnfn ldexp(double4 x, int n);
double8 __ovld __cnfn ldexp(double8 x, int n);
double16 __ovld __cnfn ldexp(double16 x, int n);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn ldexp(half x, int n);
half2 __ovld __cnfn ldexp(half2 x, int2 n);
half3 __ovld __cnfn ldexp(half3 x, int3 n);
half4 __ovld __cnfn ldexp(half4 x, int4 n);
half8 __ovld __cnfn ldexp(half8 x, int8 n);
half16 __ovld __cnfn ldexp(half16 x, int16 n);
half2 __ovld __cnfn ldexp(half2 x, int n);
half3 __ovld __cnfn ldexp(half3 x, int n);
half4 __ovld __cnfn ldexp(half4 x, int n);
half8 __ovld __cnfn ldexp(half8 x, int n);
half16 __ovld __cnfn ldexp(half16 x, int n);
#endif //cl_khr_fp16

/**
 * Log gamma function. Returns the natural
 * logarithm of the absolute value of the gamma
 * function. The sign of the gamma function is
 * returned in the signp argument of lgamma_r.
 */
float __ovld __cnfn lgamma(float x);
float2 __ovld __cnfn lgamma(float2 x);
float3 __ovld __cnfn lgamma(float3 x);
float4 __ovld __cnfn lgamma(float4 x);
float8 __ovld __cnfn lgamma(float8 x);
float16 __ovld __cnfn lgamma(float16 x);
#ifdef cl_khr_fp64
double __ovld __cnfn lgamma(double x);
double2 __ovld __cnfn lgamma(double2 x);
double3 __ovld __cnfn lgamma(double3 x);
double4 __ovld __cnfn lgamma(double4 x);
double8 __ovld __cnfn lgamma(double8 x);
double16 __ovld __cnfn lgamma(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn lgamma(half x);
half2 __ovld __cnfn lgamma(half2 x);
half3 __ovld __cnfn lgamma(half3 x);
half4 __ovld __cnfn lgamma(half4 x);
half8 __ovld __cnfn lgamma(half8 x);
half16 __ovld __cnfn lgamma(half16 x);
#endif //cl_khr_fp16

/**
 * Compute natural logarithm.
 */
float __ovld __cnfn log(float);
float2 __ovld __cnfn log(float2);
float3 __ovld __cnfn log(float3);
float4 __ovld __cnfn log(float4);
float8 __ovld __cnfn log(float8);
float16 __ovld __cnfn log(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn log(double);
double2 __ovld __cnfn log(double2);
double3 __ovld __cnfn log(double3);
double4 __ovld __cnfn log(double4);
double8 __ovld __cnfn log(double8);
double16 __ovld __cnfn log(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn log(half);
half2 __ovld __cnfn log(half2);
half3 __ovld __cnfn log(half3);
half4 __ovld __cnfn log(half4);
half8 __ovld __cnfn log(half8);
half16 __ovld __cnfn log(half16);
#endif //cl_khr_fp16

/**
 * Compute a base 2 logarithm.
 */
float __ovld __cnfn log2(float);
float2 __ovld __cnfn log2(float2);
float3 __ovld __cnfn log2(float3);
float4 __ovld __cnfn log2(float4);
float8 __ovld __cnfn log2(float8);
float16 __ovld __cnfn log2(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn log2(double);
double2 __ovld __cnfn log2(double2);
double3 __ovld __cnfn log2(double3);
double4 __ovld __cnfn log2(double4);
double8 __ovld __cnfn log2(double8);
double16 __ovld __cnfn log2(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn log2(half);
half2 __ovld __cnfn log2(half2);
half3 __ovld __cnfn log2(half3);
half4 __ovld __cnfn log2(half4);
half8 __ovld __cnfn log2(half8);
half16 __ovld __cnfn log2(half16);
#endif //cl_khr_fp16

/**
 * Compute a base 10 logarithm.
 */
float __ovld __cnfn log10(float);
float2 __ovld __cnfn log10(float2);
float3 __ovld __cnfn log10(float3);
float4 __ovld __cnfn log10(float4);
float8 __ovld __cnfn log10(float8);
float16 __ovld __cnfn log10(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn log10(double);
double2 __ovld __cnfn log10(double2);
double3 __ovld __cnfn log10(double3);
double4 __ovld __cnfn log10(double4);
double8 __ovld __cnfn log10(double8);
double16 __ovld __cnfn log10(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn log10(half);
half2 __ovld __cnfn log10(half2);
half3 __ovld __cnfn log10(half3);
half4 __ovld __cnfn log10(half4);
half8 __ovld __cnfn log10(half8);
half16 __ovld __cnfn log10(half16);
#endif //cl_khr_fp16

/**
 * Compute a base e logarithm of (1.0 + x).
 */
float __ovld __cnfn log1p(float x);
float2 __ovld __cnfn log1p(float2 x);
float3 __ovld __cnfn log1p(float3 x);
float4 __ovld __cnfn log1p(float4 x);
float8 __ovld __cnfn log1p(float8 x);
float16 __ovld __cnfn log1p(float16 x);
#ifdef cl_khr_fp64
double __ovld __cnfn log1p(double x);
double2 __ovld __cnfn log1p(double2 x);
double3 __ovld __cnfn log1p(double3 x);
double4 __ovld __cnfn log1p(double4 x);
double8 __ovld __cnfn log1p(double8 x);
double16 __ovld __cnfn log1p(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn log1p(half x);
half2 __ovld __cnfn log1p(half2 x);
half3 __ovld __cnfn log1p(half3 x);
half4 __ovld __cnfn log1p(half4 x);
half8 __ovld __cnfn log1p(half8 x);
half16 __ovld __cnfn log1p(half16 x);
#endif //cl_khr_fp16

/**
 * Compute the exponent of x, which is the integral
 * part of logr | x |.
 */
float __ovld __cnfn logb(float x);
float2 __ovld __cnfn logb(float2 x);
float3 __ovld __cnfn logb(float3 x);
float4 __ovld __cnfn logb(float4 x);
float8 __ovld __cnfn logb(float8 x);
float16 __ovld __cnfn logb(float16 x);
#ifdef cl_khr_fp64
double __ovld __cnfn logb(double x);
double2 __ovld __cnfn logb(double2 x);
double3 __ovld __cnfn logb(double3 x);
double4 __ovld __cnfn logb(double4 x);
double8 __ovld __cnfn logb(double8 x);
double16 __ovld __cnfn logb(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn logb(half x);
half2 __ovld __cnfn logb(half2 x);
half3 __ovld __cnfn logb(half3 x);
half4 __ovld __cnfn logb(half4 x);
half8 __ovld __cnfn logb(half8 x);
half16 __ovld __cnfn logb(half16 x);
#endif //cl_khr_fp16

/**
 * mad approximates a * b + c. Whether or how the
 * product of a * b is rounded and how supernormal or
 * subnormal intermediate products are handled is not
 * defined. mad is intended to be used where speed is
 * preferred over accuracy.
 */
float __ovld __cnfn mad(float a, float b, float c);
float2 __ovld __cnfn mad(float2 a, float2 b, float2 c);
float3 __ovld __cnfn mad(float3 a, float3 b, float3 c);
float4 __ovld __cnfn mad(float4 a, float4 b, float4 c);
float8 __ovld __cnfn mad(float8 a, float8 b, float8 c);
float16 __ovld __cnfn mad(float16 a, float16 b, float16 c);
#ifdef cl_khr_fp64
double __ovld __cnfn mad(double a, double b, double c);
double2 __ovld __cnfn mad(double2 a, double2 b, double2 c);
double3 __ovld __cnfn mad(double3 a, double3 b, double3 c);
double4 __ovld __cnfn mad(double4 a, double4 b, double4 c);
double8 __ovld __cnfn mad(double8 a, double8 b, double8 c);
double16 __ovld __cnfn mad(double16 a, double16 b, double16 c);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn mad(half a, half b, half c);
half2 __ovld __cnfn mad(half2 a, half2 b, half2 c);
half3 __ovld __cnfn mad(half3 a, half3 b, half3 c);
half4 __ovld __cnfn mad(half4 a, half4 b, half4 c);
half8 __ovld __cnfn mad(half8 a, half8 b, half8 c);
half16 __ovld __cnfn mad(half16 a, half16 b, half16 c);
#endif //cl_khr_fp16

/**
 * Returns x if | x | > | y |, y if | y | > | x |, otherwise
 * fmax(x, y).
 */
float __ovld __cnfn maxmag(float x, float y);
float2 __ovld __cnfn maxmag(float2 x, float2 y);
float3 __ovld __cnfn maxmag(float3 x, float3 y);
float4 __ovld __cnfn maxmag(float4 x, float4 y);
float8 __ovld __cnfn maxmag(float8 x, float8 y);
float16 __ovld __cnfn maxmag(float16 x, float16 y);
#ifdef cl_khr_fp64
double __ovld __cnfn maxmag(double x, double y);
double2 __ovld __cnfn maxmag(double2 x, double2 y);
double3 __ovld __cnfn maxmag(double3 x, double3 y);
double4 __ovld __cnfn maxmag(double4 x, double4 y);
double8 __ovld __cnfn maxmag(double8 x, double8 y);
double16 __ovld __cnfn maxmag(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn maxmag(half x, half y);
half2 __ovld __cnfn maxmag(half2 x, half2 y);
half3 __ovld __cnfn maxmag(half3 x, half3 y);
half4 __ovld __cnfn maxmag(half4 x, half4 y);
half8 __ovld __cnfn maxmag(half8 x, half8 y);
half16 __ovld __cnfn maxmag(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Returns x if | x | < | y |, y if | y | < | x |, otherwise
 * fmin(x, y).
 */
float __ovld __cnfn minmag(float x, float y);
float2 __ovld __cnfn minmag(float2 x, float2 y);
float3 __ovld __cnfn minmag(float3 x, float3 y);
float4 __ovld __cnfn minmag(float4 x, float4 y);
float8 __ovld __cnfn minmag(float8 x, float8 y);
float16 __ovld __cnfn minmag(float16 x, float16 y);
#ifdef cl_khr_fp64
double __ovld __cnfn minmag(double x, double y);
double2 __ovld __cnfn minmag(double2 x, double2 y);
double3 __ovld __cnfn minmag(double3 x, double3 y);
double4 __ovld __cnfn minmag(double4 x, double4 y);
double8 __ovld __cnfn minmag(double8 x, double8 y);
double16 __ovld __cnfn minmag(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn minmag(half x, half y);
half2 __ovld __cnfn minmag(half2 x, half2 y);
half3 __ovld __cnfn minmag(half3 x, half3 y);
half4 __ovld __cnfn minmag(half4 x, half4 y);
half8 __ovld __cnfn minmag(half8 x, half8 y);
half16 __ovld __cnfn minmag(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Returns a quiet NaN. The nancode may be placed
 * in the significand of the resulting NaN.
 */
float __ovld __cnfn nan(uint nancode);
float2 __ovld __cnfn nan(uint2 nancode);
float3 __ovld __cnfn nan(uint3 nancode);
float4 __ovld __cnfn nan(uint4 nancode);
float8 __ovld __cnfn nan(uint8 nancode);
float16 __ovld __cnfn nan(uint16 nancode);
#ifdef cl_khr_fp64
double __ovld __cnfn nan(ulong nancode);
double2 __ovld __cnfn nan(ulong2 nancode);
double3 __ovld __cnfn nan(ulong3 nancode);
double4 __ovld __cnfn nan(ulong4 nancode);
double8 __ovld __cnfn nan(ulong8 nancode);
double16 __ovld __cnfn nan(ulong16 nancode);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn nan(ushort nancode);
half2 __ovld __cnfn nan(ushort2 nancode);
half3 __ovld __cnfn nan(ushort3 nancode);
half4 __ovld __cnfn nan(ushort4 nancode);
half8 __ovld __cnfn nan(ushort8 nancode);
half16 __ovld __cnfn nan(ushort16 nancode);
#endif //cl_khr_fp16

/**
 * Computes the next representable single-precision
 * floating-point value following x in the direction of
 * y. Thus, if y is less than x, nextafter() returns the
 * largest representable floating-point number less
 * than x.
 */
float __ovld __cnfn nextafter(float x, float y);
float2 __ovld __cnfn nextafter(float2 x, float2 y);
float3 __ovld __cnfn nextafter(float3 x, float3 y);
float4 __ovld __cnfn nextafter(float4 x, float4 y);
float8 __ovld __cnfn nextafter(float8 x, float8 y);
float16 __ovld __cnfn nextafter(float16 x, float16 y);
#ifdef cl_khr_fp64
double __ovld __cnfn nextafter(double x, double y);
double2 __ovld __cnfn nextafter(double2 x, double2 y);
double3 __ovld __cnfn nextafter(double3 x, double3 y);
double4 __ovld __cnfn nextafter(double4 x, double4 y);
double8 __ovld __cnfn nextafter(double8 x, double8 y);
double16 __ovld __cnfn nextafter(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn nextafter(half x, half y);
half2 __ovld __cnfn nextafter(half2 x, half2 y);
half3 __ovld __cnfn nextafter(half3 x, half3 y);
half4 __ovld __cnfn nextafter(half4 x, half4 y);
half8 __ovld __cnfn nextafter(half8 x, half8 y);
half16 __ovld __cnfn nextafter(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Compute x to the power y.
 */
float __ovld __cnfn pow(float x, float y);
float2 __ovld __cnfn pow(float2 x, float2 y);
float3 __ovld __cnfn pow(float3 x, float3 y);
float4 __ovld __cnfn pow(float4 x, float4 y);
float8 __ovld __cnfn pow(float8 x, float8 y);
float16 __ovld __cnfn pow(float16 x, float16 y);
#ifdef cl_khr_fp64
double __ovld __cnfn pow(double x, double y);
double2 __ovld __cnfn pow(double2 x, double2 y);
double3 __ovld __cnfn pow(double3 x, double3 y);
double4 __ovld __cnfn pow(double4 x, double4 y);
double8 __ovld __cnfn pow(double8 x, double8 y);
double16 __ovld __cnfn pow(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn pow(half x, half y);
half2 __ovld __cnfn pow(half2 x, half2 y);
half3 __ovld __cnfn pow(half3 x, half3 y);
half4 __ovld __cnfn pow(half4 x, half4 y);
half8 __ovld __cnfn pow(half8 x, half8 y);
half16 __ovld __cnfn pow(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Compute x to the power y, where y is an integer.
 */
float __ovld __cnfn pown(float x, int y);
float2 __ovld __cnfn pown(float2 x, int2 y);
float3 __ovld __cnfn pown(float3 x, int3 y);
float4 __ovld __cnfn pown(float4 x, int4 y);
float8 __ovld __cnfn pown(float8 x, int8 y);
float16 __ovld __cnfn pown(float16 x, int16 y);
#ifdef cl_khr_fp64
double __ovld __cnfn pown(double x, int y);
double2 __ovld __cnfn pown(double2 x, int2 y);
double3 __ovld __cnfn pown(double3 x, int3 y);
double4 __ovld __cnfn pown(double4 x, int4 y);
double8 __ovld __cnfn pown(double8 x, int8 y);
double16 __ovld __cnfn pown(double16 x, int16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn pown(half x, int y);
half2 __ovld __cnfn pown(half2 x, int2 y);
half3 __ovld __cnfn pown(half3 x, int3 y);
half4 __ovld __cnfn pown(half4 x, int4 y);
half8 __ovld __cnfn pown(half8 x, int8 y);
half16 __ovld __cnfn pown(half16 x, int16 y);
#endif //cl_khr_fp16

/**
 * Compute x to the power y, where x is >= 0.
 */
float __ovld __cnfn powr(float x, float y);
float2 __ovld __cnfn powr(float2 x, float2 y);
float3 __ovld __cnfn powr(float3 x, float3 y);
float4 __ovld __cnfn powr(float4 x, float4 y);
float8 __ovld __cnfn powr(float8 x, float8 y);
float16 __ovld __cnfn powr(float16 x, float16 y);
#ifdef cl_khr_fp64
double __ovld __cnfn powr(double x, double y);
double2 __ovld __cnfn powr(double2 x, double2 y);
double3 __ovld __cnfn powr(double3 x, double3 y);
double4 __ovld __cnfn powr(double4 x, double4 y);
double8 __ovld __cnfn powr(double8 x, double8 y);
double16 __ovld __cnfn powr(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn powr(half x, half y);
half2 __ovld __cnfn powr(half2 x, half2 y);
half3 __ovld __cnfn powr(half3 x, half3 y);
half4 __ovld __cnfn powr(half4 x, half4 y);
half8 __ovld __cnfn powr(half8 x, half8 y);
half16 __ovld __cnfn powr(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Compute the value r such that r = x - n*y, where n
 * is the integer nearest the exact value of x/y. If there
 * are two integers closest to x/y, n shall be the even
 * one. If r is zero, it is given the same sign as x.
 */
float __ovld __cnfn remainder(float x, float y);
float2 __ovld __cnfn remainder(float2 x, float2 y);
float3 __ovld __cnfn remainder(float3 x, float3 y);
float4 __ovld __cnfn remainder(float4 x, float4 y);
float8 __ovld __cnfn remainder(float8 x, float8 y);
float16 __ovld __cnfn remainder(float16 x, float16 y);
#ifdef cl_khr_fp64
double __ovld __cnfn remainder(double x, double y);
double2 __ovld __cnfn remainder(double2 x, double2 y);
double3 __ovld __cnfn remainder(double3 x, double3 y);
double4 __ovld __cnfn remainder(double4 x, double4 y);
double8 __ovld __cnfn remainder(double8 x, double8 y);
double16 __ovld __cnfn remainder(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn remainder(half x, half y);
half2 __ovld __cnfn remainder(half2 x, half2 y);
half3 __ovld __cnfn remainder(half3 x, half3 y);
half4 __ovld __cnfn remainder(half4 x, half4 y);
half8 __ovld __cnfn remainder(half8 x, half8 y);
half16 __ovld __cnfn remainder(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Round to integral value (using round to nearest
 * even rounding mode) in floating-point format.
 * Refer to section 7.1 for description of rounding
 * modes.
 */
float __ovld __cnfn rint(float);
float2 __ovld __cnfn rint(float2);
float3 __ovld __cnfn rint(float3);
float4 __ovld __cnfn rint(float4);
float8 __ovld __cnfn rint(float8);
float16 __ovld __cnfn rint(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn rint(double);
double2 __ovld __cnfn rint(double2);
double3 __ovld __cnfn rint(double3);
double4 __ovld __cnfn rint(double4);
double8 __ovld __cnfn rint(double8);
double16 __ovld __cnfn rint(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn rint(half);
half2 __ovld __cnfn rint(half2);
half3 __ovld __cnfn rint(half3);
half4 __ovld __cnfn rint(half4);
half8 __ovld __cnfn rint(half8);
half16 __ovld __cnfn rint(half16);
#endif //cl_khr_fp16

/**
 * Compute x to the power 1/y.
 */
float __ovld __cnfn rootn(float x, int y);
float2 __ovld __cnfn rootn(float2 x, int2 y);
float3 __ovld __cnfn rootn(float3 x, int3 y);
float4 __ovld __cnfn rootn(float4 x, int4 y);
float8 __ovld __cnfn rootn(float8 x, int8 y);
float16 __ovld __cnfn rootn(float16 x, int16 y);
#ifdef cl_khr_fp64
double __ovld __cnfn rootn(double x, int y);
double2 __ovld __cnfn rootn(double2 x, int2 y);
double3 __ovld __cnfn rootn(double3 x, int3 y);
double4 __ovld __cnfn rootn(double4 x, int4 y);
double8 __ovld __cnfn rootn(double8 x, int8 y);
double16 __ovld __cnfn rootn(double16 x, int16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn rootn(half x, int y);
half2 __ovld __cnfn rootn(half2 x, int2 y);
half3 __ovld __cnfn rootn(half3 x, int3 y);
half4 __ovld __cnfn rootn(half4 x, int4 y);
half8 __ovld __cnfn rootn(half8 x, int8 y);
half16 __ovld __cnfn rootn(half16 x, int16 y);
#endif //cl_khr_fp16

/**
 * Return the integral value nearest to x rounding
 * halfway cases away from zero, regardless of the
 * current rounding direction.
 */
float __ovld __cnfn round(float x);
float2 __ovld __cnfn round(float2 x);
float3 __ovld __cnfn round(float3 x);
float4 __ovld __cnfn round(float4 x);
float8 __ovld __cnfn round(float8 x);
float16 __ovld __cnfn round(float16 x);
#ifdef cl_khr_fp64
double __ovld __cnfn round(double x);
double2 __ovld __cnfn round(double2 x);
double3 __ovld __cnfn round(double3 x);
double4 __ovld __cnfn round(double4 x);
double8 __ovld __cnfn round(double8 x);
double16 __ovld __cnfn round(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn round(half x);
half2 __ovld __cnfn round(half2 x);
half3 __ovld __cnfn round(half3 x);
half4 __ovld __cnfn round(half4 x);
half8 __ovld __cnfn round(half8 x);
half16 __ovld __cnfn round(half16 x);
#endif //cl_khr_fp16

/**
 * Compute inverse square root.
 */
float __ovld __cnfn rsqrt(float);
float2 __ovld __cnfn rsqrt(float2);
float3 __ovld __cnfn rsqrt(float3);
float4 __ovld __cnfn rsqrt(float4);
float8 __ovld __cnfn rsqrt(float8);
float16 __ovld __cnfn rsqrt(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn rsqrt(double);
double2 __ovld __cnfn rsqrt(double2);
double3 __ovld __cnfn rsqrt(double3);
double4 __ovld __cnfn rsqrt(double4);
double8 __ovld __cnfn rsqrt(double8);
double16 __ovld __cnfn rsqrt(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn rsqrt(half);
half2 __ovld __cnfn rsqrt(half2);
half3 __ovld __cnfn rsqrt(half3);
half4 __ovld __cnfn rsqrt(half4);
half8 __ovld __cnfn rsqrt(half8);
half16 __ovld __cnfn rsqrt(half16);
#endif //cl_khr_fp16

/**
 * Compute sine.
 */
float __ovld __cnfn sin(float);
float2 __ovld __cnfn sin(float2);
float3 __ovld __cnfn sin(float3);
float4 __ovld __cnfn sin(float4);
float8 __ovld __cnfn sin(float8);
float16 __ovld __cnfn sin(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn sin(double);
double2 __ovld __cnfn sin(double2);
double3 __ovld __cnfn sin(double3);
double4 __ovld __cnfn sin(double4);
double8 __ovld __cnfn sin(double8);
double16 __ovld __cnfn sin(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn sin(half);
half2 __ovld __cnfn sin(half2);
half3 __ovld __cnfn sin(half3);
half4 __ovld __cnfn sin(half4);
half8 __ovld __cnfn sin(half8);
half16 __ovld __cnfn sin(half16);
#endif //cl_khr_fp16

/**
 * Compute hyperbolic sine.
 */
float __ovld __cnfn sinh(float);
float2 __ovld __cnfn sinh(float2);
float3 __ovld __cnfn sinh(float3);
float4 __ovld __cnfn sinh(float4);
float8 __ovld __cnfn sinh(float8);
float16 __ovld __cnfn sinh(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn sinh(double);
double2 __ovld __cnfn sinh(double2);
double3 __ovld __cnfn sinh(double3);
double4 __ovld __cnfn sinh(double4);
double8 __ovld __cnfn sinh(double8);
double16 __ovld __cnfn sinh(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn sinh(half);
half2 __ovld __cnfn sinh(half2);
half3 __ovld __cnfn sinh(half3);
half4 __ovld __cnfn sinh(half4);
half8 __ovld __cnfn sinh(half8);
half16 __ovld __cnfn sinh(half16);
#endif //cl_khr_fp16

/**
 * Compute sin (PI * x).
 */
float __ovld __cnfn sinpi(float x);
float2 __ovld __cnfn sinpi(float2 x);
float3 __ovld __cnfn sinpi(float3 x);
float4 __ovld __cnfn sinpi(float4 x);
float8 __ovld __cnfn sinpi(float8 x);
float16 __ovld __cnfn sinpi(float16 x);
#ifdef cl_khr_fp64
double __ovld __cnfn sinpi(double x);
double2 __ovld __cnfn sinpi(double2 x);
double3 __ovld __cnfn sinpi(double3 x);
double4 __ovld __cnfn sinpi(double4 x);
double8 __ovld __cnfn sinpi(double8 x);
double16 __ovld __cnfn sinpi(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn sinpi(half x);
half2 __ovld __cnfn sinpi(half2 x);
half3 __ovld __cnfn sinpi(half3 x);
half4 __ovld __cnfn sinpi(half4 x);
half8 __ovld __cnfn sinpi(half8 x);
half16 __ovld __cnfn sinpi(half16 x);
#endif //cl_khr_fp16

/**
 * Compute square root.
 */
float __ovld __cnfn sqrt(float);
float2 __ovld __cnfn sqrt(float2);
float3 __ovld __cnfn sqrt(float3);
float4 __ovld __cnfn sqrt(float4);
float8 __ovld __cnfn sqrt(float8);
float16 __ovld __cnfn sqrt(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn sqrt(double);
double2 __ovld __cnfn sqrt(double2);
double3 __ovld __cnfn sqrt(double3);
double4 __ovld __cnfn sqrt(double4);
double8 __ovld __cnfn sqrt(double8);
double16 __ovld __cnfn sqrt(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn sqrt(half);
half2 __ovld __cnfn sqrt(half2);
half3 __ovld __cnfn sqrt(half3);
half4 __ovld __cnfn sqrt(half4);
half8 __ovld __cnfn sqrt(half8);
half16 __ovld __cnfn sqrt(half16);
#endif //cl_khr_fp16

/**
 * Compute tangent.
 */
float __ovld __cnfn tan(float);
float2 __ovld __cnfn tan(float2);
float3 __ovld __cnfn tan(float3);
float4 __ovld __cnfn tan(float4);
float8 __ovld __cnfn tan(float8);
float16 __ovld __cnfn tan(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn tan(double);
double2 __ovld __cnfn tan(double2);
double3 __ovld __cnfn tan(double3);
double4 __ovld __cnfn tan(double4);
double8 __ovld __cnfn tan(double8);
double16 __ovld __cnfn tan(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn tan(half);
half2 __ovld __cnfn tan(half2);
half3 __ovld __cnfn tan(half3);
half4 __ovld __cnfn tan(half4);
half8 __ovld __cnfn tan(half8);
half16 __ovld __cnfn tan(half16);
#endif //cl_khr_fp16

/**
 * Compute hyperbolic tangent.
 */
float __ovld __cnfn tanh(float);
float2 __ovld __cnfn tanh(float2);
float3 __ovld __cnfn tanh(float3);
float4 __ovld __cnfn tanh(float4);
float8 __ovld __cnfn tanh(float8);
float16 __ovld __cnfn tanh(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn tanh(double);
double2 __ovld __cnfn tanh(double2);
double3 __ovld __cnfn tanh(double3);
double4 __ovld __cnfn tanh(double4);
double8 __ovld __cnfn tanh(double8);
double16 __ovld __cnfn tanh(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn tanh(half);
half2 __ovld __cnfn tanh(half2);
half3 __ovld __cnfn tanh(half3);
half4 __ovld __cnfn tanh(half4);
half8 __ovld __cnfn tanh(half8);
half16 __ovld __cnfn tanh(half16);
#endif //cl_khr_fp16

/**
 * Compute tan (PI * x).
 */
float __ovld __cnfn tanpi(float x);
float2 __ovld __cnfn tanpi(float2 x);
float3 __ovld __cnfn tanpi(float3 x);
float4 __ovld __cnfn tanpi(float4 x);
float8 __ovld __cnfn tanpi(float8 x);
float16 __ovld __cnfn tanpi(float16 x);
#ifdef cl_khr_fp64
double __ovld __cnfn tanpi(double x);
double2 __ovld __cnfn tanpi(double2 x);
double3 __ovld __cnfn tanpi(double3 x);
double4 __ovld __cnfn tanpi(double4 x);
double8 __ovld __cnfn tanpi(double8 x);
double16 __ovld __cnfn tanpi(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn tanpi(half x);
half2 __ovld __cnfn tanpi(half2 x);
half3 __ovld __cnfn tanpi(half3 x);
half4 __ovld __cnfn tanpi(half4 x);
half8 __ovld __cnfn tanpi(half8 x);
half16 __ovld __cnfn tanpi(half16 x);
#endif //cl_khr_fp16

/**
 * Compute the gamma function.
 */
float __ovld __cnfn tgamma(float);
float2 __ovld __cnfn tgamma(float2);
float3 __ovld __cnfn tgamma(float3);
float4 __ovld __cnfn tgamma(float4);
float8 __ovld __cnfn tgamma(float8);
float16 __ovld __cnfn tgamma(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn tgamma(double);
double2 __ovld __cnfn tgamma(double2);
double3 __ovld __cnfn tgamma(double3);
double4 __ovld __cnfn tgamma(double4);
double8 __ovld __cnfn tgamma(double8);
double16 __ovld __cnfn tgamma(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn tgamma(half);
half2 __ovld __cnfn tgamma(half2);
half3 __ovld __cnfn tgamma(half3);
half4 __ovld __cnfn tgamma(half4);
half8 __ovld __cnfn tgamma(half8);
half16 __ovld __cnfn tgamma(half16);
#endif //cl_khr_fp16

/**
 * Round to integral value using the round to zero
 * rounding mode.
 */
float __ovld __cnfn trunc(float);
float2 __ovld __cnfn trunc(float2);
float3 __ovld __cnfn trunc(float3);
float4 __ovld __cnfn trunc(float4);
float8 __ovld __cnfn trunc(float8);
float16 __ovld __cnfn trunc(float16);
#ifdef cl_khr_fp64
double __ovld __cnfn trunc(double);
double2 __ovld __cnfn trunc(double2);
double3 __ovld __cnfn trunc(double3);
double4 __ovld __cnfn trunc(double4);
double8 __ovld __cnfn trunc(double8);
double16 __ovld __cnfn trunc(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn trunc(half);
half2 __ovld __cnfn trunc(half2);
half3 __ovld __cnfn trunc(half3);
half4 __ovld __cnfn trunc(half4);
half8 __ovld __cnfn trunc(half8);
half16 __ovld __cnfn trunc(half16);
#endif //cl_khr_fp16

/**
 * Compute cosine. x must be in the range -2^16 ... +2^16.
 */
float __ovld __cnfn half_cos(float x);
float2 __ovld __cnfn half_cos(float2 x);
float3 __ovld __cnfn half_cos(float3 x);
float4 __ovld __cnfn half_cos(float4 x);
float8 __ovld __cnfn half_cos(float8 x);
float16 __ovld __cnfn half_cos(float16 x);

/**
 * Compute x / y.
 */
float __ovld __cnfn half_divide(float x, float y);
float2 __ovld __cnfn half_divide(float2 x, float2 y);
float3 __ovld __cnfn half_divide(float3 x, float3 y);
float4 __ovld __cnfn half_divide(float4 x, float4 y);
float8 __ovld __cnfn half_divide(float8 x, float8 y);
float16 __ovld __cnfn half_divide(float16 x, float16 y);

/**
 * Compute the base- e exponential of x.
 */
float __ovld __cnfn half_exp(float x);
float2 __ovld __cnfn half_exp(float2 x);
float3 __ovld __cnfn half_exp(float3 x);
float4 __ovld __cnfn half_exp(float4 x);
float8 __ovld __cnfn half_exp(float8 x);
float16 __ovld __cnfn half_exp(float16 x);

/**
 * Compute the base- 2 exponential of x.
 */
float __ovld __cnfn half_exp2(float x);
float2 __ovld __cnfn half_exp2(float2 x);
float3 __ovld __cnfn half_exp2(float3 x);
float4 __ovld __cnfn half_exp2(float4 x);
float8 __ovld __cnfn half_exp2(float8 x);
float16 __ovld __cnfn half_exp2(float16 x);

/**
 * Compute the base- 10 exponential of x.
 */
float __ovld __cnfn half_exp10(float x);
float2 __ovld __cnfn half_exp10(float2 x);
float3 __ovld __cnfn half_exp10(float3 x);
float4 __ovld __cnfn half_exp10(float4 x);
float8 __ovld __cnfn half_exp10(float8 x);
float16 __ovld __cnfn half_exp10(float16 x);

/**
 * Compute natural logarithm.
 */
float __ovld __cnfn half_log(float x);
float2 __ovld __cnfn half_log(float2 x);
float3 __ovld __cnfn half_log(float3 x);
float4 __ovld __cnfn half_log(float4 x);
float8 __ovld __cnfn half_log(float8 x);
float16 __ovld __cnfn half_log(float16 x);

/**
 * Compute a base 2 logarithm.
 */
float __ovld __cnfn half_log2(float x);
float2 __ovld __cnfn half_log2(float2 x);
float3 __ovld __cnfn half_log2(float3 x);
float4 __ovld __cnfn half_log2(float4 x);
float8 __ovld __cnfn half_log2(float8 x);
float16 __ovld __cnfn half_log2(float16 x);

/**
 * Compute a base 10 logarithm.
 */
float __ovld __cnfn half_log10(float x);
float2 __ovld __cnfn half_log10(float2 x);
float3 __ovld __cnfn half_log10(float3 x);
float4 __ovld __cnfn half_log10(float4 x);
float8 __ovld __cnfn half_log10(float8 x);
float16 __ovld __cnfn half_log10(float16 x);

/**
 * Compute x to the power y, where x is >= 0.
 */
float __ovld __cnfn half_powr(float x, float y);
float2 __ovld __cnfn half_powr(float2 x, float2 y);
float3 __ovld __cnfn half_powr(float3 x, float3 y);
float4 __ovld __cnfn half_powr(float4 x, float4 y);
float8 __ovld __cnfn half_powr(float8 x, float8 y);
float16 __ovld __cnfn half_powr(float16 x, float16 y);

/**
 * Compute reciprocal.
 */
float __ovld __cnfn half_recip(float x);
float2 __ovld __cnfn half_recip(float2 x);
float3 __ovld __cnfn half_recip(float3 x);
float4 __ovld __cnfn half_recip(float4 x);
float8 __ovld __cnfn half_recip(float8 x);
float16 __ovld __cnfn half_recip(float16 x);

/**
 * Compute inverse square root.
 */
float __ovld __cnfn half_rsqrt(float x);
float2 __ovld __cnfn half_rsqrt(float2 x);
float3 __ovld __cnfn half_rsqrt(float3 x);
float4 __ovld __cnfn half_rsqrt(float4 x);
float8 __ovld __cnfn half_rsqrt(float8 x);
float16 __ovld __cnfn half_rsqrt(float16 x);

/**
 * Compute sine. x must be in the range -2^16 ... +2^16.
 */
float __ovld __cnfn half_sin(float x);
float2 __ovld __cnfn half_sin(float2 x);
float3 __ovld __cnfn half_sin(float3 x);
float4 __ovld __cnfn half_sin(float4 x);
float8 __ovld __cnfn half_sin(float8 x);
float16 __ovld __cnfn half_sin(float16 x);

/**
 * Compute square root.
 */
float __ovld __cnfn half_sqrt(float x);
float2 __ovld __cnfn half_sqrt(float2 x);
float3 __ovld __cnfn half_sqrt(float3 x);
float4 __ovld __cnfn half_sqrt(float4 x);
float8 __ovld __cnfn half_sqrt(float8 x);
float16 __ovld __cnfn half_sqrt(float16 x);

/**
 * Compute tangent. x must be in the range -216 ... +216.
 */
float __ovld __cnfn half_tan(float x);
float2 __ovld __cnfn half_tan(float2 x);
float3 __ovld __cnfn half_tan(float3 x);
float4 __ovld __cnfn half_tan(float4 x);
float8 __ovld __cnfn half_tan(float8 x);
float16 __ovld __cnfn half_tan(float16 x);

/**
 * Compute cosine over an implementation-defined range.
 * The maximum error is implementation-defined.
 */
float __ovld __cnfn native_cos(float x);
float2 __ovld __cnfn native_cos(float2 x);
float3 __ovld __cnfn native_cos(float3 x);
float4 __ovld __cnfn native_cos(float4 x);
float8 __ovld __cnfn native_cos(float8 x);
float16 __ovld __cnfn native_cos(float16 x);

/**
 * Compute x / y over an implementation-defined range.
 * The maximum error is implementation-defined.
 */
float __ovld __cnfn native_divide(float x, float y);
float2 __ovld __cnfn native_divide(float2 x, float2 y);
float3 __ovld __cnfn native_divide(float3 x, float3 y);
float4 __ovld __cnfn native_divide(float4 x, float4 y);
float8 __ovld __cnfn native_divide(float8 x, float8 y);
float16 __ovld __cnfn native_divide(float16 x, float16 y);

/**
 * Compute the base- e exponential of x over an
 * implementation-defined range. The maximum error is
 * implementation-defined.
 */
float __ovld __cnfn native_exp(float x);
float2 __ovld __cnfn native_exp(float2 x);
float3 __ovld __cnfn native_exp(float3 x);
float4 __ovld __cnfn native_exp(float4 x);
float8 __ovld __cnfn native_exp(float8 x);
float16 __ovld __cnfn native_exp(float16 x);

/**
 * Compute the base- 2 exponential of x over an
 * implementation-defined range. The maximum error is
 * implementation-defined.
 */
float __ovld __cnfn native_exp2(float x);
float2 __ovld __cnfn native_exp2(float2 x);
float3 __ovld __cnfn native_exp2(float3 x);
float4 __ovld __cnfn native_exp2(float4 x);
float8 __ovld __cnfn native_exp2(float8 x);
float16 __ovld __cnfn native_exp2(float16 x);

/**
 * Compute the base- 10 exponential of x over an
 * implementation-defined range. The maximum error is
 * implementation-defined.
 */
float __ovld __cnfn native_exp10(float x);
float2 __ovld __cnfn native_exp10(float2 x);
float3 __ovld __cnfn native_exp10(float3 x);
float4 __ovld __cnfn native_exp10(float4 x);
float8 __ovld __cnfn native_exp10(float8 x);
float16 __ovld __cnfn native_exp10(float16 x);

/**
 * Compute natural logarithm over an implementationdefined
 * range. The maximum error is implementation
 * defined.
 */
float __ovld __cnfn native_log(float x);
float2 __ovld __cnfn native_log(float2 x);
float3 __ovld __cnfn native_log(float3 x);
float4 __ovld __cnfn native_log(float4 x);
float8 __ovld __cnfn native_log(float8 x);
float16 __ovld __cnfn native_log(float16 x);

/**
 * Compute a base 2 logarithm over an implementationdefined
 * range. The maximum error is implementationdefined.
 */
float __ovld __cnfn native_log2(float x);
float2 __ovld __cnfn native_log2(float2 x);
float3 __ovld __cnfn native_log2(float3 x);
float4 __ovld __cnfn native_log2(float4 x);
float8 __ovld __cnfn native_log2(float8 x);
float16 __ovld __cnfn native_log2(float16 x);

/**
 * Compute a base 10 logarithm over an implementationdefined
 * range. The maximum error is implementationdefined.
 */
float __ovld __cnfn native_log10(float x);
float2 __ovld __cnfn native_log10(float2 x);
float3 __ovld __cnfn native_log10(float3 x);
float4 __ovld __cnfn native_log10(float4 x);
float8 __ovld __cnfn native_log10(float8 x);
float16 __ovld __cnfn native_log10(float16 x);

/**
 * Compute x to the power y, where x is >= 0. The range of
 * x and y are implementation-defined. The maximum error
 * is implementation-defined.
 */
float __ovld __cnfn native_powr(float x, float y);
float2 __ovld __cnfn native_powr(float2 x, float2 y);
float3 __ovld __cnfn native_powr(float3 x, float3 y);
float4 __ovld __cnfn native_powr(float4 x, float4 y);
float8 __ovld __cnfn native_powr(float8 x, float8 y);
float16 __ovld __cnfn native_powr(float16 x, float16 y);

/**
 * Compute reciprocal over an implementation-defined
 * range. The maximum error is implementation-defined.
 */
float __ovld __cnfn native_recip(float x);
float2 __ovld __cnfn native_recip(float2 x);
float3 __ovld __cnfn native_recip(float3 x);
float4 __ovld __cnfn native_recip(float4 x);
float8 __ovld __cnfn native_recip(float8 x);
float16 __ovld __cnfn native_recip(float16 x);

/**
 * Compute inverse square root over an implementationdefined
 * range. The maximum error is implementationdefined.
 */
float __ovld __cnfn native_rsqrt(float x);
float2 __ovld __cnfn native_rsqrt(float2 x);
float3 __ovld __cnfn native_rsqrt(float3 x);
float4 __ovld __cnfn native_rsqrt(float4 x);
float8 __ovld __cnfn native_rsqrt(float8 x);
float16 __ovld __cnfn native_rsqrt(float16 x);

/**
 * Compute sine over an implementation-defined range.
 * The maximum error is implementation-defined.
 */
float __ovld __cnfn native_sin(float x);
float2 __ovld __cnfn native_sin(float2 x);
float3 __ovld __cnfn native_sin(float3 x);
float4 __ovld __cnfn native_sin(float4 x);
float8 __ovld __cnfn native_sin(float8 x);
float16 __ovld __cnfn native_sin(float16 x);

/**
 * Compute square root over an implementation-defined
 * range. The maximum error is implementation-defined.
 */
float __ovld __cnfn native_sqrt(float x);
float2 __ovld __cnfn native_sqrt(float2 x);
float3 __ovld __cnfn native_sqrt(float3 x);
float4 __ovld __cnfn native_sqrt(float4 x);
float8 __ovld __cnfn native_sqrt(float8 x);
float16 __ovld __cnfn native_sqrt(float16 x);

/**
 * Compute tangent over an implementation-defined range.
 * The maximum error is implementation-defined.
 */
float __ovld __cnfn native_tan(float x);
float2 __ovld __cnfn native_tan(float2 x);
float3 __ovld __cnfn native_tan(float3 x);
float4 __ovld __cnfn native_tan(float4 x);
float8 __ovld __cnfn native_tan(float8 x);
float16 __ovld __cnfn native_tan(float16 x);

// OpenCL v1.1 s6.11.3, v1.2 s6.12.3, v2.0 s6.13.3 - Integer Functions

/**
 * Returns | x |.
 */
uchar __ovld __cnfn abs(char x);
uchar __ovld __cnfn abs(uchar x);
uchar2 __ovld __cnfn abs(char2 x);
uchar2 __ovld __cnfn abs(uchar2 x);
uchar3 __ovld __cnfn abs(char3 x);
uchar3 __ovld __cnfn abs(uchar3 x);
uchar4 __ovld __cnfn abs(char4 x);
uchar4 __ovld __cnfn abs(uchar4 x);
uchar8 __ovld __cnfn abs(char8 x);
uchar8 __ovld __cnfn abs(uchar8 x);
uchar16 __ovld __cnfn abs(char16 x);
uchar16 __ovld __cnfn abs(uchar16 x);
ushort __ovld __cnfn abs(short x);
ushort __ovld __cnfn abs(ushort x);
ushort2 __ovld __cnfn abs(short2 x);
ushort2 __ovld __cnfn abs(ushort2 x);
ushort3 __ovld __cnfn abs(short3 x);
ushort3 __ovld __cnfn abs(ushort3 x);
ushort4 __ovld __cnfn abs(short4 x);
ushort4 __ovld __cnfn abs(ushort4 x);
ushort8 __ovld __cnfn abs(short8 x);
ushort8 __ovld __cnfn abs(ushort8 x);
ushort16 __ovld __cnfn abs(short16 x);
ushort16 __ovld __cnfn abs(ushort16 x);
uint __ovld __cnfn abs(int x);
uint __ovld __cnfn abs(uint x);
uint2 __ovld __cnfn abs(int2 x);
uint2 __ovld __cnfn abs(uint2 x);
uint3 __ovld __cnfn abs(int3 x);
uint3 __ovld __cnfn abs(uint3 x);
uint4 __ovld __cnfn abs(int4 x);
uint4 __ovld __cnfn abs(uint4 x);
uint8 __ovld __cnfn abs(int8 x);
uint8 __ovld __cnfn abs(uint8 x);
uint16 __ovld __cnfn abs(int16 x);
uint16 __ovld __cnfn abs(uint16 x);
ulong __ovld __cnfn abs(long x);
ulong __ovld __cnfn abs(ulong x);
ulong2 __ovld __cnfn abs(long2 x);
ulong2 __ovld __cnfn abs(ulong2 x);
ulong3 __ovld __cnfn abs(long3 x);
ulong3 __ovld __cnfn abs(ulong3 x);
ulong4 __ovld __cnfn abs(long4 x);
ulong4 __ovld __cnfn abs(ulong4 x);
ulong8 __ovld __cnfn abs(long8 x);
ulong8 __ovld __cnfn abs(ulong8 x);
ulong16 __ovld __cnfn abs(long16 x);
ulong16 __ovld __cnfn abs(ulong16 x);

/**
 * Returns | x - y | without modulo overflow.
 */
uchar __ovld __cnfn abs_diff(char x, char y);
uchar __ovld __cnfn abs_diff(uchar x, uchar y);
uchar2 __ovld __cnfn abs_diff(char2 x, char2 y);
uchar2 __ovld __cnfn abs_diff(uchar2 x, uchar2 y);
uchar3 __ovld __cnfn abs_diff(char3 x, char3 y);
uchar3 __ovld __cnfn abs_diff(uchar3 x, uchar3 y);
uchar4 __ovld __cnfn abs_diff(char4 x, char4 y);
uchar4 __ovld __cnfn abs_diff(uchar4 x, uchar4 y);
uchar8 __ovld __cnfn abs_diff(char8 x, char8 y);
uchar8 __ovld __cnfn abs_diff(uchar8 x, uchar8 y);
uchar16 __ovld __cnfn abs_diff(char16 x, char16 y);
uchar16 __ovld __cnfn abs_diff(uchar16 x, uchar16 y);
ushort __ovld __cnfn abs_diff(short x, short y);
ushort __ovld __cnfn abs_diff(ushort x, ushort y);
ushort2 __ovld __cnfn abs_diff(short2 x, short2 y);
ushort2 __ovld __cnfn abs_diff(ushort2 x, ushort2 y);
ushort3 __ovld __cnfn abs_diff(short3 x, short3 y);
ushort3 __ovld __cnfn abs_diff(ushort3 x, ushort3 y);
ushort4 __ovld __cnfn abs_diff(short4 x, short4 y);
ushort4 __ovld __cnfn abs_diff(ushort4 x, ushort4 y);
ushort8 __ovld __cnfn abs_diff(short8 x, short8 y);
ushort8 __ovld __cnfn abs_diff(ushort8 x, ushort8 y);
ushort16 __ovld __cnfn abs_diff(short16 x, short16 y);
ushort16 __ovld __cnfn abs_diff(ushort16 x, ushort16 y);
uint __ovld __cnfn abs_diff(int x, int y);
uint __ovld __cnfn abs_diff(uint x, uint y);
uint2 __ovld __cnfn abs_diff(int2 x, int2 y);
uint2 __ovld __cnfn abs_diff(uint2 x, uint2 y);
uint3 __ovld __cnfn abs_diff(int3 x, int3 y);
uint3 __ovld __cnfn abs_diff(uint3 x, uint3 y);
uint4 __ovld __cnfn abs_diff(int4 x, int4 y);
uint4 __ovld __cnfn abs_diff(uint4 x, uint4 y);
uint8 __ovld __cnfn abs_diff(int8 x, int8 y);
uint8 __ovld __cnfn abs_diff(uint8 x, uint8 y);
uint16 __ovld __cnfn abs_diff(int16 x, int16 y);
uint16 __ovld __cnfn abs_diff(uint16 x, uint16 y);
ulong __ovld __cnfn abs_diff(long x, long y);
ulong __ovld __cnfn abs_diff(ulong x, ulong y);
ulong2 __ovld __cnfn abs_diff(long2 x, long2 y);
ulong2 __ovld __cnfn abs_diff(ulong2 x, ulong2 y);
ulong3 __ovld __cnfn abs_diff(long3 x, long3 y);
ulong3 __ovld __cnfn abs_diff(ulong3 x, ulong3 y);
ulong4 __ovld __cnfn abs_diff(long4 x, long4 y);
ulong4 __ovld __cnfn abs_diff(ulong4 x, ulong4 y);
ulong8 __ovld __cnfn abs_diff(long8 x, long8 y);
ulong8 __ovld __cnfn abs_diff(ulong8 x, ulong8 y);
ulong16 __ovld __cnfn abs_diff(long16 x, long16 y);
ulong16 __ovld __cnfn abs_diff(ulong16 x, ulong16 y);

/**
 * Returns x + y and saturates the result.
 */
char __ovld __cnfn add_sat(char x, char y);
uchar __ovld __cnfn add_sat(uchar x, uchar y);
char2 __ovld __cnfn add_sat(char2 x, char2 y);
uchar2 __ovld __cnfn add_sat(uchar2 x, uchar2 y);
char3 __ovld __cnfn add_sat(char3 x, char3 y);
uchar3 __ovld __cnfn add_sat(uchar3 x, uchar3 y);
char4 __ovld __cnfn add_sat(char4 x, char4 y);
uchar4 __ovld __cnfn add_sat(uchar4 x, uchar4 y);
char8 __ovld __cnfn add_sat(char8 x, char8 y);
uchar8 __ovld __cnfn add_sat(uchar8 x, uchar8 y);
char16 __ovld __cnfn add_sat(char16 x, char16 y);
uchar16 __ovld __cnfn add_sat(uchar16 x, uchar16 y);
short __ovld __cnfn add_sat(short x, short y);
ushort __ovld __cnfn add_sat(ushort x, ushort y);
short2 __ovld __cnfn add_sat(short2 x, short2 y);
ushort2 __ovld __cnfn add_sat(ushort2 x, ushort2 y);
short3 __ovld __cnfn add_sat(short3 x, short3 y);
ushort3 __ovld __cnfn add_sat(ushort3 x, ushort3 y);
short4 __ovld __cnfn add_sat(short4 x, short4 y);
ushort4 __ovld __cnfn add_sat(ushort4 x, ushort4 y);
short8 __ovld __cnfn add_sat(short8 x, short8 y);
ushort8 __ovld __cnfn add_sat(ushort8 x, ushort8 y);
short16 __ovld __cnfn add_sat(short16 x, short16 y);
ushort16 __ovld __cnfn add_sat(ushort16 x, ushort16 y);
int __ovld __cnfn add_sat(int x, int y);
uint __ovld __cnfn add_sat(uint x, uint y);
int2 __ovld __cnfn add_sat(int2 x, int2 y);
uint2 __ovld __cnfn add_sat(uint2 x, uint2 y);
int3 __ovld __cnfn add_sat(int3 x, int3 y);
uint3 __ovld __cnfn add_sat(uint3 x, uint3 y);
int4 __ovld __cnfn add_sat(int4 x, int4 y);
uint4 __ovld __cnfn add_sat(uint4 x, uint4 y);
int8 __ovld __cnfn add_sat(int8 x, int8 y);
uint8 __ovld __cnfn add_sat(uint8 x, uint8 y);
int16 __ovld __cnfn add_sat(int16 x, int16 y);
uint16 __ovld __cnfn add_sat(uint16 x, uint16 y);
long __ovld __cnfn add_sat(long x, long y);
ulong __ovld __cnfn add_sat(ulong x, ulong y);
long2 __ovld __cnfn add_sat(long2 x, long2 y);
ulong2 __ovld __cnfn add_sat(ulong2 x, ulong2 y);
long3 __ovld __cnfn add_sat(long3 x, long3 y);
ulong3 __ovld __cnfn add_sat(ulong3 x, ulong3 y);
long4 __ovld __cnfn add_sat(long4 x, long4 y);
ulong4 __ovld __cnfn add_sat(ulong4 x, ulong4 y);
long8 __ovld __cnfn add_sat(long8 x, long8 y);
ulong8 __ovld __cnfn add_sat(ulong8 x, ulong8 y);
long16 __ovld __cnfn add_sat(long16 x, long16 y);
ulong16 __ovld __cnfn add_sat(ulong16 x, ulong16 y);

/**
 * Returns (x + y) >> 1. The intermediate sum does
 * not modulo overflow.
 */
char __ovld __cnfn hadd(char x, char y);
uchar __ovld __cnfn hadd(uchar x, uchar y);
char2 __ovld __cnfn hadd(char2 x, char2 y);
uchar2 __ovld __cnfn hadd(uchar2 x, uchar2 y);
char3 __ovld __cnfn hadd(char3 x, char3 y);
uchar3 __ovld __cnfn hadd(uchar3 x, uchar3 y);
char4 __ovld __cnfn hadd(char4 x, char4 y);
uchar4 __ovld __cnfn hadd(uchar4 x, uchar4 y);
char8 __ovld __cnfn hadd(char8 x, char8 y);
uchar8 __ovld __cnfn hadd(uchar8 x, uchar8 y);
char16 __ovld __cnfn hadd(char16 x, char16 y);
uchar16 __ovld __cnfn hadd(uchar16 x, uchar16 y);
short __ovld __cnfn hadd(short x, short y);
ushort __ovld __cnfn hadd(ushort x, ushort y);
short2 __ovld __cnfn hadd(short2 x, short2 y);
ushort2 __ovld __cnfn hadd(ushort2 x, ushort2 y);
short3 __ovld __cnfn hadd(short3 x, short3 y);
ushort3 __ovld __cnfn hadd(ushort3 x, ushort3 y);
short4 __ovld __cnfn hadd(short4 x, short4 y);
ushort4 __ovld __cnfn hadd(ushort4 x, ushort4 y);
short8 __ovld __cnfn hadd(short8 x, short8 y);
ushort8 __ovld __cnfn hadd(ushort8 x, ushort8 y);
short16 __ovld __cnfn hadd(short16 x, short16 y);
ushort16 __ovld __cnfn hadd(ushort16 x, ushort16 y);
int __ovld __cnfn hadd(int x, int y);
uint __ovld __cnfn hadd(uint x, uint y);
int2 __ovld __cnfn hadd(int2 x, int2 y);
uint2 __ovld __cnfn hadd(uint2 x, uint2 y);
int3 __ovld __cnfn hadd(int3 x, int3 y);
uint3 __ovld __cnfn hadd(uint3 x, uint3 y);
int4 __ovld __cnfn hadd(int4 x, int4 y);
uint4 __ovld __cnfn hadd(uint4 x, uint4 y);
int8 __ovld __cnfn hadd(int8 x, int8 y);
uint8 __ovld __cnfn hadd(uint8 x, uint8 y);
int16 __ovld __cnfn hadd(int16 x, int16 y);
uint16 __ovld __cnfn hadd(uint16 x, uint16 y);
long __ovld __cnfn hadd(long x, long y);
ulong __ovld __cnfn hadd(ulong x, ulong y);
long2 __ovld __cnfn hadd(long2 x, long2 y);
ulong2 __ovld __cnfn hadd(ulong2 x, ulong2 y);
long3 __ovld __cnfn hadd(long3 x, long3 y);
ulong3 __ovld __cnfn hadd(ulong3 x, ulong3 y);
long4 __ovld __cnfn hadd(long4 x, long4 y);
ulong4 __ovld __cnfn hadd(ulong4 x, ulong4 y);
long8 __ovld __cnfn hadd(long8 x, long8 y);
ulong8 __ovld __cnfn hadd(ulong8 x, ulong8 y);
long16 __ovld __cnfn hadd(long16 x, long16 y);
ulong16 __ovld __cnfn hadd(ulong16 x, ulong16 y);

/**
 * Returns (x + y + 1) >> 1. The intermediate sum
 * does not modulo overflow.
 */
char __ovld __cnfn rhadd(char x, char y);
uchar __ovld __cnfn rhadd(uchar x, uchar y);
char2 __ovld __cnfn rhadd(char2 x, char2 y);
uchar2 __ovld __cnfn rhadd(uchar2 x, uchar2 y);
char3 __ovld __cnfn rhadd(char3 x, char3 y);
uchar3 __ovld __cnfn rhadd(uchar3 x, uchar3 y);
char4 __ovld __cnfn rhadd(char4 x, char4 y);
uchar4 __ovld __cnfn rhadd(uchar4 x, uchar4 y);
char8 __ovld __cnfn rhadd(char8 x, char8 y);
uchar8 __ovld __cnfn rhadd(uchar8 x, uchar8 y);
char16 __ovld __cnfn rhadd(char16 x, char16 y);
uchar16 __ovld __cnfn rhadd(uchar16 x, uchar16 y);
short __ovld __cnfn rhadd(short x, short y);
ushort __ovld __cnfn rhadd(ushort x, ushort y);
short2 __ovld __cnfn rhadd(short2 x, short2 y);
ushort2 __ovld __cnfn rhadd(ushort2 x, ushort2 y);
short3 __ovld __cnfn rhadd(short3 x, short3 y);
ushort3 __ovld __cnfn rhadd(ushort3 x, ushort3 y);
short4 __ovld __cnfn rhadd(short4 x, short4 y);
ushort4 __ovld __cnfn rhadd(ushort4 x, ushort4 y);
short8 __ovld __cnfn rhadd(short8 x, short8 y);
ushort8 __ovld __cnfn rhadd(ushort8 x, ushort8 y);
short16 __ovld __cnfn rhadd(short16 x, short16 y);
ushort16 __ovld __cnfn rhadd(ushort16 x, ushort16 y);
int __ovld __cnfn rhadd(int x, int y);
uint __ovld __cnfn rhadd(uint x, uint y);
int2 __ovld __cnfn rhadd(int2 x, int2 y);
uint2 __ovld __cnfn rhadd(uint2 x, uint2 y);
int3 __ovld __cnfn rhadd(int3 x, int3 y);
uint3 __ovld __cnfn rhadd(uint3 x, uint3 y);
int4 __ovld __cnfn rhadd(int4 x, int4 y);
uint4 __ovld __cnfn rhadd(uint4 x, uint4 y);
int8 __ovld __cnfn rhadd(int8 x, int8 y);
uint8 __ovld __cnfn rhadd(uint8 x, uint8 y);
int16 __ovld __cnfn rhadd(int16 x, int16 y);
uint16 __ovld __cnfn rhadd(uint16 x, uint16 y);
long __ovld __cnfn rhadd(long x, long y);
ulong __ovld __cnfn rhadd(ulong x, ulong y);
long2 __ovld __cnfn rhadd(long2 x, long2 y);
ulong2 __ovld __cnfn rhadd(ulong2 x, ulong2 y);
long3 __ovld __cnfn rhadd(long3 x, long3 y);
ulong3 __ovld __cnfn rhadd(ulong3 x, ulong3 y);
long4 __ovld __cnfn rhadd(long4 x, long4 y);
ulong4 __ovld __cnfn rhadd(ulong4 x, ulong4 y);
long8 __ovld __cnfn rhadd(long8 x, long8 y);
ulong8 __ovld __cnfn rhadd(ulong8 x, ulong8 y);
long16 __ovld __cnfn rhadd(long16 x, long16 y);
ulong16 __ovld __cnfn rhadd(ulong16 x, ulong16 y);

/**
 * Returns min(max(x, minval), maxval).
 * Results are undefined if minval > maxval.
 */
char __ovld __cnfn clamp(char x, char minval, char maxval);
uchar __ovld __cnfn clamp(uchar x, uchar minval, uchar maxval);
char2 __ovld __cnfn clamp(char2 x, char2 minval, char2 maxval);
uchar2 __ovld __cnfn clamp(uchar2 x, uchar2 minval, uchar2 maxval);
char3 __ovld __cnfn clamp(char3 x, char3 minval, char3 maxval);
uchar3 __ovld __cnfn clamp(uchar3 x, uchar3 minval, uchar3 maxval);
char4 __ovld __cnfn clamp(char4 x, char4 minval, char4 maxval);
uchar4 __ovld __cnfn clamp(uchar4 x, uchar4 minval, uchar4 maxval);
char8 __ovld __cnfn clamp(char8 x, char8 minval, char8 maxval);
uchar8 __ovld __cnfn clamp(uchar8 x, uchar8 minval, uchar8 maxval);
char16 __ovld __cnfn clamp(char16 x, char16 minval, char16 maxval);
uchar16 __ovld __cnfn clamp(uchar16 x, uchar16 minval, uchar16 maxval);
short __ovld __cnfn clamp(short x, short minval, short maxval);
ushort __ovld __cnfn clamp(ushort x, ushort minval, ushort maxval);
short2 __ovld __cnfn clamp(short2 x, short2 minval, short2 maxval);
ushort2 __ovld __cnfn clamp(ushort2 x, ushort2 minval, ushort2 maxval);
short3 __ovld __cnfn clamp(short3 x, short3 minval, short3 maxval);
ushort3 __ovld __cnfn clamp(ushort3 x, ushort3 minval, ushort3 maxval);
short4 __ovld __cnfn clamp(short4 x, short4 minval, short4 maxval);
ushort4 __ovld __cnfn clamp(ushort4 x, ushort4 minval, ushort4 maxval);
short8 __ovld __cnfn clamp(short8 x, short8 minval, short8 maxval);
ushort8 __ovld __cnfn clamp(ushort8 x, ushort8 minval, ushort8 maxval);
short16 __ovld __cnfn clamp(short16 x, short16 minval, short16 maxval);
ushort16 __ovld __cnfn clamp(ushort16 x, ushort16 minval, ushort16 maxval);
int __ovld __cnfn clamp(int x, int minval, int maxval);
uint __ovld __cnfn clamp(uint x, uint minval, uint maxval);
int2 __ovld __cnfn clamp(int2 x, int2 minval, int2 maxval);
uint2 __ovld __cnfn clamp(uint2 x, uint2 minval, uint2 maxval);
int3 __ovld __cnfn clamp(int3 x, int3 minval, int3 maxval);
uint3 __ovld __cnfn clamp(uint3 x, uint3 minval, uint3 maxval);
int4 __ovld __cnfn clamp(int4 x, int4 minval, int4 maxval);
uint4 __ovld __cnfn clamp(uint4 x, uint4 minval, uint4 maxval);
int8 __ovld __cnfn clamp(int8 x, int8 minval, int8 maxval);
uint8 __ovld __cnfn clamp(uint8 x, uint8 minval, uint8 maxval);
int16 __ovld __cnfn clamp(int16 x, int16 minval, int16 maxval);
uint16 __ovld __cnfn clamp(uint16 x, uint16 minval, uint16 maxval);
long __ovld __cnfn clamp(long x, long minval, long maxval);
ulong __ovld __cnfn clamp(ulong x, ulong minval, ulong maxval);
long2 __ovld __cnfn clamp(long2 x, long2 minval, long2 maxval);
ulong2 __ovld __cnfn clamp(ulong2 x, ulong2 minval, ulong2 maxval);
long3 __ovld __cnfn clamp(long3 x, long3 minval, long3 maxval);
ulong3 __ovld __cnfn clamp(ulong3 x, ulong3 minval, ulong3 maxval);
long4 __ovld __cnfn clamp(long4 x, long4 minval, long4 maxval);
ulong4 __ovld __cnfn clamp(ulong4 x, ulong4 minval, ulong4 maxval);
long8 __ovld __cnfn clamp(long8 x, long8 minval, long8 maxval);
ulong8 __ovld __cnfn clamp(ulong8 x, ulong8 minval, ulong8 maxval);
long16 __ovld __cnfn clamp(long16 x, long16 minval, long16 maxval);
ulong16 __ovld __cnfn clamp(ulong16 x, ulong16 minval, ulong16 maxval);
char __ovld __cnfn clamp(char x, char minval, char maxval);
uchar __ovld __cnfn clamp(uchar x, uchar minval, uchar maxval);
char2 __ovld __cnfn clamp(char2 x, char minval, char maxval);
uchar2 __ovld __cnfn clamp(uchar2 x, uchar minval, uchar maxval);
char3 __ovld __cnfn clamp(char3 x, char minval, char maxval);
uchar3 __ovld __cnfn clamp(uchar3 x, uchar minval, uchar maxval);
char4 __ovld __cnfn clamp(char4 x, char minval, char maxval);
uchar4 __ovld __cnfn clamp(uchar4 x, uchar minval, uchar maxval);
char8 __ovld __cnfn clamp(char8 x, char minval, char maxval);
uchar8 __ovld __cnfn clamp(uchar8 x, uchar minval, uchar maxval);
char16 __ovld __cnfn clamp(char16 x, char minval, char maxval);
uchar16 __ovld __cnfn clamp(uchar16 x, uchar minval, uchar maxval);
short __ovld __cnfn clamp(short x, short minval, short maxval);
ushort __ovld __cnfn clamp(ushort x, ushort minval, ushort maxval);
short2 __ovld __cnfn clamp(short2 x, short minval, short maxval);
ushort2 __ovld __cnfn clamp(ushort2 x, ushort minval, ushort maxval);
short3 __ovld __cnfn clamp(short3 x, short minval, short maxval);
ushort3 __ovld __cnfn clamp(ushort3 x, ushort minval, ushort maxval);
short4 __ovld __cnfn clamp(short4 x, short minval, short maxval);
ushort4 __ovld __cnfn clamp(ushort4 x, ushort minval, ushort maxval);
short8 __ovld __cnfn clamp(short8 x, short minval, short maxval);
ushort8 __ovld __cnfn clamp(ushort8 x, ushort minval, ushort maxval);
short16 __ovld __cnfn clamp(short16 x, short minval, short maxval);
ushort16 __ovld __cnfn clamp(ushort16 x, ushort minval, ushort maxval);
int __ovld __cnfn clamp(int x, int minval, int maxval);
uint __ovld __cnfn clamp(uint x, uint minval, uint maxval);
int2 __ovld __cnfn clamp(int2 x, int minval, int maxval);
uint2 __ovld __cnfn clamp(uint2 x, uint minval, uint maxval);
int3 __ovld __cnfn clamp(int3 x, int minval, int maxval);
uint3 __ovld __cnfn clamp(uint3 x, uint minval, uint maxval);
int4 __ovld __cnfn clamp(int4 x, int minval, int maxval);
uint4 __ovld __cnfn clamp(uint4 x, uint minval, uint maxval);
int8 __ovld __cnfn clamp(int8 x, int minval, int maxval);
uint8 __ovld __cnfn clamp(uint8 x, uint minval, uint maxval);
int16 __ovld __cnfn clamp(int16 x, int minval, int maxval);
uint16 __ovld __cnfn clamp(uint16 x, uint minval, uint maxval);
long __ovld __cnfn clamp(long x, long minval, long maxval);
ulong __ovld __cnfn clamp(ulong x, ulong minval, ulong maxval);
long2 __ovld __cnfn clamp(long2 x, long minval, long maxval);
ulong2 __ovld __cnfn clamp(ulong2 x, ulong minval, ulong maxval);
long3 __ovld __cnfn clamp(long3 x, long minval, long maxval);
ulong3 __ovld __cnfn clamp(ulong3 x, ulong minval, ulong maxval);
long4 __ovld __cnfn clamp(long4 x, long minval, long maxval);
ulong4 __ovld __cnfn clamp(ulong4 x, ulong minval, ulong maxval);
long8 __ovld __cnfn clamp(long8 x, long minval, long maxval);
ulong8 __ovld __cnfn clamp(ulong8 x, ulong minval, ulong maxval);
long16 __ovld __cnfn clamp(long16 x, long minval, long maxval);
ulong16 __ovld __cnfn clamp(ulong16 x, ulong minval, ulong maxval);

/**
 * Returns the number of leading 0-bits in x, starting
 * at the most significant bit position.
 */
char __ovld __cnfn clz(char x);
uchar __ovld __cnfn clz(uchar x);
char2 __ovld __cnfn clz(char2 x);
uchar2 __ovld __cnfn clz(uchar2 x);
char3 __ovld __cnfn clz(char3 x);
uchar3 __ovld __cnfn clz(uchar3 x);
char4 __ovld __cnfn clz(char4 x);
uchar4 __ovld __cnfn clz(uchar4 x);
char8 __ovld __cnfn clz(char8 x);
uchar8 __ovld __cnfn clz(uchar8 x);
char16 __ovld __cnfn clz(char16 x);
uchar16 __ovld __cnfn clz(uchar16 x);
short __ovld __cnfn clz(short x);
ushort __ovld __cnfn clz(ushort x);
short2 __ovld __cnfn clz(short2 x);
ushort2 __ovld __cnfn clz(ushort2 x);
short3 __ovld __cnfn clz(short3 x);
ushort3 __ovld __cnfn clz(ushort3 x);
short4 __ovld __cnfn clz(short4 x);
ushort4 __ovld __cnfn clz(ushort4 x);
short8 __ovld __cnfn clz(short8 x);
ushort8 __ovld __cnfn clz(ushort8 x);
short16 __ovld __cnfn clz(short16 x);
ushort16 __ovld __cnfn clz(ushort16 x);
int __ovld __cnfn clz(int x);
uint __ovld __cnfn clz(uint x);
int2 __ovld __cnfn clz(int2 x);
uint2 __ovld __cnfn clz(uint2 x);
int3 __ovld __cnfn clz(int3 x);
uint3 __ovld __cnfn clz(uint3 x);
int4 __ovld __cnfn clz(int4 x);
uint4 __ovld __cnfn clz(uint4 x);
int8 __ovld __cnfn clz(int8 x);
uint8 __ovld __cnfn clz(uint8 x);
int16 __ovld __cnfn clz(int16 x);
uint16 __ovld __cnfn clz(uint16 x);
long __ovld __cnfn clz(long x);
ulong __ovld __cnfn clz(ulong x);
long2 __ovld __cnfn clz(long2 x);
ulong2 __ovld __cnfn clz(ulong2 x);
long3 __ovld __cnfn clz(long3 x);
ulong3 __ovld __cnfn clz(ulong3 x);
long4 __ovld __cnfn clz(long4 x);
ulong4 __ovld __cnfn clz(ulong4 x);
long8 __ovld __cnfn clz(long8 x);
ulong8 __ovld __cnfn clz(ulong8 x);
long16 __ovld __cnfn clz(long16 x);
ulong16 __ovld __cnfn clz(ulong16 x);

/**
 * Returns mul_hi(a, b) + c.
 */
char __ovld __cnfn mad_hi(char a, char b, char c);
uchar __ovld __cnfn mad_hi(uchar a, uchar b, uchar c);
char2 __ovld __cnfn mad_hi(char2 a, char2 b, char2 c);
uchar2 __ovld __cnfn mad_hi(uchar2 a, uchar2 b, uchar2 c);
char3 __ovld __cnfn mad_hi(char3 a, char3 b, char3 c);
uchar3 __ovld __cnfn mad_hi(uchar3 a, uchar3 b, uchar3 c);
char4 __ovld __cnfn mad_hi(char4 a, char4 b, char4 c);
uchar4 __ovld __cnfn mad_hi(uchar4 a, uchar4 b, uchar4 c);
char8 __ovld __cnfn mad_hi(char8 a, char8 b, char8 c);
uchar8 __ovld __cnfn mad_hi(uchar8 a, uchar8 b, uchar8 c);
char16 __ovld __cnfn mad_hi(char16 a, char16 b, char16 c);
uchar16 __ovld __cnfn mad_hi(uchar16 a, uchar16 b, uchar16 c);
short __ovld __cnfn mad_hi(short a, short b, short c);
ushort __ovld __cnfn mad_hi(ushort a, ushort b, ushort c);
short2 __ovld __cnfn mad_hi(short2 a, short2 b, short2 c);
ushort2 __ovld __cnfn mad_hi(ushort2 a, ushort2 b, ushort2 c);
short3 __ovld __cnfn mad_hi(short3 a, short3 b, short3 c);
ushort3 __ovld __cnfn mad_hi(ushort3 a, ushort3 b, ushort3 c);
short4 __ovld __cnfn mad_hi(short4 a, short4 b, short4 c);
ushort4 __ovld __cnfn mad_hi(ushort4 a, ushort4 b, ushort4 c);
short8 __ovld __cnfn mad_hi(short8 a, short8 b, short8 c);
ushort8 __ovld __cnfn mad_hi(ushort8 a, ushort8 b, ushort8 c);
short16 __ovld __cnfn mad_hi(short16 a, short16 b, short16 c);
ushort16 __ovld __cnfn mad_hi(ushort16 a, ushort16 b, ushort16 c);
int __ovld __cnfn mad_hi(int a, int b, int c);
uint __ovld __cnfn mad_hi(uint a, uint b, uint c);
int2 __ovld __cnfn mad_hi(int2 a, int2 b, int2 c);
uint2 __ovld __cnfn mad_hi(uint2 a, uint2 b, uint2 c);
int3 __ovld __cnfn mad_hi(int3 a, int3 b, int3 c);
uint3 __ovld __cnfn mad_hi(uint3 a, uint3 b, uint3 c);
int4 __ovld __cnfn mad_hi(int4 a, int4 b, int4 c);
uint4 __ovld __cnfn mad_hi(uint4 a, uint4 b, uint4 c);
int8 __ovld __cnfn mad_hi(int8 a, int8 b, int8 c);
uint8 __ovld __cnfn mad_hi(uint8 a, uint8 b, uint8 c);
int16 __ovld __cnfn mad_hi(int16 a, int16 b, int16 c);
uint16 __ovld __cnfn mad_hi(uint16 a, uint16 b, uint16 c);
long __ovld __cnfn mad_hi(long a, long b, long c);
ulong __ovld __cnfn mad_hi(ulong a, ulong b, ulong c);
long2 __ovld __cnfn mad_hi(long2 a, long2 b, long2 c);
ulong2 __ovld __cnfn mad_hi(ulong2 a, ulong2 b, ulong2 c);
long3 __ovld __cnfn mad_hi(long3 a, long3 b, long3 c);
ulong3 __ovld __cnfn mad_hi(ulong3 a, ulong3 b, ulong3 c);
long4 __ovld __cnfn mad_hi(long4 a, long4 b, long4 c);
ulong4 __ovld __cnfn mad_hi(ulong4 a, ulong4 b, ulong4 c);
long8 __ovld __cnfn mad_hi(long8 a, long8 b, long8 c);
ulong8 __ovld __cnfn mad_hi(ulong8 a, ulong8 b, ulong8 c);
long16 __ovld __cnfn mad_hi(long16 a, long16 b, long16 c);
ulong16 __ovld __cnfn mad_hi(ulong16 a, ulong16 b, ulong16 c);

/**
 * Returns a * b + c and saturates the result.
 */
char __ovld __cnfn mad_sat(char a, char b, char c);
uchar __ovld __cnfn mad_sat(uchar a, uchar b, uchar c);
char2 __ovld __cnfn mad_sat(char2 a, char2 b, char2 c);
uchar2 __ovld __cnfn mad_sat(uchar2 a, uchar2 b, uchar2 c);
char3 __ovld __cnfn mad_sat(char3 a, char3 b, char3 c);
uchar3 __ovld __cnfn mad_sat(uchar3 a, uchar3 b, uchar3 c);
char4 __ovld __cnfn mad_sat(char4 a, char4 b, char4 c);
uchar4 __ovld __cnfn mad_sat(uchar4 a, uchar4 b, uchar4 c);
char8 __ovld __cnfn mad_sat(char8 a, char8 b, char8 c);
uchar8 __ovld __cnfn mad_sat(uchar8 a, uchar8 b, uchar8 c);
char16 __ovld __cnfn mad_sat(char16 a, char16 b, char16 c);
uchar16 __ovld __cnfn mad_sat(uchar16 a, uchar16 b, uchar16 c);
short __ovld __cnfn mad_sat(short a, short b, short c);
ushort __ovld __cnfn mad_sat(ushort a, ushort b, ushort c);
short2 __ovld __cnfn mad_sat(short2 a, short2 b, short2 c);
ushort2 __ovld __cnfn mad_sat(ushort2 a, ushort2 b, ushort2 c);
short3 __ovld __cnfn mad_sat(short3 a, short3 b, short3 c);
ushort3 __ovld __cnfn mad_sat(ushort3 a, ushort3 b, ushort3 c);
short4 __ovld __cnfn mad_sat(short4 a, short4 b, short4 c);
ushort4 __ovld __cnfn mad_sat(ushort4 a, ushort4 b, ushort4 c);
short8 __ovld __cnfn mad_sat(short8 a, short8 b, short8 c);
ushort8 __ovld __cnfn mad_sat(ushort8 a, ushort8 b, ushort8 c);
short16 __ovld __cnfn mad_sat(short16 a, short16 b, short16 c);
ushort16 __ovld __cnfn mad_sat(ushort16 a, ushort16 b, ushort16 c);
int __ovld __cnfn mad_sat(int a, int b, int c);
uint __ovld __cnfn mad_sat(uint a, uint b, uint c);
int2 __ovld __cnfn mad_sat(int2 a, int2 b, int2 c);
uint2 __ovld __cnfn mad_sat(uint2 a, uint2 b, uint2 c);
int3 __ovld __cnfn mad_sat(int3 a, int3 b, int3 c);
uint3 __ovld __cnfn mad_sat(uint3 a, uint3 b, uint3 c);
int4 __ovld __cnfn mad_sat(int4 a, int4 b, int4 c);
uint4 __ovld __cnfn mad_sat(uint4 a, uint4 b, uint4 c);
int8 __ovld __cnfn mad_sat(int8 a, int8 b, int8 c);
uint8 __ovld __cnfn mad_sat(uint8 a, uint8 b, uint8 c);
int16 __ovld __cnfn mad_sat(int16 a, int16 b, int16 c);
uint16 __ovld __cnfn mad_sat(uint16 a, uint16 b, uint16 c);
long __ovld __cnfn mad_sat(long a, long b, long c);
ulong __ovld __cnfn mad_sat(ulong a, ulong b, ulong c);
long2 __ovld __cnfn mad_sat(long2 a, long2 b, long2 c);
ulong2 __ovld __cnfn mad_sat(ulong2 a, ulong2 b, ulong2 c);
long3 __ovld __cnfn mad_sat(long3 a, long3 b, long3 c);
ulong3 __ovld __cnfn mad_sat(ulong3 a, ulong3 b, ulong3 c);
long4 __ovld __cnfn mad_sat(long4 a, long4 b, long4 c);
ulong4 __ovld __cnfn mad_sat(ulong4 a, ulong4 b, ulong4 c);
long8 __ovld __cnfn mad_sat(long8 a, long8 b, long8 c);
ulong8 __ovld __cnfn mad_sat(ulong8 a, ulong8 b, ulong8 c);
long16 __ovld __cnfn mad_sat(long16 a, long16 b, long16 c);
ulong16 __ovld __cnfn mad_sat(ulong16 a, ulong16 b, ulong16 c);

/**
 * Returns y if x < y, otherwise it returns x.
 */
char __ovld __cnfn max(char x, char y);
uchar __ovld __cnfn max(uchar x, uchar y);
char2 __ovld __cnfn max(char2 x, char2 y);
uchar2 __ovld __cnfn max(uchar2 x, uchar2 y);
char3 __ovld __cnfn max(char3 x, char3 y);
uchar3 __ovld __cnfn max(uchar3 x, uchar3 y);
char4 __ovld __cnfn max(char4 x, char4 y);
uchar4 __ovld __cnfn max(uchar4 x, uchar4 y);
char8 __ovld __cnfn max(char8 x, char8 y);
uchar8 __ovld __cnfn max(uchar8 x, uchar8 y);
char16 __ovld __cnfn max(char16 x, char16 y);
uchar16 __ovld __cnfn max(uchar16 x, uchar16 y);
short __ovld __cnfn max(short x, short y);
ushort __ovld __cnfn max(ushort x, ushort y);
short2 __ovld __cnfn max(short2 x, short2 y);
ushort2 __ovld __cnfn max(ushort2 x, ushort2 y);
short3 __ovld __cnfn max(short3 x, short3 y);
ushort3 __ovld __cnfn max(ushort3 x, ushort3 y);
short4 __ovld __cnfn max(short4 x, short4 y);
ushort4 __ovld __cnfn max(ushort4 x, ushort4 y);
short8 __ovld __cnfn max(short8 x, short8 y);
ushort8 __ovld __cnfn max(ushort8 x, ushort8 y);
short16 __ovld __cnfn max(short16 x, short16 y);
ushort16 __ovld __cnfn max(ushort16 x, ushort16 y);
int __ovld __cnfn max(int x, int y);
uint __ovld __cnfn max(uint x, uint y);
int2 __ovld __cnfn max(int2 x, int2 y);
uint2 __ovld __cnfn max(uint2 x, uint2 y);
int3 __ovld __cnfn max(int3 x, int3 y);
uint3 __ovld __cnfn max(uint3 x, uint3 y);
int4 __ovld __cnfn max(int4 x, int4 y);
uint4 __ovld __cnfn max(uint4 x, uint4 y);
int8 __ovld __cnfn max(int8 x, int8 y);
uint8 __ovld __cnfn max(uint8 x, uint8 y);
int16 __ovld __cnfn max(int16 x, int16 y);
uint16 __ovld __cnfn max(uint16 x, uint16 y);
long __ovld __cnfn max(long x, long y);
ulong __ovld __cnfn max(ulong x, ulong y);
long2 __ovld __cnfn max(long2 x, long2 y);
ulong2 __ovld __cnfn max(ulong2 x, ulong2 y);
long3 __ovld __cnfn max(long3 x, long3 y);
ulong3 __ovld __cnfn max(ulong3 x, ulong3 y);
long4 __ovld __cnfn max(long4 x, long4 y);
ulong4 __ovld __cnfn max(ulong4 x, ulong4 y);
long8 __ovld __cnfn max(long8 x, long8 y);
ulong8 __ovld __cnfn max(ulong8 x, ulong8 y);
long16 __ovld __cnfn max(long16 x, long16 y);
ulong16 __ovld __cnfn max(ulong16 x, ulong16 y);
char __ovld __cnfn max(char x, char y);
uchar __ovld __cnfn max(uchar x, uchar y);
char2 __ovld __cnfn max(char2 x, char y);
uchar2 __ovld __cnfn max(uchar2 x, uchar y);
char3 __ovld __cnfn max(char3 x, char y);
uchar3 __ovld __cnfn max(uchar3 x, uchar y);
char4 __ovld __cnfn max(char4 x, char y);
uchar4 __ovld __cnfn max(uchar4 x, uchar y);
char8 __ovld __cnfn max(char8 x, char y);
uchar8 __ovld __cnfn max(uchar8 x, uchar y);
char16 __ovld __cnfn max(char16 x, char y);
uchar16 __ovld __cnfn max(uchar16 x, uchar y);
short __ovld __cnfn max(short x, short y);
ushort __ovld __cnfn max(ushort x, ushort y);
short2 __ovld __cnfn max(short2 x, short y);
ushort2 __ovld __cnfn max(ushort2 x, ushort y);
short3 __ovld __cnfn max(short3 x, short y);
ushort3 __ovld __cnfn max(ushort3 x, ushort y);
short4 __ovld __cnfn max(short4 x, short y);
ushort4 __ovld __cnfn max(ushort4 x, ushort y);
short8 __ovld __cnfn max(short8 x, short y);
ushort8 __ovld __cnfn max(ushort8 x, ushort y);
short16 __ovld __cnfn max(short16 x, short y);
ushort16 __ovld __cnfn max(ushort16 x, ushort y);
int __ovld __cnfn max(int x, int y);
uint __ovld __cnfn max(uint x, uint y);
int2 __ovld __cnfn max(int2 x, int y);
uint2 __ovld __cnfn max(uint2 x, uint y);
int3 __ovld __cnfn max(int3 x, int y);
uint3 __ovld __cnfn max(uint3 x, uint y);
int4 __ovld __cnfn max(int4 x, int y);
uint4 __ovld __cnfn max(uint4 x, uint y);
int8 __ovld __cnfn max(int8 x, int y);
uint8 __ovld __cnfn max(uint8 x, uint y);
int16 __ovld __cnfn max(int16 x, int y);
uint16 __ovld __cnfn max(uint16 x, uint y);
long __ovld __cnfn max(long x, long y);
ulong __ovld __cnfn max(ulong x, ulong y);
long2 __ovld __cnfn max(long2 x, long y);
ulong2 __ovld __cnfn max(ulong2 x, ulong y);
long3 __ovld __cnfn max(long3 x, long y);
ulong3 __ovld __cnfn max(ulong3 x, ulong y);
long4 __ovld __cnfn max(long4 x, long y);
ulong4 __ovld __cnfn max(ulong4 x, ulong y);
long8 __ovld __cnfn max(long8 x, long y);
ulong8 __ovld __cnfn max(ulong8 x, ulong y);
long16 __ovld __cnfn max(long16 x, long y);
ulong16 __ovld __cnfn max(ulong16 x, ulong y);

/**
 * Returns y if y < x, otherwise it returns x.
 */
char __ovld __cnfn min(char x, char y);
uchar __ovld __cnfn min(uchar x, uchar y);
char2 __ovld __cnfn min(char2 x, char2 y);
uchar2 __ovld __cnfn min(uchar2 x, uchar2 y);
char3 __ovld __cnfn min(char3 x, char3 y);
uchar3 __ovld __cnfn min(uchar3 x, uchar3 y);
char4 __ovld __cnfn min(char4 x, char4 y);
uchar4 __ovld __cnfn min(uchar4 x, uchar4 y);
char8 __ovld __cnfn min(char8 x, char8 y);
uchar8 __ovld __cnfn min(uchar8 x, uchar8 y);
char16 __ovld __cnfn min(char16 x, char16 y);
uchar16 __ovld __cnfn min(uchar16 x, uchar16 y);
short __ovld __cnfn min(short x, short y);
ushort __ovld __cnfn min(ushort x, ushort y);
short2 __ovld __cnfn min(short2 x, short2 y);
ushort2 __ovld __cnfn min(ushort2 x, ushort2 y);
short3 __ovld __cnfn min(short3 x, short3 y);
ushort3 __ovld __cnfn min(ushort3 x, ushort3 y);
short4 __ovld __cnfn min(short4 x, short4 y);
ushort4 __ovld __cnfn min(ushort4 x, ushort4 y);
short8 __ovld __cnfn min(short8 x, short8 y);
ushort8 __ovld __cnfn min(ushort8 x, ushort8 y);
short16 __ovld __cnfn min(short16 x, short16 y);
ushort16 __ovld __cnfn min(ushort16 x, ushort16 y);
int __ovld __cnfn min(int x, int y);
uint __ovld __cnfn min(uint x, uint y);
int2 __ovld __cnfn min(int2 x, int2 y);
uint2 __ovld __cnfn min(uint2 x, uint2 y);
int3 __ovld __cnfn min(int3 x, int3 y);
uint3 __ovld __cnfn min(uint3 x, uint3 y);
int4 __ovld __cnfn min(int4 x, int4 y);
uint4 __ovld __cnfn min(uint4 x, uint4 y);
int8 __ovld __cnfn min(int8 x, int8 y);
uint8 __ovld __cnfn min(uint8 x, uint8 y);
int16 __ovld __cnfn min(int16 x, int16 y);
uint16 __ovld __cnfn min(uint16 x, uint16 y);
long __ovld __cnfn min(long x, long y);
ulong __ovld __cnfn min(ulong x, ulong y);
long2 __ovld __cnfn min(long2 x, long2 y);
ulong2 __ovld __cnfn min(ulong2 x, ulong2 y);
long3 __ovld __cnfn min(long3 x, long3 y);
ulong3 __ovld __cnfn min(ulong3 x, ulong3 y);
long4 __ovld __cnfn min(long4 x, long4 y);
ulong4 __ovld __cnfn min(ulong4 x, ulong4 y);
long8 __ovld __cnfn min(long8 x, long8 y);
ulong8 __ovld __cnfn min(ulong8 x, ulong8 y);
long16 __ovld __cnfn min(long16 x, long16 y);
ulong16 __ovld __cnfn min(ulong16 x, ulong16 y);
char __ovld __cnfn min(char x, char y);
uchar __ovld __cnfn min(uchar x, uchar y);
char2 __ovld __cnfn min(char2 x, char y);
uchar2 __ovld __cnfn min(uchar2 x, uchar y);
char3 __ovld __cnfn min(char3 x, char y);
uchar3 __ovld __cnfn min(uchar3 x, uchar y);
char4 __ovld __cnfn min(char4 x, char y);
uchar4 __ovld __cnfn min(uchar4 x, uchar y);
char8 __ovld __cnfn min(char8 x, char y);
uchar8 __ovld __cnfn min(uchar8 x, uchar y);
char16 __ovld __cnfn min(char16 x, char y);
uchar16 __ovld __cnfn min(uchar16 x, uchar y);
short __ovld __cnfn min(short x, short y);
ushort __ovld __cnfn min(ushort x, ushort y);
short2 __ovld __cnfn min(short2 x, short y);
ushort2 __ovld __cnfn min(ushort2 x, ushort y);
short3 __ovld __cnfn min(short3 x, short y);
ushort3 __ovld __cnfn min(ushort3 x, ushort y);
short4 __ovld __cnfn min(short4 x, short y);
ushort4 __ovld __cnfn min(ushort4 x, ushort y);
short8 __ovld __cnfn min(short8 x, short y);
ushort8 __ovld __cnfn min(ushort8 x, ushort y);
short16 __ovld __cnfn min(short16 x, short y);
ushort16 __ovld __cnfn min(ushort16 x, ushort y);
int __ovld __cnfn min(int x, int y);
uint __ovld __cnfn min(uint x, uint y);
int2 __ovld __cnfn min(int2 x, int y);
uint2 __ovld __cnfn min(uint2 x, uint y);
int3 __ovld __cnfn min(int3 x, int y);
uint3 __ovld __cnfn min(uint3 x, uint y);
int4 __ovld __cnfn min(int4 x, int y);
uint4 __ovld __cnfn min(uint4 x, uint y);
int8 __ovld __cnfn min(int8 x, int y);
uint8 __ovld __cnfn min(uint8 x, uint y);
int16 __ovld __cnfn min(int16 x, int y);
uint16 __ovld __cnfn min(uint16 x, uint y);
long __ovld __cnfn min(long x, long y);
ulong __ovld __cnfn min(ulong x, ulong y);
long2 __ovld __cnfn min(long2 x, long y);
ulong2 __ovld __cnfn min(ulong2 x, ulong y);
long3 __ovld __cnfn min(long3 x, long y);
ulong3 __ovld __cnfn min(ulong3 x, ulong y);
long4 __ovld __cnfn min(long4 x, long y);
ulong4 __ovld __cnfn min(ulong4 x, ulong y);
long8 __ovld __cnfn min(long8 x, long y);
ulong8 __ovld __cnfn min(ulong8 x, ulong y);
long16 __ovld __cnfn min(long16 x, long y);
ulong16 __ovld __cnfn min(ulong16 x, ulong y);

/**
 * Computes x * y and returns the high half of the
 * product of x and y.
 */
char __ovld __cnfn mul_hi(char x, char y);
uchar __ovld __cnfn mul_hi(uchar x, uchar y);
char2 __ovld __cnfn mul_hi(char2 x, char2 y);
uchar2 __ovld __cnfn mul_hi(uchar2 x, uchar2 y);
char3 __ovld __cnfn mul_hi(char3 x, char3 y);
uchar3 __ovld __cnfn mul_hi(uchar3 x, uchar3 y);
char4 __ovld __cnfn mul_hi(char4 x, char4 y);
uchar4 __ovld __cnfn mul_hi(uchar4 x, uchar4 y);
char8 __ovld __cnfn mul_hi(char8 x, char8 y);
uchar8 __ovld __cnfn mul_hi(uchar8 x, uchar8 y);
char16 __ovld __cnfn mul_hi(char16 x, char16 y);
uchar16 __ovld __cnfn mul_hi(uchar16 x, uchar16 y);
short __ovld __cnfn mul_hi(short x, short y);
ushort __ovld __cnfn mul_hi(ushort x, ushort y);
short2 __ovld __cnfn mul_hi(short2 x, short2 y);
ushort2 __ovld __cnfn mul_hi(ushort2 x, ushort2 y);
short3 __ovld __cnfn mul_hi(short3 x, short3 y);
ushort3 __ovld __cnfn mul_hi(ushort3 x, ushort3 y);
short4 __ovld __cnfn mul_hi(short4 x, short4 y);
ushort4 __ovld __cnfn mul_hi(ushort4 x, ushort4 y);
short8 __ovld __cnfn mul_hi(short8 x, short8 y);
ushort8 __ovld __cnfn mul_hi(ushort8 x, ushort8 y);
short16 __ovld __cnfn mul_hi(short16 x, short16 y);
ushort16 __ovld __cnfn mul_hi(ushort16 x, ushort16 y);
int __ovld __cnfn mul_hi(int x, int y);
uint __ovld __cnfn mul_hi(uint x, uint y);
int2 __ovld __cnfn mul_hi(int2 x, int2 y);
uint2 __ovld __cnfn mul_hi(uint2 x, uint2 y);
int3 __ovld __cnfn mul_hi(int3 x, int3 y);
uint3 __ovld __cnfn mul_hi(uint3 x, uint3 y);
int4 __ovld __cnfn mul_hi(int4 x, int4 y);
uint4 __ovld __cnfn mul_hi(uint4 x, uint4 y);
int8 __ovld __cnfn mul_hi(int8 x, int8 y);
uint8 __ovld __cnfn mul_hi(uint8 x, uint8 y);
int16 __ovld __cnfn mul_hi(int16 x, int16 y);
uint16 __ovld __cnfn mul_hi(uint16 x, uint16 y);
long __ovld __cnfn mul_hi(long x, long y);
ulong __ovld __cnfn mul_hi(ulong x, ulong y);
long2 __ovld __cnfn mul_hi(long2 x, long2 y);
ulong2 __ovld __cnfn mul_hi(ulong2 x, ulong2 y);
long3 __ovld __cnfn mul_hi(long3 x, long3 y);
ulong3 __ovld __cnfn mul_hi(ulong3 x, ulong3 y);
long4 __ovld __cnfn mul_hi(long4 x, long4 y);
ulong4 __ovld __cnfn mul_hi(ulong4 x, ulong4 y);
long8 __ovld __cnfn mul_hi(long8 x, long8 y);
ulong8 __ovld __cnfn mul_hi(ulong8 x, ulong8 y);
long16 __ovld __cnfn mul_hi(long16 x, long16 y);
ulong16 __ovld __cnfn mul_hi(ulong16 x, ulong16 y);

/**
 * For each element in v, the bits are shifted left by
 * the number of bits given by the corresponding
 * element in i (subject to usual shift modulo rules
 * described in section 6.3). Bits shifted off the left
 * side of the element are shifted back in from the
 * right.
 */
char __ovld __cnfn rotate(char v, char i);
uchar __ovld __cnfn rotate(uchar v, uchar i);
char2 __ovld __cnfn rotate(char2 v, char2 i);
uchar2 __ovld __cnfn rotate(uchar2 v, uchar2 i);
char3 __ovld __cnfn rotate(char3 v, char3 i);
uchar3 __ovld __cnfn rotate(uchar3 v, uchar3 i);
char4 __ovld __cnfn rotate(char4 v, char4 i);
uchar4 __ovld __cnfn rotate(uchar4 v, uchar4 i);
char8 __ovld __cnfn rotate(char8 v, char8 i);
uchar8 __ovld __cnfn rotate(uchar8 v, uchar8 i);
char16 __ovld __cnfn rotate(char16 v, char16 i);
uchar16 __ovld __cnfn rotate(uchar16 v, uchar16 i);
short __ovld __cnfn rotate(short v, short i);
ushort __ovld __cnfn rotate(ushort v, ushort i);
short2 __ovld __cnfn rotate(short2 v, short2 i);
ushort2 __ovld __cnfn rotate(ushort2 v, ushort2 i);
short3 __ovld __cnfn rotate(short3 v, short3 i);
ushort3 __ovld __cnfn rotate(ushort3 v, ushort3 i);
short4 __ovld __cnfn rotate(short4 v, short4 i);
ushort4 __ovld __cnfn rotate(ushort4 v, ushort4 i);
short8 __ovld __cnfn rotate(short8 v, short8 i);
ushort8 __ovld __cnfn rotate(ushort8 v, ushort8 i);
short16 __ovld __cnfn rotate(short16 v, short16 i);
ushort16 __ovld __cnfn rotate(ushort16 v, ushort16 i);
int __ovld __cnfn rotate(int v, int i);
uint __ovld __cnfn rotate(uint v, uint i);
int2 __ovld __cnfn rotate(int2 v, int2 i);
uint2 __ovld __cnfn rotate(uint2 v, uint2 i);
int3 __ovld __cnfn rotate(int3 v, int3 i);
uint3 __ovld __cnfn rotate(uint3 v, uint3 i);
int4 __ovld __cnfn rotate(int4 v, int4 i);
uint4 __ovld __cnfn rotate(uint4 v, uint4 i);
int8 __ovld __cnfn rotate(int8 v, int8 i);
uint8 __ovld __cnfn rotate(uint8 v, uint8 i);
int16 __ovld __cnfn rotate(int16 v, int16 i);
uint16 __ovld __cnfn rotate(uint16 v, uint16 i);
long __ovld __cnfn rotate(long v, long i);
ulong __ovld __cnfn rotate(ulong v, ulong i);
long2 __ovld __cnfn rotate(long2 v, long2 i);
ulong2 __ovld __cnfn rotate(ulong2 v, ulong2 i);
long3 __ovld __cnfn rotate(long3 v, long3 i);
ulong3 __ovld __cnfn rotate(ulong3 v, ulong3 i);
long4 __ovld __cnfn rotate(long4 v, long4 i);
ulong4 __ovld __cnfn rotate(ulong4 v, ulong4 i);
long8 __ovld __cnfn rotate(long8 v, long8 i);
ulong8 __ovld __cnfn rotate(ulong8 v, ulong8 i);
long16 __ovld __cnfn rotate(long16 v, long16 i);
ulong16 __ovld __cnfn rotate(ulong16 v, ulong16 i);

/**
 * Returns x - y and saturates the result.
 */
char __ovld __cnfn sub_sat(char x, char y);
uchar __ovld __cnfn sub_sat(uchar x, uchar y);
char2 __ovld __cnfn sub_sat(char2 x, char2 y);
uchar2 __ovld __cnfn sub_sat(uchar2 x, uchar2 y);
char3 __ovld __cnfn sub_sat(char3 x, char3 y);
uchar3 __ovld __cnfn sub_sat(uchar3 x, uchar3 y);
char4 __ovld __cnfn sub_sat(char4 x, char4 y);
uchar4 __ovld __cnfn sub_sat(uchar4 x, uchar4 y);
char8 __ovld __cnfn sub_sat(char8 x, char8 y);
uchar8 __ovld __cnfn sub_sat(uchar8 x, uchar8 y);
char16 __ovld __cnfn sub_sat(char16 x, char16 y);
uchar16 __ovld __cnfn sub_sat(uchar16 x, uchar16 y);
short __ovld __cnfn sub_sat(short x, short y);
ushort __ovld __cnfn sub_sat(ushort x, ushort y);
short2 __ovld __cnfn sub_sat(short2 x, short2 y);
ushort2 __ovld __cnfn sub_sat(ushort2 x, ushort2 y);
short3 __ovld __cnfn sub_sat(short3 x, short3 y);
ushort3 __ovld __cnfn sub_sat(ushort3 x, ushort3 y);
short4 __ovld __cnfn sub_sat(short4 x, short4 y);
ushort4 __ovld __cnfn sub_sat(ushort4 x, ushort4 y);
short8 __ovld __cnfn sub_sat(short8 x, short8 y);
ushort8 __ovld __cnfn sub_sat(ushort8 x, ushort8 y);
short16 __ovld __cnfn sub_sat(short16 x, short16 y);
ushort16 __ovld __cnfn sub_sat(ushort16 x, ushort16 y);
int __ovld __cnfn sub_sat(int x, int y);
uint __ovld __cnfn sub_sat(uint x, uint y);
int2 __ovld __cnfn sub_sat(int2 x, int2 y);
uint2 __ovld __cnfn sub_sat(uint2 x, uint2 y);
int3 __ovld __cnfn sub_sat(int3 x, int3 y);
uint3 __ovld __cnfn sub_sat(uint3 x, uint3 y);
int4 __ovld __cnfn sub_sat(int4 x, int4 y);
uint4 __ovld __cnfn sub_sat(uint4 x, uint4 y);
int8 __ovld __cnfn sub_sat(int8 x, int8 y);
uint8 __ovld __cnfn sub_sat(uint8 x, uint8 y);
int16 __ovld __cnfn sub_sat(int16 x, int16 y);
uint16 __ovld __cnfn sub_sat(uint16 x, uint16 y);
long __ovld __cnfn sub_sat(long x, long y);
ulong __ovld __cnfn sub_sat(ulong x, ulong y);
long2 __ovld __cnfn sub_sat(long2 x, long2 y);
ulong2 __ovld __cnfn sub_sat(ulong2 x, ulong2 y);
long3 __ovld __cnfn sub_sat(long3 x, long3 y);
ulong3 __ovld __cnfn sub_sat(ulong3 x, ulong3 y);
long4 __ovld __cnfn sub_sat(long4 x, long4 y);
ulong4 __ovld __cnfn sub_sat(ulong4 x, ulong4 y);
long8 __ovld __cnfn sub_sat(long8 x, long8 y);
ulong8 __ovld __cnfn sub_sat(ulong8 x, ulong8 y);
long16 __ovld __cnfn sub_sat(long16 x, long16 y);
ulong16 __ovld __cnfn sub_sat(ulong16 x, ulong16 y);

/**
 * result[i] = ((short)hi[i] << 8) | lo[i]
 * result[i] = ((ushort)hi[i] << 8) | lo[i]
 */
short __ovld __cnfn upsample(char hi, uchar lo);
ushort __ovld __cnfn upsample(uchar hi, uchar lo);
short2 __ovld __cnfn upsample(char2 hi, uchar2 lo);
short3 __ovld __cnfn upsample(char3 hi, uchar3 lo);
short4 __ovld __cnfn upsample(char4 hi, uchar4 lo);
short8 __ovld __cnfn upsample(char8 hi, uchar8 lo);
short16 __ovld __cnfn upsample(char16 hi, uchar16 lo);
ushort2 __ovld __cnfn upsample(uchar2 hi, uchar2 lo);
ushort3 __ovld __cnfn upsample(uchar3 hi, uchar3 lo);
ushort4 __ovld __cnfn upsample(uchar4 hi, uchar4 lo);
ushort8 __ovld __cnfn upsample(uchar8 hi, uchar8 lo);
ushort16 __ovld __cnfn upsample(uchar16 hi, uchar16 lo);

/**
 * result[i] = ((int)hi[i] << 16) | lo[i]
 * result[i] = ((uint)hi[i] << 16) | lo[i]
 */
int __ovld __cnfn upsample(short hi, ushort lo);
uint __ovld __cnfn upsample(ushort hi, ushort lo);
int2 __ovld __cnfn upsample(short2 hi, ushort2 lo);
int3 __ovld __cnfn upsample(short3 hi, ushort3 lo);
int4 __ovld __cnfn upsample(short4 hi, ushort4 lo);
int8 __ovld __cnfn upsample(short8 hi, ushort8 lo);
int16 __ovld __cnfn upsample(short16 hi, ushort16 lo);
uint2 __ovld __cnfn upsample(ushort2 hi, ushort2 lo);
uint3 __ovld __cnfn upsample(ushort3 hi, ushort3 lo);
uint4 __ovld __cnfn upsample(ushort4 hi, ushort4 lo);
uint8 __ovld __cnfn upsample(ushort8 hi, ushort8 lo);
uint16 __ovld __cnfn upsample(ushort16 hi, ushort16 lo);
/**
 * result[i] = ((long)hi[i] << 32) | lo[i]
 * result[i] = ((ulong)hi[i] << 32) | lo[i]
 */
long __ovld __cnfn upsample(int hi, uint lo);
ulong __ovld __cnfn upsample(uint hi, uint lo);
long2 __ovld __cnfn upsample(int2 hi, uint2 lo);
long3 __ovld __cnfn upsample(int3 hi, uint3 lo);
long4 __ovld __cnfn upsample(int4 hi, uint4 lo);
long8 __ovld __cnfn upsample(int8 hi, uint8 lo);
long16 __ovld __cnfn upsample(int16 hi, uint16 lo);
ulong2 __ovld __cnfn upsample(uint2 hi, uint2 lo);
ulong3 __ovld __cnfn upsample(uint3 hi, uint3 lo);
ulong4 __ovld __cnfn upsample(uint4 hi, uint4 lo);
ulong8 __ovld __cnfn upsample(uint8 hi, uint8 lo);
ulong16 __ovld __cnfn upsample(uint16 hi, uint16 lo);

/*
 * popcount(x): returns the number of set bit in x
 */
char __ovld __cnfn popcount(char x);
uchar __ovld __cnfn popcount(uchar x);
char2 __ovld __cnfn popcount(char2 x);
uchar2 __ovld __cnfn popcount(uchar2 x);
char3 __ovld __cnfn popcount(char3 x);
uchar3 __ovld __cnfn popcount(uchar3 x);
char4 __ovld __cnfn popcount(char4 x);
uchar4 __ovld __cnfn popcount(uchar4 x);
char8 __ovld __cnfn popcount(char8 x);
uchar8 __ovld __cnfn popcount(uchar8 x);
char16 __ovld __cnfn popcount(char16 x);
uchar16 __ovld __cnfn popcount(uchar16 x);
short __ovld __cnfn popcount(short x);
ushort __ovld __cnfn popcount(ushort x);
short2 __ovld __cnfn popcount(short2 x);
ushort2 __ovld __cnfn popcount(ushort2 x);
short3 __ovld __cnfn popcount(short3 x);
ushort3 __ovld __cnfn popcount(ushort3 x);
short4 __ovld __cnfn popcount(short4 x);
ushort4 __ovld __cnfn popcount(ushort4 x);
short8 __ovld __cnfn popcount(short8 x);
ushort8 __ovld __cnfn popcount(ushort8 x);
short16 __ovld __cnfn popcount(short16 x);
ushort16 __ovld __cnfn popcount(ushort16 x);
int __ovld __cnfn popcount(int x);
uint __ovld __cnfn popcount(uint x);
int2 __ovld __cnfn popcount(int2 x);
uint2 __ovld __cnfn popcount(uint2 x);
int3 __ovld __cnfn popcount(int3 x);
uint3 __ovld __cnfn popcount(uint3 x);
int4 __ovld __cnfn popcount(int4 x);
uint4 __ovld __cnfn popcount(uint4 x);
int8 __ovld __cnfn popcount(int8 x);
uint8 __ovld __cnfn popcount(uint8 x);
int16 __ovld __cnfn popcount(int16 x);
uint16 __ovld __cnfn popcount(uint16 x);
long __ovld __cnfn popcount(long x);
ulong __ovld __cnfn popcount(ulong x);
long2 __ovld __cnfn popcount(long2 x);
ulong2 __ovld __cnfn popcount(ulong2 x);
long3 __ovld __cnfn popcount(long3 x);
ulong3 __ovld __cnfn popcount(ulong3 x);
long4 __ovld __cnfn popcount(long4 x);
ulong4 __ovld __cnfn popcount(ulong4 x);
long8 __ovld __cnfn popcount(long8 x);
ulong8 __ovld __cnfn popcount(ulong8 x);
long16 __ovld __cnfn popcount(long16 x);
ulong16 __ovld __cnfn popcount(ulong16 x);

/**
 * Multiply two 24-bit integer values x and y and add
 * the 32-bit integer result to the 32-bit integer z.
 * Refer to definition of mul24 to see how the 24-bit
 * integer multiplication is performed.
 */
int __ovld __cnfn mad24(int x, int y, int z);
uint __ovld __cnfn mad24(uint x, uint y, uint z);
int2 __ovld __cnfn mad24(int2 x, int2 y, int2 z);
uint2 __ovld __cnfn mad24(uint2 x, uint2 y, uint2 z);
int3 __ovld __cnfn mad24(int3 x, int3 y, int3 z);
uint3 __ovld __cnfn mad24(uint3 x, uint3 y, uint3 z);
int4 __ovld __cnfn mad24(int4 x, int4 y, int4 z);
uint4 __ovld __cnfn mad24(uint4 x, uint4 y, uint4 z);
int8 __ovld __cnfn mad24(int8 x, int8 y, int8 z);
uint8 __ovld __cnfn mad24(uint8 x, uint8 y, uint8 z);
int16 __ovld __cnfn mad24(int16 x, int16 y, int16 z);
uint16 __ovld __cnfn mad24(uint16 x, uint16 y, uint16 z);

/**
 * Multiply two 24-bit integer values x and y. x and y
 * are 32-bit integers but only the low 24-bits are used
 * to perform the multiplication. mul24 should only
 * be used when values in x and y are in the range [-
 * 2^23, 2^23-1] if x and y are signed integers and in the
 * range [0, 2^24-1] if x and y are unsigned integers. If
 * x and y are not in this range, the multiplication
 * result is implementation-defined.
 */
int __ovld __cnfn mul24(int x, int y);
uint __ovld __cnfn mul24(uint x, uint y);
int2 __ovld __cnfn mul24(int2 x, int2 y);
uint2 __ovld __cnfn mul24(uint2 x, uint2 y);
int3 __ovld __cnfn mul24(int3 x, int3 y);
uint3 __ovld __cnfn mul24(uint3 x, uint3 y);
int4 __ovld __cnfn mul24(int4 x, int4 y);
uint4 __ovld __cnfn mul24(uint4 x, uint4 y);
int8 __ovld __cnfn mul24(int8 x, int8 y);
uint8 __ovld __cnfn mul24(uint8 x, uint8 y);
int16 __ovld __cnfn mul24(int16 x, int16 y);
uint16 __ovld __cnfn mul24(uint16 x, uint16 y);

// OpenCL v1.1 s6.11.4, v1.2 s6.12.4, v2.0 s6.13.4 - Common Functions

/**
 * Returns fmin(fmax(x, minval), maxval).
 * Results are undefined if minval > maxval.
 */
float __ovld __cnfn clamp(float x, float minval, float maxval);
float2 __ovld __cnfn clamp(float2 x, float2 minval, float2 maxval);
float3 __ovld __cnfn clamp(float3 x, float3 minval, float3 maxval);
float4 __ovld __cnfn clamp(float4 x, float4 minval, float4 maxval);
float8 __ovld __cnfn clamp(float8 x, float8 minval, float8 maxval);
float16 __ovld __cnfn clamp(float16 x, float16 minval, float16 maxval);
float2 __ovld __cnfn clamp(float2 x, float minval, float maxval);
float3 __ovld __cnfn clamp(float3 x, float minval, float maxval);
float4 __ovld __cnfn clamp(float4 x, float minval, float maxval);
float8 __ovld __cnfn clamp(float8 x, float minval, float maxval);
float16 __ovld __cnfn clamp(float16 x, float minval, float maxval);
#ifdef cl_khr_fp64
double __ovld __cnfn clamp(double x, double minval, double maxval);
double2 __ovld __cnfn clamp(double2 x, double2 minval, double2 maxval);
double3 __ovld __cnfn clamp(double3 x, double3 minval, double3 maxval);
double4 __ovld __cnfn clamp(double4 x, double4 minval, double4 maxval);
double8 __ovld __cnfn clamp(double8 x, double8 minval, double8 maxval);
double16 __ovld __cnfn clamp(double16 x, double16 minval, double16 maxval);
double2 __ovld __cnfn clamp(double2 x, double minval, double maxval);
double3 __ovld __cnfn clamp(double3 x, double minval, double maxval);
double4 __ovld __cnfn clamp(double4 x, double minval, double maxval);
double8 __ovld __cnfn clamp(double8 x, double minval, double maxval);
double16 __ovld __cnfn clamp(double16 x, double minval, double maxval);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn clamp(half x, half minval, half maxval);
half2 __ovld __cnfn clamp(half2 x, half2 minval, half2 maxval);
half3 __ovld __cnfn clamp(half3 x, half3 minval, half3 maxval);
half4 __ovld __cnfn clamp(half4 x, half4 minval, half4 maxval);
half8 __ovld __cnfn clamp(half8 x, half8 minval, half8 maxval);
half16 __ovld __cnfn clamp(half16 x, half16 minval, half16 maxval);
half2 __ovld __cnfn clamp(half2 x, half minval, half maxval);
half3 __ovld __cnfn clamp(half3 x, half minval, half maxval);
half4 __ovld __cnfn clamp(half4 x, half minval, half maxval);
half8 __ovld __cnfn clamp(half8 x, half minval, half maxval);
half16 __ovld __cnfn clamp(half16 x, half minval, half maxval);
#endif //cl_khr_fp16

/**
 * Converts radians to degrees, i.e. (180 / PI) *
 * radians.
 */
float __ovld __cnfn degrees(float radians);
float2 __ovld __cnfn degrees(float2 radians);
float3 __ovld __cnfn degrees(float3 radians);
float4 __ovld __cnfn degrees(float4 radians);
float8 __ovld __cnfn degrees(float8 radians);
float16 __ovld __cnfn degrees(float16 radians);
#ifdef cl_khr_fp64
double __ovld __cnfn degrees(double radians);
double2 __ovld __cnfn degrees(double2 radians);
double3 __ovld __cnfn degrees(double3 radians);
double4 __ovld __cnfn degrees(double4 radians);
double8 __ovld __cnfn degrees(double8 radians);
double16 __ovld __cnfn degrees(double16 radians);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn degrees(half radians);
half2 __ovld __cnfn degrees(half2 radians);
half3 __ovld __cnfn degrees(half3 radians);
half4 __ovld __cnfn degrees(half4 radians);
half8 __ovld __cnfn degrees(half8 radians);
half16 __ovld __cnfn degrees(half16 radians);
#endif //cl_khr_fp16

/**
 * Returns y if x < y, otherwise it returns x. If x and y
 * are infinite or NaN, the return values are undefined.
 */
float __ovld __cnfn max(float x, float y);
float2 __ovld __cnfn max(float2 x, float2 y);
float3 __ovld __cnfn max(float3 x, float3 y);
float4 __ovld __cnfn max(float4 x, float4 y);
float8 __ovld __cnfn max(float8 x, float8 y);
float16 __ovld __cnfn max(float16 x, float16 y);
float2 __ovld __cnfn max(float2 x, float y);
float3 __ovld __cnfn max(float3 x, float y);
float4 __ovld __cnfn max(float4 x, float y);
float8 __ovld __cnfn max(float8 x, float y);
float16 __ovld __cnfn max(float16 x, float y);
#ifdef cl_khr_fp64
double __ovld __cnfn max(double x, double y);
double2 __ovld __cnfn max(double2 x, double2 y);
double3 __ovld __cnfn max(double3 x, double3 y);
double4 __ovld __cnfn max(double4 x, double4 y);
double8 __ovld __cnfn max(double8 x, double8 y);
double16 __ovld __cnfn max(double16 x, double16 y);
double2 __ovld __cnfn max(double2 x, double y);
double3 __ovld __cnfn max(double3 x, double y);
double4 __ovld __cnfn max(double4 x, double y);
double8 __ovld __cnfn max(double8 x, double y);
double16 __ovld __cnfn max(double16 x, double y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn max(half x, half y);
half2 __ovld __cnfn max(half2 x, half2 y);
half3 __ovld __cnfn max(half3 x, half3 y);
half4 __ovld __cnfn max(half4 x, half4 y);
half8 __ovld __cnfn max(half8 x, half8 y);
half16 __ovld __cnfn max(half16 x, half16 y);
half2 __ovld __cnfn max(half2 x, half y);
half3 __ovld __cnfn max(half3 x, half y);
half4 __ovld __cnfn max(half4 x, half y);
half8 __ovld __cnfn max(half8 x, half y);
half16 __ovld __cnfn max(half16 x, half y);
#endif //cl_khr_fp16

/**
 * Returns y if y < x, otherwise it returns x. If x and y
 * are infinite or NaN, the return values are undefined.
 */
float __ovld __cnfn min(float x, float y);
float2 __ovld __cnfn min(float2 x, float2 y);
float3 __ovld __cnfn min(float3 x, float3 y);
float4 __ovld __cnfn min(float4 x, float4 y);
float8 __ovld __cnfn min(float8 x, float8 y);
float16 __ovld __cnfn min(float16 x, float16 y);
float2 __ovld __cnfn min(float2 x, float y);
float3 __ovld __cnfn min(float3 x, float y);
float4 __ovld __cnfn min(float4 x, float y);
float8 __ovld __cnfn min(float8 x, float y);
float16 __ovld __cnfn min(float16 x, float y);
#ifdef cl_khr_fp64
double __ovld __cnfn min(double x, double y);
double2 __ovld __cnfn min(double2 x, double2 y);
double3 __ovld __cnfn min(double3 x, double3 y);
double4 __ovld __cnfn min(double4 x, double4 y);
double8 __ovld __cnfn min(double8 x, double8 y);
double16 __ovld __cnfn min(double16 x, double16 y);
double2 __ovld __cnfn min(double2 x, double y);
double3 __ovld __cnfn min(double3 x, double y);
double4 __ovld __cnfn min(double4 x, double y);
double8 __ovld __cnfn min(double8 x, double y);
double16 __ovld __cnfn min(double16 x, double y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn min(half x, half y);
half2 __ovld __cnfn min(half2 x, half2 y);
half3 __ovld __cnfn min(half3 x, half3 y);
half4 __ovld __cnfn min(half4 x, half4 y);
half8 __ovld __cnfn min(half8 x, half8 y);
half16 __ovld __cnfn min(half16 x, half16 y);
half2 __ovld __cnfn min(half2 x, half y);
half3 __ovld __cnfn min(half3 x, half y);
half4 __ovld __cnfn min(half4 x, half y);
half8 __ovld __cnfn min(half8 x, half y);
half16 __ovld __cnfn min(half16 x, half y);
#endif //cl_khr_fp16

/**
 * Returns the linear blend of x & y implemented as:
 * x + (y - x) * a
 * a must be a value in the range 0.0 ... 1.0. If a is not
 * in the range 0.0 ... 1.0, the return values are
 * undefined.
 */
float __ovld __cnfn mix(float x, float y, float a);
float2 __ovld __cnfn mix(float2 x, float2 y, float2 a);
float3 __ovld __cnfn mix(float3 x, float3 y, float3 a);
float4 __ovld __cnfn mix(float4 x, float4 y, float4 a);
float8 __ovld __cnfn mix(float8 x, float8 y, float8 a);
float16 __ovld __cnfn mix(float16 x, float16 y, float16 a);
float2 __ovld __cnfn mix(float2 x, float2 y, float a);
float3 __ovld __cnfn mix(float3 x, float3 y, float a);
float4 __ovld __cnfn mix(float4 x, float4 y, float a);
float8 __ovld __cnfn mix(float8 x, float8 y, float a);
float16 __ovld __cnfn mix(float16 x, float16 y, float a);
#ifdef cl_khr_fp64
double __ovld __cnfn mix(double x, double y, double a);
double2 __ovld __cnfn mix(double2 x, double2 y, double2 a);
double3 __ovld __cnfn mix(double3 x, double3 y, double3 a);
double4 __ovld __cnfn mix(double4 x, double4 y, double4 a);
double8 __ovld __cnfn mix(double8 x, double8 y, double8 a);
double16 __ovld __cnfn mix(double16 x, double16 y, double16 a);
double2 __ovld __cnfn mix(double2 x, double2 y, double a);
double3 __ovld __cnfn mix(double3 x, double3 y, double a);
double4 __ovld __cnfn mix(double4 x, double4 y, double a);
double8 __ovld __cnfn mix(double8 x, double8 y, double a);
double16 __ovld __cnfn mix(double16 x, double16 y, double a);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn mix(half x, half y, half a);
half2 __ovld __cnfn mix(half2 x, half2 y, half2 a);
half3 __ovld __cnfn mix(half3 x, half3 y, half3 a);
half4 __ovld __cnfn mix(half4 x, half4 y, half4 a);
half8 __ovld __cnfn mix(half8 x, half8 y, half8 a);
half16 __ovld __cnfn mix(half16 x, half16 y, half16 a);
half2 __ovld __cnfn mix(half2 x, half2 y, half a);
half3 __ovld __cnfn mix(half3 x, half3 y, half a);
half4 __ovld __cnfn mix(half4 x, half4 y, half a);
half8 __ovld __cnfn mix(half8 x, half8 y, half a);
half16 __ovld __cnfn mix(half16 x, half16 y, half a);
#endif //cl_khr_fp16

/**
 * Converts degrees to radians, i.e. (PI / 180) *
 * degrees.
 */
float __ovld __cnfn radians(float degrees);
float2 __ovld __cnfn radians(float2 degrees);
float3 __ovld __cnfn radians(float3 degrees);
float4 __ovld __cnfn radians(float4 degrees);
float8 __ovld __cnfn radians(float8 degrees);
float16 __ovld __cnfn radians(float16 degrees);
#ifdef cl_khr_fp64
double __ovld __cnfn radians(double degrees);
double2 __ovld __cnfn radians(double2 degrees);
double3 __ovld __cnfn radians(double3 degrees);
double4 __ovld __cnfn radians(double4 degrees);
double8 __ovld __cnfn radians(double8 degrees);
double16 __ovld __cnfn radians(double16 degrees);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn radians(half degrees);
half2 __ovld __cnfn radians(half2 degrees);
half3 __ovld __cnfn radians(half3 degrees);
half4 __ovld __cnfn radians(half4 degrees);
half8 __ovld __cnfn radians(half8 degrees);
half16 __ovld __cnfn radians(half16 degrees);
#endif //cl_khr_fp16

/**
 * Returns 0.0 if x < edge, otherwise it returns 1.0.
 */
float __ovld __cnfn step(float edge, float x);
float2 __ovld __cnfn step(float2 edge, float2 x);
float3 __ovld __cnfn step(float3 edge, float3 x);
float4 __ovld __cnfn step(float4 edge, float4 x);
float8 __ovld __cnfn step(float8 edge, float8 x);
float16 __ovld __cnfn step(float16 edge, float16 x);
float2 __ovld __cnfn step(float edge, float2 x);
float3 __ovld __cnfn step(float edge, float3 x);
float4 __ovld __cnfn step(float edge, float4 x);
float8 __ovld __cnfn step(float edge, float8 x);
float16 __ovld __cnfn step(float edge, float16 x);
#ifdef cl_khr_fp64
double __ovld __cnfn step(double edge, double x);
double2 __ovld __cnfn step(double2 edge, double2 x);
double3 __ovld __cnfn step(double3 edge, double3 x);
double4 __ovld __cnfn step(double4 edge, double4 x);
double8 __ovld __cnfn step(double8 edge, double8 x);
double16 __ovld __cnfn step(double16 edge, double16 x);
double2 __ovld __cnfn step(double edge, double2 x);
double3 __ovld __cnfn step(double edge, double3 x);
double4 __ovld __cnfn step(double edge, double4 x);
double8 __ovld __cnfn step(double edge, double8 x);
double16 __ovld __cnfn step(double edge, double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn step(half edge, half x);
half2 __ovld __cnfn step(half2 edge, half2 x);
half3 __ovld __cnfn step(half3 edge, half3 x);
half4 __ovld __cnfn step(half4 edge, half4 x);
half8 __ovld __cnfn step(half8 edge, half8 x);
half16 __ovld __cnfn step(half16 edge, half16 x);
half __ovld __cnfn step(half edge, half x);
half2 __ovld __cnfn step(half edge, half2 x);
half3 __ovld __cnfn step(half edge, half3 x);
half4 __ovld __cnfn step(half edge, half4 x);
half8 __ovld __cnfn step(half edge, half8 x);
half16 __ovld __cnfn step(half edge, half16 x);
#endif //cl_khr_fp16

/**
 * Returns 0.0 if x <= edge0 and 1.0 if x >= edge1 and
 * performs smooth Hermite interpolation between 0
 * and 1when edge0 < x < edge1. This is useful in
 * cases where you would want a threshold function
 * with a smooth transition.
 * This is equivalent to:
 * gentype t;
 * t = clamp ((x - edge0) / (edge1 - edge0), 0, 1);
 * return t * t * (3 - 2 * t);
 * Results are undefined if edge0 >= edge1 or if x,
 * edge0 or edge1 is a NaN.
 */
float __ovld __cnfn smoothstep(float edge0, float edge1, float x);
float2 __ovld __cnfn smoothstep(float2 edge0, float2 edge1, float2 x);
float3 __ovld __cnfn smoothstep(float3 edge0, float3 edge1, float3 x);
float4 __ovld __cnfn smoothstep(float4 edge0, float4 edge1, float4 x);
float8 __ovld __cnfn smoothstep(float8 edge0, float8 edge1, float8 x);
float16 __ovld __cnfn smoothstep(float16 edge0, float16 edge1, float16 x);
float2 __ovld __cnfn smoothstep(float edge0, float edge1, float2 x);
float3 __ovld __cnfn smoothstep(float edge0, float edge1, float3 x);
float4 __ovld __cnfn smoothstep(float edge0, float edge1, float4 x);
float8 __ovld __cnfn smoothstep(float edge0, float edge1, float8 x);
float16 __ovld __cnfn smoothstep(float edge0, float edge1, float16 x);
#ifdef cl_khr_fp64
double __ovld __cnfn smoothstep(double edge0, double edge1, double x);
double2 __ovld __cnfn smoothstep(double2 edge0, double2 edge1, double2 x);
double3 __ovld __cnfn smoothstep(double3 edge0, double3 edge1, double3 x);
double4 __ovld __cnfn smoothstep(double4 edge0, double4 edge1, double4 x);
double8 __ovld __cnfn smoothstep(double8 edge0, double8 edge1, double8 x);
double16 __ovld __cnfn smoothstep(double16 edge0, double16 edge1, double16 x);
double2 __ovld __cnfn smoothstep(double edge0, double edge1, double2 x);
double3 __ovld __cnfn smoothstep(double edge0, double edge1, double3 x);
double4 __ovld __cnfn smoothstep(double edge0, double edge1, double4 x);
double8 __ovld __cnfn smoothstep(double edge0, double edge1, double8 x);
double16 __ovld __cnfn smoothstep(double edge0, double edge1, double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn smoothstep(half edge0, half edge1, half x);
half2 __ovld __cnfn smoothstep(half2 edge0, half2 edge1, half2 x);
half3 __ovld __cnfn smoothstep(half3 edge0, half3 edge1, half3 x);
half4 __ovld __cnfn smoothstep(half4 edge0, half4 edge1, half4 x);
half8 __ovld __cnfn smoothstep(half8 edge0, half8 edge1, half8 x);
half16 __ovld __cnfn smoothstep(half16 edge0, half16 edge1, half16 x);
half __ovld __cnfn smoothstep(half edge0, half edge1, half x);
half2 __ovld __cnfn smoothstep(half edge0, half edge1, half2 x);
half3 __ovld __cnfn smoothstep(half edge0, half edge1, half3 x);
half4 __ovld __cnfn smoothstep(half edge0, half edge1, half4 x);
half8 __ovld __cnfn smoothstep(half edge0, half edge1, half8 x);
half16 __ovld __cnfn smoothstep(half edge0, half edge1, half16 x);
#endif //cl_khr_fp16

/**
 * Returns 1.0 if x > 0, -0.0 if x = -0.0, +0.0 if x =
 * +0.0, or -1.0 if x < 0. Returns 0.0 if x is a NaN.
 */
float __ovld __cnfn sign(float x);
float2 __ovld __cnfn sign(float2 x);
float3 __ovld __cnfn sign(float3 x);
float4 __ovld __cnfn sign(float4 x);
float8 __ovld __cnfn sign(float8 x);
float16 __ovld __cnfn sign(float16 x);
#ifdef cl_khr_fp64
double __ovld __cnfn sign(double x);
double2 __ovld __cnfn sign(double2 x);
double3 __ovld __cnfn sign(double3 x);
double4 __ovld __cnfn sign(double4 x);
double8 __ovld __cnfn sign(double8 x);
double16 __ovld __cnfn sign(double16 x);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn sign(half x);
half2 __ovld __cnfn sign(half2 x);
half3 __ovld __cnfn sign(half3 x);
half4 __ovld __cnfn sign(half4 x);
half8 __ovld __cnfn sign(half8 x);
half16 __ovld __cnfn sign(half16 x);
#endif //cl_khr_fp16

// OpenCL v1.1 s6.11.5, v1.2 s6.12.5, v2.0 s6.13.5 - Geometric Functions

/**
 * Returns the cross product of p0.xyz and p1.xyz. The
 * w component of float4 result returned will be 0.0.
 */
float4 __ovld __cnfn cross(float4 p0, float4 p1);
float3 __ovld __cnfn cross(float3 p0, float3 p1);
#ifdef cl_khr_fp64
double4 __ovld __cnfn cross(double4 p0, double4 p1);
double3 __ovld __cnfn cross(double3 p0, double3 p1);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half4 __ovld __cnfn cross(half4 p0, half4 p1);
half3 __ovld __cnfn cross(half3 p0, half3 p1);
#endif //cl_khr_fp16

/**
 * Compute dot product.
 */
float __ovld __cnfn dot(float p0, float p1);
float __ovld __cnfn dot(float2 p0, float2 p1);
float __ovld __cnfn dot(float3 p0, float3 p1);
float __ovld __cnfn dot(float4 p0, float4 p1);
#ifdef cl_khr_fp64
double __ovld __cnfn dot(double p0, double p1);
double __ovld __cnfn dot(double2 p0, double2 p1);
double __ovld __cnfn dot(double3 p0, double3 p1);
double __ovld __cnfn dot(double4 p0, double4 p1);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn dot(half p0, half p1);
half __ovld __cnfn dot(half2 p0, half2 p1);
half __ovld __cnfn dot(half3 p0, half3 p1);
half __ovld __cnfn dot(half4 p0, half4 p1);
#endif //cl_khr_fp16

/**
 * Returns the distance between p0 and p1. This is
 * calculated as length(p0 - p1).
 */
float __ovld __cnfn distance(float p0, float p1);
float __ovld __cnfn distance(float2 p0, float2 p1);
float __ovld __cnfn distance(float3 p0, float3 p1);
float __ovld __cnfn distance(float4 p0, float4 p1);
#ifdef cl_khr_fp64
double __ovld __cnfn distance(double p0, double p1);
double __ovld __cnfn distance(double2 p0, double2 p1);
double __ovld __cnfn distance(double3 p0, double3 p1);
double __ovld __cnfn distance(double4 p0, double4 p1);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn distance(half p0, half p1);
half __ovld __cnfn distance(half2 p0, half2 p1);
half __ovld __cnfn distance(half3 p0, half3 p1);
half __ovld __cnfn distance(half4 p0, half4 p1);
#endif //cl_khr_fp16

/**
 * Return the length of vector p, i.e.,
 * sqrt(p.x2 + p.y 2 + ...)
 */
float __ovld __cnfn length(float p);
float __ovld __cnfn length(float2 p);
float __ovld __cnfn length(float3 p);
float __ovld __cnfn length(float4 p);
#ifdef cl_khr_fp64
double __ovld __cnfn length(double p);
double __ovld __cnfn length(double2 p);
double __ovld __cnfn length(double3 p);
double __ovld __cnfn length(double4 p);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn length(half p);
half __ovld __cnfn length(half2 p);
half __ovld __cnfn length(half3 p);
half __ovld __cnfn length(half4 p);
#endif //cl_khr_fp16

/**
 * Returns a vector in the same direction as p but with a
 * length of 1.
 */
float __ovld __cnfn normalize(float p);
float2 __ovld __cnfn normalize(float2 p);
float3 __ovld __cnfn normalize(float3 p);
float4 __ovld __cnfn normalize(float4 p);
#ifdef cl_khr_fp64
double __ovld __cnfn normalize(double p);
double2 __ovld __cnfn normalize(double2 p);
double3 __ovld __cnfn normalize(double3 p);
double4 __ovld __cnfn normalize(double4 p);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn normalize(half p);
half2 __ovld __cnfn normalize(half2 p);
half3 __ovld __cnfn normalize(half3 p);
half4 __ovld __cnfn normalize(half4 p);
#endif //cl_khr_fp16

/**
 * Returns fast_length(p0 - p1).
 */
float __ovld __cnfn fast_distance(float p0, float p1);
float __ovld __cnfn fast_distance(float2 p0, float2 p1);
float __ovld __cnfn fast_distance(float3 p0, float3 p1);
float __ovld __cnfn fast_distance(float4 p0, float4 p1);
#ifdef cl_khr_fp16
half __ovld __cnfn fast_distance(half p0, half p1);
half __ovld __cnfn fast_distance(half2 p0, half2 p1);
half __ovld __cnfn fast_distance(half3 p0, half3 p1);
half __ovld __cnfn fast_distance(half4 p0, half4 p1);
#endif //cl_khr_fp16

/**
 * Returns the length of vector p computed as:
 * half_sqrt(p.x2 + p.y2 + ...)
 */
float __ovld __cnfn fast_length(float p);
float __ovld __cnfn fast_length(float2 p);
float __ovld __cnfn fast_length(float3 p);
float __ovld __cnfn fast_length(float4 p);
#ifdef cl_khr_fp16
half __ovld __cnfn fast_length(half p);
half __ovld __cnfn fast_length(half2 p);
half __ovld __cnfn fast_length(half3 p);
half __ovld __cnfn fast_length(half4 p);
#endif //cl_khr_fp16

/**
 * Returns a vector in the same direction as p but with a
 * length of 1. fast_normalize is computed as:
 * p * half_rsqrt (p.x^2 + p.y^2 + ... )
 * The result shall be within 8192 ulps error from the
 * infinitely precise result of
 * if (all(p == 0.0f))
 * result = p;
 * else
 * result = p / sqrt (p.x^2 + p.y^2 + ...);
 * with the following exceptions:
 * 1) If the sum of squares is greater than FLT_MAX
 * then the value of the floating-point values in the
 * result vector are undefined.
 * 2) If the sum of squares is less than FLT_MIN then
 * the implementation may return back p.
 * 3) If the device is in "denorms are flushed to zero"
 * mode, individual operand elements with magnitude
 * less than sqrt(FLT_MIN) may be flushed to zero
 * before proceeding with the calculation.
 */
float __ovld __cnfn fast_normalize(float p);
float2 __ovld __cnfn fast_normalize(float2 p);
float3 __ovld __cnfn fast_normalize(float3 p);
float4 __ovld __cnfn fast_normalize(float4 p);
#ifdef cl_khr_fp16
half __ovld __cnfn fast_normalize(half p);
half2 __ovld __cnfn fast_normalize(half2 p);
half3 __ovld __cnfn fast_normalize(half3 p);
half4 __ovld __cnfn fast_normalize(half4 p);
#endif //cl_khr_fp16

// OpenCL v1.1 s6.11.6, v1.2 s6.12.6, v2.0 s6.13.6 - Relational Functions

/**
 * intn isequal (floatn x, floatn y)
 * Returns the component-wise compare of x == y.
 */
int __ovld __cnfn isequal(float x, float y);
int2 __ovld __cnfn isequal(float2 x, float2 y);
int3 __ovld __cnfn isequal(float3 x, float3 y);
int4 __ovld __cnfn isequal(float4 x, float4 y);
int8 __ovld __cnfn isequal(float8 x, float8 y);
int16 __ovld __cnfn isequal(float16 x, float16 y);
#ifdef cl_khr_fp64
int __ovld __cnfn isequal(double x, double y);
long2 __ovld __cnfn isequal(double2 x, double2 y);
long3 __ovld __cnfn isequal(double3 x, double3 y);
long4 __ovld __cnfn isequal(double4 x, double4 y);
long8 __ovld __cnfn isequal(double8 x, double8 y);
long16 __ovld __cnfn isequal(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __ovld __cnfn isequal(half x, half y);
short2 __ovld __cnfn isequal(half2 x, half2 y);
short3 __ovld __cnfn isequal(half3 x, half3 y);
short4 __ovld __cnfn isequal(half4 x, half4 y);
short8 __ovld __cnfn isequal(half8 x, half8 y);
short16 __ovld __cnfn isequal(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Returns the component-wise compare of x != y.
 */
int __ovld __cnfn isnotequal(float x, float y);
int2 __ovld __cnfn isnotequal(float2 x, float2 y);
int3 __ovld __cnfn isnotequal(float3 x, float3 y);
int4 __ovld __cnfn isnotequal(float4 x, float4 y);
int8 __ovld __cnfn isnotequal(float8 x, float8 y);
int16 __ovld __cnfn isnotequal(float16 x, float16 y);
#ifdef cl_khr_fp64
int __ovld __cnfn isnotequal(double x, double y);
long2 __ovld __cnfn isnotequal(double2 x, double2 y);
long3 __ovld __cnfn isnotequal(double3 x, double3 y);
long4 __ovld __cnfn isnotequal(double4 x, double4 y);
long8 __ovld __cnfn isnotequal(double8 x, double8 y);
long16 __ovld __cnfn isnotequal(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __ovld __cnfn isnotequal(half x, half y);
short2 __ovld __cnfn isnotequal(half2 x, half2 y);
short3 __ovld __cnfn isnotequal(half3 x, half3 y);
short4 __ovld __cnfn isnotequal(half4 x, half4 y);
short8 __ovld __cnfn isnotequal(half8 x, half8 y);
short16 __ovld __cnfn isnotequal(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Returns the component-wise compare of x > y.
 */
int __ovld __cnfn isgreater(float x, float y);
int2 __ovld __cnfn isgreater(float2 x, float2 y);
int3 __ovld __cnfn isgreater(float3 x, float3 y);
int4 __ovld __cnfn isgreater(float4 x, float4 y);
int8 __ovld __cnfn isgreater(float8 x, float8 y);
int16 __ovld __cnfn isgreater(float16 x, float16 y);
#ifdef cl_khr_fp64
int __ovld __cnfn isgreater(double x, double y);
long2 __ovld __cnfn isgreater(double2 x, double2 y);
long3 __ovld __cnfn isgreater(double3 x, double3 y);
long4 __ovld __cnfn isgreater(double4 x, double4 y);
long8 __ovld __cnfn isgreater(double8 x, double8 y);
long16 __ovld __cnfn isgreater(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __ovld __cnfn isgreater(half x, half y);
short2 __ovld __cnfn isgreater(half2 x, half2 y);
short3 __ovld __cnfn isgreater(half3 x, half3 y);
short4 __ovld __cnfn isgreater(half4 x, half4 y);
short8 __ovld __cnfn isgreater(half8 x, half8 y);
short16 __ovld __cnfn isgreater(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Returns the component-wise compare of x >= y.
 */
int __ovld __cnfn isgreaterequal(float x, float y);
int2 __ovld __cnfn isgreaterequal(float2 x, float2 y);
int3 __ovld __cnfn isgreaterequal(float3 x, float3 y);
int4 __ovld __cnfn isgreaterequal(float4 x, float4 y);
int8 __ovld __cnfn isgreaterequal(float8 x, float8 y);
int16 __ovld __cnfn isgreaterequal(float16 x, float16 y);
#ifdef cl_khr_fp64
int __ovld __cnfn isgreaterequal(double x, double y);
long2 __ovld __cnfn isgreaterequal(double2 x, double2 y);
long3 __ovld __cnfn isgreaterequal(double3 x, double3 y);
long4 __ovld __cnfn isgreaterequal(double4 x, double4 y);
long8 __ovld __cnfn isgreaterequal(double8 x, double8 y);
long16 __ovld __cnfn isgreaterequal(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __ovld __cnfn isgreaterequal(half x, half y);
short2 __ovld __cnfn isgreaterequal(half2 x, half2 y);
short3 __ovld __cnfn isgreaterequal(half3 x, half3 y);
short4 __ovld __cnfn isgreaterequal(half4 x, half4 y);
short8 __ovld __cnfn isgreaterequal(half8 x, half8 y);
short16 __ovld __cnfn isgreaterequal(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Returns the component-wise compare of x < y.
 */
int __ovld __cnfn isless(float x, float y);
int2 __ovld __cnfn isless(float2 x, float2 y);
int3 __ovld __cnfn isless(float3 x, float3 y);
int4 __ovld __cnfn isless(float4 x, float4 y);
int8 __ovld __cnfn isless(float8 x, float8 y);
int16 __ovld __cnfn isless(float16 x, float16 y);
#ifdef cl_khr_fp64
int __ovld __cnfn isless(double x, double y);
long2 __ovld __cnfn isless(double2 x, double2 y);
long3 __ovld __cnfn isless(double3 x, double3 y);
long4 __ovld __cnfn isless(double4 x, double4 y);
long8 __ovld __cnfn isless(double8 x, double8 y);
long16 __ovld __cnfn isless(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __ovld __cnfn isless(half x, half y);
short2 __ovld __cnfn isless(half2 x, half2 y);
short3 __ovld __cnfn isless(half3 x, half3 y);
short4 __ovld __cnfn isless(half4 x, half4 y);
short8 __ovld __cnfn isless(half8 x, half8 y);
short16 __ovld __cnfn isless(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Returns the component-wise compare of x <= y.
 */
int __ovld __cnfn islessequal(float x, float y);
int2 __ovld __cnfn islessequal(float2 x, float2 y);
int3 __ovld __cnfn islessequal(float3 x, float3 y);
int4 __ovld __cnfn islessequal(float4 x, float4 y);
int8 __ovld __cnfn islessequal(float8 x, float8 y);
int16 __ovld __cnfn islessequal(float16 x, float16 y);
#ifdef cl_khr_fp64
int __ovld __cnfn islessequal(double x, double y);
long2 __ovld __cnfn islessequal(double2 x, double2 y);
long3 __ovld __cnfn islessequal(double3 x, double3 y);
long4 __ovld __cnfn islessequal(double4 x, double4 y);
long8 __ovld __cnfn islessequal(double8 x, double8 y);
long16 __ovld __cnfn islessequal(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __ovld __cnfn islessequal(half x, half y);
short2 __ovld __cnfn islessequal(half2 x, half2 y);
short3 __ovld __cnfn islessequal(half3 x, half3 y);
short4 __ovld __cnfn islessequal(half4 x, half4 y);
short8 __ovld __cnfn islessequal(half8 x, half8 y);
short16 __ovld __cnfn islessequal(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Returns the component-wise compare of
 * (x < y) || (x > y) .
 */
int __ovld __cnfn islessgreater(float x, float y);
int2 __ovld __cnfn islessgreater(float2 x, float2 y);
int3 __ovld __cnfn islessgreater(float3 x, float3 y);
int4 __ovld __cnfn islessgreater(float4 x, float4 y);
int8 __ovld __cnfn islessgreater(float8 x, float8 y);
int16 __ovld __cnfn islessgreater(float16 x, float16 y);
#ifdef cl_khr_fp64
int __ovld __cnfn islessgreater(double x, double y);
long2 __ovld __cnfn islessgreater(double2 x, double2 y);
long3 __ovld __cnfn islessgreater(double3 x, double3 y);
long4 __ovld __cnfn islessgreater(double4 x, double4 y);
long8 __ovld __cnfn islessgreater(double8 x, double8 y);
long16 __ovld __cnfn islessgreater(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __ovld __cnfn islessgreater(half x, half y);
short2 __ovld __cnfn islessgreater(half2 x, half2 y);
short3 __ovld __cnfn islessgreater(half3 x, half3 y);
short4 __ovld __cnfn islessgreater(half4 x, half4 y);
short8 __ovld __cnfn islessgreater(half8 x, half8 y);
short16 __ovld __cnfn islessgreater(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Test for finite value.
 */
int __ovld __cnfn isfinite(float);
int2 __ovld __cnfn isfinite(float2);
int3 __ovld __cnfn isfinite(float3);
int4 __ovld __cnfn isfinite(float4);
int8 __ovld __cnfn isfinite(float8);
int16 __ovld __cnfn isfinite(float16);
#ifdef cl_khr_fp64
int __ovld __cnfn isfinite(double);
long2 __ovld __cnfn isfinite(double2);
long3 __ovld __cnfn isfinite(double3);
long4 __ovld __cnfn isfinite(double4);
long8 __ovld __cnfn isfinite(double8);
long16 __ovld __cnfn isfinite(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __ovld __cnfn isfinite(half);
short2 __ovld __cnfn isfinite(half2);
short3 __ovld __cnfn isfinite(half3);
short4 __ovld __cnfn isfinite(half4);
short8 __ovld __cnfn isfinite(half8);
short16 __ovld __cnfn isfinite(half16);
#endif //cl_khr_fp16

/**
 * Test for infinity value (+ve or -ve) .
 */
int __ovld __cnfn isinf(float);
int2 __ovld __cnfn isinf(float2);
int3 __ovld __cnfn isinf(float3);
int4 __ovld __cnfn isinf(float4);
int8 __ovld __cnfn isinf(float8);
int16 __ovld __cnfn isinf(float16);
#ifdef cl_khr_fp64
int __ovld __cnfn isinf(double);
long2 __ovld __cnfn isinf(double2);
long3 __ovld __cnfn isinf(double3);
long4 __ovld __cnfn isinf(double4);
long8 __ovld __cnfn isinf(double8);
long16 __ovld __cnfn isinf(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __ovld __cnfn isinf(half);
short2 __ovld __cnfn isinf(half2);
short3 __ovld __cnfn isinf(half3);
short4 __ovld __cnfn isinf(half4);
short8 __ovld __cnfn isinf(half8);
short16 __ovld __cnfn isinf(half16);
#endif //cl_khr_fp16

/**
 * Test for a NaN.
 */
int __ovld __cnfn isnan(float);
int2 __ovld __cnfn isnan(float2);
int3 __ovld __cnfn isnan(float3);
int4 __ovld __cnfn isnan(float4);
int8 __ovld __cnfn isnan(float8);
int16 __ovld __cnfn isnan(float16);
#ifdef cl_khr_fp64
int __ovld __cnfn isnan(double);
long2 __ovld __cnfn isnan(double2);
long3 __ovld __cnfn isnan(double3);
long4 __ovld __cnfn isnan(double4);
long8 __ovld __cnfn isnan(double8);
long16 __ovld __cnfn isnan(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __ovld __cnfn isnan(half);
short2 __ovld __cnfn isnan(half2);
short3 __ovld __cnfn isnan(half3);
short4 __ovld __cnfn isnan(half4);
short8 __ovld __cnfn isnan(half8);
short16 __ovld __cnfn isnan(half16);
#endif //cl_khr_fp16

/**
 * Test for a normal value.
 */
int __ovld __cnfn isnormal(float);
int2 __ovld __cnfn isnormal(float2);
int3 __ovld __cnfn isnormal(float3);
int4 __ovld __cnfn isnormal(float4);
int8 __ovld __cnfn isnormal(float8);
int16 __ovld __cnfn isnormal(float16);
#ifdef cl_khr_fp64
int __ovld __cnfn isnormal(double);
long2 __ovld __cnfn isnormal(double2);
long3 __ovld __cnfn isnormal(double3);
long4 __ovld __cnfn isnormal(double4);
long8 __ovld __cnfn isnormal(double8);
long16 __ovld __cnfn isnormal(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __ovld __cnfn isnormal(half);
short2 __ovld __cnfn isnormal(half2);
short3 __ovld __cnfn isnormal(half3);
short4 __ovld __cnfn isnormal(half4);
short8 __ovld __cnfn isnormal(half8);
short16 __ovld __cnfn isnormal(half16);
#endif //cl_khr_fp16

/**
 * Test if arguments are ordered. isordered() takes
 * arguments x and y, and returns the result
 * isequal(x, x) && isequal(y, y).
 */
int __ovld __cnfn isordered(float x, float y);
int2 __ovld __cnfn isordered(float2 x, float2 y);
int3 __ovld __cnfn isordered(float3 x, float3 y);
int4 __ovld __cnfn isordered(float4 x, float4 y);
int8 __ovld __cnfn isordered(float8 x, float8 y);
int16 __ovld __cnfn isordered(float16 x, float16 y);
#ifdef cl_khr_fp64
int __ovld __cnfn isordered(double x, double y);
long2 __ovld __cnfn isordered(double2 x, double2 y);
long3 __ovld __cnfn isordered(double3 x, double3 y);
long4 __ovld __cnfn isordered(double4 x, double4 y);
long8 __ovld __cnfn isordered(double8 x, double8 y);
long16 __ovld __cnfn isordered(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __ovld __cnfn isordered(half x, half y);
short2 __ovld __cnfn isordered(half2 x, half2 y);
short3 __ovld __cnfn isordered(half3 x, half3 y);
short4 __ovld __cnfn isordered(half4 x, half4 y);
short8 __ovld __cnfn isordered(half8 x, half8 y);
short16 __ovld __cnfn isordered(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Test if arguments are unordered. isunordered()
 * takes arguments x and y, returning non-zero if x or y
 * is NaN, and zero otherwise.
 */
int __ovld __cnfn isunordered(float x, float y);
int2 __ovld __cnfn isunordered(float2 x, float2 y);
int3 __ovld __cnfn isunordered(float3 x, float3 y);
int4 __ovld __cnfn isunordered(float4 x, float4 y);
int8 __ovld __cnfn isunordered(float8 x, float8 y);
int16 __ovld __cnfn isunordered(float16 x, float16 y);
#ifdef cl_khr_fp64
int __ovld __cnfn isunordered(double x, double y);
long2 __ovld __cnfn isunordered(double2 x, double2 y);
long3 __ovld __cnfn isunordered(double3 x, double3 y);
long4 __ovld __cnfn isunordered(double4 x, double4 y);
long8 __ovld __cnfn isunordered(double8 x, double8 y);
long16 __ovld __cnfn isunordered(double16 x, double16 y);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __ovld __cnfn isunordered(half x, half y);
short2 __ovld __cnfn isunordered(half2 x, half2 y);
short3 __ovld __cnfn isunordered(half3 x, half3 y);
short4 __ovld __cnfn isunordered(half4 x, half4 y);
short8 __ovld __cnfn isunordered(half8 x, half8 y);
short16 __ovld __cnfn isunordered(half16 x, half16 y);
#endif //cl_khr_fp16

/**
 * Test for sign bit. The scalar version of the function
 * returns a 1 if the sign bit in the float is set else returns
 * 0. The vector version of the function returns the
 * following for each component in floatn: a -1 if the
 * sign bit in the float is set else returns 0.
 */
int __ovld __cnfn signbit(float);
int2 __ovld __cnfn signbit(float2);
int3 __ovld __cnfn signbit(float3);
int4 __ovld __cnfn signbit(float4);
int8 __ovld __cnfn signbit(float8);
int16 __ovld __cnfn signbit(float16);
#ifdef cl_khr_fp64
int __ovld __cnfn signbit(double);
long2 __ovld __cnfn signbit(double2);
long3 __ovld __cnfn signbit(double3);
long4 __ovld __cnfn signbit(double4);
long8 __ovld __cnfn signbit(double8);
long16 __ovld __cnfn signbit(double16);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
int __ovld __cnfn signbit(half);
short2 __ovld __cnfn signbit(half2);
short3 __ovld __cnfn signbit(half3);
short4 __ovld __cnfn signbit(half4);
short8 __ovld __cnfn signbit(half8);
short16 __ovld __cnfn signbit(half16);
#endif //cl_khr_fp16

/**
 * Returns 1 if the most significant bit in any component
 * of x is set; otherwise returns 0.
 */
int __ovld __cnfn any(char x);
int __ovld __cnfn any(char2 x);
int __ovld __cnfn any(char3 x);
int __ovld __cnfn any(char4 x);
int __ovld __cnfn any(char8 x);
int __ovld __cnfn any(char16 x);
int __ovld __cnfn any(short x);
int __ovld __cnfn any(short2 x);
int __ovld __cnfn any(short3 x);
int __ovld __cnfn any(short4 x);
int __ovld __cnfn any(short8 x);
int __ovld __cnfn any(short16 x);
int __ovld __cnfn any(int x);
int __ovld __cnfn any(int2 x);
int __ovld __cnfn any(int3 x);
int __ovld __cnfn any(int4 x);
int __ovld __cnfn any(int8 x);
int __ovld __cnfn any(int16 x);
int __ovld __cnfn any(long x);
int __ovld __cnfn any(long2 x);
int __ovld __cnfn any(long3 x);
int __ovld __cnfn any(long4 x);
int __ovld __cnfn any(long8 x);
int __ovld __cnfn any(long16 x);

/**
 * Returns 1 if the most significant bit in all components
 * of x is set; otherwise returns 0.
 */
int __ovld __cnfn all(char x);
int __ovld __cnfn all(char2 x);
int __ovld __cnfn all(char3 x);
int __ovld __cnfn all(char4 x);
int __ovld __cnfn all(char8 x);
int __ovld __cnfn all(char16 x);
int __ovld __cnfn all(short x);
int __ovld __cnfn all(short2 x);
int __ovld __cnfn all(short3 x);
int __ovld __cnfn all(short4 x);
int __ovld __cnfn all(short8 x);
int __ovld __cnfn all(short16 x);
int __ovld __cnfn all(int x);
int __ovld __cnfn all(int2 x);
int __ovld __cnfn all(int3 x);
int __ovld __cnfn all(int4 x);
int __ovld __cnfn all(int8 x);
int __ovld __cnfn all(int16 x);
int __ovld __cnfn all(long x);
int __ovld __cnfn all(long2 x);
int __ovld __cnfn all(long3 x);
int __ovld __cnfn all(long4 x);
int __ovld __cnfn all(long8 x);
int __ovld __cnfn all(long16 x);

/**
 * Each bit of the result is the corresponding bit of a if
 * the corresponding bit of c is 0. Otherwise it is the
 * corresponding bit of b.
 */
char __ovld __cnfn bitselect(char a, char b, char c);
uchar __ovld __cnfn bitselect(uchar a, uchar b, uchar c);
char2 __ovld __cnfn bitselect(char2 a, char2 b, char2 c);
uchar2 __ovld __cnfn bitselect(uchar2 a, uchar2 b, uchar2 c);
char3 __ovld __cnfn bitselect(char3 a, char3 b, char3 c);
uchar3 __ovld __cnfn bitselect(uchar3 a, uchar3 b, uchar3 c);
char4 __ovld __cnfn bitselect(char4 a, char4 b, char4 c);
uchar4 __ovld __cnfn bitselect(uchar4 a, uchar4 b, uchar4 c);
char8 __ovld __cnfn bitselect(char8 a, char8 b, char8 c);
uchar8 __ovld __cnfn bitselect(uchar8 a, uchar8 b, uchar8 c);
char16 __ovld __cnfn bitselect(char16 a, char16 b, char16 c);
uchar16 __ovld __cnfn bitselect(uchar16 a, uchar16 b, uchar16 c);
short __ovld __cnfn bitselect(short a, short b, short c);
ushort __ovld __cnfn bitselect(ushort a, ushort b, ushort c);
short2 __ovld __cnfn bitselect(short2 a, short2 b, short2 c);
ushort2 __ovld __cnfn bitselect(ushort2 a, ushort2 b, ushort2 c);
short3 __ovld __cnfn bitselect(short3 a, short3 b, short3 c);
ushort3 __ovld __cnfn bitselect(ushort3 a, ushort3 b, ushort3 c);
short4 __ovld __cnfn bitselect(short4 a, short4 b, short4 c);
ushort4 __ovld __cnfn bitselect(ushort4 a, ushort4 b, ushort4 c);
short8 __ovld __cnfn bitselect(short8 a, short8 b, short8 c);
ushort8 __ovld __cnfn bitselect(ushort8 a, ushort8 b, ushort8 c);
short16 __ovld __cnfn bitselect(short16 a, short16 b, short16 c);
ushort16 __ovld __cnfn bitselect(ushort16 a, ushort16 b, ushort16 c);
int __ovld __cnfn bitselect(int a, int b, int c);
uint __ovld __cnfn bitselect(uint a, uint b, uint c);
int2 __ovld __cnfn bitselect(int2 a, int2 b, int2 c);
uint2 __ovld __cnfn bitselect(uint2 a, uint2 b, uint2 c);
int3 __ovld __cnfn bitselect(int3 a, int3 b, int3 c);
uint3 __ovld __cnfn bitselect(uint3 a, uint3 b, uint3 c);
int4 __ovld __cnfn bitselect(int4 a, int4 b, int4 c);
uint4 __ovld __cnfn bitselect(uint4 a, uint4 b, uint4 c);
int8 __ovld __cnfn bitselect(int8 a, int8 b, int8 c);
uint8 __ovld __cnfn bitselect(uint8 a, uint8 b, uint8 c);
int16 __ovld __cnfn bitselect(int16 a, int16 b, int16 c);
uint16 __ovld __cnfn bitselect(uint16 a, uint16 b, uint16 c);
long __ovld __cnfn bitselect(long a, long b, long c);
ulong __ovld __cnfn bitselect(ulong a, ulong b, ulong c);
long2 __ovld __cnfn bitselect(long2 a, long2 b, long2 c);
ulong2 __ovld __cnfn bitselect(ulong2 a, ulong2 b, ulong2 c);
long3 __ovld __cnfn bitselect(long3 a, long3 b, long3 c);
ulong3 __ovld __cnfn bitselect(ulong3 a, ulong3 b, ulong3 c);
long4 __ovld __cnfn bitselect(long4 a, long4 b, long4 c);
ulong4 __ovld __cnfn bitselect(ulong4 a, ulong4 b, ulong4 c);
long8 __ovld __cnfn bitselect(long8 a, long8 b, long8 c);
ulong8 __ovld __cnfn bitselect(ulong8 a, ulong8 b, ulong8 c);
long16 __ovld __cnfn bitselect(long16 a, long16 b, long16 c);
ulong16 __ovld __cnfn bitselect(ulong16 a, ulong16 b, ulong16 c);
float __ovld __cnfn bitselect(float a, float b, float c);
float2 __ovld __cnfn bitselect(float2 a, float2 b, float2 c);
float3 __ovld __cnfn bitselect(float3 a, float3 b, float3 c);
float4 __ovld __cnfn bitselect(float4 a, float4 b, float4 c);
float8 __ovld __cnfn bitselect(float8 a, float8 b, float8 c);
float16 __ovld __cnfn bitselect(float16 a, float16 b, float16 c);
#ifdef cl_khr_fp64
double __ovld __cnfn bitselect(double a, double b, double c);
double2 __ovld __cnfn bitselect(double2 a, double2 b, double2 c);
double3 __ovld __cnfn bitselect(double3 a, double3 b, double3 c);
double4 __ovld __cnfn bitselect(double4 a, double4 b, double4 c);
double8 __ovld __cnfn bitselect(double8 a, double8 b, double8 c);
double16 __ovld __cnfn bitselect(double16 a, double16 b, double16 c);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn bitselect(half a, half b, half c);
half2 __ovld __cnfn bitselect(half2 a, half2 b, half2 c);
half3 __ovld __cnfn bitselect(half3 a, half3 b, half3 c);
half4 __ovld __cnfn bitselect(half4 a, half4 b, half4 c);
half8 __ovld __cnfn bitselect(half8 a, half8 b, half8 c);
half16 __ovld __cnfn bitselect(half16 a, half16 b, half16 c);
#endif //cl_khr_fp16

/**
 * For each component of a vector type,
 * result[i] = if MSB of c[i] is set ? b[i] : a[i].
 * For a scalar type, result = c ? b : a.
 */
char __ovld __cnfn select(char a, char b, char c);
uchar __ovld __cnfn select(uchar a, uchar b, char c);
char2 __ovld __cnfn select(char2 a, char2 b, char2 c);
uchar2 __ovld __cnfn select(uchar2 a, uchar2 b, char2 c);
char3 __ovld __cnfn select(char3 a, char3 b, char3 c);
uchar3 __ovld __cnfn select(uchar3 a, uchar3 b, char3 c);
char4 __ovld __cnfn select(char4 a, char4 b, char4 c);
uchar4 __ovld __cnfn select(uchar4 a, uchar4 b, char4 c);
char8 __ovld __cnfn select(char8 a, char8 b, char8 c);
uchar8 __ovld __cnfn select(uchar8 a, uchar8 b, char8 c);
char16 __ovld __cnfn select(char16 a, char16 b, char16 c);
uchar16 __ovld __cnfn select(uchar16 a, uchar16 b, char16 c);
short __ovld __cnfn select(short a, short b, char c);
ushort __ovld __cnfn select(ushort a, ushort b, char c);
short2 __ovld __cnfn select(short2 a, short2 b, char2 c);
ushort2 __ovld __cnfn select(ushort2 a, ushort2 b, char2 c);
short3 __ovld __cnfn select(short3 a, short3 b, char3 c);
ushort3 __ovld __cnfn select(ushort3 a, ushort3 b, char3 c);
short4 __ovld __cnfn select(short4 a, short4 b, char4 c);
ushort4 __ovld __cnfn select(ushort4 a, ushort4 b, char4 c);
short8 __ovld __cnfn select(short8 a, short8 b, char8 c);
ushort8 __ovld __cnfn select(ushort8 a, ushort8 b, char8 c);
short16 __ovld __cnfn select(short16 a, short16 b, char16 c);
ushort16 __ovld __cnfn select(ushort16 a, ushort16 b, char16 c);
int __ovld __cnfn select(int a, int b, char c);
uint __ovld __cnfn select(uint a, uint b, char c);
int2 __ovld __cnfn select(int2 a, int2 b, char2 c);
uint2 __ovld __cnfn select(uint2 a, uint2 b, char2 c);
int3 __ovld __cnfn select(int3 a, int3 b, char3 c);
uint3 __ovld __cnfn select(uint3 a, uint3 b, char3 c);
int4 __ovld __cnfn select(int4 a, int4 b, char4 c);
uint4 __ovld __cnfn select(uint4 a, uint4 b, char4 c);
int8 __ovld __cnfn select(int8 a, int8 b, char8 c);
uint8 __ovld __cnfn select(uint8 a, uint8 b, char8 c);
int16 __ovld __cnfn select(int16 a, int16 b, char16 c);
uint16 __ovld __cnfn select(uint16 a, uint16 b, char16 c);
long __ovld __cnfn select(long a, long b, char c);
ulong __ovld __cnfn select(ulong a, ulong b, char c);
long2 __ovld __cnfn select(long2 a, long2 b, char2 c);
ulong2 __ovld __cnfn select(ulong2 a, ulong2 b, char2 c);
long3 __ovld __cnfn select(long3 a, long3 b, char3 c);
ulong3 __ovld __cnfn select(ulong3 a, ulong3 b, char3 c);
long4 __ovld __cnfn select(long4 a, long4 b, char4 c);
ulong4 __ovld __cnfn select(ulong4 a, ulong4 b, char4 c);
long8 __ovld __cnfn select(long8 a, long8 b, char8 c);
ulong8 __ovld __cnfn select(ulong8 a, ulong8 b, char8 c);
long16 __ovld __cnfn select(long16 a, long16 b, char16 c);
ulong16 __ovld __cnfn select(ulong16 a, ulong16 b, char16 c);
float __ovld __cnfn select(float a, float b, char c);
float2 __ovld __cnfn select(float2 a, float2 b, char2 c);
float3 __ovld __cnfn select(float3 a, float3 b, char3 c);
float4 __ovld __cnfn select(float4 a, float4 b, char4 c);
float8 __ovld __cnfn select(float8 a, float8 b, char8 c);
float16 __ovld __cnfn select(float16 a, float16 b, char16 c);
char __ovld __cnfn select(char a, char b, short c);
uchar __ovld __cnfn select(uchar a, uchar b, short c);
char2 __ovld __cnfn select(char2 a, char2 b, short2 c);
uchar2 __ovld __cnfn select(uchar2 a, uchar2 b, short2 c);
char3 __ovld __cnfn select(char3 a, char3 b, short3 c);
uchar3 __ovld __cnfn select(uchar3 a, uchar3 b, short3 c);
char4 __ovld __cnfn select(char4 a, char4 b, short4 c);
uchar4 __ovld __cnfn select(uchar4 a, uchar4 b, short4 c);
char8 __ovld __cnfn select(char8 a, char8 b, short8 c);
uchar8 __ovld __cnfn select(uchar8 a, uchar8 b, short8 c);
char16 __ovld __cnfn select(char16 a, char16 b, short16 c);
uchar16 __ovld __cnfn select(uchar16 a, uchar16 b, short16 c);
short __ovld __cnfn select(short a, short b, short c);
ushort __ovld __cnfn select(ushort a, ushort b, short c);
short2 __ovld __cnfn select(short2 a, short2 b, short2 c);
ushort2 __ovld __cnfn select(ushort2 a, ushort2 b, short2 c);
short3 __ovld __cnfn select(short3 a, short3 b, short3 c);
ushort3 __ovld __cnfn select(ushort3 a, ushort3 b, short3 c);
short4 __ovld __cnfn select(short4 a, short4 b, short4 c);
ushort4 __ovld __cnfn select(ushort4 a, ushort4 b, short4 c);
short8 __ovld __cnfn select(short8 a, short8 b, short8 c);
ushort8 __ovld __cnfn select(ushort8 a, ushort8 b, short8 c);
short16 __ovld __cnfn select(short16 a, short16 b, short16 c);
ushort16 __ovld __cnfn select(ushort16 a, ushort16 b, short16 c);
int __ovld __cnfn select(int a, int b, short c);
uint __ovld __cnfn select(uint a, uint b, short c);
int2 __ovld __cnfn select(int2 a, int2 b, short2 c);
uint2 __ovld __cnfn select(uint2 a, uint2 b, short2 c);
int3 __ovld __cnfn select(int3 a, int3 b, short3 c);
uint3 __ovld __cnfn select(uint3 a, uint3 b, short3 c);
int4 __ovld __cnfn select(int4 a, int4 b, short4 c);
uint4 __ovld __cnfn select(uint4 a, uint4 b, short4 c);
int8 __ovld __cnfn select(int8 a, int8 b, short8 c);
uint8 __ovld __cnfn select(uint8 a, uint8 b, short8 c);
int16 __ovld __cnfn select(int16 a, int16 b, short16 c);
uint16 __ovld __cnfn select(uint16 a, uint16 b, short16 c);
long __ovld __cnfn select(long a, long b, short c);
ulong __ovld __cnfn select(ulong a, ulong b, short c);
long2 __ovld __cnfn select(long2 a, long2 b, short2 c);
ulong2 __ovld __cnfn select(ulong2 a, ulong2 b, short2 c);
long3 __ovld __cnfn select(long3 a, long3 b, short3 c);
ulong3 __ovld __cnfn select(ulong3 a, ulong3 b, short3 c);
long4 __ovld __cnfn select(long4 a, long4 b, short4 c);
ulong4 __ovld __cnfn select(ulong4 a, ulong4 b, short4 c);
long8 __ovld __cnfn select(long8 a, long8 b, short8 c);
ulong8 __ovld __cnfn select(ulong8 a, ulong8 b, short8 c);
long16 __ovld __cnfn select(long16 a, long16 b, short16 c);
ulong16 __ovld __cnfn select(ulong16 a, ulong16 b, short16 c);
float __ovld __cnfn select(float a, float b, short c);
float2 __ovld __cnfn select(float2 a, float2 b, short2 c);
float3 __ovld __cnfn select(float3 a, float3 b, short3 c);
float4 __ovld __cnfn select(float4 a, float4 b, short4 c);
float8 __ovld __cnfn select(float8 a, float8 b, short8 c);
float16 __ovld __cnfn select(float16 a, float16 b, short16 c);
char __ovld __cnfn select(char a, char b, int c);
uchar __ovld __cnfn select(uchar a, uchar b, int c);
char2 __ovld __cnfn select(char2 a, char2 b, int2 c);
uchar2 __ovld __cnfn select(uchar2 a, uchar2 b, int2 c);
char3 __ovld __cnfn select(char3 a, char3 b, int3 c);
uchar3 __ovld __cnfn select(uchar3 a, uchar3 b, int3 c);
char4 __ovld __cnfn select(char4 a, char4 b, int4 c);
uchar4 __ovld __cnfn select(uchar4 a, uchar4 b, int4 c);
char8 __ovld __cnfn select(char8 a, char8 b, int8 c);
uchar8 __ovld __cnfn select(uchar8 a, uchar8 b, int8 c);
char16 __ovld __cnfn select(char16 a, char16 b, int16 c);
uchar16 __ovld __cnfn select(uchar16 a, uchar16 b, int16 c);
short __ovld __cnfn select(short a, short b, int c);
ushort __ovld __cnfn select(ushort a, ushort b, int c);
short2 __ovld __cnfn select(short2 a, short2 b, int2 c);
ushort2 __ovld __cnfn select(ushort2 a, ushort2 b, int2 c);
short3 __ovld __cnfn select(short3 a, short3 b, int3 c);
ushort3 __ovld __cnfn select(ushort3 a, ushort3 b, int3 c);
short4 __ovld __cnfn select(short4 a, short4 b, int4 c);
ushort4 __ovld __cnfn select(ushort4 a, ushort4 b, int4 c);
short8 __ovld __cnfn select(short8 a, short8 b, int8 c);
ushort8 __ovld __cnfn select(ushort8 a, ushort8 b, int8 c);
short16 __ovld __cnfn select(short16 a, short16 b, int16 c);
ushort16 __ovld __cnfn select(ushort16 a, ushort16 b, int16 c);
int __ovld __cnfn select(int a, int b, int c);
uint __ovld __cnfn select(uint a, uint b, int c);
int2 __ovld __cnfn select(int2 a, int2 b, int2 c);
uint2 __ovld __cnfn select(uint2 a, uint2 b, int2 c);
int3 __ovld __cnfn select(int3 a, int3 b, int3 c);
uint3 __ovld __cnfn select(uint3 a, uint3 b, int3 c);
int4 __ovld __cnfn select(int4 a, int4 b, int4 c);
uint4 __ovld __cnfn select(uint4 a, uint4 b, int4 c);
int8 __ovld __cnfn select(int8 a, int8 b, int8 c);
uint8 __ovld __cnfn select(uint8 a, uint8 b, int8 c);
int16 __ovld __cnfn select(int16 a, int16 b, int16 c);
uint16 __ovld __cnfn select(uint16 a, uint16 b, int16 c);
long __ovld __cnfn select(long a, long b, int c);
ulong __ovld __cnfn select(ulong a, ulong b, int c);
long2 __ovld __cnfn select(long2 a, long2 b, int2 c);
ulong2 __ovld __cnfn select(ulong2 a, ulong2 b, int2 c);
long3 __ovld __cnfn select(long3 a, long3 b, int3 c);
ulong3 __ovld __cnfn select(ulong3 a, ulong3 b, int3 c);
long4 __ovld __cnfn select(long4 a, long4 b, int4 c);
ulong4 __ovld __cnfn select(ulong4 a, ulong4 b, int4 c);
long8 __ovld __cnfn select(long8 a, long8 b, int8 c);
ulong8 __ovld __cnfn select(ulong8 a, ulong8 b, int8 c);
long16 __ovld __cnfn select(long16 a, long16 b, int16 c);
ulong16 __ovld __cnfn select(ulong16 a, ulong16 b, int16 c);
float __ovld __cnfn select(float a, float b, int c);
float2 __ovld __cnfn select(float2 a, float2 b, int2 c);
float3 __ovld __cnfn select(float3 a, float3 b, int3 c);
float4 __ovld __cnfn select(float4 a, float4 b, int4 c);
float8 __ovld __cnfn select(float8 a, float8 b, int8 c);
float16 __ovld __cnfn select(float16 a, float16 b, int16 c);
char __ovld __cnfn select(char a, char b, long c);
uchar __ovld __cnfn select(uchar a, uchar b, long c);
char2 __ovld __cnfn select(char2 a, char2 b, long2 c);
uchar2 __ovld __cnfn select(uchar2 a, uchar2 b, long2 c);
char3 __ovld __cnfn select(char3 a, char3 b, long3 c);
uchar3 __ovld __cnfn select(uchar3 a, uchar3 b, long3 c);
char4 __ovld __cnfn select(char4 a, char4 b, long4 c);
uchar4 __ovld __cnfn select(uchar4 a, uchar4 b, long4 c);
char8 __ovld __cnfn select(char8 a, char8 b, long8 c);
uchar8 __ovld __cnfn select(uchar8 a, uchar8 b, long8 c);
char16 __ovld __cnfn select(char16 a, char16 b, long16 c);
uchar16 __ovld __cnfn select(uchar16 a, uchar16 b, long16 c);
short __ovld __cnfn select(short a, short b, long c);
ushort __ovld __cnfn select(ushort a, ushort b, long c);
short2 __ovld __cnfn select(short2 a, short2 b, long2 c);
ushort2 __ovld __cnfn select(ushort2 a, ushort2 b, long2 c);
short3 __ovld __cnfn select(short3 a, short3 b, long3 c);
ushort3 __ovld __cnfn select(ushort3 a, ushort3 b, long3 c);
short4 __ovld __cnfn select(short4 a, short4 b, long4 c);
ushort4 __ovld __cnfn select(ushort4 a, ushort4 b, long4 c);
short8 __ovld __cnfn select(short8 a, short8 b, long8 c);
ushort8 __ovld __cnfn select(ushort8 a, ushort8 b, long8 c);
short16 __ovld __cnfn select(short16 a, short16 b, long16 c);
ushort16 __ovld __cnfn select(ushort16 a, ushort16 b, long16 c);
int __ovld __cnfn select(int a, int b, long c);
uint __ovld __cnfn select(uint a, uint b, long c);
int2 __ovld __cnfn select(int2 a, int2 b, long2 c);
uint2 __ovld __cnfn select(uint2 a, uint2 b, long2 c);
int3 __ovld __cnfn select(int3 a, int3 b, long3 c);
uint3 __ovld __cnfn select(uint3 a, uint3 b, long3 c);
int4 __ovld __cnfn select(int4 a, int4 b, long4 c);
uint4 __ovld __cnfn select(uint4 a, uint4 b, long4 c);
int8 __ovld __cnfn select(int8 a, int8 b, long8 c);
uint8 __ovld __cnfn select(uint8 a, uint8 b, long8 c);
int16 __ovld __cnfn select(int16 a, int16 b, long16 c);
uint16 __ovld __cnfn select(uint16 a, uint16 b, long16 c);
long __ovld __cnfn select(long a, long b, long c);
ulong __ovld __cnfn select(ulong a, ulong b, long c);
long2 __ovld __cnfn select(long2 a, long2 b, long2 c);
ulong2 __ovld __cnfn select(ulong2 a, ulong2 b, long2 c);
long3 __ovld __cnfn select(long3 a, long3 b, long3 c);
ulong3 __ovld __cnfn select(ulong3 a, ulong3 b, long3 c);
long4 __ovld __cnfn select(long4 a, long4 b, long4 c);
ulong4 __ovld __cnfn select(ulong4 a, ulong4 b, long4 c);
long8 __ovld __cnfn select(long8 a, long8 b, long8 c);
ulong8 __ovld __cnfn select(ulong8 a, ulong8 b, long8 c);
long16 __ovld __cnfn select(long16 a, long16 b, long16 c);
ulong16 __ovld __cnfn select(ulong16 a, ulong16 b, long16 c);
float __ovld __cnfn select(float a, float b, long c);
float2 __ovld __cnfn select(float2 a, float2 b, long2 c);
float3 __ovld __cnfn select(float3 a, float3 b, long3 c);
float4 __ovld __cnfn select(float4 a, float4 b, long4 c);
float8 __ovld __cnfn select(float8 a, float8 b, long8 c);
float16 __ovld __cnfn select(float16 a, float16 b, long16 c);
char __ovld __cnfn select(char a, char b, uchar c);
uchar __ovld __cnfn select(uchar a, uchar b, uchar c);
char2 __ovld __cnfn select(char2 a, char2 b, uchar2 c);
uchar2 __ovld __cnfn select(uchar2 a, uchar2 b, uchar2 c);
char3 __ovld __cnfn select(char3 a, char3 b, uchar3 c);
uchar3 __ovld __cnfn select(uchar3 a, uchar3 b, uchar3 c);
char4 __ovld __cnfn select(char4 a, char4 b, uchar4 c);
uchar4 __ovld __cnfn select(uchar4 a, uchar4 b, uchar4 c);
char8 __ovld __cnfn select(char8 a, char8 b, uchar8 c);
uchar8 __ovld __cnfn select(uchar8 a, uchar8 b, uchar8 c);
char16 __ovld __cnfn select(char16 a, char16 b, uchar16 c);
uchar16 __ovld __cnfn select(uchar16 a, uchar16 b, uchar16 c);
short __ovld __cnfn select(short a, short b, uchar c);
ushort __ovld __cnfn select(ushort a, ushort b, uchar c);
short2 __ovld __cnfn select(short2 a, short2 b, uchar2 c);
ushort2 __ovld __cnfn select(ushort2 a, ushort2 b, uchar2 c);
short3 __ovld __cnfn select(short3 a, short3 b, uchar3 c);
ushort3 __ovld __cnfn select(ushort3 a, ushort3 b, uchar3 c);
short4 __ovld __cnfn select(short4 a, short4 b, uchar4 c);
ushort4 __ovld __cnfn select(ushort4 a, ushort4 b, uchar4 c);
short8 __ovld __cnfn select(short8 a, short8 b, uchar8 c);
ushort8 __ovld __cnfn select(ushort8 a, ushort8 b, uchar8 c);
short16 __ovld __cnfn select(short16 a, short16 b, uchar16 c);
ushort16 __ovld __cnfn select(ushort16 a, ushort16 b, uchar16 c);
int __ovld __cnfn select(int a, int b, uchar c);
uint __ovld __cnfn select(uint a, uint b, uchar c);
int2 __ovld __cnfn select(int2 a, int2 b, uchar2 c);
uint2 __ovld __cnfn select(uint2 a, uint2 b, uchar2 c);
int3 __ovld __cnfn select(int3 a, int3 b, uchar3 c);
uint3 __ovld __cnfn select(uint3 a, uint3 b, uchar3 c);
int4 __ovld __cnfn select(int4 a, int4 b, uchar4 c);
uint4 __ovld __cnfn select(uint4 a, uint4 b, uchar4 c);
int8 __ovld __cnfn select(int8 a, int8 b, uchar8 c);
uint8 __ovld __cnfn select(uint8 a, uint8 b, uchar8 c);
int16 __ovld __cnfn select(int16 a, int16 b, uchar16 c);
uint16 __ovld __cnfn select(uint16 a, uint16 b, uchar16 c);
long __ovld __cnfn select(long a, long b, uchar c);
ulong __ovld __cnfn select(ulong a, ulong b, uchar c);
long2 __ovld __cnfn select(long2 a, long2 b, uchar2 c);
ulong2 __ovld __cnfn select(ulong2 a, ulong2 b, uchar2 c);
long3 __ovld __cnfn select(long3 a, long3 b, uchar3 c);
ulong3 __ovld __cnfn select(ulong3 a, ulong3 b, uchar3 c);
long4 __ovld __cnfn select(long4 a, long4 b, uchar4 c);
ulong4 __ovld __cnfn select(ulong4 a, ulong4 b, uchar4 c);
long8 __ovld __cnfn select(long8 a, long8 b, uchar8 c);
ulong8 __ovld __cnfn select(ulong8 a, ulong8 b, uchar8 c);
long16 __ovld __cnfn select(long16 a, long16 b, uchar16 c);
ulong16 __ovld __cnfn select(ulong16 a, ulong16 b, uchar16 c);
float __ovld __cnfn select(float a, float b, uchar c);
float2 __ovld __cnfn select(float2 a, float2 b, uchar2 c);
float3 __ovld __cnfn select(float3 a, float3 b, uchar3 c);
float4 __ovld __cnfn select(float4 a, float4 b, uchar4 c);
float8 __ovld __cnfn select(float8 a, float8 b, uchar8 c);
float16 __ovld __cnfn select(float16 a, float16 b, uchar16 c);
char __ovld __cnfn select(char a, char b, ushort c);
uchar __ovld __cnfn select(uchar a, uchar b, ushort c);
char2 __ovld __cnfn select(char2 a, char2 b, ushort2 c);
uchar2 __ovld __cnfn select(uchar2 a, uchar2 b, ushort2 c);
char3 __ovld __cnfn select(char3 a, char3 b, ushort3 c);
uchar3 __ovld __cnfn select(uchar3 a, uchar3 b, ushort3 c);
char4 __ovld __cnfn select(char4 a, char4 b, ushort4 c);
uchar4 __ovld __cnfn select(uchar4 a, uchar4 b, ushort4 c);
char8 __ovld __cnfn select(char8 a, char8 b, ushort8 c);
uchar8 __ovld __cnfn select(uchar8 a, uchar8 b, ushort8 c);
char16 __ovld __cnfn select(char16 a, char16 b, ushort16 c);
uchar16 __ovld __cnfn select(uchar16 a, uchar16 b, ushort16 c);
short __ovld __cnfn select(short a, short b, ushort c);
ushort __ovld __cnfn select(ushort a, ushort b, ushort c);
short2 __ovld __cnfn select(short2 a, short2 b, ushort2 c);
ushort2 __ovld __cnfn select(ushort2 a, ushort2 b, ushort2 c);
short3 __ovld __cnfn select(short3 a, short3 b, ushort3 c);
ushort3 __ovld __cnfn select(ushort3 a, ushort3 b, ushort3 c);
short4 __ovld __cnfn select(short4 a, short4 b, ushort4 c);
ushort4 __ovld __cnfn select(ushort4 a, ushort4 b, ushort4 c);
short8 __ovld __cnfn select(short8 a, short8 b, ushort8 c);
ushort8 __ovld __cnfn select(ushort8 a, ushort8 b, ushort8 c);
short16 __ovld __cnfn select(short16 a, short16 b, ushort16 c);
ushort16 __ovld __cnfn select(ushort16 a, ushort16 b, ushort16 c);
int __ovld __cnfn select(int a, int b, ushort c);
uint __ovld __cnfn select(uint a, uint b, ushort c);
int2 __ovld __cnfn select(int2 a, int2 b, ushort2 c);
uint2 __ovld __cnfn select(uint2 a, uint2 b, ushort2 c);
int3 __ovld __cnfn select(int3 a, int3 b, ushort3 c);
uint3 __ovld __cnfn select(uint3 a, uint3 b, ushort3 c);
int4 __ovld __cnfn select(int4 a, int4 b, ushort4 c);
uint4 __ovld __cnfn select(uint4 a, uint4 b, ushort4 c);
int8 __ovld __cnfn select(int8 a, int8 b, ushort8 c);
uint8 __ovld __cnfn select(uint8 a, uint8 b, ushort8 c);
int16 __ovld __cnfn select(int16 a, int16 b, ushort16 c);
uint16 __ovld __cnfn select(uint16 a, uint16 b, ushort16 c);
long __ovld __cnfn select(long a, long b, ushort c);
ulong __ovld __cnfn select(ulong a, ulong b, ushort c);
long2 __ovld __cnfn select(long2 a, long2 b, ushort2 c);
ulong2 __ovld __cnfn select(ulong2 a, ulong2 b, ushort2 c);
long3 __ovld __cnfn select(long3 a, long3 b, ushort3 c);
ulong3 __ovld __cnfn select(ulong3 a, ulong3 b, ushort3 c);
long4 __ovld __cnfn select(long4 a, long4 b, ushort4 c);
ulong4 __ovld __cnfn select(ulong4 a, ulong4 b, ushort4 c);
long8 __ovld __cnfn select(long8 a, long8 b, ushort8 c);
ulong8 __ovld __cnfn select(ulong8 a, ulong8 b, ushort8 c);
long16 __ovld __cnfn select(long16 a, long16 b, ushort16 c);
ulong16 __ovld __cnfn select(ulong16 a, ulong16 b, ushort16 c);
float __ovld __cnfn select(float a, float b, ushort c);
float2 __ovld __cnfn select(float2 a, float2 b, ushort2 c);
float3 __ovld __cnfn select(float3 a, float3 b, ushort3 c);
float4 __ovld __cnfn select(float4 a, float4 b, ushort4 c);
float8 __ovld __cnfn select(float8 a, float8 b, ushort8 c);
float16 __ovld __cnfn select(float16 a, float16 b, ushort16 c);
char __ovld __cnfn select(char a, char b, uint c);
uchar __ovld __cnfn select(uchar a, uchar b, uint c);
char2 __ovld __cnfn select(char2 a, char2 b, uint2 c);
uchar2 __ovld __cnfn select(uchar2 a, uchar2 b, uint2 c);
char3 __ovld __cnfn select(char3 a, char3 b, uint3 c);
uchar3 __ovld __cnfn select(uchar3 a, uchar3 b, uint3 c);
char4 __ovld __cnfn select(char4 a, char4 b, uint4 c);
uchar4 __ovld __cnfn select(uchar4 a, uchar4 b, uint4 c);
char8 __ovld __cnfn select(char8 a, char8 b, uint8 c);
uchar8 __ovld __cnfn select(uchar8 a, uchar8 b, uint8 c);
char16 __ovld __cnfn select(char16 a, char16 b, uint16 c);
uchar16 __ovld __cnfn select(uchar16 a, uchar16 b, uint16 c);
short __ovld __cnfn select(short a, short b, uint c);
ushort __ovld __cnfn select(ushort a, ushort b, uint c);
short2 __ovld __cnfn select(short2 a, short2 b, uint2 c);
ushort2 __ovld __cnfn select(ushort2 a, ushort2 b, uint2 c);
short3 __ovld __cnfn select(short3 a, short3 b, uint3 c);
ushort3 __ovld __cnfn select(ushort3 a, ushort3 b, uint3 c);
short4 __ovld __cnfn select(short4 a, short4 b, uint4 c);
ushort4 __ovld __cnfn select(ushort4 a, ushort4 b, uint4 c);
short8 __ovld __cnfn select(short8 a, short8 b, uint8 c);
ushort8 __ovld __cnfn select(ushort8 a, ushort8 b, uint8 c);
short16 __ovld __cnfn select(short16 a, short16 b, uint16 c);
ushort16 __ovld __cnfn select(ushort16 a, ushort16 b, uint16 c);
int __ovld __cnfn select(int a, int b, uint c);
uint __ovld __cnfn select(uint a, uint b, uint c);
int2 __ovld __cnfn select(int2 a, int2 b, uint2 c);
uint2 __ovld __cnfn select(uint2 a, uint2 b, uint2 c);
int3 __ovld __cnfn select(int3 a, int3 b, uint3 c);
uint3 __ovld __cnfn select(uint3 a, uint3 b, uint3 c);
int4 __ovld __cnfn select(int4 a, int4 b, uint4 c);
uint4 __ovld __cnfn select(uint4 a, uint4 b, uint4 c);
int8 __ovld __cnfn select(int8 a, int8 b, uint8 c);
uint8 __ovld __cnfn select(uint8 a, uint8 b, uint8 c);
int16 __ovld __cnfn select(int16 a, int16 b, uint16 c);
uint16 __ovld __cnfn select(uint16 a, uint16 b, uint16 c);
long __ovld __cnfn select(long a, long b, uint c);
ulong __ovld __cnfn select(ulong a, ulong b, uint c);
long2 __ovld __cnfn select(long2 a, long2 b, uint2 c);
ulong2 __ovld __cnfn select(ulong2 a, ulong2 b, uint2 c);
long3 __ovld __cnfn select(long3 a, long3 b, uint3 c);
ulong3 __ovld __cnfn select(ulong3 a, ulong3 b, uint3 c);
long4 __ovld __cnfn select(long4 a, long4 b, uint4 c);
ulong4 __ovld __cnfn select(ulong4 a, ulong4 b, uint4 c);
long8 __ovld __cnfn select(long8 a, long8 b, uint8 c);
ulong8 __ovld __cnfn select(ulong8 a, ulong8 b, uint8 c);
long16 __ovld __cnfn select(long16 a, long16 b, uint16 c);
ulong16 __ovld __cnfn select(ulong16 a, ulong16 b, uint16 c);
float __ovld __cnfn select(float a, float b, uint c);
float2 __ovld __cnfn select(float2 a, float2 b, uint2 c);
float3 __ovld __cnfn select(float3 a, float3 b, uint3 c);
float4 __ovld __cnfn select(float4 a, float4 b, uint4 c);
float8 __ovld __cnfn select(float8 a, float8 b, uint8 c);
float16 __ovld __cnfn select(float16 a, float16 b, uint16 c);
char __ovld __cnfn select(char a, char b, ulong c);
uchar __ovld __cnfn select(uchar a, uchar b, ulong c);
char2 __ovld __cnfn select(char2 a, char2 b, ulong2 c);
uchar2 __ovld __cnfn select(uchar2 a, uchar2 b, ulong2 c);
char3 __ovld __cnfn select(char3 a, char3 b, ulong3 c);
uchar3 __ovld __cnfn select(uchar3 a, uchar3 b, ulong3 c);
char4 __ovld __cnfn select(char4 a, char4 b, ulong4 c);
uchar4 __ovld __cnfn select(uchar4 a, uchar4 b, ulong4 c);
char8 __ovld __cnfn select(char8 a, char8 b, ulong8 c);
uchar8 __ovld __cnfn select(uchar8 a, uchar8 b, ulong8 c);
char16 __ovld __cnfn select(char16 a, char16 b, ulong16 c);
uchar16 __ovld __cnfn select(uchar16 a, uchar16 b, ulong16 c);
short __ovld __cnfn select(short a, short b, ulong c);
ushort __ovld __cnfn select(ushort a, ushort b, ulong c);
short2 __ovld __cnfn select(short2 a, short2 b, ulong2 c);
ushort2 __ovld __cnfn select(ushort2 a, ushort2 b, ulong2 c);
short3 __ovld __cnfn select(short3 a, short3 b, ulong3 c);
ushort3 __ovld __cnfn select(ushort3 a, ushort3 b, ulong3 c);
short4 __ovld __cnfn select(short4 a, short4 b, ulong4 c);
ushort4 __ovld __cnfn select(ushort4 a, ushort4 b, ulong4 c);
short8 __ovld __cnfn select(short8 a, short8 b, ulong8 c);
ushort8 __ovld __cnfn select(ushort8 a, ushort8 b, ulong8 c);
short16 __ovld __cnfn select(short16 a, short16 b, ulong16 c);
ushort16 __ovld __cnfn select(ushort16 a, ushort16 b, ulong16 c);
int __ovld __cnfn select(int a, int b, ulong c);
uint __ovld __cnfn select(uint a, uint b, ulong c);
int2 __ovld __cnfn select(int2 a, int2 b, ulong2 c);
uint2 __ovld __cnfn select(uint2 a, uint2 b, ulong2 c);
int3 __ovld __cnfn select(int3 a, int3 b, ulong3 c);
uint3 __ovld __cnfn select(uint3 a, uint3 b, ulong3 c);
int4 __ovld __cnfn select(int4 a, int4 b, ulong4 c);
uint4 __ovld __cnfn select(uint4 a, uint4 b, ulong4 c);
int8 __ovld __cnfn select(int8 a, int8 b, ulong8 c);
uint8 __ovld __cnfn select(uint8 a, uint8 b, ulong8 c);
int16 __ovld __cnfn select(int16 a, int16 b, ulong16 c);
uint16 __ovld __cnfn select(uint16 a, uint16 b, ulong16 c);
long __ovld __cnfn select(long a, long b, ulong c);
ulong __ovld __cnfn select(ulong a, ulong b, ulong c);
long2 __ovld __cnfn select(long2 a, long2 b, ulong2 c);
ulong2 __ovld __cnfn select(ulong2 a, ulong2 b, ulong2 c);
long3 __ovld __cnfn select(long3 a, long3 b, ulong3 c);
ulong3 __ovld __cnfn select(ulong3 a, ulong3 b, ulong3 c);
long4 __ovld __cnfn select(long4 a, long4 b, ulong4 c);
ulong4 __ovld __cnfn select(ulong4 a, ulong4 b, ulong4 c);
long8 __ovld __cnfn select(long8 a, long8 b, ulong8 c);
ulong8 __ovld __cnfn select(ulong8 a, ulong8 b, ulong8 c);
long16 __ovld __cnfn select(long16 a, long16 b, ulong16 c);
ulong16 __ovld __cnfn select(ulong16 a, ulong16 b, ulong16 c);
float __ovld __cnfn select(float a, float b, ulong c);
float2 __ovld __cnfn select(float2 a, float2 b, ulong2 c);
float3 __ovld __cnfn select(float3 a, float3 b, ulong3 c);
float4 __ovld __cnfn select(float4 a, float4 b, ulong4 c);
float8 __ovld __cnfn select(float8 a, float8 b, ulong8 c);
float16 __ovld __cnfn select(float16 a, float16 b, ulong16 c);
#ifdef cl_khr_fp64
double __ovld __cnfn select(double a, double b, long c);
double2 __ovld __cnfn select(double2 a, double2 b, long2 c);
double3 __ovld __cnfn select(double3 a, double3 b, long3 c);
double4 __ovld __cnfn select(double4 a, double4 b, long4 c);
double8 __ovld __cnfn select(double8 a, double8 b, long8 c);
double16 __ovld __cnfn select(double16 a, double16 b, long16 c);
double __ovld __cnfn select(double a, double b, ulong c);
double2 __ovld __cnfn select(double2 a, double2 b, ulong2 c);
double3 __ovld __cnfn select(double3 a, double3 b, ulong3 c);
double4 __ovld __cnfn select(double4 a, double4 b, ulong4 c);
double8 __ovld __cnfn select(double8 a, double8 b, ulong8 c);
double16 __ovld __cnfn select(double16 a, double16 b, ulong16 c);
#endif //cl_khr_fp64
#ifdef cl_khr_fp16
half __ovld __cnfn select(half a, half b, short c);
half2 __ovld __cnfn select(half2 a, half2 b, short2 c);
half3 __ovld __cnfn select(half3 a, half3 b, short3 c);
half4 __ovld __cnfn select(half4 a, half4 b, short4 c);
half8 __ovld __cnfn select(half8 a, half8 b, short8 c);
half16 __ovld __cnfn select(half16 a, half16 b, short16 c);
half __ovld __cnfn select(half a, half b, ushort c);
half2 __ovld __cnfn select(half2 a, half2 b, ushort2 c);
half3 __ovld __cnfn select(half3 a, half3 b, ushort3 c);
half4 __ovld __cnfn select(half4 a, half4 b, ushort4 c);
half8 __ovld __cnfn select(half8 a, half8 b, ushort8 c);
half16 __ovld __cnfn select(half16 a, half16 b, ushort16 c);
#endif //cl_khr_fp16

// OpenCL v1.1 s6.11.8, v1.2 s6.12.8, v2.0 s6.13.8 - Synchronization Functions

/**
 * Queue a memory fence to ensure correct
 * ordering of memory operations to local memory
 */
#define CLK_LOCAL_MEM_FENCE    0x01

/**
 * Queue a memory fence to ensure correct
 * ordering of memory operations to global memory
 */
#define CLK_GLOBAL_MEM_FENCE   0x02

/**
 * Queue a memory fence to ensure correct
 * ordering of memory operations to channel
 */
#define CLK_CHANNEL_MEM_FENCE  0x04

/**
 * All work-items in a work-group executing the kernel
 * on a processor must execute this function before any
 * are allowed to continue execution beyond the barrier.
 * This function must be encountered by all work-items in
 * a work-group executing the kernel.
 * If barrier is inside a conditional statement, then all
 * work-items must enter the conditional if any work-item
 * enters the conditional statement and executes the
 * barrier.
 * If barrer is inside a loop, all work-items must execute
 * the barrier for each iteration of the loop before any are
 * allowed to continue execution beyond the barrier.
 * The barrier function also queues a memory fence
 * (reads and writes) to ensure correct ordering of
 * memory operations to local or global memory.
 * The flags argument specifies the memory address space
 * and can be set to a combination of the following literal
 * values.
 * CLK_LOCAL_MEM_FENCE - The barrier function
 * will either flush any variables stored in local memory
 * or queue a memory fence to ensure correct ordering of
 * memory operations to local memory.
 * CLK_GLOBAL_MEM_FENCE - The barrier function
 * will queue a memory fence to ensure correct ordering
 * of memory operations to global memory. This can be
 * useful when work-items, for example, write to buffer or
 * image objects and then want to read the updated data.
 * CLK_CHANNEL_MEM_FENCE - The barrier function
 * will queue a memory fence to ensure correct ordering of
 * channel operations. For example one can use it with CLK_GLOBAL_MEM_FENCE,
 * so a call can't start until the global memory operation
 * is committed to the shared memory buffer.
 */

void __ovld __conv barrier(cl_mem_fence_flags flags);

// OpenCL v1.1 s6.11.9, v1.2 s6.12.9 - Explicit Memory Fence Functions

/**
 * Orders loads and stores of a work-item
 * executing a kernel. This means that loads
 * and stores preceding the mem_fence will
 * be committed to memory before any loads
 * and stores following the mem_fence.
 * The flags argument specifies the memory
 * address space and can be set to a
 * combination of the following literal
 * values:
 * CLK_LOCAL_MEM_FENCE
 * CLK_GLOBAL_MEM_FENCE
 * CLK_CHANNEL_MEM_FENCE.
 */
void __ovld mem_fence(cl_mem_fence_flags flags);

/**
 * Read memory barrier that orders only
 * loads.
 * The flags argument specifies the memory
 * address space and can be set to to a
 * combination of the following literal
 * values:
 * CLK_LOCAL_MEM_FENCE
 * CLK_GLOBAL_MEM_FENCE
 * CLK_CHANNEL_MEM_FENCE.
 */
void __ovld read_mem_fence(cl_mem_fence_flags flags);

/**
 * Write memory barrier that orders only
 * stores.
 * The flags argument specifies the memory
 * address space and can be set to to a
 * combination of the following literal
 * values:
 * CLK_LOCAL_MEM_FENCE
 * CLK_GLOBAL_MEM_FENCE
 * CLK_CHANNEL_MEM_FENCE.
 */
void __ovld write_mem_fence(cl_mem_fence_flags flags);

// OpenCL v1.1 s6.11.12, v1.2 s6.12.12, v2.0 s6.13.12 - Miscellaneous Vector Functions

/**
 * The shuffle and shuffle2 built-in functions construct
 * a permutation of elements from one or two input
 * vectors respectively that are of the same type,
 * returning a vector with the same element type as the
 * input and length that is the same as the shuffle mask.
 * The size of each element in the mask must match the
 * size of each element in the result. For shuffle, only
 * the ilogb(2m-1) least significant bits of each mask
 * element are considered. For shuffle2, only the
 * ilogb(2m-1)+1 least significant bits of each mask
 * element are considered. Other bits in the mask shall
 * be ignored.
 * The elements of the input vectors are numbered from
 * left to right across one or both of the vectors. For this
 * purpose, the number of elements in a vector is given
 * by vec_step(gentypem). The shuffle mask operand
 * specifies, for each element of the result vector, which
 * element of the one or two input vectors the result
 * element gets.
 * Examples:
 * uint4 mask = (uint4)(3, 2,
 * 1, 0);
 * float4 a;
 * float4 r = shuffle(a, mask);
 * // r.s0123 = a.wzyx
 * uint8 mask = (uint8)(0, 1, 2, 3,
 * 4, 5, 6, 7);
 * float4 a, b;
 * float8 r = shuffle2(a, b, mask);
 * // r.s0123 = a.xyzw
 * // r.s4567 = b.xyzw
 * uint4 mask;
 * float8 a;
 * float4 b;
 * b = shuffle(a, mask);
 * Examples that are not valid are:
 * uint8 mask;
 * short16 a;
 * short8 b;
 * b = shuffle(a, mask); <- not valid
 */
char2 __ovld __cnfn shuffle(char2 x, uchar2 mask);
char2 __ovld __cnfn shuffle(char4 x, uchar2 mask);
char2 __ovld __cnfn shuffle(char8 x, uchar2 mask);
char2 __ovld __cnfn shuffle(char16 x, uchar2 mask);

uchar2 __ovld __cnfn shuffle(uchar2 x, uchar2 mask);
uchar2 __ovld __cnfn shuffle(uchar4 x, uchar2 mask);
uchar2 __ovld __cnfn shuffle(uchar8 x, uchar2 mask);
uchar2 __ovld __cnfn shuffle(uchar16 x, uchar2 mask);

short2 __ovld __cnfn shuffle(short2 x, ushort2 mask);
short2 __ovld __cnfn shuffle(short4 x, ushort2 mask);
short2 __ovld __cnfn shuffle(short8 x, ushort2 mask);
short2 __ovld __cnfn shuffle(short16 x, ushort2 mask);

ushort2 __ovld __cnfn shuffle(ushort2 x, ushort2 mask);
ushort2 __ovld __cnfn shuffle(ushort4 x, ushort2 mask);
ushort2 __ovld __cnfn shuffle(ushort8 x, ushort2 mask);
ushort2 __ovld __cnfn shuffle(ushort16 x, ushort2 mask);

int2 __ovld __cnfn shuffle(int2 x, uint2 mask);
int2 __ovld __cnfn shuffle(int4 x, uint2 mask);
int2 __ovld __cnfn shuffle(int8 x, uint2 mask);
int2 __ovld __cnfn shuffle(int16 x, uint2 mask);

uint2 __ovld __cnfn shuffle(uint2 x, uint2 mask);
uint2 __ovld __cnfn shuffle(uint4 x, uint2 mask);
uint2 __ovld __cnfn shuffle(uint8 x, uint2 mask);
uint2 __ovld __cnfn shuffle(uint16 x, uint2 mask);

long2 __ovld __cnfn shuffle(long2 x, ulong2 mask);
long2 __ovld __cnfn shuffle(long4 x, ulong2 mask);
long2 __ovld __cnfn shuffle(long8 x, ulong2 mask);
long2 __ovld __cnfn shuffle(long16 x, ulong2 mask);

ulong2 __ovld __cnfn shuffle(ulong2 x, ulong2 mask);
ulong2 __ovld __cnfn shuffle(ulong4 x, ulong2 mask);
ulong2 __ovld __cnfn shuffle(ulong8 x, ulong2 mask);
ulong2 __ovld __cnfn shuffle(ulong16 x, ulong2 mask);

float2 __ovld __cnfn shuffle(float2 x, uint2 mask);
float2 __ovld __cnfn shuffle(float4 x, uint2 mask);
float2 __ovld __cnfn shuffle(float8 x, uint2 mask);
float2 __ovld __cnfn shuffle(float16 x, uint2 mask);

char4 __ovld __cnfn shuffle(char2 x, uchar4 mask);
char4 __ovld __cnfn shuffle(char4 x, uchar4 mask);
char4 __ovld __cnfn shuffle(char8 x, uchar4 mask);
char4 __ovld __cnfn shuffle(char16 x, uchar4 mask);

uchar4 __ovld __cnfn shuffle(uchar2 x, uchar4 mask);
uchar4 __ovld __cnfn shuffle(uchar4 x, uchar4 mask);
uchar4 __ovld __cnfn shuffle(uchar8 x, uchar4 mask);
uchar4 __ovld __cnfn shuffle(uchar16 x, uchar4 mask);

short4 __ovld __cnfn shuffle(short2 x, ushort4 mask);
short4 __ovld __cnfn shuffle(short4 x, ushort4 mask);
short4 __ovld __cnfn shuffle(short8 x, ushort4 mask);
short4 __ovld __cnfn shuffle(short16 x, ushort4 mask);

ushort4 __ovld __cnfn shuffle(ushort2 x, ushort4 mask);
ushort4 __ovld __cnfn shuffle(ushort4 x, ushort4 mask);
ushort4 __ovld __cnfn shuffle(ushort8 x, ushort4 mask);
ushort4 __ovld __cnfn shuffle(ushort16 x, ushort4 mask);

int4 __ovld __cnfn shuffle(int2 x, uint4 mask);
int4 __ovld __cnfn shuffle(int4 x, uint4 mask);
int4 __ovld __cnfn shuffle(int8 x, uint4 mask);
int4 __ovld __cnfn shuffle(int16 x, uint4 mask);

uint4 __ovld __cnfn shuffle(uint2 x, uint4 mask);
uint4 __ovld __cnfn shuffle(uint4 x, uint4 mask);
uint4 __ovld __cnfn shuffle(uint8 x, uint4 mask);
uint4 __ovld __cnfn shuffle(uint16 x, uint4 mask);

long4 __ovld __cnfn shuffle(long2 x, ulong4 mask);
long4 __ovld __cnfn shuffle(long4 x, ulong4 mask);
long4 __ovld __cnfn shuffle(long8 x, ulong4 mask);
long4 __ovld __cnfn shuffle(long16 x, ulong4 mask);

ulong4 __ovld __cnfn shuffle(ulong2 x, ulong4 mask);
ulong4 __ovld __cnfn shuffle(ulong4 x, ulong4 mask);
ulong4 __ovld __cnfn shuffle(ulong8 x, ulong4 mask);
ulong4 __ovld __cnfn shuffle(ulong16 x, ulong4 mask);

float4 __ovld __cnfn shuffle(float2 x, uint4 mask);
float4 __ovld __cnfn shuffle(float4 x, uint4 mask);
float4 __ovld __cnfn shuffle(float8 x, uint4 mask);
float4 __ovld __cnfn shuffle(float16 x, uint4 mask);

char8 __ovld __cnfn shuffle(char2 x, uchar8 mask);
char8 __ovld __cnfn shuffle(char4 x, uchar8 mask);
char8 __ovld __cnfn shuffle(char8 x, uchar8 mask);
char8 __ovld __cnfn shuffle(char16 x, uchar8 mask);

uchar8 __ovld __cnfn shuffle(uchar2 x, uchar8 mask);
uchar8 __ovld __cnfn shuffle(uchar4 x, uchar8 mask);
uchar8 __ovld __cnfn shuffle(uchar8 x, uchar8 mask);
uchar8 __ovld __cnfn shuffle(uchar16 x, uchar8 mask);

short8 __ovld __cnfn shuffle(short2 x, ushort8 mask);
short8 __ovld __cnfn shuffle(short4 x, ushort8 mask);
short8 __ovld __cnfn shuffle(short8 x, ushort8 mask);
short8 __ovld __cnfn shuffle(short16 x, ushort8 mask);

ushort8 __ovld __cnfn shuffle(ushort2 x, ushort8 mask);
ushort8 __ovld __cnfn shuffle(ushort4 x, ushort8 mask);
ushort8 __ovld __cnfn shuffle(ushort8 x, ushort8 mask);
ushort8 __ovld __cnfn shuffle(ushort16 x, ushort8 mask);

int8 __ovld __cnfn shuffle(int2 x, uint8 mask);
int8 __ovld __cnfn shuffle(int4 x, uint8 mask);
int8 __ovld __cnfn shuffle(int8 x, uint8 mask);
int8 __ovld __cnfn shuffle(int16 x, uint8 mask);

uint8 __ovld __cnfn shuffle(uint2 x, uint8 mask);
uint8 __ovld __cnfn shuffle(uint4 x, uint8 mask);
uint8 __ovld __cnfn shuffle(uint8 x, uint8 mask);
uint8 __ovld __cnfn shuffle(uint16 x, uint8 mask);

long8 __ovld __cnfn shuffle(long2 x, ulong8 mask);
long8 __ovld __cnfn shuffle(long4 x, ulong8 mask);
long8 __ovld __cnfn shuffle(long8 x, ulong8 mask);
long8 __ovld __cnfn shuffle(long16 x, ulong8 mask);

ulong8 __ovld __cnfn shuffle(ulong2 x, ulong8 mask);
ulong8 __ovld __cnfn shuffle(ulong4 x, ulong8 mask);
ulong8 __ovld __cnfn shuffle(ulong8 x, ulong8 mask);
ulong8 __ovld __cnfn shuffle(ulong16 x, ulong8 mask);

float8 __ovld __cnfn shuffle(float2 x, uint8 mask);
float8 __ovld __cnfn shuffle(float4 x, uint8 mask);
float8 __ovld __cnfn shuffle(float8 x, uint8 mask);
float8 __ovld __cnfn shuffle(float16 x, uint8 mask);

char16 __ovld __cnfn shuffle(char2 x, uchar16 mask);
char16 __ovld __cnfn shuffle(char4 x, uchar16 mask);
char16 __ovld __cnfn shuffle(char8 x, uchar16 mask);
char16 __ovld __cnfn shuffle(char16 x, uchar16 mask);

uchar16 __ovld __cnfn shuffle(uchar2 x, uchar16 mask);
uchar16 __ovld __cnfn shuffle(uchar4 x, uchar16 mask);
uchar16 __ovld __cnfn shuffle(uchar8 x, uchar16 mask);
uchar16 __ovld __cnfn shuffle(uchar16 x, uchar16 mask);

short16 __ovld __cnfn shuffle(short2 x, ushort16 mask);
short16 __ovld __cnfn shuffle(short4 x, ushort16 mask);
short16 __ovld __cnfn shuffle(short8 x, ushort16 mask);
short16 __ovld __cnfn shuffle(short16 x, ushort16 mask);

ushort16 __ovld __cnfn shuffle(ushort2 x, ushort16 mask);
ushort16 __ovld __cnfn shuffle(ushort4 x, ushort16 mask);
ushort16 __ovld __cnfn shuffle(ushort8 x, ushort16 mask);
ushort16 __ovld __cnfn shuffle(ushort16 x, ushort16 mask);

int16 __ovld __cnfn shuffle(int2 x, uint16 mask);
int16 __ovld __cnfn shuffle(int4 x, uint16 mask);
int16 __ovld __cnfn shuffle(int8 x, uint16 mask);
int16 __ovld __cnfn shuffle(int16 x, uint16 mask);

uint16 __ovld __cnfn shuffle(uint2 x, uint16 mask);
uint16 __ovld __cnfn shuffle(uint4 x, uint16 mask);
uint16 __ovld __cnfn shuffle(uint8 x, uint16 mask);
uint16 __ovld __cnfn shuffle(uint16 x, uint16 mask);

long16 __ovld __cnfn shuffle(long2 x, ulong16 mask);
long16 __ovld __cnfn shuffle(long4 x, ulong16 mask);
long16 __ovld __cnfn shuffle(long8 x, ulong16 mask);
long16 __ovld __cnfn shuffle(long16 x, ulong16 mask);

ulong16 __ovld __cnfn shuffle(ulong2 x, ulong16 mask);
ulong16 __ovld __cnfn shuffle(ulong4 x, ulong16 mask);
ulong16 __ovld __cnfn shuffle(ulong8 x, ulong16 mask);
ulong16 __ovld __cnfn shuffle(ulong16 x, ulong16 mask);

float16 __ovld __cnfn shuffle(float2 x, uint16 mask);
float16 __ovld __cnfn shuffle(float4 x, uint16 mask);
float16 __ovld __cnfn shuffle(float8 x, uint16 mask);
float16 __ovld __cnfn shuffle(float16 x, uint16 mask);

#ifdef cl_khr_fp64
double2 __ovld __cnfn shuffle(double2 x, ulong2 mask);
double2 __ovld __cnfn shuffle(double4 x, ulong2 mask);
double2 __ovld __cnfn shuffle(double8 x, ulong2 mask);
double2 __ovld __cnfn shuffle(double16 x, ulong2 mask);

double4 __ovld __cnfn shuffle(double2 x, ulong4 mask);
double4 __ovld __cnfn shuffle(double4 x, ulong4 mask);
double4 __ovld __cnfn shuffle(double8 x, ulong4 mask);
double4 __ovld __cnfn shuffle(double16 x, ulong4 mask);

double8 __ovld __cnfn shuffle(double2 x, ulong8 mask);
double8 __ovld __cnfn shuffle(double4 x, ulong8 mask);
double8 __ovld __cnfn shuffle(double8 x, ulong8 mask);
double8 __ovld __cnfn shuffle(double16 x, ulong8 mask);

double16 __ovld __cnfn shuffle(double2 x, ulong16 mask);
double16 __ovld __cnfn shuffle(double4 x, ulong16 mask);
double16 __ovld __cnfn shuffle(double8 x, ulong16 mask);
double16 __ovld __cnfn shuffle(double16 x, ulong16 mask);
#endif //cl_khr_fp64

#ifdef cl_khr_fp16
half2 __ovld __cnfn shuffle(half2 x, ushort2 mask);
half2 __ovld __cnfn shuffle(half4 x, ushort2 mask);
half2 __ovld __cnfn shuffle(half8 x, ushort2 mask);
half2 __ovld __cnfn shuffle(half16 x, ushort2 mask);

half4 __ovld __cnfn shuffle(half2 x, ushort4 mask);
half4 __ovld __cnfn shuffle(half4 x, ushort4 mask);
half4 __ovld __cnfn shuffle(half8 x, ushort4 mask);
half4 __ovld __cnfn shuffle(half16 x, ushort4 mask);

half8 __ovld __cnfn shuffle(half2 x, ushort8 mask);
half8 __ovld __cnfn shuffle(half4 x, ushort8 mask);
half8 __ovld __cnfn shuffle(half8 x, ushort8 mask);
half8 __ovld __cnfn shuffle(half16 x, ushort8 mask);

half16 __ovld __cnfn shuffle(half2 x, ushort16 mask);
half16 __ovld __cnfn shuffle(half4 x, ushort16 mask);
half16 __ovld __cnfn shuffle(half8 x, ushort16 mask);
half16 __ovld __cnfn shuffle(half16 x, ushort16 mask);
#endif //cl_khr_fp16

char2 __ovld __cnfn shuffle2(char2 x, char2 y, uchar2 mask);
char2 __ovld __cnfn shuffle2(char4 x, char4 y, uchar2 mask);
char2 __ovld __cnfn shuffle2(char8 x, char8 y, uchar2 mask);
char2 __ovld __cnfn shuffle2(char16 x, char16 y, uchar2 mask);

uchar2 __ovld __cnfn shuffle2(uchar2 x, uchar2 y, uchar2 mask);
uchar2 __ovld __cnfn shuffle2(uchar4 x, uchar4 y, uchar2 mask);
uchar2 __ovld __cnfn shuffle2(uchar8 x, uchar8 y, uchar2 mask);
uchar2 __ovld __cnfn shuffle2(uchar16 x, uchar16 y, uchar2 mask);

short2 __ovld __cnfn shuffle2(short2 x, short2 y, ushort2 mask);
short2 __ovld __cnfn shuffle2(short4 x, short4 y, ushort2 mask);
short2 __ovld __cnfn shuffle2(short8 x, short8 y, ushort2 mask);
short2 __ovld __cnfn shuffle2(short16 x, short16 y, ushort2 mask);

ushort2 __ovld __cnfn shuffle2(ushort2 x, ushort2 y, ushort2 mask);
ushort2 __ovld __cnfn shuffle2(ushort4 x, ushort4 y, ushort2 mask);
ushort2 __ovld __cnfn shuffle2(ushort8 x, ushort8 y, ushort2 mask);
ushort2 __ovld __cnfn shuffle2(ushort16 x, ushort16 y, ushort2 mask);

int2 __ovld __cnfn shuffle2(int2 x, int2 y, uint2 mask);
int2 __ovld __cnfn shuffle2(int4 x, int4 y, uint2 mask);
int2 __ovld __cnfn shuffle2(int8 x, int8 y, uint2 mask);
int2 __ovld __cnfn shuffle2(int16 x, int16 y, uint2 mask);

uint2 __ovld __cnfn shuffle2(uint2 x, uint2 y, uint2 mask);
uint2 __ovld __cnfn shuffle2(uint4 x, uint4 y, uint2 mask);
uint2 __ovld __cnfn shuffle2(uint8 x, uint8 y, uint2 mask);
uint2 __ovld __cnfn shuffle2(uint16 x, uint16 y, uint2 mask);

long2 __ovld __cnfn shuffle2(long2 x, long2 y, ulong2 mask);
long2 __ovld __cnfn shuffle2(long4 x, long4 y, ulong2 mask);
long2 __ovld __cnfn shuffle2(long8 x, long8 y, ulong2 mask);
long2 __ovld __cnfn shuffle2(long16 x, long16 y, ulong2 mask);

ulong2 __ovld __cnfn shuffle2(ulong2 x, ulong2 y, ulong2 mask);
ulong2 __ovld __cnfn shuffle2(ulong4 x, ulong4 y, ulong2 mask);
ulong2 __ovld __cnfn shuffle2(ulong8 x, ulong8 y, ulong2 mask);
ulong2 __ovld __cnfn shuffle2(ulong16 x, ulong16 y, ulong2 mask);

float2 __ovld __cnfn shuffle2(float2 x, float2 y, uint2 mask);
float2 __ovld __cnfn shuffle2(float4 x, float4 y, uint2 mask);
float2 __ovld __cnfn shuffle2(float8 x, float8 y, uint2 mask);
float2 __ovld __cnfn shuffle2(float16 x, float16 y, uint2 mask);

char4 __ovld __cnfn shuffle2(char2 x, char2 y, uchar4 mask);
char4 __ovld __cnfn shuffle2(char4 x, char4 y, uchar4 mask);
char4 __ovld __cnfn shuffle2(char8 x, char8 y, uchar4 mask);
char4 __ovld __cnfn shuffle2(char16 x, char16 y, uchar4 mask);

uchar4 __ovld __cnfn shuffle2(uchar2 x, uchar2 y, uchar4 mask);
uchar4 __ovld __cnfn shuffle2(uchar4 x, uchar4 y, uchar4 mask);
uchar4 __ovld __cnfn shuffle2(uchar8 x, uchar8 y, uchar4 mask);
uchar4 __ovld __cnfn shuffle2(uchar16 x, uchar16 y, uchar4 mask);

short4 __ovld __cnfn shuffle2(short2 x, short2 y, ushort4 mask);
short4 __ovld __cnfn shuffle2(short4 x, short4 y, ushort4 mask);
short4 __ovld __cnfn shuffle2(short8 x, short8 y, ushort4 mask);
short4 __ovld __cnfn shuffle2(short16 x, short16 y, ushort4 mask);

ushort4 __ovld __cnfn shuffle2(ushort2 x, ushort2 y, ushort4 mask);
ushort4 __ovld __cnfn shuffle2(ushort4 x, ushort4 y, ushort4 mask);
ushort4 __ovld __cnfn shuffle2(ushort8 x, ushort8 y, ushort4 mask);
ushort4 __ovld __cnfn shuffle2(ushort16 x, ushort16 y, ushort4 mask);

int4 __ovld __cnfn shuffle2(int2 x, int2 y, uint4 mask);
int4 __ovld __cnfn shuffle2(int4 x, int4 y, uint4 mask);
int4 __ovld __cnfn shuffle2(int8 x, int8 y, uint4 mask);
int4 __ovld __cnfn shuffle2(int16 x, int16 y, uint4 mask);

uint4 __ovld __cnfn shuffle2(uint2 x, uint2 y, uint4 mask);
uint4 __ovld __cnfn shuffle2(uint4 x, uint4 y, uint4 mask);
uint4 __ovld __cnfn shuffle2(uint8 x, uint8 y, uint4 mask);
uint4 __ovld __cnfn shuffle2(uint16 x, uint16 y, uint4 mask);

long4 __ovld __cnfn shuffle2(long2 x, long2 y, ulong4 mask);
long4 __ovld __cnfn shuffle2(long4 x, long4 y, ulong4 mask);
long4 __ovld __cnfn shuffle2(long8 x, long8 y, ulong4 mask);
long4 __ovld __cnfn shuffle2(long16 x, long16 y, ulong4 mask);

ulong4 __ovld __cnfn shuffle2(ulong2 x, ulong2 y, ulong4 mask);
ulong4 __ovld __cnfn shuffle2(ulong4 x, ulong4 y, ulong4 mask);
ulong4 __ovld __cnfn shuffle2(ulong8 x, ulong8 y, ulong4 mask);
ulong4 __ovld __cnfn shuffle2(ulong16 x, ulong16 y, ulong4 mask);

float4 __ovld __cnfn shuffle2(float2 x, float2 y, uint4 mask);
float4 __ovld __cnfn shuffle2(float4 x, float4 y, uint4 mask);
float4 __ovld __cnfn shuffle2(float8 x, float8 y, uint4 mask);
float4 __ovld __cnfn shuffle2(float16 x, float16 y, uint4 mask);

char8 __ovld __cnfn shuffle2(char2 x, char2 y, uchar8 mask);
char8 __ovld __cnfn shuffle2(char4 x, char4 y, uchar8 mask);
char8 __ovld __cnfn shuffle2(char8 x, char8 y, uchar8 mask);
char8 __ovld __cnfn shuffle2(char16 x, char16 y, uchar8 mask);

uchar8 __ovld __cnfn shuffle2(uchar2 x, uchar2 y, uchar8 mask);
uchar8 __ovld __cnfn shuffle2(uchar4 x, uchar4 y, uchar8 mask);
uchar8 __ovld __cnfn shuffle2(uchar8 x, uchar8 y, uchar8 mask);
uchar8 __ovld __cnfn shuffle2(uchar16 x, uchar16 y, uchar8 mask);

short8 __ovld __cnfn shuffle2(short2 x, short2 y, ushort8 mask);
short8 __ovld __cnfn shuffle2(short4 x, short4 y, ushort8 mask);
short8 __ovld __cnfn shuffle2(short8 x, short8 y, ushort8 mask);
short8 __ovld __cnfn shuffle2(short16 x, short16 y, ushort8 mask);

ushort8 __ovld __cnfn shuffle2(ushort2 x, ushort2 y, ushort8 mask);
ushort8 __ovld __cnfn shuffle2(ushort4 x, ushort4 y, ushort8 mask);
ushort8 __ovld __cnfn shuffle2(ushort8 x, ushort8 y, ushort8 mask);
ushort8 __ovld __cnfn shuffle2(ushort16 x, ushort16 y, ushort8 mask);

int8 __ovld __cnfn shuffle2(int2 x, int2 y, uint8 mask);
int8 __ovld __cnfn shuffle2(int4 x, int4 y, uint8 mask);
int8 __ovld __cnfn shuffle2(int8 x, int8 y, uint8 mask);
int8 __ovld __cnfn shuffle2(int16 x, int16 y, uint8 mask);

uint8 __ovld __cnfn shuffle2(uint2 x, uint2 y, uint8 mask);
uint8 __ovld __cnfn shuffle2(uint4 x, uint4 y, uint8 mask);
uint8 __ovld __cnfn shuffle2(uint8 x, uint8 y, uint8 mask);
uint8 __ovld __cnfn shuffle2(uint16 x, uint16 y, uint8 mask);

long8 __ovld __cnfn shuffle2(long2 x, long2 y, ulong8 mask);
long8 __ovld __cnfn shuffle2(long4 x, long4 y, ulong8 mask);
long8 __ovld __cnfn shuffle2(long8 x, long8 y, ulong8 mask);
long8 __ovld __cnfn shuffle2(long16 x, long16 y, ulong8 mask);

ulong8 __ovld __cnfn shuffle2(ulong2 x, ulong2 y, ulong8 mask);
ulong8 __ovld __cnfn shuffle2(ulong4 x, ulong4 y, ulong8 mask);
ulong8 __ovld __cnfn shuffle2(ulong8 x, ulong8 y, ulong8 mask);
ulong8 __ovld __cnfn shuffle2(ulong16 x, ulong16 y, ulong8 mask);

float8 __ovld __cnfn shuffle2(float2 x, float2 y, uint8 mask);
float8 __ovld __cnfn shuffle2(float4 x, float4 y, uint8 mask);
float8 __ovld __cnfn shuffle2(float8 x, float8 y, uint8 mask);
float8 __ovld __cnfn shuffle2(float16 x, float16 y, uint8 mask);

char16 __ovld __cnfn shuffle2(char2 x, char2 y, uchar16 mask);
char16 __ovld __cnfn shuffle2(char4 x, char4 y, uchar16 mask);
char16 __ovld __cnfn shuffle2(char8 x, char8 y, uchar16 mask);
char16 __ovld __cnfn shuffle2(char16 x, char16 y, uchar16 mask);

uchar16 __ovld __cnfn shuffle2(uchar2 x, uchar2 y, uchar16 mask);
uchar16 __ovld __cnfn shuffle2(uchar4 x, uchar4 y, uchar16 mask);
uchar16 __ovld __cnfn shuffle2(uchar8 x, uchar8 y, uchar16 mask);
uchar16 __ovld __cnfn shuffle2(uchar16 x, uchar16 y, uchar16 mask);

short16 __ovld __cnfn shuffle2(short2 x, short2 y, ushort16 mask);
short16 __ovld __cnfn shuffle2(short4 x, short4 y, ushort16 mask);
short16 __ovld __cnfn shuffle2(short8 x, short8 y, ushort16 mask);
short16 __ovld __cnfn shuffle2(short16 x, short16 y, ushort16 mask);

ushort16 __ovld __cnfn shuffle2(ushort2 x, ushort2 y, ushort16 mask);
ushort16 __ovld __cnfn shuffle2(ushort4 x, ushort4 y, ushort16 mask);
ushort16 __ovld __cnfn shuffle2(ushort8 x, ushort8 y, ushort16 mask);
ushort16 __ovld __cnfn shuffle2(ushort16 x, ushort16 y, ushort16 mask);

int16 __ovld __cnfn shuffle2(int2 x, int2 y, uint16 mask);
int16 __ovld __cnfn shuffle2(int4 x, int4 y, uint16 mask);
int16 __ovld __cnfn shuffle2(int8 x, int8 y, uint16 mask);
int16 __ovld __cnfn shuffle2(int16 x, int16 y, uint16 mask);

uint16 __ovld __cnfn shuffle2(uint2 x, uint2 y, uint16 mask);
uint16 __ovld __cnfn shuffle2(uint4 x, uint4 y, uint16 mask);
uint16 __ovld __cnfn shuffle2(uint8 x, uint8 y, uint16 mask);
uint16 __ovld __cnfn shuffle2(uint16 x, uint16 y, uint16 mask);

long16 __ovld __cnfn shuffle2(long2 x, long2 y, ulong16 mask);
long16 __ovld __cnfn shuffle2(long4 x, long4 y, ulong16 mask);
long16 __ovld __cnfn shuffle2(long8 x, long8 y, ulong16 mask);
long16 __ovld __cnfn shuffle2(long16 x, long16 y, ulong16 mask);

ulong16 __ovld __cnfn shuffle2(ulong2 x, ulong2 y, ulong16 mask);
ulong16 __ovld __cnfn shuffle2(ulong4 x, ulong4 y, ulong16 mask);
ulong16 __ovld __cnfn shuffle2(ulong8 x, ulong8 y, ulong16 mask);
ulong16 __ovld __cnfn shuffle2(ulong16 x, ulong16 y, ulong16 mask);

float16 __ovld __cnfn shuffle2(float2 x, float2 y, uint16 mask);
float16 __ovld __cnfn shuffle2(float4 x, float4 y, uint16 mask);
float16 __ovld __cnfn shuffle2(float8 x, float8 y, uint16 mask);
float16 __ovld __cnfn shuffle2(float16 x, float16 y, uint16 mask);

#ifdef cl_khr_fp64
double2 __ovld __cnfn shuffle2(double2 x, double2 y, ulong2 mask);
double2 __ovld __cnfn shuffle2(double4 x, double4 y, ulong2 mask);
double2 __ovld __cnfn shuffle2(double8 x, double8 y, ulong2 mask);
double2 __ovld __cnfn shuffle2(double16 x, double16 y, ulong2 mask);

double4 __ovld __cnfn shuffle2(double2 x, double2 y, ulong4 mask);
double4 __ovld __cnfn shuffle2(double4 x, double4 y, ulong4 mask);
double4 __ovld __cnfn shuffle2(double8 x, double8 y, ulong4 mask);
double4 __ovld __cnfn shuffle2(double16 x, double16 y, ulong4 mask);

double8 __ovld __cnfn shuffle2(double2 x, double2 y, ulong8 mask);
double8 __ovld __cnfn shuffle2(double4 x, double4 y, ulong8 mask);
double8 __ovld __cnfn shuffle2(double8 x, double8 y, ulong8 mask);
double8 __ovld __cnfn shuffle2(double16 x, double16 y, ulong8 mask);

double16 __ovld __cnfn shuffle2(double2 x, double2 y, ulong16 mask);
double16 __ovld __cnfn shuffle2(double4 x, double4 y, ulong16 mask);
double16 __ovld __cnfn shuffle2(double8 x, double8 y, ulong16 mask);
double16 __ovld __cnfn shuffle2(double16 x, double16 y, ulong16 mask);
#endif //cl_khr_fp64

#ifdef cl_khr_fp16
half2 __ovld __cnfn shuffle2(half2 x, half2 y, ushort2 mask);
half2 __ovld __cnfn shuffle2(half4 x, half4 y, ushort2 mask);
half2 __ovld __cnfn shuffle2(half8 x, half8 y, ushort2 mask);
half2 __ovld __cnfn shuffle2(half16 x, half16 y, ushort2 mask);

half4 __ovld __cnfn shuffle2(half2 x, half2 y, ushort4 mask);
half4 __ovld __cnfn shuffle2(half4 x, half4 y, ushort4 mask);
half4 __ovld __cnfn shuffle2(half8 x, half8 y, ushort4 mask);
half4 __ovld __cnfn shuffle2(half16 x, half16 y, ushort4 mask);

half8 __ovld __cnfn shuffle2(half2 x, half2 y, ushort8 mask);
half8 __ovld __cnfn shuffle2(half4 x, half4 y, ushort8 mask);
half8 __ovld __cnfn shuffle2(half8 x, half8 y, ushort8 mask);
half8 __ovld __cnfn shuffle2(half16 x, half16 y, ushort8 mask);

half16 __ovld __cnfn shuffle2(half2 x, half2 y, ushort16 mask);
half16 __ovld __cnfn shuffle2(half4 x, half4 y, ushort16 mask);
half16 __ovld __cnfn shuffle2(half8 x, half8 y, ushort16 mask);
half16 __ovld __cnfn shuffle2(half16 x, half16 y, ushort16 mask);
#endif //cl_khr_fp16

#endif //_OPENCL_COMMON_H_
