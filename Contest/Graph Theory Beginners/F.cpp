#include <bits/stdc++.h>

using namespace std;

//*******************************************************************************
//*******************************Template****************************************
//*******************************************************************************

#define eps                 1e-6
#define ll                  long long
#define llu                 long long unsigned
#define ld                  long double
#define REP(i,n)            for(int i = 0; i < n; i++)
#define FLR(i,n)            for(ll i = 0; i < n; i++)
#define ROF(i,n)            for(int i = n-1; i >= 0; i--)
#define FOR(i,a,b)          for(int i = a; i <= b; i++)
#define repl(i,a,b)         for(ll i = a; i <= b; i++)
#define casep(z)            printf("Case %d:", z);
#define sz(a)               a.size()
#define all(x)              x.begin(),x.end()
#define SORT(a,n)           sort(a,a+n)
#define RSORT(a,n)          sort(a,a+n,greater<ll>())
#define VSORT(v)            sort(all(v))
#define VRSORT(v)           sort(all(v),greater<ll>())
#define pii                 pair <int, int>
#define pll                 pair <ll, ll>
#define pb                  push_back
#define pf                  push_front
#define pob                 pop_back()
#define pof                 pop_front()
#define ff                  first
#define ss                  second
#define mp                  make_pair
#define ms(x,n)             memset((x),n,sizeof(x))
#define fin                 freopen("in.txt", "r", stdin)
#define fout                freopen("out.txt", "w", stdout)
#define IT(it,x)            for(it=x.begin(); it != x.end(); it++)

int fx[] = {1,-1,0,0,1,1,-1,-1};
int fy[] = {0,0,1,-1,1,-1,1,-1};

void FAST()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    FAST();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int row = 0, col = 0,  cnt = 0, tx = 0, ty = 0;
    char ch = 0;

    while(cin>>row>>col)
    {
        if(!row && !col)    return 0;

        vector< vector<bool> > vis (row, vector<bool>(col));
        queue< pii >Q;

        REP(i,row){
            REP(j,col){
                cin>>ch;
                if(ch=='@') vis[i][j] = false;
                else        vis[i][j] = true;
            }
        }
//        REP(i,row){
//            REP(j,col)
//                cout<<vis[i][j];
//            cout << endl;
//        }
        cnt = 0;

        REP(i,row)
        {
            REP(j,col)
            {
                if(!vis[i][j])
                {
                    cnt++;
                    Q.push(pii(i,j));
                    vis[i][j] = true;

                    while( !Q.empty() )
                    {
                        pii u = Q.front();
                        Q.pop();

                        REP(k,8)
                        {
                            tx = u.ff + fx[k],  ty = u.ss + fy[k];

                            if(tx>=0 && tx<row && ty>=0 && ty<col && !vis[tx][ty])
                            {
                                Q.push(pii(tx,ty));
                                vis[tx][ty] = true;
                            }
                        }
                    }
                }
            }
        }

        cout<<cnt<<'\n';
    }
}


