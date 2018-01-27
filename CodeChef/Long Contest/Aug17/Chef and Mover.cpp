#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int t = 0;

    scanf("%d", &t);

    while (t--){
        int n = 0, d = 0;
        ll sum = 0;

        scanf("%d %d", &n, &d);

        ll a[n+1];

        for (int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);

            sum += a[i];
        }

        if (sum%n){
            printf("%d\n", -1);
        }
        else{
            ll avg = sum/n, moves = 0;
            bool brk = false;

            for (int i = 1; i <= n; i++){
                if (a[i] == avg){
                    continue;
                }
                else if (a[i] < avg){
                    ll x = (avg-a[i]);

                    if (i+d <= n){
                        a[i] += x;
                        a[i+d] -= x;
                        moves += x;
                    }
                    else if (i-d >= 1){
                        a[i] += x;
                        a[i-d] -= x;
                        moves += x;
                    }
                    else{
                        brk = true;
                        break;
                    }
                }
                else{
                    ll x = (a[i]-avg);

                    if (i+d <= n){
                        a[i] -= x;
                        a[i+d] += x;
                        moves += x;
                    }
                    else if (i-d >= 1){
                        a[i] -= x;
                        a[i-d] += x;
                        moves += x;
                    }
                    else{
                        brk = true;
                        break;
                    }
                }
            }

            if (brk){
                printf("%d\n", -1);
            }
            else{
                for (int i = 1; i <= n; i++){
                    if (a[i] != avg){
                        brk = true;
                    }
                }

                if (brk){
                    printf("%d\n", -1);
                }
                else{
                    printf("%lld\n", moves);
                }
            }
        }
    }

    return 0;
}
