#include <stdio.h>

int main(){
    long long int a=0,b=0, mina=100000000, minb=100000000;
    int n, i;
    scanf("%d", &n);
    for (i=0; i<n; ++i){
        scanf("%lld %lld", &a, &b);
        if (a<mina) mina=a;
        if (b<minb) minb=b;
    }
    printf("%lld", mina*minb);
    return 0;
}
