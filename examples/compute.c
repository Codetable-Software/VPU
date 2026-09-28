#include "vpu/api.h"
#include <stdio.h>
int main(void){vpu_t v;if(vpu_init(&v,NULL))return 1;vpu_core_t*c;vpu_core_get(&v,0,&c);uint64_t a=11,b=4;size_t aa,bb;vpu_memory_alloc(&c->memory,8,8,&aa);vpu_memory_alloc(&c->memory,8,8,&bb);vpu_memory_write(&c->memory,aa,&a,8);vpu_memory_write(&c->memory,bb,&b,8);uint64_t x,y;vpu_memory_read(&c->memory,aa,&x,8);vpu_memory_read(&c->memory,bb,&y,8);uint64_t r,f;vpu_alu_exec(VPU_ALU_MUL,x,y,&r,&f);printf("%llu*%llu=%llu\n",(unsigned long long)x,(unsigned long long)y,(unsigned long long)r);vpu_shutdown(&v);return 0;}
