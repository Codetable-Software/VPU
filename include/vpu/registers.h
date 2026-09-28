#ifndef VPU_REGISTERS_H
#define VPU_REGISTERS_H
#include "types.h"
#include "config.h"
typedef enum { VPU_R0=0,VPU_R1,VPU_R2,VPU_R3,VPU_R4,VPU_R5,VPU_R6,VPU_R7 } vpu_gpr_t;
typedef struct { uint64_t gpr[VPU_REGISTER_COUNT]; uint64_t pc,sp,flags,ir; } vpu_registers_t;
void vpu_registers_reset(vpu_registers_t *r); vpu_status_t vpu_reg_read(const vpu_registers_t *r,unsigned idx,uint64_t *out); vpu_status_t vpu_reg_write(vpu_registers_t *r,unsigned idx,uint64_t value); vpu_status_t vpu_pc_get(const vpu_registers_t*r,uint64_t*out); void vpu_pc_set(vpu_registers_t*r,uint64_t pc);
#endif
