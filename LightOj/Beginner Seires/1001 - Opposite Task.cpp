#include <bits/stdc++.h>

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int i = 1; i <= t; i++){
        int n = 0;

        scanf("%d", &n);

        if (n <= 10){
            printf("%d %d\n", n, 0);
        }
        else{
            printf("%d %d\n", n-10, 10);
        }
    }

    return 0;
}
