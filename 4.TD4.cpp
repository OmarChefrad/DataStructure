#include <iostream>
#include <vector>

using namespace std;

// Define a class for representing a graph
class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Function to add an edge between vertices u and v
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Uncomment this line if the graph is undirected
    }

    // Function to print the adjacency list representation of the graph
    void printGraph() {
        for (int i = 0; i < V; ++i) {
            cout << "Adjacency list of vertex " << i << ": ";
            for (int j = 0; j < adj[i].size(); ++j) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Print the adjacency list representation of the graph
    g.printGraph();

    return 0;
}
