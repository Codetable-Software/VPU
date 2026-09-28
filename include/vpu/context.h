#ifndef VPU_CONTEXT_H
#define VPU_CONTEXT_H
#include "registers.h"
typedef struct { vpu_registers_t regs; vpu_core_state_t state; int error; } vpu_context_t;
void vpu_context_reset(vpu_context_t *ctx); vpu_status_t vpu_context_validate(const vpu_context_t *ctx);
#endif
