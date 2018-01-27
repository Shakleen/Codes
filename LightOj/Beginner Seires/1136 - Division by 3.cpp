#include <bits/stdc++.h>

#define ll long long

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        ll a = 0, b = 0, cnt = 0;

        scanf("%lld %lld", &a, &b);

        ll ak = (a-1)/3, bk = (b-1)/3;

        cnt = (b - a) + 1 - (bk - ak);

        if ((a == 1)||(a > 3 && 3*ak+1 == a)){
            cnt--;
        }

        printf("Case %d: %lld\n", cs, cnt);
    }


    return 0;
}
