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
#define MAX                 1000006
#define LIM                 1006
#define SIZE                15630

int num[SIZE];
vector<int>prime;
vector< pair<ll, int> >infoPrime;

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

void divisor(ll n){
    infoPrime.clear();

    for(int i=0, freq=0, root=sqrt(n); i<prime.size() && prime[i]<=root; i++){
        if (!(n%prime[i])){
            freq = 0;
            while (!(n%prime[i]))   n/=prime[i],  freq++;
            infoPrime.pb(mp(prime[i],freq));
            root = sqrt(n);
        }
    }

    if(n>1) infoPrime.pb(mp(n,1));

    return;
}

int gen(int idx, ll num, ll lo, ll hi){
    if (idx == infoPrime.size()){
//        printf("Num = %lld\n", num);
        if (num>=lo && num<=hi)   return 1;
        return 0;
    }

    int ans=0;

    for(int i=0; i<=infoPrime[idx].ss; i++){
        ans += gen(idx+1, num, lo, hi);
        num *= infoPrime[idx].ff;
    }

    return ans;
}

int main(){
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    sieve();

    int t=0;
    ll a=0, b=0;
    sf1(t);

    FOR(tc,1,t){
        scanf("%lld %lld", &a, &b);

        divisor(a);

        casep(tc);
        printf(" %lld\n", gen(0, 1, b, a/b)/2);
    }


//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);

    return 0;
}
