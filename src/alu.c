#include "vpu/alu.h"
#include "vpu/flags.h"
#include <stdint.h>
#if defined(__x86_64__) || defined(__aarch64__) || defined(__riscv)
extern uint64_t vpu_arch_add_u64(uint64_t,uint64_t);
#endif
vpu_status_t vpu_alu_exec(vpu_alu_op_t op,uint64_t a,uint64_t b,uint64_t*r,uint64_t*f){
 if(!r||!f)return VPU_ERR_NULL;
 uint64_t x=0;
 switch(op){
 case VPU_ALU_ADD:
#if defined(__x86_64__) || defined(__aarch64__) || defined(__riscv)
  x=vpu_arch_add_u64(a,b);
#else
  x=a+b;
#endif
  vpu_flags_update_arith(f,a,b,x,0);break;
 case VPU_ALU_SUB:x=a-b;vpu_flags_update_arith(f,a,b,x,1);break;
 case VPU_ALU_MUL:x=a*b;*f=(x==0?VPU_FLAG_ZERO:((int64_t)x<0?VPU_FLAG_NEGATIVE:0));if(a&&x/a!=b)*f|=VPU_FLAG_OVERFLOW;break;
 case VPU_ALU_DIV:if(!b)return VPU_ERR_DIVZERO;x=a/b;*f=x?0:VPU_FLAG_ZERO;break;
 case VPU_ALU_MOD:if(!b)return VPU_ERR_DIVZERO;x=a%b;*f=x?0:VPU_FLAG_ZERO;break;
 case VPU_ALU_AND:x=a&b;*f=x?0:VPU_FLAG_ZERO;break;
 case VPU_ALU_OR:x=a|b;*f=x?0:VPU_FLAG_ZERO;break;
 case VPU_ALU_XOR:x=a^b;*f=x?0:VPU_FLAG_ZERO;break;
 case VPU_ALU_NOT:x=~a;*f=0;break;
 case VPU_ALU_SHL:x=a<<(b&63);*f=x?0:VPU_FLAG_ZERO;break;
 case VPU_ALU_SHR:x=a>>(b&63);*f=x?0:VPU_FLAG_ZERO;break;
 case VPU_ALU_CMP:x=a-b;vpu_flags_update_arith(f,a,b,x,1);break;
 default:return VPU_ERR_INVALID;}
 *r=x;return VPU_OK;
}
