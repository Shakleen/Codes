#include <bits/stdc++.h>

int bigmod(int base, int power, int MOD);

int main(){
    int n = 0;

    scanf("%d", &n);

    int d = bigmod(1378, n, 10);

    printf("%d", d);

    return 0;
}

int bigmod(int base, int power, int MOD){
    if (power == 0){
        return 1;
    }
    else if ( !(power % 2) ){
        int y = bigmod(base, power/2, MOD);
        return (y * y) % MOD;
    }
    else{
        int y = bigmod(base, power-1, MOD);
        return (y * (base % MOD)) % MOD;
    }
}
