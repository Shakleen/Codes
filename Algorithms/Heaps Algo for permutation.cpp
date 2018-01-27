#include <bits/stdc++.h>
using namespace std;
void printArr(int a[],int n){//Prints the array
    for (int i=0; i<n; i++)
        cout << a[i] << " ";
    printf("\n");
}
void heapPermutation(int a[], int size, int n){//Generating permutation using Heap Algorithm
    if (size == 1){//if size becomes 1 then prints the obtained permutation
        printArr(a, n);
        return;
    }

    for (int i=0; i<size; i++){
        heapPermutation(a,size-1,n);
        if (size%2==1)  swap(a[0], a[size-1]);//if size is odd, swap first and last element
        else            swap(a[i], a[size-1]);//If size is even, swap ith and last element
    }
}
int main(){//Driver code
    int a[] = {1, 2, 3}, n = sizeof a/sizeof a[0];
    heapPermutation(a, n, n);
    return 0;
}
