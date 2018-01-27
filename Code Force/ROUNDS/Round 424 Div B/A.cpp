#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 0;

    scanf("%d", &n);

    int a[n];
    bool in = false, con = false, de = false, flag = true;

    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);

        if ( !i ){
            continue;
        }
        else if (flag){
            if (a[i] > a[i-1]){
                if (!con && !de)    in = true;
                else                flag = false;
            }
            else if (a[i] == a[i-1]){
                if ( !de )          con = true;
                else                flag = false;
            }
            else{
                de = true;
            }
        }
        printf("in=%d con=%d de=%d flag=%d\n",in,con,de,flag);
    }


    if (flag){
        printf("YES");
    }
    else{
        printf("NO");
    }
    return 0;
}
