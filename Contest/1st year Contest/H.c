#include <stdio.h>
#include <string.h>

int main(){
    char user[101], enter[101];
    scanf("%s %s", &user, &enter);
    int i=0, cnt=0, ul=strlen(user), el=strlen(enter), j=0;
    if (el<8)
        printf("no");
    else if (ul-el>1)
        printf("no");
    else{
        if (!(ul-el)){
            for (i=0; i<ul; i++){
                if (user[i]!=enter[i]){
                    cnt++;
                }
                if (cnt>1)
                    break;
            }
            if (cnt<=1)
                printf("yes");
            else
                printf("no");
        }
        else{
            for (i=0; i<ul; i++){
                if (user[i]==enter[j]){
                    j++;
                }
                else if (user[i]!=enter[j]){
                    cnt++;
                }
                if (cnt>1)
                    break;
            }
            if (cnt<=1)
                printf("yes");
            else
                printf("no");
        }
    }
    return 0;
}
