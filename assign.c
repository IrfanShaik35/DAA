#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 4

int minCost = INT_MAX;
int assignment[N]; // Stores the assignment of tasks to agents

// Function to check if a task can be assigned to an agent
bool isAssignable(int agent, int task, bool assigned[]) {
    return !assigned[task];
}

// Function to recursively solve the assignment problem
void assignmentProblem(int costMatrix[N][N], int agent, int totalCost, bool assigned[]) {
    // Base case: all agents are assigned tasks
    if (agent == N) {
        if (totalCost < minCost) {
            minCost = totalCost;
            // Update the assignment
            for (int i = 0; i < N; i++) {
                assignment[i] = assigned[i];
            }
        }
        return;
    }

    // Try assigning each task to the current agent
    for (int task = 0; task < N; task++) {
        if (isAssignable(agent, task, assigned)) {
            // Mark the task as assigned
            assigned[task] = true;
            // Recur for the next agent with updated total cost
            assignmentProblem(costMatrix, agent + 1, totalCost + costMatrix[agent][task], assigned);
            // Unmark the task for backtracking
            assigned[task] = false;
        }
    }
}

int main() {
    int costMatrix[N][N];

    printf("Enter the cost matrix (%dx%d):\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }

    bool assigned[N] = {false};

    assignmentProblem(costMatrix, 0, 0, assigned);

    printf("Minimum cost of assignment: %d\n", minCost);
    printf("Assignment:\n");
    for (int i = 0; i < N; i++) {
        printf("Worker %d -> Job %d\n", i + 1, assignment[i] + 1);
    }

    return 0;
}
