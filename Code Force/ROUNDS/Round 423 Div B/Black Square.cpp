#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 0, m = 0;

    scanf("%d %d", &n, &m);

    int mx = 0, s_row = n, e_row = 0, s_col = m, e_col = 0, b = 0;

    for (int i = 0; i < n; i++){
        char str [m+2] = {};

        scanf("%s", str);

        for (int j = 0; str[j]; j++){
            if (str [j] == 'B'){
                b++;

                if (i < s_row)    s_row = i;
                if (j < s_col)    s_col = j;
                if (i > e_row)    e_row = i;
                if (j > e_col)    e_col = j;
            }
        }
    }

    mx = max(e_row - s_row + 1, e_col - s_col + 1);

    if (mx > n || mx > m){
        printf("-1");
    }
    else if (!b){
        printf("1");
    }
    else{
        int cnt = 0;

        cnt = mx*mx - b;

        printf("%d", cnt);
    }

    return 0;
}
