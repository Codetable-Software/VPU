#include "vpu/api.h"
vpu_status_t vpu_runtime_memory(vpu_core_t*c,size_t n,size_t*out){if(!c)return VPU_ERR_NULL;return vpu_memory_alloc(&c->memory,n,8,out);}
