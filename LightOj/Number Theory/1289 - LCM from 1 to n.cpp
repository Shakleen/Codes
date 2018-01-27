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
#define UI                  unsigned

#define chkC(x,n)           (x&(1<<n))
#define setC(x,n)           (x|=(x|(1<<n)))
#define MAX                 100000001
#define LIM                 10001
#define STR                 1562501
#define SZ                  5761455

int num[STR];
UI prime[SZ];
UI store[SZ];

void sieve(){
    UI i,j,k;
    for(i=3; i<LIM; i+=2)
        if(!chkC(num[i>>6],((i>>1)&31)))
            for(j=i*i, k=i<<1; j<MAX; j+=k)
                setC(num[j>>6],((j>>1)&31));
    j=0;
    prime[j++]=2;
    for(i=3; i<MAX; i+=2)
        if(!chkC(num[i>>6],((i>>1)&31)))
            prime[j++]=i;
    return;
}

void preCal(){
    store[0] = 2;

    for(UI i=1; i<SZ; i++)   store[i] = store[i-1] * prime[i];

    return;
}

UI cal(int n){
    UI ans = 1, no = n, i=0;
    for(i=0; prime[i]*prime[i]<=n && i<SZ; i++){
        no=n,   no/=prime[i];
        while(no>=prime[i])     no/=prime[i],   ans *= prime[i];
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
    preCal();

    int t=0, ans=0, n=0, m=1;

    scanf("%d", &t);

    FOR(tc,1,t){
        scanf("%u", &n);

        ans=cal(n);

        m = upper_bound(prime, prime+SZ, n) - prime;
        m--;
        ans *= store[m];

        casep(tc);
        printf(" %u\n", ans);
    }

//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);

    return 0;
}
