#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)
#define N 1000000007

ll bigmod (ll x, ll n, ll m);

int main(){
    ll n=0;

    scanf("%I64d", &n);

    ll no1 = bigmod (27, n, N), no2 = bigmod(7, n, N),
       no3 = (no1 - no2 + N) % N;

    printf("%I64d", no3);

    return 0;
}

ll bigmod (ll x, ll n, ll m){
    if (n == 0){
        return 1;
    }
    else if ( !(n%2) ){
        ll y = bigmod(x,n/2,m);
        return ((y*y)%m);
    }
    else{
        ll y1 = x % m, y2 = bigmod(x, n-1, m);
        return ((y1*y2)%m);
    }
}
