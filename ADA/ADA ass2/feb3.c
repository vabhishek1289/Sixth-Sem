#include<stdio.h>
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	
	int j,i,a[n];
	
	for(i=0;i<n;i++)	scanf("%d",&a[i]);

	for(j=0;j<m;j++){
		
		int l,r,k;					//l=1 r=5 k=3 2 5
		scanf("%d%d%d",&l,&r,&k);
	
		int floor_min,floor_max;
		floor_min=(r-l+1)/2;
		floor_max=r-l+1;
		int res=-1,print_count=1;
		if(k>floor_min && k<=floor_max && (l>=1 && r>=l && n>=r)){
			int diff=floor_max-floor_min;
			int k,p,flag=0;
			
			for(k=floor_max;k>floor_min;k--){
				int count=0;
				for(i=0;i<n-1;i++){
						if(a[i]==a[i+1]) count++;
						else count=1;
						if(count==k){
							res=a[i];
							printf("%d\n",res);
							count=1; 
							print_count++;
							flag=1;
							 break;
							}
						else	res=print_count;
				}
			}
			if(res==0)	printf("-1\n");	
		}
		else	printf("-1\n");
		
	}
}
