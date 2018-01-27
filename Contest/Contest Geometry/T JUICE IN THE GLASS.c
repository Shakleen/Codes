#include <stdio.h>
#include <math.h>
#define pi acos(-1)

int main(){
    int t=0,i=0,r1=0,r2=0,h=0,p=0;
    double r3=0, vol=0;
    scanf("%d", &t);
    for (i=1; i<=t; i++){
        scanf("%d %d %d %d", &r1, &r2, &h, &p);
        r3=r2+(r1-r2)*((double)p/h);
        vol=(1.0/3.0)*pi*p*(r3*r3+r3*r2+r2*r2);
        printf("Case %d: %.9lf\n", i, vol);
    }

    return 0;
}
