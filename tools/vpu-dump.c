#include "vpu/decoder.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char**argv){if(argc!=2)return 2;FILE*f=fopen(argv[1],"rb");if(!f)return 1;fseek(f,0,SEEK_END);long n=ftell(f);fseek(f,0,SEEK_SET);uint8_t*b=malloc((size_t)n);fread(b,1,(size_t)n,f);fclose(f);for(size_t p=0;p<(size_t)n;){vpu_instruction_t i;size_t u;vpu_status_t s=vpu_decode(b+p,(size_t)n-p,&i,&u);if(s){fprintf(stderr,"decode error at %zu\n",p);free(b);return 1;}printf("%04zu op=%02x dst=R%u src=R%u flags=%u imm=%lld\n",p,i.opcode,i.dst,i.src,i.flags,(long long)i.imm);p+=u;}free(b);return 0;}
