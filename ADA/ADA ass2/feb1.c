    #include<stdio.h>
     
    int main(){
    	int x,T;
    	scanf("%d",&T);
    	for(x=0;x<T;x++){
    		long int n,count=0,flag=0;
    		scanf("%ld",&n);
    		long int i,a,m=0;
    		int fine=100,zeroflag=0;
    	for(i=1;i<=n;i++){
    		
			scanf("%ld",&a);
			if(a==0){
				//flag++;
				//if(flag==1){
				m=m+1000+fine;
				//}
				//else{
				//	if(i==n)	m=m+1000+100;
				//	else		m=m+1000;
				//}
				
				
			}
			else{
				flag=0;
				//m=m+100;
				if(m==0)	m=m+0;
				else		m=m+100;	
			}
		}
		printf("%ld\n",m);
    	
    	
    	
    	
    }
    }
     


