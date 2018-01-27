#include <bits/stdc++.h>

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int ax,ay,bx,by,cx,cy,dx,dy,area;
        ax=ay=bx=by=cx=cy=dx=dy=area=0;

        scanf("%d %d %d %d %d %d",
              &ax, &ay, &bx, &by, &cx, &cy);

        dx = ax + cx - bx;
        dy = ay + cy - by;

        area = abs((ax*by+bx*cy+cx*dy+dx*ay)-(ay*bx+by*cx+cy*dx+dy*ax))/2;

        printf("Case %d: %d %d %d\n", cs, dx, dy, area);
    }

    return 0;
}
