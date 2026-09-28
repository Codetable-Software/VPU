#ifndef VPU_VECTOR_H
#define VPU_VECTOR_H
#include "types.h"
vpu_status_t vpu_vector_add(const double*a,const double*b,double*out,size_t n); vpu_status_t vpu_vector_sub(const double*a,const double*b,double*out,size_t n); vpu_status_t vpu_vector_mul(const double*a,const double*b,double*out,size_t n); vpu_status_t vpu_vector_div(const double*a,const double*b,double*out,size_t n); vpu_status_t vpu_vector_min(const double*a,size_t n,double*out); vpu_status_t vpu_vector_max(const double*a,size_t n,double*out); vpu_status_t vpu_vector_sum(const double*a,size_t n,double*out); vpu_status_t vpu_vector_dot(const double*a,const double*b,size_t n,double*out);
#endif
