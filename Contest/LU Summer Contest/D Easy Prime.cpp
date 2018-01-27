#include <bits/stdc++.h>

#define N 10000000

bool num [N];

void sieve(void);
void iut (int *a, int *b, int size);

int main(){

    sieve();

    int n = 0;

    scanf("%d", &n);

    int a[n] = {}, prime[n] = {}, sum = 0;

    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);

        if (a[i] == 2){
            sum++;
        }
        else if (a[i]%2 && !num[a[i]]){
            sum++;
        }

        prime[i] = sum;
    }

    int q = 0;

    scanf("%d", &q);

    for (int i = 0; i < q; i++){
        int choice = 0, x = 0, y = 0;

        scanf("%d %d %d", &choice, &x, &y);

        if (choice == 1){
            int ans = prime[y-1] - prime[x-1];

            if (!num[a[x-1]] && a[x-1]%2 && a[x-1]!=1){
//                printf("a=%d\n",a[x-1]);
                ans++;
            }
//            printf("Y=%d X=%d\n",prime[y-1],prime[x-1]);
            printf("%d\n", ans);
        }
        else if (choice == 2){
            a[x-1] = y;

            if ((!num[a[x-1]] && a[x-1]%2 && a[x-1] != 1) || (a[x-1] == 2))
                iut(a,prime,n);

//            for (int i = 0; i < n; i++){
//                printf("%d ", a[i]);
//            }
//            printf("\n");
        }
    }
    return 0;
}

void sieve (void){
    int lim = sqrt(N) + 1;

    for (int i = 3; i <= lim; i+=2){
        if (!num[i]){
            for (int k = i*i; k <= N; k += 2*i){
                num[k] = 1;
            }
        }
    }
}

void iut (int *a, int *b, int size){
    int sum = 0;

    for (int i = 0; i < size; i++){

        if (a[i] == 2){
            sum++;
        }
        else if (a[i]%2 && !num[a[i]]){
            sum++;
        }

        b[i] = sum;
    }

    return;
}
