#include <bits/stdc++.h>

using namespace std;

#define chkC(x,n)   (x&(1<<n))
#define setC(x,n)   (x|=(x|(1<<n)))
#define MAX         16384
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

int bs(int x)
{
    int lo=0, hi=prime.size()-1, mid=0;

    while(lo<=hi)
    {
        mid=(lo+hi)/2;

        if(prime[mid]==x)
        {
            return mid;
        }
        else if (prime[mid]>x)
        {
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
    }

    if(lo>=prime.size())    return prime.size()-1;

    return lo;
}

void FAST()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    FAST();
    sieve();

    int t=0,n=0,ans=0;

    cin>>t;


    while(t--)
    {
        cin>>n;

        n/=2;
        ans=bs(n);

        if(prime[ans]<=n && ans!=prime.size()-1)    ans++;

        cout<<prime[ans]<<'\n';
    }

    return 0;
}
