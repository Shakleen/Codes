#include <bits/stdc++.h>

using namespace std;

#define N 5000001
#define ll unsigned long long

ll score[N];

void phi()
{
    int i=0,j=0;

    for(i=0; i<N; i++)  score[i]=i;

    for(i=2; i<N; i++)
    {
        if(score[i]==i)
        {
            score[i]=i-1;
            for(j=2*i; j<N; j+=i){
                score[j]=((score[j]/i)*(i-1));
            }
        }
    }

    return;
}

void cal()
{
    phi();

    for(int i=1; i<N; i++)
        score[i]=score[i-1]+(score[i]*score[i]);
}

int main()
{
    cal();

    int t=0,tc=0,a=0,b=0;

    scanf("%d", &t);

    for (tc=1;tc<=t;tc++)
    {
        scanf("%d %d", &a, &b);
        printf("Case %d: %llu\n",tc,score[b]-score[a-1]);
    }
    return 0;
}
