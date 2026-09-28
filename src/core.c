#include "vpu/core.h"
#include "vpu/executor.h"
#include <string.h>
vpu_status_t vpu_core_init(vpu_core_t*c,unsigned id,size_t ms,size_t cl){if(!c)return VPU_ERR_NULL;memset(c,0,sizeof(*c));c->id=id;vpu_context_reset(&c->ctx);vpu_status_t s=vpu_memory_init(&c->memory,ms);if(s)return s;s=vpu_cache_init(&c->cache,cl,64);if(s){vpu_memory_destroy(&c->memory);return s;}c->ctx.regs.sp=ms;c->ctx.state=VPU_CORE_RUNNING;return VPU_OK;}
void vpu_core_destroy(vpu_core_t*c){if(!c)return;vpu_cache_destroy(&c->cache);vpu_memory_destroy(&c->memory);vpu_context_reset(&c->ctx);}
vpu_status_t vpu_core_step(vpu_core_t*c,const uint8_t*p,size_t n){if(!c||!p)return VPU_ERR_NULL;if(c->ctx.state==VPU_CORE_HALTED)return VPU_ERR_HALTED;return vpu_execute_program(c,p,n,1,NULL);}
