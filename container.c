#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_CONTAINERS 100

int items[MAX_ITEMS];
int containers[MAX_CONTAINERS];
int n, m; // Number of items and containers
int capacity; // Maximum capacity of each container

void loadContainers() {
    int currentContainer = 0;
    containers[currentContainer] = 0; // Start loading items into the first container
    int currentCapacity = capacity;

    for (int i = 0; i < n; i++) {
        if (items[i] <= currentCapacity) {
            containers[currentContainer]++; // Add item to current container
            currentCapacity -= items[i]; // Update remaining capacity of current container
        } else {
            currentContainer++; // Move to the next container
            containers[currentContainer] = 1; // Start loading items into a new container
            currentCapacity = capacity - items[i]; // Update remaining capacity of new container
        }
    }
    m = currentContainer + 1; // Update the number of containers used
}

int main() {
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the maximum capacity of each container: ");
    scanf("%d", &capacity);

    printf("Enter the weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i]);
    }

    loadContainers();

    printf("Items loaded into containers:\n");
    for (int i = 0; i < m; i++) {
        printf("Container %d: %d items\n", i + 1, containers[i]);
    }

    return 0;
}
