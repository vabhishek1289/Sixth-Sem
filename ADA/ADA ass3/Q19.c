#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct ret{
    int min;
    int max;
};


struct ret minmax(int p[],int lo,int hi){
    int mid,leftdiff,rightdiff,crossdiff;
    struct ret left,right,cross,local_result;

    if(lo == hi){
        local_result.min = p[lo];
        local_result.max = p[hi];
        return local_result;
    }

    mid = (lo+hi)/2;
    left = minmax(p,lo,mid);
    right = minmax(p,mid+1,hi);

    int i,local_min,local_max;
    
    local_min = p[mid];
    for(i=mid;i>=lo;i--){
        if(p[i] < local_min){
            local_min = p[i];
        }
    }

    local_max = p[mid+1];
    for(i=mid+1;i<=hi;i++){
        if(p[i] > local_max){
            local_max = p[i];
        }
    }
    cross.min = local_min;
    cross.max = local_max;

    leftdiff = left.max - left.min;
    rightdiff = right.max - right.min;
    crossdiff = cross.max - cross.min;

    if(leftdiff > rightdiff && leftdiff > crossdiff){
        return left;
    }else if(rightdiff > crossdiff){
        return right;
    }else{
        return cross;
    }
}

int main(void){
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;
    double interval;

	int n,i;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array:\n");
    for(i=0;i<n;i++)	scanf("%d",&arr[i]);
	struct ret result;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);
	
    result = minmax(arr,0,n-1);
    int temp=result.max - result.min;
    QueryPerformanceCounter(&end);
    interval = ((double) (end.QuadPart - start.QuadPart) / frequency.QuadPart)*1000;

    printf("%f\n", interval);

    printf("Max difference = %d\n",temp);
    //printf("Max difference = %d, Max Element=%d, Min Element = %d  \n",result.max - result.min,result.max,result.min);
    return 0;
}

