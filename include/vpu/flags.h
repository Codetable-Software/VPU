#ifndef VPU_FLAGS_H
#define VPU_FLAGS_H
#include <stdint.h>
enum { VPU_FLAG_ZERO=1u<<0, VPU_FLAG_NEGATIVE=1u<<1, VPU_FLAG_CARRY=1u<<2, VPU_FLAG_OVERFLOW=1u<<3 };
void vpu_flags_set(uint64_t *flags, uint64_t value); void vpu_flags_update_arith(uint64_t *flags,uint64_t a,uint64_t b,uint64_t result,int subtract);
#endif
