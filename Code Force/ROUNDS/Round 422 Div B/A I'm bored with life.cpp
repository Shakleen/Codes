#include <bits/stdc++.h>

using namespace std;

int main(){
    long long a = 0, b = 0;

    scanf("%I64d %I64d", &a, &b);

    long long ans = min (a, b);

    for (long long i = ans-1; i > 0; i--){
        ans *= i;
    }

    printf("%I64d", ans);

    return 0;
}
