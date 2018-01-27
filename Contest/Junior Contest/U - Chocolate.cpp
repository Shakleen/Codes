#include <bits/stdc++.h>

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)

int main(){
    int n = 0, no1 = 0, no2 = 0, cnt1 = 0;
    ll cnt = 1;

    scanf("%d", &n);

    bool a[n] = {};

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);

        if (a[i]){
            cnt1++;
            if (!no1)           no1=i+1;
            else if (!no2)      no2=i+1;
            else{
                no1 = no2;
                no2 = i+1;
            }
            if (no1 && no2){
                cnt *= (no2-no1);
            }
        }
    }

    if (!no1 && !no2){
        printf("0");
    }
    else if ((!no1 || !no2) || cnt1 == n){
        printf("1");
    }
    else{
        printf("%I64d",cnt);
    }

    return 0;
}
