import java.util.Scanner;
import java.util.Arrays;
public class Multiplication{
	
	public static void main(String [] args){
		Scanner scan=new Scanner(System.in);
		System.out.println("Number1 :size m digits.Number 2 : size n digits.Enter m and n");
		int m=scan.nextInt();
		int n=scan.nextInt();
		char num1[]=new char[m];
		char num2[]=new char[n];
		int ans=0;
		int i;
		System.out.println("Enter 1st number digits");
		for(i=0;i<m;++i)
			num1[i]=scan.next().charAt(0);
		System.out.println("Enter 2nd number digits");
		for(i=0;i<n;++i)
			num2[i]=scan.next().charAt(0);
			
		if(num1.length!=num2.length){
				int size1=num1.length;
				int size2=num2.length;
				int len=(size1>size2)?size1:size2;
				String a1=new String(num1);
				String a2=new String(num2);
				if(size1<size2){
						for(i=0;i<size2-size1;++i)
							a1="0"+a1;
				}
				else {
						for( i=0;i<size1-size2;++i)
							a2="0"+a2;
				
				}
				char newa[]=a1.toCharArray();
				char newb[]=a2.toCharArray();
				ans=multiply(newa,newb,0,newa.length-1,0,newb.length-1);
		}
		else 
			ans=multiply(num1,num2,0,m-1,0,n-1);
		System.out.println("Result: "+ans);
		
	}
	public static int multiply(char a[],char b[],int s1,int e1,int s2,int e2){
	
	if(s1<=e1 && s2<=e2){
		//System.out.printf("s1: %d e1 %d s2 %d e2 %d\n",s1,e1,s2,e2);
		
		if((e1-s1)==0|| (e2-s2)==0||(e1-s1)==1 || (e2-s2)==1){
			char a1[]=new char[e1-s1+1];
			char a2[]=new char[e2-s2+1];
			
		
		
			for(int i=0;i<a1.length;++i)
				a1[i]=a[s1+i];
			for(int i=0;i<a2.length;++i)
				a2[i]=b[s1+i];
			//System.out.println("Numbers received are "+new String(a1)+" and "+new String(a2));
			int p=Integer.parseInt(new String(a1));
			int q=Integer.parseInt(new String(a2));
			//System.out.println("Returning "+p*q);
			return p*q;
		}
		
		int n=a.length;
		int mid1=s1+(e1-s1)/2;
		int mid2=s2+(e2-s2)/2;
		char arr1[]=new char[mid1-s1+1];
		char arr2[]=new char [e1-mid1];
		char arr3[]=new char[mid2-s2+1];
		char arr4[]=new char[e2-mid2];
		for(int i=0;i<arr1.length;++i)
			arr1[i]=a[s1+i];
		for(int i=0;i<arr2.length;++i)
			arr2[i]=a[mid1+1+i];
		for(int i=0;i<arr3.length;++i)
			arr3[i]=b[s2+i];
		for(int i=0;i<arr4.length;++i)
			arr4[i]=b[mid2+i+1];
		int x1=multiply(arr1,arr3,0,arr1.length-1,0,arr3.length-1);
		int x3=multiply(arr2,arr4,0,arr2.length-1,0,arr4.length-1);
		int al=Integer.parseInt(new String(arr1));
		int ar=Integer.parseInt(new String(arr2));
		int bl=Integer.parseInt(new String(arr3));
		int br=Integer.parseInt(new String(arr4));
		int t1=(al+ar);
		int t2=(bl+br);
		char n1[]=numberToArray(t1);
		char n2[]=numberToArray(t2);
		int x2=multiply(n1,n2,0,n1.length-1,0,n2.length-1);
		return x1*(int)Math.pow(100,Math.floor(n/2))+(x2-x1-x3)*(int)Math.pow(10,Math.ceil(n/2))+x3;
	}	
		return 0;
	}
	public static char [] numberToArray(int x){
		String temp = Integer.toString(x);
		char[] digitarr = new char[temp.length()];
		for (int i = 0; i < temp.length(); i++)
		{
			digitarr[i] = temp.charAt(i);
		}
		return digitarr;
	}

}