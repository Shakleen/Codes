#include <iostream>
using namespace std;
struct Edge{    int Source, Destination, Weight; };// Edge from Source to Destination
struct Graph{
    int NodeNo, EdgeNo;     // Number of nodes & edges in the graph
    struct Edge *EdgeList;  // For keeping a list of edges in the graph
};
struct Subset{  int parent, rank; }; // Rank means the depth
struct Graph* CreateGraph(int NumberOfNodes, int NumberOfEdges){
    struct Graph *G = new struct Graph;
    G->EdgeNo = NumberOfEdges;
    G->NodeNo = NumberOfNodes;
    G->EdgeList = new struct Edge[G->EdgeNo * sizeof(struct Edge)];
    return G;
}
int find (struct Subset subsets[], int i){
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
void Union (struct Subset Subsets[], int x, int y){
    // Finding the parent of x and y
    int xroot = find(Subsets, x), yroot = find(Subsets, y);
    // attach the subset with a smaller rank to the larger one
    if (Subsets[xroot].rank < Subsets[yroot].rank)
        Subsets[xroot].parent = yroot;
    else if (Subsets[yroot].rank < Subsets[xroot].rank)
        Subsets[yroot].parent = xroot;
    // If both ranks are same then attach one to the other & increment the rank of the other
    else
        Subsets[yroot].parent = xroot,  Subsets[xroot].rank++;
    return;
}
int Comp(const void* a, const void *b){
    struct Edge *a1 = (struct Edge*)a;
    struct Edge *b1 = (struct Edge*)b;
    return (a1->Weight > b1->Weight);
}
void KruskalMST(struct Graph *G){
    int NodeNo = G->NodeNo, e=0, i=0, x=0, y=0;
    struct Edge Result[NodeNo]; // For keeping resulting MST
    struct Subset SSet[NodeNo]; // Creating the sets
    // Sort edge of graph in non-decreasing order
    qsort(G->EdgeList, G->EdgeNo, sizeof(struct Edge), Comp);
    // Initializing the sets
    for (int i=0; i<NodeNo; i++){
        SSet[i].parent = i;
        SSet[i].rank = 0;
    }
    // Perform disjoint set operation and construct MST
    while (e < NodeNo-1){
        struct Edge NewEdge = G->EdgeList[i++];
        x = find(SSet, NewEdge.Source);
        y = find(SSet, NewEdge.Destination);
        if (x != y){
            Result[e++] = NewEdge;
            Union(SSet, x, y);
        }
    }
    // Result
    cout << "Following are the edges in the constructed MST\n";
    for (int i = 0; i < e; i++)
        cout << Result[i].Source << ' ' << Result[i].Destination << ' ' << Result[i].Weight << '\n';
    return;
}
// Driver program to test above functions
int main()
{
    /* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */
    int V = 4;  // Number of vertices in graph
    int E = 5;  // Number of edges in graph
    struct Graph* graph = CreateGraph(V, E);


    // add edge 0-1
    graph->EdgeList[0].Source = 0;
    graph->EdgeList[0].Destination = 1;
    graph->EdgeList[0].Weight = 10;

    // add edge 0-2
    graph->EdgeList[1].Source = 0;
    graph->EdgeList[1].Destination = 2;
    graph->EdgeList[1].Weight = 6;

    // add edge 0-3
    graph->EdgeList[2].Source = 0;
    graph->EdgeList[2].Destination = 3;
    graph->EdgeList[2].Weight = 5;

    // add edge 1-3
    graph->EdgeList[3].Source = 1;
    graph->EdgeList[3].Destination = 3;
    graph->EdgeList[3].Weight = 15;

    // add edge 2-3
    graph->EdgeList[4].Source = 2;
    graph->EdgeList[4].Destination = 3;
    graph->EdgeList[4].Weight = 4;

    KruskalMST(graph);

}
