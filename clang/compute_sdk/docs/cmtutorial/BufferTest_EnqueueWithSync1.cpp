/*========================== begin_copyright_notice ============================

Copyright (C) 2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

#include <cstdio>

// The only CM runtime header file that you need is cm_rt.h.
// It includes all of the CM runtime.
#include "cm_rt.h"
#include "cm_loadprogram.h"

// Includes bitmap_helpers.h for bitmap file open/save operations.
#include "common/bitmap_helpers.h"

// Includes cm_rt_helpers.h to convert the integer return code returned from
// the CM runtime to a meaningful string message.
#include "common/cm_rt_helpers.h"

// Includes isa_helpers.h to load the ISA file generated by the CM compiler.
#include "common/isa_helpers.h"

using cm::util::bitmap::BitMap;
using cm::util::isa::loadFile;

#define KERNEL_NUM_PER_TASK 16

int BufferTest_Sync_MediaWalker() {
    printf("Running %s()...\n", __FUNCTION__);

    // Defines buffer size and initial value to initialize input surface
    // and reference result.
    unsigned int width = 256;
    unsigned char init_value = 0x55;

    // Allocates system memory for input data used for initializing input
    // surface, and fills memory with init_value.
    unsigned char *input_data = new unsigned char[width];
    memset(input_data, init_value, width);

    // Allocates system memory for containing output data, and fills memory
    // with 0.
    unsigned char *output_data = new unsigned char[width];
    memset(output_data, 0, width);

    // Allocates system memory for containing reference data, and fills
    // memory with value (init_value + KERNEL_NUM_PER_TASK).
    unsigned char *ref_data = new unsigned char[width];
    memset(ref_data, (init_value + KERNEL_NUM_PER_TASK), width);

    // Creates a CmDevice from scratch.
    // Param device: pointer to the CmDevice object.
    // Param version: CM API version supported by the runtime library.
    CmDevice *device = nullptr;
    unsigned int version = 0;
    cm_result_check(::CreateCmDevice(device, version));

    // The file BufferTest_EnqueueWithSync1_genx.isa is generated when the
    // kernels in the file BufferTest_EnqueueWithSync1_genx.cpp are compiled
    // by the CM compiler.
    // Reads in the virtual ISA from "BufferTest_EnqueueWithSync1_genx.isa"
    // to the code buffer.
    std::string isa_code = loadFile("BufferTest_EnqueueWithSync1_genx.isa");
    if (isa_code.size() == 0) {
        std::cerr << "Error: empty ISA binary.\n";
        std::exit(1);
    }

    // Creates a CmProgram object consisting of the kernels loaded from the code
    // buffer.
    // Param isa_code.data(): Pointer to the code buffer containing the virtual
    // ISA.
    // Param isa_code.size(): Size in bytes of the code buffer containing the
    // virtual ISA.
    CmProgram *program = nullptr;
    cm_result_check(CmDevLoadProgram(device, const_cast<char *>(isa_code.data()),
                                        isa_code.size(),
                                        program));


    // Creates a CmBuffer of the specified size in bytes.
    CmBuffer *buffer = nullptr;
    cm_result_check(device->CreateBuffer(width, buffer));

    // Copies system memory content to the CmBuffer using the CPU. The
    // system memory content is the data in the input_data. The size of data
    // copied is the size of data in the CmBuffer.
    cm_result_check(buffer->WriteSurface(input_data, nullptr));

    // Creates an array consisting of 16 CmKernel objects.
    // Creates an array consisting of 16 CmBuffer objects.
    CmKernel *kernel[KERNEL_NUM_PER_TASK];
    CmBuffer *output_surface[KERNEL_NUM_PER_TASK];
    for (int i = 0; i < KERNEL_NUM_PER_TASK; i++) {
        // Creates every CmBuffer in the array with the specified size
        // in bytes.
        output_surface[i] = nullptr;
        cm_result_check(device->CreateBuffer(width, output_surface[i]));

        // Creates every kernel in the array.
        // Param program: CM Program from which the kernel is created.
        // Param "BufferTest": The kernel name which should be
        // no more than 256 bytes including the null terminator.
        kernel[i] = nullptr;
        cm_result_check(device->CreateKernel(program,
                                             "BufferTest",
                                             kernel[i]));
    }

    // Here, for "BufferTest" kernel, each thread works on a block of 64 bytes.
    // The thread width is equal to the CmBuffer size divided by 64.
    unsigned int thread_width = width / 64 ;

    // Creates a CmThreadSpace object.
    // There are two usage models for the thread space. One is to define the
    // dependency between threads to run in the GPU. The other is to define a
    // thread space where each thread can get a pair of coordinates during
    // kernel execution. For this example, we use the latter usage model.
    CmThreadSpace *thread_space = nullptr;
    cm_result_check(device->CreateThreadSpace(thread_width,
                                              1,
                                              thread_space));

    // Creates a CmTask object.
    // The CmTask object is a container for CmKernel pointers. It is used to
    // enqueue the kernels for execution.
    CmTask *task = nullptr;
    cm_result_check(device->CreateTask(task));

    for (int i = 0; i < KERNEL_NUM_PER_TASK; i++) {
        // Associates a thread space to this kernel.
        cm_result_check(kernel[i]->AssociateThreadSpace(thread_space));

        // When a CmBuffer is created by the CmDevice a SurfaceIndex object is
        // created. This object contains a unique index value that is mapped
        // to the CmBuffer.
        // Uses the output CmBuffer of previous kernel as the input CmBuffer of
        // this kernel.
        SurfaceIndex *input_surface_idx = nullptr;
        SurfaceIndex *output_surface_idx = nullptr;
        if (i == 0) {
            // Gets the input CmBuffer index.
            input_surface_idx = nullptr;
            buffer->GetIndex(input_surface_idx);
            // Gets the output CmBuffer index.
            output_surface_idx = nullptr;
            output_surface[i]->GetIndex(output_surface_idx);
        } else {
            // Gets the input CmBuffer index.
            input_surface_idx = nullptr;
            output_surface[i - 1]->GetIndex(input_surface_idx);
            // Gets the output CmBuffer index.
            output_surface_idx = nullptr;
            output_surface[i]->GetIndex(output_surface_idx);
        }

        // Sets a per kernel argument.
        // Sets the input CmBuffer index as the first argument of the kernel.
        // Sets the output CmBuffer index as the second argument of the kernel.
        cm_result_check(kernel[i]->SetKernelArg(0,
                                                sizeof(SurfaceIndex),
                                                input_surface_idx));
        cm_result_check(kernel[i]->SetKernelArg(1,
                                                sizeof(SurfaceIndex),
                                                output_surface_idx));

        // Adds a CmKernel pointer to CmTask.
        // This task has 16 kernels.
        cm_result_check(task->AddKernel(kernel[i]));

        // Inserts a synchronization pointer between two kernels(except for
        // the last one).
        // The 2nd kernel only will be executed after the 1st kernel finishes
        // execution.
        if (i < (KERNEL_NUM_PER_TASK - 1)) {
            cm_result_check(task->AddSync());
        }
    }

    // Creates a task queue.
    // The CmQueue is an in-order queue. Tasks get executed according to the
    // order they are enqueued. The next task does not start execution until the
    // current task finishes.
    CmQueue *cmd_queue = nullptr;
    cm_result_check(device->CreateQueue(cmd_queue));

    // Launches the task on the GPU. Enqueue is a non-blocking call, i.e. the
    // function returns immediately without waiting for the GPU to start or
    // finish execution of the task. The runtime will query the HW status. If
    // the hardware is not busy, the runtime will submit the task to the
    // driver/HW; otherwise, the runtime will submit the task to the driver/HW
    // at another time.
    // An event, "sync_event", is created to track the status of the task.
    CmEvent *sync_event = nullptr;
    cm_result_check(cmd_queue->Enqueue(task, sync_event));

    // Destroys a CmTask object.
    // CmTask will be destroyed when CmDevice is destroyed.
    // Here, the application destroys the CmTask object by itself.
    cm_result_check(device->DestroyTask(task));

    // Destroys a CmThreadSpace object.
    // CmThreadSpace will be destroyed when CmDevice is destroyed.
    // Here, the application destroys the CmThreadSpace object by itself.
    cm_result_check(device->DestroyThreadSpace(thread_space));

    // Reads the CmBuffer content to the system memory using the CPU.
    // The size of data copied is the size of data in the CmBuffer.
    // It is a blocking call. The function will not return until the copy
    // operation is completed.
    // The dependent event "sync_event" ensures that the reading of the CmBuffer
    // will not happen until its state becomes CM_STATUS_FINISHED.
    cm_result_check(output_surface[KERNEL_NUM_PER_TASK - 1]->
        ReadSurface(output_data, sync_event));

    // Destroys the CmEvent.
    // CmEvent must be destroyed by the user explicitly.
    cm_result_check(cmd_queue->DestroyEvent(sync_event));

    // Destroys the CmDevice.
    // Also destroys surfaces, kernels, tasks, thread spaces, and queues that
    // were created using this device instance that have not explicitly been
    // destroyed by calling the respective destroy functions.
    cm_result_check(::DestroyCmDevice(device));

    // Compares the GPU result with the reference result.
    // If they are identical, the result is correct.
    // Or else there is something wrong.
    int hr = 0;
    if (!memcmp(output_data, ref_data, width)) {
        printf("Final Output is CORRECT\n");
        hr = 0;
    } else {
        printf("Final Output is WRONG\n");
        printf("Expected:");
        for (int i = 0; i < width; i++) {
            printf("0x%x ", ref_data[i]);
        }
        printf("\n");
        printf("Actual:");
        for (int i = 0; i < width; i++) {
            printf("0x%x ", output_data[i]);
        }
        hr = -1;
    }

    // Frees memory
    delete[] input_data;
    delete[] output_data;
    delete[] ref_data;

    return hr;
}

int BufferTest_Sync_GPGPUWalker() {
    printf("Running %s()...\n", __FUNCTION__);

    // Defines buffer size and initial value to initialize input surface
    // and reference result.
    unsigned int width = 256;
    unsigned char init_value = 0x55;

    // Allocates system memory for input data used for initializing input
    // surface, and fills memory with init_value.
    unsigned char *input_data = new unsigned char[width];
    memset(input_data, init_value, width);

    // Allocates system memory for containing output data, and fills memory
    // with 0.
    unsigned char *output_data = new unsigned char[width];
    memset(output_data, 0, width);

    // Allocates system memory for containing reference data, and fills
    // memory with value (init_value + KERNEL_NUM_PER_TASK).
    unsigned char *ref_data = new unsigned char[width];
    memset(ref_data, (init_value + KERNEL_NUM_PER_TASK), width);

    // Creates a CmDevice from scratch.
    // Param device: pointer to the CmDevice object.
    // Param version: CM API version supported by the runtime library.
    CmDevice *device = nullptr;
    unsigned int version = 0;
    cm_result_check(::CreateCmDevice(device, version));

    // The file BufferTest_EnqueueWithSync1_genx.isa is generated when the
    // kernels in the file BufferTest_EnqueueWithSync1_genx.cpp are compiled
    // by the CM compiler.
    // Reads in the virtual ISA from "BufferTest_EnqueueWithSync1_genx.isa"
    // to the code buffer.
    std::string isa_code = loadFile("BufferTest_EnqueueWithSync1_genx.isa");
    if (isa_code.size() == 0) {
        std::cerr << "Error: empty ISA binary.\n";
        std::exit(1);
    }

    // Creates a CmProgram object consisting of the kernels loaded from the code
    // buffer.
    // Param isa_code.data(): Pointer to the code buffer containing the virtual
    // ISA.
    // Param isa_code.size(): Size in bytes of the code buffer containing the
    // virtual ISA.
    CmProgram *program = nullptr;
    cm_result_check(CmDevLoadProgram(device, const_cast<char *>(isa_code.data()),
                                        isa_code.size(),
                                        program));

    // Creates a CmBuffer of the specified size in bytes.
    CmBuffer *buffer = nullptr;
    cm_result_check(device->CreateBuffer(width, buffer));

    // Copies system memory content to the input CmBuffer using the CPU. The
    // system memory content is the data in the input_data. The size of data
    // copied is the size of data in the CmBuffer.
    cm_result_check(buffer->WriteSurface(input_data, nullptr));

    // Creates an array consisting of 16 CmKernel objects.
    // Creates an array consisting of 16 CmBuffer objects.
    CmKernel *kernel[KERNEL_NUM_PER_TASK];
    CmBuffer *output_surface[KERNEL_NUM_PER_TASK];
    for (int i = 0; i < KERNEL_NUM_PER_TASK; i++) {
        // Creates every CmBuffer in the array with the specified size
        // in bytes.
        output_surface[i] = nullptr;
        cm_result_check(device->CreateBuffer(width, output_surface[i]));

        // Creates every kernel in the array.
        // Param program: CM Program from which the kernel is created.
        // Param "BufferTest_GPGPU": The kernel name which should be
        // no more than 256 bytes including the null terminator.
        kernel[i] = nullptr;
        cm_result_check(device->CreateKernel(program,
                                             "BufferTest_GPGPU",
                                             kernel[i]));
    }

    // Here, for "BufferTest_GPGPU" kernel, each thread works on a block of
    // 64 bytes
    // The thread width is equal to the buffer size divided by 64.
    unsigned int thread_width = width / 64 ;

    // Creates a thread group space specified by the height and width dimensions
    // of the group space, and the height and width dimensions of the thread
    // space within a group.
    CmThreadGroupSpace *thread_groupspace = nullptr;
    cm_result_check(device->CreateThreadGroupSpace(1,
                                                   1,
                                                   thread_width,
                                                   1,
                                                   thread_groupspace));

    // Creates a CmTask object.
    // The CmTask object is a container for CmKernel pointers. It is used to
    // enqueue the kernels for execution.
    CmTask *task = nullptr;
    cm_result_check(device->CreateTask(task));

    for (int i = 0; i < KERNEL_NUM_PER_TASK; i++) {
        // Associates a thread space to this kernel.
        cm_result_check(kernel[i]->AssociateThreadGroupSpace(thread_groupspace));

        // When a CmBuffer is created by the CmDevice a SurfaceIndex object is
        // created. This object contains a unique index value that is mapped
        // to the CmBuffer.
        // Uses the output CmBuffer of previous kernel as the input CmBuffer of
        // this kernel.
        SurfaceIndex *input_surface_idx = nullptr;
        SurfaceIndex *output_surface_idx = nullptr;
        if (i == 0) {
            // Gets the input CmBuffer index.
            input_surface_idx = nullptr;
            buffer->GetIndex(input_surface_idx);
            // Gets the output CmBuffer index.
            output_surface_idx = nullptr;
            output_surface[i]->GetIndex(output_surface_idx);
        } else {
            // Gets the input CmBuffer index.
            input_surface_idx = nullptr;
            output_surface[i - 1]->GetIndex(input_surface_idx);
            // Gets the output CmBuffer index.
            output_surface_idx = nullptr;
            output_surface[i]->GetIndex(output_surface_idx);
        }

        // Sets a per kernel argument.
        // Sets the input CmBuffer index as the first argument of the kernel.
        // Sets the output CmBuffer index as the second argument of the kernel.
        cm_result_check(kernel[i]->SetKernelArg(0,
                                                sizeof(SurfaceIndex),
                                                input_surface_idx));
        cm_result_check(kernel[i]->SetKernelArg(1,
                                                sizeof(SurfaceIndex),
                                                output_surface_idx));

        // Adds a CmKernel pointer to CmTask.
        // This task has 16 kernels.
        cm_result_check(task->AddKernel(kernel[i]));

        // Inserts a synchronization pointer between two kernels(except for the
        // last one).
        // The 2nd kernel only will be executed after the 1st kernel finises
        // execution.
        if (i < (KERNEL_NUM_PER_TASK - 1)) {
            cm_result_check(task->AddSync());
        }
    }

    // Creates a task queue.
    // The CmQueue is an in-order queue. Tasks get executed according to the
    // order they are enqueued. The next task does not start execution until the
    // current task finishes.
    CmQueue *cmd_queue = nullptr;
    cm_result_check(device->CreateQueue(cmd_queue));

    // Launches the task on the GPU. Enqueue is a non-blocking call, i.e. the
    // function returns immediately without waiting for the GPU to start or
    // finish execution of the task. The runtime will query the HW status. If
    // the hardware is not busy, the runtime will submit the task to the
    // driver/HW; otherwise, the runtime will submit the task to the driver/HW
    // at another time.
    // An event, "sync_event", is created to track the status of the task.
    CmEvent *sync_event = nullptr;
    cm_result_check(cmd_queue->EnqueueWithGroup(task, sync_event));

    // Destroys a CmTask object.
    // CmTask will be destroyed when CmDevice is destroyed.
    // Here, the application destroys the CmTask object by itself.
    cm_result_check(device->DestroyTask(task));

    // Reads the CmBuffer content to the system memory using the CPU.
    // The size of data copied is the size of data in the CmBuffer.
    // It is a blocking call. The function will not return until the copy
    // operation is completed.
    // The dependent event "sync_event" ensures that the reading of the CmBuffer
    // will not happen until its state becomes CM_STATUS_FINISHED.
    cm_result_check(output_surface[KERNEL_NUM_PER_TASK - 1]->
        ReadSurface(output_data, sync_event));

    // Destroys the CmEvent.
    // CmEvent must be destroyed by the user explicitly.
    cm_result_check(cmd_queue->DestroyEvent(sync_event));

    // Destroys the CmDevice.
    // Also destroys surfaces, kernels, tasks, thread spaces, and queues that
    // were created using this device instance that have not explicitly been
    // destroyed by calling the respective destroy functions.
    cm_result_check(::DestroyCmDevice(device));

    // Compares the GPU result with the reference result.
    // If they are identical, the result is correct.
    // Or else there is something wrong.
    int hr = 0;
    if (!memcmp(output_data, ref_data, width)) {
        printf("Final Output is CORRECT\n");
            hr = 0;
    } else {
        printf("Final Output is WRONG\n");
        printf("Expected:");
        for (int i = 0; i < width; i++) {
            printf("0x%x ", ref_data[i]);
        }
        printf("\n");
        printf("Actual:");
        for (int i = 0; i < width; i++) {
            printf("0x%x ", output_data[i]);
        }
        hr = -1;
    }

    // Frees memory
    delete[] input_data;
    delete[] output_data;
    delete[] ref_data;

    return hr;
}

int main(int argc, char *argv[]) {
    int result = 0;

    // Inserts synchronization point among different kernel instances
    // within a CmTask, and dispatches the task with media walker.
    result |= BufferTest_Sync_MediaWalker();

    // Inserts synchronization point among different kernel instances
    // within a CmTask, and dispatches the task with GPGPU walker.
    result |= BufferTest_Sync_GPGPUWalker();

    if (!result) {
        printf("BufferTest_EnqueueWithSync PASSED\n");
    } else {
        printf("BufferTest_EnqueueWithSync FAILED\n");
    }

    return result;
}
