#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)

int main(){
    ll n = 0;

    while ( scanf("%lld", &n) != EOF ){
        ll num = 1, cnt = 1, k = 1;

        while (k){
            if (num < n){
                num = num * 10 + 1;
                cnt++;
            }

            k = num % n;
            num = k;
        }

        printf("%lld\n",cnt);
    }

    return 0;
}
