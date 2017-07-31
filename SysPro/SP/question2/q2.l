%{
int nchar=0,nword=0,nline=0,nspace=0;
%}
%%
[\n] {nline++;nword++;}
[\t] {nspace++;nword++;}
[" "] {nspace++;nword++;}
[^\n\t] {nchar++;}
%%
int main(){

	FILE *fp;
	char file[10];
	printf("Enter the filename");
	scanf("%s",file);
	fp=fopen(file,"r");
	yyin=fp;
	yylex();
	
	printf("Characters: %d\nWords: %d\nLines: %d\nSpaces: %d\n",nchar,nword,nline,nspace);
return 0;
}
