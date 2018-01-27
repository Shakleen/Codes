#include <bits/stdc++.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[n+2], p[n+2], i=0, min_price=102, total_cost=0;
    for(i=0; i<n; i++){
        scanf("%d %d",&a[i], &p[i]);
        if(min_price>p[i])  min_price=p[i];
        total_cost+=a[i]*min_price;
    }
    printf("%d", total_cost);

    return 0;
}
