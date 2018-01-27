#include <bits/stdc++.h>

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int x1 = 0, x2 = 0, y1 = 0, y2 = 0, m = 0;

        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        scanf("%d", &m);

        printf("Case %d:\n", cs);

        for (int i = 0; i < m; i++){
            int x = 0, y = 0;

            scanf("%d %d", &x, &y);

            bool c1 = x < x2 && x > x1,
                 c2 = y < y2 && y > y1;

            if (c1 && c2){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
    }



    return 0;
}
