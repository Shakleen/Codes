#include <stdio.h>

int main(){
    int n=0, h[51]={},j=1;
    while (1){
        scanf("%d", &n);
        if (n==0)   break;
        int i=0,sum=0,moves=0;
        for (i=0; i<n; i++){
            scanf("%d", &h[i]);
            sum+=h[i];
        }
        int avg=sum/n;
        for (i=0; i<n; i++){
            if (h[i]>avg)
                moves+=(h[i]-avg);
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",j,moves);
        j++;
    }

    return 0;
}
