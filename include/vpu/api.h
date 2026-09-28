#ifndef VPU_API_H
#define VPU_API_H
#include "core.h"
#include "config.h"
#include "scheduler.h"
#include "executor.h"
#include "alu.h"
#include "vector.h"
#include "version.h"
typedef struct { vpu_config_t config; vpu_core_t *cores; vpu_scheduler_t scheduler; } vpu_t;
vpu_status_t vpu_init(vpu_t*v,const vpu_config_t*cfg); void vpu_shutdown(vpu_t*v); const char*vpu_status_string(vpu_status_t s); vpu_status_t vpu_core_get(vpu_t*v,unsigned id,vpu_core_t**out);
#endif
