	int num_lines1 = 0, num_chars1 = 0, digits = 0;
%%
[0-9] ++digits; ++num_chars1;
\n	++num_lines1;	++num_chars1;
.	++num_chars1;
%%

int main(){
	yylex();
	printf("# of lines = %d, # of chars = %d, # of digits %d\n", num_lines1,num_chars1,digits);

}
