#include <bits/stdc++.h>

using namespace std;

#define chkC(x,n)   (x&(1<<n))
#define setC(x,n)   (x|=(x|(1<<n)))
#define MAX         20000000
#define LIM         sqrt(MAX)+1

int num[MAX/32];
vector< pair <int,int> >prime;

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

    int last=0;
    for(int i=3; i<MAX; i+=2)
    {
        if (!chkC(num[i>>5],(i&31)))
        {
            if(!last)   last=i;
            else if(i-last==2)
            {
                prime.push_back(make_pair(last,i));
            }
            last=i;
        }
    }

    return;
}

int main()
{
    sieve();

    int n=0;

    while(scanf("%d",&n)!=EOF)
    {
        printf("(%d, %d)\n", prime[n-1].first, prime[n-1].second);
    }
}
