#include <bits/stdc++.h>

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)
#define N 32770

bool num[N];
int prime[2000];

void sieve (void);

int main(){

    sieve();

    while (1){
        int n=0, cnt=0;

        scanf("%d", &n);

        if (n == 0)   break;

        int lim = (n+1)/2;

        for(int i=0; prime[i] <= lim; i++){

            int k = n - prime[i];

            if (!num[k]){
                cnt++;
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}

void sieve (void){
    num[0]=num[1]=1;

    prime[0]=2;

    for(int i=4; i<=N; i+=2) num[i]=1;

    int j=1;
    double lim = sqrt(N)+1;

    for (int i=3; i <= lim; i+=2){
        if (!num[i]){
            for(int k = i*i; k <= N; k += 2*i){
                num[k]=1;
            }
        }
    }

    for(int i=3; i<=N; i+=2){
        if (!num[i]){
            prime[j++]=i;
            if (j==2000)
                break;
        }
    }
    return;
}
