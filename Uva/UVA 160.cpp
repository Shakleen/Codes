#include <bits/stdc++.h>

using namespace std;

bool num[101];
vector<int>prime;

void sieve()
{
    prime.push_back(2);

    for(int i = 3; i <= 10; i += 2)
    {
        if (!num[i])
        {
            for(int j = i*i, k = i<<1; j <= 100; j += k)
            {
                num[j] = 1;
            }
        }
    }

    for(int i = 3; i <= 100; i += 2)
    {
        if (!num[i])
        {
            prime.push_back(i);
        }
    }

    return;
}

int cnt (int n, int p)
{
    int x = 0;

    while (n)
    {
        n /= p;
        x += n;
    }

    return x;
}

int main()
{
    sieve();

    int n = 0;
    bool f = 0;
    vector<int>v;

    while(cin >> n)
    {
        if (!n) break;

        v.clear();

        for (int i = 0; prime[i] <= n && i < prime.size(); i++)
        {
            v.push_back(cnt(n,prime[i]));
        }

        printf("%3d! =", n);
        for(int i = 0, cnt = 0; i < v.size(); i++, cnt++)
        {
            if (cnt == 15)
            {
                printf("\n      ");
                cnt -= 15;
            }
            printf("%3d", v[i]);
        }

        printf("\n");
    }

    return 0;
}
