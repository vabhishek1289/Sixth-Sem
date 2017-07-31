#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


pid_t  pid;
int status;
char str[20], string[20], *token[20];
int i,j=0,k=0;
char pipe_symbol[]="|",output_symbol[]=">",input_symbol[]="<";


void OR_function(){

		pid=fork();
		wait(&status);
		if (pid == 0) 
		{	
			memset(token, 0, sizeof(token[0]) * 30 * 30);
			char * p,*filename;
			int i=0,j,fd;
			p = strtok (str," >");
			while (p != NULL)
			{
			  	token[i]=p;
			 	i++;
				p = strtok (NULL, " >");
			}
			token[i]=NULL;
			
			filename=token[1];
			token[1]=NULL;
			fd= open(filename,O_WRONLY);
			dup2(fd, 1);
			execvp(token[0],token);
		}	
	

}

void IR_function()
{
	pid=fork();
	wait(&status);
	if (pid == 0) 
	{	
		memset(token, 0, sizeof(token[0]) * 30 * 30);
		char * p,*filename;
		int i=0,j,fd;
		p = strtok (str," <");
		while (p != NULL)
		{
		  	token[i]=p;
		 	i++;
			p = strtok (NULL, " <");
		}
		token[i]=NULL;
		
		filename=token[1];
		token[1]=NULL;
		fd= open(filename,O_RDONLY);
		dup2(fd, 0);
		execvp(token[0],token);
	}	
}

void PIPE_function()
{
	pid=fork();
	wait(&status);
	if (pid == 0) 
	{	
		memset(token, 0, sizeof(token[0]) * 30 * 30);
		char * p,*filename,*q,*cmd[5];
		int i=0,j,fd,k=0;
		memset(cmd, 0, sizeof(cmd[0]) * 5);
		q = strtok (str, "|");
		while (q != NULL)
		{
		  	cmd[k]=q;
		 	k++;
			q = strtok (NULL, "|");
		}
		cmd[k]=NULL;
		
		for(j=0;j<k;j++)
		{
			strcpy(str,cmd[j]);
			strcpy(string,str);
			
					memset(token, 0, sizeof(token[0][0]) * 30 * 30);
					char *p;
					int i=0,j;
					for (p = strtok(str," "); p != NULL; p = strtok(NULL, " "))
					{
					  token[i]=p;
					  i++;
					}
					token[i]=NULL;
		
				if(strcmp(token[0],"exit") == 0)
				{
					system("clear");
					exit(0);
				}
		
				pid=fork();
				wait(&status);
				if (pid == 0) 
				{          
			       	execvp(token[0], token);
				}
						
			
		
		}
		p = strtok (str, " >");
		while (p != NULL)
		{
		  	token[i]=p;
		 	i++;
			p = strtok (NULL, " >");
		}
		token[i]=NULL;
		
	}	
}


void main()
{
	system("banner ---Shell---");
	while(1)
	{
	printf("-->$:");
	gets(str);
	strcpy(string,str);
		if(strstr(string, pipe_symbol)!=NULL)
		{
			PIPE_function();
		}
		else if(strstr(string, output_symbol)!=NULL)
		{
			OR_function();
		}
		else if(strstr(string, input_symbol)!=NULL)
		{
			IR_function();
		}
		else
		{
		
			memset(token, 0, sizeof(token[0][0]) * 30 * 30);
			char *p;
			int i=0,j;
			for (p = strtok(str," "); p != NULL; p = strtok(NULL, " "))
			{
			  token[i]=p;
			  i++;
			}
			token[i]=NULL;
		
			if(strcmp(token[0],"exit") == 0)
			{
				system("clear");
				exit(0);
			}
		
			pid=fork();
			wait(&status);
			if (pid == 0) 
			{          
		       	execvp(token[0], token);
			}
		
		}
	}

}
