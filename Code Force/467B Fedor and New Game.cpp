#include <bits/stdc++.h>

int main(){
    int n,m,k,frnd=0;
    scanf("%d %d %d",&n, &m, &k);
    int i, loop=m+1, x[m+5], bits1[n+5], bits2[n+5];
    for(i=1; i<=loop; i++){
        scanf("%d", &x[i]);
        if (i==loop){
            int j=0, num=x[i];
            for(j=0; j<n; j++){
                bits1[j]=num%2;
                num/=2;
            }
        }
    }
    for(i=1; i<loop; i++){
        int num=x[i], j=0, cnt=0, flag=1;
        //converting binary
        for(j=0; j<n; j++){
            bits2[j]=num%2;
            num/=2;
        }
        //comparing binary
        for(j=0; j<n; j++){
            if (bits1[j] != bits2[j]){
                cnt++;
                if (cnt>k){
                    flag=0;
                    break;
                }
            }
        }
        if (flag)  frnd++;
    }
    printf("%d", frnd);
    return 0;
}
