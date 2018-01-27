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

//bool num[N];
//int prime[M];
//
//void sieve(){
//    for (int i = 4; i <= N; i += 2){
//        num [i] = 1;
//    }
//
//    for (int i = 3; i*i <= N; i += 2){
//        if ( !num[i] ){
//            for (int k = i*i; k <= N; k += 2*i){
//                num[k] = 1;
//            }
//        }
//    }
//
//    prime[0] = 2;
//    int j = 1;
//
//    for (int i = 3; i <= N; i += 2){
//        if (!num[i]){
//            prime[j++] = i;
//        }
//    }
//    return;
//}
//
//int factors (int n){
//    if (n < N){
//        if ( !num[n] ){
//            return 2;
//        }
//    }
//
//    int cnt = 1, s = 0, val = sqrt(n)+1;
//
//    for (int i = 0; prime[i] < val; i++){
//        if ( !(n%prime[i]) ){
//            s = 1;
//
//            while ( !(n%prime[i]) ){
//                n /= prime[i];
//                s++;
//            }
//
//            cnt *= s;
//        }
//    }
//
//    if ( n > 1 ){
//        cnt *= 2;
//    }
//
//    return cnt;
//}
//
//ll factor_sum (ll n){
//    ll sum = 1, p = 0, val = sqrt(n)+1, s = 0;
//
//    for (int i = 0; prime[i] < val; i++){
//        if ( !(n%prime[i]) ){
//            p = prime[i];
//
//            while ( !(n%prime[i]) ){
//                p *= prime[i];
//                n /= prime[i];
//            }
//
//            s = (p-1)/(prime[i]-1);
//            sum *= s;
//        }
//    }
//
//    if (n > 1){
//        sum *= (n*n-1)/(n-1);
//    }
//
//    return sum;
//}

//bool compare (pair<int,pair<int,int> > a, pair<int,pair<int,int> > b){
//    if (a.first == b.first){
//        if (a.second.first == b.second.first){
//            return (a.second.second < b.second.second);
//        }
//
//        return (a.second.first < b.second.first);
//    }
//
//    return (a.first < b.first);
//}

int main(){
//    sieve();

    int n = 0, cnt = 0;

    scanf("%d", &n);

    while (n--){
        int x1,x2,x3,y1,y2,y3;

        scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

        int a = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2),
            b = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3),
            c = (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3);

        if (a == b+c || b == a+c || c == a+b){
            cnt++;
        }
    }

    printf("%d", cnt);
    return 0;
}
