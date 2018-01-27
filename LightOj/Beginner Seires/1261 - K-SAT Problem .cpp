#include <bits/stdc++.h>

using namespace std;

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int n = 0, m = 0, k = 0, p = 0;
        char ch = 0;
        bool flag = true;

        scanf("%d %d %d", &n, &m, &k);

        bool g_or_t [n] [k];
        int no [n] [k];

        memset(g_or_t, false, sizeof g_or_t);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < k; j++){
                scanf(" %c%d", &ch, &no[i][j]);

                if (ch == '+')  g_or_t[i][j] = true;
            }
        }

        scanf("%d", &p);

        int ans [p];

        for (int i = 0; i < p; i++){
            scanf("%d", &ans[i]);
        }

        sort(ans, ans+p);

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){

            }
        }
    }

    return 0;
}
