#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

pid_t  pid;
int status;
char str[20], str_std[20], *token[20];
int i,j=0,k=0;
char pip[]="|",or[]=">";

void op_redirect()
{
	
		

}


void main()
{
	system("clear");
	while(1)
	{
		printf("$$");
		gets(str);
		strcpy(str_std,str);
		if(strstr(str_std, pip)!=NULL)
		{  //PIPED HERE
			pid=fork();
			//wait(&status);
			if (pid == 0) 
			{	
				memset(token, 0, sizeof(token[0]) * 10 * 20);
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
				//printf("%d\n",k);
				for(j=0;j<k;j++)
				{
					strcpy(str,cmd[j]);
					strcpy(str_std,str);
					if(strstr(str_std, or)!=NULL)
					{
						// OUTPUT REDIRECTION						
								pid=fork();
								wait(&status);
								if (pid == 0) 
								{	
									memset(token, 0, sizeof(token[0]) * 10 * 20);
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
									fd= open(filename,O_WRONLY|O_TRUNC);
									dup2(fd, 1);
									execvp(token[0],token);
								}
						// END	
	
					}
					else
					{
		
						memset(token, 0, sizeof(token[0][0]) * 10 * 20);
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
				p = strtok (str, " >");
				while (p != NULL)
				{
				  	token[i]=p;
				 	i++;
					p = strtok (NULL, " >");
				}
				token[i]=NULL;
		
			}
			// END	
		
	
	
	}}

}
