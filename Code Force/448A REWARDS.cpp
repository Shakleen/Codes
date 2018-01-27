#include <bits/stdc++.h>

int main(){
    int a1,a2,a3,b1,b2,b3,n;
    scanf("%d %d %d %d %d %d %d",&a1,&a2,&a3,&b1,&b2,&b3,&n);
    int c=(a1+a2+a3)%5,me=(b1+b2+b3)%10,m=(a1+a2+a3)/5+(b1+b2+b3)/10;
    if(c)   m++;
    if(me)  m++;
    if(m<=n)    printf("YES");
    else        printf("NO");
    return 0;
}
