#include <bits/stdc++.h>

#define ll long long

int main(){
    ll n = 0, m = 0;

    scanf("%I64d %I64d", &n, &m);

    ll a[n] = {}, sum[n] = {};
    int mod [m] = {};
    bool flag = true;

    for (int i = 0; i < n; i++){
        scanf("%I64d", &a[i]);

        if (flag){
            if (i == 0){
                sum [i] = a [i];
            }
            else{
                sum [i] = sum [i-1] + a [i];
            }

            if (!(sum[i] % m)){
                flag = false;
            }
            else{
                mod [a[i] % m]++;

                for (int j = 0; j < i; j++){
                    ll s = sum [i] - sum [j];

                    if (!(s % m)){
                        flag = false;
                        break;
                    }
                }
            }
        }
    }

    if (flag){
        for (int i = 1; i < m; i++){
            if (!(m%i)){
                int no = m/i;
                if (mod [i] >= no || mod [m-i*no] >= m-i*no){
                    printf("YES");
                    return 0;
                }
            }
            else if (mod [m-i]){
                printf("YES");
                return 0;
            }
        }
        printf("NO");
    }
    else{
        printf("YES");
    }

    return 0;
}
