#include <stdio.h>
#include <math.h>
#define pi 2*asin(0.0)
int main(){
    int t,i;
    scanf("%d", &t);
    for (i=0; i<t; i++){
        double ox,oy,ax,ay,bx,by;
        scanf("%d %lf %lf %lf %lf %lf", &ox,&oy,&ax,&ay,&bx,&by);
        double r=sqrt(pow(ox-ax,2)+pow(oy-ay,2)), d=sqrt(pow(bx-ax,2)+pow(by-ay,2));
        double angle = (acos((2*r*r-d*d)/(2*r*r)));
        double arc_length=r*angle;
        printf("Case %d: %.8lf\n", i+1, arc_length);
    }
    return 0;
}
