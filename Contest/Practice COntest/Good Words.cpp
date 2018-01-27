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

int main(){
//    sieve();
    int t = 0;

    cin >> t;

    while (t--){
        string a, b;
        int lim = 0;
        bool flag = 0;

        cin >> a >> b;
        lim = a.size()-4;

        for (int i = 0; i <= lim; i++){
            if (a[i]==b[0] and a[i+1]==b[1] and a[i+2]==b[2] and a[i+3]==b[3]){
                flag = 1;
                break;
            }
        }

        if (flag){
            cout << "good\n";
        }
        else{
            lim = a.size()-3;

            for (int i = 0; i <= lim; i++){
                if (a[i]==b[0] and a[i+1]==b[1] and a[i+2]==b[2]){
                    flag = 1;
                    break;
                }
                else if (a[i]==b[0] and a[i+1]==b[2] and a[i+2]==b[3]){
                    flag = 1;
                    break;
                }
                else if (a[i]==b[0] and a[i+1]==b[1] and a[i+2]==b[3]){
                    flag = 1;
                    break;
                }
                else if (a[i+1]==b[1] and a[i+2]==b[2] and a[i+2]==b[3]){
                    flag = 1;
                    break;
                }
            }

            if (flag){
                cout << "almost good\n";
            }
            else{
                cout << "none\n";
            }
        }
    }
    return 0;
}
