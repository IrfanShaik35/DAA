#include <stdio.h>

#define MAX_ITEMS 100

typedef struct {
    int weight;
    int value;
} Item;

void knapsackGreedy(int capacity, Item items[], int n) {
    // Calculate value-to-weight ratio for each item
    double ratios[n];
    for (int i = 0; i < n; i++) {
        ratios[i] = (double)items[i].value / items[i].weight;
    }

    // Sort items based on value-to-weight ratio in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratios[i] < ratios[j]) {
                double tempRatio = ratios[i];
                ratios[i] = ratios[j];
                ratios[j] = tempRatio;

                Item tempItem = items[i];
                items[i] = items[j];
                items[j] = tempItem;
            }
        }
    }

    int currentWeight = 0;
    double totalValue = 0.0;

    printf("Selected items:\n");

    // Add items to the knapsack greedily
    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            printf("Item with weight %d and value %d\n", items[i].weight, items[i].value);
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // If adding the whole item would exceed capacity, add fraction of it
            double fraction = (double)(capacity - currentWeight) / items[i].weight;
            totalValue += fraction * items[i].value;
            printf("Fraction of item with weight %d added: %.2lf\n", items[i].weight, fraction);
            break;
        }
    }

    printf("Total value of items in the knapsack: %.2lf\n", totalValue);
}

int main() {
    int capacity, n;
    Item items[MAX_ITEMS];

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d:\n", i + 1);
        printf("Weight: ");
        scanf("%d", &items[i].weight);
        printf("Value: ");
        scanf("%d", &items[i].value);
    }

    knapsackGreedy(capacity, items, n);

    return 0;
}
