/*
NUMBER TRIANGLE PROBLEM 2
*/

#include <stdio.h>

int main(){
    int i,j,k,linesize;
    i=j=linesize=0;
    k=1;
    scanf("%d", &linesize);
    //Outer loop controls line number
    for (i=1; i<=linesize; i++){
        //This loop controls the spaces
        for (j=0; j<(linesize-i); j++)
            printf("   ");
        //This loop prints the numbers
        //The amount of numbers to input is the line number
        for (j=0; j<i; j++){
            printf("%6d", k);
            k++;
        }
        printf("\n");
    }
    return 0;
}
