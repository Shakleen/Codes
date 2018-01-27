#include <bits/stdc++.h>

#define ll long long

bool pw (ll num){
    if (num%2){
        return 0;
    }
    else{
        while (num != 0){
            if (num%2 && num != 1)  return 0;
            num /= 2;
        }

        return 1;
    }
}

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int in = 1; in <= t; in++){
        ll n = 0;

        scanf("%lld", &n);

        if (n == 1){
            printf("Case %d: 2\n", in);
        }
        else if ( !(n%2) && pw(n) ){
            printf("Case %d: %lld\n", in, n*2);
        }
        else{
            bool a[32], b[32];
            int cnt = 0, sz = 0, k = 1;
            ll no = 0;

            memset(a,0,sizeof(a));
            memset(b,0,sizeof(b));

            for (int i = 0; n != 0; i++, n /= 2, sz++){
                a[i] = n%2;
            }

            for(int i = 0; i <= sz; i++, k++){
                if (a[i] && !a[k]){
                    break;
                }

                if (a[i]){
                    cnt++;
                }
            }


            for (int i = 0; i < cnt; i++){
                b[i] = 1;
            }

            b[k] = 1;

            for (int i = k+1; i <= sz+1; i++){
                b[i] = a[i];
            }

            for (int i = 0, po = 1; i <= sz+1; i++, po *= 2){
                no += b[i] * po;
            }

            printf("Case %d: %lld\n", in, no);
        }
    }

    return 0;
}
