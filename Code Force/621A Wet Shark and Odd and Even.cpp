#include <bits/stdc++.h>

using namespace std;

#define     ll                  long long
#define     min3(a,b,c)         min(a,min(b,c))
#define     max3(a,b,c)         max(a,max(b,c))
#define     min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define     max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define     sqr(a)              ((a)*(a))
#define     scan2(a,b)          scanf("%d %d", &a, &b)

int main(){
    ll n=0;

    scanf("%I64d", &n);

    ll o[n]={}, sum=0, num=0;
    int k=0;

    while(n--){
        scanf("%I64d", &num);

        if (!(num%2)){
            sum += num;
        }
        else{
            o[k] = num;
//            printf("sum=%I64d o[%d]=%d\n",sum,k,o[k]);
            k++;
        }
    }

    sort( o,o+k,greater<int>() );

    int limit = 0;

    if (k%2)    limit = k-1;
    else        limit = k;

    for(int i=0; i<limit; i++){
        sum += o[i];
    }

    printf("%I64d", sum);

    return 0;
}
