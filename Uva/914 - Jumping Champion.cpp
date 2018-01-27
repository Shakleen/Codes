#include <bits/stdc++.h>

using namespace std;

#define chkC(x,n)   (x&(1<<n))
#define setC(x,n)   (x|=(x|(1<<n)))
#define MAX         1000001
#define LIM         sqrt(MAX)+1

int num[MAX/32];
vector<int>prime;

void sieve()
{
    for(int i=3; i<=LIM; i+=2)
    {
        if (!chkC(num[i>>5],(i&31)))
        {
            for(int j=i*i,k=i<<1; j<MAX; j+=k)
            {
                num[j>>5]=setC(num[j>>5],(j&31));
            }
        }
    }

    prime.push_back(2);

    for(int i=3; i<MAX; i+=2)
    {
        if (!chkC(num[i>>5],(i&31)))
        {
            prime.push_back(i);
        }
    }

    return;
}

int main()
{
    sieve();

    int t=0,l=0,u=0,w=0,high=0,cnt=0,mx=0,mxn=0;
    vector<int>::iterator lo,hi;
    vector<int>dif;

    cin>>t;

    while(t--)
    {
        dif.clear();
        l=u=w=high=mxn=0;
        mx=INT_MIN;

        cin>>l>>u;

        lo=lower_bound(prime.begin(),prime.end(),l);
        hi=lower_bound(prime.begin(),prime.end(),u);

        if (*hi>u)  hi--;

        w=*lo;

        for(lo++; lo<=hi; lo++)
        {
            dif.push_back(*lo-w);
            w=*lo;
        }

        if (dif.size()!=0)
        {
            sort(dif.begin(), dif.end());
            w=dif[0];
            cnt=1;

            for(int i=1; i<dif.size(); i++)
            {
                if (dif[i]==w)
                {
                    cnt++;
                }
                else
                {
                    if(cnt>mx)
                    {
                        mx=cnt, high=1, mxn=w;
                    }
                    else if (cnt==mx)
                    {
                        high++;
                    }
                    cnt=1, w=dif[i];
                }
            }

            if(cnt>mx)
            {
                mx=cnt, high=1, mxn=w;
            }
            else if (cnt==mx)
            {
                high++;
            }
        }

        if (high!=1 || dif.size()<1)
        {
            cout << "No jumping champion";
        }
        else
        {
//                cout << high << ' ' << mx << endl;
            cout << "The jumping champion is " << mxn;
        }

        cout << '\n';
    }

    return 0;
}
