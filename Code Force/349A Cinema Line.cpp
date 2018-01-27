#include <bits/stdc++.h>

int main(){
    int n = 0, p = 0, box [2] = {};
    bool flag = true;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++){
        scanf("%d", &p);

        if (flag){
            if (p == 25){
                box[0]++;
                continue;
            }
            else if (p == 50){
                box[1]++;

                if (box[0]){
                    box[0]--;
                }
                else{
                    flag = false;
                }
            }
            else{
                if (box[1] >= 1 && box[0] >=1){
                    box[1]--;
                    box[0]--;
                }
                else if (box[0] >= 3){
                    box[0]-=3;
                }
                else{
                    flag = false;
                }
            }
        }
    }

    if (flag){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}
