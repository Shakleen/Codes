#include <bits/stdc++.h>

int main(){
    int n=0,m=0,a=0,max=-1,in=0;

    scanf("%d %d", &n, &m);

    int city[n+2]={};

    for (int i=1; i<=m; i++, max = -1){

        for(int j=0; j<n; j++){

            scanf("%d", &a);

            if (a>max){
                in = j;
                max = a;
            }
        }

        city[in]++;
    }

    for(int i=0; i<n; i++){

        if (city[i] > max){
            max = city[i];
            in = i;
        }

    }

    printf("%d", in+1);

    return 0;
}
