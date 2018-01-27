#include <bits/stdc++.h>

int main(){
    int n;
    scanf("%d", &n);
    int i=0, c=0, m=0, cw=0, mw=0;
    for(i=0; i<n; i++){
        scanf("%d %d", &m, &c);
        if(c==m)        continue;
        else if(c>m)    cw++;
        else            mw++;
    }
    if(cw>mw)       printf("Chris");
    else if(mw>cw)  printf("Mishka");
    else            printf("Friendship is magic!^^");
    return 0;
}
