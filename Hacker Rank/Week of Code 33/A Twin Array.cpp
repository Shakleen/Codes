#include <bits/stdc++.h>

#define N 100001

int a[N], b[N], ia[N], ib[N], t[N], ti[N];

void input (int *a, int n, int *in){
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        in[i] = i;
    }
    return;
}

void mergesort1 (int lo, int hi){
    if (lo == hi){
        return;
    }

    int mid = (lo+hi)/2;

    mergesort1(lo, mid);
    mergesort1(mid+1, hi);

    int i,j,k;

    for (i=k=lo, j=mid+1; k <= hi; k++){
        if (i == mid + 1){
            t [k] = a [j];
            ti [k] = ia [j++];
        }
        else if (j == hi + 1){
            t [k] = a [i];
            ti [k] = ia [i++];
        }
        else if (a[i] < a[j]){
            t [k] = a [i];
            ti [k] = ia [i++];
        }
        else{
            t [k] = a [j];
            ti [k] = ia [j++];
        }
    }

    for (int k = lo; k <= hi; k++){
        a [k] = t [k];
        ia [k] = ti [k];
    }
}
void mergesort2 (int lo, int hi){
    if (lo == hi){
        return;
    }

    int mid = (lo+hi)/2;

    mergesort2(lo, mid);
    mergesort2(mid+1, hi);

    int i,j,k;

    for (i=k=lo, j=mid+1; k <= hi; k++){
        if (i == mid + 1){
            t [k] = b [j];
            ti [k] = ib [j++];
        }
        else if (j == hi + 1){
            t [k] = b [i];
            ti [k] = ib [i++];
        }
        else if (b[i] < b[j]){
            t [k] = b [i];
            ti [k] = ib [i++];
        }
        else{
            t [k] = b [j];
            ti [k] = ib [j++];
        }
    }

    for (int k = lo; k <= hi; k++){
        b [k] = t [k];
        ib [k] = ti [k];
    }
}

int main(){
    int n = 0;

    scanf("%d", &n);

    input (a, n, ia);
    input (b, n, ib);

    mergesort1 (0,n-1);
    mergesort2 (0,n-1);

    if (ia[0] != ib[0]){
        printf("%d", a[0]+b[0]);
    }
    else{
        int num1 = a[1]+b[0], num2 = a[0]+b[1];

        if (num1<num2){
            printf("%d", num1);
        }
        else{
            printf("%d", num2);
        }
    }
    return 0;
}
