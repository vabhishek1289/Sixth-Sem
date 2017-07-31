#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int comp=0,sp=0;

struct Point
{
    int x, y;
};







void DIVIDE(int ARRAY[],int low,int high)
{
	int mid;
	if(low < high)
	{	
		mid = (low + high) / 2;
		DIVIDE(ARRAY, low, mid);
		DIVIDE(ARRAY, mid + 1, high);
		MERGEALGO(ARRAY, low, mid, high);
	}
}

void MERGEALGO(int ARRAY[],int low,int mid,int high)
{
	int i, mi, k, lo, temp[1000];
	lo = low;
	i = low;
	mi = mid + 1;
	while ((lo <= mid) && (mi <= high))
	{	comp++;
		if (ARRAY[lo] <= ARRAY[mi])
		{	comp++;
			temp[i] = ARRAY[lo];
			lo++;
		}
		else
		{	comp++;
			temp[i] = ARRAY[mi];
			mi++;
		}
		i++;
	}
	comp++;
	while(lo<=mid){
		comp++;
		temp[i]=ARRAY[lo];
		lo++;
		i++;
	}
	comp++;
	while(mi<= high){
		comp++;
		temp[i]=ARRAY[mi];
		mi++;
		i++;
	}
	comp++;
/*	if (lo > mid)
	{	comp++;
		for (k = mi; k <= high; k++)
		{
			temp[i] = ARRAY[k];
			i++;
			//sp++;
		}
	}
	else
	{	comp++;
		for (k = lo; k <= mid; k++)
		{
			temp[i] = ARRAY[k];
			i++;
			//sp++;
		}
	}*/
	for (k = low; k <= high; k++)
	{	
		ARRAY[k] = temp[k];
		sp++;
	}
}

















float dist(struct Point p1, struct Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}
 
// A Brute Force method to return the smallest distance between two points
// in P[] of size n
float bruteForce(struct Point P[], int n)
{
    float min = 1000.00f;
    int i,j;
    for (i = 0; i < n; ++i)
        for (j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}




float stripClosest(struct Point strip[], int size, float d)
{
    float min = d;  // Initialize the minimum distance as d
 
    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    int i,j;
    for (i = 0; i < size; ++i)
        for (j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);
 
    return min;
}



float closestUtil(int P1[],int P2[], int n)
{
	struct Point Px[n];
	struct Point Py[n];
	int i;
	for (i = 0; i < n; i++)
    {
        Px[i].x = P1[i];
        Px[i].y = P2[i];
        
        Py[i].x = P1[i];
        Py[i].y = P2[i];
    }
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(Px, n);
        
    // Find the middle point
    int mid = n/2;
    struct Point midPoint = Px[mid];
 
 
    // Divide points in y sorted array around the vertical line.
    // Assumption: All x coordinates are distinct.
    struct Point Pyl[mid+1];   // y sorted points on left of vertical line
    struct Point Pyr[n-mid-1];  // y sorted points on right of vertical line
    int li = 0, ri = 0;  // indexes of left and right subarrays
    for (i = 0; i < n; i++)
    {
      if (Py[i].x <= midPoint.x)
         Pyl[li++] = Py[i];
      else
         Pyr[ri++] = Py[i];
    }
 
    // Consider the vertical line passing through the middle point
    // calculate the smallest distance dl on left of middle point and
    // dr on right side
    float dl = closestUtil(Px, Pyl, mid);
    float dr = closestUtil(Px + mid, Pyr, n-mid);
 
    // Find the smaller of two distances    
 	float d = (dl < dr)? dl : dr;
	
	// Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    struct Point strip[n];
    int j = 0;
    for (i = 0; i < n; i++){
    int temp= Py[i].x - midPoint.x;
    if(temp<0)	temp=temp*(-1);
    if (temp < d)
    	strip[j] = Py[i], j++;
	}
    // Find the closest points in strip.  Return the minimum of d and closest
    // distance is strip[]
    float local_result=stripClosest(strip, j, d);
    return (d < local_result)? d : local_result;
	

}



float closestpair(struct Point P[], int n){
	int Px[n];
    int Py[n];
    int i;
    for (i = 0; i < n; i++)
    {
        Px[i] = P[i].x;
        Py[i] = P[i].y;
    }
    
    DIVIDE(Px, 0, n - 1);
    /*for (i = 0; i < n; i++)			//Yaha Px me x-soted h
    {
    	printf("%d ",Px[i]);
    }
    printf("\n");*/
    DIVIDE(Py, 0, n - 1);
    /*for (i = 0; i < n; i++)			//Yaha Py me y-soted h
    {
    	printf("%d ",Py[i]);
    }
    return 0;*/
    return closestUtil(Px, Py, n);
    
    
    
    
    
}

















int main()
{
    struct Point P[] = {{1,2},{5,3},{2,9},{6,5},{1,7}};
    int n = sizeof(P) / sizeof(P[0]);
    //printf("%d",n);
    float res=closestpair(P,n);
    printf("%f",res);
    
	return 0;
}


