#include <bits/stdc++.h>

#define pii pair<int,int>

using namespace std;

//Directional arrays
int fx[4] = {1, -1, 0, 0};
int fy[4] = {0, 0, 1, -1};

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int w = 0, h = 0, startx = 0, starty = 0, cnt = 0;

        scanf("%d %d", &w, &h);

        queue < pii > q;
        bool vis [h+2] [w+2];

        memset(vis, false, sizeof(vis));
        while ( !q.empty() )    q.pop();

        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                char ch = 0;

                scanf(" %c", &ch);

                if (ch == '#'){
                    vis[i][j] = true;
                }
                else if (ch == '@'){
                    startx = j;
                    starty = i;
                    vis[i][j] = true;
                }
            }
        }

        q.push(pii(starty, startx));
        cnt++;

        while ( !q.empty() ){
            int popy = q.front().first, popx = q.front().second, tx = 0, ty = 0;
            q.pop();

            for (int i = 0; i < 4; i++){
                tx = popx + fx[i];
                ty = popy + fy[i];

                if (!vis[ty][tx] && tx >= 0 && ty >= 0 && tx < w && ty < h){
                    vis[ty][tx] = true;
                    cnt++;
                    q.push(pii(ty, tx));
                }
            }
        }

        printf("Case %d: %d\n", cs, cnt);
    }

    return 0;
}
