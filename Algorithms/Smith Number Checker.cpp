#include<bits/stdc++.h>
using namespace std;
const int MAX  = 10000;
vector <int> primes;// array to store all prime less than and equal to 10^6
void sieveSundaram(){
//In general Sieve of Sundaram, produces primes smaller than (2*x+2) for a number given number x. Since
//we want primes smaller than MAX, we reduce MAX to half
//This array is used to separate numbers of the form i+j+2ij from others where 1 <= i <= j
    bool marked[MAX/2 + 100] = {0};
//Main logic of Sundaram. Mark all numbers which do not generate prime number by doing 2*i+1
    for (int i=1; i<=(sqrt(MAX)-1)/2; i++)
        for (int j=(i*(i+1))<<1; j<=MAX/2; j=j+2*i+1)
            marked[j] = true;
    primes.push_back(2);    // Since 2 is a prime number
//Print other primes. Remaining primes are of the form 2*i + 1 such that marked[i] is false.
    for (int i=1; i<=MAX/2; i++)
        if (marked[i] == false)
            primes.push_back(2*i + 1);
}
bool isSmith(int n){//Returns true if n is a Smith number, else false.
    int original_no = n, pDigitSum = 0;//Find sum the digits of prime factors of n
    for (int i = 0; primes[i] <= n/2; i++){
        while (n % primes[i] == 0){//If primes[i] is a prime factor, add its digits to pDigitSum.
            int p = primes[i];
            n = n/p;
            while (p > 0){
                pDigitSum += (p % 10);
                p = p/10;
            }
        }
    }
    if (n != 1 && n != original_no){//If n!=1 then one prime factor still to be summed up;
        while (n > 0){
            pDigitSum = pDigitSum + n%10;
            n = n/10;
        }
    }
//All prime factors digits summed up. Now sum the original number digits
    int sumDigits = 0;
    while (original_no > 0){
        sumDigits = sumDigits + original_no % 10;
        original_no = original_no/10;
    }
//If sum of digits in prime factors and sum of digits in original number are same, then return true. Else return false.
    return (pDigitSum == sumDigits);
}
int main(){
//Finding all prime numbers before limit. These numbers are used to find prime factors.
   sieveSundaram();
   cout << "Printing first few Smith Numbers using isSmith()n";
   for (int i=1; i<500; i++)
      if (isSmith(i))
          cout << i << " ";
    return 0;
}
