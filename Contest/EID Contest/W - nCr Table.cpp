#include <bits/stdc++.h>

#define ll long long
#define N 1000000000

int main(){
    int t = 0;

    scanf("%d", &t);

    while (t--){
        int n = 0;

        scanf("%d", &n);

        ll arr [n+1][n+1] = {};
        arr[0][0] = 1;

        for (int i = 1; i <= n; i++){
            int m = i/2;
            for (int j = 0; j <= i; j++){
                if (j == 0 || j == i){
                    arr[i][j] = 1;
                }
                else if (j <= m){
                    arr[i][j] = (arr[i-1][j-1]%N + arr[i-1][j]%N)%N;
                    arr[i][i-j] = arr[i][j];
                }
                if (i == n){
                    printf("%lld ", arr[i][j]);
                }
            }
        }

        printf("\n");
    }

    return 0;
}
