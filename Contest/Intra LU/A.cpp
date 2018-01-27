#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 0;

    scanf("%d", &n);

    if (n <= 3){
        printf("NO PUNISHMENT\n");
    }
    else{
        int flag = 1, len = sqrt(n)+1;

        for (int i = 2; i <= len; i++){
            if ( !(n%i) ){
                flag = 0;
                break;
            }
        }

        if (flag){
            printf("NO PUNISHMENT\n");
        }
        else{
            for (int i = 1; i <= n; i++){
                printf("I DID NOT DO THE ASSIGNMENT.\n");
            }
        }
    }

    return 0;
}
