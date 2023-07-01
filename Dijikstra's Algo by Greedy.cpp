#include <iostream>
#include <climits>

#define INF INT_MAX

// Function to find the vertex with the minimum distance value
int findMinDistanceVertex(int* dist, bool* visited, int V) {
    int minDist = INF;
    int minVertex = -1;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= minDist) {
            minDist = dist[v];
            minVertex = v;
        }
    }

    return minVertex;
}

// Function to perform Dijkstra's algorithm
void dijkstra(int** graph, int V, int src) {
    int dist[V];
    bool visited[V];

    // Initialize the distance array and visited array
    for (int v = 0; v < V; v++) {
        dist[v] = INF;
        visited[v] = false;
    }

    // Distance of source vertex from itself is 0
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = findMinDistanceVertex(dist, visited, V);

        // Mark the selected vertex as visited
        visited[u] = true;

        // Update the distances of the adjacent vertices
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distances
    std::cout << "Shortest distances from source vertex " << src << ":\n";
    for (int v = 0; v < V; v++) {
        if (dist[v] == INF) {
            std::cout << v << ": INF\n";
        } else {
            std::cout << v << ": " << dist[v] << "\n";
        }
    }
}

int main() {
    int V, E;
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;
    std::cout << "Enter the number of edges: ";
    std::cin >> E;

    // Create a 2D array to represent the graph
    int** graph = new int*[V];
    for (int i = 0; i < V; i++) {
        graph[i] = new int[V];
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    std::cout << "Enter the edges and their weights (source destination weight):\n";
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        std::cin >> src >> dest >> weight;
        graph[src][dest] = weight;
        graph[dest][src] = weight; // If the graph is undirected
    }

    int src;
    std::cout << "Enter the source vertex: ";
    std::cin >> src;

    dijkstra(graph, V, src);

    // Free the dynamically allocated memory
    for (int i = 0; i < V; i++) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}

