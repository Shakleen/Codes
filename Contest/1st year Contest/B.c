#include <stdio.h>

int main(){
    int x,g,y,r,remain=0,t=0;
    scanf("%d", &t);
    while (t--){
        scanf("%d %d %d %d", &x, &g, &y, &r);
        remain=x%(g+y+r);
        if (remain<g){
            printf("GREEN\n");
        }
        else{
            if (remain-g<y){
                printf("YELLOW\n");
            }
            else if (remain-g-y<r){
                printf("RED\n");
            }
            else{
                printf("GREEN\n");
            }
        }
    }
    return 0;
}
