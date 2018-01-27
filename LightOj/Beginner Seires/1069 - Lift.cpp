#include <bits/stdc++.h>

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int me = 0, lift = 0;

        scanf("%d %d", &me, &lift);

        int ans = (abs(me-lift)+me)*4+19;

        printf("Case %d: %d\n", cs, ans);
    }


    return 0;
}
