#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)

int s_search (double x, int sz, double *a);

int main(){
    int t=0;

    scanf("%d", &t);

    while(t--){
        int n=0, q=0;

        scan2(n,q);

        double a[n]={};

        for (int i=0; i<n; i++){
            scanf("%lf", &a[i]);
        }

        sort(a,a+n);

        for (int i=0; i<q; i++){
            double x=0;

            scanf("%lf", &x);

            int cnt = s_search(x,n,a);

            if (cnt == -1 || cnt >= n){
                printf("0\n");
            }
            else{
                int num = n - (cnt + 1);
                printf("%d\n", num);
            }
        }
    }

    return 0;
}

int s_search (double x, int sz, double *a){
    int lo=0, hi=sz-1, result = hi;
    bool flag = 0;

    while (lo <= hi){
        int mid = lo + (hi-lo)/2;
        double res = a[mid] - x;

        if (res == 0){
            result = mid;
            flag = 1;
            lo = mid + 1;
        }
        else if (res < 0){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }

    if (flag){
        return result;
    }
    else{
        return lo;
    }
}
