#include <bits/stdc++.h>

using namespace std;

int main(){
    int g = 0;

    scanf("%d", &g);
    fflush(stdin);

    while (g--){
        int n = 0;

        scanf("%d", &n);
        fflush(stdin);

        char str [n+2] = {};
        int cnt [30] = {}, h = 1;


        map <char, int> mymap;

        scanf("%s", str);
        fflush(stdin);

        for (int i = 0; i <= n; i++){
            if (str[i] == '_'){
                cnt[0]++;
            }
            else{
                if (!mymap[str[i]]){
                    mymap[str[i]] = h++;
                }

                cnt[mymap[str[i]]]++;
            }
        }

        if (!cnt[0]){
            if (strlen(str) == 1){
                printf("NO\n");
            }
            else{
                bool f = true, fu = false;

                char ch = str[0];

                for (int i = 1; i < n; i++){
                    if (ch == str[i]){
                        fu = true;
                    }
                    else if (fu){
                        ch = str[i];
                        fu = false;
                    }
                    else{
                        f = false;
                        break;
                    }
                }

                if (f && fu){
                    printf("YES\n");
                }
                else{
                    printf("NO\n");
                }
            }
        }
        else{
            bool f = true;

            for (int i = 1; i < h-1; i++){
                if (cnt[i] < 2){
                    printf("NO\n");
                    f = false;
                    break;
                }
            }

            if (f){
                printf("YES\n");
            }
        }
    }


    return 0;
}
