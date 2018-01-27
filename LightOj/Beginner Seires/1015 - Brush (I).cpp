#include <bits/stdc++.h>

using namespace std;

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int i = 1; i <= t; i++){
        int n = 0;

        scanf("%d", &n);

        int a = 0, sum = 0;

        while (n--){
            scanf("%d", &a);

            if (a > 0){
                sum += a;
            }
        }

        if (sum >= 0){
            printf("Case %d: %d\n", i, sum);
        }
    }
    return 0;
}
