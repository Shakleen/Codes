#include <bits/stdc++.h>

int main(){
    int n,k,i,y,cnt=0,teams=0;
    scanf("%d %d", &n, &k);
    for (i=0; i<n; i++){
        scanf("%d", &y);
        if (5-y>=k)
            cnt++;
        if (cnt==3){
            teams++;
            cnt=0;
        }
    }
    printf("%d", teams);
    return 0;
}
