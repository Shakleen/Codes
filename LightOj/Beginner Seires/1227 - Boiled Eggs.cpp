#include <bits/stdc++.h>

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int n = 0, p = 0, q = 0;

        scanf("%d %d %d", &n, &p, &q);

        int w = 0, cnt = 0;
        bool flag = true;

        for (int i = 0; i < n; i++){
            scanf("%d", &w);

            if (flag){
                if (w <= q && cnt < p){
                    cnt++;
                    q -= w;

                    if (cnt == p){
                        flag = false;
                    }
                }
                else{
                    flag = false;
                }
            }
        }

        printf("Case %d: %d\n", cs, cnt);
    }

    return 0;
}
