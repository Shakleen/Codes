#include <bits/stdc++.h>

using namespace std;

//*******************************************************************************
//*******************************Template****************************************
//*******************************************************************************

#define eps                 1e-10
#define ll                  long long
#define llu                 long long unsigned
#define ld                  long double
#define REP(i,n)            for(int i = 0; i < n; i++)
#define FLR(i,n)            for(ll i = 0; i < n; i++)
#define ROF(i,n)            for(int i = n-1; i >= 0; i--)
#define FOR(i,a,b)          for(int i = a; i <= b; i++)
#define FORL(i,a,b)         for(ll i = a; i <= b; i++)
#define casep(z)            printf("Case %d:", z);
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
#define sf1(x)              scanf("%d", &x)
#define sfl1(x)             scanf("%lld", &x)
//
//#define chkC(x,n)           (x&(1<<n))
//#define setC(x,n)           (x|=(x|(1<<n)))
//#define MAX                 1000001
//#define LIM                 1001
//#define SIZE                15626
//
//int num[SIZE];
//vector<int>prime;
//
//void sieve(){
//    unsigned i,j,k;
//    for(i=3; i<LIM; i+=2)
//        if (!chkC(num[i>>6],((i>>1)&31)))
//            for(j=i*i,k=i<<1; j<MAX; j+=k)
//                setC(num[j>>6],((j>>1)&31));
//    prime.pb(2);
//    for(i=3; i<MAX; i+=2)
//        if (!chkC(num[i>>6],((i>>1)&31)))
//            prime.pb(i);
//    return;
//}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

//    sieve();

    int t=0;
    ll n=0, cnt=0, lim=0, temp=0, i=0;
    double sr = 0.0, dif = 0.0;

    sf1(t);

    FOR(tc,1,t){
        sfl1(n);

        cnt = sqrt(n);
        cnt += (sqrt(n/2));

        casep(tc);
        printf(" %lld\n", n-cnt);
    }



//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);
    return 0;
}


