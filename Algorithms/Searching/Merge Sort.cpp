#include <bits/stdc++.h>
#define N 100
using namespace std;
int temp[N];
void mergeSort(int lo, int hi, int *a){
    if (lo == hi)   return;
    int mid = (lo+hi)/2;
    mergeSort(lo, mid, a);  mergeSort(mid+1, hi, a);
    for(int i=lo,k=lo,j=mid+1; k<=hi; k++)
        if(i == mid+1)      temp[k] = a[j++];
        else if(j == hi+1)  temp[k] = a[i++];
        else if(a[i] < a[j])temp[k] = a[i++];
        else                temp[k] = a[j++];
    for(int k=lo; k<=hi; k++)   a[k] = temp[k];
    return;
}
int main(){
    int num[] = {3,1,2};
    mergeSort(0,3,num);
    printf("%d %d %d", num[0],num[1],num[2]);
    return 0;
}
