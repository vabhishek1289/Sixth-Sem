#include <sys/sysinfo.h>
#include<stdio.h>
#include<string.h>
#include <unistd.h>

       int chdir(const char *path);
       int fchdir(int fd);


#define MAXLEN 100000
int main(){


printf("\n\n\n\n");

chdir("../../../proc");
//system("cd proc");
system("cat meminfo > /home/abhishek/Desktop/a.txt");
chdir("../home/abhishek/Desktop");
static const char filename[] = "a.txt";
   FILE *file = fopen ( filename, "r" );
   if ( file != NULL )
   {
	int line_count = 0;
      char line [ 128 ]; 
      while (line_count == 7 ) 
      {
	line_count ++;
         fputs ( line, stdout ); /* write the line */
      }
      fclose ( file );
   }
   else
   {
      perror ( filename ); /* why didn't the file open? */
   }
   return 0;


}


