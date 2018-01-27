#include <stdio.h>
#define N 100
int main(){
    int n=0,k=0,a[N]={},i=0,j=0,max=0, val=0, cnt=0;
    scanf("%d %d", &n, &k);
    for (i=0; i<n; i++)
        scanf("%d", &a[i]);
    for (i=0; i<n-1; i++){
        for (j=i; j<n; j++){
            if (i!=j){
                val=a[i]+a[j];
                if (!(val%k))
                    cnt++;
            }
        }
        if (cnt>max)    max=cnt;
    }
    printf("%d",max);
    return 0;
}
