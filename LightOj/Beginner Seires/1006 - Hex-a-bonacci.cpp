#include <bits/stdc++.h>
#define N 10000007

int a, b, c, d, e, f;

int fn( int n , int *ar) {
    if( n == 0 ) return a%N;
    if( n == 1 ) return b%N;
    if( n == 2 ) return c%N;
    if( n == 3 ) return d%N;
    if( n == 4 ) return e%N;
    if( n == 5 ) return f%N;
    if ( ar[n] ){
        return ar[n];
    }
    if( !ar[n] ){
        ar[n] = (fn(n-1,ar)%N + fn(n-2,ar)%N + fn(n-3,ar)%N + fn(n-4,ar)%N + fn(n-5,ar)%N + fn(n-6,ar)%N)%N;
        return( ar[n] );
    }
}
int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        int ar[10001] = {};
        printf("Case %d: %d\n", ++caseno, fn(n,ar));
    }
    return 0;
}
