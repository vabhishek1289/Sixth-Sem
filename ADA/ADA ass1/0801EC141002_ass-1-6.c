#include <stdio.h>
#include<time.h>
int fibo_rec(int num) {
	if(num<=1) {
		return 1;
	} else {
	return fibo_rec(num-1) + fibo_rec(num-2);
	}	
}

int fibo_it(int num) {
	int i,result=1,prev=0,t=0;
	if(num==0 || num==1)	return 1;
	else{
	for(i=2;i<=num;i++) {
		
			t=prev;	
			prev = result;		
			result=t+result;					
				
	}
	return result;
	}	
	
}

int main() {
	printf("Enter number\n");
	int num;
	scanf("%d",&num);
	int result=0;
	printf("Enter choice:\n1. Iteration\n2. Recursion\n");
	int ch;
	scanf("%d",&ch);
	if(ch==1){
	clock_t begin = clock();
	result = fibo_it(num);
	printf("%d\n",result);
	clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("----------------%lf------------------",time_spent);
    
	}
	if(ch==2){
	clock_t begin1 = clock();
	result = fibo_rec(num-1);
	printf("%d\n",result);
	clock_t end1 = clock();
double time_spent1 = (double)(end1 - begin1) / CLOCKS_PER_SEC;
printf("----------------%lf------------------",time_spent1);
    
	}
	
}

