#ifndef VPU_CONFIG_H
#define VPU_CONFIG_H
#include <stddef.h>
#define VPU_REGISTER_COUNT 8
#define VPU_DEFAULT_MEMORY_SIZE (1024u*1024u)
#define VPU_DEFAULT_CACHE_LINES 64
#define VPU_DEFAULT_QUEUE_CAPACITY 64
typedef struct { size_t memory_size; size_t cache_lines; size_t queue_capacity; unsigned core_count; } vpu_config_t;
void vpu_config_default(vpu_config_t *cfg);
#endif
