#include <bits/stdc++.h>

int min (int i, int j){
    return i<j ? i: j;
}

int main(){
    int k2,k3,k5,k6;
    k2=k3=k5=k6=0;
    long long int sum=0;

    scanf("%d %d %d %d", &k2, &k3, &k5, &k6);

    int i = min ( min(k2,k5), k6);

    sum += (i*256);

    k2-=i;

    if (k2 && k3){
        int j = min (k2, k3);
        sum += (j*32);
    }

    printf("%I64d", sum);

    return 0;
}
