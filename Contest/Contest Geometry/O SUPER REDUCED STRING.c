#include <stdio.h>
#include <string.h>

#define N 100
int main(){
    char str[101]={},final_str[N]={};
    int i=0, j=0, cnt=0;
    scanf("%s", &str);
    start:
    for (i=0; i<strlen(str); i++){
        if (str[i]!=1){
            char ch=str[i];
//            printf("ch=%c outer_i=%d ", ch,i);
            for(j=i+1; j<strlen(str); j++){
                if (str[j]!=1){
                    if (ch==str[j]){
                        str[i]=1;
                        str[j]=1;
                        cnt++;
                        goto start;
                    }
//                    printf("inner_i=%d cnt=%d\n", i);
                    break;
                }
            }
        }
    }
    if ((double)cnt==(double)strlen(str)/2)
        printf("Empty String");
    else{
        for (i=0,j=0; i<strlen(str); i++){
            if (str[i]!=1)
                final_str[j++]=str[i];
        }
        printf("%s\n", final_str);
    }
    return 0;
}
