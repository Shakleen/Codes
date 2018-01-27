#include <bits/stdc++.h>

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int n = 0;

        scanf("%d", &n);

        int a[11] = {}, cnt = 0, no = 0;

        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);

            if (!i && a[i] == 2){
                continue;
            }
            else if (!i && a[i] != 2){
                no = a[i] - 2;
            }
            else{
                no = a[i] - a[i-1];
            }

            if (no <= 5 && no){
                cnt++;
            }
            else{
                int mul = no/5;
                cnt += mul;

                if (mul*5 != no)    cnt++;
            }
        }

        printf("Case %d: %d\n", cs, cnt);
    }

    return 0;
}
