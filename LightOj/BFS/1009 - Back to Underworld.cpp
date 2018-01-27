#include <bits/stdc++.h>
#define SIZE 20002

using namespace std;

int main(){
    int t = 0, n = 0, u = 0, v = 0, black = 0, white = 0, mx = 0;
    list <int> duel[SIZE];
    queue <int> q;
    int col [SIZE];

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++, mx = 0){
        scanf("%d", &n);

        while ( !q.empty() )                q.pop();
        for (int i = 1; i < SIZE; i++)      duel[i].clear();
        memset(col, 0, sizeof(col));

        for (int i = 0; i < n; i++){
            scanf("%d %d", &u, &v);

            duel[u].push_back(v);
            duel[v].push_back(u);
        }

        for (int i = 0; i < SIZE; i++, black = 0, white = 0){
            if (!duel[i].empty() && !col[i]){
                q.push(i);
                col[i] = 1;         //1 = black
                black++;

                while ( !q.empty() ){
                    int pop = q.front();
                    q.pop();

                    list <int>::iterator it;

                    for (it = duel[pop].begin(); it != duel[pop].end(); it++){
                        if (!col[*it]){
                            if (col[pop] == 1){
                                col[*it] = 2;  //2 = white
                                white++;
                            }
                            else{
                                col[*it] = 1;  //1 = black
                                black++;
                            }

                            q.push(*it);
                        }
                    }
                }

                mx += max(white, black);
            }
        }

        printf("Case %d: %d\n", cs, mx);
    }

    return 0;
}
