#include <bits/stdc++.h>

#define pi 2*acos(0.0)

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        double R = 0, r = 0, SIN = 0, n = 0, f = 0;

        scanf("%lf %lf", &R, &n);

        SIN = sin(pi/n);

        r = (R*SIN)/(1+SIN);

        f = r - (int)r;

        if (f){
            printf("Case %d: %.10f\n", cs, r);
        }
        else{
            printf("Case %d: %.0f\n", cs, r);
        }
    }


    return 0;
}
