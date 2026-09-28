#ifndef VPU_QUEUE_H
#define VPU_QUEUE_H
#include "task.h"
typedef struct { vpu_task_t *items; size_t capacity,count,head,tail; } vpu_queue_t;
vpu_status_t vpu_queue_init(vpu_queue_t*q,size_t capacity); void vpu_queue_destroy(vpu_queue_t*q); vpu_status_t vpu_queue_push(vpu_queue_t*q,const vpu_task_t*t); vpu_status_t vpu_queue_pop(vpu_queue_t*q,vpu_task_t*out); int vpu_queue_empty(const vpu_queue_t*q);
#endif
