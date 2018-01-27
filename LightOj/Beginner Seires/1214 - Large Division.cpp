#include <bits/stdc++.h>

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        char a [201] = {};
        long long b = 0, num = 0;
        int m = 0;

        scanf("%s %lld", a, &b);

        if (a[0] == '-')    m = 1;

        for (int i = m; a[i]; i++, num *= 10){
            num += (a[i]-'0');

            if (num >= b)   num %= b;
        }

        if (!num) printf("Case %d: divisible\n", cs);
        else      printf("Case %d: not divisible\n", cs);
    }

    return 0;
}
