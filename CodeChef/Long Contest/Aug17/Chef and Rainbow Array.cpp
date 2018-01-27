#include <bits/stdc++.h>

using namespace std;

int main(){
    int t = 0;

    scanf("%d", &t);

    while (t--){
        int n = 0;

        scanf("%d", &n);

        int a[n], num[8];
        bool f7 = false, no = false;
        memset(num, 0, sizeof(num));

        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);

            if ( !no ){
                if ( !i ){
                    num[a[i]]++;
                    continue;
                }
                if (a[i] > 7){
                    no = true;
                }
                if ( !f7 ){
                    if (a[i] < a[i-1]){
                        no = true;
                    }

                    num[a[i]]++;

                    if (a[i] == 7){
                        f7 = true;
                    }
                }
                else if (a[i] != 7){
                    if (a[i] > a[i-1]){
                        no = true;
                    }

                    num[a[i]]--;
                }
            }
        }

        if (!no){
            for (int i = 1; i < 7; i++){
                if (num[i]){
                    no = true;
                }
            }
        }

        if ( no ){
            printf("no\n");
        }
        else{
            printf("yes\n");
        }
    }

    return 0;
}
