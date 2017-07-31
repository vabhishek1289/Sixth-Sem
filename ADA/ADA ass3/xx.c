#include<stdio.h>
#include<math.h>

int func(int x,int y)	{
		int x1=x,  y1=y;
		int size_x=0, size_y=0;
		while(x1 != 0)
    	{
                x1 /= 10;
        	++size_x;
    	}
    	while(y1 != 0)
    	{
                y1 /= 10;
        	++size_y;
    	}
    	
		if(size_x==1 || size_y==1)	return (x*y);
		
		
			int max;
			if(size_x>size_y)	max=size_x;
			else				max=size_y;
			
			int mid=max/2;
			int a,b,c,d,ac,bd,ad_plus_bc,res;
			int deg=pow(10,mid);
				a = x / deg;
                b = x % deg;
                c = y / deg;
                d = y % deg;
                ac = func(a,c);
                bd = func(b,d);
                ad_plus_bc = func(a+b,c+d) - ac - bd;
                int prod = ac * pow(10,(2*mid)) + (ad_plus_bc * pow(10,mid)) + bd;
                return prod;	
		
}



int main(){
	int len_x,len_y;
	scanf("%d%d",&len_x,&len_y);
	int x[len_x],y[len_y],i,j;
    for(i=0;i<len_x;i++){
    	scanf("%d",&x[i]);
    }
    for(i=0;i<len_y;i++){
    	scanf("%d",&y[i]);
	}
	
	int a=0,b=0;
	
	for(i=0,j=(len_x-1);i<len_x && j>=0; i++,j--)    	a=a+pow(10,j)*x[i];
	for(i=0,j=(len_y-1);i<len_y && j>=0; i++,j--)    	b=b+pow(10,j)*y[i];
	printf("%d %d",a,b);
	
	
	
	int res=func(a,b);
	printf("res is:%d",res);




	
}
