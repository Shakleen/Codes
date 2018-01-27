#include <bits/stdc++.h>

int main(){
    long long n=0,n2=0;

    scanf("%I64d", &n);

    int i=0,n1=n,last=0,digit[10]={};

    for(i=0; n1>0; i++){
        digit[i]=n1%10;
        n1/=10;
    }

    int num=digit[i-1];
    num++;

    if (num<10){
        digit[i-1]=num;
        last=i-1;
    }
    else{
        digit[i-1]=num%10;
        num/=10;
        digit[i]=num%10;
        last=i;
    }

    for(int j=last-1; j>=0; j--)   digit[j]=0;

    for(i=last; i>=0; i--){
        n2+=digit[i];
        if (i!=0)   n2*=10;
    }
    printf("%I64d",n2-n);

    return 0;
}
