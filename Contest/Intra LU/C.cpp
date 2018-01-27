#include <bits/stdc++.h>

using namespace std;

int main(){
    int t = 0;

    scanf("%d", &t);

    while (t--){
        int n = 0, m = 0;

        scanf("%d %d", &n, &m);

        for (int i = 1; i <= m; i++){
            int p = 0, q = 0, r = 0, g = 0;

            scanf("%d %d", &p, &q);

            if (p != q){
                r = (q/2)-(p/2);
                g = r;

                if ( !(p%2) ){
                    g++;
                }
                if ( q%2 ){
                    r++;
                }
            }
            else{
                if (p%2){
                    r = 1;  g = 0;
                }
                else{
                    g = 1;  r = 0;
                }
            }

            printf("%d %d", r, g);

            if (t || i != m){
                printf("\n");
            }
        }
    }


    return 0;
}
