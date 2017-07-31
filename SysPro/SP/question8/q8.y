%{
	#include<stdio.h>
	
%}

%token NUM
%left '+' '-'
%left '*' '/'
%left '(' ')'

%%

expr : e{
		printf("result:%d\n",$$);
		return 0;
		}
e:	e'+'e {$$=$1+$3;}
	|e '-' e {$$=$1-$3;}
	|e '*' e {$$=$1*$3;}
	|e '/' e {$$=$1/$3;}
	|'(' e ')' {$$=$2;}
	|NUM {$$=$1;}
	;
%%

main(){
	printf("enter the arithmetic expression:\n");
	yyparse();
	printf("Valid expression\n");
	}

yyerror(){
	printf("\n invalid expression\n");
	exit(0);
}
	