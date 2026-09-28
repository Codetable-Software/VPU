#include "encoder.h"
#include <stdlib.h>
#include <string.h>
static const size_t SZ=12;
size_t asm_encode(const asm_statement*s,unsigned char*out,size_t cap){if(!s||!out||cap<SZ)return 0;out[0]=s->ins.opcode;out[1]=s->ins.dst;out[2]=s->ins.src;out[3]=s->ins.flags;memcpy(out+4,&s->ins.imm,8);return SZ;}
int asm_assemble(const char*text,unsigned char**out,size_t*len,char*err,size_t cap){if(!text||!out||!len)return -1;size_t lines=1;for(const char*p=text;*p;p++)if(*p=='\n')lines++;unsigned char*buf=malloc(lines*SZ);if(!buf)return -2;size_t used=0;const char*start=text;for(const char*p=text;;p++){if(*p=='\n'||!*p){size_t n=(size_t)(p-start);char*line=malloc(n+1);if(!line){free(buf);return -2;}memcpy(line,start,n);line[n]=0;asm_statement st;int rc=asm_parse_line(line,&st,err,cap);free(line);if(rc<0){free(buf);return -3;}if(rc==0){size_t w=asm_encode(&st,buf+used,lines*SZ-used);if(!w){free(buf);return -4;}used+=w;}if(!*p)break;start=p+1;}}*out=buf;*len=used;return 0;}
