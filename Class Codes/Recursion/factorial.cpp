#include <bits/stdc++.h>
int fact(int i);
int main(){
    int n=0;
    printf("Enter a value:\n");
    scanf("%d", &n);

    printf("The answer is %d\n",fact(n));
    return 0;
}
int fact(int i){
    if (i==1)   return 1;
    return i*fact(i-1);
}
