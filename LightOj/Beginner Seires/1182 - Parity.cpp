#include <bits/stdc++.h>

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int n = 0, cnt = 0;

        scanf("%d", &n);

        while (n){
            if (n%2)    cnt++;
            n /= 2;
        }

        if (cnt%2)  printf("Case %d: odd\n", cs);
        else        printf("Case %d: even\n", cs);
    }

    return 0;
}
