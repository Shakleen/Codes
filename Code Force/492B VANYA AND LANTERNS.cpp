#include <bits/stdc++.h>
#define N 1000
long long int num[N],temp[N];
void mergesort(int lo, int hi);
int main(){
    long long int l,n,i;
    n=i=l=0;
    scanf("%I64d %I64d", &n, &l);
    for (i=0; i<n; i++)
        scanf("%I64d", &num[i]);
    mergesort(0, n-1);
    double maxdif=num[0], dif=l-num[n-1];
    if (dif>maxdif)
        maxdif=dif;
    for (i=1; i<n; i++){
        dif=(num[i]-num[i-1])*0.5;
        if (dif>maxdif)   maxdif=dif;
    }
    printf("%.12lf", maxdif);

    return 0;
}

void mergesort(int lo, int hi){
    if (hi==lo) return;
    int mid=(hi+lo)/2;
    mergesort(lo, mid);
    mergesort(mid+1, hi);
    int i,j,k;
    for (i=k=lo, j=mid+1; k<=hi; k++){
        if (i==mid+1)
            temp[k]=num[j++];
        else if (j==hi+1)
            temp[k]=num[i++];
        else if (num[i]<num[j])
            temp[k]=num[i++];
        else
            temp[k]=num[j++];
    }
    for (k=lo; k<=hi; k++){
        num[k]=temp[k];
    }
}
