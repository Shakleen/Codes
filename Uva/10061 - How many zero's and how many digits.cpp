#include <bits/stdc++.h>
using namespace std;

#define chkC(x,n)   (x&(1<<n))
#define setC(x,n)   (x|=(x|(1<<n)))
#define MAX         1025
#define LIM         sqrt(MAX)+1

int num[MAX/32];
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
}

int expo(int n, int p)
{
    int cnt=0;

    while (n)
    {
        cnt+=(n/p);
        n/=p;
    }

    return cnt;
}

int trailingB(int n, int b)
{
    int ans = INT_MAX, freq=0, power=0;

    for(int i=0; prime[i]<=b; i++)
    {
        if (!(b%prime[i]))
        {
            freq=0;

            while (!(b%prime[i]))
            {
                b/=prime[i];
                freq++;
            }

            power=expo(n,prime[i]);

            ans=min(ans,(int)(power/freq));
        }
    }

    return ans;
}

int digitsB(int n, int b)
{
    double y=0.0;
    for(int i=1; i<=n; i++)
        y += (log(i));
    y/=log(b);
    y+=1.0;
    return (floor(y));
}

int main()
{
    sieve();

    int n=0,b=0;

    while(cin>>n>>b)
    {
        cout << trailingB(n,b) << " " << digitsB(n,b) << '\n';
    }

    return 0;
}
