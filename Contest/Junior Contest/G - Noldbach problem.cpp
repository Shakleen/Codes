#include <bits/stdc++.h>

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)
#define N 1000

bool num[N];
int prime[167];

void sieve(void);

int main(){
    sieve();

    int n=0, k=0, cnt=0;
    bool flag=0;

    scanf("%d %d", &n, &k);

    for(int i=0; prime[i] <= n; i++){
        int number = prime[i], j=0;

        while (j < 167){
            int no = prime[j] + prime[j+1] + 1;

            if (no > number)    break;

            if (number == no){
                cnt++;
                break;
            }

            j++;
        }

        if (cnt == k){
            printf("YES");
            flag=1;
            break;
        }
    }

    if (!flag){
        printf("NO");
    }

    return 0;
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
            if (j == 167)
                break;
        }
    }
    return;
}
