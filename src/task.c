#include "vpu/task.h"
vpu_status_t vpu_task_init(vpu_task_t*t,uint64_t id,int p,vpu_task_fn fn,void*payload,void*result){if(!t||!fn)return VPU_ERR_NULL;t->id=id;t->priority=p;t->state=VPU_TASK_READY;t->fn=fn;t->payload=payload;t->result=result;t->status=VPU_OK;return VPU_OK;}
vpu_status_t vpu_task_run(vpu_task_t*t){if(!t||!t->fn)return VPU_ERR_NULL;if(t->state!=VPU_TASK_READY)return VPU_ERR_INVALID;t->state=VPU_TASK_RUNNING;t->status=t->fn(t->payload,t->result);t->state=t->status==VPU_OK?VPU_TASK_DONE:VPU_TASK_FAILED;return t->status;}
