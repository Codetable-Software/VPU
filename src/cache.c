#include "vpu/cache.h"
#include <stdlib.h>
#include <string.h>
vpu_status_t vpu_cache_init(vpu_cache_t*c,size_t lines,size_t ls){if(!c||!lines||!ls)return VPU_ERR_INVALID;if(lines>SIZE_MAX/ls)return VPU_ERR_OVERFLOW;if(ls>SIZE_MAX/lines)return VPU_ERR_OVERFLOW;c->data=calloc(lines,ls);if(!c->data)return VPU_ERR_NOMEM;c->lines=lines;c->line_size=ls;return VPU_OK;}
void vpu_cache_destroy(vpu_cache_t*c){if(!c)return;free(c->data);c->data=NULL;c->lines=c->line_size=0;}
static vpu_status_t chk(const vpu_cache_t*c,size_t a,size_t n){if(!c||!c->data)return VPU_ERR_NULL;if(c->lines>SIZE_MAX/c->line_size)return VPU_ERR_OVERFLOW;size_t total=c->lines*c->line_size;if(a>total||n>total-a)return VPU_ERR_BOUNDS;return VPU_OK;}
vpu_status_t vpu_cache_store(vpu_cache_t*c,size_t a,const void*d,size_t n){if(!d)return VPU_ERR_NULL;vpu_status_t s=chk(c,a,n);if(s)return s;memcpy(c->data+a,d,n);return VPU_OK;}
vpu_status_t vpu_cache_load(const vpu_cache_t*c,size_t a,void*d,size_t n){if(!d)return VPU_ERR_NULL;vpu_status_t s=chk(c,a,n);if(s)return s;memcpy(d,c->data+a,n);return VPU_OK;}
