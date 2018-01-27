#include <bits/stdc++.h>

using namespace std;

#define N                   100000000
#define M                   5761455
#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)
#define pii                 pair <int, int>

bool num[N];
int prime[M];

void sieve(){
    for (int i = 4; i <= N; i += 2){
        num [i] = 1;
    }

    for (int i = 3; i*i <= N; i += 2){
        if ( !num[i] ){
            for (int k = i*i; k <= N; k += 2*i){
                num[k] = 1;
            }
        }
    }

    prime[0] = 2;
    int j = 1;

    for (int i = 3; i <= N; i += 2){
        if (!num[i]){
            prime[j++] = i;
        }
    }
    return;
}

int factor_no (int n){
    int cnt = 0;

    for (int i = 1; i*i <= n; i++){
        if ( !(n%i) ){
            cnt++;

            if (n/i != i)   cnt++;
        }
    }

    return cnt;
}


int main(){
    int n = 0, m = 0;
    ll sum = 0;

    scan2(n,m);

    for (int i = 0; i < m; i++){
        int a = 0, b = 0, c = 0;

        scanf("%d %d %d", &a, &b, &c);

        sum += 2*c;
    }

    printf("%lld\n", sum);

    return 0;
}
