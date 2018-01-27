#include <bits/stdc++.h>
int binsearch(int a[],int sz,int x);
int main(){
    int a[9]={1,2,3,4,6,7,8,9,10},n;
    printf("Enter a number to find in the array:\n");
    scanf("%d", &n);
    int f=binsearch(a,9,n);
    if (f!=-1)
        printf("No found at index %d", f);
    else
        printf("No not found");

    return 0;
}
int binsearch(int a[],int sz,int x){
    int lo=0, hi=sz-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if (x==a[mid])
            return mid;
        else if (x<a[mid])
            hi=mid-1;
        else
            lo=mid+1;
    }
    return -1;
}
