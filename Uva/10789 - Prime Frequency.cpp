#include <bits/stdc++.h>

using namespace std;

#define chkC(x,n)   (x&(1<<n))
#define setC(x,n)   (x|=(x|(1<<n)))
#define MAX         2048
#define LIM         sqrt(MAX)+1
#define ll          long long

int num[MAX/32];

void sieve()
{
    for(int i=3; i<=LIM; i+=2)
    {
        if (!chkC(num[i>>5],(i&31)))
        {
            for(int j=i*i, k=i<<1; j<MAX; j+=k)
            {
                num[j>>5]=setC(num[j>>5],(j&31));
            }
        }
    }

    return;
}

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    FAST();
    sieve();

    int t=0,cnt=0;
    string str,ans;

    cin>>t;

    for(int tc=1;tc<=t;tc++)
    {
        ans.clear(),    str.clear();

        cin>>str;

        sort(str.begin(), str.end());

        cnt=1;

        for(int i=1; i<str.size(); i++)
        {
            if(str[i]==str[i-1])
            {
                cnt++;
            }
            else
            {
                if(!chkC(num[cnt>>5],(cnt&31)) && (cnt%2 || cnt==2) && cnt!=1)
                {
                    ans+=str[i-1];
                }
                cnt=1;
            }
        }

        if(!chkC(num[cnt>>5],(cnt&31)) && (cnt%2 || cnt==2) && cnt!=1)
        {
            ans+=str[str.size()-1];
        }

        if(ans.size()>0)    cout<<"Case "<<tc<<": "<<ans<<'\n';
        else                cout<<"Case "<<tc<<": "<<"empty"<<'\n';
    }

    return 0;
}
