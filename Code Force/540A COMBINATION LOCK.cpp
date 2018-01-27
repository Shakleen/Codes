#include <bits/stdc++.h>
#define N 1001
int main(){
    int n=0,i=0,moves=0;
    char ori[N]={}, comb[N]={};
    scanf("%d", &n);
    scanf("%s %s", &ori, &comb);
    for (i=0; i<n; i++){
        int o=ori[i]-48, c=comb[i]-48,a=0,b=0;
        if (o>c){a=o;   b=c;}
        else    {a=c;   b=o;}
        if (a-b>5)
            moves+=b+10-a;
        else
            moves+=a-b;
    }
    printf("%d", moves);
    return 0;
}
