#include <bits/stdc++.h>

int main(){
    int n;
    scanf("%d", &n);
    int r=0,c=0,i=0,m=0;
    for(i=0; i<n; i++){
        scanf("%d", &m);
        if(m==-1){
            if(!r)  c++;
            else    r--;
        }
        else
            r+=m;
    }
    printf("%d",c);
    return 0;
}
