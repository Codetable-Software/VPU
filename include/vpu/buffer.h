#ifndef VPU_BUFFER_H
#define VPU_BUFFER_H
#include "types.h"
typedef struct { uint8_t *data; size_t size,capacity; } vpu_buffer_t;
vpu_status_t vpu_buffer_init(vpu_buffer_t*b,size_t capacity); void vpu_buffer_destroy(vpu_buffer_t*b); vpu_status_t vpu_buffer_resize(vpu_buffer_t*b,size_t size); vpu_status_t vpu_buffer_append(vpu_buffer_t*b,const void*data,size_t size);
#endif
