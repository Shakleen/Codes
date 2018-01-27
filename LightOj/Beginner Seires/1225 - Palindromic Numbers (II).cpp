#include <bits/stdc++.h>

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int n = 0;

        scanf("%d", &n);

        if ( !n ){
            printf("Case %d: Yes\n", cs);
            continue;
        }

        int digits [10] = {}, j = 0;
        bool f = true;

        while (n){
            digits [j++] = n%10;
            n /= 10;
        }

        j--;

        for (int i = 0, lim = j/2; i <= lim; i++){
            if (digits [i] != digits [j-i]){
                f = false;
            }
        }

        if (f)  printf("Case %d: Yes\n", cs);
        else    printf("Case %d: No\n", cs);
    }

    return 0;
}
