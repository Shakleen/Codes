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
#define casep(z)            printf("Case %lld:", z);
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
#define MAX                 1000001

int d[2] = {2,5};
pii fact[MAX],numb[MAX];

void cal()
{
    int no=0;

    fact[0].ff = fact[0].ss = fact[1].ff = fact[1].ss = 0;
    numb[0].ff = numb[0].ss = numb[1].ff = numb[1].ss = 0;

    for(int i=2; i<MAX; i++)
    {
        no = i;

        for(int j=0; j<2; j++)
        {
            if(!(no%d[j]))
            {
                no /= d[j];

                numb[i].ff = numb[no].ff;
                numb[i].ss = numb[no].ss;

                if(!j)  numb[i].ff++;//increasing 2
                else    numb[i].ss++;//increasing 5

                break;
            }
        }

        fact[i].ff = fact[i-1].ff + numb[i].ff;
        fact[i].ss = fact[i-1].ss + numb[i].ss;

//        printf("%d has %d 2s and %d 5s\t%d! has %d 2s and %d 5s\n",
//               i,numb[i].ff,numb[i].ss,i,fact[i].ff,fact[i].ss);
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();
    cal();

    ll t=0, n=0, r=0, p=0, q=0, no5=0, no2=0;

    scanf("%lld", &t);

    FORL(tc,1,t)
    {
        scanf("%lld %lld %lld %lld", &n, &r, &p, &q);

        no5 = fact[n].ss-fact[r].ss-fact[n-r].ss+q*numb[p].ss;
        no2 = fact[n].ff-fact[r].ff-fact[n-r].ff+q*numb[p].ff;

        casep(tc);
        printf(" %lld\n", min(no2,no5));
    }

//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);

    return 0;
}


