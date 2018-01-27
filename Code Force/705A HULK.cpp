#include <bits\stdc++.h>
#define N 1500
int main(){
    int n=0,i=0;
    char str[N]="I hate";
    scanf("%d", &n);
    while(i<n){
        if (i==n-1)
            strcat(str, " it");
        else if (i%2)
            strcat(str, " that I hate");
        else
            strcat(str, " that I love");
        i++;
    }
    printf("%s", str);
    return 0;
}
