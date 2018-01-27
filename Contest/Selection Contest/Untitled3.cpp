#include <bits/stdc++.h>
using namespace std;
#define NO 100001
int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int N = 0, c1 = 0, c2 = 0;

        scanf("%d", &N);

        int dist [N+1] = {};
        vector <int> v[N+2];
        queue <int> q;
        bool vis [NO] = {};

        memset(dist, 0, sizeof(dist));
        memset(vis, 0, sizeof(vis));

        for (int  i = 0; i < N; i++){
            int x = 0, y = 0, no = 0;

            scanf("%d %d", &x, &no);

            for (int j = 0; j < no; j++){
                scanf("%d", &y);

                v[x].push_back(y);
            }
        }

        scanf("%d %d", &c1, &c2);

        dist [c1] = 0;
        vis [c1] = true;

        q.push(c1);

        while ( !q.empty() ){
            int pop = q.front();
            q.pop();

            for (int in = 0; in < v[pop].size(); in++){
                if (!vis[v[pop][in]]){
                    dist [v[pop][in]] = dist [pop] + 1;
                    vis [v[pop][in]] = true;
                    q.push(v[pop][in]);
                }
            }
        }

        printf("%d %d %d\n", c1, c2, dist[c2]-1);
        if (cs != t)   printf("\n");
    }


    return 0;
}
