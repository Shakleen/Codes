#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

#define pii pair < int, int >

using namespace std;

bool mat[102][102];
bool vis[102][102];
int dist[10406];
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};

int main(){
    int n = 0, m = 0, k = 0, mx = 0;

    cin >> n >> m >> k;


    for (int i = 0; i < k; i++){
        int r = 0, c = 0;

        cin >> r >> c;

        mat[r][c] = true;
    }

    for (int i = 1; i < 101; i++){
        for (int j = 1; j < 101; j++){
            int cnt = 1;

            if (mat[i][j] && !vis[i][j]){
                queue < pii > q;
                q.push(make_pair(i,j));
                vis[i][j] = true;

                while (!q.empty()){
                    pii p = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++){
                        int x = p.first + fx[k], y = p.second + fy[k];

                        if (mat[x][y] && !vis[x][y]){
                            q.push(make_pair(x,y));
                            vis[x][y] = true;
                            cnt++;
                        }
                    }
                }

                mx = max(cnt,mx);
            }
        }
    }


    cout << mx << endl;

    return 0;
}
