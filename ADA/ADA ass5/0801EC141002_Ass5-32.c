#include<stdio.h>

int max(int a, int b){
	if(a>b)	return a;
	else if(b>a)	return b;
	else return a; 
}

int function( char a[], char b[], char c[], int l1,
                               int l2, int l3){
    int arr[l1+1][l2+1][l3+1];
    int i,j,k;
    /*for(i=0,j=0,k=0; (i<=l1)&&(j<=l2)&&(k<=l3) ;i++,j++,k++){
                if (i == 0 || j == 0||k==0)
                    arr[i][j][k] = 0;
 
                else if (a[i-1] == b[j-1] && a[i-1]==c[k-1])
                    arr[i][j][k] = arr[i-1][j-1][k-1] + 1;
 
                else
                    arr[i][j][k] = max(max(arr[i-1][j][k],
                                         arr[i][j-1][k]),
                                     arr[i][j][k-1]);
    }*/
        
    for (i=0;i<=l1;i++){
        for (j=0;j<=l2;j++){
            for (k=0;k<=l3;k++){
                if (i == 0 || j == 0||k==0)
                    arr[i][j][k] = 0;
 
                else if (a[i-1] == b[j-1] && a[i-1]==c[k-1])
                    arr[i][j][k] = arr[i-1][j-1][k-1] + 1;
 
                else
                    arr[i][j][k] = max(max(arr[i-1][j][k],
                                         arr[i][j-1][k]),
                                     arr[i][j][k-1]);
            }
        }
    }
    return arr[l1][l2][l3];
}
 
int main()
{
    char a[] = "As123";
    char b[] = "123bd";
    char c[] = "12123X";
 
    int l1 = sizeof(a)-1;
    int l2 = sizeof(b)-1;
    int l3 = sizeof(c)-1;
 
 	int res = function(a, b, c, l1, l2, l3);
    printf("Length = %d",res);
 
    return 0;
}
