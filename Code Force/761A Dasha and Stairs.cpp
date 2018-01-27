#include <bits/stdc++.h>

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)

int main(){
    int a=0, b=0;

    scan2(a,b);

    if (a == b || abs(a-b) <= 1){
        if(a || b)
            printf("YES");
        else
            printf("NO");
    }
    else{
        printf("NO");
    }

    return 0;

}
