#include <bits/stdc++.h>

using namespace std;

int main(){
    int x = 0, cl = 0, cr = 0, ans = 0;

    cin >> x;

    for (int i = x; i; i/=10){
        if (i < 1000)   cl += (i%10);
        else            cr += (i%10);
    }

    if (cl == cr){
        ans = x + 9;
    }
    else{
        ans = x;

        while (cl != cr){
            ans++;
            cl = cr = 0;

            for (int i = ans; i; i /= 10){
                if (i < 1000)   cl += (i%10);
                else            cr += (i%10);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
