#include <bits/stdc++.h>
int sum(int a);
int main(){
    int n=0;
    printf("Enter range of summation:\n");
    scanf("%d", &n);
    printf("The answer is %d\n", sum(n));
    return 0;
}
int sum(int a){
    if (a==1)   return 1;
    return a+sum(a-1);
}
