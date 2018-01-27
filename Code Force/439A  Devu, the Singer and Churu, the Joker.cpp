#include <bits/stdc++.h>

int main(){
    int n,d,i;
    scanf("%d %d", &n, &d);
    int t,tym=10*(n-1),jokes=tym/5;
    for(i=0; i<n; i++){
        scanf("%d", &t);
        tym+=t;
    }
    if (tym>d){
        printf("-1");
        return 0;
    }
    jokes+=((d-tym)/5);
    printf("%d", jokes);
    return 0;
}
