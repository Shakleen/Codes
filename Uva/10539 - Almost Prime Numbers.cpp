#include <bits/stdc++.h>

using namespace std;

#define chkC(x,n)   (x&(1<<n))
#define setC(x,n)   (x|=(x|(1<<n)))
#define MAX         1000001
#define LIM         sqrt(MAX)+1
#define ll          long long

int num[MAX/32];
vector<int>prime;

void sieve()
{
    for(int i=3; i<=LIM; i+=2)
    {
        if (!chkC(num[i>>5],(i&31)))
        {
            for(int j=i*i, k=i<<1; j<MAX; j+=k)
            {
                num[j>>5]=setC(num[j>>5],(j&31));
            }
        }
    }

    prime.push_back(2);

    for(int i=3; i<MAX; i+=2)
    {
        if (!chkC(num[i>>5],(i&31)))
        {
            prime.push_back(i);
//            cout << i << endl;
        }
    }

    return;
}

ll power (ll a, ll b)
{
    ll cnt=0;

    while(a>=b)
    {
        a/=b;
        cnt++;
    }

    return cnt;
}

ll fastexpo(ll base, ll power)
{
    ll res=1;

    while(power>0)
    {
        if(power&1)
        {
            res=res*base;
        }

        power>>=1;
        base=base*base;
    }

    return res;
}

ll cal(ll n, bool f)
{
    if (n==1)   return 0;

    ll lim=sqrt(n)+1, sum=0, x=0, b=0;
    bool flag=true;

    for(ll i=0; i<prime.size() && prime[i]<=lim; i++)
    {
        x=power(n,prime[i]);
        if (flag)
        {
            sum+=(x-1);
            b=fastexpo(prime[i],x);
            if (b==n && f==0)   sum--;
        }

//        cout << prime[i] << ' ' << x << endl;
    }

    if (sum<0)  return 0;

    return sum;
}

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    FAST();
    sieve();

    ll n=0,lo=0,hi=0;

    cin>>n;

    while(n--)
    {
        cin>>lo>>hi;
        cout<<cal(hi,1)-cal(lo,0)<<'\n';
    }
    return 0;
}
