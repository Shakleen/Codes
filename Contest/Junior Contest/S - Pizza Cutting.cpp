#include <bits/stdc++.h>

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)

int main(){
    ll n=0;

    while (1){
        scanf("%I64d", &n);

        if (n < 0)  break;

        ll p = 1;

        if (n%2){
            p += n*((n+1)/2);
        }
        else{
            p += (n/2)*(n+1);
        }

        printf("%I64d\n", p);
    }

    return 0;
}
