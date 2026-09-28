#include "vpu/scheduler.h"
extern "C" int vpu_cpp_run_scheduler(vpu_scheduler_t*s){return vpu_scheduler_run_all(s);}
