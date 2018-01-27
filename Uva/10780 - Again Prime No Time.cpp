#include <bits/stdc++.h>

using namespace std;

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int expo(int n, int p)
{
    int cnt=0;

    while(n)
    {
        n/=p;
        cnt+=n;
    }

    return cnt;
}

int cal(int n, int p)
{
    int freq=0,power=0,ans=INT_MAX;

    for(int i=2; i<=p; i++)
    {
        if(!(p%i))
        {
            freq=0;
            while(!(p%i))
            {
                freq++;
                p/=i;
            }
            power=expo(n,i);
            ans=min(ans,power/freq);
        }
    }

    return ans;
}
int main()
{
    FAST();
    int t=0,n=0,m=0,ans=0;
    cin>>t;
    for(int tc=1; tc<=t; tc++)
    {
        cin>>m>>n;
        ans=cal(n,m);
        cout<<"Case "<<tc<<":"<<'\n';
        if(ans) cout<<ans;
        else    cout<<"Impossible to divide";
        cout<<'\n';
    }
    return 0;
}

