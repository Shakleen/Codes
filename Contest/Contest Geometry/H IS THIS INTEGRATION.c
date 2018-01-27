#include <stdio.h>
#include <math.h>

#define pi acos(-1)
int main(){
    double a=0;
    while (scanf("%lf", &a)!=EOF){
        double z=(a*a)*(1.0-pi/6.0-sqrt(3)/4.0),
               y=a*a-(a*a*pi)/4.0-2*z,
               x=a*a-4*y-4*z;
               printf("%.3lf %.3lf %.3lf\n", x, 4*y, 4*z);
    }

    return 0;
}
