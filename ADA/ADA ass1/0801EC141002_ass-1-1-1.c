#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define randrange(N) rand() / (RAND_MAX/(N) + 1)//If not to use floating point

#define MAX 100000
static int arr[10];
long long int cad[MAX];

int main (void) {
	clock_t begin = clock();
  int i;

  srand(time(NULL));   

  for (i=0; i<MAX; i++)
    cad[i] = i;

  for (i = 0; i < MAX-1; i++) {
    int c = randrange(MAX-i);
    int t = cad[i];
    cad[i] = cad[i+c];
    cad[i+c] = t;
  }

  for (i=0; i<10; i++)
    arr[i] = cad[i] + 1;

  for (i=0; i<10; i++)
    printf("%i\n", arr[i]);
clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("----------------%lf------------------",time_spent);	
  return 0;
}
