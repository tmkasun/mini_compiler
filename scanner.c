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
		//printf("Token: %d\nString: %s\n",name_token,yytext);
		if(yylex() != COLON){
			printf("Syntax error in line: %d, Expected a ':' but found %s\n",yylineno,yytext);
			return 1;
		}
		value_token = yylex();
		switch (name_token){
			
			case TYPE:

			case NAME:

			case COLLECTION:
				if (value_token != IDENTIFIER){
				
					printf("Value error for collection name, You have given %s\n",yytext);
					return 0;
				}
				printf("TOKEN is set to %s\n",yytext);
				break;
			default:
				printf("syntax error at line number %d\n",yylineno);
				break;	
		}
			
		name_token = yylex(); // Get next token
	}	
	return 0;
}

