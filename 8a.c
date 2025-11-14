#include <stdio.h>

#define MAX 30

// Structure for an edge
struct Edge
{
    int source, destination, weight;
};

// Function to find set of an element (with path compression)
int findParent(int vertex, int parent[])
{
    if (parent[vertex] != vertex)
        parent[vertex] = findParent(parent[vertex], parent);
    return parent[vertex];
}

// Function to perform union of two subsets
void unionSets(int root1, int root2, int parent[])
{
    parent[root2] = root1;
}

// Function to sort edges by weight (Bubble Sort for simplicity)
void sortEdges(struct Edge edges[], int edgeCount)
{
    for (int i = 0; i < edgeCount - 1; i++)
    {
        for (int j = 0; j < edgeCount - i - 1; j++)
        {
            if (edges[j].weight > edges[j + 1].weight)
            {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

// Kruskal’s Algorithm
void kruskalMST(struct Edge edges[], int vertexCount, int edgeCount)
{
    struct Edge mst[MAX];
    int parent[MAX];
    int mstEdges = 0;
    int totalWeight = 0;

    for (int i = 0; i < vertexCount; i++)
        parent[i] = i;

    sortEdges(edges, edgeCount);

    for (int i = 0; i < edgeCount && mstEdges < vertexCount - 1; i++)
    {
        int root1 = findParent(edges[i].source, parent);
        int root2 = findParent(edges[i].destination, parent);

        if (root1 != root2)
        {
            mst[mstEdges++] = edges[i];
            totalWeight += edges[i].weight;
            unionSets(root1, root2, parent);
        }
    }

    printf("Edges in Minimum Spanning Tree (Kruskal’s Algorithm):\n");
    for (int i = 0; i < mstEdges; i++)
        printf("%d -- %d  (Weight = %d)\n", mst[i].source, mst[i].destination, mst[i].weight);
    printf("Total Weight of MST = %d\n", totalWeight);
}

int main()
{
    int vertexCount = 4, edgeCount = 5;

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    printf("Kruskal’s Algorithm – Minimum Spanning Tree\n");
    printf("\n");
    kruskalMST(edges, vertexCount, edgeCount);

    return 0;
}
