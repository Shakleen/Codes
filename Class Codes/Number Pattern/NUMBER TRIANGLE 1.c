#include <stdio.h>

int main(){
    int i, j, size;
    printf("Enter Size:\n");
    scanf("%d", &size);

    for (i=0; i<size; i++){
        for (j=1; j<=size-i; j++)
            printf("%d ", j);
        printf("\n");
    }

    return 0;
}
