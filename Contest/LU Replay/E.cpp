#include <bits/stdc++.h>
#define N 1001
#define ll long long
using namespace std;

int main(){
    int k = 0;

    scanf("%d", &k);

    for (int cs = 1; cs <= k; cs++){
        long long n = 0, s = 0, t = 0, cnt = 0, mx = LONG_LONG_MIN;

        scanf("%lld %lld", &n, &s);

        vector <ll> v[N];
        priority_queue < pair<ll,ll> > q;

        for (int i = 1; i <= n; i++){
            ll time = 0, dif = 0;

            scanf("%d %d", &time, &dif);

            v[time].push_back(dif);
        }

        for (int i = 1; i <= s; i++){
            if (v[i].size() != 0){
                for (int j = 0; j < v[i].size(); j++){
                    t+=i;

                    if (t > s) break;

                    cnt++;
                    mx = max(mx, v[i][j]);
                }
            }
        }

        printf("Case %d: ", cs);

        if (cnt)    printf("%lld %lld\n", cnt, mx);
        else        printf("RIP LUIUPC\n");
    }


    return 0;
}
