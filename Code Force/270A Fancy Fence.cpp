#include <bits/stdc++.h>

int main(){
    int t,a;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &a);
        a=180-a;
        if (!(360%a))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
