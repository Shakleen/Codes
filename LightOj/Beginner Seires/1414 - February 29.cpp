#include <bits/stdc++.h>

using namespace std;

//*******************************************************************************
//*******************************MACROS******************************************
//*******************************************************************************

#define N                   100000000
#define M                   5761455
#define ll                  long long
#define ull                 unsigned long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define pii                 pair <int, int>
#define FOR(a,b,c,d)        for(ll a = b; a <= c; a+=d)
#define rFOR(a,b,c,d)       for(ll a = b; a >= c; a-=d)
#define TEST(t)             for(ll cs = 1; cs <= t; cs++)
#define all(v)              v.begin(),v.end()
#define SORT(v)             sort(all(v))
#define REV(v)              reverse(v.begin(),v.end()
#define setm(ar,m)          memset(ar,m,sizeof ar)
#define FF                  first
#define SS                  second
#define PB                  push_back
#define MP                  make_pair
#define nline               '\n'

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

void input(int n, int *arr){
    FOR(i,1,n,1){
        cin >> arr[i];
    }
}

int main(){
//    sieve();
//    FAST();

    string monthStart, monthEnd;
    int dateStart, dateEnd, yearStart, yearEnd, t, cnt;
    char c = 0;
    bool isLeapStart = false, isLeapEnd = false;
    map <string, int> mymap;

    {
    mymap["January"] = 1;
    mymap["February"] = 2;
    mymap["March"] = 3;
    mymap["April"] = 4;
    mymap["May"] = 5;
    mymap["June"] = 6;
    mymap["July"] = 7;
    mymap["August"] = 8;
    mymap["September"] = 9;
    mymap["October"] = 10;
    mymap["November"] = 11;
    mymap["December"] = 12;
    }

    cin >> t;

    TEST(t){
        dateStart = dateEnd = yearStart = yearEnd = cnt = isLeapStart = isLeapEnd = 0;

        cin >> monthStart >> dateStart >> c >> yearStart;
        cin >> monthEnd >> dateEnd >> c >> yearEnd;

        isLeapStart = !(yearStart%4) || ((yearStart%100 != 0) && !(isLeapStart%400));
        isLeapEnd = !(yearEnd%4) || ((yearEnd%100 != 0) && !(isLeapEnd%400));
//        cout << monthStart << " " << dateStart << " " << c << " " << yearStart << nline;
//        cout << monthEnd << " " << dateEnd << " " << c << " " << yearEnd << nline;

        if (yearStart == yearEnd){
            if (isLeapStart){

            }
        }
    }
    return 0;
}
