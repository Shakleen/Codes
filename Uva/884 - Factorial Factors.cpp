#include <bits/stdc++.h>

using namespace std;

#define chkC(x,n)   (x&(1<<n))
#define setC(x,n)   (x|=(x|(1<<n)))
#define MAX         1000001
#define LIM         sqrt(MAX)+1
#define ll          long long

int num[MAX/32];
int ans[MAX];
vector<int>prime;

void sieve()
{
    for(int i=3; i<=LIM; i+=2)
    {
        if (!chkC(num[i>>5],(i&31)))
        {
            for(int j=i*i,k=i<<1; j<MAX; j+=k)
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
        }
    }
    return;
}

void preCal()
{
    ans[1]=ans[0]=0;
    ans[2]=1;

    for(int i=3; i<MAX; i++)
    {
        ans[i]=ans[i-1];
        int n=i, j=0,lim=sqrt(n)+1;

        for(int j=0; j<prime.size() && prime[j]<=lim; j++)
        {
            if (!(n%prime[j]))
            {
                while(!(n%prime[j]))
                {
                    ans[i]++;
                    n/=prime[j];
                }
            }
        }
        if(n>1)
        {
            ans[i]++;
        }
    }
}

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
//    FAST();
    sieve();
    preCal();

    ll n = 0, cnt = 0, m = 0;

    while (cin>>n)
    {
        cout << ans[n] << '\n';
    }

    return 0;
}
