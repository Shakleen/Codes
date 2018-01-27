/*
Upper Triangle Matrix:
If all the elements of a matrix below the main diagonal
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
            if (i>j)
                if (m[i][j]!=0)
                    flag=1;
        }
    }
    if (flag==0)
        printf("UPPER TRIANGLE MATRIX");
    else
        printf("NOT UPPER TRIANGLE MATRIX");

    return 0;
}
