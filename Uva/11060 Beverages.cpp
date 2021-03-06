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
#define FORL(i,a,b)         for(ll i = a; i <= b; i++)
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
#define sf1(x)              scanf("%d", &x)
#define sfl1(x)             scanf("%lld", &x)

//int fx[] = {1,-1,0,0};
//int fy[] = {0,0,1,-1};

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

map <string, int> Bev;

class Graph{
    list <string> *adj;    // Adjacency list for storing node relation
    int Nodes;          // Number of total nodes in the Graph
public:
    Graph(int NodeNo);  // Constructor to initialize the graph object
    void AddEdge(string src, string dst); // Adds an edge from src to dst
    void TopSort();     // Performs a topological sort on inputted graph
};
Graph::Graph(int NodeNo){
    this->Nodes = NodeNo;       // Setting total no of nodes
    adj = new list<string>[Nodes]; // Creating a list of Nodes number
}
void Graph::AddEdge(string src, string dst){
    adj[src].push_back(dst);
    return;
}
void Graph::TopSort(){
    vector <string> InDegree (Nodes, 0);   // Keep in degree information
    vector <string> TopOrder;              // Keep sorted list of nodes
    queue <string> ProcessQueue;           // For processing the graph
    list <string> :: iterator ListItr;
    vector <string> :: iterator VecItr;
    int CurrentNode = 0;
    int cnt = 0;                        // Keeping count of nodes sorted
    // Calculating In degree for each and every node
    for (int i = 0; i < Nodes; i++)
        for (ListItr=adj[i].begin(); ListItr != adj[i].end(); ListItr++)
            InDegree[*ListItr]++;
    // Initializing queue with nodes with 0 in-degree
    for (int i = 0; i < Nodes; i++)
        if (!InDegree[i])
            ProcessQueue.push(i);
    // Topological sorting
    while (!ProcessQueue.empty()){
        CurrentNode = ProcessQueue.front();
        ProcessQueue.pop();
        TopOrder.push_back(CurrentNode);
        for (ListItr = adj[CurrentNode].begin(); ListItr != adj[CurrentNode].end(); ListItr++)
            if (--InDegree[*ListItr] == 0)
                ProcessQueue.push(*ListItr);
        cnt++;
    }
    //Cycle Check
    if (cnt != Nodes){
        cout << "Not Acyclic graph!\n";
        return;
    }
    for (VecItr = TopOrder.begin(); VecItr != TopOrder.end(); VecItr++)
        cout << ' ' << VecItr;
    cout << '\n';
    return;
}

int main(){
    FAST();

//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    int n=0, m=0;
    string name, name2;

    for (int tc=1; ; tc++){
        Bev.clear();
        Graph g(n);

        FOR(i,1,n){
            cin >> name;
            Bev[name] = i+1;
        }

        cin >> m;

        REP(i,m){
            cin >> name >> name2;
            g.AddEdge(name, name2);
        }

        cout << "Case #" << tc << ": Dilbert should drink beverages in this order:";
    }


//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);

    return 0;
}


