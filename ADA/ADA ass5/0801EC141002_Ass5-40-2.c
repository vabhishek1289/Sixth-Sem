/*
Given time taken by n tasks. Find the minimum time needed to finish the tasks such that 
skipping of tasks is allowed, but can not skip two consecutive tasks.
*/

#include<stdio.h>
 
int min(int a, int b) {
	if(a<b)	return a;
	else	return b;
} 
 
int minTime(int arr[], int n){
    if (n <= 0)        return 0;
    int incl = arr[0];  
    int excl = 0;    
	int i;   
    for (i=1; i<n; i++){
       int incl_new = arr[i] + min(excl, incl);
       int excl_new = incl;
       incl = incl_new;
       excl = excl_new;
    }
    return min(incl, excl);
}
 
int main(){
    //int arr1[] = {10, 5, 2, 7, 10};
    //int n1 = sizeof(arr1)/sizeof(arr1[0]);
    //printf("%d\n",minTime(arr1, n1));
 
    int arr2[] = {10, 5, 7, 10};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("%d\n",minTime(arr2, n2));
 
    //int arr3[] = {10, 5, 2, 4, 8, 6, 7, 10};
    //int n3 = sizeof(arr3)/sizeof(arr3[0]);
    //printf("%d\n",minTime(arr3, n3));
 
    return 0;
}
