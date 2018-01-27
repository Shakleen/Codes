#include <bits/stdc++.h>
#define N 10000

using namespace std;

int prime[1229];
bool num[N];

void sieve(){
    for (int i = 3, len = sqrt(N); i <= len; i += 2){
        if ( !num[i] ){
            for (int k = i*i; k <= N; k += 2*i){
                num[k] = true;
            }
        }
    }

    prime [0] = 2;

    for (int i = 3, j = 1; i <= N; i += 2){
        if (!num[i]){
            prime [j] = i;
            j++;
        }
    }

    return;
}

int main(){
    sieve();

    int t = 0;

    scanf("%d", &t);

    while (t--){
        int no1 = 0, no2 = 0, no3 = 0, j = 0;
        bool f = true;

        scanf("%d %d", &no1, no2);

        while (f){

        }
    }


    return 0;
}
