#include<stdio.h>
#include<time.h>

#define MAX 100000
 
 
unsigned int multiply(int x, unsigned int res[], int res_size)
{
    int carry=0,i;
    for (i=0; i<res_size; i++){
        int prod=res[i]*x + carry;
        res[i]=prod % 10;
        carry=prod/10;  
    }
    while (carry){
        res[res_size] = carry%10;
        carry=carry/10;
        res_size++;
    }
    return res_size;
}

void factorial(int n)
{
    unsigned int res[MAX];
    res[0]=1;
    int res_size=1,x,i;
    for (x=2; x<=n; x++)
        res_size = multiply(x, res, res_size);
    printf("Factorial of given number is \n");
    for (i=res_size-1; i>=0; i--)
        printf("%u ",res[i]);
    printf("\n");
}

int main()
{
    int a;
    printf("Enter value\n");
    scanf("%d",&a);
    clock_t begin = clock();
    factorial(a);
    
clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("----------------%lf------------------",time_spent);
    
}
