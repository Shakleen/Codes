#include <bits/stdc++.h>

#define pi 2*acos(0.0)

using namespace std;

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int i = 1; i <= t; i++){
        double r = 0;

        scanf("%lf", &r);

        printf("Case %d: %.2lf\n", i, r*r*(4.0-pi));
    }




    return 0;
}
