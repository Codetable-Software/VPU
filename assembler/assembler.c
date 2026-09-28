#include "encoder.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char**argv){if(argc!=3){fprintf(stderr,"usage: vpu-as input.asm output.vpu\n");return 2;}FILE*f=fopen(argv[1],"rb");if(!f)return 1;fseek(f,0,SEEK_END);long n=ftell(f);fseek(f,0,SEEK_SET);char*s=malloc((size_t)n+1);if(!s){fclose(f);return 1;}fread(s,1,(size_t)n,f);fclose(f);s[n]=0;unsigned char*out;size_t len;char err[128]={0};int rc=asm_assemble(s,&out,&len,err,sizeof(err));free(s);if(rc){fprintf(stderr,"assembly error: %s\n",err);return 1;}f=fopen(argv[2],"wb");if(!f){free(out);return 1;}fwrite(out,1,len,f);fclose(f);free(out);return 0;}
