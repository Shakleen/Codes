#include <bits/stdc++.h>

int main(){
    int n;
    scanf("%d", &n);
    int c[n+2],i,mx=0,money=0;
    for(i=0; i<n; i++){
        scanf("%d", &c[i]);
        if (c[i]>mx)    mx=c[i];
    }
    if(n==1){
        printf("0");
        return 0;
    }

    for(i=0; i<n; i++)      money+=(mx-c[i]);

    printf("%d", money);
    return 0;
}
