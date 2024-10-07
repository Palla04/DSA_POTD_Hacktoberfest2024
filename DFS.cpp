#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
    // Number of vertices
    int V;
    // Adjacency list to store graph
    vector<list<int>> adj;

    // Utility function for DFS traversal
    void DFSUtil(int v, vector<bool>& visited)
    {
        // Mark the current node as visited
        visited[v] = true;
        cout << v << " ";

        // Recur for all the vertices adjacent to this vertex
        for (int i : adj[v]) {
            if (!visited[i])
                // Recur for the unvisited adjacent nodes
                DFSUtil(i, visited);
        }
    }

public:
    // Constructor to initialize graph with V vertices
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w) { adj[v].push_back(w); }

    // DFS traversal of the vertices reachable from v
    void DFS(int v)
    {
        // Mark all vertices as not visited
        vector<bool> visited(V, false);
        // Call the recursive helper function to print DFS traversal
        DFSUtil(v, visited);
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;

    Graph g(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (source and destination):" << endl;
    for (int i = 0; i < E; ++i) {
        int v, w;
        cin >> v >> w;
        g.addEdge(v, w);
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    // Print the DFS traversal starting from user-defined vertex
    cout << "Depth First Traversal (starting from vertex " << startVertex << "): ";
    g.DFS(startVertex);
    cout << endl;

    return 0;
}
