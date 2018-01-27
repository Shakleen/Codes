#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)
#define pii                 pair <int, int>

ll fact[21];

int main(){
    fact[0] = 1;

    for (int i = 1; i < 21; i++){
        fact[i] = i*fact[i-1];
    }

    int t = 0;

    scanf("%d", &t);

    while (t--){
        ll n = 0, k = 0, ans = 0;

        scan2(n,k);

        if (n <= k){
            printf("%d\n", 0);
        }
        else{
            printf("%lld\n", fact[n-1]/(fact[k]*(fact[n-1-k])));
        }
    }

    return 0;
}
