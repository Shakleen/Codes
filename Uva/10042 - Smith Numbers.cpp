#include <bits/stdc++.h>

using namespace std;

int count(int m)
{
    int sz=0;

    while(m)
    {
        sz+=(m%10);
        m/=10;
    }

    return sz;
}

int digitsum(int n)
{
    int sum=0, lim=(int)sqrt(n), cnt=0, dsum=0, sz=count(n);
    bool f=0;

    for(int i=2; i<=lim; i++)
    {
        if (!(n%i))
        {
            cnt=0, dsum=0, dsum=count(i), f=1;

            while (!(n%i))
            {
                n/=i;
                cnt++;
            }

            sum+=(cnt*dsum);
        }
    }

    if (n>1)
    {
        sum+=count(n);
    }

    if (sum==sz && f)       return 1;
    else                    return 0;
}

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    FAST();

    int t=0,n=0,m=0;

    cin>>t;

    while(t--)
    {
        n=m=0;

        cin>>n;

        for(int i=n+1; ;i++)
        {
            m=i;

            if(digitsum(i)==1)
            {
                m=i;
                break;
            }
        }

        cout << m << '\n';
    }

    return 0;
}
