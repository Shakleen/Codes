#include <bits/stdc++.h>
int x[3], temp[3];
void mergesort(int lo, int hi);
int main(){
    int i=0;
    for (i=0; i<3; i++){
        scanf("%d", &x[i]);
    }
    mergesort(0,2);
    printf("%d", x[2]-x[0]);
    return 0;
}
void mergesort(int lo, int hi){
    if(hi==lo)  return;
    int mid=(hi+lo)/2;
    mergesort(lo, mid);
    mergesort(mid+1, hi);
    int i,j,k;
    for (i=lo, j=mid+1, k=lo; k<=hi; k++){
        if (i==mid+1)
            temp[k]=x[j++];
        else if (j==hi+1)
            temp[k]=x[i++];
        else if (x[i]<x[j])
            temp[k]=x[i++];
        else
            temp[k]=x[j++];
    }
    for (k=lo; k<=hi; k++)
        x[k]=temp[k];
}
