#include <bits/stdc++.h>

#define N 10

double p1 [N] [2], p2 [N] [2], p3 [N] [2];
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
        else if (c[i] == 't'){
            scanf("%lf %lf %lf %lf", &p1 [i] [0], &p1 [i] [1], &p2 [i] [0], &p2 [i] [1]);
            scanf("%lf %lf", &p3 [i] [0], &p3 [i] [1]);
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
            else if (c [k] == 't'){
                double x1 = p1 [k] [0], x2 = p2 [k] [0], x3 = p3 [k] [0],
                       y1 = p1 [k] [1], y2 = p2 [k] [1], y3 = p3 [k] [1],
                       con1 = (x-x1)*(y1-y2) - (y-y1)*(x1-x2),
                       con2 = (x-x1)*(y1-y3) - (y-y1)*(x1-x3),
                       con3 = (x-x2)*(y2-y3) - (y-y2)*(x2-x3);

                if (con1 && con2 && con3){
                    double con4 = (x3-x1)*(y1-y2) - (y3-y1)*(x1-x2),
                           con5 = (x2-x1)*(y1-y3) - (y2-y1)*(x1-x3),
                           con6 = (x1-x2)*(y2-y3) - (y1-y2)*(x2-x3);

                    bool c1 = (con1 > 0) ^ (con4 > 0),
                         c2 = (con2 > 0) ^ (con5 > 0),
                         c3 = (con3 > 0) ^ (con6 > 0);

                    if (!c1 && !c2 && !c3){
                        f = false;
                        printf("Point %d is contained in figure %d\n", j, k+1);
                    }
                }
            }
        }

        if (f){
            printf("Point %d is not contained in any figure\n", j);
        }
    }

    return 0;
}
