#include <iostream>

using namespace std;

int main(){
    int t=0, n=0, k=0, a=0, i=0, mn=2147483647;
cout<<INT_MAX;
    cin>>t;

    while(t--){
        cin>>n>>k;

        mn=2147483647;

        for(i=0; i<n; i++){
            cin>>a;
            mn = min(a,mn);
        }

        if (mn<k)   cout<<k-mn;
        else        cout<<0;

        cout<<'\n';
    }

    return 0;
}
