#include "vpu/vector.h"
extern "C" int vpu_cpp_vector_sum(const double*a,size_t n,double*out){return vpu_vector_sum(a,n,out);}
