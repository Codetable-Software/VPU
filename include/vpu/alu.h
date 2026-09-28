#ifndef VPU_ALU_H
#define VPU_ALU_H
#include "types.h"
typedef enum { VPU_ALU_ADD,VPU_ALU_SUB,VPU_ALU_MUL,VPU_ALU_DIV,VPU_ALU_MOD,VPU_ALU_AND,VPU_ALU_OR,VPU_ALU_XOR,VPU_ALU_NOT,VPU_ALU_SHL,VPU_ALU_SHR,VPU_ALU_CMP } vpu_alu_op_t;
vpu_status_t vpu_alu_exec(vpu_alu_op_t op,uint64_t a,uint64_t b,uint64_t *result,uint64_t *flags);
#endif
