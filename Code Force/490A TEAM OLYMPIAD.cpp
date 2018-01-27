#include <bits/stdc++.h>
int mn(int a, int b);
int main(){
    int n,i,skill[3]={};
    scanf("%d", &n);
    int child[n+2]={};
    for(i=0; i<n; i++){
        scanf("%d", &child[i]);
        skill[child[i]-1]++;
    }
    int w=mn(skill[0],mn(skill[1],skill[2]));
    printf("%d", w);;
    if(w){
        for(i=0; i<w; i++){
            int team[3]={}, j=0, k=1;
            while(k<4){
                if(child[j]==k){
                    team[k-1]=j+1;
                    child[j]=0;
                    k++;
                }
                if(j<n) j++;
                else    j=0;
            }
            printf("\n%d %d %d",team[0],team[1],team[2]);
        }
    }
    return 0;
}
int mn(int a, int b){
    if(a<b) return a;
    return b;
}
