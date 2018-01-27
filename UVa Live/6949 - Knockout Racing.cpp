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

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    FAST();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    ll n,m,a[1001],b[1001],x,y,t,cnt,s,dif,lo,hi,r;

    while(cin>>n>>m){
        REP(i,n){
            cin>>a[i]>>b[i];
        }

        REP(i,m){
            cnt=0;

            cin>>x>>y>>t;

            REP(i,n){
                lo = min(a[i],b[i]),    hi = max(a[i],b[i]);

                if(x>hi || y<lo)
                    continue;
                if(lo>=x && hi<=y){
                    cnt++;
                    continue;
                }

                dif = (b[i]-a[i]),    r = t/dif,    s = (t%dif);

                if(r%2)     (a[i]<b[i]) ? s=a[i]+(dif-s) : s+=b[i];
                else        (a[i]<b[i]) ? s+=a[i] : s=b[i]+(dif-s);

//                printf("(a,b)=(%lld,%lld) %lld is in (%lld,%lld) s=%lld r=%lld\n",
//                       a[i],b[i],s,x,y,s,r);

                if(s>=x && s<=y)    cnt++;
            }

            cout<<cnt<<'\n';
        }
    }


//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);

    return 0;
}


