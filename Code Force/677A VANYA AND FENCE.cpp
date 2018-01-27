#include <bits/stdc++.h>

int main(){
    int n=0,h=0,a=0,i=0,w=0;
    scanf("%d %d",&n,&h);
    for (i=0; i<n; i++){
        scanf("%d", &a);
        if (a>h)    w+=2;
        else        w++;
    }
    printf("%d", w);
    return 0;
}
