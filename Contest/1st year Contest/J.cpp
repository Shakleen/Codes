#include <stdio.h>
int main(){
    int n=10,i,sum=0;
    scanf("%d", &n);
    int a[n+5];
    for (i=0; i<n; i++){
        scanf("%d", &a[i]);
        sum+=a[i];
    }
    printf("%d",sum);
    return 0;
}
