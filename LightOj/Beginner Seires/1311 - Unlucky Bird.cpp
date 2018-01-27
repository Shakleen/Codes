#include <bits/stdc++.h>

using namespace std;

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs =1; cs <= t; cs++){
        double v1, v2, v3, a1, a2, d, s, t1, t2, t;
        v1=v2=v3=a1=a2=d=s=t1=t2=t=0;

        scanf("%lf %lf %lf %lf %lf", &v1, &v2, &v3, &a1, &a2);

        t1 = v1/a1; t2=v2/a2;
        d = ((v1*t1)-(a1*t1*t1)/2) + ((v2*t2)-(a2*t2*t2)/2);
        t = max (t1, t2);
        s = v3*t;

        printf("Case %d: %.10f %.10f\n", cs, d, s);
    }

    return 0;
}
