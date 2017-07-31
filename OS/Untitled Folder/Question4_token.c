#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

void get_keywords(char string[]);
void get_operators(char string[]);

int main() {  
    printf("Enter the line of code:");
    char string[100];
    scanf("%[^\n]s", string);
    printf("%s\n", string);
    printf("Operartors: \n") ;
    get_operators(string);
    printf("Keywords: \n") ;
    get_keywords(string);
}

void get_keywords(char string[]){
    int c=10;
    char keyword[15][20]={"int","long","main","scanf","printf","char","short","string","do","while","for","float","double","break","continue"};
    char *identifier[100];
    int i=0,j=0;
    int i_count=0;
    for(i=0;i<c;i++) {
        int count=0,flag;
        char *str = strdup(string);
        char *token;
        while ((token = strsep(&str, " ,:=;.*/+-()")))  {
            if(strcmp(keyword[i],token)==0)
                count++;
            else if(strcmp("",token)!=0)  {
                flag=0;
                for(j=0;j<c;j++) {                    
                    if(strcmp(keyword[j],token)==0) {
                        flag=1;
                        break;
                    }
                }
                for(j=0;j<i_count;j++) {
                    if(strcmp(identifier[j],token)==0) {
                        flag=1;
                        break;
                    }
                }
                if(flag==0) {
                    if((int)token[0]<48||(int)token[0]>57){
                        identifier[i_count] = &token[0];                    
                        i_count++;
                    }                    
                }
            }            
        }
        if(count!=0)
            printf("%s\t:\t%d \n",keyword[i],count);
    }

    printf("Identifier: \n") ;
    for(i=0;i<i_count;i++) {
        int count=0,flag;
        char *str = strdup(string);
        char *token;
        while ((token = strsep(&str, " ,=:;.*/+-()")))  {
            if(strcmp(identifier[i],token)==0)
                count++;                       
        }
        if(count!=0)
            printf("%s\t:\t%d \n",identifier[i],count);
    }
}

void get_operators(char string[]) {
    char *str = strdup(string);  
    char operators[]=",:;=.*/+-()#";    
    int i=0;    
    for(i=0;i<strlen(operators);i++) {                 
        char *token;
        str = strdup(string);
        char a[2]= "\0";
        a[0] = operators[i];
        int count=0;
        while ((token = strsep(&str, a)))  {
            count++;
        }
        if(count-1!=0)
            printf("%s\t:\t%d \n",a,count-1);
    }    
    free(str);
}



