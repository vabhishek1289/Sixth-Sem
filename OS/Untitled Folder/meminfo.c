#include<stdio.h>
#include<stdlib.h>
#include<sys/sysinfo.h>
int main()
{
	FILE *meminfo=fopen("/proc/self/status","r");
	if(meminfo==NULL)
		{
			printf("Cant open the file ");
		}
	char line[256];
	while(fgets(line,sizeof(line),meminfo))
	{
		printf(line);
	}
}
