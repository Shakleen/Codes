#include <bits/stdc++.h>

int main(){
    long long x;
    scanf("%I64d", &x);
    int num[19]={};
    int i=0;
    for(i=0; x>0; i++){
        int n=x%10;
        x/=10;
        if (n>=5){
            n=9-n;
            if (x==0 && n==0)
                n+=9;
        }
        num[i]=n;
    }
    x=0;
    int j=i;
    for (i=j-1; i>=0; i--){
        x+=num[i];
        if (i!=0)   x*=10;
    }
    printf("%I64d",x);
    return 0;
}

