#include <stdio.h>

#define V 5  // Number of vertices

int path[V];        // To store the Hamiltonian path
int graph[V][V];    // Adjacency matrix

// Function to check if current vertex can be added to Hamiltonian Cycle
int isSafe(int v, int pos) {
    // Check if this vertex is adjacent to the previous vertex in path
    if (graph[path[pos - 1]][v] == 0)
        return 0;

    // Check if vertex already exists in the path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;

    return 1;
}

// Recursive function to find Hamiltonian cycles
void hamCycleUtil(int pos) {
    // Base case: if all vertices are included in the path
    if (pos == V) {
        // Check if last vertex is connected to the first vertex
        if (graph[path[pos - 1]][path[0]] == 1) {
            printf("Hamiltonian Cycle found: ");
            for (int i = 0; i < V; i++)
                printf("%d ", path[i]);
            printf("%d\n", path[0]);  // To show cycle back to start
        }
        return;
    }

    // Try different vertices as next candidate
    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;
            hamCycleUtil(pos + 1);
            path[pos] = -1;  // Backtrack
        }
    }
}

// Function to find all Hamiltonian cycles in the graph
void hamCycle() {
    // Initialize path[] to -1
    for (int i = 0; i < V; i++)
        path[i] = -1;

    // Start from vertex 0
    path[0] = 0;

    printf("All Hamiltonian Cycles in the given graph:\n");
    hamCycleUtil(1);
}

int main() {
    // Example graph (Undirected)
    int temp[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    // Copy to graph[][]
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = temp[i][j];

    printf("Adjacency Matrix of Graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    printf("\nFinding Hamiltonian Cycles using Backtracking...\n\n");
    hamCycle();

    printf("\n\n");
    return 0;
}
