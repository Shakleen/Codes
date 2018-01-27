#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n = 0, l = 0, u = 0, mx = 0, mxn = 0, cnt = 0;
    double lim = 0;

    cin >> n;

    while (n--)
    {
        mx = mxn = LONG_LONG_MIN;
        cin >> l >> u;

        for(ll i = l; i <= u; i++)
        {
            cnt = 0;
            lim = sqrt(i);

            for(ll j = 1; j <= lim; j++)
            {
                if (!(i%j))
                {
                    cnt++;
                    if (j != (i/j))
                    {
                        cnt++;
                    }
                }
            }

            if (cnt>mx)
            {
                mx = cnt;
                mxn = i;
            }
        }

        cout << "Between " << l << " and " << u << ", " << mxn <<
        " has a maximum of " << mx << " divisors."<< '\n';
    }
}
