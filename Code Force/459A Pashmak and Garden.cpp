#include <bits/stdc++.h>

int main(){
    int x1,x2,y1,y2,x3,y3,x4,y4,m;
    scanf("%d %d %d %d",&x1, &y1, &x2, &y2);
    if (x1==x2 || y1==y2){
        if (y1==y2){
            m=abs(x2-x1);
            x3=x2;              x4=x1;
            y3=y2+m;            y4=y1+m;
            if (y3>1000)    y3-=(2*m);
            if (y4>1000)    y4-=(2*m);
        }
        else if (x1==x2){
            m=abs(y2-y1);
            y3=y2;              y4=y1;
            x3=x2+m;            x4=x1+m;
            if (x3>1000)    x3-=(2*m);
            if (x4>1000)    x4-=(2*m);
        }
    }
    else{
        int m=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2),a=2*(x2-x1)*(x2-x1);
        if (m != a){
            printf("-1");
            return 0;
        }
        x3=x2;  y3=y1;
        x4=x1;  y4=y2;
    }
    printf("%d %d %d %d",x3,y3,x4,y4);
    return 0;
}
