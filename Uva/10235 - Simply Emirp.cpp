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
            for(int j=i*i, k=i<<1; j<MAX; j+=k)
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

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
//    FAST();
    sieve();

    int n=0,m=0,rev=0,type=0;

    while(cin>>n)
    {
        type=0;

        if (n<=1)
        {
            type=0;
        }
        else if(!chkC(num[n>>5],(n&31)) && (n%2 || n==2))
        {
            if (n<13)
            {
                type=1;
            }
            else
            {
                m=n,    rev=0;

                while(m)
                {
                    rev=rev*10+(m%10);
                    m/=10;
                }

                if(!chkC(num[rev>>5],(rev&31)) && (rev%2) && (rev!=n))
                {
                    type=2;
                }
                else
                {
                    type=1;
                }
            }
        }

        if (!type)
        {
            cout << n << " is not prime."<< '\n';
        }
        else if (type==1)
        {
            cout << n << " is prime."<< '\n';
        }
        else
        {
            cout << n << " is emirp."<< '\n';
        }
    }

    return 0;
}
