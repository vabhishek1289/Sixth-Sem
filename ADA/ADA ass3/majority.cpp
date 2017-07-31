#include<stdio.h>
#define N 10
 
int majority(int arr[],int i,int j);
int checkCount(int arr[],int i,int j,int major);
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int n;
    int major=0;	
	int m=majority(a,0,N-1);
	printf("%d",m);
	
}
int majority(int arr[],int i,int j)
{
	int major;
	int first=0;
	int second=0;
	if(j-i==0)     	return	arr[j];
	if(j-i==1){
		first=checkCount(arr,i,j,arr[i]);
		second=checkCount(arr,i,j,arr[j]);
		if(first==1)			return arr[i];
		else if(second==1)		return arr[j];
	}
	int mid;
	mid=(i+j)/2;
    majority(arr,i,mid);
    majority(arr,mid+1,j);
}
int checkCount(int arr[],int i,int j,int major)
{
	if(j-i==1)		return 1;
	int k;
	int count=0;
	for(k=0;k<N;++k)
	{
		if(arr[k]==major)			count++;
	}
	int size=((i+j)+1)/2;
	if(count>size)					return 1;
	else							return 0;
	
}
