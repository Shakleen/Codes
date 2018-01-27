/*
MATRIX MULTIPLICATION
*********************************************
*********************************************
**Condition: Matrix 1 Column = Matrix 2 Row**
*********************************************
*********************************************
*/
#include <stdio.h>
//Defining the highest possible dimensions for 2D array
#define N 100
int main(){
    int mat1[N][N]={0},mat2[N][N]={0},mat3[N][N]={0};
    int r1,c1,r2,c2,r3,c3,i,j,k,sum;
    r1=r2=r3=c1=c2=c3=i=j=k=sum=0;
    printf("Input matrix 1 row and column size:\n");
    scanf("%d %d", &r1, &c1);
    printf("Input matrix 2 row and column size:\n");
    scanf("%d %d", &r2, &c2);
    //Check condition for matrix multiplication
    if (c1!=r2)         //If the condition isn't met the program exits
        printf("Matrix Multiplication not possible!\n");
    else{               //If true then it'll execute
        printf("Enter Matrix 1 Elements:\n");
        for (i=0; i<r1; i++)
            for (j=0; j<c1; j++)
                scanf("%d", &mat1[i][j]);
        printf("Enter Matrix 2 Elements:\n");
        for (i=0; i<r2; i++)
            for (j=0; j<c2; j++)
                scanf("%d", &mat2[i][j]);
        printf("Matrix 1:\n");
        for (i=0; i<r1; i++){
            for (j=0; j<c1; j++)
                printf("%6d", mat1[i][j]);
            printf("\n");
        }
        printf("Matrix 2:\n");
        for (i=0; i<r2; i++){
            for (j=0; j<c2; j++)
                printf("%6d", mat2[i][j]);
            printf("\n");
        }
        printf("Matrix 3 = Matrix 1 X Matrix 2\n");
        for (i=0; i<r1; i++){        //Mat3 will have row size same as Mat1
            for (j=0; j<c2; j++){    //Mat3 will have col size same as mat2
                sum=0;              //Don't forget to initialize sum to 0
                for (k=0; k<r2; k++){
                    sum+=mat1[i][k]*mat2[k][j];
                }
                mat3[i][j]=sum;
                printf("%6d", mat3[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
