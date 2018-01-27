#include <bits/stdc++.h>

int main(){
    int x,y,p,pos[26],flag=0;
    scanf("%d %d %d", &p, &x, &y);
    int j=(x/50)%475;
    for(int i=0; i<26; i++){
        pos[i]=( (j*96 + 42) % 475);
        j=pos[i];
        pos[i]+=26;
        if (pos[i]==p)  flag=1;
//        printf("%d\n",pos[i]);
    }
    if (flag){
        printf("0");
    }
    else{
        while(1){
            if ()
        }
    }
    return 0;
}
