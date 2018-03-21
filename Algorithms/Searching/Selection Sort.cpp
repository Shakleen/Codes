#include<bits/stdc++.h>
using namespace std;
void selection(int *a, int size){
    int i=0,j=0,mn=0;
    for(i = 0; i < size; i++){
        mn = i;
        for(j = i+1; j < size; j++)
            if(a[j] < a[mn])    mn = j;
            else                break;
        if (i!=mn)  swap(a[mn],a[i]);
    }
    return;
}

int main(){
    int a[] = {5,4,2};
    selection(a, 3);
    printf("%d %d %d", a[0],a[1],a[2]);
    return 0;
}
