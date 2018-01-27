#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int t = 0;

    scanf("%d", &t);

    while (t--){
        int n = 0;

        scanf("%d", &n);

        map <ll, ll> mymap;
        ll a[ n+2 ] = {}, no = 1, sum = 0;

        for (int i = 0; i < n; i++){
            ll num = 0;

            scanf("%lld", &num);

            if ( !mymap[num] ){
                mymap[num] = no++;
            }

            a[mymap[num]]++;
        }

        for (int i = 0; i < no; i++){
            if (a [i] > 1){
                sum += a[i]*(a[i]-1);
            }
        }

        printf("%lld\n", sum);
    }

    return 0;
}
