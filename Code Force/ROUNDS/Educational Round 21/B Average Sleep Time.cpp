#include <bits/stdc++.h>

int main(){
    int n=0,k=0,j=0;

    scanf("%d %d", &n, &k);

    double sum=0, div=0, a=0, dis=n-k+1;;
    for(int i=1; i<=n; i++){
        scanf("%lf", &a);
        sum+=a;
        j++;
        if (j==k && i!=n){
            sum+=a;
            j=1;
        }
    }
    div=sum/dis;
    printf("%.10lf",div);

    return 0;
}
