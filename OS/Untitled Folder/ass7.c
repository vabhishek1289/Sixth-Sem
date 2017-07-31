#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>


int printPath(char *pid) {
    char cmd[256]="sudo realpath /proc/";
    char path[256];
    FILE *fp;   
    strcat(cmd,pid);
    strcat(cmd,"/exe");
    fp=popen(cmd,"r"); 
    fscanf(fp,"%s",path);   
    printf("PATH(%s):: %s\n",pid,path);    
}

int contextSwitches(char *pid) {
    char cmd[256]="grep ctxt /proc/";
    char path[256];
    int out;
    FILE *fp;   
    strcat(cmd,pid);
    strcat(cmd,"/status");
    fp=popen(cmd,"r"); 
    fscanf(fp,"%s %d\n",path,&out);
    printf("%s %d\n",path,out);
    fscanf(fp,"%s %d\n",path,&out);    
    printf("%s %d\n",path,out);    
}


int printProcessDetails(const char *p) {    
    char Mpath[256];
    strcpy(Mpath,"/proc/");    
    strcat(Mpath,p);    
    strcat(Mpath,"/statm");    
    FILE *prinfo = fopen(Mpath, "r");    
    if(prinfo == NULL)
        printf("ERROR\n");

    char line[256];
    int ram, residentRam,temp,dirty,shared;
    fscanf(prinfo, "%d %d %d %d %d %d %d",&ram,&residentRam,&shared,&temp,&temp,&temp,&dirty)  ;  
    printf("RAM Size:: %d\n",ram);
    printf("Resident in RAM:: %d\n",residentRam);
    printf("Shared Pages:: %d\n",shared);
    printf("Dirty Page:: %d\n",dirty);
    fclose(prinfo);
    return -1;
}

int cpuInfo() {
    FILE *cpuinfo = fopen("/proc/cpuinfo", "r");
    if(cpuinfo == NULL)
        printf("ERROR\n");

    char line[256];
    int i=0;
    while(fgets(line, sizeof(line), cpuinfo))
    {        
        float ram;
        if(sscanf(line, "cpu MHz : %f kB", &ram) == 1) {            
            printf("CPU Clock Freq Core(%d):: %f\n",++i,ram);            
        }              
    }

    fclose(cpuinfo);
    return -1;
}

int main() {  
    char pid[20];  
            puts("Enter PID");
            scanf("%s",pid);     
            printProcessDetails(pid);
printf("\n");
            cpuInfo();
printf("\n");
            puts("Enter PID");
            scanf("%s",pid);     
            printPath(pid);
printf("\n");
             puts("Enter PID");
             scanf("%s",pid);     
             contextSwitches(pid);
printf("\n");
    return 0;
}
