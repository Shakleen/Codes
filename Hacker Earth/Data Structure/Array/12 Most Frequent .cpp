#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a[10000],c=1,j,mx=0,i=0;
    cin>>n;
    while(i<n)    cin>>a[i++];
    sort(a,a+n);
    j=a[0], i=1;
    while((i++)<n){
        if(a[i]==a[i-1])    c++;
        else{
            if(c>mx || (c==mx && j>a[i-1])) mx=c, j=a[i-1];
            c=1;
        }
    }
    if(c>mx || (c==mx && j>a[n-1]))        j=a[n-1];
    cout<<j;
    return 0;
}


