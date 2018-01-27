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

#define chkC(x,n)           (x&(1<<n))
#define setC(x,n)           (x|=(x|(1<<n)))
#define MAX                 128
#define LIM                 12
#define pb                  push_back

int num[MAX/32];
vector<int>prime;
vector< pii >factor[100];

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

void cal()
{
    int freq=0, numb=0;

    FOR(no,2,100)
    {
        factor[no-1]=factor[no-2];

        if(!(chkC(num[no>>5],(no&31))) && (no%2 || no==2))
            factor[no-1].pb(mp(no,1));
        else
            for(int i=0,numb=no; i<prime.size() && numb>1; i++)
                if(!(numb%prime[i]))
                {
                    freq=0;

                    while(!(numb%prime[i]))
                        numb/=prime[i],  freq++;

                    factor[no-1][i].ss+=freq;
                }
    }

    return;
}

int main()
{
    sieve();
    cal();

    int t=0,n=0,freq=0;
    scanf("%d", &t);

    FOR(tc,1,t)
    {
        scanf("%d", &n);

        casep(tc);
        printf(" %d =", n);
        REP(i,factor[n-1].size())
            if(!i)  printf(" %d (%d)", factor[n-1][i].ff,factor[n-1][i].ss);
            else    printf(" * %d (%d)", factor[n-1][i].ff,factor[n-1][i].ss);

        printf("\n");
    }

    return 0;
}



