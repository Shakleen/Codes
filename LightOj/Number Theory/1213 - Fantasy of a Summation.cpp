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

ll bigMod (ll base, ll power, ll mod)
{
    ll res = 1;
    while(power)
    {
        if(power&1)      res = (res*base)%mod;
        base = (base*base)%mod;
        power >>= 1;
    }
    return res;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    int t=0;
    ll n,k,MOD,ans,A;

    scanf("%d", &t);

    FOR(tc,1,t)
    {
        ans=A=0;

        scanf("%lld %lld %lld", &n, &k, &MOD);

        FOR(i,1,n)
        {
            scanf("%lld", &A);
            ans = (ans+A)%MOD;
        }

        ans = (ans*bigMod(n,k-1,MOD)*k)%MOD;

        casep(tc);
        printf(" %lld\n", ans);
    }


//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);
    return 0;
}


