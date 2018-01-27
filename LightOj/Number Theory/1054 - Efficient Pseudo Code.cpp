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
#define repl(i,a,b)         for(ll i = a; i <= b; i++)
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
#define MOD                 1000000007
#define chkC(x,n)           (x&(1<<n))
#define setC(x,n)           (x|=(x|(1<<n)))
#define MAX                 65536
#define LIM                 256

int num[2048];
vector<int>prime;

void sieve()
{
    for(int i=3; i<+LIM; i+=2)
        if(!(chkC(num[i>>5],(i&31))))
            for(int j=i*i, k=i<<1; j<MAX; j+=k)
                num[j>>5]=setC(num[j>>5],(j&31));
    prime.pb(2);
    for(int i=3; i<MAX; i+=2)
        if(!(chkC(num[i>>5],(i&31))))
            prime.pb(i);
}

ll bigmod(ll base, ll power, ll mod)
{
    ll result=1;

    while(power)
    {
        if(power%2)
            result=(result*base)%mod;

        power/=2;
        base=(base*base)%mod;
    }

//    if(result<0)    result=(result+mod)%mod;

    return result;
}

int main()
{
    sieve();

    ll t=0,n=0,m=0,freq=0,p=0,s=0,ans=0;

    scanf("%lld", &t);

    FOR(tc,1,t)
    {
        scanf("%lld %lld", &n, &m);
        ans=1;

        for(int i=0; i<prime.size() && prime[i]*prime[i]<=n; i++)
        {
            if(!(n%prime[i]))
            {
                freq=0;

                while(!(n%prime[i]))
                    n/=prime[i],  freq++;

                ans = (ans * (bigmod(prime[i],freq*m+1LL,MOD)-1LL+MOD))%MOD;
                ans = (ans * (bigmod(prime[i]-1LL,MOD-2,MOD)))%MOD;
            }
        }

        if(n>1)
        {
            ans = (ans * (bigmod(n,m+1LL,MOD)-1+MOD))%MOD;
            ans = (ans * bigmod(n-1,MOD-2,MOD))%MOD;
        }

        casep(tc)
        printf(" %lld\n", ans);
    }

    return 0;
}


