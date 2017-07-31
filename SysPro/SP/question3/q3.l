%{
int commentcount=0;
extern char* yytext;
%}
%s COMMENT
%%
"/*" {BEGIN COMMENT;}
<COMMENT>"*/" {BEGIN 0;commentcount++;}
<COMMENT>\n	{commentcount++;}
<COMMENT>. {;}
\/\/.*	    {commentcount++;}
.|\n	{ fprintf(yyout,"%s",yytext);}
%%
int main(void){
	FILE *fp1,*fp2;
	char file1[10],file2[10];
	printf("Enter the input file:\n");
	scanf("%s",file1);
	printf("Enter the name for output file:\n");
	scanf("%s",file2);
	
	fp1=fopen(file1,"r");
	fp2=fopen(file2,"w");
	yyin=fp1;
	yyout=fp2;
	yylex();
	printf("Comments count %d\nConversion complete\n",commentcount);
}