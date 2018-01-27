#include <bits/stdc++.h>

int main(){
    long long a = 0, b = 0, c = 0, k = 0;

    scanf("%lld", &a);

    if (a%2){
        k = (a-1)/2;
        b = (k+1)*(k+1) + k*k;
        c = 2*k*(k+1);
    }
    else{
        k = a/2;
        b = k*k + 1;
        c = k*k - 1;
    }

    printf("%lld %lld %lld", a, b, c);

    return 0;
}
