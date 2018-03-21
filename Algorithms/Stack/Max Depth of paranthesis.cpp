#include <bits/stdc++.h>
using namespace std;
string str;
int calculate(){
    int cnt=0, mx=INT_MIN;
    for(int i=0; i<str.size(); i++){
        if(str[i]=='(') cnt++;
        else if(cnt)    cnt--;
        else            return -1;
        mx = max(mx,cnt);
    }
    if(cnt) return -1;
    return mx;
}
int main(){
    cin>>str;
    cout<<calculate();
    return 0;
}
