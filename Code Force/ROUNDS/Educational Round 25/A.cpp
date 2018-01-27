#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 0, cnt = 0;
    long long ans = 0;
    string s;

    cin >> n >> s;

    for (int i = 0; i < s.size(); i++){
        if (s[i] == '1'){
            cnt++;

            if (i == s.size() - 1){
                ans += cnt;
            }
        }
        else{
            ans += cnt;

            if (i != s.size() - 1){
                ans *= 10;
            }

            cnt = 0;
        }
    }

    cout << ans << endl;

    return 0;
}
