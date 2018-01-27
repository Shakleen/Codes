#include <bits/stdc++.h>

int main(){
    int n=0, x=0, sum=0, a=0;

    scanf("%d %d", &n, &x);

    for (int i=0; i<n; i++){
        scanf("%d", &a);
        sum += a;
    }

    if (sum < 0)    sum *= (-1);

    if (sum == 0){
        printf("0");
    }
    else if (sum < x){
        printf("1");
    }
    else{
        int cnt = sum/x;
        if (sum%x)  cnt++;

        printf("%d", cnt);
    }
    return 0;
}
