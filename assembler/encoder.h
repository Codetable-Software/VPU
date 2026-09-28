#ifndef VPU_ASM_ENCODER_H
#define VPU_ASM_ENCODER_H
#include "parser.h"
#include <stddef.h>
size_t asm_encode(const asm_statement*s,unsigned char*out,size_t cap);
int asm_assemble(const char*text,unsigned char**out,size_t*len,char*err,size_t errcap);
#endif
