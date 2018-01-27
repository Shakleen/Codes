#include <bits/stdc++.h>

using namespace std;

//*******************************************************************************
//*******************************MACROS******************************************
//*******************************************************************************

#define N                   100000000
#define M                   5761455
#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define scan2(a,b)          scanf("%d %d", &a, &b)
#define pii                 pair <int, int>
#define FOR(a,b,c,d)        for(int a = b; a <= c; a+=d)

//*******************************************************************************
//*****************************FUNCTIONS*****************************************
//*******************************************************************************

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void fastscan(int &number)
{
    bool negative = false;
    register int c;

    number = 0;

    c = getchar();
    if (c=='-')
    {
        negative = true;
        c = getchar();
    }

    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    if (negative)
        number *= -1;
}

//bool num[N];
//int prime[M];
//
//int binarysearch(int lo, int hi, int x, int *arr){
//    int result = -1;
//
//    while (lo <= hi){
//        int mid = lo + (hi-lo)/2;
//
//        if (arr[mid] == x){
//            result = mid;
//        }
//        else if (arr[mid] < x){
//            lo = mid+1;
//        }
//        else{
//            hi = mid-1;
//        }
//    }
//
//    return result;
//}
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
    FAST();

    int t = 0;

    cin >> t;

    while (t--){
        int n = 0, m = 0, f = 0;
        char str[50][50],c;
        memset(str,0,sizeof(str));

        cin >> n >> m;

        FOR(i,0,n-1,1){
            FOR(j,0,m-1,1){
                cin >> str[i][j];
            }
        }

        FOR(i,0,n-1,1){
            FOR(j,0,m-1,1){
                if (str[i][j]=='p'){
                    int s = i+1, s1 = i+2, r = j+1, r1 = j+2,
                        l = i-1, l1 = i-2, u = j-1, u1 = j-2;

                    if (r < m && r1 < m && str[i][r]=='i' && str[i][r1]=='e'){
                        f = 1;
                        break;
                    }
                    if (s < n && s1 < n && str[s][j]=='i' && str[s1][j]=='e'){
                        f = 1;
                        break;
                    }
                    if (s < n && s1 < n && r < m && r1 < m && str[s][r]=='i' && str[s1][r1]=='e'){
                        f = 1;
                        break;
                    }
                    if (l >= 0 && l1 >= 0 && str[l][j]=='i' && str[l1][j]=='e'){
                        f = 1;
                        break;
                    }
                    if (i >= 0 && u1 >= 0 && str[i][u]=='i' && str[i][u1]=='e'){
                        f = 1;
                        break;
                    }
                    if (l >= 0 && l1 >= 0 && i >= 0 && u1 >= 0 && str[l][u]=='i' && str[l1][u1]=='e'){
                        f = 1;
                        break;
                    }
                    if (s < n && s1 < n && r < m && r1 < m && str[s][r]=='i' && str[s1][r1]=='e'){
                        f = 1;
                        break;
                    }
                    if (u >= 0 && u >= 0 && str[u][j]=='i' && str[u1][j]=='e'){
                        f = 1;
                        break;
                    }

                }
            }

            if (f == 1){
                break;
            }
        }

        if (f){
            cout << "Cutie Pie!";
        }
        else{
            cout << "Sorry Man";
        }

        if (t){
            cout << "\n";
        }
    }
    return 0;
}
