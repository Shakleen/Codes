/*
Pattern Printing Program 8
Size=5
*_*_*_*_*
 *_*_*_*
  *_*_*
   *_*
    *
*/

#include <stdio.h>

int main(){
    int i,j,size,k,m;
    i=j=size=k=m=0;
    //Taking size input
    scanf("%d", &size);

    for (i=1; i<=size; i++){      //Outer loop controls row no
        //Printing the space
        for (j=1; j<i; j++){
            printf(" ");
        }
        //Printing the star
        k=size-i;
        m=2*k+1;
        for (j=0; j<m; j++){
            if (j%2==1)
                printf("_");
            else
                printf("*");

        }
        printf("\n");     //New line at the end of every inner loop
    }

    return 0;
}
