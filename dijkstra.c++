#include <iostream>
#include <vector>
#include <queue>
#include <utility> // for std::pair
#include <limits>  // for std::numeric_limits

// Define the graph as an adjacency list
using namespace std;
const int INF = numeric_limits<int>::max();

void dijkstra(int source, const vector<vector<pair<int, int>>> &graph) {
    int n = graph.size();
    vector<int> distance(n, INF);
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start with the source node
    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node]) continue;
        visited[node] = true;

        // Explore neighbors
        for (const auto &neighbor : graph[node]) {
            int next_node = neighbor.first;
            int weight = neighbor.second;

            if (distance[node] + weight < distance[next_node]) {
                distance[next_node] = distance[node] + weight;
                pq.push({distance[next_node], next_node});
            }
        }
    }

    // Print shortest distances from source
    for (int i = 0; i < n; ++i) {
        if (distance[i] == INF)
            cout << "Distance from " << source << " to " << i << " is infinity" << endl;
        else
            cout << "Distance from " << source << " to " << i << " is " << distance[i] << endl;
    }
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<pair<int, int>>> graph(n);

    // Add edges (node1, node2, weight)
    graph[0].push_back({1, 10});
    graph[0].push_back({4, 3});
    graph[1].push_back({2, 2});
    graph[2].push_back({3, 9});
    graph[4].push_back({1, 1});
    graph[4].push_back({2, 8});

    int source = 0; // Starting node
    dijkstra(source, graph);

    return 0;
}
