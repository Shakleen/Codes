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
#define MAX                 5001
#define LIM                 71
#define SIZE                79
#define PRM                 669

int num[SIZE], factors[PRM];
char digit[2000];
vector<int>prime;
vector<int>primeFact[MAX];

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
    int i,j,k,freq,no;
    for(i=2,no=i; i<MAX; i++,no=i){
        primeFact[i] = primeFact[i-1];
        for(j=0; j<prime.size() && prime[j]<=no; j++){
            if(!(no%prime[j])){
                freq=0;
                while(!(no%prime[j]))           freq++,    no/=prime[j];
                if(j<primeFact[i].size())       primeFact[i][j] += freq;
                else                            primeFact[i].pb(freq);
            }
            if(no==1)   break;
        }
//        printf("%d ->", i);
//        for(k=0; k<primeFact[i].size(); k++)    printf(" %d(%d)",prime[k],primeFact[i][k]);
//        printf("\n");
    }
    return;
}

int cal(ll mul, int resSize){
    ll carry = 0, prod = 0;
    for(int i=0; i<resSize; i++){
        prod = (digit[i]-'0')*mul + carry;
        carry = prod/10;
        digit[i] = (prod%10+'0');
    }
    while (carry){
        digit[resSize++] = (carry%10+'0');
        carry /= 10;
    }
    return resSize;
}

ll fastExpo(ll n, ll p){
    ll res = 1;
    while(p){
        if (p&1)    res = n*res;
        n = n*n;
        p >>= 1;
    }
    return res;
}

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){

//    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    preCal();

    int N,M,n,r,lim,m,rng;
    ll temp,p;

    while(cin>>N>>M){
        lim = N+M;
        ms(factors,0);
        ms(digit,0);

        FOR(i,1,lim){
            cin>>n>>r;

            m = n-r, rng = primeFact[n].size();

            REP(j,rng){
                if(j<primeFact[n].size())   (i<=N) ? factors[j]+=primeFact[n][j] : factors[j]-=primeFact[n][j];
                if(j<primeFact[m].size())   (i<=N) ? factors[j]-=primeFact[m][j] : factors[j]+=primeFact[m][j];
                if(j<primeFact[r].size())   (i<=N) ? factors[j]-=primeFact[r][j] : factors[j]+=primeFact[r][j];
            }
        }

//        REP(i,PRM)  if(factors[i])  printf("%d -> %d\n", prime[i], factors[i]);

        digit[0] = '1', r = 1;

        REP(i,PRM){
            if(factors[i]>0){
                while(factors[i]){
                    p = min(factors[i], 64);
                    factors[i] -= p;
                    if(p>1)     temp = fastExpo(prime[i],p);
                    else        temp = prime[i];
//                    printf("Prime=%d power=%d temp=%lld taken=%lld number=",prime[i],factors[i],temp,p);
                    r = cal(temp, r);
//                    for(int i=r-1; i>=0; i--)  printf("%c", digit[i]);
//                    printf("\n");
                    if(r>100){r = -1;   break;}
                }
                if(r==-1)   break;
            }
            else if (factors[i]<0){r = 0;    break;}
        }

        if(r == -1)                printf("-1");
        else if (!r)               printf("0");
        else                       for(int i=r-1; i>=0; i--)  printf("%c", digit[i]);
        printf("\n");
    }


//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);

    return 0;
}
/*
3  3
10  5
10  4
10  3
10  7
10  6
10  5
3  3
10  5
10  4
10  3
10  7
10  6
10  1
3  3
10  5
10  4
10  3
10  7
10  6
10  10
4  1
10  5
10  5
10  5
10  5
100  100
*/

