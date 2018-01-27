#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int t = 0;

    scanf("%d", &t);

    while (t--){
        ll n = 0, m = 0;

        scanf("%lld %lld", &n, &m);

        ll minsalary[n+1], offeredsalary[m+1], maxjoboffer[m+1], canjob = 0, totalsalary = 0, nocan = m;
        bool jobgiven[m+1];
        memset(jobgiven, false, sizeof(jobgiven));

        for (int i = 1; i <= n; i++){
            scanf("%lld", &minsalary[i]);
        }

        for (int i = 1; i <= m; i++){
            scanf("%lld %lld", &offeredsalary[i], &maxjoboffer[i]);
        }

        for (int i = 1; i <= n; i++){
            char qual [m+2];
            ll mx = minsalary[i];
            int index = 0;

            scanf(" %s", qual);

            for (int j = 0; j < m; j++){
                if ((qual[j] == '1') && maxjoboffer[j+1] && (offeredsalary[j+1] >= mx)){
                    index = j+1;
                    mx = offeredsalary[j+1];
                }
            }

            if (index){
                totalsalary += mx;
                maxjoboffer[index]--;
                canjob++;

                if (!jobgiven[index]){
                    nocan--;
                    jobgiven[index] = true;
                }
            }
        }

        printf("%lld %lld %lld\n", canjob, totalsalary, nocan);
    }
    return 0;
}
