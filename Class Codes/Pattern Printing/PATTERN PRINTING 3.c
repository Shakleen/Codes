/*
Pattern Printing Program 3
Size=5
*****
****
***
**
*
*/

#include <stdio.h>

int main(){
    int i,j,size;
    i=j=size=0;
    //Taking size input
    scanf("%d", &size);

    for (i=0; i<size; i++){      //Outer loop controls row no
        for (j=0; j<size-i; j++){  //Inner loop controls column no
            printf("*");
        }
        printf("\n");     //New line at the end of every inner loop
    }

    return 0;
}
