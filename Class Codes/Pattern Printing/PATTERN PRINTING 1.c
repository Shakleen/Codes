/*
Pattern Printing Program 1
Rowsize=5 Colsize=5
*****
*****
*****
*****
*****
*/

#include <stdio.h>

int main(){
    int i,j,rowsize, colsize;
    i=j=rowsize=colsize=0;
    //Taking row and column size input
    scanf("%d %d", &rowsize, &colsize);

    for (i=0; i<rowsize; i++){      //Outer loop controls row no
        for (j=0; j<colsize; j++){  //Inner loop controls column no
            printf("*");
        }
        printf("\n");     //New line at the end of every inner loop
    }

    return 0;
}
