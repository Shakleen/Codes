#include <bits/stdc++.h>

using namespace std;

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int n = 0;

        scanf("%d", &n);

        int vol = 0, no = 1, mn = INT_MAX, mx=INT_MIN,
            mni = 0, mxi = 0;
        char name [n+1][22];

        for (int i = 0; i < n; i++){
            int l = 0, w = 0, h = 0;

            scanf("%s %d %d %d", &name[i], &l, &w, &h);

            vol = l*w*h;

            if (vol > mx){
                mx = vol;
                mxi = i;
            }
            if (vol < mn){
                mn = vol;
                mni = i;
            }
        }

        if (mx == mn){
            printf("Case %d: no thief\n", cs);
        }
        else{
            printf("Case %d: %s took chocolate from %s\n", cs, name[mxi], name[mni]);
        }
    }


    return 0;
}
