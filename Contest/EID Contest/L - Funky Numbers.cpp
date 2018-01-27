#include <bits/stdc++.h>

#define ll long long

int main(){
    ll n = 0;

    scanf("%I64d", &n);

    bool f = false;

    for (ll i = 1; i <= n; i++){
        ll no2 = n - (i*(i+1))/2;

        if (no2 < 0){
            break;
        }

        ll lo = 1, hi = no2;

        while (lo <= hi){
            ll mid = (lo+hi)/2;

            ll no3 = (mid*(mid+1))/2;

            if (no3 == no2){
                f = true;
                break;
            }
            else if (no3 > no2){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }

        if (f){
            break;
        }
    }

    if (f){
        printf("YES");
    }
    else{
        printf("NO");
    }

    return 0;
}
