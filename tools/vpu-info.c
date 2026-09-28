#include "vpu/api.h"
#include <stdio.h>
int main(void){vpu_config_t c;vpu_config_default(&c);printf("%s\nversion %s\ncores %u\nmemory %zu\n",VPU_NAME,VPU_VERSION_STRING,c.core_count,c.memory_size);return 0;}
