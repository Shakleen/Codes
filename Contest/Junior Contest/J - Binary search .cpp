#include <bits/stdc++.h>

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)

int  bin_search (int *a, int x, int sz);

int main(){
    int n=0, q=0;

    scanf("%d %d", &n, &q);

    int arr[n+1]={}, qur;

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int j=0; j<q; j++){
        scanf("%d", &qur);

        printf("%d\n", bin_search(arr,qur,n));
    }

    return 0;
}

int bin_search(int *a, int x, int sz){
    int lo = 0, hi = sz - 1, result = -1;

    while (lo <= hi){
        int mid = lo + (hi - lo)/2;

        if (a[mid] == x){
            result = mid;
            hi = mid - 1;
        }
        else if (a[mid] > x){
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }

    return result;
}
