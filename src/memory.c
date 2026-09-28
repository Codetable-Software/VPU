#include "vpu/memory.h"
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
vpu_status_t vpu_memory_init(vpu_memory_t*m,size_t size){if(!m||!size)return VPU_ERR_INVALID;m->data=calloc(1,size);if(!m->data)return VPU_ERR_NOMEM;m->size=size;m->used=0;return VPU_OK;}
void vpu_memory_destroy(vpu_memory_t*m){if(!m)return;free(m->data);m->data=NULL;m->size=m->used=0;}
vpu_status_t vpu_memory_alloc(vpu_memory_t*m,size_t size,size_t align,size_t*out){if(!m||!out)return VPU_ERR_NULL;if(!size)return VPU_ERR_INVALID;if(align==0)align=1;if((align&(align-1))!=0)return VPU_ERR_INVALID;if(align-1>SIZE_MAX-m->used)return VPU_ERR_OVERFLOW;size_t base=(m->used+align-1)&~(align-1);if(base>m->size||size>m->size-base)return VPU_ERR_NOMEM;m->used=base+size;*out=base;return VPU_OK;}
vpu_status_t vpu_memory_free(vpu_memory_t*m,size_t addr,size_t size){if(!m)return VPU_ERR_NULL;if(addr>m->size||size>m->size-addr)return VPU_ERR_BOUNDS;memset(m->data+addr,0,size);return VPU_OK;}
vpu_status_t vpu_memory_read(const vpu_memory_t*m,size_t a,void*out,size_t n){if(!m||!out)return VPU_ERR_NULL;if(a>m->size||n>m->size-a)return VPU_ERR_BOUNDS;memcpy(out,m->data+a,n);return VPU_OK;}
vpu_status_t vpu_memory_write(vpu_memory_t*m,size_t a,const void*in,size_t n){if(!m||!in)return VPU_ERR_NULL;if(a>m->size||n>m->size-a)return VPU_ERR_BOUNDS;memcpy(m->data+a,in,n);return VPU_OK;}
