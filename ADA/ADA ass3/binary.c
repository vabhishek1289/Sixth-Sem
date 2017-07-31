#include<stdio.h>

int binary(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid1 = l + (r - l)/2;
 
        if (arr[mid1] == x)  return mid1;
        if (arr[mid1] > x) return binary(arr, l, mid1-1, x);
        return binary(arr, mid1+1, r, x);
   }
   return -1;
}

int iteration(int a[], int n, int x){
int i;
for(i=0;i<n;i++){
		if(a[i]==x)	{
			return i;
		}
	}
	return -1;
}


int main(){
	int n;
	printf("Enter size of array:");
	//int n;
	scanf("%d",&n);
	int a[n];
	printf("Enter Array elements:");
	int i;
	for(i=0;i<n;i++)	scanf("%d",&a[i]);
	printf("Enter no to be searched:");
	int x;
	scanf("%d",&x);
	int l=0;
	int r=n-1;
	int index_iter,index_bin;
	
	
	//search iteration
	index_iter=iteration(a,n,x);
	printf("-----Iteration Method---------");
	if(index_iter!=-1)	printf("\n Index is: %d\n\n",index_iter);	
	else			printf("\n Not Found.\n\n");
	
	
	
	
	//search divide and conquer
	index_bin=binary(a,l,r,x);
	printf("-----Divide & Conquer Method---------");
	if(index_bin!=-1)	printf("\n Index is: %d\n",index_bin);	
	else			printf("\n Not Found.\n");
	
}




