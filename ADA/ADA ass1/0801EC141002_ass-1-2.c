#include<stdio.h>
int arr[5]={1,6,2,6,6};

int pair_check(int i,int j){
		return arr[i]<arr[j];
	}
int main(){
	
	int n=5;
	//int N=(n/2)+1;
	int i,j,check=0,flag=0;

	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if((pair_check(i,j) || pair_check(j,i))==0){
				printf("%d\t%d",i,j);
				flag=1;
				break;
			}	
		}
		if(flag==1)	break;
//		k++;
	}

}
