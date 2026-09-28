#include "vpu/api.h"
vpu_status_t vpu_runtime_worker(vpu_t*v){if(!v)return VPU_ERR_NULL;return vpu_scheduler_run_one(&v->scheduler);}
