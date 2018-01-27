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
#define casep(z)            printf("Case %d: ", z);
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
#define MAX                 10001
#define LIM                 101
#define SIZE                158

int num[SIZE];
vector<int>prime;
ll store[10001];
char digit[1000001];

void sieve(){
    unsigned i,j,k;
    for(i=3; i<LIM; i+=2)
        if(!chkC(num[i>>6],((i>>1)&31)))
            for(j=i*i,k=i<<1; j<MAX; j+=k)
                setC(num[j>>6],((j>>1)&31));
    prime.pb(2);
    for(i=3;i<MAX;i+=2)
        if(!chkC(num[i>>6],((i>>1)&31)))
            prime.pb(i);
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
        digit[resSize] = (carry%10+'0');
        carry /= 10;
        resSize++;
    }

    return resSize;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    sieve();

    int t=0, n=0, x=0;
    ll mul=0, r=0;
    sf1(t);

    FOR(tc,1,t){
        ms(store, 0);
        ms(digit, 0);

        sf1(n);

        FOR(i,1,n){
            sf1(x);

            for(int j=0; j<prime.size() && prime[j]*prime[j]<=x; j++){
                if(!(x%prime[j])){
                    mul = prime[j];

                    while(!(x%prime[j])){
                        x /= prime[j];
                        mul *= prime[j];
                    }

                    mul /= prime[j];

                    store[prime[j]] = max(store[prime[j]], mul);
                }
            }

            if(x>1) store[x] = max(store[x], (ll)x);
        }

        digit[0] = '1', r = 1;

        FOR(i,2,10000)
            if(store[i])
                r = cal(store[i], r);

        casep(tc);
        for(int i=r-1; i>=0; i--)  printf("%c", digit[i]);
        printf("\n");
    }


//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);

    return 0;
}

