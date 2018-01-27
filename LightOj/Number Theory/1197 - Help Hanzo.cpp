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
#define MAX                 65537
#define LIM                 257
#define RNG                 100032

vector<int>prime;
int num[MAX>>6], segment[RNG>>6];

void sieve()
{
    unsigned i,j,k;
    for(i=3; i*i<LIM; i += 2)
        if(!chkC(num[i>>6],((i>>1)&31)))
            for(j=i*i, k=i<<1; j<MAX; j+=k)
                setC(num[j>>6],((j>>1)&31));
    for(i=3; i<MAX; i+=2)
        if(!chkC(num[i>>6],((i>>1)&31)))
            prime.pb(i);
    return;
}

int segmentSieve(int a, int b)
{
    unsigned i,j,k,n, cnt = (a<=2 && 2<=b) ? 1 : 0;

    if(b<2)         return 0;   //2 is the first prime
    if(b==2)        return 1;
    if(a<3)         a=3;
    if(a%2==0)      a++;        //Code works for odd, so we'll make even odd

    ms(segment,0);              //Initialize everytime

    for(i=0; prime[i]*prime[i]<=b && i<prime.size(); i++)
    {
        j = prime[i]*((a+prime[i]-1)/prime[i]);//Finding the first multiple of prime[i] within [a,b]

        if(j%2==0)  j += prime[i];             //If first multiple is even, make it odd

        for(k=prime[i]<<1; j<=b; j+=k)
            if(j!=prime[i])
                n=j-a, setC(segment[n>>6],((n>>1)&31));
    }

    for(i=0; i<=b-a; i+=2)
        if(!chkC(segment[i>>6],((i>>1)&31)))
            cnt++;

    return cnt;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    sieve();

    int t=0, a=0, b=0;

    scanf("%d", &t);

    FOR(tc,1,t)
    {
        scanf("%d %d", &a, &b);

        casep(tc);
        printf(" %d\n", segmentSieve(a,b));
    }


//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);
    return 0;
}


