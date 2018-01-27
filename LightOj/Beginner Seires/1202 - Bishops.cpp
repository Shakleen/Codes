#include <bits/stdc++.h>

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int r1, r2, c1, c2;
        r1=r2=c1=c2=0;

        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

        bool col1 = false, col2 = false;

        if ((r1%2) == (c1%2))   col1 = true;
        if ((r2%2) == (c2%2))   col2 = true;

        printf("Case %d: ", cs);

        if (col1 != col2){
            printf("impossible");
        }
        else if ((r1-c1 == r2-c2) || (r1-r2 == c2-c1)){
            printf("1");
        }
        else{
            printf("2");
        }

        printf("\n");
    }

    return 0;
}
