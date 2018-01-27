#include <bits/stdc++.h>

int main(){
    char str[101]={};

    scanf("%s", str);

    int last=-1, length = strlen(str),dif=0, max=0;

    for (int i=0,cnt=0; i<=length; i++,cnt++){
        if (i == length){
            dif = i - last;
        }
        else{
            switch (str[i]){
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                case 'Y':
                    dif = i - last;
                    last = i;
                    break;
            }
        }

        if (dif > max){
            max = dif;
        }
    }

    printf("%d", max);

    return 0;
}
