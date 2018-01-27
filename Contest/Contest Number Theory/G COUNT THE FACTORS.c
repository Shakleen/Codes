#include <stdio.h>
#include <math.h>
#define N 100001
void sieve(int n);
int count_fact(int n);
int prime[N],num[N];
int main(){
    sieve(N);
    int n;
    while(1){
        scanf("%d",&n);
        if (!n) break;
        int cnt=count_fact(n);
        printf("%d : %d\n",n,cnt);
    }
    return 0;
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
int count_fact(int n){
    int i=0,count=0;
    for (i=0; prime[i]*prime[i]<=n; i++){
        if (!(n%prime[i])){
            count++;
            while(!(n%prime[i]))
                n/=prime[i];
        }
    }
    if (n>1)
        count++;
    return count;
}
