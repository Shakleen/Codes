#include <bits/stdc++.h>

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    if(n<m) printf("%d", -1);
    else{
        int div=n/2, mod=n%2, flag=0;
        while(1){
            if((div+mod)%m==0){
                flag=1;
                break;
            }
            div--;
            mod+=2;
            if(!div){
                flag=1;
                break;
            }
        }
        if(flag)    printf("%d", div+mod);
        else        printf("%d", -1);
    }
    return 0;
}
