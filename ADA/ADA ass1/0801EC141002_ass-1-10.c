#include <stdio.h>
#include <stdlib.h>
#include<time.h>
void spiralscan(int a[][100],int n,int c,int count)
{
    int i,j;
    
    if(count>=n*n)		return;
        for(j=c;j<n-c;j++)
        {printf("%d ",a[c][j]);
        count++;
        }
		for(i=c+1;i<n-c;i++)
        {printf("%d ",a[i][n-c-1]);
        count++;
        }
		for(j=n-2-c;j>=c;j--)
        {printf("%d ",a[n-1-c][j]);
        count++;
        }
		for(i=n-2-c;i>c;i--)
        {printf("%d ",a[i][c]);
         count++;
        }

    spiralscan(a,n,c+1,count);
}
int main()
{
	
    int n,m,i,j,a[100][100];
    printf("Enter rows and columns: ");
    scanf("%d%d",&n,&m);
    if(n!=m){
    	printf("Not a NxN matrix!\n");
    }
    else{
    printf("\nEnter matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
             scanf("%d",&a[i][j]);
    }
    printf("\nSpiral Order:\n");
    clock_t begin = clock();
    spiralscan(a,n,0,0);
    clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("----------------%lf------------------",time_spent);	

	}    
    return 0;
}
