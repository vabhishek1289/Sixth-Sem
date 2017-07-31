#include <stdio.h>

void print_time (long time){
const long minute = 60;
const long hour = minute * 60;
const long day = hour * 24;
printf ("%ld days, %ld:%02ld:%02ld\n", time / day,
(time % day) / hour, (time % hour) / minute, time % minute);
}


int main (){
FILE* fp;
double uptime, idle_time;
fp = fopen ("/proc/uptime", "r");
fscanf (fp, "%lf %lf\n", &uptime, &idle_time);
fclose (fp);

printf("Uptime is:");print_time ((long) uptime);
printf("Idle time is:");print_time ((long) idle_time);
return 0;
}
