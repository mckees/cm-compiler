/*========================== begin_copyright_notice ============================

Copyright (C) 2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#include <string>

// Includes this header file for input/output stream.
#include <iostream>

// The only CM runtime header file that you need is cm_rt.h.
// It includes all of the CM runtime.
#include "cm_rt.h"
#include "cm_loadprogram.h"

// Includes cm_rt_helpers.h to convert the integer return code returned from
// the CM runtime to a meaningful string message.
#include "common/cm_rt_helpers.h"

// Includes isa_helpers.h to load the ISA file generated by the CM compiler.
#include "common/isa_helpers.h"

#define RANDOM_TEST  1
#define STATIC_TEST  2
#define MAX_ERROR 30
#define FEATURE_VECTOR_PER_GROUP   8
#define VECTOR_PER_GROUP          8
#define VECTOR_LENGTH            80

// Uses the CPU to calculate the SAD output data.
// Then compare the CPU SAD output data with the GPU SAD output data. If all
// values are matched, then return true. Or else return false.
bool CompareSAD(int vector_size,
                unsigned char *feature_vect,
                int feature_vect_num,
                unsigned char *db_vect,
                int db_vect_num,
                unsigned short *output_gpu) {
  int error_num = 0;
  for (int i = 0; i < db_vect_num; i++) {
    unsigned char *db_vect_tmp = db_vect;
    unsigned char *feature_vect_tmp = feature_vect;
    for (int j = 0; j < feature_vect_num; j++) {
      unsigned short sad_cpu = 0;
      for (int k = 0; k < vector_size; k++)
        sad_cpu += abs(db_vect_tmp[k] - feature_vect_tmp[k]);

      if ((sad_cpu != *output_gpu) && (error_num < MAX_ERROR)) {
        printf("SAD mismatch at: DB %5d, FV %5d, Ref: %5d, Actual: %5d\n",
            i, j, sad_cpu, *output_gpu);
        error_num++;
      }
      feature_vect_tmp += vector_size;
      output_gpu++;
    }
    db_vect += vector_size;
  }

  if (error_num == 0) {
    std::cout << "All SAD values match!!" << std::endl;
    return true;
  } else {
    std::cout << "SAD values mismatch!!" << std::endl;
    return false;
  }
}


int main(int argc, char* argv[]) {
  // Checks the command line arguments number
  if (4 > argc) {
    std::cout << "Usage: vcaOpSAD <DBVector> <NumFV> <TestMode> <Offset>\n"
        << "       <DBVector>: Number of vectors in data base;\n"
        << "       <NumFV>: Number of feature vectors;\n"
        << "       <TestMode>: -random or -static\n"
        << "       <Offset>: offset value for -static test mode\n"
        << std::endl;
    exit(1);
  }

  // Gets the number of database vectors from command line. It should be
  // multiple of 8, or else the result may be inconsistent.
  int db_vect_num = atoi(argv[1]);
  if (db_vect_num & 7)
    std::cout << "Number of database vectors is not multiple of 8, "
        << "so the result may be inconsistent." << std::endl;

  // Gets the number of feature vectors from command line. It should be
  // mutiple of 8, or else the result may be inconsitent.
  int feature_vect_num = atoi(argv[2]);
  if (feature_vect_num & 7)
    std::cout << "Number of feature vectors is not multiple of 8, "
        << "so the result may be inconsistent" << std::endl;

  // Checks and sets test mode, 1: random test, 2: static test.
  // For static test mode, need get the offset value from command line.
  int test_mode = 0;
  int offset = 0;
  if (!strcmp(argv[3], "-random")) {
    test_mode = RANDOM_TEST;
  } else if (!strcmp(argv[3], "-static")) {
    test_mode = STATIC_TEST;
    if (5 > argc) {
      std::cerr << "<Offset> is needed for -static mode" << std::endl;
      exit(1);
    } else {
      offset = atoi(argv[4]);
    }
  } else {
    std::cerr << "Invalid test mode!" << std::endl;
    exit(1);
  }

  // Allocates 4K-aligned memory for the feature vectors and initialize them.
  // For random test mode, initialize the feature vectors with random values.
  // For static test mode, initialize the feature vectors with fixed values.
  unsigned char *feature_vect = (unsigned char *)
      CM_ALIGNED_MALLOC(VECTOR_LENGTH*feature_vect_num, 0x1000);
  for (int j = 0; j < feature_vect_num; j++) {
    if (RANDOM_TEST == test_mode) {
      for (int i = 0; i < VECTOR_LENGTH; i++)
        feature_vect[i + j*VECTOR_LENGTH] = (unsigned char)
            (255.0*rand()/static_cast<double>(RAND_MAX) + 0.5);
    } else {
      for (int i = 0; i < VECTOR_LENGTH; i++)
        feature_vect[i + j*VECTOR_LENGTH] = (unsigned char)(i + j + offset);
    }
  }

  // Allocates 4K-aligned memory for the database vectors and initialize them
  // For random test mode, initialize the database vectors with random values
  // For static test mode, initialize the database vectors with fixed values.
  unsigned char *db_vect = (unsigned char *)CM_ALIGNED_MALLOC(
      db_vect_num*VECTOR_LENGTH,
      0x1000);
  unsigned char *vector_tmp = db_vect;
  for (int i = 0; i < db_vect_num; i++) {
    if (RANDOM_TEST == test_mode) {
      for (int j = 0; j < VECTOR_LENGTH; j++)
        *vector_tmp++ = (unsigned char)
            (255.0*rand()/static_cast<double>(RAND_MAX) + 0.5);
    } else {
      for (int j = 0; j < VECTOR_LENGTH; j++)
        *vector_tmp++ = (unsigned char)(i + j);
    }
  }

  // Creates a CmDevice from scratch.
  // Param device: pointer to the CmDevice object.
  // Param version: CM API version supported by the runtime library.
  CmDevice *device = nullptr;
  unsigned int version = 0;
  cm_result_check(::CreateCmDevice(device, version));

  // The file vcaOpSAD_genx.isa is generated when the kernels in the file
  // vcaOpSAD_genx.cpp are compiled by the CM compiler. There is one kernel
  // included here, "vcaOpSAD_Ex".
  // Reads in the virtual ISA from "vcaOpSAD_genx.isa" to the code buffer.
  std::string isa_code = cm::util::isa::loadFile("vcaOpSAD_genx.isa");
  if (isa_code.size() == 0) {
    std::cerr << "Error: empty ISA binary.\n";
    exit(1);
  }

  // Creates a CmProgram object consisting of the kernels loaded from code
  // buffer.
  // Param isa_code.data(): Pointer to the code buffer containing the virtual
  // ISA.
  // Param isa_code.size(): Size in bytes of the code buffer containing the
  // virtual ISA.
  CmProgram *program = nullptr;
  cm_result_check(CmDevLoadProgram(device, const_cast<char *>(isa_code.data()),
                                      isa_code.size(),
                                      program));

  // Creates the vcaOpSAD_Ex kernel.
  // @param program: CM Program from which the kernel is created.
  // @param "vcaOpSAD_Ex": The kernel name which should be no more than 256
  // bytes including the null terminator.
  CmKernel *kernel = nullptr;
  cm_result_check(device->CreateKernel(program, "vcaOpSAD_Ex", kernel));

  // Creates a 1D input surface for the feature vectors in the user provided
  // system memory. Application can either access the memory through the
  // memory pointer from the CPU, or access the buffer created upon the same
  // memory from the GPU.
  CmBufferUP *feature_vect_surf = nullptr;
  cm_result_check(device->CreateBufferUP(feature_vect_num*VECTOR_LENGTH,
                                         feature_vect,
                                         feature_vect_surf));

  // When a surface is created by the CmDevice a SurfaceIndex object is
  // created. This object contains a unique index value that is mapped to the
  // surface.
  // Gets the surface index of the surface of feature vectors.
  SurfaceIndex *feature_vect_surf_idx = nullptr;
  cm_result_check(feature_vect_surf->GetIndex(feature_vect_surf_idx));

  // Creates a 1D input surface for the database vectors in the user provided
  // system memory. Application can either access the memory through the
  // memory pointer from the CPU, or access the buffer created upon the same
  // memory from the GPU.
  CmBufferUP *db_vect_surf = nullptr;
  cm_result_check(device->CreateBufferUP(db_vect_num*VECTOR_LENGTH,
                                         db_vect,
                                         db_vect_surf));

  // Gets the surface index of the surface of database vectors.
  SurfaceIndex *db_vect_surf_idx = nullptr;
  cm_result_check(db_vect_surf->GetIndex(db_vect_surf_idx));

  // Allocates 4K-aligned memory for the SAD output data.
  unsigned char *output_data = (unsigned char *)CM_ALIGNED_MALLOC(
      db_vect_num*feature_vect_num*sizeof(unsigned short),
      0x1000);

  // Creates a 1D output surface for the SAD output data in the user provided
  // system memory. Application can either access the memory through the
  // memory pointer from the CPU, or access the buffer created upon the same
  // memory from the GPU.
  CmBufferUP *output_surf = nullptr;
  int output_surf_size = feature_vect_num*db_vect_num*sizeof(unsigned short);
  cm_result_check(device->CreateBufferUP(output_surf_size,
                                         output_data,
                                         output_surf));

  // Gets the surface index of the surface of SAD output data.
  SurfaceIndex *output_surf_idx = nullptr;
  cm_result_check(output_surf->GetIndex(output_surf_idx));

  // Gets available HW thread count.
  size_t cap_size = 4;
  int max_thread_count = 0;
  cm_result_check(device->GetCaps(CAP_HW_THREAD_COUNT,
                                  cap_size,
                                  &max_thread_count));
  std::cout << "Max number of HW threads: " << max_thread_count << std::endl;

  // Each CmKernel can be executed by multiple concurrent threads.
  // Here, for "vcaOpSAD_Ex" kernel, each thread works on VECTOR_PER_GROUP
  // vectors. Therefore, the thread count is equal to the number of database
  // vectors divided by VECTOR_PER_GROUP. If db_vect_num/VECTOR_PER_GROUP
  // exceeds the max number of HW threads, then sets the thread count as the
  // number of max HW threads.
  if (max_thread_count > db_vect_num/VECTOR_PER_GROUP)
    max_thread_count = db_vect_num/VECTOR_PER_GROUP;

  // Creates a CmThreadSpace object.
  // There are two usage models for the thread space. One is to define the
  // dependency between threads to run in the GPU. The other is to define a
  // thread space where each thread can get a pair of coordinates during
  // kernel execution. For this example, we use the latter usage model.
  CmThreadSpace *thread_space = nullptr;
  cm_result_check(device->CreateThreadSpace(max_thread_count,
                                            1,
                                            thread_space));


  // Sets a per kernel argument.
  // Sets the surface index of the feature vectors as the first argument.
  cm_result_check(kernel->SetKernelArg(0,
                                       sizeof(SurfaceIndex),
                                       feature_vect_surf_idx));

  // Sets the surface index of the database vectors as the second argument.
  cm_result_check(kernel->SetKernelArg(1,
                                       sizeof(SurfaceIndex),
                                       db_vect_surf_idx));

  // Sets the surface index of the SAD output data as the third argument.
  cm_result_check(kernel->SetKernelArg(2,
                                       sizeof(SurfaceIndex),
                                       output_surf_idx));

  // Sets jump step between the database vector group as the fourth argument.
  unsigned int global_step = VECTOR_PER_GROUP*max_thread_count;
  cm_result_check(kernel->SetKernelArg(3,
                                       sizeof(unsigned int),
                                       &global_step));

  // Sets the number of database vectors as the fifth argument.
  cm_result_check(kernel->SetKernelArg(4,
                                       sizeof(unsigned int),
                                       &db_vect_num));

  // Sets the group number of feature vectors as the sixth argument.
  int feature_vect_group = feature_vect_num/FEATURE_VECTOR_PER_GROUP;
  cm_result_check(kernel->SetKernelArg(5,
                                       sizeof(unsigned int),
                                       &feature_vect_group));

  // Creates a CmTask object.
  // The CmTask object is a container for CmKernel pointers. It is used to
  // enqueue the kernels for execution.
  CmTask *task = nullptr;
  cm_result_check(device->CreateTask(task));

  // Adds a CmKernel pointer to CmTask.
  // This task has one kernel "vcaOpSAD_Ex".
  cm_result_check(task->AddKernel(kernel));

  // Creates a task queue.
  // The CmQueue is an in-order queue. Tasks get executed according to the
  // order they are enqueued. The next task does not start execution until the
  // current task finishes.
  CmQueue *queue = nullptr;
  cm_result_check(device->CreateQueue(queue));

  // Launches the task on the GPU. Enqueue is a non-blocking call, i.e. the
  // function returns immediately without waiting for the GPU to start or
  // finish execution of the task. The runtime will query the HW status. If
  // the hardware is not busy, the runtime will submit the task to the
  // driver/HW; otherwise, the runtime will submit the task to the driver/HW
  // at another time.
  // An event, "sync_event", is created to track the status of the task.
  CmEvent *sync_event = nullptr;
  cm_result_check(queue->Enqueue(task, sync_event, thread_space));

  // Waits for the task associated with the sync_event finishing execution on
  // the GPU.
  cm_result_check(sync_event->WaitForTaskFinished());

  // Queries the execution time of a task in the unit of nanoseconds.
  // The execution time is measured from the time the task started execution
  // in the GPU to the time when the task finished execution.
  unsigned long long execution_time = 0;
  cm_result_check(sync_event->GetExecutionTime(execution_time));
  std::cout << "Kernel vcaOpSAD_Ex execution time is " << execution_time
      << " nanoseconds" << std::endl;

  // Destroys the CmEvent.
  // CmEvent must be destroyed by the user explicitly.
  cm_result_check(queue->DestroyEvent(sync_event));

  // Destroys the CmDevice.
  // Also destroys surfaces, kernels, tasks, thread spaces, and queues that
  // were created using this device instance that have not explicitly been
  // destroyed by calling the respective destroy functions.
  cm_result_check(::DestroyCmDevice(device));

  // Uses the CPU to calculate the SAD output data. Then compare the CPU SAD
  // output data with the GPU SAD output data. If there is no difference, the
  // result is correct. Or else there is something wrong.
  bool passed = CompareSAD(VECTOR_LENGTH,
                           feature_vect,
                           feature_vect_num,
                           db_vect,
                           db_vect_num,
                           (unsigned short*)output_data);

  // Frees memories to avoid the memory leakage issue.
  CM_ALIGNED_FREE(feature_vect);
  CM_ALIGNED_FREE(db_vect);
  CM_ALIGNED_FREE(output_data);

  std::cout << (passed ? "PASSED" : "FAILED") << std::endl;
  return (passed ? 0 : -1);
}
