#include <bits/stdc++.h>

int main(){
    int t = 0;

    scanf("%d", &t);

    while (t--){
        int n = 0, k = 0;

        scanf("%d %d", &n, &k);

        double l = n/2;

        if (k < l){
            printf("%d\n", 2*k+1);
        }
        else{
            printf("%d\n", 2*(n-1-k));
        }
    }


    return 0;
}
