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

int fx[] = {1,-1,0,0};
int fy[] = {0,0,1,-1};

int main()
{
    int t=0,row=0,col=0,x=0,y=0,cnt=0,tx=0,ty=0;

    scanf("%d", &t);

    FOR(tc,1,t)
    {
        scanf("%d %d", &col, &row);

        vector< vector<char> > maze(row, vector<char>(col));
        vector< vector<bool> > vis(row, vector<bool>(col));
        queue< pii >Q;

        REP(i,row)
            REP(j,col){
                scanf(" %c", &maze[i][j]);
                if(maze[i][j] == '@')   x=i, y=j, cnt++;
            }

        vis[x][y] = true;
        Q.push(pii(x,y));

        while( !(Q.empty()) )
        {
            pii u = Q.front();
            Q.pop();
            REP(i,4)
            {
                tx = u.ff + fx[i],  ty = u.ss + fy[i];
                if(tx>=0 && tx<maze.size() && ty>=0 && ty<maze[0].size() && !vis[tx][ty] && maze[tx][ty]!='#')
                {
                    Q.push(pii(tx,ty));
                    vis[tx][ty] = true;
                    cnt++;
                }
            }
        }

        casep(tc);
        printf(" %d\n", cnt);
        cnt=0;
    }
    return 0;
}


