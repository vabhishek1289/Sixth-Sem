#include<stdio.h>



	
void DIVIDE(long long int ARRAY[],long int low,long int high)
{
	long int p=high+1;
	long int mid;
	if(low < high)
	{	//comp++;
		mid = (low + high) / 2;
		DIVIDE(ARRAY, low, mid);
		DIVIDE(ARRAY, mid + 1, high);
		
		MERGEALGO(ARRAY, low, mid, high, p);
	}
}

void MERGEALGO(long long int ARRAY[],long int low,long int mid,long int high,long int p)
{
	long int i, mi, k, lo, temp[p];
	lo = low;
	i = low;
	mi = mid + 1;
	while ((lo <= mid) && (mi <= high))
	{
		if (ARRAY[lo] <= ARRAY[mi])
		{	//comp++;
			temp[i] = ARRAY[lo];
			lo++;
		}
		else
		{
			temp[i] = ARRAY[mi];
			mi++;
		}
		i++;
	}
	if (lo > mid)
	{	//comp++;
		for (k = mi; k <= high; k++)
		{
			temp[i] = ARRAY[k];
			i++;
			//sp++;
		}
	}
	else
	{
		for (k = lo; k <= mid; k++)
		{
			temp[i] = ARRAY[k];
			i++;
			//sp++;
		}
	}
	for (k = low; k <= high; k++)
	{
		ARRAY[k] = temp[k];
	}
}
	




int main(){
	long int n;
	long long int l,r;
	scanf("%ld",&n);
	scanf("%lld",&l);
	scanf("%lld%",&r);
	if(n>=2 && l<=r && l>=1){
	
	long long int L[n],count=0;
	long long int i,j,k;
	int check=0;
	for(i=0;i<n;i++)		scanf("%lld",&L[i]);
	DIVIDE(L, 0, n - 1);
	for(i=0;i<n;i++)		printf("%lld ",&L[i]);
	//long int a[r-l+1];
	for(j=l;j<=r+1;j++)	{
		
    	for(k=0;k<n-1;k++){
    		   if ((j+L[k]>L[k+1]) && (L[k]>0 && L[k+1]>0 && j>0)){
                count++;
                check=1;
                break;
				}	
    	}
    	
         
	
	}	
//	count=0;
	
	
	
	printf("%lld",count);
	}
	return 0;
}
	
	

