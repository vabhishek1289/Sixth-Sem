import java.util.Scanner;
public class MajorityElement{
	public static void main(String [] args){
		System.out.println("Enter the size of array");
		Scanner scan=new Scanner(System.in);
		int n=scan.nextInt();
		int arr[]=new int[n];
		System.out.println("Enter elements");
		for(int i=0;i<n;++i){
			arr[i]=scan.nextInt();
		}
		
		int ans[]=findMajority(arr,0,arr.length-1);
		if(ans[1]!=0)
			System.out.println("Element:"+ans[0]+" Frequency:"+ans[1]);
		else 
			System.out.println("No majority element found");
	}
	
	public static int[] findMajority(int arr[],int start,int end){
			int ans[]=new int[2];
		if(start==end){
			ans[0]=arr[start];
			ans[1]=1;
		}
		if(start<end){
			int mid=start+(end-start)/2;
			int left[]=findMajority(arr,start,mid);
			int right[]=findMajority(arr,mid+1,end);
			int half=mid-start+1;
			int countl=0,countr=0,elem;
			if(right[1]!=0){
			elem=right[0];
			for(int i=start;i<=mid;++i){
					if(arr[i]==elem)
						countl++;}
			countl+=right[1];
			}
			if(left[1]!=0){
			elem=left[0];
			for(int i=mid+1;i<=end;++i){
					if(arr[i]==elem)
						countr++;}
			countr+=left[1];
			}
			
			if(countl>half){
				ans[0]=right[0];
				ans[1]=countl;
			}
			else if(countr>half){
				ans[0]=left[0];
				ans[1]=countr;
			}
			else{
				ans[0]=-1;
				ans[1]=0;
			}
			
		}
		return ans;
	}
	
}