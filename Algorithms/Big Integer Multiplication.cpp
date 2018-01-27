#include <bits/stdc++.h>
using namespace std;
string multiply(string num1, string num2){
    int size1=num1.size(), //Size of number 1
        size2=num2.size(); //Size of number 2
    if(!size1 || !size2)    return "0";//Multiplying by 0 is 0
    vector<int> result(size1 + size2, 0);//Stores result. Initialized to 0
    string s = "";                       //Stores result converted to string from vector
    int sizeR=0,                         //Size of result
        idx1=0,                          //index position indicator for number 1
        idx2=0,                          //index position indicator for number 2
        digit1=0,                        //digit at index i of number 1
        digit2=0,                        //digit at index j of number 2
        carry=0,                         //Stores carry after each multiplication
        sum=0;                           //Stores sum after each multiplication
    for(int i=size1-1; i>=0; i--){       //Start from right to left
        carry=0;                         //Carry reverted to zero after each stage of multiplication
        digit1=num1[i]-'0';              //Digit of number 1 at index i saved as integer
        idx2=0;                          //After each stage of multiplication revert to start of number 2
        for(int j=size2-1; j>=0; j--){   //Start from right to left
            digit2=num2[j]-'0';          //Digit of number 1 at index i saved as integer
//sum = current multiplication + previously done multiplication sum + carry from previous index
            sum = digit1*digit2 + result[idx1+idx2] + carry;
            carry = sum/10;              //Carry for next index
            result[idx1+idx2] = sum%10;  //Store result
            idx2++;                      //Move on to the next index of number 2
        }
        if(carry)   result[idx1+idx2] += carry;//Overflow carry
        idx1++;                          //Move on to the next index of number 1
    }
    sizeR=result.size()-1;
    while (sizeR>=0 && result[sizeR] == 0)  sizeR--;// ignore '0's from the right
    if(sizeR == -1)    return "0";       //All digits were 0 means either or both numbers were 0
    while (sizeR >= 0)  s += (result[sizeR--]+'0');
    return s;
}
int main(){                             //Driver code
    string str1 = "1235421415454545454545454544", str2 = "1714546546546545454544548544544545";
    cout << multiply(str1, str2);
    return 0;
}
