#include <stdio.h>
#include <math.h>
#include <time.h>

int main()
{
  int n, c, d,swap, sp=0,comp=0,pos;
  printf("Enter Size\n");
  scanf("%d", &n);
  int arr[n];
  printf("Enter elements\n");
 
  for (c = 0; c < n; c++)
    scanf("%d", &arr[c]);
     	clock_t begin = clock();

   int i, key, j;
   for (i = 0; i < n; i++)
   {
   	comp++;
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key)
       {
       	comp++;
       	   sp++;
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
  for (i=0; i < n; i++)
       printf("%d ", arr[i]);
  	printf("Comparision:%d\n",comp);
	printf("Swapping:%d\n",sp);
    clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("----------------%lf------------------",time_spent);	

  return 0;
}

