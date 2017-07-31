#include<stdio.h>

struct ret{

int elem;
int freq;
};

struct ret majority(int arr[],int low,int high)
{
	struct ret local_result,left,right;
	if(high-low==0)
	{
	   local_result.elem=arr[low];
	   local_result.freq=1;	
	}	
	if(low<high)
	{
	int mid=low+(high-low)/2;
	left=majority(arr,low,mid);			//divide
	right=majority(arr,mid+1,high);		//divide
	int major=mid-low+1;				//condition for half+1
	int count_left=0,count_right=0,x;
	if(right.freq!=0){					
		x=right.elem;
		int i;
		for(i=low;i<=mid;++i){
			if(arr[i]==x)	count_left++;	}
		count_left=count_left+right.freq;
	}
	if(left.freq!=0){
		x=left.elem;
		int i;
		for(i=mid+1;i<=high;++i){
			if(arr[i]==x)	count_right++;	}
		count_right+=left.freq;
	}
	
	if(count_left>major){
				local_result.freq=count_left;
				local_result.elem=right.elem;
			}
	else if(count_right>major){
				local_result.freq=count_right;
				local_result.elem=left.elem;
			}
	else{
				local_result.elem=-1;
				local_result.freq=0;
			}
	}
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
	result=majority(a,0,N-1);
	if(result.freq!=0){
		printf("The Majority element is= %d\twith frquency= %d\n",result.elem,result.freq);
	}
	else{
		printf("No majority element");
	}
}

