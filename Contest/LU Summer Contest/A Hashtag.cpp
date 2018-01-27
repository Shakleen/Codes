#include <bits/stdc++.h>

int main(){
    char str[102] = {}, str2[101] = {};

    gets(str);

    int j = 0;

    for (int i = 0, len = strlen(str); i < len; i++){
        if (str[i] != ' '){
            str2[j++] = str[i];
        }
    }

    str2[j] = '\0';

    printf("%s", str2);

    return 0;
}
