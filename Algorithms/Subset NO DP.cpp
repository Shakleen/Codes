#include <bits/stdc++.h>

using namespace std;

//*******************************************************************************
//*******************************MACROS******************************************
//*******************************************************************************

#define N                   100000000
#define MOD                 1e9+7
#define ll                  long long
#define ull                 unsigned long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define pii                 pair <int, int>
#define FOR(i,n)            for(ll i = 0; i <= n; i++)
#define REP(i,n)            for(ll i = 0; i < n; i++)
#define ROF(i,n)            for(ll i = n; i >= 0; i--)
#define FORSTL(i,n)         for(__typeof(n.begin())i = n.begin(); i!=n.end() ;i++)
#define all(v)              v.begin(),v.end()
#define SORT(v)             sort(all(v))
#define REV(v)              reverse(v.begin(),v.end())
#define asort(m,n)          sort(a+m,a+n)
#define ms(ar,m)            memset(ar,m,sizeof ar)
#define ff                  first
#define ss                  second
#define pb                  push_back
#define mp                  make_pair

//*******************************************************************************
//*****************************FUNCTIONS*****************************************
//*******************************************************************************

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

vector <char>c;

void subset(string& str, int idx){
    if (idx == str.size()){
        for (int i = 0; i < c.size(); i++)          cout << c[i];
        cout << '\n';
        return;
    }
    subset(str,idx+1);
    c.pb(str[idx]);
    subset(str,idx+1);
    c.pop_back();
    return;
}

int main(){
    //FAST();

    int sz = 0;
    string str;

    while (cin >> str)
    {
        subset(str,0);
    }
    return 0;
}
