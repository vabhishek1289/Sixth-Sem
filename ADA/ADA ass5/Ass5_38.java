/* 0801EC141002_Ass5_38 */

import java.util.Arrays;
import java.util.Scanner;
import  java.util.Arrays.*;

public class Ass5_38{
    static int a[][];
    static int dp[][];
    public static void main(String[] args) {
        Scanner scan=new Scanner(System.in);
        System.out.println("Enter the number of rows");
        int n=scan.nextInt();
        a=new int[n+1][n+1];
        dp=new int[n+1][n+1];
        for(int[] t:dp)
        Arrays.fill(t,-1);
        System.out.println("Enter elements");
        for(int i=1;i<=n;++i){
           for(int j=1;j<=i;++j){
               a[i][j]=scan.nextInt();
 
           }
        }
        int sum=findMaxSum(1,1,n);
        System.out.println("Answer is "+sum);
    }

    private static int findMaxSum(int i, int j, int end) {
        if(i>end || j>end) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        else if(i<=end){
            return dp[i][j]=a[i][j]+Math.max(findMaxSum(i+1,j,end),findMaxSum(i+1,j+1,end));
        }
        else
            return 0;
    }
}
