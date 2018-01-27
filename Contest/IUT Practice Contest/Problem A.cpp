#include <bits/stdc++.h>

int main(){
    int a, b, c, d;

    while (1){
        a = b = c = d = 0;

        scanf("%d %d %d %d", &a, &b, &c, &d);

        if (!a && !b && !c && !d){
            break;
        }

        int min = abs(c - b), max = abs(a - d);

        printf("%d %d\n", min, max);
    }

    return 0;
}
