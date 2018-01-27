#include <bits/stdc++.h>

#define pi 3.1416

using namespace std;

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        double r = 0;

        scanf("%lf", &r);

        double aC = pi*r*r*2, aR = 8*r*r, a = aR-aC;

        printf("Case %d: %.2lf", cs, a);

        if (cs != t){
            printf("\n");
        }
    }


    return 0;
}
