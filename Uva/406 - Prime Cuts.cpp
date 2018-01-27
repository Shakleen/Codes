#include <bits/stdc++.h>

using namespace std;

#define chkC(x,n)   (x&(1<<n))
#define setC(x,n)   (x|=(x|(1<<n)))
#define MAX         1024
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
                num[j>>5] = setC(num[j>>5],(j&31));
            }
        }
    }

    prime.push_back(1);
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

int binsearch(int x)
{
    int mid = 0, lo = 0, hi = prime.size()-1;

    while (lo<=hi)
    {
        mid = (lo+hi)/2;

        if (prime[mid]==x)
        {
            return mid;
        }
        else if (prime[mid]>x)
        {
            hi = mid-1;
        }
        else
        {
            lo = mid+1;
        }
    }

    return hi;
}

int main()
{
    sieve();

    int n = 0, c = 0, sz = 0, cut = 0, lo = 0, hi = 0;

    while (cin>>n>>c)
    {
        sz = binsearch(n)+1;

        cout << n << " " << c << ":";

        if (2*c >= sz)
        {
            for(int i = 0; i < sz; i++)
            {
                cout << " " << prime[i];
            }
        }
        else
        {
            if (sz%2){lo=(sz/2)-c+1;hi=(sz/2)+c-1;}
            else     {lo=(sz/2)-c;  hi=(sz/2)+c-1;}

            for(int i = lo; i <= hi; i++)
            {
                cout << " " << prime[i];
            }
        }

        cout << "\n\n";
    }

    return 0;
}
