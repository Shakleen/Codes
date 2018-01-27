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
#define INF                 1000000000000000000
#define chkC(x,n)           (x&(1<<n))
#define setC(x,n)           (x|=(1<<n))
#define MAX                 1000
#define LIM                 33
#define SIZE                17
#define PRM                 168

int num[SIZE], factorCount[PRM];
vector<int>prime;
vector< pii > primeFactor[1001];

void sieve(){
    unsigned i,j,k;
    for(i=3; i<LIM; i+=2)
        if(!chkC(num[i>>6],((i>>1)&31)))
            for(j=i*i,k=i<<1; j<MAX; j+=k)
                setC(num[j>>6],((j>>1)&31));
    prime.pb(2);
    for(i=3; i<MAX; i+=2)
        if(!chkC(num[i>>6],((i>>1)&31)))
            prime.pb(i);
    return;
}

void preCal(){
    sieve();
    unsigned i,j,k,freq;
    for(i=2; i<=MAX; i++){
        k = i;
        for(j=0; prime[j]<=k && j<prime.size(); j++){
            if(!(k%prime[j])){
                freq = 0;
                while(!(k%prime[j]))    freq++,     k/=prime[j];
                primeFactor[i].pb(mp(j,freq));
            }
            if(k==1)    break;
        }
    }
    return;
}

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    FAST();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    preCal();

    int t=0, n=0, cnt=0, temp=0;
    llu ans = 0;
    string fact;

    cin>>t;

    FOR(tc,1,t){
        fact.clear(),   n=cnt=0,    ms(factorCount, 0),     ans = 1;
        cin>>fact;

        REP(i,fact.size())
            if(fact[i]>='0' && fact[i]<='9')    n = n*10+(fact[i]-'0');
            else if(fact[i]=='!')               cnt++;

        temp = n;
        while(n>0){
            for(int i=0; i<primeFactor[temp].size(); i++)
                factorCount[ primeFactor[temp][i].ff ] += primeFactor[temp][i].ss;
            if(n>cnt)       temp = n-cnt;
            else if(n==cnt) temp = cnt;
            else            temp = n;
            n -= cnt;
        }

        REP(i,PRM){
            if(factorCount[i]){
                ans *= (factorCount[i]+1);
                if(ans>INF){
                    ans = -1;
                    break;
                }
            }
        }

        casep(tc);
        if(ans==-1)     printf(" Infinity\n");
        else            printf(" %lld\n", ans);
    }

//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);

    return 0;
}


