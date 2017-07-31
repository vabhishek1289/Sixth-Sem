 #include <stdio.h>
 
int main()
{
  int array[100], n, c, d,swap, sp=0,comp=0,pos;
  printf("Enter Size\n");
  scanf("%d", &n);
 
  printf("Enter elements\n");
 
  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);
 
  for (c=0;c<(n-1);c++)
  {
    for (d=0;d<n-c-1;d++)
    {
	comp++;
      if (array[d] > array[d+1])
      {
        swap = array[d];
        array[d] = array[d+1];
        array[d+1]= swap;
		sp++;
      }
		
    }
  }
 
  printf("Bubble Sort:\n");
 
  for (c=0;c<n;c++){
     printf("%d\n", array[c]);
  }
	printf("Comparision:%d\n",comp);
	printf("Swapping:%d\n",sp);
 
}
