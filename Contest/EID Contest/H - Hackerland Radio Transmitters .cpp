#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 0, k = 0;

    scanf("%d %d", &n, &k);

    int h[n] = {}, prev = -1, cnt = 0, r = -1;

    for (int i = 0; i < n; i++){
        scanf("%d", &h[i]);
    }

    sort(h, h+n);

    for (int i = 0; i < n; i++){
        if ( h[i] <= r ){
            continue;
        }
        if ( prev == -1 ){
            prev = h[i];
        }
        else{
            int dif = h[i] - prev;

            if (dif > k){
                cnt++;

                if ( h[i] - h[i-1] <= k ){
                    prev = -1;
                }
                else{
                    prev = h[i];
                }

                r = h[i-1] + k;
            }
        }
    }

    printf("%d", cnt + (prev != -1));

    return 0;
}
