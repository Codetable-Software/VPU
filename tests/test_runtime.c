#include "vpu/api.h"
#include <assert.h>
static vpu_status_t f(void*p,void*r){*(int*)r=*(int*)p*3;return VPU_OK;}
int main(void){vpu_t v;assert(vpu_init(&v,NULL)==VPU_OK);int x=7,y=0;vpu_task_t t;assert(vpu_task_init(&t,2,1,f,&x,&y)==VPU_OK);assert(vpu_scheduler_submit(&v.scheduler,&t)==VPU_OK);assert(vpu_scheduler_run_one(&v.scheduler)==VPU_OK&&y==21);vpu_shutdown(&v);return 0;}
