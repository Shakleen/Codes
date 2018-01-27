#include <bits/stdc++.h>

using namespace std;

#define ll          long long

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    ll n=0, lim=0, t=0;

    while(cin>>n)
    {
        if (n<0)    break;

        for(ll i=2; i<=sqrt(n); i++)
        {
            if(!(n%i))
            {
                while(!(n%i))
                {
                    n/=i;
                    cout<<"    "<<i<<'\n';
                }
                t++;
            }
        }

        if (t==0||n>1)   cout<<"    "<<n<<'\n';

        printf("\n");
    }

    return 0;
}
