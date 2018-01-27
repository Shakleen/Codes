/*
Fastest way to find a prime by trial method
*/


#include <stdio.h>

int main(){
    long long int n,i;
    int flag;
    i=n=flag=0;
    scanf("%I64d", &n);
    for (i=2; i*i<=n; i++){
        if (n%i==0){
            flag=1;
            break;
        }
    }
    if (flag)
        printf("NOT PRIME");
    else
        printf("PRIME");
    return 0;
}
