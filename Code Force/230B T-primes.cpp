#include <bits/stdc++.h>
#define N 1000000
int num[N], prime[1000];
void sieve(int n);
int main(){
    sieve(N);
    int n;
    scanf("%d", &n);
    while(n--){
        long long x;
        scanf("%I64d", &x);
        if (x<4){
            printf("NO\n");
            continue;
        }
        int cnt=2, lim=sqrt(x)+1,f=1;
        for (int i=0; i<1000; i++){
            long long m=prime[i];
            if (m>lim)  break;
            if (!(x%m)){
                f=0;
                cnt++;
                if (m != x/m)   cnt++;
                break;
            }
        }
        if (f){
            long long s=sqrt(x);
            if (s*s == x)   cnt++;
        }
        if (cnt==3) printf("YES\n");
        else        printf("NO\n");
    }
    return 0;
}

void sieve(int n){
    num[0]=num[1]=1;
    int j=1,lim=sqrt(n)+1;
    for (int i=3; i<=lim; i+=2){
        if (!num[i]){
            prime[j++]=i;
            for (int k=i*i; k<=n; k+=2*i){
                num[k]=1;
            }
        }
    }
    int i=lim+1;
    if (!(i%2)) i++;
    for(i; i<=n; i+=2){
        if (!num[i]){
            prime[j++]=i;
            if (j==1000) break;
        }
    }
    prime[0]=2;
    return;
}
