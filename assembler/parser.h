#ifndef VPU_ASM_PARSER_H
#define VPU_ASM_PARSER_H
#include "lexer.h"
#include "../include/vpu/instruction.h"
typedef struct {vpu_instruction_t ins; size_t source_pos;} asm_statement;
int asm_parse_line(const char*line,asm_statement*out,char*err,size_t errcap);
#endif
