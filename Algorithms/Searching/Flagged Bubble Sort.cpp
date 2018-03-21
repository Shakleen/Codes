#include<bits/stdc++.h>
using namespace std;
void selection(int *a, int n){
    int i=0,j=0;
    bool flag = false;
    for(i = n-1; i > 0; i--){
        flag = true;
        for(j = 0; j < i; j++)
            if(a[j] < a[j+1])   swap(a[j],a[j+1]), flag = false;
        if (flag)   break;
    }
    return;
}
int main(){
    int a[] = {5, 2, 7};
    selection(a, 3);
    printf("%d %d %d", a[0],a[1],a[2]);
    return 0;
}
