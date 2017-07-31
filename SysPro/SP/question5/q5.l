%{
int simple=1;
%}
%%
[ \t\n]+[aA][nN][dD][ \t\n]+ {simple=0;}
[ \t\n]+[oO][rR][ \t\n]+ {simple=0;}
[ \t\n]+[bB][uU][tT][ \t\n]+ {simple=0;}
. 		{;}
%%
main(){
	printf("enter a sentence and press ctrl-D to check:\n");
	yylex();
	if(simple)
		printf("Sentence is simple\n");
	else
		printf("Sentence is compound\n");
		
}