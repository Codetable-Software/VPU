#ifndef VPU_TASK_H
#define VPU_TASK_H
#include "types.h"
typedef vpu_status_t (*vpu_task_fn)(void *payload, void *result);
typedef struct { uint64_t id; int priority; vpu_task_state_t state; vpu_task_fn fn; void *payload; void *result; vpu_status_t status; } vpu_task_t;
vpu_status_t vpu_task_init(vpu_task_t*t,uint64_t id,int priority,vpu_task_fn fn,void*payload,void*result); vpu_status_t vpu_task_run(vpu_task_t*t);
#endif
