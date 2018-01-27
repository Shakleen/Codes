#include <bits/stdc++.h>

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int n = 0, k = 0;

        scanf("%d %d", &n, &k);

        int a[n][n] = {}, b[n][n] = {}, c = 0, v = 0;
        bool flag = false;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                scanf("%d", &a[i][j]);
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                scanf("%d", &b[i][j]);
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (a[i][j] != b[i][j]){
//printf("C a=%d b=%d\n", a[i][j], b[i][j]);
                    c++;
                }
                if (i != j && i < j){
                    if (a[i][j] == b[j][i]){
//printf("V a=%d b=%d i=%d j=%d\n", a[i][j], b[j][i], i, j);
                        v++;
                    }
                }
                if (b[i][j] != b[j][i]){
                    flag = true;
                }
            }
        }
//printf("v = %d c = %d\n", v, c);
        if (!flag){
            printf("Case %d: %d\n", cs, -1);
        }
        else{
            if (v == (n*n-n)/2){
                printf("Case %d: %d\n", cs, c+1);
            }
            else{
                printf("Case %d: %d\n", cs, c);
            }
        }
    }



    return 0;
}
