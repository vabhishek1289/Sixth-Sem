#include<stdio.h>

struct ret{

int min;
int max;
};

struct ret MaxMin(int arr[],int low,int high)
{
	struct ret local_result,left,right;
	if(high-low==0)
	{
	   local_result.min=arr[low];
	   local_result.max=arr[high];	
	   return local_result;
	}	
	if(high-low==1)
	{
		if(arr[low]<arr[high])
		{
			local_result.min=arr[low];
			local_result.max=arr[high];
		}
		else{
			local_result.min=arr[high];
			local_result.max=arr[low];			
		}
		return local_result;
	}
	int mid;
	mid=(low+high)/2;
	left=MaxMin(arr,low,mid);
	right=MaxMin(arr,mid+1,high);
	if(left.min<right.min)		local_result.min=left.min;
	else						local_result.min=right.min;
	if(left.max>right.max)		local_result.max=left.max;
	else						local_result.max=right.max;
	return local_result;
}

int main()
{
	int N;
	printf("Enter size of array\n");
	scanf("%d",&N);
	printf("Enter array:");
	int i,a[N];
	for(i=0;i<N;i++){
		scanf("%d",&a[i]);
	}
	struct ret result;
	result=MaxMin(a,0,N-1);
	printf("\nMax is: %d\n",result.min);
	printf("\nMin is: %d\n",result.max);
}

