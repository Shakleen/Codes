#include <bits/stdc++.h>

using namespace std;

#define chkC(x,n)   (x&(1<<n))
#define setC(x,n)   (x|=(x|(1<<n)))
#define MAX         100001
#define LIM         sqrt(MAX)+1

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
        }
    }

    return;
}

int phifunc(int n)
{
    int res=n, lim=sqrt(n)+1,cnt=0;
    for(int i=0; prime[i]<=lim && i<prime.size(); i++)
    {
        if (!(n%prime[i]))
        {
            cnt=0;
            while (!(n%prime[i]))
            {
                n/=prime[i];
            }
            res-=(res/prime[i]);
        }
    }
    if (n>1)
    {
        res-=(res/n);
    }
    return res;
}

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    FAST();
    sieve();
    int n=0;

    while(cin>>n)
    {
        if (!n)         break;
        else if(n==1)   cout<<0<<'\n';
        else            cout<<phifunc(n)<<'\n';
    }

    return 0;
}
