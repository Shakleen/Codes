#include <bits/stdc++.h>
#define N 100001
int am[N];
int main(){
    int n,m,i,j;
    n=m=i=j=0;
    scanf("%d %d", &n, &m);
    for (i=0; i<m; i++){
        scanf("%d", &am[i]);
    }
/*
Here i controls loop which are the tasks to be done
     j controls the house numbers
     cnt controls the tasks finished
*/
    long long int cnt=0;
    for (i=0,j=1; i<m; i++){
        if (am[i]>=j)
            cnt+=am[i]-j;
        else
            cnt+=(n+am[i])-j;
        j=am[i];
    }
    printf("%I64d", cnt);
    return 0;
}
