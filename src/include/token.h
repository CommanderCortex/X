#ifndef TOKEN_H
#define TOKEN_H
typedef struct TOKEN_STRUCT{
	enum{
		TOKEN_ID,
		TOKEN_EQ,
		TOKEN_STR,
		TOKEN_SEMI,
		TOKEN_LP,
		TOKEN_RP
	} type;

	char* value;
} token_T;

token_T* init_token(int type, char* value);
#endif
