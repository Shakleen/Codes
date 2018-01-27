#include <bits/stdc++.h>
using namespace std;
#define chkC(x,n)   (x&(1<<n))
#define setC(x,n)   (x|=(x|(1<<n)))
#define MAX         2048
#define LIM         sqrt(MAX)+1
#define ll          long long
#define N           3000000
int Num[MAX/32],fact[N]={1,1,1}, num[N]={0,0,1};
vector<int>prime;
void sieve(){
    for(int i=3; i<=LIM; i+=2)
        if (!chkC(Num[i>>5],(i&31)))
            for(int j=i*i, k=i<<1; j<MAX; j+=k)
                Num[j>>5]=setC(Num[j>>5],(j&31));
    prime.push_back(2);
    for(int i=3; i<MAX; i+=2)
        if (!chkC(Num[i>>5],(i&31)))
            prime.push_back(i);
    return;
}
void cnt(){
    int no=0;
    for(int i=3; i<N; i++){
        no=i;
        for(int j=0; prime[j]*prime[j]<=no && j<prime.size(); j++){
            if(!(no%prime[j])){
                no/=prime[j];
                num[i]=num[no]+1;   //Number i has one more prime divisor than it's divisor no
                break;
            }
        }
        if(no==i) num[i]=1;         //Prime number
        fact[i]=(fact[i-1]+num[i]); //Total number of factors of factorial
    }
    return;
}
int bs(int x){
    int mid=0, lo=0, hi=N-1;
    while(lo<=hi)
    {
        mid=(lo+hi)>>1;
        if(fact[mid]<=x)
        {
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }
    if(lo==N)    lo--;
    return lo;
}
void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    FAST();
    sieve();
    cnt();

    int t=0,n=0,ans=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=bs(n);
        cout << ans << '\n';
    }
    return 0;
}
