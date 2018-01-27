#include <bits/stdc++.h>

using namespace std;

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int n = 0;
        long long acc = 0;

        printf("Case %d:\n", cs);

        scanf("%d", &n);

        for (int i = 1; i <= n; i++){
            string com;

            cin >> com;

            if ( com == "donate" ){
                int k = 0;

                scanf("%d", &k);

                acc += k;
            }
            else if ( com == "report" ){
                printf("%lld\n", acc);
            }
        }
    }

    return 0;
}
