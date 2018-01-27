#include <bits/stdc++.h>

#define ll long long

ll bigmod (ll base, ll pow, ll mod);

int main(){
    ll n = 0;

    scanf("%lld", &n);

    ll mod = 1000000007, pow = bigmod(3, n, mod-1);

    ll ans = bigmod (3, pow, mod);

    printf("%lld", ans);

    return 0;
}

ll bigmod (ll base, ll pow, ll mod){
    if (pow == 0){
        return 1;
    }
    else if (pow % 2){
        ll y = bigmod (base, pow - 1, mod);
        return (((base%mod)*y) % mod);
    }
    else{
        ll y = bigmod (base, pow/2, mod);
        return ((y*y) % mod);
    }
}
