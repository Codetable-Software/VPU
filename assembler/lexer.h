#ifndef VPU_ASM_LEXER_H
#define VPU_ASM_LEXER_H
#include <stddef.h>
typedef enum {TOK_EOF,TOK_IDENT,TOK_NUMBER,TOK_COMMA,TOK_LBRACKET,TOK_RBRACKET,TOK_NEWLINE} asm_token_kind;
typedef struct {asm_token_kind kind; char text[64]; long long number; size_t pos;} asm_token;
typedef struct {const char*src;size_t pos;} asm_lexer;
void asm_lexer_init(asm_lexer*l,const char*s); int asm_lexer_next(asm_lexer*l,asm_token*t);
#endif
