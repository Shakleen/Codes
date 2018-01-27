#include <bits/stdc++.h>
#define N 100001
int main(){
    int n,i,d=0,a=0;
    char str[N]={};
    scanf("%d", &n);
    scanf("%s", &str);
    for (i=0; i<n; i++){
        if (str[i]=='A')        a++;
        else if (str[i]=='D')   d++;
    }
    if (a>d)        printf("Anton");
    else if (a<d)   printf("Danik");
    else            printf("Friendship");
    return 0;
}
