import java.util.Scanner;
public class p{
	public static void main(String [] args){
		System.out.println("Enter the size of array");
		Scanner scan=new Scanner(System.in);
		int n=scan.nextInt();
		int arr[]=new int[n];
		System.out.println("Enter elements");
		for(int i=0;i<n;++i){
			arr[i]=scan.nextInt();
		}
System.out.println("Enter no to be searched:");
		int x=scan.nextInt();
int l=0;
int r=n-1;
int index;
index=function(arr,l,r,x);
if(index!=-1)	System.out.println("Element is at index:"+index);
	else		System.out.println("Not Found");

	}

public static int function(int arr[], int l, int r, int x)
{
	
   if (r >= l)
   {
        int mid1 = l + (r - l)/3;
        int mid2 = mid1 + (r - l)/3;
 
        if (arr[mid1] == x)  return mid1;
        if (arr[mid2] == x)  return mid2;
        if (arr[mid1] > x) return function(arr, l, mid1-1, x);
        if (arr[mid2] < x) return function(arr, mid2+1, r, x);
        return function(arr, mid1+1, mid2-1, x);
   }
   return -1;
}

}


	