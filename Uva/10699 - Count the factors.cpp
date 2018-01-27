#include <bits/stdc++.h>

using namespace std;

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    FAST();
    int n=0, m=0, cnt=0;

    while (cin>>n)
    {
        if (!n) break;

        cnt=0;
        m=n;
        for(int i=2; i<=sqrt(n); i++)
        {
            if(!(n%i))
            {
                cnt++;
                while (!(n%i))
                {
                    n/=i;
                }
            }
        }

        if(n>1)
        {
            cnt++;
        }

        cout << m << " : " << cnt << '\n';
    }

    return 0;
}

