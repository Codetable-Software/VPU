#include "vpu/api.h"
#include <stdio.h>
static vpu_status_t work(void*p,void*r){*(int*)r=*(int*)p*2;return VPU_OK;}
int main(void){vpu_t v;if(vpu_init(&v,NULL))return 1;int in=21,out=0;vpu_task_t t;vpu_task_init(&t,1,1,work,&in,&out);vpu_scheduler_submit(&v.scheduler,&t);vpu_status_t s=vpu_scheduler_run_all(&v.scheduler);printf("status=%s result=%d\n",vpu_status_string(s),out);vpu_shutdown(&v);return s?1:0;}
