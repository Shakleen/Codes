#include <stdio.h>

int main(){
    int n,i,x,y,flagx=1,flagy=1;
    x=y=i=0;
    scanf("%d", &n);
    scanf("%d %d", &x, &y);
    int cmpx=x, cmpy=y;
    for (i=1; i<=n; i++){
        if (x!=cmpx)
            flagx=0;
        if (y!=cmpy)
            flagy=0;
        if (i!=n)
        scanf("%d %d", &x, &y);
    }
    if (flagx || flagy)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
