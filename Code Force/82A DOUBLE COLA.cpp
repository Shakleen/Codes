#include <bits/stdc++.h>

int main(){
    int n=0,m=0,i=0;
    scanf("%d", &n);
    for (i=1; ;i*=2){
        m+=5*i;
        if (m>=n)   break;
    }
    m-=5*i;
    n-=m;
    double p=(double)n/(double)i;
    if (p<=1)
        printf("Sheldon");
    else if (p<=2)
        printf("Leonard");
    else if (p<=3)
        printf("Penny");
    else if (p<=4)
        printf("Rajesh");
    else
        printf("Howard");

    return 0;
}
