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
#define chkC(x,n)           (x&(1<<n))
#define setC(x,n)           (x|=(x|(1<<n)))
#define MAX                 1000000
#define LIM                 1000

int num[MAX/32];
vector<int>prime;

void sieve()
{
    for(int i=3; i<=LIM; i+=2)
        if(!chkC(num[i>>5],(i&31)))
            for(int j=i*i, k=i<<1; j<MAX; j+=k)
                num[j>>5]=setC(num[j>>5],(j&31));
    prime.push_back(2);
    for(int i=3; i<MAX; i+=2)
        if(!chkC(num[i>>5],(i&31)))
            prime.push_back(i);
}

ll cal(ll n)
{
    ll freq, s=1;

    for(int i=0; i<prime.size() && prime[i]*prime[i]<=n; i++)
    {
        if(!(n%prime[i]))
        {
            freq=1;

            while(!(n%prime[i]))
                n/=prime[i],    freq++;

            s*=freq;
        }
    }
    if(n>1)
        s*=2;

    return s;
}
int main()
{
//    FAST();
    sieve();
    ll t=0,n=0;

    scanf("%lld", &t);

    FOR(tc,1,t)
    {
        scanf("%lld", &n);
        printf("Case %d: %lld\n", tc, cal(n)-1);
    }
    return 0;
}



