#include<stdio.h>
#include <time.h>
#include <time.h>

int comp=0,sp=0;
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
        {	comp++;
            i++;
            swap(&arr[i], &arr[j]);
            //sp++;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    sp++;
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {	//comp++;
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main(){
int n,i,j;
	scanf("%d",&n);
	int arr[n]; 
	printf("Enter Original array\n");
    for(i=0;i<n;i++){
    	scanf("%d",&arr[i]);
    }
     	clock_t begin = clock();

    quickSort(arr, 0, n-1);
    for(i=0;i<n;i++){
    	printf("%d ",arr[i]);
    }
	//printf("Comparision:%d\n",comp);
	printf("Swapping:%d\n",sp);
    clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("----------------%lf------------------",time_spent);	

}

