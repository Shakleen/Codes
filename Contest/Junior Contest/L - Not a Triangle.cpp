#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)

int main(){
    while (1){
        int n=0;

        scanf("%d", &n);

        if (n==0){
            break;
        }

        int a[n]={}, mx=0;
        ll cnt=0;

        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);

            if (a[i]>mx){
                mx = a[i];
            }
        }

        sort(a,a+n);

        for(int i=n-1; i>1; i--){
            int f=0, l=i-1;

            while (f < l){
                if (a[f] + a[l] < a[i]){
                    cnt += (l - f);
                    f++;
                }
                else{
                    l--;
                }
            }
        }

        printf("%lld\n",cnt);
    }


    return 0;
}
