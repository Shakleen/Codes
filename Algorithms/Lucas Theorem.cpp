#include<bits/stdc++.h>
using namespace std;
// Returns nCr % p.  In this Lucas Theorem based program, this function is only called for n < p and r < p.
int nCrModpDP(int n, int r, int p){
//The array C is going to store last row of pascal triangle at the end. And last entry of last row is nCr
    int C[r+1];
    memset(C, 0, sizeof(C));
    C[0] = 1; // Top row of Pascal Triangle
    for (int i = 1; i <= n; i++)//One by constructs remaining rows of Pascal Triangle from top to bottom
        for (int j = min(i, r); j > 0; j--)//Fill entries of current row using previous row values
            C[j] = (C[j] + C[j-1])%p;      //Formula: nCj = (n-1)Cj + (n-1)C(j-1);
    return C[r];
}
// Lucas Theorem based function that returns nCr % p
// This function works like decimal to binary conversion recursive function.  First we compute last digits of
// n and r in base p, then recur for remaining digits
int nCrModpLucas(int n, int r, int p){
   if (r==0) return 1; //Base case
   int ni = n%p, ri = r%p;// Compute last digits of n and r in base p
//Compute result for last digits computed above, and for remaining digits.  Multiply the two results and
//compute the result of multiplication in modulo p.
   return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r
           nCrModpDP(ni, ri, p)) % p;  // Remaining digits
}
int main(){// Driver program
    int n = 1000, r = 900, p = 13;
    cout << "Value of nCr % p is " << nCrModpLucas(n, r, p);
    return 0;
}
