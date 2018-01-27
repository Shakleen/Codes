#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)
#define pii                 pair <int, int>

int main(){
    ll n = 0, m = 0;

    scan2(n,m);

    for (ll i = 2; n >= i && m != 1; i++){
        while ( !(m%i) && n >= i && m != 1){
            n -= i;
            m /= i;
        }
    }

    printf("%lld %lld\n", n,m);

    return 0;
}
