#include <stdio.h>

long long int binary (int n);
int main(){
    int n;

    printf("Enter a decimal number to covert to binary!\n");
    scanf("%d", &n);

    printf("Binary form of %d is %I64d\n", n, binary(n));
    return 0;
}

long long int binary (int n){
    int j=n%2;
    n/=2;

    //Base case
    if (n==0)   return j;

    return j+10*binary(n);
}
