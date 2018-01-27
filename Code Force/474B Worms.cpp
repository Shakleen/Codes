#include <bits/stdc++.h>
int binsearch(int a[],int lo,int hi,int x);
int main(){
    int n,m,j=0;
    scanf("%d", &n);
    int a[n+2],*p=a;
    for(int i=0; i<n; i++){
        scanf("%d",&j);
        if (i!=0)       a[i]=a[i-1]+j;
        else            a[i]=j;
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%d", &j);
        int pos=binsearch(p,0,n-1,j)+1;
        printf("%d\n",pos);
    }
    return 0;
}
int binsearch(int a[],int lo,int hi,int x){
    if (lo>hi){
        return lo;
    }
    int mid=(lo+hi)/2;
    if (x==a[mid]){
        return mid;
    }
    else if (x>a[mid]){
        binsearch(a,mid+1,hi,x);
    }
    else{
        binsearch(a,lo,mid-1,x);
    }
}
