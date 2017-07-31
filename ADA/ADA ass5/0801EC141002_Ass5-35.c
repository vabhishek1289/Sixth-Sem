#include <stdio.h>
 
#define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0]))
int i;
void printSubset(int A[], int size){
	int i;
    for(i = 0; i < size; i++)        printf("%d\t", A[i]);
    printf("\n");
}
 
void subset_sum(int s[], int t[], int s_size, int t_size, int sum, int ite, int const target_sum){
    if( target_sum == sum ){
        printSubset(t, t_size);
        subset_sum(s, t, s_size, t_size-1, sum - s[ite], ite + 1, target_sum);
        return;
    }
    else{
    	int i; 
        for( i = ite; i < s_size; i++ ){
            t[t_size] = s[i];
            subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
        }
    }
}
 
 
int main(){
    int array[] = {5, 10, 15};
    int size = ARRAYSIZE(array);
    int tuplet_vector[size];
subset_sum(array, tuplet_vector, size, 0, 0, 0, 15);
    return 0;
}
