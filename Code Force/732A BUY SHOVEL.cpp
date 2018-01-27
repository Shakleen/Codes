#include <bits/stdc++.h>

int main(){
    int k=0,r=0,i=1;
    scanf("%d %d", &k, &r);
    while (1){
        if((((k*i)%10)==0) || ((k*i)%10==r))
            break;
        i++;
    }
    printf("%d",i);
    return 0;
}
