#include <stdio.h>
#define N 1000001
int prime[N],num[N];
void sieve(int n);
int main(){
    sieve(N);
    int n,i,flag=0;
    while(1){
        scanf("%d", &n);
        if (n==0)   break;
        int i=0,j=0;
        for (i=1; i*i<=n; i++){
            int a=prime[i],b=n-prime[i];
            if (!num[b]){
                printf("%d = %d + %d\n",n,a,b);
                flag=1;
                break;
            }
        }
        if (!flag)
            printf("\'Goldbach's conjecture is wrong\'\n");
    }

    return 0;
}
void sieve(int n){
    num[0]=num[1]=1;
    prime[0]=2;
    int i=3,j=1,k=0;
    for (i=3; i*i<=n; i+=2){
        if (!num[i]){
            prime[j++]=i;
            for (k=i*i; k<=n; k+=2*i){
                num[k]=1;
            }
        }
    }
    for (i=1000; i<=N; i++)
        if (!num[i])
            prime[j++]=i;
}
