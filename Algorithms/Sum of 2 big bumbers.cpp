#include <bits/stdc++.h>
using namespace std;
string summation(string num1, string num2){
    if(num1.length()>num2.length()) swap(num1,num2);//Number 2 must always be greater for this to work
    string res="";
    int len1=num1.length(),                          //length of number 1
        len2=num2.length(),                          //length of number 2
        diff=len2-len1,                              //difference of lengths
        sum=0,carry=0;                               //sum and carry for computation
    for(int i=len1-1; i>=0; i--){                    //Traverse from right to left
        sum = (num1[i]-'0')+(num2[i+diff]-'0')+carry;//sum of digits of number 1 & 2 at position i
        carry = sum/10;                              //Update carry value
        res.push_back(sum%10+'0');                   //Save sum unit value in res string
    }
    for(int i=len2-len1-1; i>=0; i--){               //Traverse remaining digits of number 2, as number 1 is done
        sum = (num2[i]-'0')+carry;                   //only number 2 digits are there because number 2 > number 1
        carry = sum/10;                              //Update carry value
        res.push_back(sum%10+'0');                   //Save sum unit value in res string
    }
    if(carry)   res.push_back(carry+'0');            //Save overflow carry
    reverse(res.begin(), res.end());                 //Reverse string res because calculation was done backwards
    return res;
}
int main(){                                          // Driver code
    string str1 = "12", str2 = "198111";
    cout << summation(str1, str2);
    return 0;
}
