#include<stdio.h>
#include<limits.h>

int function(int a[], int n){
    int max = INT_MIN, last = 0 ,i,start=0,end=0;
    for (i = 0; i < n; i++){
        last=last+a[i];
        if (max<last)       {max = last;
        						end=i;}
        if (last<0)         {last = 0;
        						start=i+1;			
    }
}
    for(i=start;i<=end;i++)
    printf("%d ",a[i]);
    return max;

}

int main(){
    int a[] = {5, 15, -30, 10, -5, 40, 10};
    int n = sizeof(a)/sizeof(a[0]);
    int res = function(a, n);
    printf("Maximum sum is %d", res);
    return 0;
}
