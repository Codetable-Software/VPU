#include "vpu/scheduler.h"
vpu_status_t vpu_scheduler_init(vpu_scheduler_t*s,size_t cap,unsigned workers){if(!s||!workers)return VPU_ERR_INVALID;s->workers=workers;return vpu_queue_init(&s->queue,cap);}
void vpu_scheduler_destroy(vpu_scheduler_t*s){if(s)vpu_queue_destroy(&s->queue);}
vpu_status_t vpu_scheduler_submit(vpu_scheduler_t*s,const vpu_task_t*t){if(!s)return VPU_ERR_NULL;return vpu_queue_push(&s->queue,t);}
vpu_status_t vpu_scheduler_run_one(vpu_scheduler_t*s){if(!s)return VPU_ERR_NULL;vpu_task_t t;vpu_status_t x=vpu_queue_pop(&s->queue,&t);if(x)return x;return vpu_task_run(&t);}
vpu_status_t vpu_scheduler_run_all(vpu_scheduler_t*s){if(!s)return VPU_ERR_NULL;vpu_status_t last=VPU_OK;while(!vpu_queue_empty(&s->queue)){vpu_status_t x=vpu_scheduler_run_one(s);if(x)last=x;}return last;}
