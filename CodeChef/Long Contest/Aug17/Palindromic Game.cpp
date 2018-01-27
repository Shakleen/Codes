#include <bits/stdc++.h>

using namespace std;

int main(){
    int t = 0;

    cin >> t;

    while (t--){
        string s, t;
        int smap[27], tmap[27];
        bool B = false, A = false, same = true;

        memset(smap, 0, sizeof(smap));
        memset(tmap, 0, sizeof(tmap));

        cin >> s >> t;

        for (int i = 0; ; i++){
            if (i < s.size()){
                smap[ s[i]-'a' ]++;
            }
            if (i < t.size()){
                tmap[ t[i]-'a' ]++;
            }

            if (i >= s.size() && i >= t.size()){
                break;
            }
        }
        for (int i = 0; i < 27; i++){
            if ((tmap[i] && !smap[i])||(smap[i] && !tmap[i])){
                same = false;
            }
            if (tmap[i]){
                if (!smap[i]){
                    B = true;
                }
            }

            if (smap[i]>1 && !tmap[i]){
                A = true;
            }
        }

        if ((B && !A) || same){
            printf("B\n");
        }
        else{
            printf("A\n");
        }
    }
    return 0;
}
