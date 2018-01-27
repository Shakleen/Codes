#include <stdio.h>

int main(){
    int n=0;
    scanf("%d", &n);
    if (!(n%2)){
        printf("%d %d",4,n-4);
    }
    else{
        printf("%d %d",9,n-9);
    }
    return 0;
}
