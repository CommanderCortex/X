#include "include/lexer.h"
#include "stdlib.h"
#include "string.h"


lexer_T* init_lexer(char* raw_code){
    lexer_T* lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->raw_code = raw_code;
    lexer->i=0;
    lexer->c = raw_code[lexer->i];

    return lexer;
}

void lexer_move(lexer_T* lexer){
    if(lexer->c != '\0' && lexer->i < strlen(lexer->raw_code)){
        lexer->i += 1;
        lexer->c =lexer->raw_code[lexer->i];
    }
} //next char

void lexer_void(lexer_T* lexer){
    //skip whitespace
    while (lexer-> c == ' ' || lexer->c == 10){
        lexer_move(lexer);
    }
}

token_T* lexer_new(lexer_T* lexer){
    //get new token
    while (lexer->c != '\0' && lexer->i < strlen(lexer->raw_code)){
        if (lexer-> c == ' ' || lexer->c == 10){
            lexer_void(lexer);

            if(lexer->c == '"'){
                return lexer_cstr(lexer);
            }

            switch (lexer->c){
                case '=': return lexer_move_token(lexer, init_token(TOKEN_EQ, lexer_convert_char_string(lexer))); break;
                case ';': return lexer_move_token(lexer, init_token(TOKEN_EQ, lexer_convert_char_string(lexer))); break;
                case '(': return lexer_move_token(lexer, init_token(TOKEN_EQ, lexer_convert_char_string(lexer))); break;
                case ')': return lexer_move_token(lexer, init_token(TOKEN_EQ, lexer_convert_char_string(lexer))); break;
            }
        }
    }
}

token_T* lexer_cstr(lexer_T* lexer){
    lexer_move(lexer);

    char* value = calloc(1, sizeof(char));
    value[0] = '\0';

    while (lexer->c != '"'){
        char* s = lexer_convert_char_string(lexer);
        value = realloc(value, strlen(value) + strlen((s) +1 )* sizeof(char));
        strcat(value, s);
    }

    lexer_move(lexer);

    return init_token(TOKEN_STR, value);

} //collect string 

token_T* lexer_move_token(lexer_T* lexer, token_T* token){
    lexer_move(lexer);
    return token;
}

char* lexer_convert_char_string(lexer_T* lexer){
    char* str = calloc(2, sizeof(char));
    str[0] = lexer->c;
    str[1] = '\0';

    return str;
} // get the current char as a string value
