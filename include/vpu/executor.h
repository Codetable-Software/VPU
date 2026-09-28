#ifndef VPU_EXECUTOR_H
#define VPU_EXECUTOR_H
#include "core.h"
#include "instruction.h"
vpu_status_t vpu_execute_instruction(vpu_core_t*c,const vpu_instruction_t*i);
vpu_status_t vpu_execute_program(vpu_core_t*c,const uint8_t*program,size_t size,size_t max_steps,size_t*steps);
#endif
