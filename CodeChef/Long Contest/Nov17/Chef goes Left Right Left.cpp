#include <bits/stdc++.h>

using namespace std;

//*******************************************************************************
//*******************************MACROS******************************************
//*******************************************************************************

#define MAX                 100005
#define eps                 1e-6
#define ll                  long long
#define llu                 long long unsigned
#define ld                  long double
#define REP(i,n)            for(int i = 0; i < n; i++)
#define FLR(i,n)            for(ll i = 0; i < n; i++)
#define ROF(i,n)            for(int i = n-1; i >= 0; i--)
#define FOR(i,a,b)          for(int i = a; i <= b; i++)
#define repl(i,a,b)         for(ll i = a; i <= b; i++)
#define casep(z)            cout << "Case " << z << ": ";
#define sz(a)               a.size()
#define all(x)              x.begin(),x.end()
#define SORT(a,n)           sort(a,a+n)
#define RSORT(a,n)          sort(a,a+n,greater<ll>())
#define VSORT(v)            sort(all(v))
#define VRSORT(v)           sort(all(v),greater<ll>())
#define pii                 pair <int, int>
#define pll                 pair <ll, ll>
#define pb                  push_back
#define pf                  push_front
#define pob                 pop_back()
#define pof                 pop_front()
#define ff                  first
#define ss                  second
#define mp                  make_pair
#define ms(x,n)             memset((x),n,sizeof(x))
#define fin                 freopen("in.txt", "r", stdin)
#define fout                freopen("out.txt", "w", stdout)
#define IT(it,x)            for(it=x.begin(); it != x.end(); it++)

int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};

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

ll arr[1000005];

int main(){
//    sieve();
//    FAST();

    ll t = 0, n = 0, r = 0, hi = -1, lo = -1;
    bool mis = false;

    cin >> t;

    while (t--)
    {
        n = r = 0;
        hi = lo = -1;
        mis = false;

        cin >> n >> r;

        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        if (arr[n-1] != r || lo>hi)
        {
            mis = true;
        }

        n--;

        for(ll i = 0; i < n; i++)
        {
            if (arr[i]>r && (arr[i]<hi || hi == -1))
            {
                hi = arr[i];
            }
            else if (arr[i]<r && (arr[i]>lo || lo == -1))
            {
                lo = arr[i];
            }
            else
            {
                mis = true;
                break;
            }
        }

        if (mis)
        {
            cout << "NO" << '\n';
        }
        else
        {
            cout << "YES" << '\n';
        }
    }

    return 0;
}


