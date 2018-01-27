#include <bits/stdc++.h>

int main(){
    int t = 0;

    scanf("%d", &t);

    while (t--){
        long long u = 0, v = 0;

        scanf("%lld %lld", &u, &v);

        long long s = u + v, r = (s*(s+1))/2+1+u;

        printf("%lld\n", r);
    }

    return 0;
}
