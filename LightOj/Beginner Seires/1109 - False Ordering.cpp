#include <bits/stdc++.h>

#define N 1001

int fact [N], in [N], t [N], t2 [N];

void factors (void);
void msort (int lo, int hi);

int main(){
    factors();

    msort(1,1000);

    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int n = 0;

        scanf("%d", &n);

        printf("Case %d: %d\n", cs, in [n]);
    }

    return 0;
}

void factors (void){
    fact [1] = 1;
    in [1] = 1;

    for (int i = 2; i <= 1000; i++){
        int n = i, cnt = 2;
        double lim = sqrt(n);

        for (int j = 2; j <= lim; j++){
            if ( !(n%j) ){
                cnt++;
                if (j != n/j){
                    cnt++;
                }
            }
        }

        fact [i] = cnt;
        in [i] = i;
    }

    return;
}

void msort (int lo, int hi){
    if (lo == hi){
        return;
    }

    int mid = (lo+hi)/2;

    msort(lo, mid);
    msort(mid+1, hi);

    for (int i = lo, k = lo, j = mid + 1; k <= hi; k++){
        if (i == mid + 1){
            t [k] = fact [j];
            t2 [k] = in [j];
            j++;
        }
        else if (j == hi + 1){
            t [k] = fact [i];
            t2 [k] = in [i];
            i++;
        }
        else if (fact [i] < fact [j]){
            t [k] = fact [i];
            t2 [k] = in [i];
            i++;
        }
        else if (fact [i] == fact [j] && in[i] > in [j]){
            t [k] = fact [i];
            t2 [k] = in [i];
            i++;
        }
        else{
            t [k] = fact [j];
            t2 [k] = in [j];
            j++;
        }
    }

    for (int k = lo; k <= hi; k++){
        fact [k] = t [k];
        in [k] = t2 [k];
    }

    return;
}
