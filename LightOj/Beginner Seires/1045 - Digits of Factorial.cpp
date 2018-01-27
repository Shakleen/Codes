#include <bits/stdc++.h>

double d [1000001];

int main(){
    d[1] = 0;

    int t = 0;

    scanf("%d", &t);

    for (int i = 1; i <= t; i++){
        int n = 0, base = 0, ans = 0;

        scanf("%d %d", &n, &base);

        double div = log10(base), sum = 0;

        if (n == 1){
            printf("Case %d: %d\n", i, 0);
        }
        else if (d[n]){
            ans = d[n]/div + 1;

            printf("Case %d: %d\n", i, ans);
        }
        else{
            for (int i = 2; i <= n; i++){
                sum += log10(i);
                d[i] = sum;
            }

            ans = d[n]/div + 1;

            printf("Case %d: %d\n", i, ans);
        }
    }

    return 0;
}
