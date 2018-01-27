#include <stdio.h>
#include <math.h>
int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int L,U,i,j,div,maxdiv,maxdiv_no;
        L=U=i=j=div=maxdiv=maxdiv_no=0;
        scanf("%d %d", &L, &U);
        for (i=L; i<=U; i++){
            div=0;
            double val=sqrt(i);
            for(j=1; j<=val; j++){
                if(!(i%j)){
                    div++;
                    if (j!=i/j) div++;
                }
            }
            if(div>maxdiv){
                maxdiv=div;
                maxdiv_no=i;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,U,maxdiv_no,maxdiv);
    }
    return 0;
}
