#include <bits/stdc++.h>

#define ll long long

using namespace std;

unsigned long long fact [21];

int main(){
    fact [0] = 1;

    for (int i = 1; i <= 20; i++){
        fact [i] = i * fact [i-1];
    }

    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        ll n = 0;

        scanf("%lld", &n);

        stack <int> no;

        for (int i = 20; i >= 0; i--){
            if (fact [i] <= n){
                n -= fact [i];
                no.push(i);
            }
        }

        if (n > 0){
            printf("Case %d: impossible\n", cs);
        }
        else{
            printf("Case %d: ", cs);

            while (no.size() != 1){
                printf("%d!+", no.top());
                no.pop();
            }

            printf("%d!\n", no.top());
        }
    }

    return 0;
}
