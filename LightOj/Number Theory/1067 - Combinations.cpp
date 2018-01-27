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
#define casep(z)            printf("Case %lld:", z);
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
#define MOD                 1000003
#define MAX                 1000001

ll fact[MAX];

void factorial()
{
    fact[0]=fact[1]=1;
    for(ll i=2; i<MAX; i++)        fact[i] = (i*fact[i-1])%MOD;
    return;
}

ll bigmod(ll base, ll power)
{
    ll res = 1;

    while(power)
    {
        if(power&1) res = (res*base)%MOD;
        base = (base*base)%MOD;
        power >>= 1;
    }

    return res;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    factorial();

    ll t=0, n=0, r=0, ans=0;
    scanf("%lld", &t);

    FORL(tc,1,t)
    {
        scanf("%lld %lld", &n, &r);

        if(r==n || r==0)
            ans=1;
        else
        {
            ans = (fact[n-r]*fact[r])%MOD;
            ans = (fact[n]*bigmod(ans,MOD-2))%MOD;
        }
        printf("Case %lld: %lld\n",tc, ans);
    }

    return 0;
}


