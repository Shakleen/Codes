#include <bits/stdc++.h>

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        double ox, oy, ax, ay, bx, by;

        ox=oy=ax=ay=bx=by=0;

        scanf("%lf %lf %lf %lf %lf %lf",
              &ox, &oy, &ax, &ay, &bx, &by);

        double A = sqrt((ox-ax)*(ox-ax) + (oy-ay)*(oy-ay)),
               B = sqrt((ox-bx)*(ox-bx) + (oy-by)*(oy-by)),
               C = sqrt((bx-ax)*(bx-ax) + (by-ay)*(by-ay)),
               AOB = (A*A+B*B-C*C)/(2*A*B), angAOB = acos(AOB),
               s = angAOB * A;

        printf("Case %d: %.8lf\n", cs, s);
    }

    return 0;
}
