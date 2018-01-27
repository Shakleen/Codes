#include <bits/stdc++.h>

#define pi 2*acos(0.0)

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        double r1, r2, h, p;
        r1=r2=h=p=0;

        scanf("%lf %lf %lf %lf", &r1, &r2, &h, &p);

        double x = (h*r2)/(r1-r2), r = ((p+x)*r2)/x,
               volpx = (pi*r*r*(p+x))/3.0,
               volx = (pi*r2*r2*x)/3.0,
               vol = volpx - volx;

        printf("Case %d: %.9lf\n", cs, vol);
    }

    return 0;
}
