struct Edge{
    int u, v, w;
};

vector <Edge> E;
int dist[100];
int n;

void Bellman_Ford(int s){
    for(int i=1; i<n; i++){
        dis[i] = 1e9;
    }

    dist[s] = 0;

    for (int i=1; i<n-1; i++){
        for (int j=0; j<E.size(); j++){
            Edge e = E[j];
            if (dist[e.v] > dist[e.u] + e.w){
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }
}
