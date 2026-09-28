#ifndef VPU_CACHE_H
#define VPU_CACHE_H
#include "types.h"
typedef struct { uint8_t *data; size_t line_size,lines; } vpu_cache_t;
vpu_status_t vpu_cache_init(vpu_cache_t*c,size_t lines,size_t line_size); void vpu_cache_destroy(vpu_cache_t*c); vpu_status_t vpu_cache_store(vpu_cache_t*c,size_t addr,const void*data,size_t size); vpu_status_t vpu_cache_load(const vpu_cache_t*c,size_t addr,void*out,size_t size);
#endif
