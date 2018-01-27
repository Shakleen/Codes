#include <bits/stdc++.h>

int main(){
    int n=0, max=0, cnt=0;

    scanf("%d", &n);

    int a[n]={};

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        max += a[i];
    }

    if (n == 2){
        printf("1 2\n");
    }
    else{
        int avg = (2*max)/n;

        for(int i=0; cnt != n; i++){

            if (a[i]){

                int k = avg - a[i];

                for (int j=0; j<n; j++){
                    if (a[j] == k && j != i && a[j]){
                        printf("%d %d\n", i+1, j+1);

                        a[j]=a[i]=0;
                        cnt += 2;

                        break;
                    }
                }
            }
        }
    }
    return 0;
}
