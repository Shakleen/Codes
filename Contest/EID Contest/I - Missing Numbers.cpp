#include <bits/stdc++.h>

int main(){
    int n = 0, m = 0;

    scanf("%d", &n);

    int a[n] = {};

    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    scanf("%d", &m);

    int b[m] = {}, mn = INT_MAX, num [101] = {};

    for (int i = 0; i < m; i++){
        scanf("%d", &b[i]);

        if (b[i] < mn){
            mn = b[i];
        }
    }

    for (int i = 0; i < m; i++){
        num [b[i] - mn]++;
    }

    for (int i = 0; i < n; i++){
        num [a[i] - mn]--;
    }

    for (int i = 0; i < 101; i++){
        if (num[i] > 0){
            printf("%d ", i+mn);
        }
    }

    return 0;
}
