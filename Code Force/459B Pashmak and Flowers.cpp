#include <bits/stdc++.h>

int main(){
    long long n=0,b=0,mx=0,mn=0,mxcnt=0,mncnt=0,a1=0;
    scanf("%I64d", &n);
    for (int i=0; i<n; i++){
        scanf("%I64d", &b);
        if (i==0){
            mx=b;       mn=b;
            mxcnt=1;    mncnt=1;
        }
        else{
            if (b>mx){
                mx=b;
                mxcnt=1;
            }
            else if (b==mx){
                mxcnt++;
            }
            if (b<mn){
                mn=b;
                mncnt=1;
            }
            else if (b==mn){
                mncnt++;
            }
        }
    }
    if (mx==mn) a1=n*(n-1)/2;
    else        a1=mxcnt*mncnt;

    printf("%I64d %I64d",mx-mn,a1);
    return 0;
}
