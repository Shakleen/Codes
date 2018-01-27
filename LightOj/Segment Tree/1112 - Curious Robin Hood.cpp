#include <bits/stdc++.h>
#define ll long long
using namespace std;

void build (int node, int b, int e, int *num, ll *tree){
    if (b == e){
        tree [node] = num [b];
        return;
    }

    int mid = (b+e)/2, left = node*2, right = left + 1;

    build (left, b, mid, num, tree);
    build (right, mid+1, e, num, tree);

    tree [node] = tree [left] + tree [right];

    return;
}
void update (int node, int b, int e, int in, int newval, ll *tree, bool flag){
    if (in < b || in > e){
        return;
    }
    else if (b >= in && e <= in){
        if (flag)   tree [node] += newval;
        else        tree [node] = newval;

        return;
    }

    int mid = (b+e)/2, left = node*2, right = left+1;

    update(left, b, mid, in, newval, tree, flag);
    update(right, mid+1, e, in, newval, tree, flag);

    tree [node] = tree [left] + tree [right];

    return;
}
ll query (int node, int b, int e, int l, int r, ll *tree){
    if (r < b || l > e){
        return 0;
    }
    else if (b >= l && e <= r){
        return tree[node];
    }

    int mid = (b+e)/2, left = node*2, right = left+1;
    ll x = query(left, b, mid, l, r, tree),
       y = query(right, mid+1, e, l, r, tree);

    return (x+y);
}
int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int n = 0, q = 0;

        scanf("%d %d", &n, &q);

        int sack [n+1];
        ll tree [4*n];

        memset(tree, 0, sizeof(tree));

        for(int i = 1; i <= n; i++){
            scanf("%d", &sack[i]);
        }

        build(1, 1, n, sack, tree);

        printf("Case %d:\n", cs);

        for (int i = 1; i <= q; i++){
//for(int i = 1; i < 3*n; i++)printf("%d -> %d\n",i,tree[i]);
            int choice = 0;

            scanf("%d", &choice);

            if (choice == 1){
                int ix = 0;

                scanf("%d", &ix);

                if (ix >= 0 && ix < n){
                    printf("%d\n", sack [ix+1]);

                    sack [ix+1] = 0;

                    update(1,1,n,ix+1,0,tree,false);
                }
                else{
                    printf("%d\n", 0);
                }
            }
            else if (choice == 2){
                int ix = 0, val = 0;

                scanf("%d %d", &ix, &val);

                if (ix >= 0 && ix <= n){
                    sack [ix+1] += val;

                    update(1,1,n,ix+1,val,tree,true);
                }
            }
            else if (choice == 3){
                int ix = 0, jx = 0;

                scanf("%d %d", &ix, &jx);

                ll ans = query (1,1,n,ix+1,jx+1,tree);

                printf("%lld\n", ans);
            }
        }
    }


    return 0;
}
