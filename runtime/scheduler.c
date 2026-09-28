#include "vpu/api.h"
vpu_status_t vpu_runtime_schedule(vpu_t*v){if(!v)return VPU_ERR_NULL;return vpu_scheduler_run_all(&v->scheduler);}
