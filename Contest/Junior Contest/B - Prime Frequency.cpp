#include <bits/stdc++.h>

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)
#define N 2100

bool num[N];

void sieve (void);

int main(){
    sieve();

    int t=0;

    scanf("%d", &t);

    for(int k=1; k<=t; k++){
        char  str[2001]={}, ans[500];
        int ascii[75]={}, j=0;

        scanf("%s", str);

        for(int i=0; str[i] != '\0'; i++){
            int in = str[i] - 48;
            ascii[in]++;
        }

        for (int i=0; i<75; i++){
            if (ascii[i]){
                if(!num[ascii[i]]){
                    ans[j++]=i+48;
                }
            }
        }
        ans[j]='\0';
        if (!j) printf("Case %d: empty\n",k);
        else    printf("Case %d: %s\n",k,ans);
    }

    return 0;
}

void sieve (void){
    num[0]=num[1]=1;

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
