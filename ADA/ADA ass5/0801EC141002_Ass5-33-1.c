
#include<stdio.h>
#include<limits.h>

int Matrix(int [], int); 
 
int main()
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Least  operations are: %d ", Matrix(arr, size));
}


int Matrix(int p[], int n)
{
    int arr[n][n];
    int i, j, k, L, q;
    for (i=1; i<n; i++)
        arr[i][i] = 0;
    for (L=2; L<n; L++){
        for (i=1; i<n-L+1; i++){
            j = i+L-1;
            arr[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++){
                q = arr[i][k] + arr[k+1][j] + p[i-1]*p[k]*p[j];
                    arr[i][j] = q;
            }
        }
    }
    return arr[1][n-1];
}

