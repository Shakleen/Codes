#include <bits/stdc++.h>

int main(){
    int n,i,length=0,cnt1=0, cnt0=0;
    scanf("%d", &n);
    char num[n+2];
    scanf("%s", num);
    for(i=0; i<n; i++){
        if (num[i] == '1')       cnt1++;
        else                     cnt0++;
    }
    if (cnt1 == cnt0){
        printf("0");
        return 0;
    }
    else{
        if (cnt1>cnt0)  length=cnt1-cnt0;
        else            length=cnt0-cnt1;
        printf("%d", length);
    }
    return 0;
}
