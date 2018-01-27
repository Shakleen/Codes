#include <bits/stdc++.h>
using namespace std;
double d[1000001];
void precal()
{
    d[0]=d[1]=0.0;
    for(int i=2; i<1000001; i++)
    {
        d[i]=d[i-1]+log(i);
    }
    return;
}
int main()
{
    precal();

    int t=0,n=0,b=0;
    scanf("%d", &t);

    for(int tc=1;tc<=t;tc++)
    {
        scanf("%d %d", &n, &b);
        if(!n)  printf("Case %d: 1\n", tc);
        else    printf("Case %d: %d\n", tc, (int)(d[n]/log(b)+1.0));
    }
    return 0;
}
