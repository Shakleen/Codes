#include <bits/stdc++.h>

int main(){
    int q = 0;

    scanf("%d", &q);

    while (q--){
        long long n = 0;

        scanf("%lld", &n);

        long long ans = 1 + (n*(2+(n-1)*4))/2;

        printf("%lld\n",ans);
    }

    return 0;
}
