#include "vpu/alu.h"
extern "C" uint64_t vpu_cpp_add(uint64_t a,uint64_t b){uint64_t r=0,f=0;return vpu_alu_exec(VPU_ALU_ADD,a,b,&r,&f)==VPU_OK?r:0;}
