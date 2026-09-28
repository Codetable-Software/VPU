#include "vpu/decoder.h"
#include <string.h>
#define SZ 12
static int valid(uint8_t op){switch(op){case VPU_OP_NOP:case VPU_OP_MOV:case VPU_OP_LOAD:case VPU_OP_STORE:case VPU_OP_ADD:case VPU_OP_SUB:case VPU_OP_MUL:case VPU_OP_DIV:case VPU_OP_MOD:case VPU_OP_AND:case VPU_OP_OR:case VPU_OP_XOR:case VPU_OP_NOT:case VPU_OP_SHL:case VPU_OP_SHR:case VPU_OP_CMP:case VPU_OP_JMP:case VPU_OP_JE:case VPU_OP_JNE:case VPU_OP_JG:case VPU_OP_JL:case VPU_OP_PUSH:case VPU_OP_POP:case VPU_OP_CALL:case VPU_OP_RET:case VPU_OP_HALT:return 1;default:return 0;}}
vpu_status_t vpu_decode(const uint8_t*b,size_t n,vpu_instruction_t*o,size_t*u){if(!b||!o||!u)return VPU_ERR_NULL;if(n<SZ)return VPU_ERR_BOUNDS;if(!valid(b[0]))return VPU_ERR_DECODE;if(b[1]>=8||b[2]>=8)return VPU_ERR_DECODE;memset(o,0,sizeof(*o));o->opcode=b[0];o->dst=b[1];o->src=b[2];o->flags=b[3];uint64_t x=0;memcpy(&x,b+4,8);o->imm=(int64_t)x;*u=SZ;return VPU_OK;}
