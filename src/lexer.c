#include "include/lexer.h"


lexer_T init_lexer(char* raw_code){
    lexer_T lexer = calloc(1, sizeof(struct LEXER_STRUCT));
    lexer->raw_code = raw_code;
    lexer->i=0;
    lexer->c = raw_code[lexer->i];

    return lexer;
}

void lexer_move(lexer_T* lexer){
    if(lexer->c != '\0' && lexer->i < strlen(lexer->raw_code)){
        
    }
} //next char

void lexer_void(lexer_T* lexer){
    //skip whitespace
}
token_T* lexer_new(lexer_T* lexer){
    //get new token
}
token_T* lexer_cstr(lexer_T* lexer){

} //collect string 

char* lexer_convert_char_string(lexer_T* lexer){

} // get the current char as a string value