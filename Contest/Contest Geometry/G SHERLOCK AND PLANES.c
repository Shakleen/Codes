#include <stdio.h>

int main(){
    int t=0;
    scanf("%d", &t);
    while(t--){
        int x[4],y[4],z[4],i,j,a[3],b[3],c[3];
        for (i=0; i<4; i++)
            scanf("%d %d %d", &x[i], &y[i], &z[i]);
        for (i=1; i<4; i++){
            a[i-1]=x[i]-x[0];
            b[i-1]=y[i]-y[0];
            c[i-1]=z[i]-z[0];
        }
        j=a[0]*(b[1]*c[2]-b[2]*c[1])-b[0]*(a[1]*c[2]-a[2]*c[1])+c[0]*(a[1]*b[2]-a[2]*b[1]);
        if (j)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
