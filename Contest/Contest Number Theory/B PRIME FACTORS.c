#include <stdio.h>
#include <math.h>
#define N 10000
void sieve(int n);
void prime_fact(int n);
int prime[200],num[N];
int main(){
    sieve(N);
    int n=0;
    while(1){
        scanf("%d", &n);
        if (!n) break;
        if(n<0){
            printf("%d = -1 x",n);
            n*=-1;
        }
        else
            printf("%d =",n);
        prime_fact(n);
        printf("\n");
    }
}
void sieve(int n){
    prime[0]=2;
    num[0]=num[1]=1;
    int i,j=1,k,val=sqrt(n)+1;
    for (i=3; i<=val; i+=2){
        if (!(num[i])){
            prime[j++]=i;
            for (k=i*i; k<=n; k+=2*i)
                num[k]=1;
        }
    }
    for (i=val+1; i<=n; i++){
        if (!num[i])
            prime[j++]=i;
    }
}
void prime_fact(int n){
    long long int i=0;
    for (i=0; prime[i]*prime[i]<=n; i++){
        if (!(n%prime[i])){
            while(!(n%prime[i])){
                n/=prime[i];
                printf(" %d",prime[i]);
                if (!(n%prime[i]))
                    printf(" x");
            }
        if(n>1)
            printf(" x");
        }
    }
    if (n>1)
        printf(" %d",n);
}
