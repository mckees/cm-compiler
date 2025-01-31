/*========================== begin_copyright_notice ============================

Copyright (C) 2016-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#include <cm/cm.h>

_GENX_ void test()
{
  char r;
  matrix<unsigned char, 4, 8> m1;
  r = cm_sum<unsigned char>(m1.select<1, 1, 2, 1>(2, 0)) >> 1;

#pragma cm_nonstrict
  unsigned char t = cm_sum<unsigned char>(m1.select<1, 1, 2, 1>(2, 0));
  r = t >> 1 ;
}

// RUN: %cmc -march=SKL -emit-llvm -- %s 2>&1 | FileCheck --implicit-check-not error %s
// CHECK: warning: cm_nonstrict is deprecated
