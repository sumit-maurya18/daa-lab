#include <stdio.h>
#define INF 9999
#define MAX 10

int minDistance(int dist[], int visited[], int n) {
    int min = INF, min_index = -1;
    for (int v = 0; v < n; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(int graph[MAX][MAX], int src, int n) {
    int dist[MAX], visited[MAX];

    for (int i = 0; i < n; i++)
        dist[i] = INF, visited[i] = 0;

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    printf("Shortest distances from source vertex %d (Dijkstra):\n", src);
    for (int i = 0; i < n; i++)
        printf("Vertex %d -> Distance = %d\n", i, dist[i]);
}

int main() {
    int n = 5;
    int graph[MAX][MAX] = {
        {0, 10, 0, 5, 0},
        {0, 0, 1, 2, 0},
        {0, 0, 0, 0, 4},
        {0, 3, 9, 0, 2},
        {7, 0, 6, 0, 0}
    };

    printf("Dijkstra’s Algorithm – Single-Source Shortest Path\n");
    printf("\n\n");

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%3d ", graph[i][j]);
        printf("\n");
    }

    printf("\nShortest Paths from Source Vertex 0:\n");
    dijkstra(graph, 0, n);

    return 0;
}
