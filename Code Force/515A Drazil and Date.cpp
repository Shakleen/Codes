#include <bits/stdc++.h>
#define ll long long
int main(){
    ll a,b,s;
    scanf("%I64d %I64d %I64d", &a, &b, &s);

    if(a==0 && b==0 && !(s%2))
        printf("Yes");
    else{
        if (a<0)    a*=(-1);
        if (b<0)    b*=(-1);
        ll t_s=a+b-2;
        if (t_s>s)  printf("No");
        else{
            t_s-=s;
            if (!(t_s%2) && t_s)      printf("Yes");
            else                    printf("No");
        }
    }

    return 0;
}
