#include <stdio.h>

int gcd(int a,int b){
    if (!(a%b)) return b;
    return gcd(b, a%b);
}

int main(){
    int n=0,i=0,j=0,G=0;
    while(scanf("%d", &n)!=EOF){
        if (!n) break;
        G=0;
        for (i=1; i<n; i++){
            for (j=i+1; j<=n; j++){
                G+=gcd(i,j);
            }
        }
        printf("%d\n",G);
    }
    return 0;
}
