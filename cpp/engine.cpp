#include "vpu/api.h"
#include <stdexcept>
namespace vpu_cpp { class Engine { vpu_t v_{}; public: Engine(){if(vpu_init(&v_,nullptr)!=VPU_OK)throw std::bad_alloc();} ~Engine(){vpu_shutdown(&v_);} vpu_t* raw(){return &v_;} }; }
