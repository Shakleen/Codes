#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int t = 0;

    scanf("%d", &t);

    while (t--){
        ll n = 0, b = 0, ans = 0, m = 0;

        scanf("%lld %lld", &n, &b);

        if ( b >= n/2 && b < n ){
            ans = (n - b);
        }
        else if ( b < n/2 ){
            ll a = 0, mx = n/b;

            for (ll i = mx/2 - 1; i <= mx; i++){
                a = (n-b*i)*i;

                if (a >= ans)    ans = a;
                else             break;
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}
