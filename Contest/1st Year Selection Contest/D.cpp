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

bool compare (pair<int,pair<int,int> > a, pair<int,pair<int,int> > b){
    if (a.first == b.first){
        if (a.second.first == b.second.first){
            return (a.second.second < b.second.second);
        }

        return (a.second.first < b.second.first);
    }

    return (a.first < b.first);
}

int main(){
//    sieve();
    int n = 0;

    scanf("%d", &n);

    priority_queue < pii > q1,q2,q3;
    int p[n+1], a[n+1], b[n+1];
    bool check[n];
    memset(check, true, sizeof(check));

    for (int i = 0; i < n; i++){
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++){
        scanf("%d", &b[i]);

        if (a[i] != b[i]){
            if (a[i] == 1){
                q1.push(make_pair(p[i]*(-1), i));
            }
            else if (a[i] == 2){
                q2.push(make_pair(p[i]*(-1), i));
            }
            else{
                q3.push(make_pair(p[i]*(-1), i));
            }

            if (b[i] == 1){
                q1.push(make_pair(p[i]*(-1), i));
            }
            else if (b[i] == 2){
                q2.push(make_pair(p[i]*(-1), i));
            }
            else{
                q3.push(make_pair(p[i]*(-1), i));
            }
        }
        else{
            if (a[i] == 1){
                q1.push(make_pair(p[i]*(-1), i));
            }
            else if (a[i] == 2){
                q2.push(make_pair(p[i]*(-1), i));
            }
            else{
                q3.push(make_pair(p[i]*(-1), i));
            }
        }
    }

    int m = 0;

    scanf("%d", &m);

    for (int i = 0; i < m; i++){
        int col = 0, f = 1;
        pii p = make_pair(0, -1);

        scanf("%d", &col);

        if (col == 1){
            while (f && !q1.empty()){
                p = q1.top();
//                printf("1");
                if (check[p.second]){
                    check[p.second] = false;
                    f = 0;
                }
                q1.pop();
            }
        }
        else if (col == 2){
            while (f && !q2.empty()){
                 p = q2.top();
                if (check[p.second]){
                    check[p.second] = false;
                    f = 0;
                }
//                printf("2");
                q2.pop();
            }
        }
        else{
            while (f && !q3.empty()){
                 p = q3.top();
//                printf("3");
                if (check[p.second]){
                    check[p.second] = false;
                    f = 0;
                }
                q3.pop();
            }
        }
//printf("Price = %d Pos = %d\n", p.first, p.second);
//for (int i = 0; i < n; i++) printf("%d ", check[i]);
//printf("\n");
        if (p.second != -1){
            printf("%d ", p.first*(-1));
        }
        else{
            printf("%d ", -1);
        }
    }
    return 0;
}
