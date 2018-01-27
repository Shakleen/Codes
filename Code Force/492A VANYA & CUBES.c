#include <stdio.h>

int main(){
    int n=0,i=0,s=0;
    scanf("%d", &n);
    while (1){
        s=((i+1)*(i+2))/2;
        n-=s;
        if (n<0)
            break;
        i++;
    }
    printf("%d", i);
    return 0;
}
