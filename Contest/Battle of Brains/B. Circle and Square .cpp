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
    double x = 1/(sqrt(2)), y = 1;

    for (int i = 0; i < 100; i++){
        y *= x;
    }

    int t = 0;

    scanf("%d", &t);

    while (t--){
        int R = 0;

        scanf("%d", &R);

        printf("%.1lf\n", (R*(1-y))/(1-x));
    }

    return 0;
}
