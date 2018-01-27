#include <stdio.h>
#include <math.h>

int main(){
    int r,x,y,_x,_y;
    scanf("%d %d %d %d %d", &r, &x, &y, &_x, &_y);
    if (x==_x && y==_y)
        printf("0");
    else{
        int  cnt=0;
        double distance=sqrt(pow(x-_x,2)+pow(y-_y,2));
        while (distance>0){
            distance-=2*r;
            cnt++;
        }
        printf("%d", cnt);
    }

    return 0;
}
