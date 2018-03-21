#include <bits/stdc++.h>
#define N 100
using namespace std;
bool a[N][N];
int findCelebrity(int n){
    stack<int>s;
    for(int i=0; i<n; i++)  s.push(i);
    int A,B,C;
    A = s.top(), s.pop();
    B = s.top(), s.pop();
    while(s.size()>1)
        if(a[A][B]) A = s.top(), s.pop();// A knows B so A isn't celebrity
        else        B = s.top(), s.pop();// B knows A so B isn't celebrity
    C = s.top(), s.pop();
    if(a[C][B])     C = B;
    else if(a[C][A])C = A;
    for(int i=0; i<n; i++)  if(i!=C && (a[C][i] && !a[i][C]))   return -1;
    return C;
}
int main(){
    int no=0;
    cin>>no;
    for(int i=0; i<no; i++)  for(int j=0; j<no; j++)  cin>>a[i][j];
    cout<<findCelebrity(no);
    return 0;
}
