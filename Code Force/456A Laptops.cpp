#include <bits/stdc++.h>

#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)

#define N 100001

int temp[N], temp2[N];

void merge_sort (int lo, int hi, int p[], int q[]);

int main(){
    int n=0, f=0;

    scanf("%d", &n);

    int p[n]={}, q[n]={};

    if (n == 1){
        scan2(p,q);

        printf("Poor Alex");

        return 0;
    }

    for (int i=0; i<n; i++){
        scan2(p[i],q[i]);
    }

    merge_sort (0, n-1, p, q);

    for (int i=0; i < n-1; i++){
        if (q[i] > q[i+1]){
            f = 1;
            break;
        }
    }

    if (f){
        printf("Happy Alex");
    }
    else{
        printf("Poor Alex");
    }

    return 0;
}

void merge_sort (int lo, int hi, int p[], int q[]){
    if (lo == hi)   return;

    int mid = (lo + hi)/2;

    merge_sort (lo, mid, p, q);
    merge_sort (mid+1, hi, p, q);

    for (int i=lo, j=mid+1, k=lo; k<=hi; k++){
        if (i == mid + 1){
            temp[k] = p[j];
            temp2[k] = q[j];
            j++;
        }
        else if (j == hi + 1){
            temp[k] = p[i];
            temp2[k] = q[i];
            i++;
        }
        else if (p[i] < p[j]){
            temp[k] = p[i];
            temp2[k] = q[i];
            i++;
        }
        else{
            temp[k] = p[j];
            temp2[k] = q[j];
            j++;
        }
    }

    for (int k=lo; k<=hi; k++){
        p[k] = temp[k];
        q[k] = temp2[k];
    }
    return;
}
