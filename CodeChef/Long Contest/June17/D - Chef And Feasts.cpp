#include <bits/stdc++.h>

using namespace std;

int main(){
    int  t = 0;

    scanf("%d", &t);

    while (t--){
        int n = 0;

        scanf("%d", &n);

        int a[n+2] = {};
        long long sum = 0, temp = 0;
        bool first = false;
        int k = 0;

        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);

            if (a[i] <= 0){
                if (first){
                    int no = i - k;
                    sum += (temp * no);

                    temp = 0;
                    k = 0;
                    first = false;
                }
                sum += a[i];
            }
            else{
                if (!first){
                    k = i;
                    first = true;
                }
                temp += a[i];
            }
        }

        if (first){
            int no = n - k;
            sum += (temp * no);
        }

        printf("%I64d\n", sum);
    }

    return 0;
}
