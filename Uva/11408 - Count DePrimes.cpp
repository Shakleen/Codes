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
#define MAX                 5000001
#define LIM                 2240

bool num[MAX];
int store[MAX];

void cal(){
    unsigned i,j;
    for(i=4; i<MAX; i+=2)   store[i] += 2,  num[i] = true;
    for(i=3; i<LIM; i+=2)
        if(!num[i])
            for(j=2*i; j<MAX; j+=i)
                num[j] = true,  store[j] += i;
    for(i=2; i<MAX; i++){
        if(!store[i] || !num[store[i]])               store[i] = store[i-1] + 1;
        else                                          store[i] = store[i-1];
//        printf("%d -> %d\n", i, store[i]);
    }
    return;
}

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    FAST();
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
//
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    cal();

    int a,b;

    while(1){
        cin>>a;
        if(!a)  break;
        cin>>b;
        cout<<store[b]-store[a-1]<<'\n';
    }

//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);
    return 0;
}


