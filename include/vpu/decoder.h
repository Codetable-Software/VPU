#ifndef VPU_DECODER_H
#define VPU_DECODER_H
#include "instruction.h"
vpu_status_t vpu_decode(const uint8_t *bytes,size_t len,vpu_instruction_t*out,size_t*used);
#endif
