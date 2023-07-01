#include <iostream>
#include <climits>

#define INF INT_MAX

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Function to perform the Bellman-Ford algorithm
void bellmanFord(Edge* edges, int V, int E, int src) {
    int dist[V];

    // Initialize the distance array
    for (int i = 0; i < V; i++) {
        if (i == src) {
            dist[i] = 0;
        } else {
            dist[i] = INF;
        }
    }

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            std::cout << "Graph contains negative-weight cycle\n";
            return;
        }
    }

    // Print the shortest distances
    std::cout << "Shortest distances from source vertex " << src << ":\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) {
            std::cout << i << ": INF\n";
        } else {
            std::cout << i << ": " << dist[i] << "\n";
        }
    }
}

int main() {
    int V, E;
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;
    std::cout << "Enter the number of edges: ";
    std::cin >> E;

    Edge* edges = new Edge[E];

    std::cout << "Enter the edges and their weights (source destination weight):\n";
    for (int i = 0; i < E; i++) {
        std::cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    int src;
    std::cout << "Enter the source vertex: ";
    std::cin >> src;

    bellmanFord(edges, V, E, src);

    delete[] edges;

    return 0;
}

