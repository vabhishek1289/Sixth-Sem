#include <stdio.h>

struct ret{
    int min;
    int max;
};

struct ret crossminmax(int p[],int lo,int mid,int hi){
    int i,local_min,local_max;
    struct ret local_result;

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
    local_result.min = local_min;
    local_result.max = local_max;
    return local_result;
}

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

    cross = crossminmax(p,lo,mid,hi);
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

int main(){
	int n,i;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array:\n");
    for(i=0;i<n;i++)	scanf("%d",&arr[i]);
	struct ret result;
    result = minmax(arr,0,n-1);
    int temp=result.max - result.min;
    printf("Max difference = %d\n",temp);
    //printf("Max difference = %d, Max Element=%d, Min Element = %d  \n",result.max - result.min,result.max,result.min);
    return 0;
}

