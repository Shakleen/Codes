#include <bits/stdc++.h>

using namespace std;

#define chkC(x,n)   (x&(1<<n))
#define setC(x,n)   (x|=(x|(1<<n)))
#define MAX         1000001
#define LIM         sqrt(MAX)+1

int num[MAX/32];
vector<int>prime;

int check(int n)
{
    int sum=0;

    while(n)
    {
        sum+=n%10;
        n/=10;
    }

    return sum;
}

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
            int s=check(i);
            if (!chkC(num[s>>5],(s&31)) && (s%2||s==2))
            {
                prime.push_back(i);
//                cout << i << endl;
            }
        }
    }

    return;
}

int bs(int x)
{
    int lo=0, hi=prime.size()-1,mid=0;

    while(lo<=hi)
    {
        mid=(lo+hi)/2;
//        cout << lo << ' ' << hi << ' ' << mid << endl;
        if(prime[mid]==x)
        {
            return mid;
        }
        else if (prime[mid]>x)
        {
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
    }

    if(lo>=prime.size())    lo--;
    return lo;
}
void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main()
{
//    FAST();
    sieve();

    int n=0,t1=0,t2=0,lo=0,hi=0;

    scanf("%d", &n);

    while(n--)
    {
        scanf("%d %d", &t1, &t2);

        lo=bs(t1);
        hi=bs(t2);
        if (prime[hi]>t2)   hi--;

        printf("%d\n",(hi-lo+1));
    }

    return 0;
}
