#include <bits/stdc++.h>

using namespace std;

#define MAX 65537
#define LIM sqrt(MAX)+1
#define chkC(x,n) (x&(1<<n))
#define setC(x,n) (x|=(x|(1<<n)))

int num[MAX/32];
vector<int>prime;

void sieve()
{
    for(int i = 3; i <= LIM; i += 2)
    {
        if (!(chkC(num[i>>5],(i&31))))
        {
            for(int j = i*i, k = i<<1; j < MAX; j += k)
            {
                num[j>>5] = setC(num[j>>5],(j&31));
            }
        }
    }

    prime.push_back(2);

    for(int i = 3; i < MAX; i+=2)
    {
        if (!(chkC(num[i>>5],(i&31))))
        {
            prime.push_back(i);
        }
    }
}

int main()
{
    sieve();

    int g = 0, h = 0;
    vector<int>div;

    while (cin>>g)
    {
        if (!g) break;

        div.clear();
        h = g;

        if (h<0)
        {
            div.push_back(-1);
            h*=(-1);
        }

        for(int i = 0; i < prime.size() && prime[i] < h; i++)
        {
            if (!(h%prime[i]))
            {
                while(!(h%prime[i]))
                {
                    h/=prime[i];
                    div.push_back(prime[i]);
                }
            }
        }

        if (h>1)
        {
            div.push_back(h);
        }

        cout << g << " = ";
        for(int i = 0, j = div.size()-1; i <= j; i++)
        {
            cout << div[i];

            if (i!=j)
            {
                cout << " x ";
            }
        }
        cout << '\n';
    }
}
