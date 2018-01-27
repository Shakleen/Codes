#include <bits/stdc++.h>

int main(){
    int n = 0;

    scanf("%d", &n);

    int a[n] = {}, total = 0;

    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);

        total += a[i];
    }

    int m = 0;

    scanf("%d", &m);

    if (m == 0){
        printf("-1");
        return 0;
    }

    int s [m] = {}, f [m] = {};

    for (int i = 0; i < m; i++){
        scanf("%d %d", &s[i], &f[i]);
    }

    if (total > f [m-1]){
        printf("-1");
    }
    else if (total == f[m-1]){
        printf("%d", total);
    }
    else{
        bool flag = false, find = false;
        int i = 0;

        for (i = m-1; i >= 0; i--){
            if (s[i] <= total){
                if (s[i]==total){
                    flag = true;
                }
                find = true;
                break;
            }
        }
        if (!find){
            printf("%d", s[0]);
        }
        else if (flag){
            printf("%d", total);
        }
        else{
            if (total <= f[i]){
                printf("%d", total);
            }
            else{
                printf("%d", s[i+1]);
            }
        }
    }

    return 0;
}
