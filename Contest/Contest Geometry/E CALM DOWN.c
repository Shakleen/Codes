#include <stdio.h>
#include <math.h>

int main(){
    int t,i,j;
    double pi=2*acos(0), n, R, r, rad, flag;
    scanf("%d", &t);
    for (i=0; i<t; i++){
        scanf("%lf %lf", &R, &n);
        rad=pi/n;
        r=(R*sin(rad))/(1+sin(rad));
        j = (int) r;
        flag = (r*1.0)/j;
        if(flag!=1)
            printf("Case %d: %.10lf\n", i+1, r);
        else
            printf("Case %d: %.0lf\n", i+1, r);
    }
    return 0;
}
