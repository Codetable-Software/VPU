#ifndef VPU_SCHEDULER_H
#define VPU_SCHEDULER_H
#include "queue.h"
typedef struct { vpu_queue_t queue; unsigned workers; } vpu_scheduler_t;
vpu_status_t vpu_scheduler_init(vpu_scheduler_t*s,size_t capacity,unsigned workers); void vpu_scheduler_destroy(vpu_scheduler_t*s); vpu_status_t vpu_scheduler_submit(vpu_scheduler_t*s,const vpu_task_t*t); vpu_status_t vpu_scheduler_run_one(vpu_scheduler_t*s); vpu_status_t vpu_scheduler_run_all(vpu_scheduler_t*s);
#endif
