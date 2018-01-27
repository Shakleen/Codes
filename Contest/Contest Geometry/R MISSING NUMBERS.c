#include <stdio.h>
int a[1000010],b[1000010],r[201];
int main(){
    int n,m,i,j;
    scanf("%d", &n);
    for (i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (i=0; i<m; i++){
        scanf("%d", &b[i]);
    }
    int p=a[0];
    for (i=0; i<n; i++){
        int d=a[i]-p;
        r[100+d]--;
    }
    for (i=0; i<m; i++){
        int d=b[i]-p;
        r[100+d]++;
    }
    for (i=0; i<201; i++){
        if (r[i]>0){
            printf("%d ", i-100+p);
        }
    }
    return 0;
}
