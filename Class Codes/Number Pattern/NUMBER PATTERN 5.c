/*
NUMBER PATTERN 5
SIZE = 5;
1 1 1 1 1
1 1     1
1   1   1
1     1 1
1 1 1 1 1
*/

#include <stdio.h>

int main(){
    int i,j,size;
    i=j=size=0;
    printf("Input the number of lines to print:\n");
    scanf("%d", &size);

    for (i=0; i<size; i++){
        if (i==0 || i==size-1){
            for (j=0; j<size; j++)
                printf("%d ", 1);
        }
        else{
            printf("%d ", 1);
            for (j=1; j<i; j++)
                printf("  ");
            printf("%d ", 1);
            for (j=1; j<=size-2-i; j++)
                printf("  ");
            printf("%d ", 1);
        }
        printf("\n");
    }
    return 0;
}
