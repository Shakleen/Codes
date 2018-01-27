#include <bits/stdc++.h>

int main(){
    int l = 0, st [10] = {};
    bool flag = false, elephant = false;

    for (int i = 0; i < 6; i++){
        scanf("%d", &l);
        st[l]++;
    }

    for (int i = 0; i < 10; i++){
        if ( st[i] >= 4 ){
            flag = true;
            st [i] -= 4;
            break;
        }
    }

    for (int i = 0; i < 10; i++){
        if ( st[i] == 2 ){
            elephant = true;
            break;
        }
    }

    if ( flag ){
        if ( elephant ){
            printf("Elephant");
        }
        else{
            printf("Bear");
        }
    }
    else{
        printf("Alien");
    }
    return 0;
}
