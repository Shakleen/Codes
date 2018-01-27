#include <bits/stdc++.h>

int main(){
    int n,m,a,b,rubles;
    n=m=a=b=rubles=0;
    scanf("%d %d %d %d", &n, &m, &a, &b);
    if (m*a>b){
        rubles=(n/m)*b;
        n%=m;
        if (b<n*a)
            rubles+=b;
        else
            rubles+=n*a;
        printf("%d", rubles);
    }
    else{
        rubles=a*n;
        printf("%d", rubles);
    }
    return 0;
}
