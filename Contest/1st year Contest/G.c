#include <stdio.h>

int main(){
    int n=0,i=0,max=0,j=0,cnt=1,lcnt=0;
    scanf("%d", &n);
    long long int h=0;
    for (i=0; i<n; i++){
        scanf("%I64d", &h);
        if (h>=max){
            if (h>max){
                j=i+1;
                cnt=1;
                max=h;
            }
            else
                cnt++;
        }
    }
    if (cnt>1)
        printf("%d", -1);
    else
        printf("%d", j);
    return 0;
}
