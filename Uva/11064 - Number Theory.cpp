#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=0,cnt=0,m=0,res=0,s=0;
    while(cin>>n){
        cnt=0, m=res=n, s=1;
        for(int i=2; i<=sqrt(m); i++){
            if(!(m%i)){
                cnt=1;
                while(!(m%i))   m/=i,   cnt++;
                s*=cnt, res-=(res/i);
            }
        }
        if(m>1) s*=2, res-=(res/m);
        cout<<n-res-s+1<<'\n';
    }
    return 0;
}
