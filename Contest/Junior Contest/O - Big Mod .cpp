#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)

int bigmod (int x, int n, int m);

int main(){
    int b,p,m;
    b=p=m=0;

    while(scanf("%d %d %d", &b, &p, &m) != EOF){
        int MOD=bigmod(b,p,m);
        printf("%d\n",MOD);
    }

    return 0;
}

int bigmod (int x, int n, int m){
    if (n == 0){
        return 1;
    }
    else if ( !(n%2) ){
        int y = bigmod(x,n/2,m);
        return ((y*y)%m);
    }
    else{
        return ((x%m)* bigmod(x,n-1,m))%m;
    }
}
