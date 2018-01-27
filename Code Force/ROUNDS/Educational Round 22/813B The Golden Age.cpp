#include <bits/stdc++.h>

int main(){
    long long x = 0, y = 0, l = 0, r = 0;

    scanf("%I64d %I64d %I64d %I64d", &x, &y, &l, &r);

    long long s = l, f = l;

    for (long long i = l; i <= r; i++){
        long long year = i;

        if (year <= x || year <= y){
            continue;
        }

        if ( !((year-1)%x) ){
            double  lo = log(x), hi = year, num = hi/lo;
            int num2 = (int) num;

            if ((num - num2) == 0){
                printf("year = %d\n", year);
                f = i;
                continue;
            }
        }
        if ( !((year-1)%y) ){
            double  lo = log(y), hi = year, num = hi/lo;
            int num2 = (int) num;

            if ((num - num2) == 0){
                printf("year = %d\n", year);
                f = i;
                continue;
            }
        }
        long long min = x < y ? x : y;
        long long no = 1, pw = 0;
        bool flag = false;

        while (no <= year){
            no *= min;
            pw++;
        }
        pw--;

        for (long long k = 0; k <= pw; k++){
            long long nox = pow(x,k) + 0.1, noy = pow(y, pw-k);

            if (nox + noy == year){
                flag = true;
                break;
            }
        }

        if (flag){
            printf("year* = %d\n", year);
            f = i;
        }
        else{
            s = f = i + 1;
        }
    }
    printf("s=%d f=%d\n", s,f);

    if (s == r){
        printf("0");
    }
    else{
        printf("%I64d", f-s);
    }

    return 0;
}
