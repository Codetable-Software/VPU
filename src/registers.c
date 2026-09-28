#include "vpu/registers.h"
#include <string.h>
void vpu_registers_reset(vpu_registers_t*r){if(r)memset(r,0,sizeof(*r));}
vpu_status_t vpu_reg_read(const vpu_registers_t*r,unsigned i,uint64_t*out){if(!r||!out)return VPU_ERR_NULL;if(i>=VPU_REGISTER_COUNT)return VPU_ERR_INVALID;*out=r->gpr[i];return VPU_OK;}
vpu_status_t vpu_reg_write(vpu_registers_t*r,unsigned i,uint64_t v){if(!r)return VPU_ERR_NULL;if(i>=VPU_REGISTER_COUNT)return VPU_ERR_INVALID;r->gpr[i]=v;return VPU_OK;}
vpu_status_t vpu_pc_get(const vpu_registers_t*r,uint64_t*out){if(!r||!out)return VPU_ERR_NULL;*out=r->pc;return VPU_OK;} void vpu_pc_set(vpu_registers_t*r,uint64_t pc){if(r)r->pc=pc;}
