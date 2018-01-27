#include <bits/stdc++.h>
int mx(int a, int b){
    return a>b?a:b;
}
int mn(int a, int b){
    return a<b?a:b;
}
int main(){
    int n,a,b,c,i,j,mxN;
    n=a=b=c=i=j=mxN=0;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int x=mx(a, mx(b,c)), z=mn(a, mn(b,c)),
        y=a+b+c-x-z;
    for (i=0; i*x<=n; i++){
        for (j=0; i*x+j*y<=n; j++){
            int m=i*x+j*y;
            if ((n-m)%z==0){
                int sum=i+j+(n-m)/z;
                if (sum>mxN)
                    mxN=sum;
            }
        }
    }
    printf("%d", mxN);
    return 0;
}
