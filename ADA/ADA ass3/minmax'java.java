public class minmax'java {
    static MaxMin m=new MaxMin();
    static int max,min;
    
    public static void main(String ar[])
    {
        int a[]={10,12,9,7,15,11,1};
        MaxMin.max=MaxMin.min=a[0];
        int[] getMaxMin=m.MaxMin(a, 0, a.length-1, a[0], a[0]);
        System.out.println("Max : "+getMaxMin[0]+"\nMin : "+getMaxMin[1]);
    }
    
    public int[] MaxMin(int[] a,int i,int j,int max,int min)
    {
        int mid,max1,min1;
        int result[]=new int[2];
        //Small(P)
        if (i==j) { max = min = a[i]; } 
     else if (i==j-1) // Another case of Small(P)
          {
                if (a[i] < a[j]) { this.max = getMax(this.max,a[j]); this.min = getMin(this.min,a[i]); }
                else { this.max = getMax(this.max,a[i]); this.min = getMin(this.min,a[j]); }
          }
     else
     {
           // if P is not small, divide P into sub-problems.
           // Find where to split the set.
           mid = ( i + j )/2;
           // Solve the sub-problems.
           max1=min1=a[mid+1];
           MaxMin( a, i, mid, max, min );    
           MaxMin( a, mid+1, j, max1, min1 );
           // Combine the solutions.
           if (this.max < max1) this.max = max1;
           if (this.min > min1) this.min = min1;
     }
        result[0]=this.max;  result[1]=this.min;
        return result;
    }
    
    public static int getMax(int i,int j)
    {
        if(i>j) return i;
        else return j;
    }
    
    public static int getMin(int i,int j)
    {
        if(i>j) return j;
        else return i;
    }
}

