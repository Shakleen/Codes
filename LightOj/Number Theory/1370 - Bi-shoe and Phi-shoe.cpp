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
#define MAX                 1000004
#define SIZE                1000003

int phi[MAX], num[SIZE];

void phiFunc(){
    int i,j,k,mn=INT_MAX;;
    phi[1] = 0;
    for(i=2; i<MAX; i++)        phi[i] = i;
    for(i=2; i<MAX; i++){
        if (phi[i] == i){
            phi[i] = i-1;

            for(j=i<<1; j<MAX; j+=i)
                phi[j] = (phi[j]/i)*(i-1);
        }

        if (num[ phi[i] ]) num[ phi[i] ] = min(i, num[ phi[i] ]);
        else               num[ phi[i] ] = i;
//            printf("PHI(%d) = %d\n", i, phi[i]);
    }

    for(i=SIZE-1; i>=0; i--){
        if (num[i])     mn = min(num[i],mn);
        num[i] = mn;
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    phiFunc();
//    for(int i = 0; i < SIZE; i++)   printf("NUM[%d] = %d\n", i, num[i]);

    int t=0, n=0, x=0;
    ll sum=0;

    sf1(t);

    FOR(tc,1,t){
        sf1(n);

        sum=0;
        REP(i,n){
            sf1(x);
            sum += num[x];
        }


        casep(tc);
        printf(" %lld Xukha\n", sum);
    }


//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);
    return 0;
}
//999982
//non zeros 163862

