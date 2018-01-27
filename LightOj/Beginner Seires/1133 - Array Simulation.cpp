#include <bits/stdc++.h>

using namespace std;

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int n = 0, m = 0;

        scanf("%d %d", &n, &m);

        int a[n];

        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }


        for (int i = 0; i < m; i++){
            char c = 0;

            scanf(" %c", &c);

            switch (c){
                case 'S':{
                    int d = 0;

                    scanf("%d", &d);

                    for (int i = 0; i < n; i++){
                        a[i] += d;
                    }

                    break;
                }
                case 'M':{
                    int d = 0;

                    scanf("%d", &d);

                    for (int i = 0; i < n; i++){
                        a[i] *= d;
                    }

                    break;
                }
                case 'D':{
                    int k = 0;

                    scanf("%d", &k);

                    for (int i = 0; i < n; i++){
                        a[i] /= k;
                    }

                    break;
                }
                case 'R':{
                    for (int i = 0; i < n/2; i++){
                        int temp = a[i];
                        a[i] = a[n-1-i];
                        a[n-1-i] = temp;
                    }

                    break;
                }
                case 'P':{
                    int y = 0, z = 0;

                    scanf("%d %d", &y, &z);

                    swap(a[y], a[z]);

                    break;
                }
            }
        }

        printf("Case %d:\n", cs);

        for (int i = 0; i < n; i++){
            printf("%d", a[i]);

            if (i != n-1)   printf(" ");
            else            printf("\n");
        }
    }

    return 0;
}
