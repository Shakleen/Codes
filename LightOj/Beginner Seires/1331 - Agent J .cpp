#include <bits/stdc++.h>

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        double r1 = 0, r2 = 0, r3 = 0;

        scanf("%lf %lf %lf", &r1, &r2, &r3);

        double a = r2+r3, b = r1+r3, c = r1+r2,
               s = (a+b+c)/2, area = sqrt(s*(s-a)*(s-b)*(s-c)),
               A = acos((b*b+c*c-a*a)/(2*b*c)),
               B = acos((c*c+a*a-b*b)/(2*a*c)),
               C = acos((a*a+b*b-c*c)/(2*a*b)),
               areaA = ((r1*r1)*A)/2,
               areaB = ((r2*r2)*B)/2,
               areaC = ((r3*r3)*C)/2;

        printf("Case %d: %.10lf\n", cs, area-areaA-areaB-areaC);
    }


    return 0;
}
