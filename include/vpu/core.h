#ifndef VPU_CORE_H
#define VPU_CORE_H
#include "context.h"
#include "memory.h"
#include "cache.h"
typedef struct { unsigned id; vpu_context_t ctx; vpu_memory_t memory; vpu_cache_t cache; } vpu_core_t;
vpu_status_t vpu_core_init(vpu_core_t*c,unsigned id,size_t memory_size,size_t cache_lines); void vpu_core_destroy(vpu_core_t*c); vpu_status_t vpu_core_step(vpu_core_t*c,const uint8_t*program,size_t program_size);
#endif
