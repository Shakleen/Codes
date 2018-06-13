#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;
class Graph{
    list <int> *adj;    // Adjacency list for storing node relation
    int Nodes;          // Number of total nodes in the Graph
public:
    Graph(int NodeNo);  // Constructor to initialize the graph object
    void AddEdge(int src, int dst); // Adds an edge from src to dst
    void TopSort();     // Performs a topological sort on inputted graph
};
Graph::Graph(int NodeNo){
    this->Nodes = NodeNo;       // Setting total no of nodes
    adj = new list<int>[Nodes]; // Creating a list of Nodes number
}
void Graph::AddEdge(int src, int dst){
    adj[src].push_back(dst);
    return;
}
void Graph::TopSort(){
    vector <int> InDegree (Nodes, 0);   // Keep in degree information
    vector <int> TopOrder;              // Keep sorted list of nodes
    queue <int> ProcessQueue;           // For processing the graph
    list <int> :: iterator ListItr;
    vector <int> :: iterator VecItr;
    int CurrentNode = 0;
    int cnt = 0;                        // Keeping count of nodes sorted
    // Calculating In degree for each and every node
    for (int i = 0; i < Nodes; i++)
        for (ListItr : adj[i])
            InDegree[ListItr]++;
    // Initializing queue with nodes with 0 in-degree
    for (int i = 0; i < Nodes; i++)
        if (InDegree[i] == 0)
            ProcessQueue.push(i);
    // Topological sorting
    while (!ProcessQueue.empty()){
        CurrentNode = ProcessQueue.front();
        ProcessQueue.pop();
        TopOrder.push_back(CurrentNode);
        for (ListItr : adj[CurrentNode])
            if (--InDegree[ListItr] == 0)
                ProcessQueue.push(ListItr);
        cnt++;
    }
    //Cycle Check
    if (cnt != Nodes){
        cout << "Not Acyclic graph!\n";
        return;
    }
    for (VecItr : TopOrder)
        cout << VecItr << ' ';
    cout << "\n";
    return;
}
int main(){
    Graph g(6);
    g.AddEdge(5, 2);
    g.AddEdge(5, 0);
    g.AddEdge(4, 0);
    g.AddEdge(4, 1);
    g.AddEdge(2, 3);
    g.AddEdge(3, 1);
    cout << "Top sorting gives : ";
    g.TopSort();

    return 0;
}
