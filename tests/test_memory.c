#include "vpu/api.h"
#include <assert.h>
#include <string.h>
int main(void){vpu_memory_t m;assert(vpu_memory_init(&m,64)==VPU_OK);size_t a;assert(vpu_memory_alloc(&m,8,8,&a)==VPU_OK);uint64_t x=123,y=0;assert(vpu_memory_write(&m,a,&x,8)==VPU_OK);assert(vpu_memory_read(&m,a,&y,8)==VPU_OK);assert(x==y);assert(vpu_memory_read(&m,60,&y,8)==VPU_ERR_BOUNDS);vpu_memory_destroy(&m);return 0;}
