#include <bits/stdc++.h>

int main(){
    int k=0,a[12]={},mn=0, i=0, mx=0;
    scanf("%d", &k);
    for(i=0; i<12; i++){
        scanf("%d", &a[i]);
        mx+=a[i];
    }
    if (k>mx){
        printf("-1");
        return 0;
    }
    std::sort(a,a+12);
    i=0;
    while(k>0){
        k-=a[11-i];
        i++;
    }
    printf("%d", i);
    return 0;
}
