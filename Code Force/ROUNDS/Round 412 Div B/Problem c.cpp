#include <bits/stdc++.h>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int x,y,p,q,m;
        scanf("%d %d %d %d", &x, &y, &p, &q);
        if ((x==0&&p==0)||(p==q&&x==y)){
            printf("0\n");
        }
        else if (p==0 || p==q){
            printf("-1\n");
        }
        else{
            int k;
            for(k=2; ; k++){
                int pk=p*k, qk=q*k;
                if (pk<x || qk<y) continue;
                if ((pk-x)<=(qk-y)){
                    m=qk-y;
                    break;
                }
            }
            printf("%d\n",m);
        }
    }
    return 0;
}
