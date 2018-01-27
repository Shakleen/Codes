/*
Pattern Printing Program 6
Size=5
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
*/

#include <stdio.h>

int main(){
    int i,j,size,k,m;
    //k controls spaces
    //m controls stars
    //i controls the row
    //j control the column
    i=j=size=k=m=0;
    //Taking size input
    scanf("%d", &size);
    //The no of rows will be 2 times the size
    for (i=1; i<(2*size); i++){      //Outer loop controls row no
        //For the first half
        if (i<=size){
            k=size-i;
            for (j=0; j<k; j++)
                printf(" ");
            m=2*i-1;
            for (j=0; j<m; j++)
                printf("*");
        }
        //For the second half
        else{
            k=i-size;
            for (j=0; j<k; j++)
                printf(" ");
            m=2*size-i;
            for (j=0; j<(2*m-1); j++)
                printf("*");
        }
        printf("\n");     //New line at the end of every inner loop
    }

    return 0;
}
