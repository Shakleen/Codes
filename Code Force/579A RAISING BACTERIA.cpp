#include <bits/stdc++.h>

int main(){
    int x;
    scanf("%d", &x);
    if(x==1){
        printf("%d", 1);
        return 0;
    }
    int i=0,no=1;
    while(1){
        no*=2;
        if(no>=x)    break;
    }
    if(no==x)   printf("%d", 1);
    else{//no>x
        no/=2;
        x-=no;
        int cnt=1;
        while(x>0){
            if(x==1){
                printf("%d", cnt+1);
                break;
            }
            no=1;
            cnt++;
            while(1){
                no*=2;
                if(no>=x)    break;
            }
            if(no==x){
                printf("%d", cnt);
                break;
            }
            else{
                no/=2;
                x-=no;
            }
            if(!x){
                printf("%d", cnt);
                break;
            }
        }
    }

    return 0;
}
