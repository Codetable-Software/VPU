#include "vpu/api.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char**argv){if(argc!=2){fprintf(stderr,"usage: vpu-run program.vpu\n");return 2;}FILE*f=fopen(argv[1],"rb");if(!f)return 1;fseek(f,0,SEEK_END);long n=ftell(f);fseek(f,0,SEEK_SET);if(n<0){fclose(f);return 1;}uint8_t*p=malloc((size_t)n);if(!p){fclose(f);return 1;}fread(p,1,(size_t)n,f);fclose(f);vpu_t v;vpu_status_t s=vpu_init(&v,NULL);if(!s){vpu_core_t*c;vpu_core_get(&v,0,&c);s=vpu_execute_program(c,p,(size_t)n,100000,NULL);printf("status: %s\nR0=%llu R1=%llu\n",vpu_status_string(s),(unsigned long long)c->ctx.regs.gpr[0],(unsigned long long)c->ctx.regs.gpr[1]);vpu_shutdown(&v);}free(p);return s?1:0;}
