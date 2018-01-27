#include <bits/stdc++.h>
#define N 101
char s[N],slo[N],shi[N];
int main(){
    int locnt=0, hicnt=0, i=0;
    scanf("%s", &s);
    for (i=0; i<strlen(s); i++){
        if (islower(s[i]))
            locnt++;
        else if (isupper(s[i]))
            hicnt++;
        shi[i]=toupper(s[i]);
        slo[i]=tolower(s[i]);
    }
    if (locnt>=hicnt)
        printf("%s",slo);
    else
        printf("%s",shi);
    return 0;
}
