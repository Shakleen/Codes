#include <bits/stdc++.h>

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    int i=0,loop=n*m,flag=0;
    char ch=0;
    for(i=0;i<loop; i++){
        scanf(" %c",&ch);
        if(!flag)
            if(ch=='C'||ch=='M'||ch=='Y')
                flag=1;
    }
    if(flag)    printf("#Color");
    else        printf("#Black&White");
    return 0;
}
