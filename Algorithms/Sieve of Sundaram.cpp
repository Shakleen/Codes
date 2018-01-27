#include <bits/stdc++.h>
using namespace std;
int SieveOfSundaram(int n){
//In general Sieve of Sundaram, produces primes smaller than (2*x+2) for a number given number x.
//Since we want primes smaller than n, we reduce n to half
    int nNew = (n-2)/2;
//This array is used to separate numbers of the form i+j+2ij from others where 1<=i<=j
    bool marked[nNew + 1];
    memset(marked, false, sizeof(marked));  //Initalize all elements as not marked
// Main logic of Sundaram.  Mark all numbers of the form i+j+2ij as true where 1<=i<=j
    for (int i=1; i<=nNew; i++)
        for (int j=i; (i + j + 2*i*j) <= nNew; j++)
            marked[i + j + 2*i*j] = true;
//Since 2 is a prime number
    if (n > 2)
        cout << 2 << " ";
//Print other primes. Remaining primes are of the form 2*i+1 such that marked[i] is false.
    for (int i=1; i<=nNew; i++)
        if (marked[i] == false)
            cout << 2*i + 1 << " ";
}
int main(void){
    int n = 20;
    SieveOfSundaram(n);
    return 0;
}
