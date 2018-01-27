#include<bits/stdc++.h>
using namespace std;
int kPrimeFactor(int n, int k){
    while (n%2 == 0){//Find the number of 2's that divide k
        k--,    n = n/2;
        if (k == 0) return 2;
    }

//n must be odd at this point. So we can skip one element (Note i=i+2)
    for (int i = 3; i <= sqrt(n); i = i+2){
        while (n%i == 0){// While i divides n, store i and divide n
            if (k == 1)     return i;
            k--, n=n/i;
        }
    }
//This condition is to handle the case where n is a prime number greater than 2
    if (n > 2 && k == 1)
        return n;
    return -1;
}
int main(){// Driver Program
    int n = 12, k = 3;
    cout << kPrimeFactor(n, k) << endl;
    n = 14, k = 3;
    cout << kPrimeFactor(n, k) << endl;
    return 0;
}
