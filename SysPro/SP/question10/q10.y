%{
#include<stdio.h>
#include<stdlib.h>
%}
%token A
%token B NL
%%
stmt: A A A A A A A A A A S B NL {printf("valid string\n"); exit(0);}
;
S: S A
|
;
%%

%%
int main(){
	printf("Enter the string\n");
	yyparse();
}
int yyerror(char *s){
	printf("Invalid string\n");
	exit(0);
}