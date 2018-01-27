#include <bits/stdc++.h>

int main(){
    int n,t,k,d;
    scanf("%d %d %d %d", &n, &t, &k, &d);
    int time1=(n/k);
    if (n%k)    time1++;
    time1*=t;
    if ((time1-d) <= 0){
        printf("NO");
    }
    else{
        int time2=0,t2,t1;
        if (d<t){
            time2+=t;
            t2=d;
            t1=t;
        }
        else{
            int mk=d/t;
            time2+=t;
            t2=(mk-1)*t-d;
            t1=t;
        }
        n-=k;
        while(n>0){
            if(n>0){//for oven 2
                n-=k;
                time2+=t2;
            }
            if (n>0){//for oven 1
                n-=k;
                time2+=t1;
            }
        }
        printf("T1=%d T2=%d\n",time1,time2);;
        if (time2<time1)    printf("YES");
        else                printf("NO");
    }
    return 0;
}
