#include <iostream>

using namespace std;

int main(){
    int n=0, a[101], i=0;

    cin>>n;

    for(i=0; i<n; i++){
        cin>>a[i];
    }

    for(i=n-1; i>=0; i--){
        cout<<a[i]<<'\n';
    }

    return 0;
}
