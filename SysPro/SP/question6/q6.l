%{
#include <stdio.h>
int count =0;
%}
letter [a-zA-Z_]
digit [0-9]
id {letter}+|{letter}{digit}+
notid ({digit}|{letter})+
%%
(("int")|("float")|("char")|("case")|("default")|("if")|("for")|("printf")|("scanf")) {printf("%s is a keyword\n", yytext);}
{id} {printf("%s is an identifier \n",yytext);count++;}
{notid} {printf("%s is not an identifier\n",yytext);}
. {;}
%%
int main(){
	FILE *fp;
	char file[10];
	printf("Enter the name of the file \n");
	scanf("%s",file);
	fp=fopen(file,"r");
	yyin=fp;
	yylex();
	printf("Total identifiers are : %d\n",count);
	return 0;
}

