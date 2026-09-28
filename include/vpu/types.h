#ifndef VPU_TYPES_H
#define VPU_TYPES_H
#include <stdint.h>
#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif
typedef enum { VPU_OK=0, VPU_ERR_NULL=-1, VPU_ERR_NOMEM=-2, VPU_ERR_BOUNDS=-3, VPU_ERR_INVALID=-4, VPU_ERR_DIVZERO=-5, VPU_ERR_OVERFLOW=-6, VPU_ERR_EMPTY=-7, VPU_ERR_FULL=-8, VPU_ERR_HALTED=-9, VPU_ERR_DECODE=-10, VPU_ERR_IO=-11 } vpu_status_t;
typedef uint64_t vpu_word_t;
typedef uint32_t vpu_reg_t;
typedef uint64_t vpu_address_t;
typedef enum { VPU_CORE_HALTED=0, VPU_CORE_RUNNING=1 } vpu_core_state_t;
typedef enum { VPU_TASK_READY=0, VPU_TASK_RUNNING=1, VPU_TASK_DONE=2, VPU_TASK_FAILED=3 } vpu_task_state_t;
typedef struct { int code; const char *message; } vpu_error_t;
#ifdef __cplusplus
}
#endif
#endif
