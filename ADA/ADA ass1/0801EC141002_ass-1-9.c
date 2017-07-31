#include<stdio.h>
#include<math.h>
#define N 5
#include <time.h>


int determinant(int[N][N],int);
void init(int[N][N],int);

 
int main()
{
 int a[N][N],l,n;
 int result;
 printf("Enter matrix(max 5x5):");
 scanf("%d %d",&l,&n);
 if(l!=n)
  {  printf("l!=n Not square matrix!!\n");
  }
  else{
 init(a,n);
 	clock_t begin = clock();
 result = determinant(a,n);
 printf("\nDeterminant: %d",result);
 clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("----------------%lf------------------",time_spent);	

}
}


void init(int b[N][N],int m)
{
printf("Enter elements:\n");
int i,j;
for(i=0;i<m;i++)
  for(j=0;j<m;j++)
	scanf("%d",&b[i][j]);
	

printf("Matrix is:\n");
//int i,j;
for(i=0;i<m;i++)
 {
  for(j=0;j<m;j++)
	printf("%d ",b[i][j]);
 printf("\n");
 }

}



int determinant(int b[N][N],int m)   
{
 int i,j,result = 0,c[N][N];
 if(m==1)	return b[0][0];
 else if(m==2)
  {                                        
	result = b[0][0]*b[1][1] - b[0][1]*b[1][0];
	return result;
  }
  int p;
 for(p=0;p<m;p++)
 {
  int h = 0,k = 0;
  for(i=1;i<m;i++)
  {
	for( j=0;j<m;j++)
	{
	 if(j==p)
	  continue;
	 c[h][k] = b[i][j];
	 k++;
	 if(k == m-1)
	  {
		 h++;
		 k = 0;
	  }

	}
  }

  result = result + b[0][p]*pow(-1,p)*determinant(c,m-1);
 }
 return result;
}
