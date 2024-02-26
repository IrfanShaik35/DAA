#include <stdio.h>

#define V 5

int graph[V][V] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

int path[V];

void printPath() {
    printf("Hamiltonian Circuit: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d", path[0]); // Complete the cycle
    printf("\n");
}

int isValidMove(int v, int k) {
    if (!graph[path[k - 1]][v]) // Check if there's an edge
        return 0;

    for (int i = 0; i < k; i++) // Check if already visited
        if (path[i] == v)
            return 0;

    return 1;
}

int hamiltonianCycle(int k) {
    if (k == V) {
        if (graph[path[k - 1]][path[0]]) // Check if there's an edge to the starting vertex
            return 1;
        else
            return 0;
    }

    for (int v = 1; v < V; v++) {
        if (isValidMove(v, k)) {
            path[k] = v;

            if (hamiltonianCycle(k + 1))
                return 1;

            path[k] = -1; // Backtrack
        }
    }

    return 0;
}

int main() {
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0; // Starting vertex

    if (!hamiltonianCycle(1)) {
        printf("No Hamiltonian Circuit exists.\n");
        return 0;
    }

    printPath();

    return 0;
}
