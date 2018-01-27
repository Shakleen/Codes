#include <bits/stdc++.h>

int main(){
    int c1,c2,c3,c4,c5;
    scanf("%d %d %d %d %d", &c1, &c2, &c3, &c4, &c5);
    if (c1==0 && c2==0 && c3==0 && c4==0 && c5==0)
        printf("%d",-1);
    else if (!((c1+c2+c3+c4+c5)%5))
        printf("%d",(c1+c2+c3+c4+c5)/5);
    else
        printf("%d", -1);

    return 0;
}
