#include <bits/stdc++.h>

using namespace std;

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int n = 0;

        scanf("%d", &n);

        int a[n], cur = 0, prev = 0, len = 0;

        bool g = true, b = true, neu = true;

        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);

            if (i == 0) continue;

            if (a[i] != a[i-1]){
                if (a[i] > a[i-1])          b = false;
                else if (a[i] < a[i-1])     g = false;
                neu = false;
            }

            if (i >= 2){
                if (a[i-1] > a[i] && a[i-1] > a[i-2]){
                    if (!prev)  prev = i;
                    else{
                        cur = i;
                        len = max(len, cur - prev - 1);
                        prev = cur;
                    }
                }
            }
        }

        if (neu)                printf("neutral\n");
        else if (g)             printf("allGoodDays\n");
        else if (b)             printf("allBadDays\n");
        else if (len < 2)       printf("none\n");
        else                    printf("%d\n", len);
    }

    return 0;
}
