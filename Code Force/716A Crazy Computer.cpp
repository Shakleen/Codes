#include <bits/stdc++.h>

int main(){
    int n,c,flag=1,l,m,cnt=0,i;
    scanf("%d %d", &n, &c);
    for(i=0;i<n;i++){
        if (!i){
            scanf("%d", &l);
            cnt=1;
            continue;
        }
        if(flag){
            flag=0;
            scanf("%d",&m);
        }
        else{
            flag=1;
            scanf("%d", &l);
        }
        if (abs(m-l)>c){
            cnt=1;
        }
        else{
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
