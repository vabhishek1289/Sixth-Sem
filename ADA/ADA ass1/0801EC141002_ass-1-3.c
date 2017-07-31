#include<stdio.h>
#include<time.h>
int indx[];
void check(int a[],int arr[],int n){
	int temp[n];
	int i,j,k=0;
    for(i=0;i<n;i++){
    	temp[i]=arr[indx[i]];
    }
    for(i=k,j=i+1;i<n-1 && j<n;i++,j++){
    	//if(a[i]!=a[j])
    	//	break;
    	if(a[i]==a[j]){
    		k=k+2;
			if(temp[i]>temp[j]){
				int t=temp[i];
				temp[i]=temp[j];
				temp[j]=t;
				//break;
			}
    	}
    	}
    /*
	for(i=k;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i]==a[j]){
				k=k+2;
				if(temp[i]>temp[j]){
					int t=temp[i];
					temp[i]=temp[j];
					temp[j]=t;
					break;
				}
			}	
		}
	}*/
	printf("Sorted array: \n");
    for(i=0;i<n;i++){
    	printf("%d ",temp[i]);
    }
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high,int index[])
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
            swap(&index[i],&index[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    swap(&index[i + 1], &index[high]);
    return (i + 1);
}
 
void custom(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high,indx);
        custom(arr, low, pi - 1);
        custom(arr, pi + 1, high);
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
    int weight[n];
    printf("Enter weights of elements of Original array\n");
    for(i=0;i<n;i++){
    	scanf("%d",&weight[i]);
    }
    clock_t begin = clock();
    indx[n];
    for(i=0;i<n;i++){
    	indx[i]=i;
    }
    custom(weight, 0, n-1);
    check(weight,arr,n);
    clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("----------------%lf------------------",time_spent);
    return 0;
}

