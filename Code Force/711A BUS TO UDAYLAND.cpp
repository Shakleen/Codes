#include <bits/stdc++.h>

int main(){
    int n,i,j,cnt=0,match=0;
    scanf("%d", &n);
    char str[n+2][6], emp='O';
    for (i=0; i<n; i++){
        scanf("%s", str[i]);
        if (!match){
            for (j=0; j<6; j++){
                if(str[i][j]==emp)  cnt++;
                else                cnt=0;
                if (cnt==2){
                    str[i][j-1]='+';
                    str[i][j]='+';
                    match=1;
                    break;
                }
            }
        }
    }
    if(match){
        printf("YES\n");
        for (i=0; i<n; i++)
            printf("%s\n",str[i]);
    }
    else
        printf("NO");
    return 0;
}
