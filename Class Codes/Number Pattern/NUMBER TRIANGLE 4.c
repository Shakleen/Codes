/*
NUMBER TRIANGLE 4
SIZE=4;
      1
    2 4 6
  3 6 9 12 15
4 8 12 16 20 24 28
*/
#include <stdio.h>

int main(){
    int i,j,size;
    i=j=size=0;
    printf("Input the number of lines to print:\n");
    scanf("%d", &size);

    for (i=1; i<=size; i++){
        for (j=0; j<size-i; j++)
            printf("    ");
        int k=2*i-1;
        for (j=1; j<=k; j++)
            printf("%4d", i*j);
        printf("\n");
    }

    return 0;
}
