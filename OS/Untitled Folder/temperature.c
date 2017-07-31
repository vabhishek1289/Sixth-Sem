 #include<stdio.h>
 #include <string.h>
 #include <stdlib.h>
    
    int main(void)
    {
      
        float temp;
        int i=0;
	FILE *fcritical1,*finput1,*fcritical2,*finput2;
        fcritical1=fopen("/sys/class/hwmon/hwmon1/device/temp1_crit","r");
	finput1=fopen("/sys/class/hwmon/hwmon1/device/temp1_input","r");        
	fcritical2=fopen("/sys/class/hwmon/hwmon1/device/temp2_crit","r");
	finput2=fopen("/sys/class/hwmon/hwmon1/device/temp2_input","r");        
		
	if (fcritical1==NULL){
          printf("file could not be opened");
          exit(1);
        }  
	printf("Core 1:");
        fscanf(fcritical1,"%f",&temp);
	printf("The critical Temperature is %f celcius\n",temp/1000);
	fscanf(finput1,"%f",&temp);
            printf("The  Temperature is %f celcius\n",temp/1000);
	printf("Core 2:");
        fscanf(fcritical2,"%f",&temp);
	printf("The critical Temperature is %f celcius\n",temp/1000);
	fscanf(finput2,"%f",&temp);
            printf("The Temperature is %f celcius\n",temp/1000);
                

        
      
      return 0;
    }
