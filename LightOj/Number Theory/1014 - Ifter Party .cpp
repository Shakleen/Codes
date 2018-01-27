#include <bits/stdc++.h>

using namespace std;

#define chkC(x,n)       (x&(1<<n))
#define setC(x,n)       (x|=(x|(1<<n)))
#define MAX             65536
#define LIM             256
#define pb              push_back

int num[2048];
vector<int>prime,primediv,freq,store;

void sieve()
{
    for(int i=3; i<=LIM; i+=2)
        if(!chkC(num[i>>5],(i&31)))
            for(int j=i*i, k=i<<1; j<MAX; j+=k)
                num[j>>5]=setC(num[j>>5],(j&31));

    prime.push_back(2);

    for(int i=3; i<MAX; i+=2)
        if(!chkC(num[i>>5],(i&31)))
            prime.push_back(i);
}

void div(int n)
{
    int cnt=0;

    for(int i=0; i<prime.size() && prime[i]*prime[i]<=n; i++)
    {
        if (!(n%prime[i]))
        {
            primediv.pb(prime[i]),  cnt=0;

            while(!(n%prime[i]))
                n/=prime[i],        cnt++;

            freq.pb(cnt);
        }
    }

    if(n>1)
        primediv.pb(n), freq.pb(1);

    return;
}

void gen(int cur, int num)
{
    if(cur==primediv.size())
        store.pb(num);
    else
    {
        int val=1;
        for(int i=0; i<= freq[cur]; i++)
            gen(cur+1, num*val),    val*=primediv[cur];
    }

    return;
}

int main()
{
    sieve();
    int t=0,p=0,l=0,n=0,a=0;

    scanf("%d", &t);

    for(int tc=1; tc<=t; tc++)
    {
        scanf("%d %d", &p, &l);

        primediv.clear();
        store.clear();
        freq.clear();

        printf("Case %d:",tc);
        n=p-l;

        if (!l && !p)
            printf(" 1");
        else if(l>=n)
            printf(" impossible");
        else
        {
            div(n);
            gen(0,1);
            sort(store.begin(), store.end());
            for(int i=0; i<store.size(); i++)
                if(store[i]>l)  printf(" %d", store[i]);
        }

        printf("\n");
    }
    return 0;
}
