#include <bits/stdc++.h>

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)

int main(){
    ll a=0, b=0;

    int i=1;

    while (1){
        scanf("%lld %lld", &a, &b);

        if (a==0 && b==0){
            break;
        }

        ll in = (a*(a-1)*b*(b-1))/4;

        printf("Case %d: %lld\n",i,in);

        i++;
    }
    return 0;
}
