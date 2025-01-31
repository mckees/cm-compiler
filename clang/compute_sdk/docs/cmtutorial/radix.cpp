/*========================== begin_copyright_notice ============================

Copyright (C) 2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#include <string>

// The only CM runtime header file that you need is cm_rt.h.
// It includes all of the CM runtime.
#include "cm_rt.h"
#include "cm_loadprogram.h"

// Includes bitmap_helpers.h for bitmap file open/save/compare operations.
#include "../common/bitmap_helpers.h"

// Include cm_rt_helpers.h to convert the integer return code returned from
// the CM runtime to a meaningful string message.
#include "../common/cm_rt_helpers.h"

// Includes isa_helpers.h to load the ISA file generated by the CM compiler.
#include "../common/isa_helpers.h"
#include <algorithm>
#include <time.h>
#include <iostream>
#include "radix.h"
using namespace std;

// The implementation is sorting unsigned int(32 - bit) values. It can be
// easily adopted to sort signed integer values.
// The sorting starts from the least significant bits (LSB).
// In each iteration, starting LSB to MSB, we extract 2 - bit values and
// put elements into 4 bins / buckets(BIN0, BIN1, BIN2 and BIN3) based
// on their 2-bit values, i.e., BIN0 for value 0. Once elements are binned,
// elements in each bin are written out to an output buffer from BIN0 to
// BIN4 with FIFO order.In the next iteration, the previously written
// output buffer is fed as the input data buffer and the subsequent 2 bits
// are extracted and the same binning is processed.For 32-bit integer,
// the whole process will repeat 16 times.The algorithm is simple.The goal
// is to divide the binning process so that the work can be done in parallel
// and efficiently mapped to Intel GEN HW threads.
// The implementation is composed of three parts.
// 1.	cmk_radix_count: which counts how many elements in each bin locally
//    within each HW thread.
// 2.	prefix sum : which cumulates the number of elements of bins
//    of all threads.
// 3.	cmk_radix_bucket : which reads a chunk of data, 256 elements, bins
//    them into buckets, finally writes elements in each bucket to
//    the output buffer based on the global positions calculated in step 2.

void cmk_radix_count(SurfaceIndex input, SurfaceIndex output, unsigned int n);
void cmk_radix_bucket(SurfaceIndex input, SurfaceIndex table,
  SurfaceIndex output, unsigned int bin0_cnt, unsigned int bin1_cnt,
  unsigned int bin2_cnt, unsigned int bin3_cnt, unsigned int n);

#define LOG2_ELEMENTS 26
//
// validate radix_count result
//
bool validate_count(unsigned int inputs[], unsigned int result[],
  unsigned int total_threads, unsigned int size,
  unsigned n) {
  unsigned int binCount[4];
  binCount[0] = binCount[1] = binCount[2] = binCount[3] = 0;
  unsigned int mask = 0x3 << n;
  for (int i = 0; i < size; i++) {
    binCount[(inputs[i] & mask) >> n]++;
  }

  unsigned int total_cnt[BIN_NUM];
  total_cnt[0] = total_cnt[1] = total_cnt[2] = total_cnt[3] = 0;
  for (int i = 0; i < total_threads; i++) {
    total_cnt[0] += result[i*BIN_NUM];
    total_cnt[1] += result[i*BIN_NUM + 1];
    total_cnt[2] += result[i*BIN_NUM + 2];
    total_cnt[3] += result[i*BIN_NUM + 3];
  }

  cout << "Expected result " <<
    binCount[0] << " " <<
    binCount[1] << " " <<
    binCount[2] << " " <<
    binCount[3] << " " << endl;
  cout << "result " <<
    total_cnt[0] << " " <<
    total_cnt[1] << " " <<
    total_cnt[2] << " " <<
    total_cnt[3] << " " << endl;
  return (binCount[0] == total_cnt[0] &&
    binCount[1] == total_cnt[1] &&
    binCount[2] == total_cnt[2] &&
    binCount[3] == total_cnt[3]);
}
//
// validate bin's contents
//
bool validate_bin(unsigned int outputs[], unsigned int binCount[], unsigned int n) {
  unsigned int mask = 0x3 << n;
  int idx = 0;
  for (int i = 0; i < binCount[0]; i++, idx++) {
    if (((outputs[idx] & mask) >> n) != 0) {
      cout << "Bin0 error at idx = " << idx << " value= " << outputs[idx] << endl;
      return false;
    }
  }
  for (int i = 0; i < binCount[1]; i++, idx++) {
    if (((outputs[idx] & mask) >> n) != 1) {
      cout << "Bin1 error at idx = " << idx << " value= " << outputs[idx] << endl;
      return false;
    }
  }
  for (int i = 0; i < binCount[2]; i++, idx++) {
    if (((outputs[idx] & mask) >> n) != 2) {
      cout << "Bin2 error at idx = " << idx << " value= " << outputs[idx] << endl;
      return false;
    }
  }
  for (int i = 0; i < binCount[3]; i++, idx++) {
    if (((outputs[idx] & mask) >> n) != 3) {
      cout << "Bin3 error at idx = " << idx << " value= " << outputs[idx] << endl;
      return false;
    }
  }
  return true;
}

static unsigned int clock_prefix = 0;
void  compute_prefixsum(unsigned int prefixSum[], unsigned int total_threads) {
#if _DEBUG
  cout << "Count Table" << endl;
  for (int i = 0; i < total_threads; i++)
    cout << "\t" << prefixSum[i*BIN_NUM] << "\t" << prefixSum[i*BIN_NUM + 1]
         << "\t" << prefixSum[i*BIN_NUM + 2] << "\t" << prefixSum[i*BIN_NUM + 3] << endl;

  cout << "Prefix Sum Table " << endl;
  cout << "\t" << prefixSum[0] << "\t" << prefixSum[1] << "\t" << prefixSum[2] << "\t" << prefixSum[3] << endl;
#endif
  clock_t start = clock();
  for (int i = 1; i < total_threads; i++) {
    prefixSum[i*BIN_NUM] += prefixSum[(i - 1)*BIN_NUM];
    prefixSum[i*BIN_NUM+1] += prefixSum[(i - 1)*BIN_NUM+1];
    prefixSum[i*BIN_NUM+2] += prefixSum[(i - 1)*BIN_NUM+2];
    prefixSum[i*BIN_NUM+3] += prefixSum[(i - 1)*BIN_NUM+3];
#if _DEBUG
    cout << "\t" << prefixSum[i*BIN_NUM] << "\t" << prefixSum[i*BIN_NUM + 1]
      << "\t" << prefixSum[i*BIN_NUM + 2] << "\t" << prefixSum[i*BIN_NUM + 3] << endl;
#endif
  }
  clock_t end = clock();

  clock_prefix += end - start;
}

void validate_sorted_result(unsigned int expectOutputs[], unsigned int result[], unsigned int size) {
  clock_t start = clock(); // start timer
  std::sort(expectOutputs, expectOutputs + size);
  clock_t end = clock(); // end timer
  cout << " CPU Sorting Time = " << end - start << " msec " << endl;

  bool pass = true;
  for (unsigned int i = 0; i < size; ++i) {
    if (expectOutputs[i] != result[i]) {
      cout << "Difference is detected at i= " << i << " Expect = " << expectOutputs[i] << " Actual = " << result[i] << endl;
      pass = false;
      break;
    }
  }
  cout << "Radix Sort " << (pass ? "PASSED" : "FAILED") << endl;
}
int main(int argc, char * argv[])
{
  unsigned int * pInputs;
  unsigned int * pActualOutputs;
  unsigned int * pExpectOutputs;
  unsigned int * prefixSum;

  unsigned int size = 1 << LOG2_ELEMENTS;
  // prepare intput data
  pInputs = (unsigned int*)CM_ALIGNED_MALLOC(size * sizeof(unsigned int), 0x1000);
  for (unsigned int i = 0; i < size; ++i) {
    pInputs[i] = (rand()<<16) + rand();
    // pInputs_[i] = rand() % (1 << 15);
  }
  // prepare output buffer for sorted result
  pActualOutputs = (unsigned int*)CM_ALIGNED_MALLOC(size * sizeof(unsigned int), 0x1000);
  memset(pActualOutputs, 0, sizeof(unsigned int) * size);
  // prepare validation result. call std::sort to get the expected result
  pExpectOutputs = new unsigned int[size];
  memcpy(pExpectOutputs, pInputs, sizeof(unsigned int) * size);
  std::sort(pExpectOutputs, pExpectOutputs + size);

  // Creates a CmDevice
  // Param device: pointer to the CmDevice object.
  // Param version: CM API version supported by the runtime library.
  CmDevice *device = nullptr;
  unsigned int version = 0;
  cm_result_check(::CreateCmDevice(device, version));
  // The file radix_genx.isa is generated by the CM compiler.
  // Reads in the virtual ISA from "radix_genx.isa" to the code
  // buffer.
  std::string isa_code = cm::util::isa::loadFile("radix_genx.isa");
  if (isa_code.size() == 0) {
    std::cerr << "Error: empty ISA binary.\n";
    exit(1);
  }
  // Creates a CmProgram object consisting of the kernels loaded
  // from the code buffer.
  CmProgram *program = nullptr;
  cm_result_check(CmDevLoadProgram(device, const_cast<char*>(isa_code.data()),
    isa_code.size(),
    program));

  // Creates the radix bin-count kernel.
  CmKernel *count_kernel = nullptr;
  cm_result_check(device->CreateKernel(program,
    CM_KERNEL_FUNCTION(cmk_radix_count),
    count_kernel));
  // create radix bucket kernel
  CmKernel *bucket_kernel = nullptr;
  cm_result_check(device->CreateKernel(program,
    CM_KERNEL_FUNCTION(cmk_radix_bucket),
    bucket_kernel));

  // determine how many threads we need
  // each thread handling 256 elements
  unsigned int width, height; // thread space width and height
  unsigned int total_threads = size / BASE_SZ;
  if (total_threads < MAX_TS_WIDTH) {
    width = total_threads;
    height = 1;
  }
  else {
    width = MAX_TS_WIDTH;
    height = total_threads / MAX_TS_WIDTH;
  }
  // create buffers for input and output and prefix sum table
  // in system-memory, zero-copy for GPU-CPU sharing.
  CmBufferUP *inBuf;
  cm_result_check(device->CreateBufferUP(size * sizeof(unsigned int), (void *)pInputs, inBuf));
  CmBufferUP *outBuf;
  cm_result_check(device->CreateBufferUP(size * sizeof(unsigned int), (void *)pActualOutputs, outBuf));
  // prepare prefixSum table
  prefixSum = (unsigned int*)CM_ALIGNED_MALLOC(total_threads*BIN_NUM * sizeof(unsigned int), 0x1000);
  CmBufferUP *prefixBuf;
  cm_result_check(device->CreateBufferUP(total_threads*BIN_NUM * sizeof(unsigned int), (void *)prefixSum, prefixBuf));
  // When a surface is created by the CmDevice a SurfaceIndex object is
  // created. This object contains a unique index value that is mapped to the
  // surface.
  // Gets the input surface index.
  SurfaceIndex *input_idx = nullptr;
  cm_result_check(inBuf->GetIndex(input_idx));
  SurfaceIndex *output_idx = nullptr;
  cm_result_check(outBuf->GetIndex(output_idx));
  SurfaceIndex *prefix_idx = nullptr;
  cm_result_check(prefixBuf->GetIndex(prefix_idx));

  // Creates a CmThreadSpace object.
  CmThreadSpace *thread_space = nullptr;
  cm_result_check(device->CreateThreadSpace(width, height, thread_space));

  // Creates a task queue.
  CmQueue *cmd_queue = nullptr;
  cm_result_check(device->CreateQueue(cmd_queue));

  // Creates CmTask objects.
  // The CmTask object is a container for CmKernel pointers. It is used to
  // enqueue the kernels for execution.
  CmTask *cnt_task = nullptr;
  cm_result_check(device->CreateTask(cnt_task));
  CmTask *bucket_task = nullptr;
  cm_result_check(device->CreateTask(bucket_task));
  // Adds a CmKernel pointer to CmTask.
  // This task has one kernel, "cmk_radix_count".
  cm_result_check(cnt_task->AddKernel(count_kernel));
  cm_result_check(bucket_task->AddKernel(bucket_kernel));
  // Inits the print buffer.
  // Here the buffer used by printf is allocated.
  cm_result_check(device->InitPrintBuffer());

  cout << "Radix Sort (" << size << ") Start..." << endl;

  clock_t start = clock(); // start timer

  // 16 iterations for sorting 32-bit unsigned numbers, 2-bit each iteration
  for (int n = 0; n <= 32; n += 2) {
    // cmk_radix_count(SurfaceIndex input, SurfaceIndex prefix, unsigned int n).
    // set argument for radix_count
    // determine even or odd iteration. alternate in and out buffers
    bool even_iteration = ((n >> 1) & 0x1) == 0;
    if (even_iteration) {
      cm_result_check(count_kernel->SetKernelArg(0, sizeof(SurfaceIndex), input_idx));
    }
    else {
      cm_result_check(count_kernel->SetKernelArg(0, sizeof(SurfaceIndex), output_idx));
    }
    cm_result_check(count_kernel->SetKernelArg(1, sizeof(SurfaceIndex), prefix_idx));
    cm_result_check(count_kernel->SetKernelArg(2, sizeof(int), &n));
    // Launches the task on the GPU. Enqueue is a non-blocking call, i.e. the
    // function returns immediately without waiting for the GPU to start or
    // finish execution of the task. The runtime will query the HW status. If
    // the hardware is not busy, the runtime will submit the task to the
    // driver/HW; otherwise, the runtime will submit the task to the driver/HW
    // at another time.
    // An event, "sync_event", is created to track the status of the task.
    CmEvent *event = nullptr;
    cm_result_check(cmd_queue->Enqueue(cnt_task, event, thread_space));

    // Waits for the task associated with "sync_event" finishing execution
    // on the GPU.
    unsigned long time_out = -1;
    cm_result_check(event->WaitForTaskFinished(time_out));

    bool pass = true;
#ifdef _DEBUG
    // validate bin count result
    pass = validate_count(even_iteration ? pInputs : pActualOutputs, prefixSum, total_threads, size, n);
#endif

    // compute prefix sum on CPU
    compute_prefixsum(prefixSum, total_threads);

#ifdef _DEBUG
    cout << "Count " << (pass ? "=> PASSED)" : "=> FAILED") << endl << endl;
#endif
    unsigned int binCount[4];
    binCount[0] = prefixSum[(total_threads - 1)*BIN_NUM];
    binCount[1] = prefixSum[(total_threads - 1)*BIN_NUM + 1];
    binCount[2] = prefixSum[(total_threads - 1)*BIN_NUM + 2];
    binCount[3] = prefixSum[(total_threads - 1)*BIN_NUM + 3];

    // cmk_radix_bucket(
    // SurfaceIndex input, SurfaceIndex table, SurfaceIndex output,
    // unsigned int bin0_cnt, unsigned int bin1_cnt, unsigned int bin2_cnt,
    // unsigned int bin3_cnt, unsigned int n);
    // set arguments
    // determine even or odd iteration. alternate in and out buffers
    if (even_iteration) {
      cm_result_check(bucket_kernel->SetKernelArg(0, sizeof(SurfaceIndex), input_idx));
      cm_result_check(bucket_kernel->SetKernelArg(2, sizeof(SurfaceIndex), output_idx));
    }
    else {
      cm_result_check(bucket_kernel->SetKernelArg(0, sizeof(SurfaceIndex), output_idx));
      cm_result_check(bucket_kernel->SetKernelArg(2, sizeof(SurfaceIndex), input_idx));
    }

    cm_result_check(bucket_kernel->SetKernelArg(1, sizeof(SurfaceIndex), prefix_idx));
    cm_result_check(bucket_kernel->SetKernelArg(3, sizeof(unsigned int), &binCount[0]));
    cm_result_check(bucket_kernel->SetKernelArg(4, sizeof(unsigned int), &binCount[1]));
    cm_result_check(bucket_kernel->SetKernelArg(5, sizeof(unsigned int), &binCount[2]));
    cm_result_check(bucket_kernel->SetKernelArg(6, sizeof(unsigned int), &binCount[3]));
    cm_result_check(bucket_kernel->SetKernelArg(7, sizeof(unsigned int), &n));

    cm_result_check(cmd_queue->Enqueue(bucket_task, event, thread_space));
    // Waits for the task associated with "sync_event" finishing execution
    // on the GPU.
    cm_result_check(event->WaitForTaskFinished(time_out));
    //
    // validate bin result
    //
#ifdef _DEBUG
    pass = validate_bin(even_iteration? pActualOutputs : pInputs, binCount, n);
    cout << "Bucket " << (pass ? "=> PASSED" : "=> FAILED") << endl << endl;
#endif

  }
  clock_t end = clock(); // end timer
  cout << " Sorting Time = " << end - start << " msec " << endl;
  cout << " Prefix Time = " << clock_prefix << " msec " << endl;

  validate_sorted_result(pExpectOutputs, pInputs, size);
  // Flushes the print buffer to stdout.
  // This function call will also clear/reset the print buffer.
  cm_result_check(device->FlushPrintBuffer());

  // Destroys a CmTask object.
  // CmTask will be destroyed when CmDevice is destroyed.
  // Here, the application destroys the CmTask object by itself.
  cm_result_check(device->DestroyTask(cnt_task));
  cm_result_check(device->DestroyTask(bucket_task));

  // Destroy a CmThreadSpace object.
  // CmThreadSpace will be destroyed when CmDevice is destroyed.
  // Here, the application destroys the CmThreadSpace object by itself.
  cm_result_check(device->DestroyThreadSpace(thread_space));
  // Destroys the CmDevice.
  // Also destroys surfaces, kernels, tasks, thread spaces, and queues that
  // were created using this device instance that have not explicitly been
  // destroyed by calling the respective destroy functions.
  cm_result_check(::DestroyCmDevice(device));

  CM_ALIGNED_FREE(pInputs);
  CM_ALIGNED_FREE(pActualOutputs);
  CM_ALIGNED_FREE(prefixSum);
  delete[]pExpectOutputs;

}

