#include<bits/stdc++.h>
using namespace std;

/* msi1427 */

#define ll           long long
#define llu          long long unsigned
#define FOR(i,n)     for(int i=0;i<n;i++)
#define FLR(i,n)     for(ll i=0;i<n;i++)
#define RFOR(i,n)    for(int i=n-1;i>=0;i--)
#define RFLR(i,n)    for(ll i=n-1;i>=0;i--)
#define rep(i,a,b)   for(int i=a;i<=b;i++)
#define repl(i,a,b)  for(ll i=a;i<=b;i++)
#define casep(z)     cout << "Case " << z << ": ";
#define Fast         ios_base::sync_with_stdio(0);cin.tie(0);
#define sz(a)        a.size()
#define all(x)       x.begin(),x.end()
#define SORT(a,n)    sort(a,a+n)
#define RSORT(a,n)   sort(a,a+n,greater<int>())
#define pii          pair<int,int>
#define pll          pair<ll,ll>
#define VSORT(v)     sort(all(v))
#define VRSORT(v)    sort(all(v),greater<int>())
#define pb           push_back
#define pf           push_front
#define pob          pop_back()
#define pof          pop_front()
#define ff           first
#define ss           second
#define tt           true
#define fs           false
#define MP           make_pair
#define ms(x,n)      memset((x),n,sizeof(x))
#define bsrch(a,n,x) binary_search(a,a+n,x)
#define vi           vector<int>
#define vll          vector<ll>
#define PI           acos(-1.0)
#define LB(a,x)      (lower_bound(all(a),x)-a.begin()) //  first element in the range [first,last) which does not compare less than val.
#define UB(a,x)      (upper_bound(all(a),x)-a.begin()) //  first element in the range [first,last) which compares greater than val.
#define PQ           priority_queue
#define heap         PQ< ll , vll , greater < ll > >
#define REV(x)       reverse(all(x))
#define mpii         map<int,int>
#define mpll         map<ll,ll>
#define cig          cin.ignore()
#define INF          1e10
#define prec(n)      fixed << setprecision(n)
#define lb           lower_bound
#define ub           upper_bound
#define lcm(a, b)    ((a)*((b)/__gcd(a,b)))
#define fin          freopen("in.txt","r",stdin)
#define fout         freopen("out.txt","w",stdout)
#define sc           scanf
#define pt           printf
#define np           next_permutation
#define IT(it,x)     for(it=x.begin();it!=x.end();it++)

ll dx[] =              {1,-1,0,0};
ll dy[] =              {0,0,1,-1};

#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(min(a,b),min(c,d))
#define max4(a,b,c,d)   max(max(a,b),max(c,d))
#define max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))

ll n;

int main()
{
    //Fast
    while(cin >> n)
    {
        vector<ll>v[205];
        pll p[n+9];
        ll ar[205]= {0};
        ll vis[105]= {0};
        ll mx=-1;
        FLR(i,n)
        {
            cin >> p[i].ff >> p[i].ss;
            repl(j,p[i].ff,p[i].ss)
            {
                v[j].pb(i);
                ar[j]++;
            }
            //cout << "r\n";
        }
        ll x=0;
        ll c=0;
        while(1)
        {
            mx=0;
            FLR(i,201)
            {
                if(mx<ar[i])
                {
                    mx=ar[i];
                    x=i;
                }
            }
            if(mx==0) break;
            FLR(i,sz(v[x]))
            {
                ll xx = v[x][i];
                if(vis[xx]) continue;
                repl(j,p[xx].ff,p[xx].ss) ar[j]--;
                vis[xx]=1;
            }
            c++;
        }
        cout << c << "\n";
    }
}
