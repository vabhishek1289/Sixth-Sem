/* 
Consider a highway of M miles. The task is to place billboards on the highway such that revenue
is maximized. The possible sites for billboards are given by number x1 < x2 < ….. < xn-1 < xn, 
specifying positions in miles measured from one end of the road. If we place a billboard at position 
xi, we receive a revenue of ri > 0. There is a restriction that no two billboards can be placed within
t miles or less than it.
Note : All possible sites from x1 to xn are in range from 0 to M as need to place billboards on a 
highway of M miles.
*/


#include<stdio.h>

int max(int a, int b) {
	if(a>b)	return a;
	else	return b;
}
int function(int m, int x[], int revenue[], int n, int t){
    int maxRev[m+1];
    memset(maxRev, 0, sizeof(maxRev));
    int next = 0,i;
    for (i = 1; i <= m; i++){
        if (next < n){
            if (x[next] != i)                maxRev[i] = maxRev[i-1];
            else{
                if (i <= t)                   maxRev[i] = max(maxRev[i-1], revenue[next]);
                else		                  maxRev[i] = max(maxRev[i-t-1]+revenue[next],maxRev[i-1]);
                next++;
            }
        }
        else						          maxRev[i] = maxRev[i - 1];
    }
    return maxRev[m];
}
 
int main(){
    int m = 20, t = 5, x[] = {6, 7, 12, 13, 14}, revenue[] = {5, 6, 5, 3, 1};
    int n = sizeof(x)/sizeof(x[0]);
    printf("Maximum revenue is: %d\n",function(m, x, revenue, n, t));
    return 0;
}

