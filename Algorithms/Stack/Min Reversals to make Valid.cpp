#include <bits/stdc++.h>
using namespace std;
stack<char>stk;
int calculate(string exp){
    if(exp.size()%2)    return -1;
    int cntOp=0, cntCl=0;
    for(int i=0; i<exp.size(); i++){
        if(exp[i]=='(')             stk.push(exp[i]);
        else if(stk.empty())        stk.push(exp[i]);
        else if (stk.top()=='(')    stk.pop();
        else if (stk.top()!='(')    stk.push(exp[i]);
    }
    while(!stk.empty()){
        if(stk.top()=='(')  cntOp++;
        else                cntCl++;
        stk.pop();
    }
    return (cntOp+1)/2 + (cntCl+1)/2;
}
int main(){
    string str;
    cin>>str;
    cout<<calculate(str);
    return 0;
}
