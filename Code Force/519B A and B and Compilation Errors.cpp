#include <bits\stdc++.h>
#define N 100001
int temp[N];
void msort(int lo, int hi, int *p);
int main(){
    int n;
    scanf("%d", &n);
    int c1[n+2]={},c2[n+2]={},c3[n+2]={},i=0,no1=0,no2=0;
    bool con1=0,con2=0;
    for(i=0; i<n; i++)   scanf("%d",&c1[i]);
    for(i=0; i<n-1; i++) scanf("%d",&c2[i]);
    for(i=0; i<n-2; i++) scanf("%d",&c3[i]);
    msort(0,n-1,c1);
    msort(0,n-2,c2);
    msort(0,n-3,c3);
    for(i=0; i<n; i++){
        if(!no2){
            if(c2[i]!=c3[i])    no2=c2[i];
        }
        if(!no1){
            if(c1[i]!=c2[i])    no1=c1[i];
        }
        if(no1&&no2)    break;
    }
    printf("%d\n%d",no1,no2);
    return 0;
}
void msort(int lo, int hi, int *p){
    if(lo==hi)  return;
    int mid=lo+(hi-lo)/2;
    msort(lo,mid,p);
    msort(mid+1,hi,p);
    int i=lo, k=lo, j=mid+1;
    for(i,j,k; k<=hi; k++){
        if(i==mid+1)
            temp[k]=p[j++];
        else if (j==hi+1)
            temp[k]=p[i++];
        else if (p[i]<p[j])
            temp[k]=p[i++];
        else
            temp[k]=p[j++];
    }
    for(k=lo; k<=hi; k++)
        p[k]=temp[k];
}
