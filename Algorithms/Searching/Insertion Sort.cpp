#include<bits/stdc++.h>
using namespace std;
void insertion(int *a, int size){
    int i=0,j=0;
    for(i = 1; i < size; i++)
        for(j = i; j > 0; j--)
            if(a[j-1] > a[j])   swap(a[j],a[j-1]);
            else                break;
    return;
}

int main(){
    int a[] = {5,4,2};
    insertion(a, 3);
    printf("%d %d %d", a[0],a[1],a[2]);
    return 0;
}
