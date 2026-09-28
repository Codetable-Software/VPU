#include "vpu/scheduler.h"
#include <assert.h>
static vpu_status_t f(void*p,void*r){*(int*)r=*(int*)p+1;return VPU_OK;}
int main(void){vpu_scheduler_t s;assert(vpu_scheduler_init(&s,4,1)==VPU_OK);int x=4,y=0;vpu_task_t t;assert(vpu_task_init(&t,1,1,f,&x,&y)==VPU_OK);assert(vpu_scheduler_submit(&s,&t)==VPU_OK);assert(vpu_scheduler_run_all(&s)==VPU_OK&&y==5);vpu_scheduler_destroy(&s);return 0;}
