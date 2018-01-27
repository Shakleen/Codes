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

#define chkC(x,n)           (x&(1<<n))
#define setC(x,n)           (x|=(x|(1<<n)))
#define MAX                 1000001
#define LIM                 1001

vector<int>prime;
vector<int>cFact;
int num[MAX/64];

void sieve()
{
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

ll gcd(ll a, ll b)
{
    if (!b) return a;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b)
{
    ll g=gcd(a,b);

    return ((a/g)*b);
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    sieve();

    int t=0, i=0;
    ll a,b,L,l,c;

    scanf("%d", &t);

    FOR(tc,1,t)
    {
        a=b=l=L=c=0;
        cFact.clear();

        scanf("%lld %lld %lld", &a, &b, &L);

        l = lcm(a,b);

        casep(tc);

        if(L%l)
        {
            printf(" impossible\n");
            continue;
        }

        c = L/l;

        for(i=0; prime[i]*prime[i]<=c && i<prime.size(); i++)
        {
            if(!(c%prime[i]))
            {
                cFact.pb(prime[i]);
                while(!(c%prime[i]))
                    c/=prime[i];
            }
        }
        if(c>1)      cFact.pb(c), c=1;
//for(int i=0; i<cFact.size(); i++)   printf("Fact %d = %lld\n",i,cFact[i]);
        for(i=0; i<cFact.size(); i++)
            while(!(L%cFact[i]))
                L /= cFact[i],  c *= cFact[i];

        printf(" %lld\n", c);
    }

//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);

    return 0;
}


