#include <bits/stdc++.h>
using namespace std;

#define chkC(x,n)    (x&(1<<n))
#define setC(x,n)    (x|=(x|(1<<n)))
#define MAX 1000000
int num[MAX/32];
vector<int>prime;

void sieve()
{
    for(int i = 3, val = sqrt(MAX)+1; i <= val; i += 2)
    {
        if (!chkC(num[i>>5],(i&31)))
        {
            for(int j = i*i, k = i<<1; j <= MAX; j += k)
            {
                num[j>>5] = setC(num[j>>5],(j&31));
            }
        }
    }

    for(int i = 3; i <= MAX; i += 2)
    {
        if (!chkC(num[i>>5],(i&31)))
        {
            cout << i << endl;
            prime.push_back(i);
        }
    }
}
int main()
{
    sieve();
}
