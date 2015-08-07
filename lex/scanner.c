
#include <stdio.h>
#include "scanner.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

int main(void) {
   int token;
   int lexeme;
   token = yylex();
   
   while(token){
      printf("token %d\n",token);
      if( yylex() != equal){
         printf("Syntax error in line %d, expected a = but found %s\n", yylineno,yytext);
      }
      lexeme = yylex();
      switch(token){
         case server:
                 if(lexeme != serverIP){ 
                     printf("Syntax error in line %d, expected an server ip but found %s\n", yylineno,yytext);
                 }
                 break;
         case port:
                 if(lexeme != portno){ 
                     printf("Syntax error in line %d, expected a port number but found %s\n", yylineno,yytext);
                 }
                 break;
	    case database:
                 if(lexeme != identifier){ 
                     printf("Syntax error in line %d, expected a database name but found %s\n", yylineno,yytext);
                 }
                 break;
	    case userid:
                 if(lexeme != useridText){ 
                     printf("Syntax error in line %d, expected a userid but found %s\n", yylineno,yytext);
                 }
                 break;
         case password:
                 if(lexeme != passwordText){ 
                     printf("Syntax error in line %d, expected a password but found %s\n", yylineno,yytext);
                 }

                 break;
         default : printf("Syntax error at line %d\n", yylineno);
                   break;
      }
   token = yylex();
   }
   return 0;
}