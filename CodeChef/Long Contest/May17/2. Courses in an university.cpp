#include <bits/stdc++.h>

int main(){
    int t,n;
    scanf("%d", &t);

    while (t--){
        scanf("%d", &n);
        int a=0,cnt=0,j=0;
        for(int i=0; i<n; i++){
            scanf("%d", &a);
            if (a>j) j=a;
        }
        cnt=n-j;
        printf("%d\n",cnt);
    }

    return 0;
}
