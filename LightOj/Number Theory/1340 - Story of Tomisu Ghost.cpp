#include <bits/stdc++.h>

using namespace std;

//*******************************************************************************
//*******************************Template****************************************
//*******************************************************************************

#define eps                 1e-6
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

#define chkC(x,n)           (x&(1<<n))
#define setC(x,n)           (x|=(x|(1<<n)))
#define MAX                 100001
#define LIM                 318
#define SIZE                1564
#define MOD                 10000019

int num[SIZE];
vector<int>prime;

void sieve(){
    unsigned i,j,k;
    for(i=3; i<LIM; i+=2)
        if(!chkC(num[i>>6],((i>>1)&31)))
            for(j=i*i, k=i<<1; j<MAX; j+=k)
                setC(num[j>>6],((j>>1)&31));
    prime.pb(2);
    for(i=3; i<MAX; i+=2)
        if(!chkC(num[i>>6],((i>>1)&31)))
            prime.pb(i);
    return;
}

ll bigmod(ll base, ll power){
    ll res=1;

    while(power){
        if(power&1)     res = (res*base) % MOD;
        power >>= 1;
        base = (base*base) % MOD;
    }

    return res;
}

ll Count(ll n, ll p){
    ll x = 0;

    while(n){
        n /= p;
        x += n;
    }

    return x;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    sieve();

    int T=0;
    ll n=0, t=0, cnt=0, q=0, res = 1;

    sf1(T);

    FOR(tc,1,T){
        scanf("%lld %lld", &n, &t);

        res = 1;

        REP(i,prime.size()){
            cnt = (Count(n, prime[i])/t);

            if(!cnt)    break;

            res = (res*bigmod(prime[i],cnt)) % MOD;
        }

        casep(tc);
        if (res == 1)       printf(" -1\n");
        else                printf(" %lld\n", res);
    }

//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);

    return 0;
}


