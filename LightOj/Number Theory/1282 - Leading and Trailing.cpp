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
#define MOD                 1000

ll bigmod(ll n, ll k){
    ll res=1;

    while (k){
        if(k&1) res = (res*n)%MOD;
        k >>= 1;
        n = (n*n)%MOD;
    }

    if(res<0)   res = (res+MOD)%MOD;

    return res;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    ll t=0, n=0, k=0, trailing=0, leading=0;
    double val=0.0;

    scanf("%lld", &t);

    FORL(tc,1,t){
        scanf("%lld %lld", &n, &k);

        trailing = bigmod(n,k);

        if(trailing<1000 && n<1000 && k==1){
                leading = trailing;
        }else{
            val = (double)k*(log10((double)n));
            val = val - (ll)val;
            leading = (pow(10,val)*100.0);
        }

        casep(tc);
        printf(" %03lld %03lld\n", leading, trailing);
    }

//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);
    return 0;
}


