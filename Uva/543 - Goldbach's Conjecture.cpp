#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001
#define LIM sqrt(MAX)+1
#define chkC(x,n) ((x&(1<<n)))
#define setC(x,n) (x|=((x|(1<<n))))

int num[MAX/32];
vector<int>prime;

void sieve()
{
    for(int i = 3; i <= LIM; i+=2)
    {
        if (!chkC(num[i>>5],(i&31)))
        {
            for(int j  = i*i, k = i<<1; j < MAX; j += 2*i)
            {
                num[j>>5] = setC(num[j>>5],(j&31));
            }
        }
    }

    for(int i = 3; i < MAX; i+=2)
    {
        if (!chkC(num[i>>5],(i&31)))
        {
            prime.push_back(i);
//            cout << i << endl;
        }
    }

    return;
}

int main()
{
    sieve();

    int n = 0, lim = 0, a = 0, b = 0;

    while (cin >> n)
    {
        if (!n) break;

        lim = (n+1)/2;

        for(int i = 0; prime[i] <= lim && i < prime.size(); i++)
        {
            a = prime[i];
            b = n-a;

            if (!chkC(num[b>>5],(b&31)))
            {
                break;
            }
        }

        cout << n << " = " << a << " + " << b << '\n';
    }
    return 0;
}
