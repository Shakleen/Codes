#include <stdio.h>
#include <math.h>

int main(){
    double a,b,c;
    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF){
        double s = (a+b+c)/2, area, h=s*(s-a)*(s-b)*(s-c);
        area = (4.0/3.0)*(sqrt(h));
        if (area>0)
            printf("%.3lf\n", area);
        else{
            area=-1;
            printf("%.3lf\n", area);
        }
    }
    return 0;
}
