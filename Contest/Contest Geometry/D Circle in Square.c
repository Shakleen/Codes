#include <stdio.h>
#include <math.h>

int main(){
    int n,i;
    double pi=2*acos(0), r;
    scanf("%d", &n);
    for (i=0; i<n; i++){
        scanf("%lf", &r);
        double area=pow(2*r,2)-(pi*pow(r,2))+10e-9;
        printf("Case %d: %.2lf\n", i+1, area);
    }
    return 0;
}
