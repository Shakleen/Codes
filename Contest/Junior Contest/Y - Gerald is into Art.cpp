#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)

int main(){
    int a1,a2,a3,b1,b2,b3,sp1,sp2;
    a1=a2=a3=b1=b2=b3=sp1=sp2=0;

    scan2(a1,b1);
    scan2(a2,b2);
    scan2(a3,b3);

    if (a1>=a2 && b1>=b2){
        sp1 = a1-a2;
        sp2 = b1;

        if ((sp1>=a3 && sp2>=b3) || (sp1>=b3 && sp2>=a3)){
            printf("YES");
            return 0;
        }

        sp1 = b1-b2;
        sp2 = a1;

        if ((sp1>=a3 && sp2>=b3) || (sp1>=b3 && sp2>=a3)){
            printf("YES");
            return 0;
        }
    }

    swap (a1,b1);

    if (a1>=a2 && b1>=b2){
        sp1 = a1-a2;
        sp2 = b1;

        if ((sp1>=a3 && sp2>=b3) || (sp1>=b3 && sp2>=a3)){
            printf("YES");
            return 0;
        }

        sp1 = b1-b2;
        sp2 = a1;

        if ((sp1>=a3 && sp2>=b3) || (sp1>=b3 && sp2>=a3)){
            printf("YES");
            return 0;
        }
    }

    printf("NO");

    return 0;

}
