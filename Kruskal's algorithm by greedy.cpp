// kruskal's algorithm by greedy

#include <bits/stdc++.h>
using namespace std;

// Structure to represent a weighted edge in the graph
struct Edge {
    int u, v, w;
};

// Comparator function to sort edges by weight in ascending order
bool compareEdges(Edge a, Edge b) {
    return a.w < b.w;
}

// Function to find the parent of a node in a union-find data structure
int find(int parent[], int node) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = find(parent, parent[node]);
}

// Function to perform union of two nodes in a union-find data structure
void unionNodes(int parent[], int rank[], int u, int v) {
    int parentU = find(parent, u);
    int parentV = find(parent, v);
    if (rank[parentU] < rank[parentV]) {
        parent[parentU] = parentV;
    } else if (rank[parentU] > rank[parentV]) {
        parent[parentV] = parentU;
    } else {
        parent[parentV] = parentU;
        rank[parentU]++;
    }
}

// Function to find the minimum spanning tree of a graph using Kruskal's algorithm
void kruskal(vector<Edge> edges, int numNodes) {
    // Sort edges by weight in ascending order
    sort(edges.begin(), edges.end(), compareEdges);
    
    // Initialize parent and rank arrays for union-find data structure
    int parent[numNodes], rank[numNodes];
    for (int i = 0; i < numNodes; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    
    // Initialize MST and total weight of MST
    vector<Edge> mst;
    int mstWeight = 0;
    
    // Iterate over sorted edges and add edge to MST if it doesn't create a cycle
    for (auto edge : edges) {
        if (find(parent, edge.u) != find(parent, edge.v)) {
            mst.push_back(edge);
            mstWeight += edge.w;
            unionNodes(parent, rank, edge.u, edge.v);
        }
    }
    
    // Print MST edges and total weight
    cout << "Minimum Spanning Tree Edges:\n";
    for (auto edge : mst) {
        cout << edge.u << " - " << edge.v << " : " << edge.w << "\n";
    }
    cout << "Total Weight: " << mstWeight << "\n";
}

int main() {
    // Take input from user: number of nodes, number of edges, and edges
    int numNodes, numEdges;
    cout << "Enter number of nodes and edges:\n";
    cin >> numNodes >> numEdges;
    
    vector<Edge> edges;
    cout << "Enter edges in format <u> <v> <w>:\n";
    for (int i = 0; i < numEdges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    
    // Find minimum spanning tree using Kruskal's algorithm and print result
    kruskal(edges, numNodes);
    
    return 0;
}

