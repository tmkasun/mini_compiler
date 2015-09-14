%{
#include <math.h>
#include <unistd.h>
%}
DIGIT	[0-9]
ID	[a-z][a-z0-9]*

%%
{DIGIT}+	{
			printf("An integer: %s (%d)\n", yytext, atoi( yytext ));
		}
{DIGIT}+"."{DIGIT}*	{
				printf("A float : %s (%g)\n", yytext, atof( yytext ));
			}
if|then|begin|BEGIN|end|END|procedure|function	{
						printf("A keyword : %s \n", yytext );
					}
{ID}			printf("An identifiert : %s \n", yytext);
"*"|"-"|"+"|"/"		printf("An operator : %s \n", yytext);
"{"[\^{}}\n]*"}"	;/*Eat up one-line comments*/
[ \t\n]			;/*Eat up whitespaces*/
.			printf("Unrecognized charactor: %s\n",yytext);
%%
int main(int argc, char **argv){
	++argv, --argc; /* skip over program name */
	if (argc > 0){
		yyin = fopen(argv[0], "r");
	}
	else
		yyin = stdin;
	yylex();
	}
