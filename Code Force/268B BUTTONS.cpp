#include <bits/stdc++.h>

int main(){
    long long int n=0,push=0;
    scanf("%I64d", &n);
    push=n+n*(n*n-1)/6;
    printf("%I64d", push);
    return 0;
}
