#include <bits/stdc++.h>

int main(){
    int n;
    scanf("%d", &n);

    int h,m,t[n+2]={},cnt=1,mx=1;

    for(int i=0; i<n; i++){
        scanf("%d %d", &h, &m);

        t[i]=h*60+m;

        if (i==0){
            continue;
        }

        if (t[i]==t[i-1]){
            cnt++;

            if (cnt>mx){
                mx=cnt;
            }
        }
        else{
            cnt=1;
        }
    }

    printf("%d", mx);

    return 0;
}
