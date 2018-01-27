#include <bits/stdc++.h>

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int j = 0; j < t; j++){
        long long s = 0, i = 0, k = 0, x = 0, y = 0;

        scanf("%lld", &s);

        i = sqrt(s);
        k = i*i;

        if (k != s){
            i++;
            k = i*i;
        }

        long long dif = k - s;

        if (k%2){
            x = 1;
            y = i;

            if (dif < i){
                x += dif;
            }
            else{
                x += (i-1);
                y -= (dif-i+1);
            }
        }
        else{
            x = i;
            y = 1;

            if (dif < i){
                y += dif;
            }
            else{
                y += (i-1);
                x -= (dif-i+1);
            }
        }
        printf("Case %d: %lld %lld\n", j+1, x, y);
    }

    return 0;
}
