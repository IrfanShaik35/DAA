#include <stdio.h>
#include <math.h>

#define MAX_FACTORS 100

int factors[MAX_FACTORS];
int num_factors = 0;

// Function to generate factors of n using recursion
void generateFactors(int n, int current_factor) {
    // Base case: If current_factor exceeds the square root of n
    if (current_factor * current_factor > n) {
        // If n is a perfect square, include its square root as a factor
        if (current_factor * current_factor == n) {
            factors[num_factors++] = current_factor;
        }
        return;
    }

    // If current_factor is a factor of n
    if (n % current_factor == 0) {
        // Add current_factor and n / current_factor to the list of factors
        factors[num_factors++] = current_factor;
        factors[num_factors++] = n / current_factor;
    }

    // Recur for the next factor
    generateFactors(n, current_factor + 1);
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    generateFactors(n, 1);

    printf("Factors of %d are:\n", n);
    for (int i = 0; i < num_factors; i++) {
        printf("%d ", factors[i]);
    }
    printf("\n");

    return 0;
}
