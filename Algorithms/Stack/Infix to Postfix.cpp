#include <bits/stdc++.h>
using namespace std;
string postfix,infix;
void convert(){
    stack<char>stk;
    char ch;
    for(int i=0; i<infix.size(); i++){
        ch = infix[i];
        if(ch>='0' && ch<='9')  postfix += ch;// Operands get directly pushed to postfix string
        else{// Otherwise some conditions must be checked
            if(ch=='(')           stk.push(ch);
            else if (ch==')'){
                while(stk.top()!='(' && !stk.empty()) postfix += stk.top(), stk.pop();
                if(!stk.empty()) stk.pop();
            }
            else{
                if (ch=='*')
                    while(!stk.empty() && (stk.top()=='/'))
                        postfix += stk.top(),    stk.pop();
                else if (ch=='/')
                    while(!stk.empty() && (stk.top()=='*'))
                        postfix += stk.top(),    stk.pop();
                else if (ch=='+')
                    while(!stk.empty() && (stk.top()=='*'||stk.top()=='/'||stk.top()=='-'))
                        postfix += stk.top(),    stk.pop();
                else if (ch=='-')
                    while(!stk.empty() && (stk.top()=='*'||stk.top()=='/'||stk.top()=='-'))
                            postfix += stk.top(),    stk.pop();
                stk.push(ch);
            }
        }
    }
    while(!stk.empty()) postfix += stk.top(), stk.pop();
    return;
}
int main(){
    cin>>infix;
    convert();
    cout<<postfix;
    return 0;
}
