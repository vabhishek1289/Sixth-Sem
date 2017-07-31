 #include <stdio.h>
#include <time.h>


void MERGEALGO(int [], int, int, int);
void DIVIDE(int [],int, int);
int comp=0,sp=0;
int main()
{
	int ARRAY[1000];
	int i, LENGTH;
	

	printf("Enter total number of elements:");
	scanf("%d", &LENGTH);

	printf("Enter the elements:\n");
	for(i = 0; i < LENGTH; i++)
	{
		scanf("%d", &ARRAY[i]);
	}
     	clock_t begin = clock();

	DIVIDE(ARRAY, 0, LENGTH - 1);

	printf("After merge sort:\n");
	for(i = 0;i < LENGTH; i++)
	{
		printf("%d   ",ARRAY[i]);
	}
    clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("----------------%lf------------------",time_spent);	
	
	printf("Comparision:%d\n",comp);
	printf("Swapping:%d\n",sp);
	return 0;

}

void DIVIDE(int ARRAY[],int low,int high)
{
	int mid;
	if(low < high)
	{	
		mid = (low + high) / 2;
		DIVIDE(ARRAY, low, mid);
		DIVIDE(ARRAY, mid + 1, high);
		MERGEALGO(ARRAY, low, mid, high);
	}
}

void MERGEALGO(int ARRAY[],int low,int mid,int high)
{
	int i, mi, k, lo, temp[1000];
	lo = low;
	i = low;
	mi = mid + 1;
	while ((lo <= mid) && (mi <= high))
	{	comp++;
		if (ARRAY[lo] <= ARRAY[mi])
		{	comp++;
			temp[i] = ARRAY[lo];
			lo++;
		}
		else
		{	comp++;
			temp[i] = ARRAY[mi];
			mi++;
		}
		i++;
	}
	comp++;
	while(lo<=mid){
		comp++;
		temp[i]=ARRAY[lo];
		lo++;
		i++;
	}
	comp++;
	while(mi<= high){
		comp++;
		temp[i]=ARRAY[mi];
		mi++;
		i++;
	}
	comp++;
/*	if (lo > mid)
	{	comp++;
		for (k = mi; k <= high; k++)
		{
			temp[i] = ARRAY[k];
			i++;
			//sp++;
		}
	}
	else
	{	comp++;
		for (k = lo; k <= mid; k++)
		{
			temp[i] = ARRAY[k];
			i++;
			//sp++;
		}
	}*/
	for (k = low; k <= high; k++)
	{	
		ARRAY[k] = temp[k];
		sp++;
	}
}
