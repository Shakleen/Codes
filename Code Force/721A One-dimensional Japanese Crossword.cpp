#include <bits/stdc++.h>

int main(){
    int n=0,cnt=0;
    bool w=0;
    scanf("%d", &n);
    char str[n+2],no[n+2]={};

    scanf("%s", str);

    for(int i=0; i<n; i++){
        if (i==0){
            if (str[i] == 'W'){
                w=1;
                cnt=0;
            }
            else{
                cnt=1;
                w=0;
                no[cnt-1]++;
            }
        }
        else{
            if (w){
                if (str[i] == 'B'){
                    cnt++;
                    no[cnt-1]++;
                    w=0;
                }
            }
            else{
                if (str[i] == 'W'){
                    w=1;
                }
                else{
                    no[cnt-1]++;
                }
            }
        }
    }

    printf("%d\n", cnt);

    for(int i=0; i<cnt; i++)    printf("%d ",no[i]);

    return 0;
}
