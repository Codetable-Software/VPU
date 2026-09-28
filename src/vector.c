#include "vpu/vector.h"
#include <math.h>
#define CHK(a,b,o,n) do{if((!a||!b||!o)&&n)return VPU_ERR_NULL;if(n>SIZE_MAX/sizeof(double))return VPU_ERR_OVERFLOW;}while(0)
vpu_status_t vpu_vector_add(const double*a,const double*b,double*o,size_t n){CHK(a,b,o,n);for(size_t i=0;i<n;i++)o[i]=a[i]+b[i];return VPU_OK;}
vpu_status_t vpu_vector_sub(const double*a,const double*b,double*o,size_t n){CHK(a,b,o,n);for(size_t i=0;i<n;i++)o[i]=a[i]-b[i];return VPU_OK;}
vpu_status_t vpu_vector_mul(const double*a,const double*b,double*o,size_t n){CHK(a,b,o,n);for(size_t i=0;i<n;i++)o[i]=a[i]*b[i];return VPU_OK;}
vpu_status_t vpu_vector_div(const double*a,const double*b,double*o,size_t n){CHK(a,b,o,n);for(size_t i=0;i<n;i++){if(b[i]==0)return VPU_ERR_DIVZERO;o[i]=a[i]/b[i];}return VPU_OK;}
vpu_status_t vpu_vector_min(const double*a,size_t n,double*o){if(!a||!o)return VPU_ERR_NULL;if(!n)return VPU_ERR_INVALID;*o=a[0];for(size_t i=1;i<n;i++)if(a[i]<*o)*o=a[i];return VPU_OK;}
vpu_status_t vpu_vector_max(const double*a,size_t n,double*o){if(!a||!o)return VPU_ERR_NULL;if(!n)return VPU_ERR_INVALID;*o=a[0];for(size_t i=1;i<n;i++)if(a[i]>*o)*o=a[i];return VPU_OK;}
vpu_status_t vpu_vector_sum(const double*a,size_t n,double*o){if(!a||!o)return VPU_ERR_NULL;*o=0;for(size_t i=0;i<n;i++)*o+=a[i];return VPU_OK;}
vpu_status_t vpu_vector_dot(const double*a,const double*b,size_t n,double*o){if((!a||!b||!o)&&n)return VPU_ERR_NULL;*o=0;for(size_t i=0;i<n;i++)*o+=a[i]*b[i];return VPU_OK;}
