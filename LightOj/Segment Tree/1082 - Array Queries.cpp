#include <bits/stdc++.h>

using namespace std;

void build (int AT, int L, int R, int *a, int *num);
int query (int AT, int L, int R, int l, int r, int *a);

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int n = 0, q = 0, mn = 0;

        scanf("%d %d", &n, &q);

        int a[3*n], num[n+1];

        memset(a, -1, sizeof(a));

        for (int i = 1; i <= n; i++){
            scanf("%d", &num[i]);
        }

        build(1, 1, n, a, num);

        printf("Case %d:\n", cs);

        for (int i = 0; i < q; i++){
            int I = 0, J = 0, m = 0;

            scanf("%d %d", &I, &J);

            m = query (1, 1, n, I, J, a);

            printf("%d\n", m);
        }
    }

    return 0;
}

void build (int AT, int L, int R, int *a, int *num){
    if (L == R){
        a[AT] = num[L];
        return;
    }

    int mid = (L+R)/2, left = AT*2, right = AT*2+1;

    build (left, L, mid, a, num);
    build (right, mid+1, R, a, num);

    a[AT] = min(a[left], a[right]);

    return;
}

int query (int AT, int L, int R, int l, int r, int *a){
    if (r < L || l > R){
        return -1;
    }
    if (l <= L && r >= R){
        return a[AT];
    }

    int mid = (L+R)/2, left = AT*2, right = AT*2+1,
        x = query (left, L, mid, l, r, a),
        y = query (right, mid+1, R, l, r, a);

    if (x == -1)                    return y;
    else if (y == -1)               return x;
    else if (x != -1 && y != -1)    return min(x,y);
}
