#include<stdio.h>
int main(){
	int a[5]={1,1,2,3,4};
	int n=5;
	int N=(n/2)+1;
	int i,j,k=1,flag=0;

	for(i=0;i<N;i++){
		for(j=k;j<n;j++){
			if(a[i]==a[j]){
				printf("%d\t%d",i,j);
				flag=1;
				break;
			}	
		}

		if(flag==1)	break;
		k++;
	}

}
