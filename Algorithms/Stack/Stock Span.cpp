#include <bits/stdc++.h>
#define N 100
using namespace std;
int a[N], span[N];
void stockSpan(int n){
    stack<int>stk;
    for(int i=0; i<n; i++){
        span[i] = 1;
        while(!stk.empty() && a[stk.top()]<a[i])    stk.pop();
        (!stk.empty()) ? span[i] = i-stk.top() : span[i] = i+1;
        stk.push(i);
    }
    return;
}
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++)  cin>>a[i];
    stockSpan(n);
    for(int i=0; i<n; i++)  cout<<a[i]<<" -> "<<span[i]<<'\n';
    return 0;
}
