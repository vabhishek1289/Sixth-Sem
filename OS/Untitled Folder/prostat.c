#include<stdio.h>
#include<stdlib.h>
#include<sys/sysinfo.h>
int main()
{
	FILE *meminfo=fopen("/proc/statm","r");
	if(meminfo==NULL)
		{
			printf("Cant open the file ");
		}
	char line[10000];
	while(fgets(line,sizeof(line),meminfo))
	{
		printf(line);
	}




}
