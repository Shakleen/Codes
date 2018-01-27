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

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    int t=0;
    double x,y,c,lo,hi,mid,invX,invY,h;
    sf1(t);

    FOR(tc,1,t){
        x=y=c=lo=hi=mid=invX=invY=h=0.0;

        scanf("%lf %lf %lf", &x, &y, &c);

        lo = 0.0,   hi = (x<y)?x:y,     x = x*x,    y = y*y;

        FOR(i,1,100000){
            mid = (lo+hi)/2.0,  invX = 1.0/(sqrt(x-mid*mid)),   invY = 1.0/(sqrt(y-mid*mid));
            h = 1.0/(invX + invY);

            if(h<c)     hi = mid;
            else        lo = mid;
        }

        casep(tc);
        printf(" %.10lf\n", mid);
    }


//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);
    return 0;
}


