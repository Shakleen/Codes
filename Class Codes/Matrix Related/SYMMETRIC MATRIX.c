/*
SYMMETRIC MATRIX
If a matrix is the same as it's transpose matrix then it is a
SYMMETRIC MATRIX!
*/

#include <stdio.h>

#define N 100

int main(){
    int i,j,m[N][N]={},mt[N][N]={},size,flag=0;
    i=j=size=0;
    scanf("%d", &size);
    //Outer loop controls rows
    for (i=0; i<size; i++){
    //Inner loop controls columns
        for (j=0; j<size; j++){
            scanf("%d", &m[i][j]);
            mt[j][i]=m[i][j];
        }
    }
    for (i=0; i<size; i++)
        for (j=0; j<size; j++)
        //Comparing the elements one by one
            if (m[i][j]!=mt[i][j])
                flag=1;
    if (flag)
        printf("NOT SYMMETRIC MATRIX\n");
    else
        printf("SYMMETRIC MATRIX\n");
    return 0;
}
