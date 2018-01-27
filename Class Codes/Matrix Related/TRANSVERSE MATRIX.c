/*
TRANSPOSE OF A MATRIX
Row becomes Column and Column becomes Row
*/
#include <stdio.h>
//Defining the highest possible dimensions for 2D array
#define N 100
int main(){
    int matA[N][N]={0},matAt[N][N]={0};
    int rA, cA, rAt, cAt, i, j;
    rA=cA=rAt=cAt=i=j=0;
    printf("Input matrix row and column size:\n");
    scanf("%d %d", &rA, &cA);
    rAt=cA;
    cAt=rA;
    printf("Input the elements of the matrix:\n");
    for (i=0; i<rA; i++){
        for (j=0; j<cA; j++){
            scanf("%d", &matA[i][j]);
            matAt[j][i]=matA[i][j];
        }
    }
    printf("Inputted Matrix:\n");
    for (i=0; i<rA; i++){
        for (j=0; j<cA; j++)
            printf("%5d ", matA[i][j]);
        printf("\n");
    }
    printf("Transverse Matrix:\n");
    for (i=0; i<rAt; i++){
        for (j=0; j<cAt; j++)
            printf("%5d ", matAt[i][j]);
        printf("\n");
    }
    return 0;
}
