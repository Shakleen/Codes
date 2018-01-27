#include <bits/stdc++.h>

using namespace std;

#define N                   100000000
#define M                   5761455
#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)
#define pii                 pair <int, int>
#define MOD                 1000000007

void func1(ll *arr, int l, int r);
void func2(vector < pair< pii,pii > > &v, int l, int r, ll *arr);

int main(){
    int t = 0;

    scanf("%d", &t);

    while (t--){
        vector < pair< pii,pii > > v;
        int n = 0, m = 0;

        scanf("%d %d", &n, &m);

        ll arr [n+2];
        memset(arr, 0, sizeof(arr));

        for (int i = 1; i <= m; i++){
            int type = 0, left = 0, right = 0;

            scanf("%d %d %d", &type, &left, &right);

            v.push_back(make_pair(make_pair(i,type),make_pair(left,right)));
        }

//        printf("\n");
//        for (int i = 0; i < v.size(); i++){
//            printf("%d %d %d %d\n",v[i].first.first, v[i].first.second,
//                   v[i].second.first, v[i].second.second);
//        }

        vector < pair< pii,pii > >::iterator itr = v.begin(), ite = v.end();

        while (itr != ite){
            if ((*itr).first.second == 1){
                func1(arr,(*itr).second.first,(*itr).second.second);
            }
            else{
                func2(v,(*itr).second.first,(*itr).second.second,arr);
            }

            itr++;
        }

        for (int i = 1; i <= n; i++){
            arr[i] += arr[i-1];

            printf("%lld ", arr[i]%MOD);
        }

        printf("\n");
    }
    return 0;
}

void func1(ll *arr, int l, int r){
    arr[l]++;
    arr[r+1]--;

    return;
}

void func2(vector < pair< pii,pii > > &v, int l, int r, ll *arr){
    for (int i = l-1; i < r; i++){
        if (v[i].first.second == 1){
            func1(arr,v[i].second.first,v[i].second.second);
        }
        else{
            func2(v,v[i].second.first,v[i].second.second,arr);
        }
    }

    return;
}
