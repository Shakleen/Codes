#include <bits/stdc++.h>

int main(){
    int n=0, maxN=0, loN=10000, i=0, score=0, cnt=0;
    scanf("%d", &n);
    for (i=0; i<n; i++){
        scanf("%d", &score);
        if (score > maxN){
            maxN=score;
            if (i!=0)   cnt++;
        }
        if (score < loN){
            loN=score;
            if (i!=0)   cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
