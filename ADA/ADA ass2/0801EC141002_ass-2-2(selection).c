#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main()
{
    int i,n,s,temp,swap=0,comp=0;
    scanf("%d",&n);
    int A[n];
    for(i=0;i<n;++i)
      {
       //A[i]=rand()%100+1;
       scanf("%d",&A[i]);
    }
    	clock_t begin = clock();

    for(s=0;s<n;++s)
    for(i=s+1;i<n;++i)
     {	comp++;
         if(A[s]>A[i])  
          {
             temp=A[s];
             A[s]=A[i]; 
             A[i]=temp;
             swap++;
         }
    }
    for(i=0;i<n;++i)
        printf("%d  ",A[i]);
        
    printf("Total Swapping: %d\nTotal Comparison: %d\n",swap,comp);
    clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("----------------%lf------------------",time_spent);	

    return 0;
}
