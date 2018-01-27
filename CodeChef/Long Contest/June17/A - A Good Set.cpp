#include <bits/stdc++.h>

int main(){
    int t = 0;

    scanf("%d", &t);

    while (t--){
        int n = 0;

        scanf("%d", &n);

        if (n == 1){
            printf("1\n");
        }
        else if (n == 2){
            printf("1 2\n");
        }
        else{
            printf("1 2");

            n-=2;

            for (int i = 4; n; i += 3){
                printf(" %d", i);
                n--;
            }
            printf("\n");
        }
    }

    return 0;
}
