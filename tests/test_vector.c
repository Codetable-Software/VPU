#include "vpu/vector.h"
#include <assert.h>
#include <math.h>
int main(void){double a[]={1,2,3},b[]={4,5,6},o[3],x;assert(vpu_vector_add(a,b,o,3)==VPU_OK&&o[2]==9);assert(vpu_vector_dot(a,b,3,&x)==VPU_OK&&fabs(x-32)<1e-9);assert(vpu_vector_div(a,(double[]){1,0,1},o,3)==VPU_ERR_DIVZERO);return 0;}
