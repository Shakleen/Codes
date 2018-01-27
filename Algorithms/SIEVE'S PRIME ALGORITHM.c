/*
FINDING OUT PRIME WITHIN A GIVEN RANGE USING
SIEVE'S ALGORITHM
*/
//There's no way I can explain this to you with comments
//Google it!

#include <stdio.h>
#include <math.h>

int prime[100], nprime=0;
int mark[300];

int isprime(int no){
    int k=sqrt(no+1), i, flag=1;
    for (i=2; i<=k; i++){
        if (no%i==0){
            flag=0;
            break;
        }
    }
    if (flag)
        return 0;
    else
        return 1;
}

void findprime(int a,int b){
    int i,j, limit=sqrt(b+1.)+2;
    if (a<=2){
        mark[1]=1;
        prime[nprime++]=2;
        printf("%3d", prime[nprime-1]);
    }
    else{
        if (a%2==0){
            while(isprime(a))
                a++;
        }
    }
    for (i=3; i<=b; i+=2){
        if (!mark[i]){
            if(i>=a){
                prime[nprime++]=i;
                printf("%3d", prime[nprime-1]);
            }
            if (i<=limit){
                for (j=i*i; j<=b; j+=i*2){
                    mark[j]=1;
                }
            }
        }
    }
}

int main(){
    int a,b;
    printf("Enter range to find primes:\n");
    scanf("%d %d", &a, &b);
    findprime(a,b);
    return 0;
}
