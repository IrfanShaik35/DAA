#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 20

// Function to check if it's safe to assign color c to vertex v
bool isSafe(int v, int graph[][MAX_VERTICES], int color[], int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

// Function to recursively solve the graph coloring problem
bool graphColoringUtil(int graph[][MAX_VERTICES], int m, int color[], int v, int V) {
    if (v == V) {
        // Base case: all vertices are colored
        return true;
    }

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c; // Assign color c to vertex v

            // Recursively color remaining vertices
            if (graphColoringUtil(graph, m, color, v + 1, V)) {
                return true;
            }

            // If assigning color c doesn't lead to a solution, backtrack
            color[v] = 0;
        }
    }

    return false; // No solution found
}

// Function to solve the graph coloring problem
bool graphColoring(int graph[][MAX_VERTICES], int m, int V) {
    int color[MAX_VERTICES];
    for (int i = 0; i < V; i++) {
        color[i] = 0; // Initialize all colors as unassigned
    }

    if (graphColoringUtil(graph, m, color, 0, V)) {
        // Print the solution
        printf("Solution exists. The coloring of vertices is:\n");
        for (int i = 0; i < V; i++) {
            printf("Vertex %d: Color %d\n", i, color[i]);
        }
        return true;
    } else {
        printf("Solution does not exist.\n");
        return false;
    }
}

// Main function
int main() {
    int V, m;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    int graph[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m, V);

    return 0;
}
