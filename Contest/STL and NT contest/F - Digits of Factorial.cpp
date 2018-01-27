#include <bits/stdc++.h>

using namespace std;

#define N                   100000000
#define M                   5761455
#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)
#define pii                 pair <int, int>

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int n = 0, b = 0;

        scanf("%d %d", &n, &b);

        double x = log(b), y = 1;

        if ( !n ){
            printf("Case %d: %d\n", cs, 1);
            continue;
        }

        for (int i = 1; i <= n; i++){
            y += log(i);
        }

        y /= x;

        printf("Case %d: %d\n", cs, (int)y);
    }

    return 0;
}
