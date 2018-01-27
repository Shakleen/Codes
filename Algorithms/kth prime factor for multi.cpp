#include<bits/stdc++.h>
using namespace std;
const int MAX = 10001;
// Using SieveOfEratosthenes to find smallest prime factor of all the numbers.
// For example, if MAX is 10, s[2] = s[4] = s[6] = s[10] = 2 s[3] = s[9] = 3
// s[5] = 5 s[7] = 7
void sieveOfEratosthenes(int s[]){
    vector <bool> prime(MAX+1, false);// Create a boolean array "prime[0..MAX]" and initialize all entries in it as false.
    for (int i=2; i<=MAX; i+=2)       //Initializing smallest factor equal to 2 for all the even numbers
        s[i] = 2;
    for (int i=3; i<=MAX; i+=2){// For odd numbers less then equal to n
        if (prime[i] == false){
            s[i] = i;// s(i) for a prime is the number itself
            for (int j=i; j*i<=MAX; j+=2){// For all multiples of current prime number
                if (prime[i*j] == false){
                    prime[i*j] = true;
                    s[i*j] = i;// i is the smallest prime factor for number "i*j".
                }
            }
        }
    }
}
//Function to generate prime factors and return its k-th prime factor. s[i] stores least prime factor of i.
int kPrimeFactor(int n, int k, int s[]){
//Keep dividing n by least prime factor while either n is not 1 or count of prime factors is not k.
    while (n > 1){
        if (k == 1)
          return s[n];
        k--;// To keep tract of count of prime factors
        n /= s[n];// Divide n to find next prime factor
    }
    return -1;
}
int main(){// Driver Program
    int s[MAX+1];// s[i] is going to store prime factor of i.
    memset(s, -1, sizeof(s));
    sieveOfEratosthenes(s);
    int n = 12, k = 3;
    cout << kPrimeFactor(n, k, s) << endl;
    n = 14, k = 3;
    cout << kPrimeFactor(n, k, s) << endl;
    return 0;
}
