#include <bits/stdc++.h>
#define N 100005
char str[N];
int main(){
    int T;
    scanf("%d", &T);

    while (T--){
        scanf("%s", str);
        int n=strlen(str),flag=0,sflag=0,eflag=0;
        for(int i=0; i<n; i++){
            if (i>0){
                if (sflag && str[i]!='S'){
                    flag=1;
                    break;
                }
                else{
                    if (str[i]=='E')
                        eflag=1;
                    else if (eflag && str[i]=='C'){
                        flag=1;
                        break;
                    }
                    else if (str[i]=='S')
                        sflag=1;
                }
            }
            else if (i==0 && str[i]!='C'){
                flag=1;
                break;
            }
        }
        if (flag)   printf("no\n");
        else        printf("yes\n");
    }

    return 0;
}
