#include "vpu/alu.h"
#include "vpu/flags.h"
#include <assert.h>
int main(void){uint64_t r,f;assert(vpu_alu_exec(VPU_ALU_ADD,2,3,&r,&f)==VPU_OK&&r==5);assert(vpu_alu_exec(VPU_ALU_SUB,3,5,&r,&f)==VPU_OK);assert(f&VPU_FLAG_NEGATIVE);assert(vpu_alu_exec(VPU_ALU_DIV,1,0,&r,&f)==VPU_ERR_DIVZERO);return 0;}
