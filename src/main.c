#include "include/lexer.h"
#include <stdio.h>


int main(int argc, char* argv[]){	
	printf("start\n");

	lexer_T* lexer = init_lexer(
		"var name = \"Chris\";\n"
		"print(name);\n"
	);

	token_T* token = (void*)0;

	while ((token = lexer_new(lexer)) != (void*)0){
		printf("TOKEN(%d, %s)\n", token->type, token->value);
	}
	
	return 0;
}
