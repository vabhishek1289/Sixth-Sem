import java.util.Scanner;

public class A0801EC141002_A4_27 {
	public static void main(String []args){
		Scanner scan=new Scanner(System.in);
		System.out.println("Enter capacity,rate of fuel comsumption and rate of filling petrol");
		int c=scan.nextInt();
		double f=scan.nextDouble();
		double r=scan.nextDouble();
		System.out.println("Enter the number of stations :");
		int stationcount=scan.nextInt();
		int stations[]=new int[stationcount];
		System.out.println("Enter the postion of each station :");
		for(int i=0;i<stationcount;i++)
			stations[i]=scan.nextInt();
		int distances[]=new int[stationcount-1];
		for(int i=0;i<stationcount-1;++i)
			distances[i]=stations[i+1]-stations[i];
		System.out.println("Algorithm 1");
		algorithm1(c,f,r,stations,distances);
		System.out.println("\nAlgorithm 2");
		algorithm2(c,f,r,stations,distances);	
		
	}
	public static void algorithm1(int c,double f,double r,int stations[],int distances[]){
	//Assuming petrol is 0 at the starting point
		int i=0;
		double petrol=0;
		int distance;
		double litresreq,time=0;
		
		for(i=0;i<stations.length-1;++i){
			System.out.println("At station "+i+" petrol remaining: "+petrol);
			distance=distances[i];
			litresreq=Math.ceil(distance*f);
			if(petrol>litresreq)
				continue;
			if(litresreq>c)
				litresreq-=c;
			
			double fueltime=(litresreq-petrol)/r;
			
			petrol=petrol+litresreq;
			System.out.println("Stopped at station "+i+". Filling   :"+litresreq+" litres.Time taken: "+fueltime+" min");
			time+=fueltime;
			petrol=petrol-(distance*f);
		}
		System.out.println("Total time taken in filling  : "+time+ "min");
	}
	
	public static void algorithm2(int c,double f,double r,int stations[],int distances[]){
	//Assuming petrol is 0 at the starting point
		int i=0;
		double petrol=0;
		int distance;
		double litresreq,time=0;
		
		for(i=0;i<stations.length-1;++i){
			System.out.println("At station "+i+" petrol remaining: "+petrol);
			distance=distances[i];
			litresreq=Math.ceil(distance*f);
			if(petrol>litresreq)
				continue;
			if(litresreq>c){
				System.out.println("Petrol required is greater than capacity !!");
				break;
			}
			
			double fueltime=(c-petrol)/r;
			
			petrol=c;
			System.out.println("Stopped at station "+i+". Filling   :"+(c-petrol)+" litres.Time taken: "+fueltime+" min");
			time+=fueltime;
			petrol=petrol-(distance*f);
		}
		System.out.println("Total time taken in filling  : "+time+ "min");
	}
}