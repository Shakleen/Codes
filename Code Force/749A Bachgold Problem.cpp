#include <bits/stdc++.h>

int main(){
    int n = 0, cnt = 0;

    scanf("%d", &n);

    if ( !(n%2) ){
        int  no = n/2;

        printf("%d\n",no);

        for (int i = 1; i <= no; i++){
            printf("2 ");
        }
    }
    else{
        int no = n/2;

        printf("%d\n",no);

        for (int i = 1; i < no; i++){
            printf("2 ");
        }

        printf("3");
    }

    return 0;
}
