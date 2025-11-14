#include <stdio.h>
#define INF 9999
#define V 5

// Function to find the vertex with minimum key value not yet included in MST
int findMinKey(int key[], int included[])
{
    int min = INF, minIndex;
    for (int v = 0; v < V; v++)
        if (!included[v] && key[v] < min)
            min = key[v], minIndex = v;
    return minIndex;
}

// Function to print the constructed MST
void printMST(int parent[], int graph[V][V])
{
    int totalWeight = 0;
    printf("Edges in Minimum Spanning Tree (Prim’s Algorithm):\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d -- %d  (Weight = %d)\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Total Weight of MST = %d\n", totalWeight);
}

// Prim’s Algorithm
void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    int included[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INF;
        included[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = findMinKey(key, included);
        included[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !included[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    printf("Prim’s Algorithm – Minimum Spanning Tree\n");
    printf("\n");
    primMST(graph);

    return 0;
}
