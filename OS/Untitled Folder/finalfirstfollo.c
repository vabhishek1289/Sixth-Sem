#include<stdio.h>
#include<ctype.h>
#include<string.h>
void FIRST(char[],char );
void addToResultSet(char[],char);
int size,m=0;
char a[10][10],followResult[10];
void follow(char c);
void temp(char c);
void addToResultFollow(char);

void main(){
    int i;
    char c;
    char result[20];
    printf("How many number of productions ? :");
    scanf(" %d",&size);
    printf("Epsilon==>@\n");
    for(i=0;i<size;i++){
        printf("Enter productions Number %d : ",i+1);
        scanf(" %s",a[i]);
    }
    int flag=0;
    for(i=0;i<size;i++){
    	if( islower(a[i][0]))	flag=1;	
		if(a[i][0]==a[i][3])	flag=2;
		if(flag==1 || flag==2)	break;
	}
	
	if(flag==0){
	
    int b[size],cx=0,cnt=0;
    for(i=0;i<size;i++)	b[i]='\0';			//initialize array b[] by NULL
    for(i=0; i<size; i++){					//stores LHS values in b[] array 
	cx=0;
	int j;
    for(j=0;j<i+1;j++){									//check duplicates
        if(a[i][0] == b[j]){
            cx=1;    
            break;
        	}    
        }
    if(cx !=1){											//store unique values in b[]
      b[cnt] = a[i][0];
      cnt++;
    }               
    }
    
    //for(i=0;i<cnt;i++)		printf("%c ",b[i]);
    
    int ii=0;
    while(ii!=cnt){
    	c=b[ii];
        FIRST(result,c); 								//Compute FIRST();
        printf("\n FIRST(%c)= { ",c);
        for(i=0;result[i]!='\0';i++)
        printf(" %c ",result[i]);       				//Display result	
        printf("}\n");
        ii++;
    }
    printf("\n");
    printf("\n");
    
    
    int ij=0;
    while(ij!=cnt){
    	c=b[ij];	//printf("%c ",b[ij]);
        m=0;
        follow(c);										//Compute FOLLOW();
  		printf("\n FOLLOW(%c) = { ",c);
  		for(i=0;i<m;i++)
   			printf(" %c ",followResult[i]);				//Display result
  		printf(" }\n");
        ij++;
    }
	}
	else if(flag==1){
		printf("\nNot a valid grammar.....\n");
	}
	else if(flag==2){
		printf("\nGrammar has left recursion....\n");
	}
}


void follow(char c){
	int j,i;
    if(a[0][0]==c)						addToResultFollow('$');
 for(i=0;i<size;i++){
  for(j=3;j<strlen(a[i]);j++){
   if(a[i][j]==c){
    if(a[i][j+1]!='\0')					temp(a[i][j+1]);
    if(a[i][j+1]=='\0'&&c!=a[i][0])     follow(a[i][0]);
   }
  }
 }
}

void temp(char c){
      int k;
      if(!(isupper(c)))                 addToResultFollow(c);
      for(k=0;k<size;k++){
      	if(a[k][0]==c){
      		if(a[k][3]=='@') 			follow(a[k][0]);
            else if(islower(a[k][3]))   addToResultFollow(a[k][3]);
            else 						temp(a[k][3]);
          }
      }
}

void addToResultFollow(char c){
    int i;
    for( i=0;i<=m;i++){
    	if(followResult[i]==c)          return;
	}
    followResult[m++]=c;
}

void FIRST(char* Result,char c){
    int i,j,k;
    char subResult[20];
    int epsilon;
    subResult[0]='\0';
    Result[0]='\0';
    if(!(isupper(c))){
        addToResultSet(Result,c);
        return ;
    }
    for(i=0;i<size;i++){
        if(a[i][0]==c){
 			if(a[i][3]=='@') 							addToResultSet(Result,'@');
      		else{
                j=3;
                while(a[i][j]!='\0'){
                epsilon=0;
                FIRST(subResult,a[i][j]);
                for(k=0;subResult[k]!='\0';k++)         addToResultSet(Result,subResult[k]);
                 for(k=0;subResult[k]!='\0';k++){			//{}
                     if(subResult[k]=='@'){
                         epsilon=1;
                         break;
                     }
                 }    
                 if(!epsilon)		                     break;
                 j++;
                }
            }
    }
}
return;
}

void addToResultSet(char Result[],char val){
    int k;
    for(k=0 ;Result[k]!='\0';k++){			//{}
        if(Result[k]==val)						           return;
        }    
    Result[k]=val;
    Result[k+1]='\0';
}
