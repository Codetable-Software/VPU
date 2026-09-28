#include "vpu/context.h"
void vpu_context_reset(vpu_context_t*c){if(!c)return;vpu_registers_reset(&c->regs);c->state=VPU_CORE_HALTED;c->error=0;}
vpu_status_t vpu_context_validate(const vpu_context_t*c){return c?VPU_OK:VPU_ERR_NULL;}
