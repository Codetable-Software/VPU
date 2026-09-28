#include "vpu/api.h"
#include <stdio.h>
int main(void){vpu_t v;if(vpu_init(&v,NULL))return 1;vpu_core_t*c;vpu_core_get(&v,0,&c);vpu_reg_write(&c->ctx.regs,VPU_R0,7);vpu_reg_write(&c->ctx.regs,VPU_R1,5);uint64_t r,f;vpu_alu_exec(VPU_ALU_ADD,7,5,&r,&f);printf("7+5=%llu flags=%llu\n",(unsigned long long)r,(unsigned long long)f);vpu_shutdown(&v);return 0;}
