struct Point{           // Used to save node and node distance information
    int NodeName,       // The node signifying number
        NodeDistance;   // The distance from source of this node
    bool operator<(const Point &a)const{    // Operator < overloading
        return Point.NodeDistance < NodeDistance;
    }
};
vector <int> Graph[SIZE+5]; // For Adjacency list
int Distance[SIZE+5],       // For distance from source
    Cost[SIZE+5][SIZE+5];   // Cost of edge from
priority_queue <Point> Q;   // For Greedy step
void Dijkstra (int Source){ // Main Algorithm
    Point Get, // Used for getting source
          Cur, // Used for processing in while loop
          Pr;  // Used for Updating in the for loop
    int CurName, CurDist, // Used for Cur
        PrName, PrDist;   // Used for Processing
    Get.NodeName = Source;
    Get.NodeDistance = Distance[Source] = 0;
    Q.push(Get);          // Pushing the source into the queue
    while (!Q.empty()){   // Run until queue is empty
        Cur = Q.top(), Q.pop(); // Get the top of the priority queue
        CurName = Cur.NodeName, CurDist = Cur.NodeDistance; // Setting cur variable
        for (int i=0; i<Graph[CurName].size(); i++){    // Going through all the adjacent nodes
            PrName = Graph[CurName][i], PrDist = Distance[CurName]; // Setting up the processing adjacent node
            if (PrDist > CurDist+Cost[CurName][PrName]){    // If the current path is shorter than any thus far
                PrDist = Distance[CurName] = CurDist+Cost[CurName][PrName]; // Update path distance
                Pr.NodeName = PrName, Pr.NodeDistance = PrDist; // Updating Processed node info
                Q.push(Pr); // Pushing processed node into priority queue
            }
        }
    }
}
