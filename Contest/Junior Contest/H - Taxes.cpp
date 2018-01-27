#include <bits/stdc++.h>

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)
#define N 46000

bool num[N];
int prime[4700];

void sieve(void);
bool isprime(ll num);

int main(){
    sieve();

    ll n=0;
    int cnt=0;

    scanf("%I64d", &n);

    if ( n == 2 ){
        cnt = 1;
    }
    else if ( !(n%2) ){
        cnt = 2;
    }
    else if ( isprime(n) ){
        cnt = 1;
    }
    else{
        bool con = isprime(n-2);
        if (con)    cnt = 2;
        else        cnt = 3;
    }
    printf("%d", cnt);

    return 0;
}

bool isprime(ll num){
    int lim = sqrt(num) + 1;

    for(int i=0; prime[i] <= lim; i++){
        ll no = prime[i];

        if ( !(num%no) ){
            return 0;
        }
    }
    return 1;
}

void sieve (void){
    num[0]=num[1]=1;

    for (int i=4; i <= N; i += 2)   num[i] = 1;

    int lim = sqrt(N) + 1, j=1;

    for (int i=3; i <= lim; i += 2){
        if ( !num[i] ){
            for (int k = i*i; k <= N; k += 2*i){
                num[k] = 1;
            }
        }
    }

    prime[0]=2;

    for (int i=3; i<=N; i++){
       if ( !num[i] ){
            prime[j++] = i;
            if (j == 4700)
                break;
        }
    }
    return;
}
