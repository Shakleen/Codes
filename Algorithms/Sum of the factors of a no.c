#include <stdio.h>
#include <math.h>
#define N 10000
int prime[N],num[N];
int sum_fact(int n);
void sieve(int n);
int main(){
    int n;
    printf("Please input a number:\n");
    scanf("%d", &n);
    sieve(n);
    printf("The no of factors are %d\n",sum_fact(n));
    return 0;
}
void sieve(int n){
    num[0]=num[1]=1;
    int i,j=0,k=0,val=sqrt(n)+1;
    prime[j++]=2;
    for(i=3; i<=val; i+=2){
        if (!num[i]){
            prime[j++]=i;
            for (k=i*i; k<=n; k+=2*i)
                num[k]=1;
        }
    }
    for (i=val; i<=n; i++)
        if (!num[i])
            prime[j++]=i;
}
int sum_fact(int n){
    int i=0,sum=1,s=1,p=1;
    for(i=0; prime[i]*prime[i]<=n; i++){
        p=1;
        if (!(n%prime[i])){
            s=1;
            while(!(n%prime[i])){
                n/=prime[i];
                p*=prime[i];
            }
            p*=prime[i];
            s=(p-1)/(prime[i]-1);
            sum*=s;
        }
    }
    if (n>1){
        s=n*n;
        sum*=(s-1)/(n-1);
    }
    return sum;
}
