import java.util.Scanner;
public class MaxMin{

	public static void main(String [] args){
		System.out.println("Enter the size of array");
		Scanner scan=new Scanner(System.in);
		int n=scan.nextInt();
		int arr[]=new int[n];
		System.out.println("Enter elements");
		for(int i=0;i<n;++i){
			arr[i]=scan.nextInt();
		}
		
		int ans[]=findMaxMin(arr,0,arr.length-1);
		System.out.println("Max "+ans[0]+" Min "+ans[1]);
	}
	
	public static int[] findMaxMin(int arr[],int p,int q){
	
		int max,min;
		int []ans=new int[2];
		if(p==q) {
			max=arr[p];
			min=arr[q];
			ans[0]=max;
			ans[1]=min;
			return ans;
		}
		
		else if(p==q-1){
			if(arr[p]>=arr[q]){
				max=arr[p];
			}
			else{
				max=arr[q];
			}
			if(arr[p]<=arr[q]){
				min=arr[p];
			}
			else{
				min=arr[q];
			}
			ans[0]=max;
			ans[1]=min;
			return ans;
		}
		else{
			int mid=((q-p)+1)/2;
			
			//System.out.println("mid is "+mid);
			int []a1=findMaxMin(arr,p,p+mid);
			int a2[]=findMaxMin(arr,p+mid+1,q);
			if(a1[0]>=a2[0]){
				max=a1[0];	
			}
			else{
				max=a2[0];
			}
			if(a1[1]<=a2[1]){
				min=a1[1];
			}
			else{
				min=a2[1];
			}
			ans[0]=max;
			ans[1]=min;
			return ans;
			
		}
		
	}
	
}