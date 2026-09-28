#include "vpu/queue.h"
#include <stdlib.h>
vpu_status_t vpu_queue_init(vpu_queue_t*q,size_t cap){if(!q||!cap)return VPU_ERR_INVALID;q->items=calloc(cap,sizeof(*q->items));if(!q->items)return VPU_ERR_NOMEM;q->capacity=cap;q->count=q->head=q->tail=0;return VPU_OK;}
void vpu_queue_destroy(vpu_queue_t*q){if(!q)return;free(q->items);q->items=NULL;q->capacity=q->count=q->head=q->tail=0;}
vpu_status_t vpu_queue_push(vpu_queue_t*q,const vpu_task_t*t){if(!q||!t)return VPU_ERR_NULL;if(q->count==q->capacity)return VPU_ERR_FULL;q->items[q->tail]=*t;q->tail=(q->tail+1)%q->capacity;q->count++;return VPU_OK;}
vpu_status_t vpu_queue_pop(vpu_queue_t*q,vpu_task_t*out){if(!q||!out)return VPU_ERR_NULL;if(!q->count)return VPU_ERR_EMPTY;*out=q->items[q->head];q->head=(q->head+1)%q->capacity;q->count--;return VPU_OK;}
int vpu_queue_empty(const vpu_queue_t*q){return !q||q->count==0;}
