#include <bits/stdc++.h>
#define N 10
int a[N][N];
int main(){
    int n=0, i=0,j=0;
    scanf("%d", &n);
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            if (i!=0 && j!=0)
                a[i][j]=a[i-1][j]+a[i][j-1];
            else
                a[i][j]=1;
        }
    }
    printf("%d", a[n-1][n-1]);
    return 0;
}
