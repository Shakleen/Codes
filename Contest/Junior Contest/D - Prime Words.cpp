#include <bits/stdc++.h>

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)
#define N 1050

bool num[N];

void sieve (void);

int main(){
    sieve();

    char str[22]={};

    while ( scanf("%s",str) != EOF ){
        int sum=0;

        for(int i=0; str[i] != '\0'; i++){
            if (str[i] > 96){
                sum += (str[i] - 96);
            }
            else{
                sum += (str[i] - 38);
            }
        }

        if (num[sum]){
            printf("It is not a prime word.\n");
        }
        else{
            printf("It is a prime word.\n");
        }
    }

    return 0;
}

void sieve (void){

    for(int i=4; i<=N; i+=2) num[i]=1;

    double lim = sqrt(N)+1;

    for (int i=3; i <= lim; i+=2){
        if (!num[i]){
            for(int k = i*i; k <= N; k += 2*i){
                num[k]=1;
            }
        }
    }

    return;
}
