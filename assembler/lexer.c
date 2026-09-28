#include "lexer.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
void asm_lexer_init(asm_lexer*l,const char*s){l->src=s;l->pos=0;}
int asm_lexer_next(asm_lexer*l,asm_token*t){const char*s=l->src;while(s[l->pos]==' '||s[l->pos]=='\t'||s[l->pos]=='\r')l->pos++;t->pos=l->pos;if(!s[l->pos]){t->kind=TOK_EOF;return 0;}if(s[l->pos]=='\n'){l->pos++;t->kind=TOK_NEWLINE;return 1;}if(s[l->pos]==','){l->pos++;t->kind=TOK_COMMA;return 1;}if(s[l->pos]=='['){l->pos++;t->kind=TOK_LBRACKET;return 1;}if(s[l->pos]==']'){l->pos++;t->kind=TOK_RBRACKET;return 1;}size_t st=l->pos;if(isdigit((unsigned char)s[l->pos])||(s[l->pos]=='-'&&isdigit((unsigned char)s[l->pos+1]))){char*e;long long n=strtoll(s+st,&e,0);l->pos=(size_t)(e-s);t->kind=TOK_NUMBER;t->number=n;return 1;}if(isalpha((unsigned char)s[l->pos])||s[l->pos]=='_'){while(isalnum((unsigned char)s[l->pos])||s[l->pos]=='_')l->pos++;size_t n=l->pos-st;if(n>=sizeof(t->text))n=sizeof(t->text)-1;memcpy(t->text,s+st,n);t->text[n]=0;t->kind=TOK_IDENT;return 1;}l->pos++;return -1;}
