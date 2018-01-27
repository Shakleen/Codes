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
#define casep(z)            printf("Case %d:\n", z);
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
    int t=0,row=0,col=0,qry=0,x=0,y=0,no=0,cnt=0,tx=0,ty=0;
    scanf("%d", &t);
    FOR(tc,1,t)
    {
        row=col=qry=x=y=tx=ty=cnt=no=0;

        scanf("%d %d %d", &row, &col, &qry);

        vector< vector<int> > vis(row, vector<int>(col));
        vector< vector<char> > maze(row, vector<char>(col));
        vector<int>ans;
        queue< pii > Q;

        REP(i,row)
            REP(j,col)
                scanf(" %c", &maze[i][j]);
//        REP(i,row){
//            REP(j,col)
//                printf("[%d][%d]%c", i,j,maze[i][j]);
//            printf("\n");
//        }

        REP(i,row)
        {
            REP(j,col)
            {
                if(!vis[i][j] && maze[i][j]!='#')
                {
                    no++,   cnt=0;
                    Q.push(pii(i,j));
                    vis[i][j] = no;
                    if(maze[i][j]=='C')   cnt++;
//                    printf("[%d][%d]\n",x,y);

                    while(!Q.empty())
                    {
                        pii u = Q.front();
                        Q.pop();

                        REP(k,4)
                        {
                            tx = u.ff + fx[k],  ty = u.ss + fy[k];
//                            printf("[%d][%d] ",tx,ty);
//                            if(tx>=0 && tx<row && ty>=0 && ty<col)  printf("ch = %c vis = %d",maze[tx][ty], vis[tx][ty]);
//                            printf(" Cnt = %d\n",cnt);
                            if(tx>=0 && tx<row && ty>=0 && ty<col && vis[tx][ty]!=no && maze[tx][ty]!='#')
                            {
                                if(maze[tx][ty]=='C')   cnt++;
                                Q.push(pii(tx,ty));
                                vis[tx][ty] = no;
//                                printf("[%d][%d] = %c count = %d\n",tx,ty,maze[tx][ty],cnt);
                            }
                        }
                    }

                    ans.push_back(cnt);
                }
            }
        }

        casep(tc);

        REP(i,qry)
        {
            scanf("%d %d", &x, &y);
            x--,    y--;

            if(maze[x][y]=='#')
            {
                printf("%d\n", 0);
                continue;
            }

            printf("%d\n", ans[vis[x][y]-1]);
        }

    }
    return 0;
}


