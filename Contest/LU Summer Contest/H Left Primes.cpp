#include <bits/stdc++.h>

#define N 10000001
#define M 664579

bool num [N];
int prime [M];

int sieve(void);
int bsearch (int x, int hi);

int main(){
    int l = sieve();

    int t = 0;

    scanf("%d", &t);

    while (t--){
        int n = 0;

        scanf("%d", &n);

        int i = bsearch(n,l);

        if (i < 0){
            i = 0;
        }

        printf("%d\n", i);
    }


    return 0;
}

int sieve (void){
    int lim = sqrt(N) + 1;

    for (int i = 3; i <= lim; i++){
        if (!num[i]){
            for (int k = i*i; k <= N; k += 2*i){
                num[k] = 1;
            }
        }
    }

    prime [0] = 2;

    int j = 1;

    for (int i = 3; i <= N; i += 2){
        if (!num[i]){
            prime[j++] = i;
        }
    }

    return j - 1;
}

int bsearch (int x, int hi){
    int lo = 0;

    while (lo <= hi){
        int mid = (lo + hi)/2;

        if (prime[mid] == x){
            return mid;
        }
        else if (prime[mid] > x){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }

    return lo;
}
