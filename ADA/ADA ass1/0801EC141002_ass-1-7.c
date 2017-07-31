#include<stdio.h>
#include <time.h>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
 	int j;
    for (j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
int main()
{
	printf("Enter size of array\t");
	int n,i,j;
	scanf("%d",&n);
	int arr[n]; 
	printf("Enter Original array\n");
    for(i=0;i<n;i++){
    	scanf("%d",&arr[i]);
    }
	clock_t begin = clock();    	
    quickSort(arr, 0, n-1);
    int counter[n];
    for(i=0;i<n;i++){
    	counter[i]=0;
    }
    int count=1;
    for(i=0;i<n;i++){
    	
    	if(arr[i]+1==arr[i+1]){
    		count++;
    	}
    	else{
    		counter[i]=count;
    		count=1;
    	}
    }
    int max=0;
    for(i=0;i<n;i++){
    	if(counter[i]>max)	max=counter[i];
    }
    printf("%d",max);
clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("----------------%lf------------------",time_spent);	



    
    return 0;
}
