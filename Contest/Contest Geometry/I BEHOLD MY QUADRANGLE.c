#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (a==b && a==c && a==d)
            printf("square\n");
        else if ((a==b&&c==d)||(a==c&&b==d)||(a==d&&b==c))
                printf("rectangle\n");
        else if (a+b+c>d && a+c+d>b && a+b+d>c && b+c+d>a)
            printf("quadrangle\n");
        else
            printf("banana\n");
    }
    return 0;
}
