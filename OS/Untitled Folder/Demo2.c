#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
char *token,*tokens[10];
char *outputfile = NULL, *inputfile = NULL;
			
			
void inputfunction(int i){
				int fin = open(inputfile, O_RDWR|O_CREAT|O_APPEND, 0777);
				if(-1 == fin) { perror("opening File error"); return 255; }				
				
				int file = dup(fileno(stdin));
				if (-1 == dup2(fin, fileno(stdin))) { perror("cannot redirect stdin"); return 255; }				

				int id = fork();   
				if(id==0) {	   			   		
						tokens[i]=NULL;	   		
						execvp(tokens[0],tokens);
				} else {
						wait();
				}	

				fflush(stdout); 
				close(fin);				
				dup2(file, fileno(stdin));				
				close(file);
				return;
}


void outputfunction(int i){
				int fout = open(outputfile, O_RDWR|O_CREAT|O_APPEND, 0777);
				if (-1 == fout) { perror("opening File error"); return 255; }				

				int file = dup(fileno(stdout));				

				if (-1 == dup2(fout, fileno(stdout))) { perror("cannot redirect stdout"); return 255; }				

				int id = fork();   
				if(id==0) {	   			   		
						tokens[i]=NULL;	   		
						execvp(tokens[0],tokens);
				} else {
						wait();
				}	

				fflush(stdout); close(fout);				
				dup2(file, fileno(stdout));				
				close(file);	
				return;			
}


int main() {
	while(1) {
			char str[10] = "";
			printf("$$:");
			gets(str);
			const char s[2] = " ";
			int i=0;
			token = strtok(str, s);
			int char_output = 0;
			int char_input = 0;
			int fd;

			while( token != NULL ) 
			{				
				if(char_output == 1 ) {
					outputfile = token;
					char_output = 0;
				}
				else if(char_input == 1 ) {
					inputfile = token;
					char_input = 0;
				}

 				
				else if(strcmp(token,"<") == 0) {
					char_input = 1;
				}
				else if(strcmp(token,">") == 0) {
					char_output = 1;
				}

 
				else {
					tokens[i++] = token;
				}
				token = strtok(NULL, s);      
			}   	   			

			if(inputfile != NULL) {
				inputfunction(i);
			}


			if(outputfile != NULL) {
				outputfunction(i);
			}

			


			int id = fork();   
			if(id==0) {	   			   		
					tokens[i]=NULL;	   		
					execvp(tokens[0],tokens);
			} else {
					wait();
			}
			if(strcmp(str,"exit") == 0)	break;

								
	}
}

