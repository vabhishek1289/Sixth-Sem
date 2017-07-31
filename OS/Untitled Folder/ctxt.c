#include<stdio.h>
#include<string.h>






int main()

{

char a[100],pid[30],z[100];
char c[]="/proc/";
char b[]="/status";
printf("enter pid");
scanf("%s",pid);
strcat(c,pid);
strcat(c,b);

FILE *fp=fopen(c,"r");
printf("%s",c);

while(!feof(fp))
{
fscanf(fp,"%s \t %s\n",a,z);
if(strstr(a,"ctxt")!=NULL)
printf("%s : %s\n",a,z);


}

fclose(fp);

}
