#include <bits/stdc++.h>
#define N 100001
int a,temp[N];
int main(){
    int n=0,i=0,maxN=0,loN=59999,sumN=0;
    scanf("%d", &n);
    for (i=0; i<n; i++){
        scanf("%d", &a);
        if (maxN<a)      maxN=a;
        if (loN>a)       loN=a;
        temp[a]++;
    }
    int round=0;
    for (i=loN; i<=maxN; round++){
        printf("Entering i=%d r=%d temp[i]=%d sumN=%d\n",i,round,temp[i],sumN);
        int j=0, k=0, m=0;
        if (round!=0){
            if (maxN>2)
                for (m=i+2; m<=maxN; m++){
                    if (temp[m]!=0 && j==0)         j=m;
                    else if (temp[m]!=0 && k==0)    k=m;
                    if (j!=0 && k!=0)               break;
                }
            else{
                j=i+1;
                k=i+2;
            }
            if (temp[j]*(j)<temp[k]*(k)){
                sumN+=temp[k]*(k);
                i+=3;
            }
            else{
                sumN+=temp[j]*(j);
                i+=2;
            }
        }
        else{
            int c=(temp[i]*i<temp[i+1]*(i+1)) && (temp[i+3]*(i+3)<temp[i+1]*(i+1));
            if (c){ sumN+=temp[i+1]*(i+1);       i++;}
            else    sumN+=temp[i]*i;
        }
        printf("Exiting sumN=%d i=%d j=%d k=%d ",sumN,i,j,k);
        printf("temp[i]=%d temp[j]=%d temp[k]=%d\n",temp[i],temp[j],temp[k]);
    }
    printf("%d", sumN);
    return 0;
}
