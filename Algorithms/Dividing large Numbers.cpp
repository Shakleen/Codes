#include <bits/stdc++.h>
using namespace std;
string divide(string number, int divisor){
    string quotient = "";                   //For storing answer
    int idx = 0,                            //Index position pointer of large number
        temp = number[idx]-'0';             //For segmenting large number
    while(temp < divisor)                   //Find prefix of number that is larger than divisor.
        temp = temp*10 + (number[++idx]-'0');
    while(number.size() > idx){
        quotient += ((temp/divisor) + '0'); //Saving result of the different stages of division
        temp = (temp%divisor)*10 + (number[++idx]-'0');//Updating temp to move on to the next stage
    }
    if(quotient.length())   return quotient;
    return "0";
}
int main(){// Driver program
    string number = "1248163264128256512";
    int divisor = 125;
    cout << divide(number, divisor);
    return 0;
}
