#include <stdio.h>
int fib(int i);
int main(){
    int n=0;
    printf("Enter a value:\n");
    scanf("%d", &n);
    printf("Answer is %d\n", fib(n));
    return 0;
}
int fib(int i){
    if (i<=1)   return i;
    return fib(i-1)+fib(i-2);
}
