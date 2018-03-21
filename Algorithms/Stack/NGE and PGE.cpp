#include <bits/stdc++.h>
using namespace std;
#define N 100
int arr[N], NGE[N], PGE[N];
void nge(int n){// Finds next greater element
    stack<int>stk;
    for(int i=n-1; i>=0; i--){
        NGE[i] = -1;
        while(!stk.empty() && arr[stk.top()]<arr[i])    stk.pop();
        if(!stk.empty() && arr[stk.top()]>arr[i])       NGE[i] = stk.top();
        stk.push(i);
    }
    return;
}
void pge(int n){//Finds previous greater element
    stack<int>stk;
    for(int i=0; i<n; i++){
        PGE[i] = -1;
        while(!stk.empty() && arr[stk.top()]<arr[i])    stk.pop();
        if(!stk.empty() && arr[stk.top()]>arr[i])       PGE[i] = stk.top();
        stk.push(i);
    }
    return;
}
int main(){
    int n,i;
    cin>>n;
    for(i=0; i<n; i++)  cin>>arr[i];
    nge(n); cout<<"NGE\n";  for(i=0; i<n; i++)  cout<<i<<" -> "<<NGE[i]<<'\n';
    pge(n); cout<<"PGE\n";  for(i=0; i<n; i++)  cout<<i<<" -> "<<PGE[i]<<'\n';
    return 0;
}
