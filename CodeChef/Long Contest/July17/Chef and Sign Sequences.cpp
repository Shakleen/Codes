#include <bits/stdc++.h>

using namespace std;

int main(){
    int t = 0;

    scanf("%d", &t);

    while (t--){
        string s;

        cin >> s;

        long long len = s.size(), gs = 1, ls = 1, mx = 1;

        for (int i = 0; i < len; i++){
            if ( s [i] == '=' )         continue;
            else if ( s [i] == '<' ){
                    gs++;
                    ls = 1;
            }
            else if ( s [i] == '>' ){
                    ls++;
                    gs = 1;
            }

            mx = max(max(mx,gs), max(mx,ls));
        }

        printf("%lld\n", mx);
    }

    return 0;
}
