#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define INF             5e13
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<LL,LL>
#define all(a)          a.begin(),a.end()
#define Unique(a)       sort(all(a)),a.erase(unique(all(a)),a.end())

#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define SQR(a)          ((a)*(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))

#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())

//#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr);
const int N = 100005;
int trie[26 * N][26],id = 1;
int mark[26 * N];

int main()
{
//   FastRead
   int n;
   cin >> n;

   while(n--)
   {
      string s;
      cin >> s;
      if(s == "add"){
         cin >> s;
         int row = 1;
         for(int i = 0;i < s.size();i++){
            int d = s[i] - 'a';
            if(trie[row][d] == 0){
               trie[row][d] = ++id;
            }
            row = trie[row][d];
            mark[row]++;
         }
      }else{
         cin >> s;
         int row = 1;
         for(int i = 0;i < s.size();i++){
            int d = s[i] - 'a';
            if(trie[row][d] == 0){
               trie[row][d] = ++id;
            }
            row = trie[row][d];
         }
         cout << mark[row] << "\n";
      }
   }


}
