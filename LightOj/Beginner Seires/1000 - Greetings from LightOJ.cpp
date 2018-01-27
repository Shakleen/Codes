#include <bits/stdc++.h>

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int i = 1; i <= t; i++){
        int a = 0, b = 0;

        scanf("%d %d", &a, &b);

        printf("Case %d: %d\n", i, a+b);
    }

    return 0;
}
