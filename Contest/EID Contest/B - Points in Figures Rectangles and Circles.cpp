#include <bits/stdc++.h>

#define N 10

double p1 [N] [2], p2 [N] [2];
char c[N];

int main(){
    int i = 0;

    while (1){
        fflush(stdin);
        scanf("%c", &c[i]);

        if (c[i] == '*'){
            break;
        }

        if (c[i] == 'r'){
            scanf("%lf %lf %lf %lf", &p1 [i] [0], &p1 [i] [1], &p2 [i] [0], &p2 [i] [1]);
            i++;
        }
        else if (c[i] == 'c'){
            scanf("%lf %lf %lf", &p1 [i] [0], &p1 [i] [1], &p2 [i] [0]);
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
            if (c [k] == '*'){
                break;
            }
            else if (c [k] == 'r'){
                bool conx = (x > p1 [k] [0]) && (x < p2 [k] [0]),
                     cony = (y > p2 [k] [1]) && (y < p1 [k] [1]);

                if (conx && cony){
                    f = false;
                    printf("Point %d is contained in figure %d\n", j, k+1);
                }
            }
            else if (c [k] == 'c'){
                double dis = (x - p1 [k] [0])*(x - p1 [k] [0]) + (y - p1 [k] [1])*(y - p1 [k] [1]);

                if (sqrt(dis) < p2 [k] [0]){
                    f = false;
                    printf("Point %d is contained in figure %d\n", j, k+1);
                }
            }
        }

        if (f){
            printf("Point %d is not contained in any figure\n", j);
        }
    }

    return 0;
}
