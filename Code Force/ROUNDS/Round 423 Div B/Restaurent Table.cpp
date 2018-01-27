#include <bits/stdc++.h>

int main(){
    long long n, a, b, c, cnt;
    n = a = b = c = cnt = 0;

    scanf("%lld %lld %lld", &n, &a, &b);

    for (int i = 1; i <= n; i++){
        long long g = 0;

        scanf("%lld", &g);

        if (g == 1){
            if (a){
                a--;
            }
            else if (b){
                b--;
                c++;
            }
            else if (c){
                c--;
            }
            else{
                cnt++;
            }
        }
        else{
            if (b){
                b--;
            }
            else{
                cnt+=2;
            }
        }
    }

    printf("%lld",cnt);

    return 0;
}
