#include "vpu/api.h"
#include <stdio.h>
int main(void){double a[]={1,2,3},b[]={4,5,6},o[3],sum,dot;if(vpu_vector_add(a,b,o,3)||vpu_vector_sum(o,3,&sum)||vpu_vector_dot(a,b,3,&dot))return 1;printf("add=[%.0f %.0f %.0f] sum=%.0f dot=%.0f\n",o[0],o[1],o[2],sum,dot);return 0;}
