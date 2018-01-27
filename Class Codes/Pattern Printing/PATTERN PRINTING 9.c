/*
Pattern printing program 9
Size = 5
***** *****
****   ****
***     ***
**       **
*         *
**       **
***     ***
****   ****
***** *****
*/

#include <stdio.h>

int main(){
    int i,j,k,m,size;
    scanf("%d", &size);

    for (i=1; i<(2*size); i++){
        if (i<=size){   //For first portion of the pattern
            k=size-i+1;
            for (j=0; j<k; j++)
                printf("*");
            m=2*i-1;
            for (j=0; j<m; j++)
                printf(" ");
            for (j=0; j<k; j++)
                printf("*");
        }
        else{           //For second portion of the pattern
            m=i-size+1;
            for (j=0; j<m; j++)
                printf("*");
            k=2*(2*size-i)-1;
            for (j=0; j<k; j++)
                printf(" ");
            for (j=0; j<m; j++)
                printf("*");
        }
        printf("\n");
    }


    return 0;
}
