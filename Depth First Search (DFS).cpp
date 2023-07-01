#include <iostream>
#include <stack>

// Structure to represent a node in the graph
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge between two nodes in the graph
void addEdge(Node* adjacencyList[], int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjacencyList[src];
    adjacencyList[src] = newNode;

    newNode = createNode(src);
    newNode->next = adjacencyList[dest];
    adjacencyList[dest] = newNode;
}

// Depth First Search algorithm
void dfs(Node* adjacencyList[], int start, bool visited[]) {
    std::stack<int> stack;
    stack.push(start);

    while (!stack.empty()) {
        int currNode = stack.top();
        stack.pop();

        if (!visited[currNode]) {
            visited[currNode] = true;
            std::cout << currNode << " ";

            Node* temp = adjacencyList[currNode];
            while (temp != NULL) {
                if (!visited[temp->data])
                    stack.push(temp->data);
                temp = temp->next;
            }
        }
    }
}

int main() {
    int numNodes, numEdges;
    std::cout << "Enter the number of nodes: ";
    std::cin >> numNodes;
    std::cout << "Enter the number of edges: ";
    std::cin >> numEdges;

    Node* adjacencyList[numNodes];
    bool visited[numNodes] = {false};

    // Initialize adjacency list with NULL pointers
    for (int i = 0; i < numNodes; ++i) {
        adjacencyList[i] = NULL;
    }

    std::cout << "Enter the edges (source destination):\n";
    for (int i = 0; i < numEdges; ++i) {
        int src, dest;
        std::cin >> src >> dest;
        addEdge(adjacencyList, src, dest);
    }

    int startNode;
    std::cout << "Enter the starting node for DFS: ";
    std::cin >> startNode;

    std::cout << "DFS traversal starting from node " << startNode << ": ";
    dfs(adjacencyList, startNode, visited);
    std::cout << std::endl;

    return 0;
}

