import java.util.Scanner;
class Point{
	int x;
	int y;
	private static boolean compareX(Point p,Point q){
		
		return p.x<=q.x;
	}
	private static boolean compareY(Point p,Point q){
		return p.y<=q.y;
	}
	public static void sortByX(Point []arr){
		MergeSort(arr,0,arr.length-1,1);
	}
	public static void sortByY(Point []arr){
		MergeSort(arr,0,arr.length-1,2);
	}
	public  static void copyPoint(Point src,Point dest){
		dest.x=src.x;
		dest.y=src.y;
		}
	private static void MergeSort(Point[] arr,int start,int end,int coord){
		if(start<end){
			int mid=start+(end-start)/2;
			MergeSort(arr,start,mid,coord);
			MergeSort(arr,mid+1,end,coord);
			
			Merge(arr,start,mid,end,coord);
		}
	}
	public static void Merge(Point[] arr,int start,int mid,int end,int coord){
		
		int l1=mid-start+1;
		int l2=end-mid;
		Point []p1=new Point[l1];
		Point []p2=new Point[l2];
		int i,j,k=start;
		//System.out.println(start+" "+mid+" "+end+" "+l1+" "+l2);
		for(i=0;i<l1;++i){
			p1[i]=new Point();
			copyPoint(arr[start+i],p1[i]);
		}
		for(j=0;j<l2;++j){
			p2[j]=new Point();
			copyPoint(arr[mid+1+j],p2[j]);
			//System.out.println(p2[j].x);
		}
		i=0;j=0;
		if(coord==1){
			while(i<l1 && j<l2){
				
				if(compareX(p1[i],p2[j])){
					copyPoint(p1[i],arr[k]);
					i++;
				}
				else{
					copyPoint(p2[j],arr[k]);
					j++;
				}
				k++;
			}
		}
		else{
			while(i<l1 && j<l2){
				if(compareY(p1[i],p2[j])){
					copyPoint(p1[i],arr[k]);
					i++;
				}
				else{
					copyPoint(p2[j],arr[k]);
					j++;
				}
				k++;
			}
			
		}
		while(i<l1){
			copyPoint(p1[i],arr[k]);
			i++;
			k++;
		}
		while(j<l2){
			copyPoint(p2[j],arr[k]);
			j++;
			k++;
		}
		
		
		
	}
	
	public static void printPoints(Point arr[]){
		if(arr.length>0){
		for(Point p:arr)
			System.out.print("("+p.x+","+p.y+")");
		System.out.println();
		}
		else
			System.out.println("No elements in the array");
	}
	public static double getDistance(Point p,Point q){
		double ans=Math.sqrt((Math.pow((p.x-q.x),2)+Math.pow((p.y-q.y),2))*1.0);
		return ans;
	}
	
}

public class ClosestPair{
	public static void main(String []args){
		Scanner scan=new Scanner(System.in);
		System.out.println("Enter the number of points");
		int count=scan.nextInt();
		Point arr[]=new Point[count];
		System.out.println("Enter the coordinates separated by space,one point per line");
		
		
		for(int i=0;i<count;++i){
			Point p=new Point();
			p.x=scan.nextInt();
			p.y=scan.nextInt();
			arr[i]=p;
		}
		
		Point.sortByX(arr);
		System.out.println("Sorted by X");
		Point.printPoints(arr);
		Point[] ans=findClosestPoint(arr,0,arr.length-1);
		System.out.println("Closest pair points are ");
		Point.printPoints(ans);
		System.out.println("Distance: "+Point.getDistance(ans[0],ans[1]));
		
	}
	
	public static Point[] findClosestPoint(Point arr[],int start,int end){
		Point ans[]=new Point[]{new Point(),new Point()};
		
		if(start<end){
		    
			if((end-start)<3){
					int size=(end-start)+1;
					ans[0]=arr[start];
					ans[1]=arr[start+1];
					double min=Point.getDistance(arr[start],arr[start+1]);
					for(int i=0;i<size;++i)
						for(int j=i+1;j<size;++j)
							if(Point.getDistance(arr[start+i],arr[start+j])<min){
								ans[0]=arr[start+i];
								ans[1]=arr[start+j];
							}
					return ans;		
						
			}
			//System.out.println("Starting element : ("+arr[start].x+","+arr[start].y+") Ending element("+arr[end].x+","+arr[end].y+")");
			int mid=start+(end-start)/2;
			Point median=arr[mid];
			//System.out.printf("Median is (%d,%d)\n",median.x,median.y);
			Point lans[]=findClosestPoint(arr,start,mid);
			Point rans[]=findClosestPoint(arr,mid+1,end);
			double ld=Point.getDistance(lans[0],lans[1]);
			double rd=Point.getDistance(rans[0],rans[1]);
			double d;
			Point ans1[]={new Point(),new Point()};
			if(ld<rd){
				ans1[0]=lans[0];
				ans1[1]=lans[1];
				d=ld;
			}
			else{
				ans1[0]=rans[0];
				ans1[1]=rans[1];
				d=rd;
			
			}
			int j=0;
			Point strip[]=new Point[arr.length];
			for(int i=start;i<=end;++i){
				if(i==mid)
					continue;
				Point p=arr[i];
				//System.out.printf("Point(%d,%d) median(%d,%d) distance %f\n",p.x,p.y,median.x,median.y,d);
				if(Math.abs(p.x-median.x)<d){
					//System.out.println("IN");
					Point k=new Point();
					Point.copyPoint(p,k);
					//System.out.println("Adding point("+k.x+","+k.y+")");
					strip[j++]=k;
				}
			}
			//System.out.printf("Length of strip %d\n",j);
			//System.exit(0);
			if(j>0){
				Point newstrip[]=new Point[j];
				for(int i=0;i<j;++i){
					newstrip[i]=new Point();
					Point.copyPoint(strip[i],newstrip[i]);
				}
			Point.printPoints(newstrip);
			
			Point.sortByY(newstrip);
			double min=d;
			Point ans2[]={new Point(),new Point()};
			for(int i=0;i<newstrip.length;++i){
				for(j=i+1;j<newstrip.length && (newstrip[j].y-newstrip[i].x)<min;++j){
					double dist=Point.getDistance(newstrip[i],newstrip[j]);
					if(dist<min){
						Point.copyPoint(newstrip[i],ans2[i]);
						Point.copyPoint(newstrip[j],ans2[j]);
						min=dist;
					}
				}
			}
			if(min<d)
				return ans2;
			else
				return ans1;
			}
			return ans1;
		}
		return ans;
	}
}