#include <bits/stdc++.h>
#define N 2002

int rating [N], index [N], temp [N], temp2 [N];

void msort (int lo, int hi);

int main(){
    int n = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%d", &rating[i]);
        index [i] = i;
    }

    msort(0, n-1);

    int position [n] = {};

    for (int i = n-1; i >= 0; i--){
        if (i == n-1){
            position [ index [i] ] = 1;
        }
        else{
            if (rating [i] == rating [i+1]){
                position [ index [i] ] = position [ index [i+1] ];
            }
            else{
                position [ index [i] ] = n - i;
            }
        }
    }

    for (int i = 0; i < n; i++){
        printf("%d ", position [i]);
    }
    return 0;
}

void msort (int lo, int hi){
    if (lo == hi)
        return;

    int mid = (hi+lo)/2;

    msort(lo, mid);
    msort(mid+1,hi);

    int i,j,k;

    for (i=k=lo, j=mid+1; k <= hi; k++){
        if (i == mid+1){
            temp [k] = rating [j];
            temp2 [k] = index [j];
            j++;
        }
        else if (j == hi+1){
            temp [k] = rating [i];
            temp2 [k] = index [i];
            i++;
        }
        else if (rating [i] < rating [j]){
            temp [k] = rating [i];
            temp2 [k] = index [i];
            i++;
        }
        else{
            temp [k] = rating [j];
            temp2 [k] = index [j];
            j++;
        }
    }

    for (int k = lo; k <= hi; k++){
        rating [k] = temp [k];
        index [k] = temp2 [k];
    }
}
