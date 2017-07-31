#include<stdio.h>
#include<math.h>


int multiply(int a[],int b[],int low1,int high1,int low2,int high2){
	if(low1<=high1 && low2<=high2){
	if((high1-low1==0)||(high2-low2==0)||(high1-low1==1)||(high2-low2==1)){
		int a1[2];
		int a2[2];
		
		a1[0]=a[low1];
		a1[1]=a[high1];
		
		a2[0]=b[low2];
		a2[1]=b[high2];
		
		int p=0,q=0,j,i;
		p=a1[0]*10 + a1[1]*1;
		q=a2[0]*10 + a2[1]*1;
		//printf("p=:%d\nq=:%d",p,q);
		return p*q;
	}
		int n=high1-low1+1;
		int mid1=low1+(high1-low1)/2;
		int mid2=low2+(high2-low2)/2;
		
		int arr1[mid1-low1+1];
		int arr2[high1-mid1];
		int arr3[mid2-low2+1];
		int arr4[high2-mid2];
		int i;
		for(i=0;i<mid1-low1+1;++i)			arr1[i]=a[low1+i];
			
		for(i=0;i<high1-mid1;++i)				arr2[i]=a[mid1+1+i];
			
		for(i=0;i<mid2-low2+1;++i)			arr3[i]=b[low2+i];
		
		for(i=0;i<high2-mid2;++i)				arr4[i]=b[mid2+i+1];

		int x1=multiply(arr1,arr3,0,(mid1-low1),0,(mid2-low2));
		int x3=multiply(arr2,arr4,0,high1-mid1-1,0,high2-mid2-1);
		
		
		int al=0,ar=0,bl=0,br=0,j;
	
		for(i=0,j=(mid1-low1+1);i<mid1-low1+1 && j>=0; i++,j--)    	al=al+pow(10,j)*arr1[i];
	
		for(i=0,j=(high1-mid1);i<high1-mid1 && j>=0; i++,j--)    	ar=ar+pow(10,j)*arr2[i];
		
		for(i=0,j=(mid2-low2+1);i<mid2-low2+1 && j>=0; i++,j--)    	bl=bl+pow(10,j)*arr3[i];
		
		for(i=0,j=(high2-mid2);i<high2-mid2 && j>=0; i++,j--)    	br=br+pow(10,j)*arr4[i];
		
		int t1=(al+ar);
		int t2=(bl+br);
		
		int tt1=t1, tt2=t2, len_t1=0, len_t2=0;
		while(tt1 != 0)
    	{
                tt1 /= 10;
        	++len_t1;
    	}
    	while(tt2 != 0)
    	{
                tt2 /= 10;
        	++len_t2;
    	}
    	
    	int n1[len_t1];
		int n2[len_t2];
	    for(i=0;i<len_t1;i++){
	    	int temp;
	    	temp=t1%10;
	    	n1[i]=temp;
	    	t1=t1/10;
	    }
	    for(i=0;i<len_t2;i++){
	    	int temp;
	    	temp=t2%10;
	    	n2[i]=temp;
	    	t2=t2/10;
	    }
	    		
		int x2=multiply(n1,n2,0,len_t1-1,0,len_t2-1);
		printf("X1=%d X2-X1-X3=%d X3=%d",x1,x2,x3);
		return x1*pow(100,(n/2))   +    (x2-x1-x3)*pow(10,(n/2)+1)    +    x3;		
	}
	else	return 0;
}




int main(){
	int len_x,len_y;
	scanf("%d%d",&len_x,&len_y);
	int x[len_x],y[len_y],i;
    for(i=0;i<len_x;i++){
    	scanf("%d",&x[i]);
    }
    for(i=0;i<len_y;i++){
    	scanf("%d",&y[i]);
	}
	
	int a=0,b=0,j;
	
	for(i=0,j=(len_x-1);i<len_x && j>=0; i++,j--)    	a=a+pow(10,j)*x[i];
	for(i=0,j=(len_y-1);i<len_y && j>=0; i++,j--)    	b=b+pow(10,j)*y[i];
	printf("%d %d",a,b);
	
	
	int res=multiply(x,y,0,len_x-1,0,len_y-1);
	printf("res is:%d",res);




	
}
