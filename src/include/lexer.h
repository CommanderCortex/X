#ifndef LEXER_H
#define LEXER_H
#include "token.h"

typedef struct LEXER_STRUCT{
	char c;
	unsigned int i;
	char* raw_code;	
} lexer_T;

lexer_T init_lexer(char* raw_code);

void lexer_move(lexer_T* lexer); //next char

void lexer_void(lexer_T* lexer); //skip whitespace

token_T* lexer_new(lexer_T* lexer); //get new token

token_T* lexer_cstr(lexer_T* lexer); //collect string 

char* lexer_convert_char_string(lexer_T* lexer); // get the current char as a string value


#endif
