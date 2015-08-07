#include <stdio.h>
#include "my_headers.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

char *names[] = {NULL,"db_type","db_name","db_port"};
int main(void){
	int name_token,value_token;

	name_token = yylex(); // Call the scanner and return the first token
	while(name_token){
		printf("Token %d\n",name_token);
		name_token = yylex(); // Get next token
	}	
	return 0;
}

