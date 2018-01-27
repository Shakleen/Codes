#include <bits/stdc++.h>

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)

int main(){
    int n=0;

    scanf("%d", &n);

    ll sum = 0;

    while (n--){
        char str[15]={};

        scanf("%s", str);

        if (!strcmp(str,"Tetrahedron"))         sum += 4;
        else if (!strcmp(str,"Cube"))           sum += 6;
        else if (!strcmp(str,"Octahedron"))     sum += 8;
        else if (!strcmp(str,"Dodecahedron"))   sum += 12;
        else                                    sum += 20;
    }

    printf("%I64d", sum);

    return 0;
}
