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
    bool flag = 0;

    scanf("%d", &n);

    for (ll i=1; i<=n; i++){
        ll num2 = n - i*(i+1)/2;

        if (num2 < 0){
            break;
        }

        ll lo = 1, hi = n;

        while (lo <= hi){
            ll mid = (lo+hi)/2;

            ll no = mid*(mid+1)/2;

            if (no == num2){
                flag = 1;
                break;
            }
            else if (no < num2){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

        if (flag){
            break;
        }
    }

    if (flag){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}
