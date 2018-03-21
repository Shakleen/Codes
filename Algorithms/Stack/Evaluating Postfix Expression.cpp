#include <bits/stdc++.h>
using namespace std;
stack<int>stk;
int evaluate(){
    char ch=0;
    int x=0,y=0,n=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>ch;
        if(ch>='0' && ch<='9')  stk.push(ch-'0');
        else{
            x = stk.top(),  stk.pop();
            y = stk.top(),  stk.pop();
            if(ch == '+')       x += y;
            else if (ch == '-') x -= y;
            else if (ch == '*') x *= y;
            else if (ch == '/') x /= y;
            stk.push(x);
        }
    }
    return stk.top();
}
int main(){
    cout<<evaluate();
    return 0;
}
