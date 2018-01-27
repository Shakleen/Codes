#include <bits/stdc++.h>

using namespace std;

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int n = 0, lox,hix,loy,hiy,loz,hiz;
        lox=loy=loz=hix=hiy=hiz=0;
        bool f = true;

        scanf("%d", &n);

        for (int j = 1; j <= n; j++){
            int x1,x2,y1,y2,z1,z2;
            x1=x2=y1=y2=z1=z2=0;

            scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);

            if (j == 1){
                lox = x1;   loy = y1;   loz = z1;
                hix = x2;   hiy = y2;   hiz = z2;
            }
            else if ((x1>hix || y1>hiy || z1>hiz) || (x2<lox || y2<loy || z2<loz)){
                f = false;
            }

            if (f){
                lox = max(x1, lox);
                loy = max(y1, loy);
                loz = max(z1, loz);

                hix = min(x2, hix);
                hiy = min(y2, hiy);
                hiz = min(z2, hiz);
            }
        }

        if (f){
            long long vol = (hix-lox)*(hiy-loy)*(hiz-loz);

            printf("Case %d: %lld\n", cs, vol);
        }
        else{
            printf("Case %d: %d\n", cs, 0);
        }
    }

    return 0;
}
