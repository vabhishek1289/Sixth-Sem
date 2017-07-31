%{
#include<stdio.h>
%}
letter [a-zA-Z_]
digit  [0-9]
%%
{letter}({letter}|{digit})* {printf("%s is a valid variable\n",yytext);}
{digit}({letter}|{digit})* {printf("%s is not a valid variable\n",yytext);}
%%
int main(){
	printf("Enter the variables.Press ^d to exit \n");
	yylex();
	
}