/*
MAIN DIAGONAL OF MATRIX PROGRAM
Main diagonal is basically the elements whose row and column no is equal
*/
#include <stdio.h>
//Defining the highest size for 2D array
#define N 100
int main(){
    int m[N][N]={0};
    int i, j, k, uppersum=0, lowersum=0, size=0;
    //Taking row size input from user
    printf("Enter matrix Size:\n");
    scanf("%d", &size);
    //Inputting matrix A
    printf("Input values for Matrix A:\n");
    for (i=0; i<size; i++)
        for (j=0; j<size; j++)
            scanf("%d", &m[i][j]);
    //Finding out main diagonal elements
    printf("The Main Diagonal Elements are:\n");
    for (i=0; i<size; i++)
        for (j=0; j<size; j++)
            if (i==j)       //Checking if row no = column no
                printf("%d\t", m[i][j]);
    //Finding the summation of elements above the main diagonal
    printf("\nElements above the main diagonal are:\n");
    for (i=0; i<size; i++)
        for (j=0; j<size; j++)
            if (i<j){
                printf("%d\t", m[i][j]);
                uppersum+=m[i][j];
            }
    printf("\nThe summation of elements above the main diagonal is: %d", uppersum);
    //Fiding the summation of elements below the main diagonal
    printf("\nElements above the main diagonal are:\n");
    for (i=0; i<size; i++)
        for (j=0; j<size; j++)
            if (i>j){
                printf("%d\t", m[i][j]);
                lowersum+=m[i][j];
            }
    printf("\nThe summation of elements above the main diagonal is: %d", lowersum);
    return 0;
}
