#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 0;

    scanf("%d", &n);

    map <int, int> mymap;

    int num = 1, h[n+1]={}, mx = 0;

    for (int i = 0; i < n; i++){
        int a = 0;

        scanf("%d", &a);

        if ( !mymap[a] ){
            mymap[a] = num++;
        }
        h [ mymap[a] ]++;
    }

    for (int i = 1; i < num; i++){
        if (h [i] > mx){
            mx = h [i];
        }
    }

    printf("%d %d", mx, num-1);

    return 0;
}
