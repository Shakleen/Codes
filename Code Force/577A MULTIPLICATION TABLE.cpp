#include <bits/stdc++.h>

int main(){
    int n,x,i,cnt=0;
    scanf("%d %d", &n, &x);
    double val=sqrt(x);
    for(i=1;i<=val;i++){
        if(!(x%i)){
            if(i<=n && (x/i)<=n){
                cnt++;
                if(i!=(x/i))    cnt++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}
