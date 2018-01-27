#include <bits/stdc++.h>
using namespace std;
int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int n = 0, r = 0, mx = INT_MIN;
        char name[10000] = {}, best[10000] = {};

        scanf("%d", &n);

        for (int i = 1; i <= n; i++){
            scanf(" %s %d", name, &r);

            if (r >= mx){
                if (r > mx || strcmp(name, best) == 1){
                    strcpy(best, name);
                }

                mx = r;
            }
        }

        printf("Case %d: %s is ", cs, best);

        if (mx >= 1600){
            printf("Expert!.");
        }
        else if (mx >= 1400){
            printf("Specialist!.");
        }
        else if (mx >= 1200){
            printf("Pupil!.");
        }
        else{
            printf("Newbie!.");
        }

        if (cs != t)    printf("\n");
    }



    return 0;
}
