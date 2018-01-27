#include <bits/stdc++.h>
using namespace std;
int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        string str;
        int y = 0, z = 0;

        cin >> str;

        for (int i = 0; i < str.size()-1; i++){
            if (str[i] == 'S'){
                if (str[i] == str[i+1]) y++;
                else                    z++;
            }
        }

        printf("Case %d: %d / %d\n", cs, y, z);
    }

    return 0;
}
