/*
Lower Triangle Matrix:
If all the elements of a matrix above the main diagonal
is zero then it is called a LOWER TRIANGLE MATRIX
*/
#include <stdio.h>
//Defining the highest possible dimensions for 2D array
#define N 100
int main(){
    int m[N][N]={0}, n, i, j, flag=0;
    n=i=j=0;
    printf("Input matrix size:\n");
    scanf("%d", &n);
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            scanf("%d", &m[i][j]);
            if (j>i)    //column no > row no
                if (m[i][j]!=0)
                    flag=1;
        }
    }
    if (flag==0)
        printf("LOWER TRIANGLE MATRIX");
    else
        printf("NOT LOWER TRIANGLE MATRIX");


    return 0;
}
