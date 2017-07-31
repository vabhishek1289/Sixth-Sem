#include<stdio.h>
#include <time.h>

int main(){
	clock_t begin = clock();

  srand(time(NULL));   


int vektor[10];    
int random;
int uniqueflag;
int i, j;

for(i = 0; i < 10; i++) {
     do {
        /* Assume things are unique... we'll reset this flag if not. */
        uniqueflag = 1;
        random = rand() % 100+ 1;
        /* This loop checks for uniqueness */
        for (j = 0; j < i && uniqueflag == 1; j++) {
           if (vektor[j] == random) {
              uniqueflag = 0;
           }
        }
     } while (uniqueflag != 1);
     vektor[i] = random;
}

for(i=0;i<10;i++){
	printf("%d\n",vektor[i]);
}
clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("----------------%lf------------------",time_spent);	

}
