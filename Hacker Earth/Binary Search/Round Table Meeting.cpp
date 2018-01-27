#include<bits/stdc++.h>
#define assn(n,a,b) assert(n<=b && n>=a)
using namespace std;
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define pdn(n) printf("%d\n",n)
#define sl(n) scanf("%lld",&n)
#define sd(n) scanf("%d",&n)
#define pn printf("\n")
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define MOD 1000000007
LL mpow(LL a, LL n)
{LL ret=1;LL b=a;while(n) {if(n&1)
    ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}
return (LL)ret;}
#define MAXK 100000
#define MAXN 1000000000
int ar[MAXK];
int get(int n, int k){
    int i=0;
    while(i<k and ar[i]<=n)i++;
    return n-i;
}
int main()
{
    int t;
    sd(t);
    assn(t,1,10);
    while(t--){
        int n,k,p,s=0;
        sd(n),sd(k),sd(p);
        assn(n,1,MAXN);
        assn(k,0,MAXK);
        assn(p,1,n);
        for(int i=0; i<k; i++)
            sd(ar[i]);
        sort(ar,ar+k);
        int l=0,r=n,mid;
        if(get(r,k)<p){
            pdn(-1);
            continue;
        }
        while(r-l>1){
            mid=(r+l)/2;
            int q=get(mid,k);
            if(q<p)l=mid;
            else r=mid;
        }
        pdn(l+1);
    }
    return 0;
}

