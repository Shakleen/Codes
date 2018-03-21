#include<bits/stdc++.h>
using namespace std;
int findMaxLen(string str){
    int n = str.length(), result = 0;// Initialize result
    stack<int> stk;     // Create a stack
    stk.push(-1);       // and push -1 as initial index to it.
    for (int i=0; i<n; i++){     // Traverse all characters of given string
        if (str[i] == '(')  stk.push(i);// If opening bracket, push index of it
        else{ // else closing bracket, pop the previous opening bracket's index
            stk.pop();
// Check if this length formed with base of current valid substring is more than max so far
            if (!stk.empty())   result = max(result, i - stk.top());
// If stack is empty. push current index as base for next valid substring (if any)
            else                stk.push(i);
        }
    }
    return result;
}
int main(){ // Driver program{
    string str = "((()()";
    cout << findMaxLen(str) << endl;
    return 0;
}
