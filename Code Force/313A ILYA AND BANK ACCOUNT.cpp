#include <bits/stdc++.h>
int f(int a, int b, int arr[10]);
int main(){
    int b=0, a=0;
    scanf("%d", &b);
    if (b>=0)
        printf("%d", b);
    else{
        int digit[10],i=0,j=0,m=0;
        b*=(-1);
        while (b>0){
            digit[i]=b%10;
            b/=10;
            i++;
        }
        if (digit[0]>digit[1]){
            j=0;
            a=f(j,i,digit);
            printf("%d",a);
        }
        else{
            j=1;
            a=f(j,i,digit);
            printf("%d",a);
        }

    }
}

int f(int a, int b, int arr[10]){
    int i=0, val=0, po=0;
    for (i=0; i<b; i++){
        if (i!=a){
            val-=arr[i]*(pow(10,po)+0.1);
            po++;
        }
    }
    return val;
}
