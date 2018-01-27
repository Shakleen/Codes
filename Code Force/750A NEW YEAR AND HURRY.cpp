#include <bits/stdc++.h>

int main(){
    int n,k;
    scanf("%d %d", &n, &k);
    int t=240-k;
    if (t>=5){
        int i=1;
        while(1){
            t-=5*i;
            if (t<5*(i+1) || i==n)
                break;
            i++;
        }
        printf("%d", i);
    }
    else
        printf("%d", 0);
    return 0;
}
