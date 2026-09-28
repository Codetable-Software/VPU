#include "vpu/api.h"
#include <assert.h>
int main(void){vpu_t v;assert(vpu_init(&v,NULL)==VPU_OK);assert(v.config.core_count==1);vpu_core_t*c;assert(vpu_core_get(&v,0,&c)==VPU_OK);assert(c->ctx.regs.sp==c->memory.size);vpu_shutdown(&v);return 0;}
