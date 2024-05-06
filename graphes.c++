#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure to represent an undirected graph
typedef struct {
    int numVertices;
    Node** adjacencyList;
    int* visited;
} Graph;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with given number of vertices
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    graph->numVertices = numVertices;
    graph->adjacencyList = (Node**)malloc(numVertices * sizeof(Node*));
    graph->visited = (int*)malloc(numVertices * sizeof(int));
    if (graph->adjacencyList == NULL || graph->visited == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Function to add an edge between two vertices in the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

// Function to perform DFS traversal of the graph
void DFS(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("%d ", vertex);
    Node* temp = graph->adjacencyList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (graph->visited[adjVertex] == 0) {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int numVertices = 5;
    Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    printf("Depth First Search Traversal: ");
    DFS(graph, 0);
    printf("\n");

    return 0;
}
