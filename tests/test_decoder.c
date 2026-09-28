#include "vpu/decoder.h"
#include <assert.h>
#include <string.h>
int main(void){uint8_t b[12]={VPU_OP_MOV,0,0,1};int64_t n=42;memcpy(b+4,&n,8);vpu_instruction_t i;size_t u;assert(vpu_decode(b,12,&i,&u)==VPU_OK&&i.opcode==VPU_OP_MOV&&i.dst==0&&i.imm==42&&u==12);b[0]=0x7e;assert(vpu_decode(b,12,&i,&u)==VPU_ERR_DECODE);return 0;}
