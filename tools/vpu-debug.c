#include "vpu/api.h"
#include <stdio.h>
int main(void){vpu_t v;if(vpu_init(&v,NULL))return 1;vpu_core_t*c;vpu_core_get(&v,0,&c);printf("core=%u pc=%llu sp=%llu state=%d\n",c->id,(unsigned long long)c->ctx.regs.pc,(unsigned long long)c->ctx.regs.sp,c->ctx.state);for(unsigned i=0;i<8;i++)printf("R%u=%llu\n",i,(unsigned long long)c->ctx.regs.gpr[i]);vpu_shutdown(&v);return 0;}
