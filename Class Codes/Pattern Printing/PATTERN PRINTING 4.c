/*
Pattern Printing Program 4
Size=5
    *
   ***
  *****
 *******
*********
*/

#include <stdio.h>

int main(){
    int i,j,size,k;
    i=j=size=k=0;
    //Taking size input
    scanf("%d", &size);

    for (i=1; i<=size; i++){      //Outer loop controls row no
        //Printing the space
        for (j=0; j<size-i; j++){
            printf(" ");
        }
        //Printing the star
        k=2*i-1;
        for (j=0; j<k; j++){
            printf("*");
        }
        printf("\n");     //New line at the end of every inner loop
    }

    return 0;
}
