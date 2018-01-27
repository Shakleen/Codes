/*
Matrix Addition and Subtraction program
Condition: All the matrix has to have EQUAL no of
ROWS and COLUMNS!
*/
#include <stdio.h>
//Defining the highest possible dimensions for 2D array
#define N 100
int main(){
    int mat1[N][N]={0},mat2[N][N]={0}, matAns[N][N]={0};
    int r1, c1, r2, c2, i, j, flag;
    r1=r2=c1=c2=i=j=flag=0;
    printf("Input matrix 1 row and column size:\n");
    scanf("%d %d", &r1, &c1);
    printf("Input matrix 2 row and column size:\n");
    scanf("%d %d", &r2, &c2);
    if (r1!=r2 || c1!=c2)
        printf("Matrix addition or subtraction isn't possible!\n");
    else{
        printf("Enter elements for matrix 1\n");
        for (i=0; i<r1; i++)        //Outer loop controls ROW
            for (j=0; j<c1; j++)    //Inner loop controls COLUMN
                scanf("%d", &mat1[i][j]);
        printf("Enter elements for matrix 2\n");
        for (i=0; i<r1; i++)        //Outer loop controls ROW
            for (j=0; j<c1; j++)    //Inner loop controls COLUMN
                scanf("%d", &mat2[i][j]);
        printf("Matrix 1 + Matrix 2 equals\n");
        for (i=0; i<r1; i++){       //Outer loop controls ROW
            for (j=0; j<c1; j++){   //Inner loop controls COLUMN
                matAns[i][j]=mat1[i][j]+mat2[i][j];
                printf("%d ", matAns[i][j]);
            }
            printf("\n");
        }
        printf("Matrix 1 - Matrix 2 equals\n");
        for (i=0; i<r1; i++){       //Outer loop controls ROW
            for (j=0; j<c1; j++){   //Inner loop controls COLUMN
                matAns[i][j]=mat1[i][j]-mat2[i][j];
                printf("%d ", matAns[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
