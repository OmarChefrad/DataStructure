#include <iostream>
#include <vector>
#include <list>
#include <queue>

class Graph {
private:
    int numVertices;
    std::vector<std::list<int>> adjLists;

    void DFSUtil(int v, std::vector<bool> &visited) {
        visited[v] = true;
        std::cout << v << " ";

        for (int adj : adjLists[v]) {
            if (!visited[adj]) {
                DFSUtil(adj, visited);
            }
        }
    }

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjLists.resize(vertices);
    }

    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src); // Pour un graphe non orienté, ajouter les deux arêtes
    }

    void DFS(int startVertex) {
        std::vector<bool> visited(numVertices, false);
        DFSUtil(startVertex, visited);
        std::cout << std::endl;
    }

    void BFS(int startVertex) {
        std::vector<bool> visited(numVertices, fal
