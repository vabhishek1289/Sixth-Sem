#include<stdio.h>
int *findMaxMin(int arr[],int p,int q){
	
		int max,min;
		int ans[2];
		if(p==q) {
			max=arr[p];
			min=arr[q];
			ans[0]=max;
			ans[1]=min;
			return ans;
		}
		
		else if(p==q-1){
			max=(arr[p]>=arr[q])?arr[p]:arr[q];
			min=(arr[p]<=arr[q])?arr[p]:arr[q];
			ans[0]=max;
			ans[1]=min;
			return ans;
		}
		else{
			int mid=((q-p)+1)/2;
			
			int* a1=findMaxMin(arr,p,p+mid);
			int* a2=findMaxMin(arr,p+mid+1,q);
			max=(*a1>=*(a2+1))?*a1:*(a2+1);
			max=(*a1<=*(a2+1))?*a1:*(a2+1);
			//min=(a1[1]<=a2[1])?a1[1]:a2[1];
			ans[0]=max;
			ans[1]=min;
			return ans;
			
		}
		
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
	int* ans=findMaxMin(a,0,n-1);
	printf(" Max: %d\n  Min: %d\n ",*ans,*(ans+1));
}




