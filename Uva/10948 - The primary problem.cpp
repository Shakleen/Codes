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
#define setC(x,n)           (x|=(1<<n))
#define MAX                 1000000
#define LIM                 1000
#define SIZE                15626

int num[SIZE];
vector<int>prime;

void sieve(){
    unsigned i,j,k;
    for(i=3; i<=LIM; i+=2)
        if(!chkC(num[i>>6],((i>>1)&31)))
            for(j=i*i,k=i<<1; j<MAX; j+=k)
                setC(num[j>>6],((j>>1)&31));
    prime.pb(2);
    for(i=3; i<MAX; i+=2)
        if(!chkC(num[i>>6],((i>>1)&31)))
            prime.pb(i);
    return;
}

void FAST()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    sieve();

    int n,a,b,lim,no1,no2,dif;

    while(cin>>n){
        if(!n)      break;
        a = b = -1, lim = (n+1)/2,  dif=no1=no2=0;
        for(int i=0; i<prime.size() && prime[i]<=lim; i++){
            no1 = prime[i],     no2 = n-prime[i];
            if((!chkC(num[no2>>6],((no2>>1)&31)) && no2%2) || (no2==2)){
                if(abs(no1-no2)>=dif)
                    dif = abs(no1-no2), a = no1,    b = no2;
            }
        }
        printf("%d:\n",n);
        if(a==-1 && b==-1){
            printf("NO WAY!\n");
        }
        else{
            if(a>b) swap(a,b);
            printf("%d+%d\n",a,b);
        }
    }


//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);
    return 0;
}


