#include <stdio.h>
#include <math.h>

#define pi acos(-1)

int main(){
    int t=0, i=0;
    scanf("%d", &t);
    for (i=0; i<t; i++){
        double r1,r2,r3;
        scanf("%lf %lf %lf", &r1, &r2, &r3);
        double a=r2+r3, b=r1+r3, c=r1+r2,
            angA=acos((b*b+c*c-a*a)/(2*b*c)),
            angB=acos((a*a+c*c-b*b)/(2*a*c)),
            angC=acos((a*a+b*b-c*c)/(2*b*a)),
            areaA=(r1*r1*angA)/2,
            areaB=(r2*r2*angB)/2,
            areaC=(r3*r3*angC)/2,
            s=(a+b+c)/2,
            areatotal=sqrt(s*(s-a)*(s-b)*(s-c));
        printf("Case %d: %.10lf\n", i+1, areatotal-areaA-areaB-areaC);
    }
    return 0;
}
