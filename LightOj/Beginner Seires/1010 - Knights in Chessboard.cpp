#include <bits/stdc++.h>

using namespace std;

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int i = 0; i < t; i++){
        int m = 0, n = 0;

        scanf("%d %d", &m, &n);

        int s = n*m, ans = 0;

        if (n == 1 || m == 1){
            printf("Case %d: %d\n", i+1, s);
        }
        else if (n == 2 || m == 2){
            if (n == 2){
                ans = m;
            }
            else{
                ans = n;
            }

            if (ans%4 == 1 || ans%4 == 3){
                ans++;
            }
            else if (ans%4 == 2){
                ans += 2;
            }

            printf("Case %d: %d\n", i+1, ans);
        }
        else{
            printf("Case %d: %d\n", i+1, (s+1)/2);
        }
    }

    return 0;
}
