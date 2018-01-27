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

#define MAX                 1000000
#define LIM                 1000
#define SIZE                15625
#define chkC(x,n)           (x&(1<<n))
#define setC(x,n)           (x|=(1<<n))

int num[SIZE];
vector<int>prime;

void sieve(){
    unsigned i,j,k;
    for(i=3; i<=LIM; i+=2)
        if(!chkC(num[i>>6],(i>>1)&31))
            for(j=i*i,k=i<<1; j<MAX; j+=k)
                setC(num[j>>6],((j>>1)&31));
    prime.pb(2);
    for(i=3; i<MAX; i+=2)
        if(!chkC(num[i>>6],((i>>1)&31)))
            prime.pb(i);
    return;
}

//ll bigMod(ll base, ll power){
//    ll res = 1;
//    while(power){
//        if(power&1) res = (res * base) % 10;
//        base = base*base;
//        power >>= 1;
//    }
//    return res;
//}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    sieve();

    ll n=0, ans=0, cnt=0, p=0;

    while(cin>>n){
        if(!n)  break;
        if(n<=2){
            printf("%d\n",n);
        }
        else{
            cnt = 0,    ans = 1;

            if(n>=5){
                p = prime[2],   cnt=1;
                while(p<=n) p*=prime[2],    cnt++;
                cnt--;
            }

            for(int i=0; i<prime.size() && prime[i]<=n; i++){
                if(prime[i]==5)     continue;
                p = prime[i];
                if(prime[i]*prime[i]<=n){
                    while(p<=n)     p*=prime[i];
                    p /= prime[i];
                    while(cnt)      p/=prime[i],    cnt--;
//                    printf("prime = %d p = %lld ", prime[i], p);
                }
                ans = (ans*p)%10;
//                printf("ans = %lld\n", ans);
            }
            printf("%lld\n", ans);
        }
    }

//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);
    return 0;
}


