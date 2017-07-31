#include<stdio.h>
#include<time.h>

int main()
{

int n,i,j,c=0,num,k;
int flag; 
int arr[100];

	for(i=0;i<100;i++)	
		arr[i]=0;
printf("Enter array size:\n");
scanf("%d",&n);
n*=2;
printf("Enter Elements:\n");
for(i=0;i<n;i+=2)
{
    flag=0;
    scanf("%d",&num);
    
    for(j=0;j<=i;j+=2)
    {
        if(arr[j]==num)
        {
            arr[j+1]++;
            flag=1;
        }       
    }
    if(flag==0)
    {
        c++;
        arr[c*2-2]=num;
        arr[c*2-1]++;
    }
}
	clock_t begin = clock();
/*
printf("\nUnique numbes are:");
for(i=0;i<c*2;i+2)
    printf("%d ",arr[i]);
*/    
int stack[200];

	for(i=0;i<200;i++)	
		stack[i]=0;
		
int top=-1;
/*for(j=c*2-1;j>0;j-=2){
	stack[++top]=arr[j];
}
*/
for(k=1;k<n/2;k++)   
{
    for(j=c*2-1;j>0;j-=2)
    {
        if(arr[j]==k)
            stack[++top]=j;
    }
}
int x;
printf("\nSorted array is:\n");
for(x=top;x>-1;x--)
{       
    for(j=arr[stack[x]];j>0;j--)
        printf("%d ",arr[stack[x]-1]);
}
clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("----------------%lf------------------",time_spent);	

}
