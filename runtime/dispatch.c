#include "vpu/api.h"
vpu_status_t vpu_runtime_dispatch(vpu_t*v,vpu_task_t*t){if(!v||!t)return VPU_ERR_NULL;return vpu_scheduler_submit(&v->scheduler,t);}
