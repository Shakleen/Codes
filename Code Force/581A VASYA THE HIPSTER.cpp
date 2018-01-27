#include <bits/stdc++.h>
int same(int dif, int remain){
    if (remain<2)   return 0;
    return (remain/2);
}
int main(){
    int a=0,b=0,max_dif=0,max_same=0;
    scanf("%d %d", &a, &b);
    if (a<=b){
        max_dif=a;
        b-=max_dif;
        max_same=same(max_dif, b);
    }
    else if (a>b){
        max_dif=b;
        a-=max_dif;
        max_same=same(max_dif, a);
    }
    printf("%d %d", max_dif, max_same);
    return 0;
}
