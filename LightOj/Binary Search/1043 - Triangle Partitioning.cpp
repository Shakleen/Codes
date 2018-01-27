//1043 - Triangle Partitioning

#include <bits/stdc++.h>

using namespace std;

//*******************************************************************************
//*******************************Template****************************************
//*******************************************************************************

#define eps                 1e-8
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

double area(double a, double b, double c){
    double s = ((a+b+c)/(2.0));
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    int t=0;
    double AB,BC,CA,rat,angADE,angAED,angDAE,AD,AE,DE,areaABC,areaADE,r,lo,hi,rAE,rAD,sinADE,sinAED,sinDAE;

    sf1(t);

    FOR(tc,1,t){
        //Initializing values
        AB=BC=CA=rat=angADE=angAED=angDAE=AD=AE=DE=areaABC=areaADE=r=lo=hi=rAE=rAD=sinADE=sinDAE=sinAED=0.0;

        scanf("%lf %lf %lf %lf", &AB, &CA, &BC, &rat);

        areaABC = area(AB,BC,CA);

        //Angle values
        angDAE = acos((AB*AB + CA*CA - BC*BC)/(2.0*AB*CA));
        angADE = acos((AB*AB + BC*BC - CA*CA)/(2.0*AB*BC));
        angAED = acos((CA*CA + BC*BC - AB*AB)/(2.0*CA*BC));

        //sin values
        sinDAE = sin(angDAE),   sinADE = sin(angADE),   sinAED = sin(angAED);

        //ratio values
        rAE = (sinADE/sinDAE),   rAD = (sinAED/sinDAE);

        //Binary search values
        lo = 0.0,   hi = BC;

        //Binary searching
        FOR(i,1,100000){
            DE = (lo+hi)/2.0,   AE = DE*rAE,     AD = DE*rAD;
            areaADE = area(AD, AE, DE);
            r = (areaADE/(areaABC-areaADE));

            if(r < rat)                lo = DE;
            else if (r > rat)          hi = DE;
        }

//        printf("AD = %lf DE = %lf AE = %lf r = %lf\n",AD,DE,AE,r);
        casep(tc);
        printf(" %.6lf\n", AD);
    }


//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);
    return 0;
}
