#include <bits/stdc++.h>

int main(){
    int d1,d2,d3,tdis=0,mx=0;
    scanf("%d %d %d", &d1, &d2, &d3);
    if (d1>d2){
        mx=d1;
        tdis=d2;
    }
    else{
        mx=d2;
        tdis=d1;
    }
    if (d1+d2>=d3)              tdis+=d3;
    else                        tdis+=d1+d2;
    if (mx<=(d3+d2+d1-mx))      tdis+=mx;
    else                        tdis+=(d3+d2+d1-mx);
    printf("%d",tdis);
    return 0;
}
