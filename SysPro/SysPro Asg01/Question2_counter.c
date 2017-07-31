#include <stdio.h>
#include <string.h>
int main()
{
	printf("Enter Choice:\n");
	printf("1. Input from File\n2. Input from Command Line ('$' to stop).\n3. Exit\n");
	int choice;
	scanf("%d",&choice);
	FILE *f;
 	char filename[100];
 	char ch;
	int no_line=0, no_word=0, no_character=0;
	char para[1000];
	//int *ptr=para;
	int size,i;

switch(choice){
	case 1:printf("Enter filename:");
		  scanf("%s", filename);
		  f = fopen(filename,"r");
		  if(f){
		     while((ch=getc(f))!=EOF){
			 	if (ch!=' ' && ch!='\n') ++no_character;
				if(ch==' ' || ch=='\n') ++no_word;
				if (ch=='\n') ++no_line;
			   	}
			   if(no_character>0){
				++no_line;
				++no_word;
			   }
		    }
		   else{
		         printf("Unable to open file\n");
			break;
		       }
		
		    printf("Lines : %d \nWords : %d \nCharacters : %d \n", no_line-1,no_word-1,no_character);
		    fclose(f);
			break;
	case 2:		printf("Enter paragraph:\n");
				scanf("%[^\$]",para);
				//printf("%u\n",(sizeof((para)) / sizeof((para)[0])));
    			//printf("%s",para);
    			//printf("%u\n", sizeof(ptr));
				size=strlen(para)-1;
				for(i=0;i<size;i++){
					if (para[i]!=' ' && para[i]!='\n') ++no_character;
					if(para[i]==' ' || para[i]=='\n') ++no_word;
					if (para[i]=='\n') ++no_line;
				}
				if(no_character>0){
				++no_line;
				++no_word;
			   	}
				printf("Lines : %d \nWords : %d \nCharacters : %d \n", no_line-1,no_word-1,no_character+1);
				break;
				
	
	
	
	
	
	case 3:		break;
	default:	printf("Wrong Choice!\n");
				break;
}	

 
  
return(0);
}
