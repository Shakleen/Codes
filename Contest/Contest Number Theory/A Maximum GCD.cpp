#include <bits/stdc++.h>
#define N 20000
int gcd(int a, int b){
    if (!(a%b)) return b;
    return gcd(b,a%b);
}
int main(){
    int i=0,j=0,n=0,num[102];
    char str[N]={};
    gets(str);
    while(str[i])
        n=n*10+str[i++]-'0';
    while(n--){
        gets(str);
        i=0;
        j=0;
        while(str[i]){
            num[j]=0;
            while(str[i]&&str[i]!=' ')
                num[j]=num[j]*10+str[i++]-'0';
            while(str[i]==' ')
                i++;
            j++;
        }
        int sz=j, mx=0,j=0;
        for (i=0; i<sz-1; i++){
            int g=0;
            for (j=i+1; j<sz; j++){
                g=gcd(num[i],num[j]);
                if (g>mx)
                mx=g;
            }
        }
        printf("%d\n",mx);
    }


    return 0;
}
