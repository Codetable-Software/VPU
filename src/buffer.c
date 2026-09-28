#include "vpu/buffer.h"
#include <stdlib.h>
#include <string.h>
vpu_status_t vpu_buffer_init(vpu_buffer_t*b,size_t cap){if(!b)return VPU_ERR_NULL;b->data=cap?malloc(cap):NULL;if(cap&&!b->data)return VPU_ERR_NOMEM;b->size=0;b->capacity=cap;return VPU_OK;}
void vpu_buffer_destroy(vpu_buffer_t*b){if(!b)return;free(b->data);b->data=NULL;b->size=b->capacity=0;}
vpu_status_t vpu_buffer_resize(vpu_buffer_t*b,size_t n){if(!b)return VPU_ERR_NULL;if(n>b->capacity){size_t cap=b->capacity?b->capacity:16;while(cap<n){if(cap>SIZE_MAX/2)return VPU_ERR_OVERFLOW;cap*=2;}void*p=realloc(b->data,cap);if(!p)return VPU_ERR_NOMEM;b->data=p;b->capacity=cap;}b->size=n;return VPU_OK;}
vpu_status_t vpu_buffer_append(vpu_buffer_t*b,const void*d,size_t n){if(!b||(!d&&n))return VPU_ERR_NULL;if(n>SIZE_MAX-b->size)return VPU_ERR_OVERFLOW;vpu_status_t s=vpu_buffer_resize(b,b->size+n);if(s)return s;memcpy(b->data+b->size-n,d,n);return VPU_OK;}
