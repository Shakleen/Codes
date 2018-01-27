#include <bits/stdc++.h>
using namespace std;
#define chkC(x,n)   (x&(1<<n))
#define setC(x,n)   (x|=(x|(1<<n)))
#define MAX         10000001
#define LIM         sqrt(MAX)+1
#define ll          long long
int Num[MAX/32];
vector<int>prime;
void sieve(){
    for(int i=3; i<=LIM; i+=2)
        if (!chkC(Num[i>>5],(i&31)))
            for(int j=i*i, k=i<<1; j<MAX; j+=k)
                Num[j>>5]=setC(Num[j>>5],(j&31));
    prime.push_back(2);
    for(int i=3; i<MAX; i+=2)
        if (!chkC(Num[i>>5],(i&31)))
            prime.push_back(i);
    return;
}
void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main()
{
    FAST();
    sieve();

    ll n=0,ans=0,cnt=0;

    while(cin>>n)
    {
        cnt=0;

        if(!n)  break;
        else if (n<0)   n*=(-1);

        for(ll i=0; prime[i]<=sqrt(n) && i<prime.size(); i++)
        {
            if (!(n%prime[i]))
            {
                ans=prime[i];
                while(!(n%prime[i]))
                    n/=prime[i];
                cnt++;
            }
        }

        if(n>1)
        {
            cnt++;
            ans=n;
        }

        if(cnt>1)       cout << ans << '\n';
        else            cout << -1 << '\n';
    }
    return 0;
}

