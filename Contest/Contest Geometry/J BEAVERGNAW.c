#include <stdio.h>
#include <math.h>

#define PI acos(-1)

int main(){
    int D=0,v=0;
    while(scanf("%d %d",&D,&v)){
        if (D==0 && v==0)
            break;
        double d = pow(pow(D,3)-(6.0*v)/PI, 1.0/3.0);
        printf("%.3f\n", d);
    }
    return 0;
}
