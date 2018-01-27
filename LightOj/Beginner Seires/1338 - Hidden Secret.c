#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int t = 0, cs = 0, i = 0;

    scanf("%d ", &t);

    for (cs = 1; cs <= t; cs++){
        char n1 [120] = {}, n2 [120] = {};

        gets(n1);        gets(n2);

        int s1 = strlen(n1), s2 = strlen(n2), a [27] = {}, flag = 0, max = s2;

        if (s1 > s2)    max = s1;

        for (i = 0; i < max; i++){
            if (i < s1){
                if (n1[i] != ' '){
                    if (n1[i] < 91) a[n1[i]-65]++;
                    else            a[n1[i]-97]++;
                }
            }
            if (i < s2){
                if (n2[i] != ' '){
                    if (n2[i] < 91) a[n2[i]-65]--;
                    else            a[n2[i]-97]--;
                }
            }
        }

        for (i = 0; i < 27; i++){
            if (a[i] != 0){
                flag = 1;
                break;
            }
        }

        if (flag){
            printf("Case %d: No\n", cs);
        }
        else{
            printf("Case %d: Yes\n", cs);
        }
    }


    return 0;
}
