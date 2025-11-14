#include <stdio.h>
#define INF 9999
#define V 4

void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    // Initialize distance matrix same as input graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Update distances considering each vertex as intermediate
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print final shortest distance matrix
    printf("Shortest distances between every pair (Floyd–Warshall):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 3, INF, 5},
        {2, 0, INF, 4},
        {INF, 1, 0, INF},
        {INF, INF, 2, 0}
    };

    printf("Floyd–Warshall Algorithm – All-Pairs Shortest Path\n");
    printf("\n\n");

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nAll-Pairs Shortest Paths:\n");
    floydWarshall(graph);

    return 0;
}
