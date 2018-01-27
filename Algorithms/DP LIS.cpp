#include <bits/stdc++.h>

using namespace std;

//*******************************************************************************
//*******************************MACROS******************************************
//*******************************************************************************

#define N                   100000000
#define MOD                 1e9+7
#define ll                  long long
#define ull                 unsigned long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define pii                 pair <int, int>
#define FOR(i,n)            for(ll i = 0; i <= n; i++)
#define REP(i,n)            for(ll i = 0; i < n; i++)
#define ROF(i,n)            for(ll i = n; i >= 0; i--)
#define FORSTL(i,n)         for(__typeof(n.begin())i = n.begin(); i!=n.end() ;i++)
#define all(v)              v.begin(),v.end()
#define SORT(v)             sort(all(v))
#define REV(v)              reverse(v.begin(),v.end())
#define asort(m,n)          sort(a+m,a+n)
#define ms(ar,m)            memset(ar,m,sizeof ar)
#define ff                  first
#define ss                  second
#define pb                  push_back
#define mp                  make_pair

//*******************************************************************************
//*****************************FUNCTIONS*****************************************
//*******************************************************************************

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

//bool num[N];
//vector<int>prime;
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
//    prime.pb(2);
//
//    for (int i = 3; i <= N; i += 2){
//        if (!num[i]){
//            prime.pb(i);
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
//
//ll bigmod (ll base, ll pow, ll mod){
//    if (pow == 0){
//        return 1;
//    }
//    else if (pow%2){
//        return ((base%mod)*bigmod(base,pow-1,mod))%mod;
//    }
//    else{
//        ll y = bigmod(base,pow/2,mod);
//
//        return (y*y)%mod;
//    }
//}
//void numToString(int num, char *no) {
//    int i = 0;
//
//    while (num>0) {
//        no[i++] = ((num%10) + '0');
//        num /= 10;
//        cout << no[i-1] << endl;
//    }
//
//    no[i] = '\0';
//
//    reverse(no, no+i);
//}

int ans[100][100], len;

int subset(int idx, int prev)
{
    if (idx == len)
    {
        return 0;
    }

    if (ans[idx][prev] != -1)
    {
        return ans[idx][prev];
    }

    ans[idx][prev] = subset(idx+1,prev);

    if (a[idx] > prev)
    {
        ans[idx][prev] = 1 + subset(idx+1, ans[idx][prev]);
    }

    return ans[idx][prev];
}

int main(){
//    sieve();
    //FAST();

    cin >>

    return 0;
}


