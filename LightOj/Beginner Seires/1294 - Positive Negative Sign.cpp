#include <bits/stdc++.h>

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        long long n = 0, m = 0, i = 1;

        scanf("%lld %lld", &n, &m);

        long long a1 = (m*(2*i+m-1))/2, a2 = (m*(2*(i+m)+m-1))/2, a3 = (m*(2*(i+2*m)+m-1))/2,
                  d = a3-a1, k1 = n/(2*m),
                  sumneg = (k1*(2*a1+(k1-1)*d))/2, sumpos = (k1*(2*a2+(k1-1)*d))/2,
                  ans = sumpos-sumneg;

//        printf("a1=%lld a2=%lld d=%lld sumpos=%lld sumneg=%lld k1=%lld\n",a1,a2,d,sumpos,sumneg,k1);
        printf("Case %d: %lld\n", cs, ans);
    }

    return 0;
}
