#include <bits/stdc++.h>

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)
#define N 46350

bool num[N];
int prime[4794];

void sieve(void);

int main(){
    sieve();

    int n = 0;

    for (int i=1; ; i++){
        scanf("%d", &n);

        if (n == 0){
            break;
        }
        else if (n == 1){
            printf("Case %d: 2\n",i);
        }
        else if (n == 2147483647){
            printf("Case %d: 2147483648\n",i);
        }
        else{
            int no = n, fact_cnt = 0, sum = 0, fact = 1,
                lim = sqrt(no) + 1;

            for(int j = 0; prime[j] <= lim; j++){
                fact = 1;

                if ( !(no%prime[j]) ){
                    fact_cnt++;

                    while ( !(no%prime[j]) ){
                        no/=prime[j];
                        fact *= prime[j];
                    }

                    sum += fact;
                }
            }

            if (no > 1){
                fact_cnt++;
                sum += no;
            }

            if ( fact_cnt == 1 ){
                printf("Case %d: %d\n", i, sum+1);
            }
            else{
                printf("Case %d: %d\n", i, sum);
            }
        }
    }
    return 0;
}

void sieve (void){
    int lim = sqrt(N) + 1;
    for (int i = 3; i <= lim; i += 2){
        if ( !num[i] ){
            for(int k = i*i; k <= N; k += 2*i){
                num[k] = 1;
            }
        }
    }

    prime[0]=2;
    int j=1;

    for (int i = 3; i <= N; i += 2){
        if ( !num[i] ){
            prime[j++] = i;
            if (j == 4794)  break;
        }
    }
    return;
}
