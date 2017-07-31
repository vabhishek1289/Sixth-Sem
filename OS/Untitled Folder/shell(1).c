#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h> 
#include<unistd.h>
#include <string.h>
int check_mp(char *ar[]){
int i=0;
while(ar[i]!=NULL){
if(strcmp(ar[i],"&")==0)
return i;
i++;
}
return -1;
}

int check_outredirect(char *tk[]){
int i=0;
while(tk[i]!=NULL){

if(strcmp(tk[i],">")==0)
return i;
i++;
}
return -1;
}

void do_outredirect(char *tk[]){
int i=0;
	for(i=0;i<10;i++){
	if(strcmp(tk[i],">")==0)
	break;

}
char *cmd1=tk[i-1];
char *argv[2];//ls
	argv[0]=tk[i-1];
	argv[1]=NULL;//u
char *fname=tk[i+1];
close(1);//ls
   int fd=open(fname,O_CREAT|O_WRONLY,0777);
   if (fork() == 0) {
           
        execvp(cmd1,argv);
        
    }
    else{
    freopen ("/dev/tty", "a", stdout);
    
    return;
    
    }
    
}


int check_inredirect(char *tk[]){


int i=0;

while(tk[i]!=NULL){

if(strcmp(tk[i],"<")==0)
	return i;
	i++;

}
return -1;
}
	void do_inredirect(char *tk[]){
	int i=0;

	for(i=0;i<10;i++){

	if(strcmp(tk[i],"<")==0)
	break;
}

char *cmd=tk[i-1];
char *argv[2];
argv[0]=tk[i-1];
argv[1]=NULL;
char *fname=tk[i+1];

close(0);

 
    int fd=open(fname,O_RDONLY);
    
    if (fork() == 0) {
           
        execvp(cmd,argv);
        
    }
    else{
    freopen ("/dev/tty", "r", stdin);
    
    return;
    
    }
}

int check_pipe(char *tk[]){
int i=0;

while(tk[i]!=NULL){

	if(strcmp(tk[i],"|")==0)
	return i;
	i++;

}
return -1;

}

void do_pipe(char *tk[]){
int i=0;

for(i=0;i<10;i++){

	if(strcmp(tk[i],"|")==0)
	break;
}

char *cmd1=tk[i-1];
char *argv1[2];
	argv1[0]=tk[i-1];
	argv1[1]=NULL;
	char *cmd2=tk[i+1];

	char *argv2[2];
	argv2[0]=tk[i+1];
	argv2[1]=NULL;
	int p[2];
	    pipe(p);

 		   if (fork() == 0) {
    
 	       close(0);
 	       close(p[0]);
 	       close(p[1]);
 	       dup(p[0]); 
 	       execvp(cmd2,argv2);
        
    } else {
        
        close(1);
        close(p[0]); 
        close(p[1]);
        dup(p[1]); 
        execvp(cmd1,argv1);
        main();
    }
    
}


int main(){
int j, index;

while(1){
char command[100];
 	printf("-->$:");
	gets(command);
	char *token;
	token= strtok(command, " ");
	char *tk[10];
	int i=0;
	while(token!=NULL){
		tk[i]=token;
		token=strtok(NULL, " ");
		i++;
	}
	tk[i]=NULL;

	if(check_outredirect(tk)>0){
		do_outredirect(tk);
		continue;
	}
	else if(check_inredirect(tk)>0)
	{
		do_inredirect(tk);
		continue;
	}
	else if(check_pipe(tk)>0)
	{
	do_pipe(tk);
	continue;
	}
	else
	{
		if(check_mp(tk)>0)
		tk[check_mp(tk)]=NULL;
		j=fork();
	
		if(j==0)
		{
		execvp(tk[0],tk);
		}
		else
		{
		if(!check_mp)
		{
		wait();
		printf("\n");
	}
	}
   }
 }
}
