#include <bits/stdc++.h>

#define N 10

double p1 [N] [2], p2 [N] [2];

int main(){
    int i = 0;

    while (1){
        char c = 0;

        fflush(stdin);
        scanf("%c", &c);

        if (c == '*'){
            break;
        }

        if (c == 'r'){
            scanf("%lf %lf %lf %lf", &p1 [i] [0], &p1 [i] [1], &p2 [i] [0], &p2 [i] [1]);
            i++;
        }
    }

    for (int j = 1; ; j++){
        double x = 0, y = 0;

        scanf("%lf %lf", &x, &y);

        if (x == 9999.9 && y == 9999.9){
            break;
        }

        bool f = true;

        for (int k = 0; k < i; k++){
            bool conx = (x > p1 [k] [0]) && (x < p2 [k] [0]),
                 cony = (y > p2 [k] [1]) && (y < p1 [k] [1]);

            if (conx && cony){
                f = false;
                printf("Point %d is contained in figure %d\n", j, k+1);
            }
        }

        if (f){
            printf("Point %d is not contained in any figure\n", j);
        }
    }

    return 0;
}
