#include <bits/stdc++.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[n+2],b[n+2],flag=0;

    for (int i=0; i<n; i++){
        scanf("%d %d",&b[i], &a[i]);
        if (a[i]!=b[i]) flag=1;
    }
    if (flag){
        printf("rated");
    }
    else{
        int f=0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if (a[j]>a[i]){
                    f=1;
                    break;
                }
            }
            if (f)  break;
        }
        if (f){
            printf("unrated");
        }
        else{
            printf("maybe");
        }
    }
    return 0;
}
