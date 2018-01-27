#include <bits/stdc++.h>

#define N 1000000007

using namespace std;

void take_input (int s, int *p);
int bsearch (int *a, int s, int x);
long long find_sum (int *a, int index, long long *sum);

int main(){
    int t = 0;

    scanf("%d", &t);

    while (t--){
        int p = 0, q = 0, r = 0;

        scanf("%d %d %d", &p, &q, &r);

        int a [p] = {}, b [q] = {}, c [r] = {};

        long long sumx [p] = {}, sumz [r] = {}, sum = 0;

        take_input (p, a);
        take_input (q, b);
        take_input (r, c);

        sort (a, a+p);
        sort (b, b+q);
        sort (c, c+r);

        for (int i = q - 1; i >= 0; i--){
            long long Y = b [i], X = 0, Z = 0;

            int index_x = bsearch (a, p, Y),
                index_z = bsearch (c, r, Y);

            if ( index_x < 0 )
                X = 0;
            else if ( !sumx [index_x] )
                X = find_sum (a, index_x, sumx);
            else
                X = sumx [index_x];

            if ( index_z < 0 )
                Z = 0;
            else if ( !sumz [index_z] )
                Z = find_sum (c, index_z, sumz);
            else
                Z = sumz [index_z];

            sum = ((sum%N) + (X + (index_x+1) * Y) * (Z + (index_z+1) * Y)%N);

//            printf("X=%lld Y=%lld inx=%d Z=%lld inz=%d sum=%lld\n",X,Y,index_x,Z,index_z,sum);
        }

//        long long s = sum % N);

        printf("%lld\n", sum);
    }
    return 0;
}

void take_input (int s, int *p){

    for (int i = 0; i < s; i++){
        scanf("%d", &p[i]);
    }

    return;
}

int bsearch (int *a, int s, int x){
    int lo  = 0, hi = s - 1, rst = lo;
    bool flag = false;

    while (lo <= hi){
        int mid = (hi + lo)/2;

        if (a[mid] == x){
            flag = true;
            rst = mid;
            lo = mid + 1;
        }
        else if (a[mid] < x){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    if (flag)
        return rst;
    else
        return hi;
}

long long find_sum (int *a, int index, long long *sum){

    for (int i = 0; i <= index; i++){
        if (!i)
            sum [i] = a [i];
        else
            sum [i] = a [i] + sum [i-1];
    }

    return sum [index];
}

