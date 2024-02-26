#include <stdio.h>

#define INF 99999
#define V 4

void printSolution(int dist[][V]) {
    printf("Shortest distances between every pair of vertices:\n");
    int i, j, k;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if(dist[i][j] == INF) {
                printf("INF\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}

void floydWarshall(int graph[][V]) {
    int dist[V][V];
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    int k;
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printSolution(dist);
}

int main() {
    int graph[V][V];

    printf("Enter the graph (enter INF for infinity):\n");
int i,j;
    for ( i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("Enter distance from vertex %d to vertex %d: ", i + 1, j + 1);
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph);

    return 0;
}
