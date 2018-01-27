/*
NUMBER TRIANGLE 3
SIZE=5
        1
      1 2 3
    1 2 3 4 5
  1 2 3 4 5 6 7
1 2 3 4 5 6 7 8 9
*/
#include <stdio.h>

int main(){
    int i,j,size;
    i=j=size=0;

    printf("Input the line number:\n");
    scanf("%d", &size);

    for (i=1; i<=size; i++){
    //To make the triangle look uniform the number of spaces
    //has to be equal to the no on %d specifier
        for (j=0; j<size-i; j++)
            printf("     ");
        int k=2*i-1;
        for (j=1; j<=k; j++){
            printf("%5d",j);
        }
        printf("\n");
    }

    return 0;
}
