#include <bits/stdc++.h>
#define N 101
int main(){
    int n=0, t=0;
    scanf("%d %d", &n, &t);
    if (t==10 && n==1)
        printf("%d", -1);
    else if (t<10 && n==1)
        printf("%d", t);
    else{
        char num[N]={};
        int i=0;
        if (t<10){
            for (i=0; i<n; i++)
                num[i]=48+t;
            printf("%s", num);
        }
        else{
            num[0]=49;
            for (i=1; i<n; i++)
                num[i]=48;
            printf("%s", num);
        }
    }
    return 0;
}
