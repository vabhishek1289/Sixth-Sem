%{
#include<stdio.h>
#include<string.h>

int optrc=0,oprdc=0;
int l=0,j=0,top=-1,valid=1;
char opnd[10][10],oprt[10][10],a[100];
%}

%%
"(" {a[top++]='(';}
"{" {a[top++]='{';}
"[" {a[top++]='[';}

")" { if(a[top]!='(') {valid=0;return;}
		else top--;
	}
"}" { if(a[top]!='}' ){valid=0;return;}
		else top--;
	}
"]" { if(a[top]!=']' ){valid=0;return;}
		else top--;
	}

"+"|"-"|"*"|"/" {optrc++; strcpy(oprt[l++],yytext);}
[0-9]+|[a-zA-Z][a-zA-Z0-9_]* {oprdc++;strcpy(opnd[j++],yytext);}

%%
main(){
	int k;
	printf("Enter the arithmetic exprssion\n");
	yylex();
	if(valid==1 && top==-1 && (oprdc-optrc)==1){
		printf("The operators are\n");
		for(k=0;k<l;++k)
			printf("%s\n",oprt[k]);
		
		printf("The operands are\n");
		for(k=0;k<j;++k)
			printf("%s \n",opnd[k]);
		
	}
	else
		printf("The expression is invalid\n");
}
int yywrap(){
	return 1;
}