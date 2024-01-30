#ifndef LEXER_H
#define LEXER_H
#include "token.h"

typedef struct LEXER_STRUCT{
	char c;
	unsigned int i;
	char* raw_code;	
} lexer_T;

lexer_T* init_lexer(char* raw_code);

void lexer_move(lexer_T* lexer); //next char

void lexer_void(lexer_T* lexer); //skip whitespace

token_T* lexer_new(lexer_T* lexer); //get new token

token_T* lexer_cstr(lexer_T* lexer); //collect string 

token_T* lexer_id(lexer_T* lexer); //collect id 

token_T* lexer_move_token(lexer_T* lexer, token_T* token); //Move lexer with token in stack

char* lexer_convert_char_string(lexer_T* lexer); // get the current char as a string value


#endif
