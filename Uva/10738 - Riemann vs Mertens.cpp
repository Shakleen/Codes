#include <bits/stdc++.h>

using namespace std;

#define chkC(x,n)   (x&(1<<n))
#define setC(x,n)   (x|=(x|(1<<n)))
#define MAX         1000001
#define LIM         sqrt(MAX)+1
#define ll          long long

int num[MAX/32], mu[1000001], M[1000001];
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

void gen()
{
    int m=0, cnt=0, freq=0;
    bool f=0;
    mu[1]=M[1]=1;

    for(int no=2; no<1000001; no++)
    {
        if (!chkC(num[no>>5], (no&31)) && (no%2 || no==2))
        {
            mu[no]=-1;
        }
        else
        {
            m=no, cnt=0, f=0;
            for(int i=0; prime[i]*prime[i]<=m; i++)
            {
                if (!(m%prime[i]))
                {
                    cnt++,  freq=0;

                    while(!(m%prime[i]))
                    {
                        m/=prime[i];
                        freq++;

                        if(freq>1)
                        {
                            f=1;
                            break;
                        }
                    }
                    if (f)  break;
                }
            }
            if (m>1)
            {
//                if (no==22) cout << m << ' ' << cnt << endl;
                cnt++;
                freq=1;
            }

            if (f)                  mu[no]=0;
            else if (cnt%2)         mu[no]=-1;
            else                    mu[no]=1;
        }

        M[no]=M[no-1]+mu[no];
//        cout << no << ' ' << mu[no] << ' ' << M[no] << ' ' << cnt << ' ' << freq << endl;
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
    gen();
//cout << 1;
    int n=0;

    while(cin>>n)
    {
        if (!n) break;
        printf("%8d%8d%8d\n",n,mu[n],M[n]);
    }
    return 0;
}

