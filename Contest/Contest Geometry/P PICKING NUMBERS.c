#include <stdio.h>
#include <math.h>
#define N 100

int main(){
    int n=0, a[N]={}, i=0, j=0, cmpno=0, max=0;
    scanf("%d", &n);
    for (i=0; i<n; i++)
        scanf("%d", &a[i]);
    for (i=0; i<n; i++){
        int cntpos=1, cntneg=1;
        cmpno=a[i];
        for (j=0; j<n; j++){
            int val=a[j]-cmpno;
            if(i!=j && (val>=-1&&val<=1)){
                if(val>=0)
                    ++cntpos;
                else if (val<=0)
                    ++cntneg;
            }
        }
        if (cntpos>max)         max=cntpos;
        else if (cntneg>max)    max=cntneg;
    }
    printf("%d", max);
    return 0;
}
