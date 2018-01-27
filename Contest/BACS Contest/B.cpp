#include <bits/stdc++.h>

using namespace std;

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int n = 0, k = 0;

        scanf("%d %d", &n, &k);

        int num = 0, s [n] = {}, ki [n] = {}, mx = INT_MIN, sm = 0;

        for (int i = 0; i < n; i++){
            scanf("%d", &num);

            if ( !i )               s[i] = (num>0) ? num : 0;
            else                    s[i] = (num>0) ? num+s[i-1] : s[i-1];

            if (num < 0)    ki[i] = ki[i-1] + 1;
            else            ki[i] = ki[i-1];

            for (int j = i-1; j > -1; j--){
                if (ki[i] - ki[j] <= k){
                    sm = s[i]-s[j];

                    if ( !j )   sm += s[j];
                    if (sm > mx){
                        mx = sm;
//printf("sm=%d mx=%d s[i]=%d s[j]=%d\n",sm,mx,s[i],s[j]);
                    }
                }
            }
        }

        printf("Case %d: %d\n", cs, mx);
    }


    return 0;
}
