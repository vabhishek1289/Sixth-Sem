%{
	
	#include <stdio.h>
	void yyerror(char *s);
	
%}

%token A
%token B
%%
expr : S'\n' {printf("Valid string\n");exit(0);}
S : A S B
	|
	;
%%
main(){
	printf("Enter the string\n");
	yyparse();
	
	
}
void yyerror(char *s){
	printf("Invalid string!!\n");
	exit(1);
}
