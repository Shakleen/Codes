#include <bits/stdc++.h>

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        long long a = 0, b = 0, c = 0;

        scanf("%lld %lld %lld", &a, &b, &c);

        a = a*a;
        b = b*b;
        c = c*c;

        if (a+b == c || b+c == a || a+c ==b){
            printf("Case %d: yes\n", cs);
        }
        else{
            printf("Case %d: no\n", cs);
        }
    }

    return 0;
}
