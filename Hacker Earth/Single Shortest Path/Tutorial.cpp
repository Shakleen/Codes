#include <bits/stdc++.h>
#define SIZE 10
using namespace std;
struct point{
    int name, val;
    bool operator <(const point &a)const{
        return a.val<val;
    }
};

priority_queue <point> Q;
int dis[SIZE+5], cost[SIZE+5][SIZE+5];
vector <int> Graph[SIZE+5];

void DJ(int s){
    dis[s] = 0;
    point get;
    get.name = s;
    get.val = 0;
    Q.push(get);
    while (!Q.empty()){
        point temp = Q.top();
        Q.pop();
        int now = temp.name;
        for(int i=0; i<Graph[now].size(); i++){
            int x = Graph[now][i];
            if (dis[now]+cost[now][x] < dis[x]){
                dis[x] = dis[now]+cost[now][x];
                point get;
                get.name = x;
                get.val = dis[x];
                Q.push(get);
            }
        }
    }
    return;
}
