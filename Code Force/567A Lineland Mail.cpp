#include <bits/stdc++.h>

int main(){
    int n,i;
    scanf("%d", &n);
    int x[n+2],mx,mn;
    for(i=0; i<n; i++)  scanf("%d", &x[i]);

    for(i=0; i<n; i++){
        if (i==0 || i==n-1){
            mx=x[n-1]-x[0];
            if (i==0)   mn=x[1]-x[0];
            else        mn=x[n-1]-x[n-2];
        }
        else{
            int j=x[i]-x[0], k=x[i]-x[i-1];
            mx=x[n-1]-x[i];
            mn=x[i+1]-x[i];
            if (j>mx)       mx=j;
            if (k<mn)       mn=k;
        }
        printf("%d %d\n", mn, mx);
    }

    return 0;
}
