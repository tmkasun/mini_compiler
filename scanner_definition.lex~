%{
#include "my_headers.h"
%}

%%
:		return COLON;
"db_type"	return TYPE;
"db_name"	return NAME;
"db_collection"	return COLLECTION;
"db_port"	return PORT;
"db_user"	return USER;

[a-zA-Z][_a-zA-Z0-9]	return IDENTIFIER;
[1-9][0-9]*		return INTEGER;
[ \t\n]			;
.			printf("Unexpected character\n");

%%

int yywrap(void){
	return 1;
}
