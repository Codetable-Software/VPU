#include "vpu/flags.h"
#include <stdint.h>
void vpu_flags_set(uint64_t*f,uint64_t v){if(f)*f=v;}
void vpu_flags_update_arith(uint64_t*f,uint64_t a,uint64_t b,uint64_t r,int sub){if(!f)return;uint64_t x=0;if(r==0)x|=VPU_FLAG_ZERO;if((int64_t)r<0)x|=VPU_FLAG_NEGATIVE;if(sub){if(a<b)x|=VPU_FLAG_CARRY;if(((a^b)&(a^r))>>63)x|=VPU_FLAG_OVERFLOW;}else{if(r<a)x|=VPU_FLAG_CARRY;if((~(a^b)&(a^r))>>63)x|=VPU_FLAG_OVERFLOW;}*f=x;}
