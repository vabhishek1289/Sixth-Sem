#include<stdio.h>
#include<math.h>
double Method3(double,int,int);
double power(double,int);
int main()
{
	double ans,x,n;
	int p,q;
	
	printf("Enter x ");
	scanf("%lf",&x);
	printf("Enter n as p/q ");
	scanf("%d",&p);
	scanf("%d",&q);
	n=p*1.0/q;
	
	
	printf("\n Method 2:\n");
	ans=Method3(x,p,q);
	printf("%lf^%lf=%lf",x,n,ans);
}

double Method3(double x,int p,int q)
{
	double ans1,ans2,c;
	int a,b;
	c=power(x,p);
	ans2=10;
	do
	{
		ans1=ans2;
		ans2=ans1-((power(ans1,q)-c)/(q*power(ans1,q-1)));
		a=ans1;
		b=ans2;
		
	}while(a!=b);
	
return ans2;	
}
double power(double x,int n)
{
	int i;
	double ans=1.00;
	for(i=0;i<n;i++)
	{
		ans=ans*x;
	}
	return ans;
}
