#include <bits/stdc++.h>

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)

int main(){
    int t=0;

    scanf("%d", &t);

    while (t--){
        ll n=0, r=0;
        int i=0;
        scanf("%I64d", &n);

        while (r<=n){
            i++;
            r = i*(i+1)/2;
        }

        printf("%d\n", i-1);
    }

    return 0;
}
