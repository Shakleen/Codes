#include <stdio.h>
#include <math.h>

#define N 100
int main(){
    int t,i,j,x1,x2,y1,y2,m,mx[N]={},my[N]={};
    t=i=j=x1=x2=y1=y2=m=0;
    scanf("%d", &t);
    for (i=0; i<t; i++){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &m);
        printf("Case %d:\n", i+1);
        for (j=0; j<m; j++){
            scanf("%d %d", &mx[j], &my[j]);
            if ((mx[j]>x1&&mx[j]<x2) && (my[j]>y1&&my[j]<y2))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
