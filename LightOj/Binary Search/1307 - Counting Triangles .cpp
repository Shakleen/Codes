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

int bSearch(int x, int sz, int sides[]){
    int lo = 0, hi = sz-1, mid = 0, res=0;
    bool f=1;

    while(lo<=hi){
        mid = (lo+hi)/2;

        if (sides[mid] == x){
            res = mid;
            f = 0;
            lo = mid + 1;
        }
        else if (sides[mid] > x){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }

    if (!res && f)         res = hi;
    if (res<0)             res = 0;

    return res;
}

int main()
{
//int    A[] = {1,3,5,7,9,11,13,15};
//    printf("%d\n",bSearch(16,8,A));
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    int t=0, sides[2000], n=0, cnt=0, sum=0;

    sf1(t);

    FOR(tc,1,t){
        n=cnt=0;

        sf1(n);

        REP(i,n)    sf1(sides[i]);

        sort(sides, sides+n);

        for(int i=0; i<n-2; i++){
            for(int j=0; j<n-1; j++){
                sum = sides[i] + sides[j];
                cnt += bSearch(sum, n, sides);
            }
        }

        casep(tc);
        printf(" %d\n", cnt);
    }


//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);
    return 0;
}


