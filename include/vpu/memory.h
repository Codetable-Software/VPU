#ifndef VPU_MEMORY_H
#define VPU_MEMORY_H
#include "types.h"
typedef struct { uint8_t *data; size_t size; size_t used; } vpu_memory_t;
vpu_status_t vpu_memory_init(vpu_memory_t*m,size_t size); void vpu_memory_destroy(vpu_memory_t*m); vpu_status_t vpu_memory_alloc(vpu_memory_t*m,size_t size,size_t align,size_t*out_addr); vpu_status_t vpu_memory_free(vpu_memory_t*m,size_t addr,size_t size); vpu_status_t vpu_memory_read(const vpu_memory_t*m,size_t addr,void*out,size_t size); vpu_status_t vpu_memory_write(vpu_memory_t*m,size_t addr,const void*in,size_t size);
#endif
