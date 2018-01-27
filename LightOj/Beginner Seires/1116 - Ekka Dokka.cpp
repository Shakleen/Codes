#include <bits/stdc++.h>

#define ll long long

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        ll w = 0;

        scanf("%lld", &w);

        if (w%2){
            printf("Case %d: Impossible\n", cs);
        }
        else{
            for (ll i = 2; i <= w; i += 2){
                if ( !(w%i) ){
                    ll j = w/i;

                    if ( j%2 ){
                        printf("Case %d: %lld %lld\n", cs, j, i);
                        break;
                    }

                }
            }
        }
    }

    return 0;
}
