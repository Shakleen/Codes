#include <bits/stdc++.h>

int main(){
    int n = 0, m = 0;

    scanf("%d %d", &n, &m);

    char s[n+2] = {}, t[m+2] = {};

    scanf("%s %s", s, t);

    int sizes = strlen(s), sizet = strlen(t) - sizes,
        cnt = 0, min = INT_MAX, mini = 0;

    for (int i = 0; i <= sizet; i++,cnt = 0){
        for (int j = 0; j < sizes; j++){
            if (s[j] != t[i+j]){
                cnt++;
            }
        }

        if (cnt < min){
            min = cnt;
            mini = i;
        }
    }

    printf("%d\n", min);

    for (int i = mini, j = 0; j < sizes; i++, j++){
        if (s[j] != t[i]){
            printf("%d", j+1);
            min--;

            if (min){
                printf(" ");
            }
        }
    }

    return 0;
}
