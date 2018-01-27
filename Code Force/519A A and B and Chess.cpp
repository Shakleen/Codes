#include <bits/stdc++.h>

int main(){
    int i=0,j=0,bw=0,ww=0;
    char str[10]={};
    for(i=0; i<8; i++){
        scanf("%s", str);
        for(j=0; j<8; j++){
            if (str[j] == 'K' || str[j] == 'k')
                continue;
            else if (str[j] == 'Q') ww+=9;
            else if (str[j] == 'q') bw+=9;
            else if (str[j] == 'R') ww+=5;
            else if (str[j] == 'r') bw+=5;
            else if (str[j] == 'B') ww+=3;
            else if (str[j] == 'b') bw+=3;
            else if (str[j] == 'N') ww+=3;
            else if (str[j] == 'n') bw+=3;
            else if (str[j] == 'P') ww+=1;
            else if (str[j] == 'p') bw+=1;
        }
    }
    if (bw>ww)          printf("Black");
    else if (bw<ww)     printf("White");
    else                printf("Draw");

    return 0;
}
